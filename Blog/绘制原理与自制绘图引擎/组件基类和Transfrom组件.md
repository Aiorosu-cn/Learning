[TOC]

# 组件类

摄像机和模型,如果要统一管理,可以用一个类封装

因为有唯一的一个有参构造,子类一定要用初始化成员列表

随便一个组件都能点出GameObject,任何一个GameObject也能添加组件

组件基类拥有的成员你变量就2个,`mType`和`mOwner`

mOwner ,就是该组件附加在哪个游戏对象上

```cpp
//定义一些组件的类型
enum emComponentType
{
	ComType_None,
	ComType_Transform,//变换组件
	ComType_MeshRender,//模型渲染组件
	ComType_Camera,//摄像机组件
	ComType_Light,//灯光组件
	//...
};

class GameObject;

//组件基类
typedef class Component
{
public:
	virtual ~Component() = default;
	Component(const Component& that) = delete;
	Component& operator = (const Component& that) = delete;

	//唯一的一个有参构造
	Component(GameObject* pObject)
	{
		mType = emComponentType::ComType_None;//mType后面会在子类赋值
		mOwner = pObject;
	}

	//获取类型
	emComponentType Type() { return mType; }
	//获取所属的gameobject
	GameObject* gameobject() { return mOwner; }
protected:
	GameObject* mOwner;//谁持有该组件，也就是该组件附加在哪一个游戏对象上
	emComponentType mType;//组件的类型
}COMPONENT,*LPCOMPONENT;
```







## 移动组件Transfrom

主要包含位置,缩放和旋转信息

unity的旋转是ZXY的旋转

由于Component有个唯一的父类构造,所以Transfrom必须要用初始化列表的方式调用父类的唯一有参构造初始化

他有3个轴,3种矩阵

比较复杂的是更新旋转函数

```cpp
#include "Component.h"
#include "Matrix4x4.h"

class Transform:public Component
{
protected:
	//用于对应的矩阵的更新
	void _update_Matrix_Translate();
	void _update_Matrix_Scale();
	void _update_Matrix_Rotate();
protected:
	vector3d mPosition;
	vector3d mScale;
	vector3d mRotation;
	vector3d mX, mY, mZ;

	Matrix4x4 matrixTranslate;
	Matrix4x4 matrixScale;
	Matrix4x4 matrixRotate;
public:
	//必须用初始化列表的方式调用父类的唯一有参构造
	Transform(GameObject* pobj) :Component(pobj)
	{
		mType = emComponentType::ComType_Transform;//确定组件的真正类型
		mPosition = vector3d::Zero();
		mScale = vector3d::One();
		mRotation = vector3d::Zero();
		//凡是修改了位置、缩放以及旋转任意一项，那么对应变换矩阵是需要进行更新的
		_update_Matrix_Translate();
		_update_Matrix_Scale();
		_update_Matrix_Rotate();
	}

	//提供前后左右上下方位向量 
	vector3d forward() { return mZ; }
	vector3d back() { return -mZ; }
	vector3d right() { return mX; }
	vector3d left() { return -mX; }
	vector3d up() { return mY; }
	vector3d down() { return -mY; }

	const vector3d& localScale() { return mScale; }
	const vector3d& position() { return mPosition; }
	const vector3d& rotation() { return mRotation; }

	Matrix4x4& MatT() { return matrixTranslate; }
	Matrix4x4& MatS() { return matrixScale; }
	Matrix4x4& MatR() { return matrixRotate; }

	void SetPosition(const vector3d& v)
	{
		mPosition = v;
		_update_Matrix_Translate();
	}
	void SetScale(const vector3d& v)
	{
		mScale = v;
		_update_Matrix_Scale();
	}
	void SetRotation(const vector3d& v)
	{
		mRotation = v;
		_update_Matrix_Rotate();
	}
	void translate(const vector3d& tv)
	{
		mPosition += tv;
		_update_Matrix_Translate();
	}
	void scale(const vector3d& ts)
	{
		mScale *= ts;
		_update_Matrix_Scale();
	}

	void rotate(const vector3d& v);


};
```

### 旋转导致的3个轴的变化

求出3个轴的矩阵

空间中的任意旋转,都可以分解为3个轴向的旋转

我们旋转过程中,需要确定旋转的顺序

在unity中,一个物体的旋转并不是绕x轴旋转再绕Y轴旋转,而是有一个主轴,然后其他轴绕这个轴旋转

这种旋转方式叫做**欧拉角**

欧拉角有6种旋转**次序**

**正交矩阵的旋转矩阵的逆矩阵是其转置矩阵**

逆矩阵的用法可以推导摄像机矩阵

得到他的旋转矩阵后,转置一下就能得到3个轴

```cpp
void Transform::rotate(const vector3d& v)
{
	//将角度转换成弧度计算
	//M_PI/180 => 0.01745329f
	vector3d angle_r = v * 0.01745329f;
	//计算出围绕三个轴旋转的矩阵求出
	Matrix4x4 _mx; _mx.SetRotateX_r(angle_r.x);
	Matrix4x4 _my; _my.SetRotateY_r(angle_r.y);
	Matrix4x4 _mz; _mz.SetRotateZ_r(angle_r.z);
	//对于使用欧拉角进行旋转有六种旋转顺序 xyz,xzy,yxz,yzx,zxy,zyx
	//我们只能选取一种顺序作为标准进行计算
	//我们此处选择zxy的顺序进行旋转
	Matrix4x4 _mr = _mz * _mx * _my;
	//在本身的基础上进行了zxy顺序的旋转
	matrixRotate *= _mr;
	//最终的旋转矩阵
	Matrix4x4& r = matrixRotate;
	//我们之前说过正交矩阵的旋转矩阵的逆矩阵是其转置矩阵
	//所以可以通过旋转矩阵得到三个轴向
	mX.x = r._11; mY.x = r._12; mZ.x = r._13;
	mX.y = r._21; mY.y = r._22; mZ.y = r._23;
	mX.z = r._31; mY.z = r._32; mZ.z = r._33;

	mX.Normalize();
	mY.Normalize();
	mZ.Normalize();

	//需要根据当前的数据求解欧拉角
	//下面是zxy顺序欧拉角的解法
	double sy = sqrt(r._11 * r._11 + r._21 * r._21);
	bool singular = sy<1e-6;

	if (!singular)
	{
		mRotation.x = atan2(r._32, r._32);
		mRotation.y = atan2(-r._31, sy);
		mRotation.z = atan2(r._21, r._21);
	}
	else
	{
		mRotation.x = atan2(r._32, r._22);
		mRotation.y = atan2(-r._31, sy);
		mRotation.z = 0;
	}

	//将弧度转换为角度
	mRotation *= 57.2957795f;
}
```


[TOC]

# MVP变换

摄像机先在世界架好,此时摄像机有个世界坐标xyz

| 把模型加载到世界 | 使用世界变换矩阵,将模型的local坐标变到世界上的坐标(以世界0,0,0为原点的坐标) | model      |
| ---------------- | ------------------------------------------------------------ | ---------- |
| 摄像机变换       | 把模型的坐标换算成摄像机视图(以摄像机为原点)的坐标           | view       |
| 投影变换         | 正交或者透视投影,将观察的摄像机的结果映射为一个立方体(OpenGL)或搬个立方体(DX) | Projection |



# 摄像机变换

变换到以摄像机为原点并不简单,因为摄像机有前方和上方的概念,而且摄像机本身可能是旋转的,所以在考虑摄像机变换矩阵时,要考虑平移和旋转2个情况的混合

一般来说,我们先平移再旋转

关于求摄像机的变换矩阵,假设摄像机自己的世界坐标点O为cx,cy,cz,那么O * 摄像机矩阵= 单位矩阵,那么我们只需要求cx,cy,cz的逆矩阵

由于摄像机的三个轴组成的矩阵,是一个正交矩阵,所以他们的逆矩阵是他的转置矩阵

那转置矩阵就是行列互换就得到了,现在就得到了平移需要的矩阵 = O的转置矩阵,

下面来求旋转的矩阵

首先我们需要知道摄像机的前方,即根节点eye看向的位置at,然后需要知道摄像机的上方up

> 叉乘时注意自己的坐标系是左手还是右手
>
> 摄像机z轴= 单位化(at - eye)
>
> 摄像机 x 轴 = 单位化( up X 摄像机Z轴)
>
> 谁想及Y 轴 = 摄像机 Z 轴  X 摄像机X轴

为什么不用up方向,因为其中up方向不一定是摄像机Y轴方向,他只是Y轴平面上的一个方向即可

最后用平移矩阵  * 旋转矩阵, 就得到了整个摄像机变换的矩阵



# 投影变换

首先理解概念,视景体,近截面,远截面,



将观察到的中间部分,变成一个立方体

我们投影是吧视景体中的东西投到近截面,远截面的作用是判断视景体的范围

所有点都压在近截面,那么我们需要一个深度值来记录这个点的深度

## 透视投影摄像机

要模仿近大远小的效果,当我们把椎体压缩成一个立方体时,就可以实现近大远小的效果

我们用一个叫FOV(feild of view)的角,表示上截面和下截面的夹角

然后我们定一个宽高比 w /h 

空间中的点O(x,y,z),xy可以先投影到近截面,然后通过拉伸为立方体,可以得到xy变换后的值,因为平面的左右拉伸是均匀的

但是O变化后的z值,需要特殊的方法计算

### 视景体中的点投影到近截面

截面上的z值都是一样的固定的

要知道近截面投影点的xy值,需要知道近截面的宽高,即需要知道3个值: 

- fov 
- 宽高比
- 近截面到摄像机的距离

### Z值求法

需要用一个其次坐标来置换



## 正交摄像机

需要一个size规定摄像观测的范围

我们透视的摄像机大概是一个四棱椎

但是对于我们正交的摄像机,大概是平行的

需要告诉摄像机看多宽多高

我们3D的宽高是视口的宽高,并不是看的世界的宽高

我们利用现有的FOV角,可以算出近截面的宽高是多少

这样就可以不用写另外的一套参数,不需要其他数值

正交投影压缩到-2-2的立方体,

Unity里面正交和透视其实改一下类型就可以自动变换





# 摄影机类

```cpp
class Camera
{
public:
	Matrix4x4 MatrixView;//摄像机变换矩阵
	Matrix4x4 MatrixProjection;//投影矩阵
	Matrix4x4 MatrixViewPort;//视口矩阵

	float mViewWidth, mViewHeight;//视口的宽高
	float mAspect;
	float mFov;
	float mZnear, mZfar;
	vector3d mPosition;//摄像机的位置
	vector3d mZ, mX, mY;

	virtual void SetCamera(
		vector3d eye,
		vector3d at,
		vector3d up,
		int width,
		int height,
		float znear,
		float zfar,
		float aspect,
		float fov = 60.0f) = 0;
};

//透视投影摄像机
class CameraPerspective:public Camera
{
public:
	// 通过 Camera 继承
	virtual void SetCamera(vector3d eye, vector3d at, vector3d up, int width, int height, float znear, float zfar, float aspect, float fov = 60.0f) override;
};

//正交投影摄像机
class CameraOrthogonal:public Camera
{
public:
	// 通过 Camera 继承
	virtual void SetCamera(vector3d eye, vector3d at, vector3d up, int width, int height, float znear, float zfar, float aspect, float fov = 60.0f) override;
};
```


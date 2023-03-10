[TOC]

# 向量点乘和叉乘

点乘的结果是点积,又称数量积或标量积

空间中有两个向量
$$
\vec{a} = (x1,y1,z1),\vec{b} = (x2,y2,z2),\vec{a}和\vec{b}之间夹角为\theta
$$
**从代数角度看**,点积是对两个向量对应位置上的值相乘再相加的操作,其结果即为点积
$$
\vec{a}\cdot\vec{b} = x1x2 + y1y2 + z1z2
\\
\vec{a}\times\vec{b} = (y1z2 - z1y2, z1x2 - x1z2,x1y2 - y1x2)
$$
**从几何角度看**,点积是两个向量的长度与他们夹角余弦的积
$$
\vec{a}\cdot\vec{b} = |\vec{a}||\vec{b}|\cos\theta
\\
\vec{a}\times\vec{b} = |\vec{a}||\vec{b}|\sin\theta\vec{n}
\\
\vec{n} 是 两个向量所在平面的法线向量,使用右手定则确定方向
$$
因为c++的三角函数是使用迭代方式进行计算,性能开销大,使用代数方法计算结果更快,

并且其结果再除以ab的模长,可以计算sin和cos,也比三角函数快

虽然我们计算结果用的是代数方法,但是一定要把结果翻译成几何意义,点乘可以表示cos()值,叉乘可以表示sin()值

# 实现

```cpp
#define M_PI       3.14159265358979323846   // pi
//1e-6：使用的科学计数法，也就是1x10^(-6)  0.000001
#define IS_FLOAT_ZERO(f) (abs(f)<1e-6)

class vector3d
{
	static vector3d _up;
	static vector3d _down;
	static vector3d _left;
	static vector3d _right;
	static vector3d _zero;
	static vector3d _forward;
	static vector3d _back;
public:
	float x, y, z;	
	//构造
	vector3d() :x(0), y(0),z(0){}//使用初始化列表全部构造为0，也即是一个0向量
	vector3d(float _x, float _y,float _z) :x(_x), y(_y),z(_z) {}
	//向量乘除（和数字）
	vector3d operator * (float r)
	{
		return vector3d(x * r, y * r,z*r);
	}
	vector3d operator / (float r)
	{
		//断言检查：在debug的模式下，对断言中的条件进行判断
		//如果条件为真，什么都不发生
		//如果条件为加，抛出断言异常
		assert(!IS_FLOAT_ZERO(r));
		return vector3d(x / r, y / r,z/r);
	}
	vector3d operator * (float r) const
	{
		return vector3d(x * r, y * r,z*r);
	}
	vector3d operator / (float r) const
	{
		//断言检查：在debug的模式下，对断言中的条件进行判断
		//如果条件为真，什么都不发生
		//如果条件为加，抛出断言异常
		assert(!IS_FLOAT_ZERO(r));
		return vector3d(x / r, y / r,z/r);
	}
	vector3d& operator *= (float r)
	{
		x *= r; y *= r;z*=r;
		return *this;
	}
	vector3d& operator /= (float r)
	{
		//断言检查：在debug的模式下，对断言中的条件进行判断
		//如果条件为真，什么都不发生
		//如果条件为加，抛出断言异常
		assert(!IS_FLOAT_ZERO(r));
		x /= r; y /= r;z/=r;
		return *this;
	}

	//模长
	float Length()
	{
		return sqrtf(x * x + y * y + z*z);
	}
	//平方长度
	float SQLength()
	{
		return x * x + y * y + z*z;
	}
	float Length() const
	{
		return sqrtf(x * x + y * y + z*z);
	}
	//平方长度
	float SQLength() const
	{
		return x * x + y * y + z*z;
	}
	//求当前向量的单位向量
	vector3d Normalized()
	{
		float len = Length();
		return (*this) / len;
	}
	//求当前向量的单位向量
	vector3d Normalized()const
	{
		float len = Length();
		return (*this) / len;
	}
	//将向量本身单位化
	vector3d Normalize()
	{
		float len = Length();
		return (*this) /= len;
	}
	//向量加减点乘叉乘（和向量）
	vector3d operator + (const vector3d& that)
	{
		return vector3d(x + that.x, y + that.y ,z+that.z);
	}
	vector3d operator - (const vector3d& that)
	{
		return vector3d(x - that.x, y - that.y ,z - that.z);
	}
	vector3d operator + (const vector3d& that) const
	{
		return vector3d(x + that.x, y + that.y, z+that.z);
	}
	vector3d operator - (const vector3d& that) const
	{
		return vector3d(x - that.x, y - that.y,z - that.z);
	}
	vector3d& operator += (const vector3d& that)
	{
		x += that.x;
		y += that.y;
		z += that.z;
		return *this;
	}
	vector3d& operator -= (const vector3d& that)
	{
		x -= that.x;
		y -= that.y;
		z -= that.z;
		return *this;
	}
	float Dot(const vector3d& that)
	{
		return x * that.x + y * that.y + z * that.z;
	}
	float Dot(const vector3d& that)const
	{
		return x * that.x + y * that.y + z * that.z;
	}
	vector3d Cross(const vector3d& that)
	{
		return vector3d(y*that.z - z*that.y,
		z*that.x - x*that.z,
		x*that.y - y*that.x);
	}
	vector3d Cross(const vector3d& that) const
	{
		return vector3d(y * that.z - z * that.y,
			z * that.x - x * that.z,
			x * that.y - y * that.x);
	}
	//投影
	vector3d Projection(const vector3d& n)
	{
		vector3d dir = n.Normalized();
		float len1 = Length();
		float len2 = n.Length();
		assert(!IS_FLOAT_ZERO(len1));
		assert(!IS_FLOAT_ZERO(len2));
		float mod = this->Dot(n) / (len1 * len2);
		dir *= mod;
		return dir;
	}
	vector3d Projection(const vector3d& n)const
	{
		vector3d dir = n.Normalized();
		float len1 = Length();
		float len2 = n.Length();
		assert(!IS_FLOAT_ZERO(len1));
		assert(!IS_FLOAT_ZERO(len2));
		float mod = this->Dot(n) / (len1 * len2);
		dir *= mod;
		return dir;
	}
	//求夹角
	//结果是弧度
	float Angle_r(const vector3d& that)
	{
		float lenab = this->Length() * that.Length();
		float dotab = this->Dot(that);
		assert(!IS_FLOAT_ZERO(lenab));
		float cosvalue = dotab / lenab;
		return acosf(cosvalue);
	}
	float Angle_r(const vector3d& that)const
	{
		float lenab = this->Length() * that.Length();
		float dotab = this->Dot(that);
		assert(!IS_FLOAT_ZERO(lenab));
		float cosvalue = dotab / lenab;
		return acosf(cosvalue);
	}
	//结果是度数
	float Angle_d(const vector3d& that)
	{
		float ra = Angle_r(that);
		return float(ra / M_PI) * 180.0f;
	}
	float Angle_d(const vector3d& that)const
	{
		float ra = Angle_r(that);
		return float(ra / M_PI) * 180.0f;
	}
	static vector3d Up()
	{
		return _up;
	}
	static vector3d Down()
	{
		return _down;
	}
	static vector3d Left()
	{
		return _left;
	}
	static vector3d Right()
	{
		return _right;
	}
	static vector3d Forwad()
	{
		return _forward;
	}
	static vector3d Back()
	{
		return _back;
	}

	static vector3d Zero()
	{
		return _zero;
	}

	static vector3d Rand();

	static vector3d Lerp(const vector3d& from, const vector3d& to, float t)
	{
        //这个t,向量直接比较距离得出t的比值
		return from + (to - from) * t;
	}
};
```

# 差值

给一个系数t,这一段小向量当t为0,当t为1,而这个向量是

```cpp
static 
```



写一个转化的公式,要把rgb转换为vector3d

```cpp
operator vector3d()
{
    return vector3d(r / 255.0f, g/ 255.0f, b / 255.0f);
}

//commonDefine.h
//限制传入的树为0~1
#define CLIMP_2_ONE(t) ((t)<0?0;(t)>1?1:(t))
stColor32(const vector3d& v)
{
    r =  (unsigned char)CLIMP_2_ONE(V.X) * 255;
    g =  (unsigned char)CLIMP_2_ONE(V.y) * 255;
    b =  (unsigned char)CLIMP_2_ONE(V.z) * 255;
    a = 255;
}
```

还需要画直线


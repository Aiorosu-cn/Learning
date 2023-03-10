[TOC]

# GameObject

主要有2个成员,mpTransform,哪怕是个空物体也要有这个组件

用vector把其他组件存入列表,这里没有考虑同一个物体加多个组件

然后有管理这个组件的一些方法

在构造函数中,所有GO一旦创建就会移动拥有移动组件

```cpp
class GameObject
{
public:
	GameObject()
	{
		//所有的GameObject一旦创建，就会自动的创建transform组件
		mpTransform = nullptr;
		mpTransform = (Transform*)AddComponent(emComponentType::ComType_Transform);
	}
	virtual ~GameObject()
	{
		//将创建的组件释放
		if (!mComponents.empty())
		{
			for (auto& c : mComponents)
			{
				delete c;
			}
			mComponents.clear();
		}
		if (mpTransform!=nullptr)
		{
			delete mpTransform;
			mpTransform = nullptr;
		}
	}

	//增加组件的功能
	LPCOMPONENT AddComponent(emComponentType t)
	{
		switch (t)
		{
		case emComponentType::ComType_Transform:
		{
			if (mpTransform!=nullptr)
			{
				return mpTransform;
			}
			mpTransform = new Transform(this);
			return mpTransform;
		}break;
		case emComponentType::ComType_Camera:
		{

		}break;
		case emComponentType::ComType_MeshRender:
		{

		}break;
		case emComponentType::ComType_Light:
		{

		}break;
		default:
		{

		}
		}
		return nullptr;
	}
	//获取组件的功能：通过遍历查找到对应类型的组件
	LPCOMPONENT GetComponent(emComponentType t)
	{
		//变换组件是单独存储的，所以优先特殊判断
		if (t == emComponentType::ComType_Transform)
		{
			return mpTransform;
		}
		//其余的非变换组件通过遍历查找
		for (auto& itr:mComponents)
		{
			if (itr->Type() == t)
			{
				return itr;
			}
		}
		return nullptr;
	}
	//删除组件的功能：实际上就是查找对应类型组件并从数组中删除
	void RemoveComponent(emComponentType t)
	{
		if (t == emComponentType::ComType_Transform) { return; }
		for (auto it = mComponents.begin();it!=mComponents.end();it++)
		{
			if ((*it)->Type() == t)
			{
				delete* it;
				mComponents.erase(it);
				return;
			}
		}
	}
	//获取该对象的变换组件
	Transform& transform() { return *mpTransform; }
protected:
	Transform* mpTransform;//每一个游戏对象至少都应该有这么唯一的一个tansform组件
	std::vector<LPCOMPONENT> mComponents;//组件存储除了transform的所有的组件
};
```


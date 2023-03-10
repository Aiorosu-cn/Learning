[toc]



# 创建一个AI蓝图

- 给一个模型和动画资源;
- AI控制的逻辑,使用AI控制器,创建一个AI 控制器;
- 角色蓝图中,有个AI controller class 和 auto possess AI,选择为我们的AI蓝图;
  - Auto possess AI 有2个选项,直接拖到世界的叫做Place in world,出生点刷新的叫做  spawnd;意思只有放到世界中才受AI控制;
- 在AI蓝图的事件视图中编辑AI行为;
- 如果要让他一直追我,可以使用`delay`,然后再连回`AI move to`;



| AI move to          | AI   | AI移动到目标位置 |
| ------------------- | ---- | ---------------- |
| get Controlled Pawn |      | 获取一个pawn     |
| get Owner           |      | 获取一个actor    |



## 添加AI组件



# 武器怎么写

蓝图可以继承的;

| set timer   | time | 设置演示器,每隔几秒执行一次,是一个异步执行的操作,构上loop会一直执行; |
| ----------- | ---- | ------------------------------------------------------------ |
| clear timer | time | 清除时钟;                                                    |
| parent:     |      | 继承蓝图,如果是C++继承类,C++也要调函数,初始化属性            |

## 抛物线组件模拟子弹

projectileMovement,投射组件,当需要物体按照抛物线运动就要这个,抛弧线移动组件有下面这些特性;

- 可以设置重力啥的;
- 勾了rotation follows velocity ,可以根据抛物线旋转,箭头会向下;
- Initial life Span,可以设置自动回收的时间,子弹会消失;
- 子弹速度可以通过设置摩擦力来判断,friction





## 人物瞄准射线检测的channel

- 人物做子弹伤害时,需要区分敌我火力;
- 在项目设置- engine- collision- trace channel里面添加channel
- 在蓝图里设置哪个类属于哪个channel;

> UE也可以支持team ,但是蓝图无法修改,只能C++里面修改



| set  collision response to channel |      | 设置蓝图属于哪个channel |
| ---------------------------------- | ---- | ----------------------- |
|                                    |      |                         |


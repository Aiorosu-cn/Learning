[toc]

# EQS概论 AI-EnvQuery类

EQS的一些样板用例包括：让AI角色找到避开玩家视线的掩护位置，或者找到关卡中最近的体力回复剂或弹药。

EQS会返回得分最高的那个环境的点

EQS是一个单独的行为树,单独写行为,里面的节点只有生成器类型,生成器还能添加条件

使用EQS设置好了后,在行为树的自定义任务中使用,使用节点**`Run EQSQuery`**执行EQS,能将结果导出

- EQS的作用就是返回一个位置或者物品
- 使用的时候需要在`编辑器-通用-EQS`为开启;
- EQS有Root没有黑板
- 生成的叫做生成器`generators`
- 可以在任意层级指定查询中心;
- 可以用`eqs testing pawn` 对象来测试EQS范围   ;
- EQS的非root节点就不能再往下执行了,但是各个平行节点可以按照顺序执行;

# 生成器节点介绍

## 生成器类型

- 生成器的类型决定了查询的范围是什么样的
- 生成器每一级都可以设置对应的查询中心;

| 生成器名字          | 作用                         | 应用场景                                                   |
| ------------------- | ---------------------------- | ---------------------------------------------------------- |
| actor of class      | 查询物品                     | 设置要搜索的类,然后设置半径,如果半径内有这个物体会高亮显示 |
| current location    | 按照位置查询                 |                                                            |
| Points              | 生成一系列以某种类型排布的点 | 有扇形排布的点,圆圈排布的点                                |
| Points:Grid         |                              | 只是生成点,但是玩家不一定能走过去                          |
| Points:Pathing Grid |                              | 查询中心能过去的点                                         |

## 生成器参数

**生成围绕（Generate Around）** 字段可以确定应该将网格放置在什么位置（这个示例中是放在查询器或AI角色周围）。



## 生成器添加测试条件 

### 直接添加

生成器并不能每次都能查询到一个最好的结果

右键`add test`可以加一些测试条件,常用的几个:
|测试条件名字|测试内容|测试返回值|
|:--|:--|:--|
|pathfinding|可以被寻路找到的|是否存在/路径成本/路径长度|
|pathing grid|同时满足可以走过去和周围的矩形测试||
|distance|用距离做条件测试,|评分制,默认越远评分越高|
|gameplay tags| 测试可指定一个标记，用于在测试中查询并尝试匹配 |布尔值|
|Trace|能看到的位置|布尔值,0是看不到,1是看的到,使用**bool mathc** 让结果取反|
|grid|点周围的矩形||
|Dot|两个向量的点乘可以用于计算向量之间的cos夹角|-1 到1 的值|
|overlap:Box|生成一个碰撞盒,查看是否有碰撞|布尔值|

> 设置测试参数的例子
>
> - **测试目的（Test Purpose）** = **仅过滤（Filter Only）**
> - **情境（Context）** = **EQC_PlayerContext**
> - **布尔匹配（Bool Match）** = **禁用（Disabled）**
>
> 在这里我们提供玩家角色作为可视性 **追踪** 测试中的参考点（情境）。禁用 **布尔匹配（Bool Match）** 选项表示我们希望过滤掉所有无法看见玩家角色的点
>
> **距离** 测试目的是对返回的项目（Item）计分，-1.0的计分因子是对离角色较近的点计高分。如果将这个设置保留为1.0，它将返回离角色最远的点，这可能导致AI为了到达最远的点而直接从玩家身边跑过。



### 通过EnvQueryContext类改变测试条件的查询中心

默认EQS在谁身上就以谁为中心,可以通过

创建一个继承于**`EnvQueryContext_BlueprintBase(简称EQC)`**的蓝图类,这个字段的来源是EQC中 cneter Actor中可以选的对象类型确认的;

- 创建一个EnvQueryContext_BlueprintBase,然后重写 single actor函数,由他来指定最后的返回值,即需要的查询中心;
- 这个蓝图用于EQC的任意节点;

## 测试条件中的参数

- Test Purpose 测试目的
  - Filter only :只过滤,结果只有true和false
  - Score only:在得到的点里面,进行打分
  - filter and score:既要排除又要评分
- Filter 过滤条件
  - type:过滤使用的方法,最大,最小,还是范围
- Score 评分方法
  - scoring equation 使用线性,反向,还是平方根等方法来评分



# 用server任务去执行EQS查询

- 执行EQS事件
- 把EQS查到的数组当中的第一个点当做AI要躲藏的点
- 把查询结果绑定到一个自定义的查询结束事件中,因为EQS查询可能会比较慢,不一定会执行结束才执行下一步,所以用这个方法可以确保是查询结束了才会执行下面的函数;

| run EQS Query                  |      | 执行EQS查询                                   |
| ------------------------------ | ---- | --------------------------------------------- |
| On Query Finished              |      |                                               |
| Get query results as actor     | eqs  | 获取EQS的结果的Actor信息,这个多用在拾取物品上 |
| get query results as locations | eqs  | 获取EQS的结果中的位置信息                     |



# 直接使用EQS

从节点连出引线，使用 **Run EQSQuery** 节点,Run EQSQuery节点可用于执行将更新分配的黑板键的EQS查询.

>  在 **Run EQSQuery** 节点的 **细节（Details）** 面板中，将 **黑板键（Blackboard Key** 设为 **MoveToLocation**，**查询模板（Query Template）** 设为 **EQS_FindPlayer**。
>
> 行为树将会运行EQS查询来更新黑板键 **MoveToLocation**，然后AI就会移动到该位置，并转身面对 **TargetActor**（玩家角色）

# 修改行为树

- 当发现人物时,要跑向躲藏点,但是一旦跑,就发现不了玩家了,就需要设置为,如果发现玩家,就必须执行完下面的所有节点,所以在节点的流程控制里,如果值变换了,不能做任何改变





> 可以使用[AI调试工具](https://docs.unrealengine.com/4.27/zh-CN/InteractiveExperiences/ArtificialIntelligence/AIDebugging)查看任何活动的EQS查询（除了行为树或感知信息之外）。要在运行时激活AI调试，请按 **'**（撇号）键，然后选择1（进行一般AI调试）、2（用于行为树）、3（用于EQS）或4（用于AI感知）。


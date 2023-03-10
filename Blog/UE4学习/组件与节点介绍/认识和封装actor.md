[TOC]

# trigger

有BOX和sphere tirgger,UE里面的碰撞,

tigger 有三种事件  ,

- BeginOverlap
- EndOverlap
- OnActorHit

>  调整tirgger 的 shape中的  box extent 比调整Scale更好,





# Actor和Trigger的碰撞

碰撞相关的有Collision有Physics

## Physics

刚体里可以计算物理的东西打开了

| 1               | 2    | 3                         |
| --------------- | ---- | ------------------------- |
| Enable Gravity  |      | 允许使用重力              |
| MassInKg        |      | 根据提及计算重力          |
| Angular Damping |      | 旋转阻尼                  |
| Linear Damping  |      | 移动阻尼                  |
|                 |      | 锁定Y轴,物体无法绕Y轴转动 |

## Collision



| 1                   | 2    | 3                                                            |
| ------------------- | ---- | ------------------------------------------------------------ |
| Collision Presets   |      | 触发方式                                                     |
| Collision Responses |      | 接触效果<br />Block, 阻挡<br />OverLap,有触发效果<br />Ignore,忽略接触 |
|                     |      |                                                              |
|                     |      |                                                              |
|                     |      |                                                              |

# 


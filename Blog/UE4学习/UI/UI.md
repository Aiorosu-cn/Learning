[TOC]

# UE4的UI概述

UE4有3套做UI的东西:

- OnGUI,效率太拉了
- UGUI,主流
- UIToolKit,基于网页技术渲染





# HUD

- HUD,只能在Game Mode中指定;
- 只能生成静态界面,效率比较低,可以用于创建简单的十字准星;



| 函数                    | 父类 | 说明                |
| ----------------------- | ---- | ------------------- |
| Event receive dreaw hud | HUD  | 每一帧都使用HUD绘制 |
| draw texture            | HUD  | 绘制图片            |



# UMG

包含了多种做UI的东西

- Font ,设置字体
- slate brush ,C++用的多

通用的设置

| padding | UI-widget | 空隙 |
| ------- | --------- | ---- |
|         |           |      |





## widget 

常用的UI设计

- 锚点集中和散开,集中时,按照方框的左上角和点的相对,散开时,按照方框的上下左右边和锚点的距离来
- 方框是按照比例来的
- 每次都会创建

如果想节约性能,可以把UI保存因为一个变量,如果没有就创建,如果有了就使用

| 函数               | 父类       | 说明                              |
| ------------------ | ---------- | --------------------------------- |
| add to viewport    | UI-widget  | 添加到屏幕                        |
| add to screen      | UI- widget | 添加到某个玩家的界面,比如多人游戏 |
| remove from parent | UI- widget | 移除不会删除,只是隐藏看不见了     |

### text

| 函数                 | 父类           | 说明                                |
| -------------------- | -------------- | ----------------------------------- |
| fallback font family | UI-font        | 使用的默认字体                      |
| Anchors              | UI- widget     | 锚点,                               |
| Alignment            | UI- widget     | 方框的参考点                        |
| size to content      | UI- widget     | 方框大小随文字变化                  |
| Z-oder               | UI- widget     | 显示层级                            |
| outline size         | UI-widget-text | 描边,可以加独立的材质               |
| strike brush         | UI-widget-text | 下划线,需要纯色或者图片             |
| warping              | UI-widget-text | 文字是否换行                        |
| tool tip text        | UI-widget-text | 鼠标移上去显示内容                  |
| shear                | UI-widget-text | 水平或者竖直错切                    |
| clipping             | UI-widget-text | 裁减选项                            |
| navigation           | UI-widget-text | 从 一个控件到另一个控件的交点的转换 |



### 按钮

- 不同的是有事件
- UE4只能播放WAV声音
- UE4的播放是多轨的,放了不管,需要单独控制,加一个组件 audio,可以控制播放;
- 增加一个音乐控制的类,mymusic,加一个组件 audio;



| 函数                   | 父类              | 说明                                            |
| ---------------------- | ----------------- | ----------------------------------------------- |
| padding                | UI-widget-button  | 和边框的距离,就算是0也不是贴合,和本身内容有关系 |
| normal                 | UI-widget-button  | 正常时候                                        |
| disabled               | UI-widget-button  | 禁止按的时候                                    |
| hovered                | UI-widget-button  | 鼠标放上去                                      |
| pressed sound          | UI-widget-button  | 按钮声音                                        |
| play sound at location | audio             | 在空间中播放                                    |
| play sound 2D          | audio             | 全局声音                                        |
| is playing             | components- audio | 是否在播放                                      |
| Get play state         | components- audio | 播放状态                                        |
| adjust atttenuation    | components- audio | 声音的衰减                                      |










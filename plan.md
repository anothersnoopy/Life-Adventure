~~### Plan :~~

~~outhome、sleep添加负面扣分~~

~~可以添加一个初始化summary，判断打开的文件是否有Summary，如果没有，写下初始化summary，各分数均为零；~~

~~或者，判断是否有summary，没有就直接在函数内部初始化summary各项为0，然后再正常运行其他功能。~~


~~改进sleep，改为从睡觉时间自动判断分数~~

~~试试把数据类型改为private： down~~

~~+ 添加每日备注功能（是否写备注？若是，进入编辑模式）~~

~~完成健康百分比、能量百分比、Spirit百分比~~



### 添加功能的步骤：

+ class.h：类函数公有成员添加相关功能函数声明，并在私有成员里定义对应分数
+ function.h：
 > + 构造函数初始化对应分数
 > + 开头定义静态总分
 > + 撰写void功能函数的函数体
 > + 在Write summary函数里写下对应的total分数
 > + 在read函数里读取相应变

+ main.cpp：引用新添加的功能






### Level / Health / Energy / Spirit

| item   | factor                                   |
| ------ | ---------------------------------------- |
| Level  | total_score                              |
| Health | sleep, S, NFN, sport, unhealthy info     |
| Energy | health, outhome, gamewkd,  UNB, word, cnpaper, enpaper,review |
| Spirit | energy，OTG, PP, sunny mind, dark mind    |



level 1

Health 总分1000分；

Energy总分 3000分；

Spirit总分 5000分；

API特征：
	信息隐藏
	一致性
	松耦合

API应该对它所解决的问题提供逻辑抽象。
物理隐藏：
	将内部细节(cpp) 和 公有接口(.h) 分离， 储存在不同的文件中。
逻辑隐藏：
	封装提供了限制访问对象成员的机制。
	Java中的包私有表示该成员只能被同一个包中的类访问。
	C++使用更加宽泛的友元概念， 以允许指定的类和方法访问某个类的受保护的或私有的成员。
	
封装是将API的公有接口与其底层实现分离的过程。

逻辑隐藏指的是使用C++语言中受保护和私有的访问控制特性从而限制访问内部细节。


按照良好API的设计原则， 不应该将成员变量设置为公有的。如果数据成员构成了
API逻辑接口的一部分， 那么应该使用getter或setter方法间接地访问成员变量。
使用getter或setter有下面地好处：
	有效性验证
	惰性求值
	缓存
	额外地计算
	通知
	调试
	同步
	同精细地访问控制
	维护不变式关系

类的数据成员应该始终声明为私有的， 而不是公有的或受保护的。

类只应该定义做什么而不是如何做 

信息隐藏的原则是： 将类的固定接口与其内部实现设计实现相分离。 


永远不要返回私有数据成员的非const指针或引用。 这会破坏封装性。

将私有功能声明为cpp文件的静态函数， 而不要将其作为私有方法暴漏子啊公开的头文件中，

优秀的API设计应该是最小完备的。 即它应该尽量简洁 

资源分配是对象构造， 资源释放是对象析构。 RAII资源获取即初始化
 
 C++API不应该在公共头文件中出现平台相关的#if#ifdef语句
 
 耦合： 软件组件之间相互来南京的强度的度量， 即系统中每个组件对其他组件的依赖程度。 
 内聚：  单个软件组件内的各种方法相互关联或聚合强度的度量。
 
 除非确实需要#include类的完整定义， 否则应该为类使用前置声明
 与成员函数相比， 使用非成员、非友元的方法能降低耦合度。
  
  图中的文字内容如下：

在C和C++中，回调是模块A中的一个函数指针，该指针被传递给模块B，这样B就能在合适的时间调用A中的函数。模块B对模块A一无所知，并且对模块A不存在“包含”（include）或者“链接”（link）依赖。回调的这种特性使得低层代码能够执行与其不能有依赖关系的高层代码。因此，在天型项自中，回调是一种用于打破循环依赖的常用技术。

有时为回调函数提供一个“闭包”也是有用的。闭包是模块A传递给模块B的一条数据，该数据是给模块B的一种途径。

请注意，文本中有一些可能是OCR识别错误的地方，例如“天型项自中”可能是指“在通常情况下”，“车A报进”可能是“作为”的错误识别。如果需要更准确的文本，请提供更清晰的图像或文本。

### 读Chapter4的随笔

***
#### Item 18 Use std::unique_ptr for exclusive-ownership resource management
-   默认的std::unique_ptr<*> 可以认为与raw_pointers的大小是一样的，当你使用自定义的deleter的时候就不一样了
    具体大小取决于你的function state，若是captureless lamda那么对象大小就是没有发生改变，如果是function
    或者是带状态的lamda,unique_prt的大小就会发生改变
-   std::unique_ptr有带[]和不带[]两种形式one for individual objects (std::
unique_ptr<T>) and one for arrays (std::unique_ptr<T[]>). 使用的话就跟单对象和多对象数组的区别一样
-   Pimpl Idiom:指向实现的指针(这种trick用在类的实现中很方便，可以隐藏被指向类的变化，达到降低耦合的效果)
    带状态的lamda比较适合这种,在**Item22**有具体解释
-   还有就是unique_ptr可以直接转换为shared_ptr，简直不能在方便了有木有

#### Item 19 Use std::shared_ptr for shared-ownership resource management
-   shared_ptr 的大小是raw pointer的2倍，他还额外包括了一个指向control block的对象，之中包括引用计数,weak_number, 以及自定义的deleter和alloctor if have.
-   shared_ptr一般情况下只能指向动态分配的内存，但是make_shared可以避免这样的存储开销
-   因为shared_ptr在进行reference count的修改的时候，需要是原子操作，**也就意味着，如果系统是时间要求很高的，就不能使用该指针或者说需要注意该指针带来的性能消耗**(**仅仅是读的话，性能损耗应该是小的，但是如果,在多线程环境下涉及多次的写的时候,就需要小心**)
-   如果使用move进行shared_ptr的ownership tranferring，这个过程不涉及引用计数的修改(原子操作),性能损耗会小很多
-   **不像unique_ptr，自定义的deleter不用放在模板参数里面，这样给了shared_ptr相当大的灵活性，所有的shared_ptr都是可以互换共享的**
-   AS for control block(CB),make_shared保证会产生一个CB，当从unique_ptr构造shared_ptr时也会创造一个CB, shared_ptr从一个raw pointer构造时会产生CB,
    如果想要把一个已经存在CB的对象传给shared_ptr，可以直接传送一个weak_ptr或shared_ptr.
-   **尽可能的不要把一个raw pointer 传给一个shared_ptr, multi-control-block 会出现，你的头会变大**
-   Curiously Recurring Template Pattern (CRTP) 用法：CRTP的出现是为了兼顾多态性以及效率，短的继承对于效率来讲，
    不是大的影响，关键是长的多重继承会影响效率，CRTP的出现兼顾二者，具体看这篇文章![C++ 惯用法 CRTP 简介 ](https://liam0205.me/2016/11/26/Introduction-to-CRTP-in-Cpp/)
-   std::enable_shared_from_this:给予一个有shared_ptr管理的对象，以用this 生成一个shared_ptr对象的能力.也就是提供了将this这个raw pointer 转变成shared_ptr的能力。最主要的是防止多个shared_ptr对象的生成. 在原来内部使用this指针的地方，现在使用shared_from_this()
-   shared_ptr里面甚至存在virtual function用来释放对象，好在只有在对象释放的时候才调用
-   shared_ptr和unique_ptr不同的地方是：**unique_ptr提供指向原始数组的能力，而shared_ptr不提供，如果你需要的话可以选择使用std\::array,std\::vector**

#### Item 20  Use std\::weak_ptr for std::shared_ptr like pointers that can dangle. 
-   weak_ptr不能解引，也不能测试是否为空，他不是一个人，一般来说，他会与shared_ptr配合
-   weak_ptr可以用在缓存中，weak_ptr.lock()返回一个shared_ptr对象，如果指针之前是空的,即weak_ptr指向的对象已经被消除，那么得到的shared_ptr对象是nullptr
-   weak_ptr可以用在观察者模式中，因为被观察者只是想要知道观察者是否存在，而不会想去操作观察者，weak_ptr是一个相当匹配的选择
-   当然weak_ptr可以用来解决循环引用的问题，这个自然是不能被忘掉的
-   有一点需要注意的是在shared_ptr的CB中，含有一个与weak_ptr有关的计数，see next item.

#### Item 21: Prefer std\::make_unique and std::make_shared to direct use of new
-   软件工程的一大原则，不要使用冗余重复的代码
-   使用make_*的一个原因是，避免将new object操作和construct a shared_ptr操作分开，不然出现异常就会导致内存泄漏，在effective CPP中也有这样的说法,
    **个人还是更加倾向于分开写，我的意思是，不要把过于复杂的代码都写在一行里面，影响理解难于维护**
-   以下两行代码的对比：
     
        std::shared_ptr<Widget> spw(new Widget);
        //上面的进行了两次内存分配，一次给widget，一次给control block
        auto spw = std::make_shared<Widget>();
        //上面的只有一次，或者说，一次干了上面两次的事，把CB和object分配在一起了，效率更高
    **emmmm，测试数据其实并没有支持"效率会提升"的这种说法, 具体看item21.cpp的执行结果，效率前者要比后者高1.5倍的样子**
-   但是make_*不能像new一样自定义需要的deleter.
-   另外一个限制在于make_*不能使用braces initializer，虽然braces initializer 也并不能完美转发
-   **对于shared_ptr来说，如果一个对象使用自定义的new和delete，这个时候使用make_shared会使得CB和object分配在一起，然后当对象被destroy的时候，如果还有weak_ptr指向该对象，由于CB和object一起分配，不能单独释放内存,会造成对象和CB占用的内存一直都在，对象如果比较大，会造成内存的不够用,而直接new则不会有这种情况**
-   书上给了一个为了达到exception-safe和tiny higher performance的trick：use lvalue to get exception-safe and use move if possible for performance.
    
####  Item 22: When using the Pimpl Idiom, define special member functions in the implementation file.

-   unique_ptr经常用来实现Pimpl
-   Pimpl可以降低编译依赖,减少编译时间
-   std\::unique_ptr不支持incomplete type，而std::shared_ptr则是支持的(不完整类型：声明但是未定义),
    **对于unique_ptr这个地方有点疑惑，不声明destructor，会使用编辑器默认的实现，然后会遇到static_assert,因为类型不完整而无法通过，但通过将destructor变成=defualt,就可以解决，那么使用编译器生成的和=defualt 有什么区别的**
-   对于unique_ptr来说，将声明和实现分开来写，即使是使用=default,来实现
***


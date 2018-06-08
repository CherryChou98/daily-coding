### ��Chapter1�����
#### Item 1  template  type deduce
-   reference  is discarded during .
-   it's normal when Paramtype is pointer or reference 
-   Universal reference means rvalue reference .
    -   **lvalue is deduced as lvalue reference .**
    -   rvalue  is still a rvalue reference .
-   ParamType is neither pointer nor reference , namely by value.
      -   all the constness and reference -ness are discarded.
      -   An exceptional case is that when the arguments passed in is an\
          const pointer  to const type, the ParmType will become non-const\ 
          pointer to const type

-   ����T&�� if you pass an array type, the ParamType will be deduced as\
    actual type of array
    -   ����Ϊconstexpr�ı��ʽ ��**������**����ʹ��,**���£�**
    
            template <typename T, std::size_t N> 
            constexpr std::size_t arraySize(T (&)N) noexcept
            {return N;}

            int value[]={1, 2,3};
            int mappedavalue[arraySize(value)];
            //of course, ���ʹ�����õ�array
    -  �����Ǻ�����ʱ������array�������ͬ

            void someFunc(int, double); // someFunc is a function;
            // type is void(int, double)

            template<typename T>
            void f1(T param); // in f1, param passed by value

            template<typename T>
            void f2(T& param); // in f2, param passed by ref

            f1(someFunc); // param deduced as ptr-to-func;
            // type is void (*)(int, double)
            f2(someFunc); // param deduced as ref-to-func;
            // type is void (&)(int, double)

***

#### Item 2  auto type deduction

-   This is exactly the same as the cases in Item 1
-   auto can get different types by different declaration  forms

        auto x1 = 27; // type is int, value is 27
        auto x2(27); // ditto
        auto x3 = { 27 }; // type is std::initializer_list<int>,
        // value is { 27 }
        auto x4{ 27 }; // ditto 
-   there are two dedection happened, one is auto, another is std::initializer_list<T>

        auto x3 = { 27 }; // type is std::initializer_list<int>,
-   ����Ĵ����õ�**ģ���ƶ�**����auto�ƶ�

        auto createInitList()
        {
        return { 1, 2, 3 }; // error: can't deduce type
        } // for { 1, 2, 3 }
***
#### Item 3 understand decltype  

-   c++�е�containerһ�㷵�ص������ã���Ҳ���ڷ���value �����
-   **universal reference ==��ֵ����**����Ҫʹ�������������ܵĲ������ܼ���\
    ��ֵ���ֿ�������ֵ��ͬʱҲ�뱣�����������(ͬʱ����),������д����
-   decltype ����**���ʽ**�Լ�decltype((x))���͵ģ����ǲ�����ֵ����
-   **(c++14)** decltype(auto) ���Ƶ�����ֵ��ʱ����Ϊ�˽��д��������õ����
-   decltype ���޸ı��ʽ�����ͣ�����auto��omit reference

//ע�ͣ�mayer����������Ĭ����
**That��s the kind of code that puts you on the express train
to undefined behavior��a train you certainly don��t want to be on.**



***

#### Item 4 How to view the deduction of type

-   By IDE, compilers diagnose , or by boost libraries.
-   **NOTE**, the type name coming from  standard library maybe not right \
    as you think, Be caution.
-   boost ����һ��

***

#### ����
derision  ��Ц
admonition ����
nag ��߶
trivial adj. ����Ҫ�ģ�����ģ���ϸ��
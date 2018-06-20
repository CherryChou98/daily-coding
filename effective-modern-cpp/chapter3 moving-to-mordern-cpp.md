### ��Chapter3�����
#### Item 7 distinguish between () and{} 
-   {}��һ�����������ܵĴ������ķ���(uniform initialization)��������ʤ�δ󲿷�����µĹ�����
-   ���б���narrow conversions:�����ڴ�������ʱ����ת��,
        
        double x, y, z;
        int sum1{ x + y + z }; // error! sum of doubles may not be expressible as int 
    **��g\++�ϳ���ʵ�ֵ�ʱ�򣬷�����ʵg\++������,ֻ���ڱ����ʱ��waringһ�£������ᱨ��**
-    avoid c++'s most vex parse : ʹ�ÿյĹ��캯�����ɶ�������ú���

         Widget w2(); // most vexing parse! declares a function named w2 that returns a Widget! 
         Widget w3{}; // calls Widget ctor with no args
-    **ȱ��Ҳ���е�**: {}����������ϵĲ��������ر��Ƕ��ڹ��캯���к��� std::initializer_list������˵
     ʹ��{1,2}��Ĭ�ϵ���std::initializer_list�ĵ��ã������Ƿ������ƥ��
-    ����һ������Ĭ�Ϻ��������⣬����һ���ն����ǵ���һ�������յ�._list�Ķ���**��page55**
-    ���о�����ʹ�ú���ģ�������µ��жϣ�()��{}���ַ�ʽ�ǲ�ͬ��,����std::vector<*> something\
     (20, 10)   //10��20�� �����{10�� 20} �Ǿ�������ֵ
-    �ܵ���˵���������߶���֮��һ������� **\{}** ���ǱȽ������ 

-    **ATTENTION**, ���´����ڹ���������ͬ:�������ǽ�����copy constructor

         Widget small_widget();
         Widget middle_widget=small_widget;
         Widget middle_widget(small_widget);
-    **������һ��ϸ������**��
            
          Widget(std::initializer_list<long double> init_list){
                cout<<"inside init_list"<<endl;
                for(const auto& temp:init_list ){
                    cout<<temp<<endl;
                }
            }
         //Widget middle_widget{{}};   //���Ϊ0
         Widget middle_widget{};     //û�����
         Ҳ����˵����gnu�ı�����ʵ���ϣ���ʵ����{{}}���ĳ�ʼֵ���Ǹ���һ��Ĭ�ϵ�0ֵ��
         ע��һ�£�����Ժ󱻿�

#### Item 8 prefer nullptr to NULL and 0
-    **ɧ����һö:  �������Է��ز�ȷ����ֵ�������أ�scott**

         auto lockAndCall(FuncType func,
         MuxType& mutex,
         PtrType ptr) -> decltype(func(ptr))
-    avoid overload on integral and pointer types;
     ����˵���������������صĻ����Ϳ��ܳ�����Ӧ�ĵ��û���
-    ��ģ���У�ʹ�ø���� nullptr Ȼ����Ҫ��NULL��0 �����岻����
-    ������һ������֮��ıȽ�

            void f(int ){
                cout<<" int";
            }
            void f(bool){
                cout<<" bool";
            }
            void f(int *){
                cout<<" void *";
            }
            int main(void)
            {
                cout<<"call f(null)"<<endl;
                //f(NULL);   //error
                cout<<"call f(0)"<<endl;
                //f(0);   //output:int
                f((void *)0);   //output bool
                cout<<"call f(nullptr)"<<endl;
                f(nullptr);   //output: void *
                return 0;
                }
#### Item 9  prefer alias declaration to typedef 
-    ���оٵ����Ӵ���ܳ�������Ͳ����ˣ���Ҫ����˼��\
     **ʹ��using ��ģ���л��кܴ�����ÿ��Ա��⣬�����Ӱ�����Ĵ���ĳ��֣�ͬʱ������template��ʹ�ö�����type �����ü���typename**
-    C++14 offers alias templates for all the C++11 type traits transformations , 
     ����sleek���������磺std::remove_const_t

#### Item 10 Prefer scoped enums to unscoped enums 
-   C++98-style enums are now known as unscoped enums.
-   Enumerators of scoped enums are visible only within the enum. They convert
to other types only with a cast.\
   **������������˵��֮ǰ��enums��û����ģ�enums����������Ⱦ�ⲿ�������ռ�**\
   **���µ�enum class �򲻻�**
-   Both scoped and unscoped enums support specification of the underlying type.
The default underlying type for scoped enums is int. Unscoped enums have no
default underlying type.\
    **enum class ������ô��������Ա�����ʽ������ת��,��Ϊenum��**
    **Ĭ��������int,���Ե���int��ʹ��**
-   Scoped enums may always be forward-declared. Unscoped enums may be
forward-declared only if their declaration specifies an underlying type.
    **enum class �����������������壬so-called forward-declaration**\
    *���ϻ�����һ�����㲻һ���ļ����µ�tuple���õ����ӣ����ǱȽϷ���, ����д����Ҳ����Ư���Ͳ��Ǻ�ע��*
    
#### Item 11 Prefer deleted functions to private undefined ones.
-   ���ϵ�һ��������ʹ��delete���ܾ���ʽת��������������ʵ����ʹ��explicit����ɣ���������Ϊһ����ֵ�����\
    **��ʵ����ͨ�����ض���constructor����Ϊdelete���ܾ�һЩ�ض���ʵ����**
-   ���������һ�����ɣ�ʹ��delete��ʹģ��ܾ�һЩ�ض������� ʵ�����������ʱͦ���õ�

#### Item 12 Declare overriding functions override
-   ��������ʾ������override�Ļ������������û����Ӧ�ĺ�����compiler�ᱨ��
    ���������Ŵ��ڱ��������ִ���
-   �����Item�£����߽��������һ��֪ʶ�㣬�����ڳ�Ա�������������η�
    �����˼������ڶ�Ӧ�Ĺ������ģʽ���棬������ɹ���������һ�����Ժ�����ʱ����ֵ��\
    �����ֻ�������������ʱ���һЩ���ݣ�Ȼ�������ͱ������ˣ��������ʹ�������ķ��������η��Ļ�\
    ��һ���˷����ܵķ�ʽ����ʹ����ֵ�������η����κ����Ժ���������ķ��صľͻ���\
    ����ʱ�����ֵ���أ����ʱ��Ͳ��ý�������һ�ε�copy-constructor

#### Item 13 Prefer const_iterators to iterators
-   c\++98�е�const�ǲ��ܺ��õģ���c\++11�н����˺ܴ���Ż�, 
-   �±�׼���������������õ�const_iterators, 
-   c++14�����˶���std::cbegin(container &C)�Ͷ�Ӧ��cend��֧��
-   �ճ������о�����const_iterator ����scott��effective c++ �е��ᵽ�� use const as far as possible.
    
#### Item 14  Declare functions noexcept if they won��t emit exceptions.
-   ʹ��noexcept �����ڳ������쳣��ʱ�򣬱�֤���еĶ��󶼱�����
-   noexceptֻӦ��������ȷ����non-except�ĺ�����ʹ�ã�����
-   ��98��׼���ʵ���У�����push_back����ǿ���쳣��ȫ��֤��Ȼ����Ա�֤��������쳣��ԭ���Ķ��󲻻��������\
    ��c++11�г�����move���壬���ֱ��ʹ��move���ԭ����copy��������ִ��󣬽��޷����������״̬�����Զ����������\
    ֻ����move�����׳��쳣���֣�����Ҳ����˵��ֻ�е���Ӧ����ײ��ʵ����nonexcept��ʱ��container�Ż�ʹ��move�汾��
    push_back.(STLһ�������, �������ֱַ�ʹ��copy��move��push_back)

            template <class T, size_t N>
            void swap(T (&a)[N], // see
            T (&b)[N]) noexcept(noexcept(swap(*a, *b))); // below
            template <class T1, class T2>
            struct pair {
            ��
            void swap(pair& p) noexcept(noexcept(swap(first, p.first)) &&
            noexcept(swap(second, p.second)));
            ��
            };
            //��ʵ�ֿ������е㵰�۰�
-   c++11�����е��ڴ���亯��Ĭ�϶���noexcept�������Ƿ������������Ϊ�ڴ����ʱ�����exception�������\
    ������Щ���к��е�data member ����һЩ������ܻ���except��ʱ��
-   functions with **wide contracts** ��˼����û���Ⱦ����������ڴ���Ĳ���û�����ƣ������ĺ���������ʾδ������Ϊ
-   �е�library designer ������ wide contracts and narrow contract������wide *���߿��ܻ�ʹ��noexcept�汾��ʵ��
-   noexcept��һ�ֺ����ӿڣ�caller may depend on it.
-   noexcept����swap��move��memory deallocation function and destructors �ô��ܴ�
-   **��һ�ڣ��е��Ѱ�, ���Ǻ����**
    
#### Item 15  Use constexpr whenever possible
-   constexpr ��ֵ�������ڱ����ڿ�֪�ģ������constexpr���ʽ�ܹ���ʹ�ó�����λ��ʹ��
-   c\++11����constexpr�����ƱȽ϶࣬����c++14�д�඼ȡ���ˡ�����c\++11Ҫ��ʹ��constexpr function
    ������һ��statement��return ��䣬c\++14��ȡ��������Ҫ��(**��Ȼ�Ҳ����õ�gcc���������ǲ�֧��, vs2017���Ե�**)
-   constexpr�������ڳ������룬���Բ�������ʱ����������runtime variable �����ͻ������runtime variable
-   ����˵**c++11��constexpr ��Ա����implicitly��const�ģ���c\++14��ȡ��������������**(���Ҳ��Ե�gcc��--std=c++14 ��Ȼ������, vs2017���Ե�)
-   **����constexpr �������߱����������һЩ����ʱ�Ŀ��������ǻ����ӱ���ʱ��**
-   **constexpr is part of function interface.** Ҳ���ǿͻ��˵�����Ĵ����������������constexpr�����˸Ķ���
    �ͻ����ĺܶ���붼���޷�ʹ��
#### Item 16: Make const member functions thread safe 
-   mutable ��const�����У�ʹ�øı�ֲ���constness. ����mutable����������const ��Ա��������Ҫ�����̰߳�ȫ�ԡ�
-   �ں�����mutex��class����move-only�Ĵ���mutex �ǲ�����copy��
-   **std::atomic �ɱ�Ҫ��ʹ��mutexҪСһ�㣬������Ҫ����ʹ��atmoic**, ���ǻ���˵������ 
    ����Ƕ��atmoic�����Ļ����ڶ��atomic֮����γɿ�϶����ɷ�ԭ���ԣ���������Ҫʹ��mutex�ˣ�û�а취��
#### Item 17: Understand special member function generation.
-   ���ڿ���move�Ķ��� move and move-assigning ʹ��move����������ԵĻ�������ʹ��copy�����
-   ��c++��copy constructor��copy-assignment ��ͬ(���Զ������е�һ��ʱ�������һ��û�ж���Ļ��б�����������)�� move������partner move-assignment 
    �������������Զ�������һ����ʱ������һ���򲻻��б��������ͣ�**ԭ�����ڣ����Զ�������������һ�����㶼Ӧ��ȥ��������һ��**
-   ���� copy operation(constructor or assignment) ��Ĭ��ֹͣ move operation (constructor or assignment)�����ɣ�ԭ����**�����Զ���һ��copy operation ʱ��,**
    **���Ѿ��϶��������class Ĭ�ϵ� copy���ʺ�������ʹ�ã���ôcopyҲ���ܲ����ʣ�������Ҳ�����������������copy operation��Ӧ��copy operationҲ����Ĭ�ϵ�����**
-   *the rule of three*: �ǹ���copy constructor and copy assignment and destructor
    **�����Զ������е��κ�һ����ʱ�򣬶���ζ�����Լ����ڴ�/���������ô���������Ҳ����Ҫ��**
-   �û��Զ����destructor �����Ʊ���������move operation
-   ������ҪĬ�ϵ�move ��destructor���Ǳ���Ҫ���ʱ�򣬿�����"=default"��ʹ��Ĭ�ϵ�,
    �����һ�������ǣ����������������һ�� destructor��ʱ��ԭ����move������ܲ�����Ч���������֮ǰ����ʹ����move���壬�����򵥵��޸ĺܿ���������ܵľ޴���ʧ
-   move operation��copy operation Ĭ���ǻ���ģ����������ǰ�ߣ�����������Ĭ�����ɺ��ߣ�����ǰ���Ǳ� overload�ģ�������move��copy�����汾��������ɺ��ߵ�����
    �������Ϊʲô����ǰ���Ժ�Ͳ���Ĭ�����ɺ��ߵ�ԭ��֮һ
-   һ����������ǵ����constructor��destructor��ģ�庯����ʱ��compilers��Ϊ������Ĭ�ϵ�copy and move operation.
-   ������һ������![Rule-of-Three becomes Rule-of-Five with C++11?](https://stackoverflow.com/questions/4782757/rule-of-three-becomes-rule-of-five-with-c11) ���޴�Philipp��
***

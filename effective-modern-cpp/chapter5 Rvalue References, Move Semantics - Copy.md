### ��Chapter5�����

***
####  Item 23: Understand std\::move and std::forward 

-   ���еĲ����Ķ�����ֵ(�е�ַ�Ķ�����ֵ)
-   move��forward������ʱ�������κε����飬����һ��ģ��,�ڱ���������Լ�Ҫ������
-   ���ʹ�õ�move�Ļ�����������const��������������copy constructor
-   move��֤���ǣ�һ�������һ����ֵ
-   forward��һ��conditional cast��ֻ�е��������Ĳ�������ֵ��ʱ�򣬲Ż����ת��,
    �����ǲ�����ֵ�������Ϣ�Ǳ�������ģ��Ĳ���T�����

####  Item 24: Understand std\::move and std::forward 

-   ���߰�**universal reference**��������ˣ�������Щc++ community member ����Ϊ **forwarding reference**
-   universal reference �� rvalue reference��ʽ��ͬ���������岻ͬ��ǰ�߿��Գн�һ�����ͣ�������Ҫ���һ��std::forward 
-   һ�����ں���ģ���������auto�����ƶ�:����:�����ƶ�
-   ��ʽһ����T&&,���ǲ����ԣ�Ҳ�б����vector�е�emplace_back()�е�Argsͬ����һ��universal reference

        template<class T, class Allocator = allocator<T>> // still from
        class vector { // C++
        public: // Standards
        template <class... Args>
        void emplace_back(Args&&... args);
        ��
        };
-   std\::move���κ�ʱ�򶼻�ȥ���Խ�����ת������ֵ����std::forwardֻ���ڴ�����������ֵ��ʱ�򣬲Ż������ֵ��ת��

####  Item 25:Use std::move on rvalue references, std\::forward on universal references

-   universal reference
-   �Ժ����ķ��ض���(local)��������Ĭ��ʹ��std::move,�������ν�� return value optimization(RVO):
    RVO������������1. ����ֵ�����뺯��������������ͬ. 2.���ص���һ��local object.
-   ��Ҫ��forward��move���ڣ�����RVO�����ķ���ֵ
-   ��������һ���������move��������ô�Ͳ�Ҫ��������Ϊconst���͡� ��һ��const����ִ��move���������𿽱���Ϊ��
   
####  Item 26: Avoid overloading on universal references.
-   universal reference��һ���ǳ�**̰��**(greediest)���ƶϣ�������ʱ����������ƥ�����еĲ�������
-   ����UR���õĺ�������ctorʱ�����ܻ���ȵ�ƥ�䵼�²���Ҫ�Ľ������
####  Item 27: Familiarize yourself with alternatives to overloading on universal references.
-   ������Ҫһ��URͬʱ�ַǳ���Ҫoverload��ʱ�������ʹ��һЩsmall trick.
-   abandon overloading
-   pass by const T&
-   pass by value(and use std::move)(��˼���ǲ�Ҫʹ��UR)
-   use tag dispatch
        
        template <typename T>
        void LogAndAddImpl(T&& name, std::false_type){
            cout<<"inside the int"<<endl;
        }

        template <typename T>
        void LogAndAddImpl(T&& name, std::true_type){
            cout<<"inside the string"<<endl;
        }
         
        template <typename T>
        void LogAndAdd(T&& name){
        //	using remove_ref=std::remove_reference<T>;
            LogAndAddImpl(std::forward<T>(name), std::is_integral<typename std::remove_reference<T>::type>());
        }
-   ����һ�ְ취������type_traits�е���������ģ���ʹ��, ��enable_if�����������ڶ���ģ��ʵ�����ļ�飬��������������ʵ����������Ͳ����������������ĺ��������û�У�error
   ��ʹ��remove_reference�Ƴ�����
-   ʹ��UR is effective������Ҳ�л��������ǿɶ��ԣ�ά���ɱ���������
-   ����岥һ��SFINAE: �ҵ�����ǣ�����overload �����Ĳ�ͬƥ���ڱ��������һЩ�ж�,enable_if��������ʵ�ֵ�

####  Item 28: Understand reference collapsing
-   ���÷ֽ�����������������е�һ����lvalue�����õ��Ľ������lvalue,ֻ����������rvalue��ʱ�򣬽������rvalue
-   ����auto&& ��ģ���ƶ����⣬��������ֳ������÷ֽ������ǣ�generation and use of typedefs and alias declarations 
-   Universal references are rvalue references in contexts where type deduction distinguishes lvalues from rvalues and where reference collapsing occurs.

####  Item 29: Assume that move operations are not present, not cheap, and not used.
-   ����c++98�Ĵ��룬���class��������copy cotr������ʽ������move cotr������������ʹ�õ������ܵ�move�����ģ�
-   ��һЩstring ����������ʵ���ǲ�����SSO(small string optimization)���������������move���������þͱ�copy������ܶ�
-   ��������һЩ���,No move operations, Move not faster,Move not usable,Source object is lvalue����Щ����£�ʹ��move���������þͻ��ܶ�
-   д���ʹ����ʱ��Ӧ��ע�⣬��һ�ֱ��صķ�ʽȥ����,����������move Ҳ��һ�������Ч��
-   ���ȷ��ʹ�õ�type֧��move ���壬�ʹ󵨵��ð� 

####  Item 30: Familiarize yourself with perfect forwarding failure cases

-   �������۵�perfect forwardһ����ָ���ô���
-   ���µļ�������»����forwarding failure:�������ƶϳ��������޷��ƶϵ������
    -   Braced initializers:ԭ��������forward���ڶ���������ʱ��compiler�����������ʽת��
    -   0 or NULL as null pointers
    -   Declaration-only integral static const data members:������ static const���󣬻�������ʱ����ָ�룬��������ʧ�ܵ�ԭ��Ҳ���ܱ���������linker���Լ����д���
    -   Overloaded function names and template names:�����غ�������ģ������������ʱ�򣬻�ʧ�ܣ�Ȼ��ʱ�õ�ʱ�򣬿���ѡ��Ժ���ʹ������ָ�룬��ģ��ʹ��stati_cast
    -   Bitfields:����bits�ǲ����еģ�����ѡ��ʹ��һ������copy����ʹ��forward
    

***


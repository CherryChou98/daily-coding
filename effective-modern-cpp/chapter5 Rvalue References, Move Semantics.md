### ��Chapter4�����

***
####  Item 23: Understand std\::move and std::forward 

-   ���еĲ����Ķ�����ֵ(�е�ַ�Ķ�����ֵ)
-   move��forward������ʱ�������κε����飬����һ��ģ��,������������Լ�Ҫ������
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
-
***


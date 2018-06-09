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
         Ҳ����˵����gnu�ı�����ʵ���ϣ���ʵ����{{}}���ĳ�ʼֵ���Ǹ���һ��Ĭ�ϵ�0ֵ��**
         ע��һ�£�����Ժ󱻿�

#### Item 8 prefer nullptr to NULL and 0
-    **ɧ����һö:  �������Է��ز�ȷ����ֵ��ɧ�أ�scott**

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
   

***

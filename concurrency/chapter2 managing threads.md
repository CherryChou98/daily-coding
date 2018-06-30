### ��Chapter2�����

-   thread()�Ĳ�����Ҫ��һ���ɵ��õĶ��������һ������()���������࣬ͬ��������Ϊ����(ֱ�Ӵ�������),
    ���������Ķ����ر���ѿ�����ñ���������ע��
-   �����������ñ���:ʵ����˼�Ƕ�����һ���������ܲ���������thread����
    
        std::thread my_thread(background_task());
        auto my_thread(background_task())->decltype(std::thread);  //��������Ҳ��
        std::thread my_thread((background_task()));    //����Ҳ��
        std::thread my_thread{background_task()};    //����Ҳ��
-   joinable()�������жϽ��̵Ŀ�join��
-   ����һ��join���쳣��ȫ�Ե��ж�:���Ҫ�����join���Ǿͱ���ȷ���쳣���������Ȼ��ȫ
    ���Բ���try-catch�ķ�������ȻҲ���Բ���RAII�ķ���������Ͳ���try-catch�ˣ���һ��RAII��ʵ��
    �����detach�Ϳ���ֱ�ӽ�����

        using namespace std;  
        class thread_guard:boost::noncopyable{  
            public:  
                explicit thread_guard(boost::thread& t):t_(t){}  
                ~thread_guard(){  
                    if(t_.joinable()){//����Ǻ��б�Ҫ�ģ���Ϊthread::joinֻ�ܵ���һ�Σ�Ҫ��ֹ�����ط�����join��  
                       t_.join();  
                    }  
                }  
                thread_guard(const thread_guard&)=delete;
                thread_guard& operator=(const thread_guard&)=delete;  
            private:  
                boost::thread& t_; 
        };  
-   fire and forget : means һ�������������������˾Ͳ�����
-   �̴߳��صĺ������ʹ�õ������ã�����ҪС�ģ������ָ�����Ǵ����ڴ���δ��ɵ�����£���ָ�����뿪��
    ���ʹ����ֵ������ʹ��ǿ��ת������ʹ��std::ref ���ɶ�������.
-   ����������copy��ʱ������Գ���ʹ��std::move

        std::thread t(process_big_object,std::move(p));   //p��һ��unique_ptr
        std::thread t(process_big_object,std::move(std::unique_ptr<DATA>(new DATA()));
-   ����һ���̣߳�Ҫô�����Ժ�ͷ��룬Ҫ�����Ժ��join
-   ��Ҫ��һ���������е��̶߳��󣬸�ֵ������һ���������е��̶߳��󣬻�����
-   std::thread::hardware_concurrency() ��ȡӲ�����ģ����ܻ᷵��0
-   thread.get_id()ֻ��֤���ڱȽϵ���ȫ֧�֣�����һ��ı�׼�������ƽ̨������

### ��Chapter4�����

****

-   ʹ������������ͬ��, **std\::conditional_variable��std\::conditional_variable_any**, ǰ��ֻ��ʹ��mutex,���߿�ʹ���κ�������������(�����ϻ���һ�����)
-   ��ʹ���еȴ��߳�û�б�notify_one����, ֻҪ�������㣬Ҳһ�������߳���Ϊspurious wake��������������� 
-   ʹ����������һ�����õ���������ֻ����֪ͨ���õ��߳���˵������ʹ�û�����+guard_lock����ʱ�����
-   ��������������ʹ�õ���Ӧ��֧��lock��unlock
-   spurious wake:�߳��ڵȴ��������������еĻ��Ѽ�飬���������������������ʹ���˺���side-effects�ĺ���,���ܻᷢ����εĸ�����
-   ����member const ��Ա����������ڲ������Ļ���������Ҫ����Ϊmutable�ģ���Ϊ�������Ĳ�����mutable��
-   ��һ�εĽӴ���future���������ͨ���������������ģ��ϴ���modern effective cpp�е�
-   future obj:suitable for one-off event.
-   async:��һ��������������Ա������ָ�룬��ô�ڶ����������౾������ָ�����std::ref()����һ��
-   std\::packed_task��std\::promise:ǰ���Ǻ��ߵĸ߽׳���:promiseֻ�������˹����״̬,��packed_task�����ڲ������һ��task,
    -    std\::packed_task<int(double)> ����ȫƥ��, ��������ʹ��int������ֵҲ��ʹ��double
    -    ��std::packed_task��get_future�õ�future����
    -    std::ͨ��std\::packed_task��thread ����������һ���߳�������ȡ����Ľ����
    -    ����ֱ�ӵ���
-   ͬstd::packed_task����,std\::promiseͬ����std\::future���ʹ�ã�ͬ����get_future��������promiseʹ��set_value��������Ӧ�ĵȴ�future��õ�֪ͨ�����promise�����٣�����һ��exception �洢����(std\::packed_taskҲ��),(���Ͻ���һ��ϸ�ڣ���׼û�й涨�����exception�����û���һ��copy)
-   std::promise��һ������set_exception������������exception
    -   һ�ְ취��ʹ��try...catch��䣬��catch�������� some_promise.set_exception(std::current_exception());
    -   ��һ����ֱ��ʹ��some_promise.set_exception(std::make_exception_ptr(std\::logic_error("����"))
    -   ����ֱ��destory promise(std::packed_task)
-   std::shared_future�ɹ�����߳̽����첽��ȡ
-   std::future �е�����ֻ������ȡһ��
-   future�ṩ��.share()����������������һ��future�ı��ݣ���������shared_future
-   ʱ�ӵ�ʱ���������÷�������ʾ�ģ���std::ratio<1,25>��˼��ÿ��25��tick, ��������ʱ��ʱ�����ڲ�����һ�ɲ����
-   steady_clock����ָʱ�����ڲ��ᷢ���ı��clock,��std::chrono\::system_clock�Ͳ���һ��steady_clock
-   ����һ��ʱ����std::chrono\::high_resolution_clock.
-   chrono�л���durationģ��,��һ�������൱�ڸ������ڶ����൱�ڵ�λ,ʹ�÷���std\::ratio<>, ��std::duration<int, std\::ratio<1,10>> ����ζ��ÿһ��int���涼��1/10����
-   chrono�кܶ�predefine typedef, ��nanosecond,microsecond,��
-   c\++14�ṩ��һЩtrick,std::chrono_literals��15ns,16ms��,
-   duration��ת������ʹ��duration_cast<Ŀ�굥λ>, ��ת����truncated��not rounded��
-   ͬʱdurationҲ֧�ּӼ��˳�������
-   future��wait��������3��״̬future_status::time_out, ready, deferred
-   std::time_pointʹ��������������һ����ָ��ʹ�õ�ʱ�ӣ��ڶ�����ʹ�õĵ�λ
-   ��������Ҳ�ǿ�ʹ��ʱ��ĵ�,��wait_for��wait_until
-   time_mutex��recursive_mutexҲ��֧��ʱ����
-   functional_programming(FP):�����ķ���ֵ������й�,���ⲿ��״̬�޹أ� **��ϰ��ʱ��һ��FP������**
-   CSP paradigm�������̶߳��Ǹ�������ȫ�����ģ����ǿ���ͨ��channelͨ�ţ��ֽ���**Actor model**
-   ���ϵ�ATM�����Ӹ��ҵĸо��ǣ�������һ��**״̬��ʽ�ı��**, ÿһ��״̬�Ĵ�����ı䶼��Ҫ����Ϣ�������ı��ģʽ�����ڲ����������Ǽ��ˣ����ڱ仯�Խϴ�ĳ���,**���ƺ���ʤ��**����Ϊ�����״̬���࣬���������ά��
-   std::experimental�ռ�������packed_task, promise, future �ṩ�˶���continuation��֧��, �����std\::future��experimental�µ����������ṩ��ֱ����Ӻ��������Ĺ���
-   ��ԭ����EXP\::future����then()�����Ժ�ԭ����future�Ͳ�����Ч(only use once),ͬʱ����һ���µ�EXP\::future
-   continuation func���ܱ�������,���Ĳ���Ӧ����ȷ���˵ģ�����Ψһ������������EXP::future ����, **���chapter4-4.3**
-   ���߳��ڲ�

        try{
            p.set_value_at_thread_exit(value);
        }catch{
            p.set_exception_at_thread_exit(std::current_exception());
        }//ͨ�������ķ��������÷���ֵ�����߷���ʱ�쳣
-   ����һϵ�е�task,������������̱�Ӱ��,����ʹ��EXP��then()����һ������lambda����
-   continuation�ṩ��һ����Ȥ(nifty)������future_unwrapping������.then()����continuation FUNC(CONFUN), ���confun����һ��future<some_type>��ô��then���صĲ���һ��future<future<some_type>>, ����unwrapping ��future<some_type>
-   **4.4.5�ڵ�listing4.22�ᵽ#1�Ĵ���ᱻ�ظ�����,��֪��Ϊʲô��������⣬ÿһ��getֻ��һ��future��״̬���м�����������future״̬��Ӱ�죿��**
-   ��׼�ṩ��std\::EXP::shared_future,�������������then(),ʹ�ù���״̬
-   std\::EXP::when_all: �����Ҫ�ȴ����future������������е�vector�����е�future����˵�ʱ�򣬷���һ��future<vector<future<some_type>>>��������д���
-   std\::EXP\::when_any��std\::EXP::when_all��Ե����ԣ��κ�һ��ready������������
-   when_any��when_all(����ʹ�õ���������)��֧��variadic��������ʱ�ķ���ֵ��һ����Ӧ��future<some_type>>��tuple,���Ҳ���(future)����by value�����Կ�����ʽ��ʹ��std::move(f1),�������(4.4.6),���ʹ�õ���һ�Ե����������ص�����һ��vector
-   std\::EXP\::latch��һ������������ֵΪ0ʱ���ready, std\::EXP\::barrier,��֤����ص��̶߳�����˵��ʱ�򣬲Ż������һ��
-   **4.4.8����latch����count_down�����͵���wait������ͬ��??**
-   latch�ṩ�ķ�����count_down, wait, is_ready_,count_down_and_wait.
-   barrier�ṩ�ķ�����arrive_and_wait, arrive_and_drop
-   barrierͬ����ʱ������Ҫһ��count���ڲ�����ʹ����latch
-   flex_barrier�����barrier���ĵط��ǣ�ǰ�߶���һ�����캯����������thread_num֮���ټ���һ��Func��**Func����-1���ʾ�߳���Ŀ����,����0 or more ��ָ����һ�ֵ�thread_count**
-   **??��flex_barrier��thread_count�����ı����Ժ���һ�����е��߳�����ô���������߳�����������**
****

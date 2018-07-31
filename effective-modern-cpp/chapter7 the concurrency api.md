### ��Chapter7�����

***
####  Item 35: Prefer task-based programming to threadbased.

-   ����software thread �ļ���ȱ��;
    -   �߳���Ŀ���ޣ����߳������������Ժ󣬼�ʹ����������Ϊnoexcept��ͬ���ᱨstd::system_error
    -   oversubscription:������ָ�߳��ڲ�ͬ��cpu����ʱ���ֵ������½�
-   std::async()��֤������Ҫ������ؽ����ʱ��scheduler��֤�������ǿ��������
-   ��һЩ����£�thread ���ܸ�����(����)
    -   ��Ҫ�����̵߳ĵײ�ʵ��API��pthread or win32ʵ�֣�
    -   ��Ҫ�Լ��Ż��̵߳�ʹ��
    -   ��Ҫʵ��һЩ����thread�ļ�������thread pool

####  Item 36:Specify std\::launch::async if asynchronicity is essential.

-   Ĭ�ϵ�std::async()������ͬ������Ҳ�������첽���У�ȡ���ھ������
-   ��ʽ��������������ʽ��std\::launch\::async��std\::launch\::defererd��ǰ������ִ�У����ߵȵ�get����wait�����õ�ʱ��,
    Ĭ�ϵ�policy�������ߵĻ�����
-   ����defered���첽�������wait_for����wait_until�����std\::future_status\::deferred

####  Item 37:Make std::threads unjoinable on all paths

-   class�ĳ�Ա�����ڳ�ʼ����ʱ�򣬰����䱻������˳���ʼ�������Խ�thread����������������������ʹthread�������������߱����Ժ��ڽ��г�ʼ��������
-   std::thread ֻ���ڵ��ó�Ա����join��detach�����߽�����move����ʱ���Ż��joinable -> unjoinable
-   ��һ��joinable��thread ����destructor�ᵼ�³�����ֹ������ΪʲôҪ��֤unjoinable on all way.Ҳ��Ϊʲô�� c++ concurrency in action�����߽��飬����thread�����õ��Ժ�Ҫ���joinҪô��detach������

####  Item 38: Be aware of varying thread handle destructor behavior.

-   ����promise���ɵ������������future�����н��ж�ȡ��ʱ����Ϊ��Щ���ݼȲ�������caller�д棬�ֲ��ʺ���callee�д棬Standard Library�͹涨����һ����share state���м�λ�ã�����ʵ���ɿ����߾���
-   ����future���󣬵����¼������������ʱ�򣬻���destruct��ʱ��block.ֱ��task finished
    -    ������һ��share state created by a call to std::async
    -    launch policy is std\::launch::async
    -    ��ǰfuture�����һ������share state��future(����std::future���������shared_future����Ȼ)
-   ����ʹ��std::packaged_task��˵���򲻻����������special behavior

####  Item 39: Consider void futures for one-shot event communication.

-   ���߳�ͬ�������⣺��ǰ���ѣ�����reacting thread ���õȴ�; spurious wakeup(��ٻ���):
-   ��������������ʹ��lambda���ʽ����lambda�����жϻ��������Ƿ����㣬����ֹ��ٻ���
-   ���������л�ʱ��̵ܶ�ʱ�򣬿�����atmoic<bool> flag ������ͬ��
-   ��������֮��Ļ���ʹ��future����shared_future,��ʹ��future��ʹ�����ڣ�һ���Բ�����ʹ��heap �ڴ�)

####  Item 40: Use std::atomic for concurrency, volatile for special memory.

-   ��atmoic���󱻸�ֵ��ʱ��ȷ���˱������������Ե�reorder your code.�����atomic ����ĸ�ֵ֮��ı�����ֵ������ֵ����һ��volatile,����Ա�reorder
-   volatile ����memory-mapping I/O�ϣ����Ա���Υ��Ŀ�ĵı������Ż�
-   volatile std::atomic\<int> vai; //�����������������ڲ�������·��������ڴ�
***



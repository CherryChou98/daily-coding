### ��Chapter3�����

-   **���߳��µ�����**��
-   ����:
    -   ����취: ���Ʒ��ʣ�lock-free���(����);ʹ������transaction,����Ҫô���Ҫôʧ��������termed as STM(Software Transaction Memory)
-   c++17�г�����һ������ģ��������Ķ���,���� :

        std::lock_guard<std::mutex> Alock(Amutex)   //������һ����
        std::lock_guard Alock(Amutex)   //�����Ѻã������׿��ɷ���lock_guard��Alock����
-   ��ȫ��lock��װ��class������OO����
-   ���Ż��ƣ������Ǳ�����������Դ�������ָ���������ָ�����Դ���Ǳ���ͬ������Ч��,**���Բ�Ҫ��pointer����reference���뱻���������У�Ҳ��Ҫͨ�����������������Ǳ������ڲ�������,�����֮,��Ҫ�����ⲿ���Կ����Ľӿ�**
-   ������Щ��������class interface ��ɵģ�����stack��top()��empty()����������stack��pop�������������remove�ڽ�pop��Ԫ�ش���������������Ϳ����ڹ����ʱ�򣬳������Ҳ������
    - ����ֱ�ӽ�������������ֱ����Ϊpop�Ĳ���,
    - ����ʹ���̰߳�ȫ��m-c��c-c class,
    - Ҳ������stack�洢Pclass,��ָ�룬����ÿһ��stack�ж�����Ҫnew�����������˸���������ʹ��shared_ptr
-   ����ʵ��һ��thread_safe_stack,ÿһ�������ڶ�Ҫ�Ȼ��class�ڵ�һ��lock
-   std::lock(Args ...)����һ�η������lock��������������Դ���������⣬�ڻ���˶�����Ժ�Ϊ�˱������ǽ���������������ü�ʱ��ʹ��unique_lock����lock_guard���õ���

        std::lock(lhs.m,rhs.m);
        std::lock_guard<std::mutex> lock_lhs(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_rhs(rhs.m, std::adopt_lock);
        //adopt_lock����Ϊ�������������Ѿ��õ�������ֻҪ��adopt_lock��ȡ����Ȩ�Ϳ�����
-    std::lock ֧��all-or-nothing ���壬ȫ�����ϣ�����һ����û��
-    c++17 ֧��scope_lockģ��,һ���˸���lock��RAII_lock������
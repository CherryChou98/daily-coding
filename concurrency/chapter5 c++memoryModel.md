### ��Chapter5�����

****

-   ������Σ�һ���ǻ����ṹ������һ���ǲ�������
-   c++ ��׼��object ����Ϊ a region of storage
-   ������λ���ܾ�����ͬ�ĵ�ַ
-   һ������һ��������undefined behavior, �������򶼻���undefined behavior
-   �޸�˳��(Modification orders)��ÿһ��������һ���޸�˳��,**��������޸�˳����������Ǻܶ�**
-   ÿһ��atomic���󶼺���һ��is_lock_free(),true:ʹ�õ���ԭ�Ӳ�����ɣ�false:ʹ�õ����ڲ���������, **����atmoic_flag(������std::atomic<bool>), ��һֱ����lock-free**
-   ʹ��internal mutex��atmoic<>ĳ�̶ֳ��ϲ������Լ�д��lock-free
-   C\++17 �ṩ��is_always_lock_free�ķ��������ҽ��������е�ƽ̨�϶���������ʱ��ſ���
-   �кܶ��marco���������ж�lock-free
-   ���� ��ȫ֧��c\++17��compiler���кܶ�� alias��������Ӧ��atomic, ������������atomic\<T>������һ���򵥣�������ֲ�Ժ�
-   atomic��֧��copy-c, Ҳ��֧��assign-c:������ͬ�Ĳ����ڲ�ͬ�Ķ����ǲ�����atomic��
-   ÿһ������on atomic����һ����ѡ�� memory  ordering ������
-   **?as such, i'd never expect to see it in use**
-   std::atomic_flagһ������Ҫ��ATOMIC_FLAG_INIT����ʼ��
-   ����atomic type�Ĳ������з��࣬��ͬ�ķ����Ӧ�ڲ�ͬ��memory ordering
-   ʹ��atomic_flagʵ��������(spin lock)
-   atomic����ֵ�������ص�ֵΪby value
-   store�滻��exchange�滻�����أ�load����(������ʽת��Ҳ����ɻ�ȡֵ�Ĳ���)
-   c++ �����У�compare_exchange�ĳ�����һ��ת�۵� **??**, ����������һ��expected value, һ��desire value,���ʱ����Ϊdesire value, �����ʱexpected val����Ϊatomic\<T>��val

        //����compare_exchange_weak ��spurious failure���Ĵ���
        bool expected =false; extern atomic<bool> b;
        while(!b.compare_exchange_weak(expected, true)&&!expected);
-   ���ڼ���򵥵�expectedֵ��ʹ��com_exc_weak��û������,�������������Ϊ��֤��ȷ���ʹ��strong�汾
-   ����atomic<T*>�����std::atomic<bool>������Ĳ�������ǰ��++��--�� +=�� -=�� �Լ�fatch_add(), fatch_sub()
-   fatch_add()��fatch_sub()����swap�İ취, ����ֵ��Ȼ�󷵻ظ���֮ǰ��ֵ
-   ����user-define-type(UDT),������һ�����������Ҳ������Ϊatomic��T
    -   have a trival copy-ass-operator.(**copy-assignment-operator:�������麯��������ಢ�ұ���ʹ�ñ��������ɵ�copy-assignment operator**)
    -   ��UDP��ÿ�������non-static��data member������Ҫ��trival copy-ass operator
-   UDP��copy-ass op ��ͨ��ֱ��memcpy���ģ�ֱ�Ӷ�bit���в������Ƚ�Ҳ�ǣ�ֻ��bit����ȫ��ͬ�ĲŻ�����ȵ�
-   ����float��double��atomic���exchange���п�����Ϊ��ʾ��ʽ��ͬ��ʧ�ܵġ�
-   double-word-compare-and-swap(DWCAS):����int˫����С��UDT,ͬ������ʹ��atomicָ��
-   �������͵�UDT�����ʹ��mutex����atomic,**�Է�����֧�ּ�table5.3**
-   ���ڷǳ�Ա���������atomic�Ĳ�����һ����atomic_��ͷ��atomic_load(), ���ڼ���_explicit�ĺ�׺��Ҫ����memory ordering.
-   Ϊ�˺�c���ݣ�free memû�в���ref����ʹ����ָ������Ϊ��������
-   stl�ṩ����shared_ptrʵ����atomic�������������shared_ptr\<T> p��std\::atomic_load(&p)��std::std_atomic_store(&p, local);
-   EXP�ļ����ṩ��һ��atomic_shared_ptr\<T>,������Ͷ�ԭ����shared_ptrû�и��ӵ�cost,�����atomic<shared_ptr>���Ƽ�ʹ��ǰ��

****
**MEAT**

-   synchronizes-with relationship:ֻ������atomic type֮��
-   ����memory ordering tag��
    -  memory_order_seq_cst ��Ĭ��ʹ�õ�����
    -  sequentially consistent ordering  (memory_order_seq_cst), acquire release ordering��memory_order_acquire, memory_order_consume, memory_order_release, mem_order_acq_rel),relaxed ordering(memory_order_relaxed)
    -  ��Щϸ���ȵ�memory ordering��Ϊ�˸��ߵ�����
-  Sequentially consistent ordering
    -  ʹ��memory_order_seq_cst �Ľ��̿����Ĳ�����˳����һ���ģ�������Ҫ������ص��̶߳�ʹ������memory_order_seq_cst  ordering
    -  �������߳���ͬ��˳��������൱�ķ�ʱ��Ĳ���������кܶ���߳���Ҫͬ��
-  Non-Sequentially consistent ordering
    -  �̵߳�����˳��һ����һ�µ�
    -  **Relaxed ordering**
    -  with relaxed ordering ֻ��ÿһ������������޸��Ǳ�����
    -  ��ͬ�������ִ��˳���ǿ���reorder�ģ�����sequentially ordering
    -  һ���������ڲ�ͬ�̵߳ķ���ֵ�����ǲ�һ�µģ����Եģ�X��y������Ȼ���޸�y������Z��ȥ��y������y���ܸ���Z��֮ǰ��Ҳ�����Ƕ�֮���
    -  ��Ϊrelaxed ordering ̫�������Բ�**������ʹ��**
-  Acquire and release
    -  acquire��release ��Ҫ�ɶ�ʹ�ã����ܷ���ͬ��������
    -  ��ͬ�߳�֮��� Acquire and release��ʹ�û��¼��Ӧ����Ϣ������relax������ȡֵ���أ�load��������A-a-RҪ�󷵻ض�Ӧ��store��ֵ
    -   ��һ�������Ķ���д������Ҫʹ��memory_order_acq_rel���������ͬ��
    -   pairwise��A-a-R�����������ȫ��mutex��һ�򵥵�ʵ�ַ�ʽ
    -  ����memory_order_consume��**�����ǲ�Ҫʹ��**
-  Release sequence
    -  ����ʹ��memory_order_acquire��R-a-W����release�����ڶ�����߿ɽ������л���R-a-W����
-  Fence
   -  �ֽ�memory barrier������һ������������
-  ʹ��atomic ͬ��non-atomic
   -  
****
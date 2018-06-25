### ��Chapter4�����

***
#### Item 18 Use std::unique_ptr for exclusive-ownership resource management
-   Ĭ�ϵ�std::unique_ptr<*> ������Ϊ��raw_pointers�Ĵ�С��һ���ģ�����ʹ���Զ����deleter��ʱ��Ͳ�һ����
    �����Сȡ�������function state������captureless lamda��ô�����С����û�з����ı䣬�����function
    �����Ǵ�״̬��lamda,unique_prt�Ĵ�С�ͻᷢ���ı�
-   std::unique_ptr�д�[]�Ͳ���[]������ʽone for individual objects (std::
unique_ptr<T>) and one for arrays (std::unique_ptr<T[]>). ʹ�õĻ��͸�������Ͷ�������������һ��
-   Pimpl Idiom:ָ��ʵ�ֵ�ָ��(����trick�������ʵ���кܷ��㣬�������ر�ָ����ı仯���ﵽ��װ��Ч��)
    ��״̬��lamda�Ƚ��ʺ�����,��**Item22**�о�����ͣ���ռ���ӣ���ͷ�ٴ�
-   ���о���unique_ptr����ֱ��ת��Ϊshared_ptr����ֱ�����ڷ�������ľ��

#### Item 19 Use std::shared_ptr for shared-ownership resource management
-   shared_ptr �Ĵ�С��raw pointer��2�����������������һ��ָ��control block�Ķ���֮�а������ü���,weak_number, �Լ��Զ����deleter��alloctor if have.
-   shared_ptrһ�������ֻ��ָ��̬������ڴ棬����make_shared���Ա��������Ĵ洢����
-   ��Ϊshared_ptr�ڽ���reference count���޸ĵ�ʱ����Ҫ��ԭ�Ӳ�����**Ҳ����ζ�ţ����ϵͳ��ʱ��Ҫ��ܸߵģ��Ͳ���ʹ�ø�ָ�����˵��Ҫע���ָ���������������**
-   ���ʹ��move����shared_ptr��ownership tranferring��������̲��漰���ü������޸�(ԭ�Ӳ���),������Ļ�С�ܶ�
-   **����unique_ptr���Զ����deleter���÷���ģ��������棬��������shared_ptr�൱�������ԣ����е�shared_ptr���ǿ��Ի��������**
-   AS for control block(CB),make_shared��֤�����һ��CB������unique_ptr����shared_ptrʱҲ�ᴴ��һ��CB, shared_ptr��һ��raw pointer����ʱ�����CB,
    �����Ҫ��һ���Ѿ�����CB�Ķ��󴫸�shared_ptr������ֱ�Ӵ���һ��weak_ptr��shared_ptr.
-   **�����ܵĲ�Ҫ��һ��raw pointer ����һ��shared_ptr, multi-control-block ����֣����ͷ����**
-   Curiously Recurring Template Pattern (CRTP) �÷���CRTP�ĳ�����Ϊ�˼�˶�̬���Լ�Ч�ʣ��̵ļ̳ж���Ч��������
    ���Ǵ��Ӱ�죬�ؼ��ǳ��Ķ��ؼ̳л�Ӱ��Ч�ʣ�CRTP�ĳ��ּ�˶��ߣ����忴��ƪ����![C++ ���÷� CRTP ��� ](https://liam0205.me/2016/11/26/Introduction-to-CRTP-in-Cpp/)
-   std::enable_shared_from_this:����һ����shared_ptr����Ķ�������this ����һ��shared_ptr���������.Ҳ�����ṩ�˽�this���raw pointer ת���shared_ptr������������Ҫ���Ƿ�ֹ���shared_ptr���������. 
-   shared_ptr������������virtual function�����ͷŶ��󣬺���ֻ���ڶ����ͷŵ�ʱ��ŵ���
-   shared_ptr��unique_ptr��ͬ�ĵط��ǣ�**unique_ptr�ṩָ��ԭʼ�������������shared_ptr���ṩ���������Ҫ�Ļ�����ѡ��ʹ��std\::array,std\::vector**

#### Item 20  Use std\::weak_ptr for std::shared_ptr like pointers that can dangle. 
-   weak_ptr���ܽ�����Ҳ���ܲ����Ƿ�Ϊ�գ�������һ���ˣ�һ����˵��������shared_ptr���
-   weak_ptr�������ڻ����У�weak_ptr.lock()����һ��shared_ptr�������ָ��֮ǰ�ǿյ�,��weak_ptrָ��Ķ����Ѿ�����������ô�õ���shared_ptr������nullptr
-   weak_ptr�������ڹ۲���ģʽ�У���Ϊ���۲���ֻ����Ҫ֪���۲����Ƿ���ڣ���������ȥ�����۲��ߣ�weak_ptr��һ���൱ƥ���ѡ��
-   ��Ȼweak_ptr�����������ѭ�����õ����⣬�����Ȼ�ǲ��ܱ�������
-   ��һ����Ҫע�������shared_ptr��CB�У�����һ����weak_ptr�йصļ�����see next item.

***


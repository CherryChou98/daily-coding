### ��Chapter4�����

#### Item 18 Use std::unique_ptr for exclusive-ownership resource management
-   Ĭ�ϵ�std::unique_ptr<*> ������Ϊ��raw_pointers�Ĵ�С��һ���ģ�����ʹ���Զ����deleter��ʱ��Ͳ�һ����
    �����Сȡ�������function state������captureless lamda��ô�����С����û�з����ı䣬�����function
    �����Ǵ�״̬��lamda,unique_prt�Ĵ�С�ͻᷢ���ı�
-   std::unique_ptr�д�[]�Ͳ���[]������ʽone for individual objects (std::
unique_ptr<T>) and one for arrays (std::unique_ptr<T[]>). ʹ�õĻ��͸�������Ͷ�������������һ��
-   Pimpl Idiom:ָ��ʵ�ֵ�ָ��(����trick�������ʵ���кܷ��㣬�������ر�ָ����ı仯���ﵽ��װ��Ч��)
    ��״̬��lamda�Ƚ��ʺ�����,��**Item22**�о�����ͣ���ռ���ӣ���ͷ�ٴ�
-   ���о���unique_ptr����ֱ��ת��Ϊshared_ptr����ֱ�����ڷ�������ľ��
***

### ��Chapter8�����

***
####  Item 41: Consider pass by value for copyable parameters that are cheap to move and always copied

-   �����һ�γ��ֵ���ֵʹ��move��
-   ��ʱ��Ϊ�˱���ʹ��UR������һϵ�����⣬���Լ򵥸�Ч��ʹ�� pass by value
-   ����pass by value �ľ���Ч�ʵķ����Ǹ��ӵģ�ͬ������Ч�ʲ�û�иı�Ŀ�����
    -   ���� PBV ����(copy)һ���ܴ�Ķ���Ȼ����û���ã��װ��˷ѵ�������������ʧ�����move�Ǻܴ��
-   PBV(pass by value)���ܴ���slicing problem.(slicing problem ��ָһ���������ֵ���ݸ����ܻ���ĺ�������ص����е�һЩԪ��)
-   ������ֵ����PBVһ����˵����expensive

####  Item 42:Consider emplacement instead of insertion.

-   һ�¼���������ʺ�ʹ��emplace_back
    -   ���������ֵ ��construct into not assigned.
    -   ������Ĳ��������������нӵĲ������Ͳ�һ�µ�ʱ��(emplace ����Ҫȥ������ʱ����)
    -   ���������ܾܾ�һ����ֵ��Ϊһ��duplicate(either permits the duplicate or most of the value you insert is unique)
-   Similiarily,emplace_front, emplace_hint, emplace_after,
-   ʹ��emplace_back��push_back��ȣ���������쳣�����׳����ڴ�й¶�����(push_bask����һ����ɵĶ����ڴ��룬��emplace back�Ƿֿ��ģ���newһ�����ڷ�������Ҫ�������ڵ���ڴ棬�ڸ��ڴ洦����)
-   emplace_back�������ʽ������ת�������¿�����push_back������޷�ͨ������Ĵ���ͨ����form a  super pit,
    ��Ҫע����ǣ�emplace ��direct initialization����push_back��copy initialiation
   
***

#### ��ʱ��һ���䣬�ȵ�7.14���ڻع�ͷ��ϰһ���Ȿ�������
#### ����item41��item42��Ҫ�ڼ�ǿһ��

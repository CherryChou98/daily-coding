### ��Chapter8�����

***
####  Item 41: Consider pass by value for copyable parameters that are cheap to move and always copied

-   �����һ�γ��ֵ���ֵʹ��move��
-   ��ʱ��Ϊ�˱���ʹ��UR������һϵ�����⣬���Լ򵥸�Ч��ʹ�� pass by value
-   ����pass by value �ľ���Ч�ʵķ����Ǹ��ӵģ�ͬ������Ч�ʲ�û�иı�Ŀ�����
-   PBV(pass by value)���ܴ���slicing problem.
-   ������ֵ����PBVһ����˵����expensive

####  Item 42:Consider emplacement instead of insertion.

-   һ�¼���������ʺ�ʹ��emplace_back
    -   ���������ֵ ��construct into not assigned.
    -   ������Ĳ��������������нӵĲ������Ͳ�һ�µ�ʱ��
    -   ���������ܾܾ�һ����ֵ��Ϊһ��duplicate
-   ʹ��emplace_back��push_back��ȣ���������쳣�����׳����ڴ�й¶�����
-   emplace_back�������ʽ������ת�������¿�����push_back������޷�ͨ������Ĵ���ͨ����form a  super pit
***

#### ��ʱ��һ���䣬�ȵ�7.14���ڻع�ͷ��ϰһ���Ȿ�������
#### ����item41��item42��Ҫ�ڼ�ǿһ��

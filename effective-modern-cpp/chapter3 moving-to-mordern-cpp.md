### ��Chapter3�����
#### Item 7 distinguish between () and{} 
-   {}��һ�����������ܵĴ������ķ���(uniform initialization)��������ʤ�δ󲿷�����µĹ�����
-   ���б���narrow conversions:�����ڴ�������ʱ����ת��
        
        double x, y, z;
        ��
        int sum1{ x + y + z }; // error! sum of doubles may not be expressible as int 
-    avoid c++'s most vex parse : ʹ�ÿյĹ��캯�����ɶ�������ú���

         Widget w2(); // most vexing parse! declares a function named w2 that returns a Widget! 
         Widget w3{}; // calls Widget ctor with no args
-    **ȱ��Ҳ���е�**: {}����������ϵĲ��������ر��Ƕ��ڹ��캯���к��� std::initializer_list������˵
     ʹ��{1,2}��Ĭ�ϵ���std::initializer_list�ĵ��ã������Ƿ������ƥ��
-    ����һ������Ĭ�Ϻ��������⣬����һ���ն����ǵ���һ�������յ�._list�Ķ���**��page55**
-    ���о�����ʹ�ú���ģ�������µ��жϣ�()��{}���ַ�ʽ�ǲ�ͬ��,����std::vector<*> something\
     (20, 10)   //10��20�� �����{10�� 20} �Ǿ�������ֵ
-    �ܵ���˵���������߶���֮��һ�������**{}**���ǱȽ������ 


***

#### ����
mandate ��Ȩ

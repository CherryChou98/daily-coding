### ��Chapter6�����

***
####  Item 31:Avoid default capture modes

-   lambda��Ĭ������һ��closure class��lamda�еĿ�ִ�д�����൱��class�е�mem-func
-   capture ֻ����ھֲ���static����,����non-static�ĳ�Ա������ÿһ����һ��Ĭ�ϵ�thisָ��
-   ����non-static local mem-func���Ĳ���   

        void Widget::addFilter() const
        {
            auto divisorCopy = divisor; // copy data member
            filters.emplace_back(
                [divisorCopy](int value) // capture the copy
                { return value % divisorCopy == 0; } // use the copy
            );
            //c++14��
            //filters.emplace_back( // C++14:
            //[divisor = divisor](int value) // copy divisor to closure
            //{ return value % divisor == 0; } // use the copy
            //);
        }
-   ����û�м�mutable������lambda,Ĭ������²�����()��**const**:�����޸�
-   ����Ĵ����У���Ȼʹ����[=]���񣬵���divisor��static�ģ����������divisor�����仯������lambda�Ķ��ᷢ���仯

        filters.emplace_back(
        [=](int value) // captures nothing!
        { return value % divisor == 0; } // refers to above static
        );
####  Item 32:Use init capture to move objects into closures.

-   c\++11��û�б������move capture����C++14���Ը����ķ�ʽ����init capture
-   ����Ĳ��������е�pw��������closure class��lambda���ʽ��=�ұߵ�������Χ��

        auto func = [pw = std::make_unique<Widget>()] // as before,
        { return pw->isValidated() // create pw
        && pw->isArchived(); }; // in closure
-   c++11��û��init capture,���ǿ�����std::bind��ģ��


        auto func=std::bind([](const Widget& data){...}, std::move(data);

####  Item 33:Use decltype on auto&& parameters to std::forward them.

-   as the title is.
-   �������õ�ԭ���ǣ�decltype ������ֵ�� ������ͨ��ֵ��������ֵ����������ֵ
-   �������˵���Ƕ���forward�Ĳ�����ʹ��
   
        auto f=[](auto&& x)
        //{return normalize(std::forward<???>(x));};
        //��������������  
        {return normalize(std::forward<decltype(x)>(x));};


####  Item 34:Prefer lambdas to std::bind.

-   std::bind ����lambda �������������룬�����뾭���������ã����Դ�������е��
-   ����һ���Ǵ���Ŀɶ���
-   std::bind���ڴ���Ĳ�����Ҫ�Ƚ��д���(evaluate)��Ȼ����ܴ���Ŀ�꺯������,�޷����ֲ���������
-   c++11�п�����std::bind�����move capture�Ͷ�̬��������İ󶨣�������c\++14�������������Զ�������lambdaʵ��

        //polymorphic
        auto boundpw=[pw](const auto& param){pw(param);};



***



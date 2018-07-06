### ��Chapter6�����

***
####  Item 31:Avoid default capture modes

-   lamda��Ĭ������һ��closure class��lamda�еĿ�ִ�д�����൱��class�е�mem-func
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
-   ���Ұ�ֵ����ı���Ҳ�ǲ����Ա��޸ĵ�
-   ����Ĵ����У���Ȼʹ����[=]���񣬵���divisor��static�ģ����������divisor�����仯������lamda�Ķ��ᷢ���仯

        filters.emplace_back(
        [=](int value) // captures nothing!
        { return value % divisor == 0; } // refers to above static
        );

***



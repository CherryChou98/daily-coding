### ��Chapter2�����
#### Item 5  prefer auto to explicit type declaration
-   ʹ��auto����ʹ��δinitializeֵ
-   **C++14**����ʹ��auto ���н�lamda���ʽ�ķ���ֵ��������lamda������ɶ���Ǻ������
-   auto��std::function���:����ռ�ø�����ڴ�,������Ҫ�����ʱ�䣬����˵auto����std:;function
-   **Item34** ���߼���Ȱ����ʹ��lamda����std::bind
-   ���µĴ���:��32λ��������unsigned��32��64λϵͳ��32λ����v.size() �ķ���
    ֵƽ̨����, **����Ϊʲôѡ��ʹ��*auto***
-   ����ȷ��ʹ��explicit declaration��ʱ�򣬳�����������׶������ӷ���ά����don't be hesitate to suer

        std::vector<int> v;
        ��
        unsigned sz = v.size(); 
-   **Scott����һ��Item�У�����һ������:**

        std::unordered_map<std::string, int> m;
        ��
        for (const std::pair<std::string, int>& p : m)
        {
        �� // do something with p
        } 
    ���ߵ���˼�������p����ʵ��һ��std::pair<const std::string, int>��Ԥ�ڵĲ�һ��
    ��������һ�£�**�����ߵĽ��۲�һ��**�����£�
        
        std::unordered_map<std::string, int > m;
        m["hello"]=2;
        m["world"]=3;
        for(const std::pair<std::string, int> &temp:m){
            cout<<temp.first<<endl;
            cout<<typeid(temp.first).name()<<endl;
        }
        const string ss("nihao");
        cout<<"the type of const string "<< typeid(ss).name()<<endl;
        
15j

#### Item 6  prefer auto to explicit type declaration
-   ����bool�����⴦��

        std::vector::operator[] returns reference for every type except bool
-   c++ ��ֹreference to bits��������Ϊ�����ܰɣ��Ͼ�bits�ڴ�ռ�þͺ��٣�����ʹ��reference
    �ͺܶ��ˣ���ν�ò���ʧ 
-   ���ϵ������ǹ���һ�����ش������Ķ�����(proxy class),����auto���ƶϵ�ʱ�򣬻ᷢ������
    ������һ���м���󣬶��м�����ַ������ã��м�������������˾ͻᱻ�ݻ٣���������£���֪�����Ĳ�����dangling pointer,
    **��Ȼ��������Ϊ�˾���������gccȥ���Ե�ʱ�򣬷��֣������������ֲ�һ��**
        
        auto temp_bool_list=features()[2];
        cout<<temp_bool_list<<endl;
        
    ��ʵ�ϣ��ǿ������е�, **����Ҫ�������������⣬��Ҫע��һ��**

    **Ҳ���Ƕ��ڴ���invisible proxy��ʱ��auto���ƶϲ���Ҫ��ֵ**
-   Ҳ����explicitly invoke static_cast<*>��ʹauto������������
 
***

#### ����
mandate ��Ȩ
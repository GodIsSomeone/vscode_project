#include "master.h"
class TextBlock
{
    public:
    TextBlock(string text) : m_text(text) {}
    TextBlock(const TextBlock& rhs) : m_text(NULL)
    {
        m_text = rhs.m_text;
    }
    const TextBlock &operator=(const TextBlock &rhs)
    {
        m_text = rhs.m_text;
    }

    const char& operator[] (int position) const
    {
        return m_text[position];
    }

    /*  ���������Ǹ�reference to char������char  */
    char &operator[](int position)
    {
        return m_text[position];
        /*����const operator[]*/
        /*
        return const_cast<cahr&>(const TextBlock&)(*this)[position]);
        */
    }

private:
    string m_text;
};

//class A{};  //class is null ,size is 1;

struct A{}; //struct is null ,size is 1;

int main()
{
    cout<<sizeof(A)<<endl;
/*    
    TextBlock tb("hello");
    cout << tb[3] << endl; //����ո�����ĵ����ַ�
    tb[0] = 'X';
    const TextBlock ctb("world");
    cout<< ctb[3] << endl;
    const char* pc = &ctb[0];
*/
   system("pause");
   return 0;
}
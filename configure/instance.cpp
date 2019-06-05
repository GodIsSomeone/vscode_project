#include "master.h"
class TextBlock
{
    public:
    TextBlock* getInstance()
    {
        static TextBlock *pText = new TextBlock;

        cout << "pText:" << pText  << endl;
        return pText;
    }

    ~TextBlock()
    {

        cout << "destructor: " << this << endl;
    }

private:
    string m_text;
};

int main()
{
    for(int i=0;i<3;i++)
    {
        TextBlock tb;

        cout << "tb:" << &tb << endl;

        TextBlock *pText = tb.getInstance();
        TextBlock *pText2 = tb.getInstance();
    }

/*    
    TextBlock tb("hello");
    cout << tb[3] << endl; //输出刚刚载入的单个字符
    tb[0] = 'X';
    const TextBlock ctb("world");
    cout<< ctb[3] << endl;
    const char* pc = &ctb[0];
*/
   system("pause");
   return 0;
}
#include"Allinclude.h"
using std::make_shared;

class Mars
{
  public:
    Mars ()
    {
        cout << this << ": Mars" << endl;
    }
    ~Mars()
    {
        cout << this << ": ~Mars" << endl;
    }
    void prin()
    {
        cout << this << ",I am Mars" << endl;
    }
};
int main()
{
    {
        Mars pMars;

        shared_ptr<Mars> p2 = make_shared<Mars>(pMars);
        {
        shared_ptr<Mars> p1 = make_shared<Mars >(pMars);
        cout << "p1.print:" <<endl;
        p1->prin();
        }
        cout << "p2.print:" <<endl;
        p2->prin();
    }
    system("pause");
    return 0;
}

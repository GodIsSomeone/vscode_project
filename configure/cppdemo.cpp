// unique_ptr::release example
#include "Allinclude.h"
class Mars
{
  public:
    Mars()
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
    Mars *mars = new Mars;
    unique_ptr<Mars> pMars(mars);
    Mars *manual_pointer;

    manual_pointer = pMars.release();
    // (auto_pointer is now empty)
    pMars->prin();
    manual_pointer->prin();

    delete manual_pointer;

    system("pause");

    return 0;
}
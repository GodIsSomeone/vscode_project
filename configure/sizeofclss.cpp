#include "master.h"

class A{};
class B : virtual public A{};

int main ()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    system("pause");
    return 0;
}
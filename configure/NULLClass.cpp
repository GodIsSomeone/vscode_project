#include "master.h"

class CNull
{
    public:
    /*
    构造函数
    */
    CNull ()
    {
        cout << this << " : constructor!"<<endl;
    }

    /*
    拷贝构造函数。注意深拷贝和浅拷贝的区别。
    为了防止不经意间的拷贝构造函数，可以声明为private！
    */
    CNull(CNull &cnull)
    {
        cout << this << " : copy constructor!" << endl;
    }

    /*
    这个地方为什么要用 “&”，为了防止调用复制构造函数！ 
    */
    CNull& operator= (const CNull &cnull)
    {
        cout << this << " : operator = constructor!" << endl;
        return *this;
    }
    
    /*
    重载取地址符
    */
    CNull* operator&()
    {
        cout << this << " : operator& constructor!" << endl;
        return this;
    }

    /*
    const 重载取地址符
    */
    const CNull* operator&() const
    {
        cout << this << " : const operator& constructor!" << endl;
        return this;
    }

    /*
    析构函数
    */
    ~CNull()
    {
        cout << this << " : destructor!" << endl;
    }
};


int main()
{
    cout << "CNull cN0:" << endl;
    CNull cN0;          //构造函数

    cout << "----------------------" << endl << endl;

    cout << "CNull cN1(cN0):" << endl;
    CNull cN1(cN0);     //copy Destructor

    cout << "----------------------" << endl << endl;

    cout << "CNull cN2 = cN1:" << endl;
    CNull cN2 = cN1; //调用了拷贝构造函数

    cout << "----------------------" << endl << endl;

    cout << "CNull cN3 = cN1:" << endl;
    CNull cN3;
    cN3 = cN1; //调用了赋值函数

    cout << "----------------------" << endl << endl;

    cout << "&cN1:" << endl;
    cout << "&cN1:" << &cN1 << endl;

    cout << "----------------------" << endl  << endl;

    cout << " const CNull *pcN3 = &cN4:" << endl;
    const CNull cN4;
    const CNull *pcN3 = &cN4;

    system("pause");
    return 0;
}
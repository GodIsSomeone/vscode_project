#include<iostream>
#include<list>
#include<string>
#include<iterator>
#include<vector>
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::string;
using std::iterator;

class CUnit
{
  private:
    /* data */
    string m_name;

  public:
    CUnit(string name)
    {
        m_name = name;
        //cout<<this<<",create"<<endl;
    }
    ~CUnit()
    {
        //delete member
        cout << this << ",destroy" << endl;
    }
    CUnit(const CUnit &c)
    {
        //cout<<&c<<",param"<<endl;
        //cout<<this<<",copy"<<endl;
    }
    string getName()
    {
        cout << this << ",copy" << endl;
        return m_name;
    }
};

int main()
{
#if 0
    list<CUnit *> listStr;
    CUnit *cUnit1 = new CUnit("Robb");
    listStr.push_back(cUnit1); //此处调用复制构造函数

    cout << "push one" << endl;
    cout << "listStr.size()    :" << listStr.size() << endl;

    CUnit *cUnit2 = new CUnit("Bran"); //size不够，多次复制构造
    listStr.push_back(cUnit2);

    cout << "push two" << endl;
    cout << "listStr.size()    :" << listStr.size() << endl;
    CUnit *cUnit3 = new CUnit("Snow"); //size不够，多次复制构造
    listStr.push_back(cUnit3);
    CUnit *cUnit4 = new CUnit("Arya"); //size不够，多次复制构造
    listStr.push_back(cUnit4);
    CUnit *cUnit5 = new CUnit("Sansa"); //size不够，多次复制构造
    listStr.push_back(cUnit5);

    cout << "push five" << endl;
    cout << "listStr.size()    :" << listStr.size() << endl;
    cout << endl;

    /*打印*/
    for (list<CUnit *>::iterator it = listStr.begin(); it != listStr.end(); it++)
    {
        cout << "-----" << (*it)->getName() << "-----" << endl;
    }
    /*释放前list的容量*/
    cout << "释放前list的容量" << endl;
    cout << "listStr.size()    :" << listStr.size() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   
    //调用析构函数，清掉了list的内存
    for (list<CUnit *>::iterator it = listStr.begin(); it != listStr.end();)
    {
        delete *it;
        listStr.erase(it);
        //listStr.remove(*it++);
    }
    listStr.clear();


    //listStr.remove(cUnit2);

    cout << "释放后list的容量" << endl;
    cout << "listStr.size()    :" << listStr.size() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
#endif
    system("pause");
    return 0;
}
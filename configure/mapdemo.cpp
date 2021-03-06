#include "master.h"

int main()
{
    cout<<endl<<"map:"<<endl;
    map<char, int> mymap;
    // insert some values:
    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;
    mymap['d'] = 40;
    mymap['e'] = 50;
    mymap['f'] = 60;
    for (map<char, int>::iterator it = mymap.begin(); it != mymap.end();)
    {
        #if 0
        if (it->second == 10)
        {
            //For the key - based version(2), the function returns the number of elements erased.
            mymap.erase(it++);
        }
        else
        {
            it++;
        }
        #endif
        cout << "before erase:" << it->second << endl;
        it = mymap.erase(it);
        cout << "after erase:" << it->second << endl;
    }
    for (map<char, int>::iterator it = mymap.begin(); it != mymap.end();it++)
    {
        cout << it->second << " , ";
    }

#if 0
    cout<<endl<<"vector:"<<endl;

    vector<int> myvector;

    // set some values (from 1 to 10)
    for (int i = 1; i <= 10; i++)
        myvector.push_back(i);
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end();)
    {
#if 0
        if (*it == 5)
        {
            myvector.erase(it++);
            //等同于it=myvector.erase(it);因为返回值是下一个值的迭代器
        }
        else
        {
            it++;
        }
#endif

        cout << "before erase:" << *it << endl;
        myvector.erase(it);
        cout << "after erase:" << *it << endl;
    }

    // set some values (from 1 to 10)
    for (int i = 0; i < myvector.size(); i++)
    {
        cout << myvector[i] << " , ";
    }

#endif
#if 0
    cout<<endl<<"list:"<<endl;
    list<int> mylist;

    // set some values:
    for (int i = 1; i < 10; ++i)
        mylist.push_back(i * 10);

    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); )
    {
        #if 0
        if (*it == 50)
        {
            mylist.erase(it++);
            //等同于it=myvector.erase(it);因为返回值是下一个值的迭代器
            //it = mylist.erase(it);
        }
        else
        {
            it++;
        }
        #endif
        cout << "before erase:" << *it << endl;

        it = mylist.erase(it);
        cout << "after erase:" << *it << endl;
    }

    // set some values (from 1 to 10)
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
    {
        cout << *it << " , ";
    }
#endif
    system("pause");
    return 0;
}

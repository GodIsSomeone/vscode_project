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


int main ()
{
    string str[] = {"robert", "snow", "blan", "arya", "sansa"};
    vector<string*> myList;
    string *pStr1 = new string("Robb");
    myList.push_back(pStr1);
    string *pStr2 = new string("Snow");
    myList.push_back(pStr2);
    string *pStr3 = new string("Bran");
    myList.push_back(pStr3);
    string *pStr4 = new string("Arya");
    myList.push_back(pStr4);
    string *pStr5 = new string("Sansa");
    myList.push_back(pStr5);

    for (vector<string*>::iterator it = myList.begin(); it != myList.end(); it++)
    {
        cout<<"-----"<<**it<<endl;
        //myList.erase(it++);
    }
    /*
    myList.clear();
    vector<string*>().swap(myList);
    */

    for (vector<string *>::iterator it = myList.begin(); it != myList.end(); )
    {
        myList.erase(it++);
    }

    cout << myList.size() << endl;
    cout << myList.capacity() << endl;

    cout<<pStr4<<endl;

    system("pause");
    return 0;
}
#include <iostream>
using namespace std;

class Base
{
public:
    Base(int value)
    {
        m_nValue = value;
        cout << "object(" << this << "){" << this->m_nValue << "} is constructing!" << endl;
    }

    Base(const Base &b)
    {
        this->m_nValue = b.m_nValue;
        cout << "object(" << this << "){" << this->m_nValue << "} is copy constructing!" << endl;
    }

    ~Base()
    {
        cout << "object(" << this << "){" << this->m_nValue << "} is destroy!" << endl;
    }

private:
    int m_nValue;
};

/*

*/
class Person
{
public:
    virtual void print()
    {
        cout << "Person print" << endl;
    }
    virtual void print2()
    {
        cout << "Person print2" << endl;
    }
    Person()
    {
        cout << "Calling Person constuctor" << endl;
    }
    Person(const Person &b)
    {
        cout << "Person object(" << this << " is copy constructing!" << endl;
    }
    virtual ~Person()
    {
        /*
        为了析构的过程中把子类也给析构掉。避免内存泄漏。
        */
        cout << "Calling Person destructor" << endl;
    }

    void prin()
    {
        //print();
        cout << "Person prin" << endl;
    }

private:
};

class Student : public Person
{
public:
    Student()
    {
        cout << "Calling Student constuctor" << endl;
    }
    Student(const Student &b)
    {
        cout << "Student object(" << this << ") is copy constructing!" << endl;
    }
    ~Student()
    {
        cout << "Calling Student destructor" << endl;
    }
    virtual void print()
    {
        cout << "Student print" << endl;
    }
    virtual void print2()
    {
        cout << "Student print2" << endl;
    }

private:
};

int main01()
{
    cout << "虚函数的位置" << endl;

    Person p;
    cout << "the addr of p: " << &p << endl;
    cout << "the virtual table's addr : " << (int *)&p << endl;

    // 通过函数指针调用函数，验证正确性
    //     typedef void(*func_pointer)(void);
    //     func_pointer fp = NULL;
    //     fp = (func_pointer)*((int*)*(int*)&p + 1); // v_func1()
    //     fp(    cout << endl;

    //000000CF9257F8C8
    //000000CF9257F8C8

    cout << "使用子类进行new" << endl;
    Person *per = new Student;
    per->print();
    per->prin();
    delete per;

    cout << endl
         << "使用子类进行类型转换" << endl;
    /*
    把派生类对象赋值或者拷贝给基类的对象，只能实现派生类隐式转换成基类，
    即在编译器完成了派生类的截断，不能达到动态联编的作用
        */
    Student stu;
    stu.prin();
    Person person = (Person)stu;
    person.prin();
    person.print();
    system("pause");
    return 0;
}

class CA
{
public:
    virtual void print()
    {
        cout << "CA print" << endl;
    }
    CA()
    {
        cout << "Calling CA constuctor" << endl;
    }
    CA(const CA &b)
    {
        cout << "CA object(" << this << " is copy constructing!" << endl;
    }
    virtual ~CA()
    {
        /*
        为了析构的过程中把子类也给析构掉。避免内存泄漏。
        */
        cout << "Calling CA destructor" << endl;
    }
    CA *operator&()
    {
        cout << this << " : CA operator& constructor!" << endl;
        return this;
    }
};

class CB : public CA
{
public:
    virtual void print()
    {
        cout << "CB print" << endl;
    }
    CB()
    {
        cout << "Calling CB constuctor" << endl;
    }
    CB(const CB &b)
    {
        cout << "CB object(" << this << " is copy constructing!" << endl;
    }
    virtual ~CB()
    {
        /*
        为了析构的过程中把子类也给析构掉。避免内存泄漏。
        */
        cout << "Calling CB destructor" << endl;
    }
    CB *operator&()
    {
        cout << this << " : CB operator& constructor!" << endl;
        return this;
    }
};

int main()
{
    CB cb;
    CA *pca = (CA *)&cb;   
    pca->print();

    CA ca = (CA)cb;
    ca.print();

    system("pause");
    return 0;
}
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
        Ϊ�������Ĺ����а�����Ҳ���������������ڴ�й©��
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
    cout << "�麯����λ��" << endl;

    Person p;
    cout << "the addr of p: " << &p << endl;
    cout << "the virtual table's addr : " << (int *)&p << endl;

    // ͨ������ָ����ú�������֤��ȷ��
    //     typedef void(*func_pointer)(void);
    //     func_pointer fp = NULL;
    //     fp = (func_pointer)*((int*)*(int*)&p + 1); // v_func1()
    //     fp(    cout << endl;

    //000000CF9257F8C8
    //000000CF9257F8C8

    cout << "ʹ���������new" << endl;
    Person *per = new Student;
    per->print();
    per->prin();
    delete per;

    cout << endl
         << "ʹ�������������ת��" << endl;
    /*
    �����������ֵ���߿���������Ķ���ֻ��ʵ����������ʽת���ɻ��࣬
    ���ڱ����������������Ľضϣ����ܴﵽ��̬���������
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
        Ϊ�������Ĺ����а�����Ҳ���������������ڴ�й©��
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
        Ϊ�������Ĺ����а�����Ҳ���������������ڴ�й©��
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
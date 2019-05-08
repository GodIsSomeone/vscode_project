#include "master.h"
static const int SPARE_CAP = 10;

template <typename Object>
class CList
{
private:
    /*为什么用struct？ 因为：本身为私有成员变量，不必再使用class声明*/
    struct Node
    {
        Node *next;
        Node *prev;
        Object data;
        Node(const Object &obj = Object(), Node *prev = NULL, Node *next = NULL)
            : data(obj), prev(prev), next(next) {}
    };

public:

    /*抽象了位置的概念，是一个共有的潜逃类，存储指向当前结点的指针，可以public 继承const指针*/
    class myiterator
    {
        public:

            myiterator(){}
            myiterator(Node *p) : m_pCur(p) {}
            Object & operator* ()
            {
                return retrieve();
            }
            const Object &operator*() const
            {
                return retrieve();
            }
            myiterator & operator++()
            {
                m_pCur = m_pCur->next;
                return *this;
            }
            myiterator operator++(int)
            {
                myiterator old = *this;
                ++(*this);
                return old;
            }
            myiterator &operator--()
            {
                m_pCur = m_pCur->prev;
                return *this;
            }
            myiterator operator--(int)
            {
                myiterator old = *this;
                --(*this);
                return old;
            }
            bool operator == (const myiterator &rhs)
            {
                return m_pCur == rhs.m_pCur;
            }
            bool operator != (const myiterator &rhs)
            {
                return !(*this == rhs);
            }

        protected:
            Node *m_pCur;
            Object &retrieve() const
            {
                return m_pCur->data;
            }
            friend class CList<Object>;
    };

    CList()
    {
        init();
    }

    CList(const CList &rhs)
    {
        init();
        *this = rhs;
    }
    ~CList()
    {
    }

    const CList &operator=(const CList &rhs)
    {
        if (this = &rhs)
        {
            return *this;
        }
        clear();
        for(myiterator iter = rhs.begin(); iter != rhs.end(); ++iter)
        {
            push_back(*iter);
        }
        return *this;
    }
    
    bool empty() const
    {
        return size() == 0;
    }
    int size() const
    {
        return m_nSize;
    }
    void clear()
    {
        while(!empty())
        {
            pop_front();
        }
    }

    myiterator begin()
    {
        //cout << m_pHead->next<<endl;
        return myiterator(m_pHead->next);
    }
    myiterator end()
    {
        //cout << m_pTail << endl;
        return myiterator(m_pTail);
    }
    Object & front()
    {
        return *begin();
    }
    Object & back()
    {
        return *--end();
    }
    void push_front(const Object &obj)
    {
        insert(begin(), obj);
    }
    void push_back(const Object &obj)
    {
        insert(end(), obj);
    }
    void pop_front()
    {
        erase(begin());
    }
    void pop_back()
    {
        erase(--end());
    }

    myiterator insert(myiterator iter, const Object &obj)
    {
        /*检测iter*/
        Node *cur = iter.m_pCur;
        m_nSize++;
        Node *newNode = new Node(obj, cur->prev, cur);
        cur->prev->next = newNode;
        cur->prev = newNode;
    }
    myiterator erase(myiterator iter)
    {
        /*检测iter*/
        Node *cur = iter.m_pCur;
        myiterator retVal(cur->next);
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        m_nSize--;
        return retVal;
    }
    myiterator erase(myiterator begin, myiterator end)
    {
        /*检测iter*/
        for (myiterator iter = begin; iter != end;)
            iter = erase(iter);
        
        return end;
    }

private:
    int m_nSize;
    Node *m_pHead;          //链表的前驱结点，便于后续处理，所以创建前驱
    Node *m_pTail;          //链表的真正尾结点，便于后续处理，所以创建尾结点
    Object *m_pObjects;
    void init()
    {
        m_nSize = 0;
        m_pHead = new Node;
        m_pTail = new Node;
        m_pHead->next = m_pTail;
        m_pTail->prev = m_pHead;
    }
};


/*
待完成：
1.添加const迭代器和逆向迭代器
*/
int main()
{
    CList<int> cList;
    cList.push_back(2);
    cList.push_back(3);
    cList.push_back(4);

    cList.push_front(10);
    cList.push_front(11);
    cList.push_front(12);
    //cout << cList.front() << endl;
    //cout << cList.back() << endl;

    cout << "iterator***********************" << endl;

    
    for(CList<int>::myiterator iter = cList.begin(); iter != cList.end(); iter++)
    {
        cout << *iter << endl;
    }
    cList.pop_back();
    cout << "after pop_back***********************" << endl;
    for (CList<int>::myiterator iter = cList.begin(); iter != cList.end(); iter++)
    {
        cout << *iter << ",";
    }
    cout<<endl;
    cList.pop_front();
    cout << "after pop_front***********************" << endl;
    for (CList<int>::myiterator iter = cList.begin(); iter != cList.end(); iter++)
    {
        cout << *iter << ",";
    }
    cout << endl;

    cout << cList.size() << endl;
    cList.clear();
    cout << cList.size() << endl;

    system("pause");
    return 0;
}

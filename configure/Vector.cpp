#include "master.h"
static const int SPARE_CAP = 10;

template<typename Object>
class CVector
{
    public:
    explicit CVector(int size = 0):m_nSize(size),m_nCapacity(size+SPARE_CAP)
    {
        m_pObjects = new Object[m_nCapacity];
    }

    CVector(const CVector &cVect): m_pObjects(NULL)
    {
        operator=(cVect);
    }
    ~CVector()
    {
        delete[] m_pObjects;
    }

    const CVector &operator=(const CVector &cVect)
    {
        if(this != &cVect)
        {
            delete[] m_pObjects;
            m_nSize = cVect.m_nSize;
            m_nCapacity = cVect.m_nCapacity;
            for(int k= 0; k< size(); k++)
            {
                m_pObjects[k] = cVect.m_pObjects[k];
            }
        }
        return *this;
    }
    void resize(int newSize)
    {
        if(newSize>m_nCapacity)
            reserve(newSize*2+1);
        m_nSize = newSize;
    }

    void reserve(int newCap)
    {
        if(newCap<m_nSize)
            return;
        Object *oldObjects = m_pObjects;
        m_pObjects = new Object[newCap];
        for(int i=0; i<m_nSize; i++)
            m_pObjects[i] = oldObjects[i];

        m_nCapacity = newCap;
        delete[] oldObjects;
    }

    Object& operator[] (int index)
    {
        return m_pObjects[index];
    }

    const Object &operator[](int index) const
    {
        return m_pObjects[index];
    }
    bool empty() const
    {
        return size() ==0;
    }
    int size() const
    {
        return m_nSize;
    }
    int capacity() const
    {
        return m_nCapacity;
    }
    void push_back(const Object &obj)
    {
        if(m_nSize == m_nCapacity)
            reserve(2*m_nCapacity+1);
        m_pObjects[m_nSize++] = obj;
    }
    void pop_back(const Object &obj)
    {
        m_nSize--;
    }
    const Object& back() const
    {
        return m_pObjects[m_nSize-1];
    }
    
    typedef Object *iterator;
    typedef const Object * const_iterator;
    iterator begin()
    {
        return &m_pObjects[0];
    }
    const_iterator begin() const
    {
        return &m_pObjects[0];
    }
    iterator end()
    {
        return &m_pObjects[m_nSize];
    }
    const_iterator end() const
    {
        return &m_pObjects[m_nSize];
    }

private:
    int m_nSize;
    int m_nCapacity;
    Object * m_pObjects;

};

/*
待完成：
1.添加索引时的边界检测功能
2.添加Insert和Erase
3.push,pop,insert和erase的调用将使迭代器失效，why？
4.operator +
*/

int main()
{
    CVector<int> cVec;
    cVec.reserve(10);
    cVec.push_back(2);

    cout << cVec.size() << endl;
    cout << cVec.capacity() << endl;

    system("pause");
    return 0;
}
#include "Allinclude.h"

class CPoint
{
  public:
    CPoint(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int xVal) { x = xVal; }
    void setY(int yVal) { y = yVal; }

  private:
    int x, y;
};
class CSmartPtr;
/*

*/
class CCountPtr
{
  private:
    friend class CSmartPtr;
    int m_count;
    CPoint *m_pPoint;
    CCountPtr(CPoint *ptr) : m_pPoint(ptr), m_count(1) {}
    ~CCountPtr() {}
};

class CSmartPtr
{
  public:
    CSmartPtr(CPoint *ptr) : m_pPoint(ptr),m_count(1) {}
    CSmartPtr(const CSmartPtr &sptr) : m_pPoint(sptr.m_pPoint),m_count(sptr.m_count) {}
    
    //CSmartPtr &operator= (CSmartPtr &&x) ;

    //CSmartPtr &operator= (nullptr_t) ;

    //CSmartPtr &operator= (const CSmartPtr &) = delete;

    ~CSmartPtr()
    {
        Release();
    }
    CPoint* get()
    {
        return m_pPoint;
    }
    CPoint *release()
    {
        m_count = 0;
        return m_pPoint;
    }
    /*Destroys the object currently managed by the unique_ptr (if any) and takes ownership of p.*/
    void reset(CPoint*) 
    {}
    void swap(CSmartPtr &x) 
    {}

    int user_count() { return m_count; }
    CPoint &operator*()
    {
        return *(m_pPoint);
    }

    CPoint *operator->()
    {
        return m_pPoint;
    }

  private:
    void Release()
    {
        if (m_count-- == 0)
        {
            delete m_pPoint;
        }
        else
        {
            cout << "���ô���:" << m_count << endl;
        }
    }

    int m_count;
    CPoint *m_pPoint;
};

int main()
{
    CPoint *pPoint = new CPoint(3, 4);
    {
        CSmartPtr sptr1(pPoint);
        {
            (*sptr1).setX(10);
            cout << "sptr1->getX(): " << sptr1->getX() << endl;
        }
        cout << "sptr1.count: " << sptr1.user_count() << endl;
    }
    cout << "pPoint.getx(): " << pPoint->getX() << endl;
    system("pause");
    return 0;
}

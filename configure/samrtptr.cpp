#include "master.h"

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
        CCountPtr(CPoint *ptr):m_pPoint(ptr),m_count(1){}
        ~CCountPtr()
        {
            m_count=0;
        }
};

class CSmartPtr
{
    public:
      CSmartPtr(CPoint *ptr) : m_pCountPtr (new CCountPtr(ptr)){}
      CSmartPtr(const CSmartPtr &sptr) : m_pCountPtr(sptr.m_pCountPtr) {}
      CSmartPtr& operator=(const CSmartPtr &sptr)
      {
          (sptr.m_pCountPtr->m_count)++;
          minusOne();
          m_pCountPtr = sptr.m_pCountPtr;
          return *this;
      }
      ~CSmartPtr() 
      {
          minusOne();
      }
      CPoint *get()
      {
          return m_pCountPtr->m_pPoint;
      }
      CPoint *release()
      {
          CPoint *pRet = m_pCountPtr->m_pPoint;
          m_pCountPtr->m_pPoint = nullptr;
          m_pCountPtr->m_count  = 0;
          return pRet;
      }
      /*Destroys the object currently managed by the unique_ptr (if any) and takes ownership of p.*/
      void reset(CPoint *pPoint)
      {
          minusOne();
          m_pCountPtr = new CCountPtr(pPoint);
      }
      void swap(CSmartPtr &x)
      {
          CPoint *pRet = m_pCountPtr->m_pPoint;
          int count = m_pCountPtr->m_count;

          m_pCountPtr->m_pPoint = x.m_pCountPtr->m_pPoint;
          m_pCountPtr->m_count = x.m_pCountPtr->m_count;

          x.m_pCountPtr->m_pPoint = pRet;
          x.m_pCountPtr->m_count = count;
      }

      int user_count(){return m_pCountPtr->m_count; }
      CPoint& operator *()
      {
          return *(m_pCountPtr->m_pPoint);
      }

      CPoint* operator ->()
      {
          return m_pCountPtr->m_pPoint;
      }

    private:
      void minusOne()
      {
          if (m_pCountPtr->m_count-- == 0)
          {
              delete m_pCountPtr;
              m_pCountPtr = nullptr;
          }
          else
          {
              cout << "引用次数:" << m_pCountPtr->m_count << endl;
          }
      }
      CCountPtr *m_pCountPtr;
};

int main()
{
    CPoint *pPoint = new CPoint(3,4);
    {
        CSmartPtr sptr1(pPoint);
        {
            (*sptr1).setX(10);
            cout<<"initial:"<<endl;
            cout << "sptr1->getX(): " << sptr1->getX() << endl;
            CPoint *pPoint2 = new CPoint(5, 6);
            /*测试swap*/
            cout << "swap:" << endl;
            CPoint *pPoint4 = new CPoint(30, 40);
            CSmartPtr sptr2(pPoint4);
            sptr1.swap(sptr2);
            cout << "sptr1->getX(): " << sptr1->getX() << endl;
            cout << "sptr2->getX(): " << sptr2->getX() << endl;
            /*测试reset*/
            cout << "reset:" << endl;
            sptr1.reset(pPoint2);
            cout << "sptr1->getX(): " << sptr1->getX() << endl;
            /*测试release*/
            cout << "release:" << endl;
            CPoint *pPoint3 = new CPoint(30, 40);
            pPoint3 = sptr1.release();
            cout << "pPoint3->getX(): " << pPoint3->getX() << endl;
            cout << "sptr1.count: " << sptr1.user_count() << endl;
        }
        cout<<"sptr1.count: "<< sptr1.user_count()<<endl;
    }

    cout<<"pPoint.getx(): "<<pPoint->getX()<<endl;
    system("pause");
    return 0;
}

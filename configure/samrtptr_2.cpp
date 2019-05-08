#include "master.h"

template <typename T>
class CSmartPtr;

template <typename T>
class CCountPtr
{
    private:
        friend class CSmartPtr<T>;
        int m_count;
        T *m_pT;
        CCountPtr(T *ptr) : m_pT(ptr), m_count(1) {}
        ~CCountPtr(){}
};

template <typename T>
class CSmartPtr
{
    public:
      CSmartPtr(T *ptr) : m_pCountPtr (new CCountPtr<T>(ptr)){}
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
      T * get()
      {
          return m_pCountPtr->m_pPoint;
      }
      T *release()
      {
          T *pRet = m_pCountPtr->m_pPoint;
          m_pCountPtr->m_pPoint = nullptr;
          m_pCountPtr->m_count = 0;
          return pRet;
      }
      /*Destroys the object currently managed by the unique_ptr (if any) and takes ownership of p.*/
      void reset(T *pPoint)
      {
          minusOne();
          m_pCountPtr = new CCountPtr<T>(pPoint);
      }
      void swap(CSmartPtr &x)
      {
          T *pRet = m_pCountPtr->m_pPoint;
          int count = m_pCountPtr->m_count;

          m_pCountPtr->m_pPoint = x.m_pCountPtr->m_pPoint;
          m_pCountPtr->m_count = x.m_pCountPtr->m_count;

          x.m_pCountPtr->m_pPoint = pRet;
          x.m_pCountPtr->m_count = count;
      }

      int user_count(){return m_pCountPtr->m_count; }

      T& operator *()
      {
          return *(m_pCountPtr->m_pT);
      }

      T* operator ->()
      {
          return m_pCountPtr->m_pT;
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
      CCountPtr<T> *m_pCountPtr;
};

template<typename T, typename... Args>
inline CSmartPtr<T>
make_smart(Args&&... args)
{
    return CSmartPtr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
    int b=10;
    int* a=&b;
    {
        CSmartPtr<int> sptr1(a);
        {
            cout << "*sptr1: " << *sptr1 << endl;
            CSmartPtr<int> sptr2 = sptr1;

            cout << "*sptr2: " << *sptr2 << endl;

            CSmartPtr<int> sptr3 = make_smart<int>(20);
            cout << "*sptr3: " << *sptr3 << endl;
        }
        cout<<"sptr1.count: "<< sptr1.user_count()<<endl;
    }

    system("pause");
    return 0;
}

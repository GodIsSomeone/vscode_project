#include<iostream>
#include<memory>
using std::auto_ptr;
using std::unique_ptr;


class Mars
{
    public:
        ~Mars ()
        {
            std::cout<<this<<",~Mars"<<std::endl;
        }
        void prin()
        {
            std::cout<<this<<",I am Mars"<<std::endl;
        }
};

void test(){
	/*pa本身会被释放,一种机制使得pa的释放导致堆内存的释放
	所以不再让一个普通指针来保存pa，用一个类来保存 */
	//A * pa = new A(123);
    auto_ptr<Mars> pa(new Mars());
    pa->prin(); 
	//delete pa;
	/*智能指针的问题，缺乏拷贝语义,普通指针肯定没问题*/
    auto_ptr<Mars> pb = pa; //拷贝构造
    pb->prin();
	/*段错误*/
	pa->prin();
}

void test2()
{
    /*pa本身会被释放,一种机制使得pa的释放导致堆内存的释放
	所以不再让一个普通指针来保存pa，用一个类来保存 */
    //A * pa = new A(123);
    unique_ptr<Mars> pa(new Mars());
    pa->prin();
    //delete pa;
    /*智能指针的问题，缺乏拷贝语义,普通指针肯定没问题*/
    //unique_ptr<Mars> pb = pa; //拷贝构造
    //pb->prin();
    /*段错误*/
    pa->prin();
}


int main()
{
    test();
#if 0
    {
        auto autoMars = std::make_unique<Mars>();
        autoMars->prin();
        Mars *mars = new Mars;
        std::unique_ptr<Mars> pMars(mars);
        std::unique_ptr<Mars> pMars2(mars);
        std::cout << "pMars2->prin:          ";
        pMars2->prin();
        std::cout << "pMars->prin:          ";
        pMars->prin();
        std::cout << "pMars.get()->prin:    ";
        pMars.get()->prin();
        std::cout << "(*pMars).prin:        ";
        (*pMars).prin();

        std::cout << "pMars:" << pMars.get() << std::endl;
        pMars.reset(new Mars);
        std::cout << "pMars.reset.prin:      ";
        pMars->prin();

        std::unique_ptr<Mars> pMars2;
        pMars2 = std::move(pMars);
        std::cout << "pMars2.move.prin:      ";
        std::cout << "pMars2:" << pMars2.get() << std::endl;
        pMars2->prin();
        pMars2.get_deleter();
        std::cout << "pMars2.getdelete:" << pMars2.get() << std::endl;

    }
#endif
    system("pause");
    return 0;
}
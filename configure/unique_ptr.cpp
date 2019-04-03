#include<iostream>
#include<memory>
class Mars
{
    public:
        ~Mars ()
        {
            std::cout<<this<<"~Mars"<<std::endl;
        }
        void prin()
        {
            std::cout<<this<<",I am Mars"<<std::endl;
        }
};
 
int main()
{
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
#if 0
        std::unique_ptr<Mars> pMars2;
        pMars2 = std::move(pMars);
        std::cout << "pMars2.move.prin:      ";
        std::cout << "pMars2:" << pMars2.get() << std::endl;
        pMars2->prin();
        pMars2.get_deleter();
        std::cout << "pMars2.getdelete:" << pMars2.get() << std::endl;
#endif
    }

    system("pause");
    return 0;
}
#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <vector>
#include <thread>
using std::cout;
using std::endl;
using std::iterator;
using std::list;
using std::string;
using std::vector;

class Task
{
  public:
    void operator()(int i)
    {
        cout << i << endl;
    }
};

int main()
{

    for (int i = 0; i < 4; i++)
    {
        Task task;
        std::thread t(task, i);
        t.detach();
    }
}
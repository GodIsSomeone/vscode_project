#include<iostream>
#include<memory>
using namespace std;

class Stark;
class Targaryen;

class Stark
{
	private:
	  Targaryen *targaryen;

	public:
		void prin(){cout<<"stark love targaryen"<<endl;}
		~Stark()
		{
			//delete targaryen;
			cout<<"~Stark"<<endl;
		}
};

class Targaryen
{
  private:
	Stark *stark;

  public:
	void prin() { cout << "targaryen love stark" << endl; }
	~Targaryen()
	{
		delete stark;
		cout << "~Targaryen" << endl;
	}
};

int main()
{
	Targaryen *tar    = new Targaryen;
	Stark     *stark  = new Stark;

	delete stark;

	system("pause");
	return 0;
} 
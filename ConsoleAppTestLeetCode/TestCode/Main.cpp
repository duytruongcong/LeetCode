#include <iostream>
#include <string>
#include <array>
using namespace std;

class Entity
{
private:
	int* m_X;
	int* m_Y;
	mutable int var;
public:
	const int* const GetX() const
	{
		var = 2;
		return m_X;
	}

	void SetX(int* x)
	{
		m_X = x;
	}
};

void PrintEntity(const Entity* const e)
{
	cout << e->GetX() << endl;
}

void PrintEntityNew(const Entity& e)
{
	cout << e.GetX() << endl;
}


int main()
{
	const int MAX_AGE = 90;

	const int const* const a = new int;

	cin.get();
	return 0;
}

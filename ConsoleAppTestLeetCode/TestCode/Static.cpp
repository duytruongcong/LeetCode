#include <iostream>
#include <string>
#include <array>
using namespace std;

struct MyStruct
{
	int x, y;
};

#if false
int main()
{
	MyStruct* a = new MyStruct{ 2,3 };
	MyStruct* b = a;
	b->x = 5;
	cout << a->x << " - " << a->y << endl;
	cout << b->x << " - " << b->y << endl;

	cin.get();
	return 0;
}
#endif // 0


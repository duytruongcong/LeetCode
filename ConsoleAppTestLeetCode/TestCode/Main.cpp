#include <iostream>
#include <string>
#include <array>
using namespace std;

class String
{
private:
	char* m_Buffer;
	int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size + 1);
	}
#if true
	String(const String& string) : m_Size(string.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string.m_Buffer, m_Size + 1);
	}
#else
	String(const String& string) = delete;
#endif

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](const int& index)
	{
		return m_Buffer[index];
	}

	friend ostream& operator<<(ostream& stream, const String& string);

};

ostream& operator<<(ostream& stream, const String& string)
{
	cout << string.m_Buffer << endl;
	return stream;
}

#if true
int main()
{
	{
		String string = "Cherno";
		String second = string;

		second[2] = 'a';

		cout << string;
		cout << second;
	}

	cin.get();
	return 0;
}
#endif

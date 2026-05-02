#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <optional>
using namespace std;

std::optional<std::string> ReadFileAsString(const std::string &filePath)
{
	std::fstream stream(filePath);

	if (stream)
	{
		std::string result;
		// read file
		//result = stream.read();
		stream.close();
		return result;
	}

	return std::string();
}

#if true
int main()
{

	std::optional<std::string> data = ReadFileAsString("data.txt");

	if(data.has_value())
	{
		std::cout << "File read Sucessfully";
	}
	else
	{
		std::cout << "File could not be opend!!";
	}

	cin.get();
	return 0;
}
#endif

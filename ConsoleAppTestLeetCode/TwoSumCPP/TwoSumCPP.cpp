#include <iostream>
#include <unordered_map>
#include <string>



int main()
{
	//declare an unordered map with string keys and int values
	std::unordered_map<std::string, int> umap;

	//insert elements using [] operator and insert() method
	umap["apple"] = 1;
	umap.insert({"banana", 2});
	umap["orange"] = 3;



	// Access elements 
	std::cout << "Value for apple: " << umap["apple"] << std::endl;

	//The at() funcion also can be used and throw and exception if the key isn't found
	std::cout << "Value for banana: " << umap.at("banana") << std::endl;


	//iterate through the map using a range-based for loop

	for(const auto& pair : umap)
	{
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	//check if a key exists using find() method

	if(umap.find("grape")==umap.end())
	{
		std::cout << "Grape not found" << std::endl;

	}

	//remove an element using erase()
	umap.erase("orange");


	//get the size of  the map
	std::cout << "Map size after erase:" << umap.size() << std::endl;

	



	return 0;
}
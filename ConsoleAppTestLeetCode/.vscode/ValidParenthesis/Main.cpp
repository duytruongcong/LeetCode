#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>

bool IsValid(std::string s)
{
    std::unordered_map<char, char> map;
    map.insert({'(', ')'});
    map.insert({'[', ']'});
    map.insert({'{', '}'});

    std::stack<char> stack;

    for (char character : s)
    {
        if (map.count(character) != 0)
        {
            stack.push(map[character]);
        }
        else
        {
            if (stack.empty() || character != stack.top())
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }
    }

    if (stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    std::string hash = "()[{}";

    bool result = IsValid(hash);

    if (result)
        std::cout << "String is valid";
    else
        std::cout << "String is not valid";

    return 0;
}
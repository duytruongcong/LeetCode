#include <iostream>
#include <stack>
#include <string>

bool ValidParentheses(std::string hashString)
{
    std::stack<char> stack;

    for (char character : hashString)
    {
        if (character == '[')
            stack.push(']');
        else if (character == '(')
        {
            stack.push(')');
        }
        else if (character == '{')
        {
            stack.push('}');
        }
        else
        {
            if (stack.empty() || stack.top() != character)
                return false;

            stack.pop();
        }
    }

    return stack.empty();
}

int main()
{
    std::string hashString = "[]{}()[]";

    int size = sizeof(hashString) / sizeof(char);

    if (ValidParentheses(hashString))
        std::cout << "Valid" << std::endl;
    else
        std::cout << "Invalid" << std::endl;

    return 0;
}

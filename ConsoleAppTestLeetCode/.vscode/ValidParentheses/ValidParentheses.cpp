#include <stack>
#include <iostream>
#include <unordered_map>
#include <vector>

bool ValidParentheses(std::vector<char> hashChar);

int main()
{
    std::vector<char> hashChar = {'[', '(', ')', ']', '{', '}', '[', ']', '}'};


    bool valid = ValidParentheses(hashChar);

    if (valid)
        std::cout << "Valid!" << std::endl;
    else
        std::cout << "Invalid!" << std::endl;

    return 0;
}

bool ValidParentheses(std::vector<char> hashChar)
{
    std::unordered_map<char, char> dict;
    std::stack<char> stack;

    dict.insert({'[', ']'});
    dict.insert({'(', ')'});
    dict.insert({'{', '}'});


    for (int i = 0; i < hashChar.size(); i++)
    {
        if (dict.find(hashChar.at(i)) != dict.end())
        {
            stack.push(hashChar.at(i));
        }
        else
        {
            if (stack.empty())
            {
                return false;
            }
            else // stack co gia tri
            {
                auto iter = dict.find(stack.top());

                // kiem tra neu gia tri dau cua stack khop voi hashChar[i]
                if (iter->second == hashChar.at(i))
                    stack.pop(); // xoa phan tu top cua stack
                else
                    return false;
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

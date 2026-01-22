#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>

bool IsValid(std::string stringHash)
{
    std::stack<char> stack;
    std::unordered_map<char, char> map;
    map.insert({'[', ']'});
    map.insert({'(', ')'});
    map.insert({'{', '}'});

    for (char character : stringHash)
    {
        //open range
        if (map.count(character) != 0)
        {
            stack.push(map[character]);
        }
        else // close range
        {
            if (stack.empty() || stack.top() != character)
                return false;
            else
                stack.pop();
        }
    }

    return stack.empty();
}

// bool IsValid(std::string stringHash)
// {
//     std::stack<char> st;

//         std::unordered_map<char,char> mp = {
//             {')','('},
//             {'}','{'},
//             {']','['}
//         };

//         for(char c : stringHash)
//         {
//             if(mp.count(c) == 0)
//             {
//                 st.push(c);
//             }
//             else
//             {
//                 if(st.empty() || st.top() != mp[c])
//                     return false;

//                 st.pop();
//             }
//         }

//         return st.empty();
// }

int main()
{
    std::string hashString = "[]{}()[]{";

    if (IsValid(hashString))
        std::cout << "Valid" << std::endl;
    else
        std::cout << "Invalid" << std::endl;

    return 0;
}

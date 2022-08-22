//Учитывая строку s, содержащую только символы '(', ')', '{', '}', '[' и ']', 
//определите, допустима ли входная строка.
//Входная строка действительна, если:
// 
//Открытые скобки должны быть закрыты однотипными скобками.
//Открытые скобки должны быть закрыты в правильном порядке.
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    static bool isValid(string s) {

        stack<char> st;

        for (char leter : s) {

            if (leter == '(' || leter == '{' || leter == '[') {

                st.push(leter);
            }

            else {

                if (st.empty() || (st.top() == '(' && leter != ')') ||
                    (st.top() == '{' && leter != '}') ||
                    (st.top() == '[' && leter != ']'))

                    return false;


                st.pop();

            }


        }
        return st.empty();

    }
};

int main()
{
    string str = "()[]{}";

    if (Solution::isValid(str) == true) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
}

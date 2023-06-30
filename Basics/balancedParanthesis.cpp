#include <iostream>
#include <stack>
using namespace std;

bool matching(char a, char b){
    return ((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'));
}

int main()
{
    string str = "(({}))[";
    stack<char> s;
    for (char c : str)
    {
        if (c == '{' || c == '(' || c == '[')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
            {
                cout << "Paranthesis are balanced";
            }
            else if (!matching(s.top(), c))
            {
                cout << "Paranthesis are not balanced";
            }
            else
            {
                s.pop();
            }
        }
    }
    if (s.empty())
    {
        cout << "Paranthesis are balanced";
    }
    else
    {
        cout << "Paranthesis are not balanced";
    }
}
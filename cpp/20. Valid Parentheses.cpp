#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        if (s[i] == ')')
        {
            if (!st.empty()&&st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        if (s[i] == ']')
        {
            if (!st.empty()&&st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        if (s[i] == '}')
        {
            if (!st.empty()&&st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (!st.empty())
        return false;
    return true;
}
int main()
{
    string s;
    cin >> s;
    if (isValid(s))
        cout << 1;
    else
        cout << 0;
}

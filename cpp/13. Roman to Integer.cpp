#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s)
{
    map<char, int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int num = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            num -= mp[s[i]];
        }
        else if (mp[s[i]] == mp[s[i + 1]])
        {
            num += mp[s[i]];
        }
        else
        {
            num += mp[s[i]];
        }
    }
    num += mp[s[s.length()-1]];
    return num;
}

int main()
{
    string s;
    cin >> s;
    int num = romanToInt(s);
    cout << num;
}

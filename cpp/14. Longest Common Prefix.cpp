#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string res = "";
    if(strs.size()==0) return res;
    for (int j = 0; j < 200; j++)
    {
        for (int i = 0; i < strs.size() - 1; i++)
        {

            if (strs[i][j] != strs[i + 1][j])
            {
                return res;
            }
        }
        res += strs[0][j];
    }
    return res;//
}

int main()
{
    vector<string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    string res = longestCommonPrefix(v);
    cout << res;
}
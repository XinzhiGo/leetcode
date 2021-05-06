#include <bits/stdc++.h>
using namespace std;

string Prefix(string s1,string s2){
    int len=min(s1.length(),s2.length());
    int index=0;
    for(int i=0;i<len&&s1[i]==s2[i];i++){
        index++;
    }
    return s1.substr(0,index);
}

string longestCommonPrefix(vector<string>& strs){
    if(!strs.size()) return "";
    string res = strs[0];
    for(int i=1;i<strs.size();i++){
        res = Prefix(res,strs[i]);
        if(!res.size()) {
            break;
        }
    }
    return res;
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
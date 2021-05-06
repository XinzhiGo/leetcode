#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> vis;
    int left = 0, right = 0;
    int len = 0;

    while (right < s.size())
    {
        char c = s[right];
        right++;
        vis[c]++;
        while (vis[c] > 1)
        {
            //if(right - left > len){
            //len = right - left;
            // }
            char d = s[left];
            left++;
            vis[d]--;
        }
        len = max(len, right - left);//应该在这里更新
    }
    return len;
}
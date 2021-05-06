#include <iostream>
#include <set>
#include <queue>
using namespace std;
char addone(char c){
    if(c=='9'){
        return '0';
    }else{
        return c+1;
    }
}
char minusone(char c){
    if(c=='0'){
        return '9';
    }else{
        return c-1;
    }
}
int openLock(vector<string> &deadends, string target)
{
    queue<string> q;
    q.push("0000");
    set<string> visited;
    int step =1;
    for(auto e:deadends){
        visited.insert(e);
    }

    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            string now = q.front();
            q.pop();
            visited.insert(now);

            if(now==target){
                return step;
            }

            for(int j=0;j<4;j++){
                char num = now[j];
                char up = addone(now[j]);
                char down = minusone(now[j]);

                string s1 = now;
                s1[j] = up;
                string s2 = now;
                s2[j] = down;
                if(visited.find(s1)==visited.end()){
                    q.push(s1);
                }
                if(visited.find(s2)==visited.end()){
                    q.push(s2);
                }
            }
        }
        step++;
    }
}
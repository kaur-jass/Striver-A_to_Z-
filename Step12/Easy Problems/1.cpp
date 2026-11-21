#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size();
        int n = s.size();
        int i = 0,l = 0; 
        int cnt = 0; 
        while(i < m && l < n){
            if(s[l]>=g[i]){
                cnt++; 
                l++; 
                i++; 
            }
            else if(s[l]<g[i]) l++; //Here no need to go for greed factor array, cookie size is important
        }
        return cnt;
    }
};
int main(){
    int m = 3, n = 2; 
    vector<int> g(m), s(n);
    g = {1,2,3};
    s = {1,1};
    Solution obj;
    int ans = obj.findContentChildren(g,s);
    cout<<ans;
}
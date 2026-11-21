#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int low = 0; 
        int high = 0;  
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                low++;
                high++;
            }
            else if(s[i] == ')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }
            if(high<0) return false;
            low = max(low,0);   // if low becomes negative anytime, balance it with  
        }
        return low == 0;
    }
};
int main(){
    string s = "(*))";
    Solution obj;
    bool ans = obj.checkValidString(s);
    cout<<ans;
}
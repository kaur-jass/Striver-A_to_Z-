#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0; 
        int ten = 0;
        for(int i = 0; i<n; i++){
            if(bills[i] == 5) five++;
            else if(bills[i] == 10)
            {
                if(five >=1){
                    five--;
                    ten++;
                }
                else return false;
            }
            else if (bills[i] == 20){
                if(five >= 1 && ten >= 1){ 
                    ten--;
                    five--;
                }
                else if (five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};
int main(){
    int n = 5; 
    vector<int> bills(n);
    bills = {5,5,5,10,20};
    Solution obj;
    bool ans = obj.lemonadeChange(bills);
    cout<<ans;
}
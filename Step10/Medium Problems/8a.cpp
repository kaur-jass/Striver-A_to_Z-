#include<bits/stdc++.h>
using namespace std; 
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int lsum = 0; 
    int rsum = 0; 
    int maxsum = 0; 
    for(int i = 0; i<k; i++){
        lsum += cardPoints[i]; 
    }
    maxsum = lsum; 
    int rindex = n-1; 
    for(int i = k-1; i>= 0; i--){
        lsum -= cardPoints[i];
        rsum += cardPoints[rindex--]; 
        maxsum = max(maxsum, lsum+rsum); 
    }
    return maxsum; 
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,1}; 
    int k = 3; 
    cout << "The maximum score obtained is : " << maxScore(nums, k); 
    return 0; 
}
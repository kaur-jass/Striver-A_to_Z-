#include<bits/stdc++.h>
using namespace std; 
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    long long totalSum = 0; 
    for(int i = 0; i<n; i++){
        totalSum += cardPoints[i]; 
    }
    long long sum = 0; 
    for(int i = 0; i< n-k; i++){ // First window 
        sum += cardPoints[i]; 
    }
    long long answer = totalSum-sum; 
    int l = 0; 
    int r = n-k;
    while(k--){
        sum -= cardPoints[l++]; 
        sum += cardPoints[r++];
        answer = max(answer,  totalSum-sum); 
    }
    return answer; 
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,1}; 
    int k = 3; 
    cout << "The maximum score obtained is : " << maxScore(nums, k); 
    return 0; 
}
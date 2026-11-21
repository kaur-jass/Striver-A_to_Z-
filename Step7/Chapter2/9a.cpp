#include<bits/stdc++.h>
using namespace std;
vector<int> generate(int index, vector<int> current, vector<int>& nums, int sum, vector<int>& result){
    int n = nums.size(); 
    if(index >= n){
        result.push_back(sum);
        return result;
    }
    current.push_back(nums[index]); 
    sum+= nums[index];
    generate(index+1, current, nums, sum, result);
    current.pop_back();
    sum -= nums[index];
    generate(index+1, current, nums, sum, result);
    return result;
}

vector<int> SubsetSumP(vector<int>& nums, vector<int>& result){
    result = generate(0,{},nums,0, result);
    return result;
}


int main(){
    int n; 
    cout << "Enter the value of nof of elements in the array : " << endl; 
    cin >> n; 
    vector<int> nums(n); 
    cout << "Enter the elements in the array : " << endl; 
    for(int i = 0; i<n; i++){
        cin >> nums[i]; 
    }
    vector<int> result;
    vector<int> Sum = SubsetSumP(nums,result);
    sort(Sum.begin(), Sum.end()); 
    cout << "The Subset Sum of nums array is "<< endl;
    cout<< "[ ";
    for(int i = 0; i<Sum.size(); i++){
        cout << Sum[i] << " ";
    }
    cout << "]";
    return 0; 
}
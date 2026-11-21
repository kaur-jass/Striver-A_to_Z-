#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i< n; i++)
    {
        int next = (i+1)%n;
        if(nums[i] > nums[next]) count++;
    }
    return count <= 1;
}


int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    if (check(nums)) {
        cout << "The array is sorted and rotated." << endl;
    } else {
        cout << "The array is not sorted and rotated." << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    int kl;
    priority_queue<int, vector<int>, greater<int>> minheap;  
    KthLargest(int k, vector<int>& nums) {
        kl = k; 
        for(int x : nums){
            minheap.push(x); 
            if(minheap.size()>k){
                minheap.pop(); 
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>kl){
            minheap.pop();
        }
        return minheap.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main(){
    vector<int> nums = {4,5,8,2}; 
    int k = 3; 
    KthLargest* obj = new KthLargest(k, nums);
    cout << obj->add(3) << endl; 
    cout << obj->add(5) << endl; 
    cout << obj->add(10) << endl; 
    cout << obj->add(9) << endl; 
    cout << obj->add(4) << endl; 
    return 0;
}
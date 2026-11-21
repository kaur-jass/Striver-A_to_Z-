#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(); 
        if(n % groupSize != 0) return false; 
        priority_queue <int, vector<int>, greater<int>> heap; 
        for(int i = 0; i<n; i++){
            heap.push(hand[i]); 
        }
        while(!heap.empty()){
            vector<int> temp; 
            int start = heap.top(); // Starting of any group is the first element that is poped out of the heap 
            heap.pop(); 
            int need = start+1; // The need element should be consecutive and thus follow th econsecutive rule 
            int cnt = 1; 
            while( cnt < groupSize){
                if(heap.empty()) return false; 
                int curr = heap.top(); 
                heap.pop(); 
                if(curr == need){
                    cnt++; 
                    need++; 
                }
                else temp.push_back(curr);                
            }
            for(int val : temp){
                heap.push(val); 
            }
            if(heap.empty()) return true; 
        }
        return false; 
    }
};
int main(){
    Solution sol; 
    vector<int> hand = {1,2,3,6,2,3,4,7,8}; 
    int groupSize = 3; 
    bool ans = sol.isNStraightHand(hand, groupSize); 
    if(ans) cout << "true\n"; 
    else cout << "false\n"; 
    return 0; 
}
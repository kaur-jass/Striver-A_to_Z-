#include<bits/stdc++.h>
using namespace std;
// >> CPP CODE <<
class Solution {
public:
    vector<int> maxCombinations(vector<int>& A, vector<int>& B, int K) {
        int N = A.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < N; i++)
        {
            int sum = A[i] + B[N-1];
            pq.push({sum, N-1});
        }

        while(!pq.empty() && K--)
        {
            int sum = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            ans.push_back(sum);

            if(ind - 1 >= 0)
                pq.push({sum - B[ind] + B[ind-1], ind-1});
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = obj.maxCombinations(nums1, nums2, k);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
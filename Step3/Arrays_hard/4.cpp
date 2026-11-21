#include<bits/stdc++.h>
#include <algorithm> 
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            // if(i>0 && nums[i] == nums[i-1]) continue;
            int k = j+1;
            int m = n-1;
            while(k<m)
            {
                long long sum =(long long)nums[i] + nums[j] +nums[k]+nums[m];
                if(sum < target){
                    k++;
                }
                else if(sum >target){
                    m--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k],nums[m]};
                    // sort(temp.begin(), temp.end());
                    // if(std::find(ans.begin(),ans.end(),temp) != ans.end()) continue;
                    ans.insert(temp);
                    k++;
                    m--;
                    // while(k<m && nums[k] == nums[k-1]) k++;
                    // while(k<m && nums[m] == nums[m-1]) m--;
                }
            }
        }
    }
    vector<vector<int>> fnf(ans.begin(), ans.end());
    return fnf;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    vector<vector<int>> arr = fourSum(nums,target);
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
                cout << arr[i][j] << " ";
        }
    }
    return 0;
}
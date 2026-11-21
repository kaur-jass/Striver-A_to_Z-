 #include<bits/stdc++.h>
using namespace std; 
class Solution{
    private:
        vector<vector<int>> dp; 
        int n;
        int func(int day, int last, vector<vector<int>> &points){
            if(day == 0){
                int maxi = INT_MIN; 
                for(int task = 0; task<3; task++){
                    if(task != last){
                        maxi = max(maxi, points[0][task]); 
                    }
                }
                return maxi; 
            }
            if(dp[day][last] != -1) return dp[day][last]; 
            int maxi = INT_MIN; 
            for(int task = 0; task<3; task++){
                if(task != last){
                    int pts = points[day][task] + func(day-1, task, points); 
                    maxi = max(pts, maxi); 
                }
            }
            return dp[day][last] =  maxi; 
        }
    public:
        Solution(int n): n(n){
            dp.resize(n, vector<int> (4, -1)); 
        }
        int ninjaTraining(int n, vector<vector<int>> &points){
            return func(n-1, 3, points); 
        }
}; 

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    Solution obj(n);
    cout << obj.ninjaTraining(n, points) << endl;

    return 0;
}
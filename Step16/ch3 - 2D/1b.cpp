 #include<bits/stdc++.h>
using namespace std; 
class Solution{
    private:
        vector<int> prev;  
        // vector<int> prev(4,0);  compiler error: 'prev' is not a type cause it thinks it is a function declaration, so we need to declare it in the constructor
        int n;
        int func(vector<vector<int>> &points){
            //Using Space Optimization
            prev[0] = max(points[0][1], points[0][2]); 
            prev[1] = max(points[0][0], points[0][2]); 
            prev[2] = max(points[0][0], points[0][1]); 
            prev[3] = max(points[0][0], max(points[0][1], points[0][2])); 

            for(int day = 1; day<n; day++){
                for(int last = 0; last<4; last++){
                    int maxi = INT_MIN; 
                    for(int task = 0; task<3; task++){
                        if(task != last){
                            int pts = points[day][task] + prev[task]; 
                            maxi = max(pts, maxi); 
                        }
                    }
                    prev[last] = maxi; 
                }
            } 
            return prev[3]; 
        }
    public:
        Solution(int n): n(n){
            prev.resize(4, 0); 
        }
        int ninjaTraining(int n, vector<vector<int>> &points){
            return func(points); 
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
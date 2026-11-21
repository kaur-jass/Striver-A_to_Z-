int beautySum(string s) {
    int n = s.length();
    if(n == 0 || n == 1 || n ==2) return 0;
    long long sum = 0;  
    for(int i = 0; i<n; i++)
    {
        unordered_map<char, int> mpp; 
        for(int j = i; j<n ;j++)
        { 
            mpp[s[j]]++;
            int mini = INT_MAX, maxi = INT_MIN;
            for(auto it : mpp) 
            {
                mini = min(it.second, mini);
                maxi = max(it.second,maxi);
            }  
                sum += (maxi-mini);
        }
    }
    return sum; 
}
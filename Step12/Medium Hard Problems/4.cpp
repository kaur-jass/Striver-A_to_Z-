#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPlatforms(int n, int arr[], int dep[]) {
        for(int i = 0; i < n; i++) {
            arr[i] = (arr[i] / 100) * 60 + (arr[i] % 100);
            dep[i] = (dep[i] / 100) * 60 + (dep[i] % 100);
        }
        sort(arr, arr + n);
        sort(dep, dep + n);
        int platforms = 0, maxPlatforms = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (arr[i] < dep[j]) {
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            } else {
                platforms--;
                j++;
            }
        }
        return maxPlatforms;
    }
};
int main() {
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    cout << "Minimum number of Platforms required : " 
         << obj.countPlatforms(n, arr, dep) << endl;

    return 0;
}
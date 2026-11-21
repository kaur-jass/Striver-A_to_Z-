#include <bits/stdc++.h>
using namespace std;

// Class to group the solution method
class Solution {
public:
    // Function to count minimum platforms needed
    int countPlatforms(int n, int arr[], int dep[]) {

        // Initialize answer to 1
        int ans = 1;

        // Loop over all arrival times
        for (int i = 0; i < n; i++) {

            // Initialize count of overlapping intervals
            int count = 1;

            // Check overlap with every other train
            for (int j = i + 1; j < n; j++) {

                // Check if there is overlap between train i and j
                if (arr[i] <= dep[j] && arr[j] <= dep[i]) {
                    count++;
                }
            }

            // Update maximum platform count
            ans = max(ans, count);
        }

        return ans;
    }
};

int main() {
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create Solution object and call function
    Solution obj;
    cout << "Minimum number of Platforms required "
         << obj.countPlatforms(n, arr, dep) << endl;

    return 0;
}

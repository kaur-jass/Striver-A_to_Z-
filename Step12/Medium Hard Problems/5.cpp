#include<bits/stdc++.h>

using namespace std;

// A structure to represent a job 
struct Job {
   // Job Id
   int id; 
   // Deadline of job
   int dead;
   // Profit if job is completed before or on the deadline 
   int profit; 
};
class Solution {
public:
    // Function to find the maximum profit and the number of jobs done.
    pair < int, int > JobScheduling(Job arr[], int n) {
         // Sort jobs in descending order of profit
         sort(arr, arr + n, [](Job a, Job b) {
              return a.profit > b.profit;
         });
            // To keep track of free time slots
            vector<bool> slot(n, false);
            int countJobs = 0, totalProfit = 0;
            for (int i = 0; i < n; i++) {
                // Find a free slot for this job (starting from the last possible slot)
                for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
                    if (!slot[j]) {
                        slot[j] = true; // Mark this slot as occupied
                        countJobs++; // Increment count of jobs done
                        totalProfit += arr[i].profit; // Add profit of this job
                        break; // Move to the next job
                    }
                }
             }
             return {countJobs, totalProfit};
    }
    };
int main() {
   // Driver code
   int n = 4;
   // Define jobs with id, deadline, and profit
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   // Function call to find the number of jobs done and total profit
   pair < int, int > ans = ob.JobScheduling(arr, n);

   // Output the number of jobs and the total profit
   cout << ans.first << " " << ans.second << endl;

   return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Function to check if we can place 'cows' cows with at least 'dist' distance between them
bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int cntCows = 1; // First cow placed at the first stall
    int last = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }

        if (cntCows >= cows) return true;
    }
    return false;
}

// Main function to find the largest minimum distance
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();

    int low = 1, high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int k;
    cin >> k;

    cout << aggressiveCows(stalls, k) << endl;

    return 0;
}

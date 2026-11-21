#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    sort(nums.begin(), nums.end());

    map<int, vector<int>> mp;
    int idx = 0;

    do {
        mp[idx] = nums; // store the current permutation
        idx++;
    } while (next_permutation(nums.begin(), nums.end()));

    // Print the stored permutations
    for (auto& pair : mp) {
        cout << pair.first << " → ";
        for (int num : pair.second)
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}

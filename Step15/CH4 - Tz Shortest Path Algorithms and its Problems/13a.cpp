#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {

        // distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // fill direct edges
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // distance from node to itself is 0
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Floyd Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    // if path doesn't exist
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    // relax the distance
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;

        // count reachable cities
        for (int city = 0; city < n; city++) {

            int cnt = 0;

            for (int adjCity = 0; adjCity < n; adjCity++) {

                if (dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }

            // choose the city with minimum count
            // if tie, choose the larger index
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

int main() {

    int n = 4;
    int m = 4;

    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    int distanceThreshold = 4;

    Solution obj;

    cout << obj.findCity(n, m, edges, distanceThreshold) << endl;

    return 0;
}
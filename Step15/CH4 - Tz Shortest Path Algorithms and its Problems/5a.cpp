#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid,
                     pair<int,int> source,
                     pair<int,int> destination) {

        int n = grid.size();
        int m = grid[0].size();

        if(source == destination)
            return 0;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        queue<pair<int,pair<int,int>>> q;

        dist[source.first][source.second] = 0;

        q.push({0, {source.first, source.second}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0; i < 4; i++) {

                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >= 0 && newr < n &&
                   newc >= 0 && newc < m &&
                   grid[newr][newc] == 1 &&
                   dis + 1 < dist[newr][newc]) {

                    dist[newr][newc] = dis + 1;

                    if(newr == destination.first &&
                       newc == destination.second)
                        return dis + 1;

                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 1}
    };

    pair<int,int> source = {0,0};
    pair<int,int> destination = {3,3};

    int ans = obj.shortestPath(grid, source, destination);

    cout << "Shortest Path Length = " << ans << endl;

    return 0;
}
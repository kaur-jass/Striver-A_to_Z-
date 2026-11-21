#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int INF = 1e9;

// 0-1 BFS Function
vector<int> zeroOneBFS(int n, vector<vector<pair<int,int>>> &adj, int src)
{
    vector<int> dist(n, INF);

    deque<int> dq;

    dist[src] = 0;
    dq.push_front(src);

    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();

        for (auto [next, wt] : adj[node])
        {
            // Relaxation
            if (dist[node] + wt < dist[next])
            {
                dist[next] = dist[node] + wt;

                if (wt == 0)
                    dq.push_front(next);
                else
                    dq.push_back(next);
            }
        }
    }

    return dist;
}

int main()
{
    int n = 6;

    // Adjacency List
    vector<vector<pair<int,int>>> adj(n);

    /*
            Graph

             0
           /   \
        0 /     \1
         /       \
        1         2
        | \      /
      1 |  \0   /1
        |   \  /
        3    4
         \   |
        0 \  |0
           \ |
            5

    Edge Format:
    {Neighbour, Weight}
    */

    adj[0].push_back({1,0});
    adj[0].push_back({2,1});

    adj[1].push_back({3,1});
    adj[1].push_back({4,0});

    adj[2].push_back({4,1});

    adj[3].push_back({5,0});

    adj[4].push_back({5,0});

    int source = 0;

    vector<int> dist = zeroOneBFS(n, adj, source);

    cout << "Shortest Distance from Source " << source << "\n\n";

    for(int i=0;i<n;i++)
    {
        cout << "Node " << i << " -> ";

        if(dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}
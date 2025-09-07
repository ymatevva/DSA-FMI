#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void calcSum(const vector<vector<int>>& graph, int start, int& oddDist, int& evenDist) {
    vector<bool>visited(graph.size(), false);
    queue<pair<int, int>>myQ;

    myQ.push({ start,0 });
    visited[start] = true;

    while (!myQ.empty()) {

        int topEl = myQ.front().first;
        int currDist = myQ.front().second;

        myQ.pop();

        if (currDist % 2 == 0) {
            evenDist += topEl;
        }
        else {
            oddDist += topEl;
        }

        for (auto it : graph[topEl]) {
            if (!visited[it]) {
                myQ.push({ it, currDist + 1 });
                visited[it] = true;
            }
        }
    }
}

void convertToAdjList(vector<vector<int>>& adj, const vector<vector<int>>& edges) {
    for (size_t i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
}

int main() {
  
    int N = 0;
    int K = 0;
    std::cin >> N >> K;

    vector<vector<int>> edges(K);
    for (size_t i = 0; i < K; i++)
    {
        int start = 0;
        int end = 0;
        std::cin >> start >> end;
        edges[i] = { start,end };
    }

    vector<vector<int>> adj(N);
    convertToAdjList(adj, edges);

    int odd = 0, even = 0;

    int start = 0;
    std::cin >> start;
    calcSum(adj, start, odd, even);

    cout << "Sum of nodes at odd distances: " << odd << endl;
    cout << "Sum of nodes at even distances: " << even << endl;

    return 0;
}

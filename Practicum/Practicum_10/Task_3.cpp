#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>

using namespace std;

void convertToAdjList(vector<vector<int>>& adj, const vector<vector<int>>& edges) {
    for (size_t i = 0; i < edges.size(); i++) { 
        adj[edges[i][0]].push_back(edges[i][1]);
    }
}

void countCompHelp(const vector<vector<int>>& graph, vector<bool>& visited, int start,vector<int>& currComp) {

    visited[start] = true;
    currComp.push_back(start);
    for (auto it : graph[start]) {
        if (!visited[it]) {
            countCompHelp(graph, visited, it,currComp);
        }
    }
}

vector<vector<int>> getConnectedComp(const vector<vector<int>>& graph) {
    vector<bool>visited(graph.size(), false);
    vector<vector<int>> components;

    for (size_t i = 0; i < graph.size(); i++)
    {
        if (!visited[i]) {
            vector<int> currComp;
            countCompHelp(graph, visited, i, currComp);
            components.push_back(currComp);
        }
    }
   
    auto comp = [](const vector<int>& lhs, const vector<int>& rhs) {
        return lhs.size() < rhs.size();
    };
    sort(components.begin(), components.end(), comp);
    return move(components);
}
int main() {
 
    int N = 8; 
    int K = 6; 

  
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, 
        {3, 4}, {4, 5},         
        {6, 7}                  
    };

    vector<vector<int>> adj(N);
    convertToAdjList(adj, edges);

    vector<vector<int>> components = getConnectedComp(adj);
    std::cout << "Count of components: " << components.size() << std::endl;
  
    for (size_t i = 0; i < components.size(); i++)
    {
        std::cout << "Component number " << i << std::endl;

        for (size_t j = 0; j < components[i].size(); j++)
        {
            std::cout << components[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

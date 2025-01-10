#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> dijkstraAlg(const vector<vector<pair<int, int>>>& weightedGraph, int start) {
	vector<int>distances(weightedGraph.size(), INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myPQ;

	distances[start] = 0;
	myPQ.push({ 0,start });

	while (!myPQ.empty()) {

		int currDist = myPQ.top().first;
		int currEl = myPQ.top().second;
		myPQ.pop();

		for (const auto& iter : weightedGraph[currEl]) {

			int nextEl = iter.first;
			int nextWeight = iter.second;

			if (currDist + nextWeight < distances[nextEl]) {
				distances[nextEl] = currDist + nextWeight;
				myPQ.push({ nextWeight + currDist,nextEl });
			}
		}
	}
	return distances;
}


int main() {
 
    vector<vector<pair<int, int>>> graph1 = {
        {{1, 4}, {2, 1}},
        {{3, 1}},         
        {{1, 2}, {3, 5}}, 
        {}               
    };

    vector<int> distances1 = djikstraAlg(graph1, 0);

    for (size_t i = 0; i < distances1.size(); i++) {
        cout << "Node " << i << ": " << (distances1[i] == INT_MAX ? -1 : distances1[i]) << "\n";
    }

    return 0;
}

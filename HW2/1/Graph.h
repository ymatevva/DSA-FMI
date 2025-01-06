#include<iostream>
#pragma once
#include<vector>

//https://github.com/Angeld55/Data_structures_and_algorithms_FMI/blob/7056fe5988ed7caaa10f8062f3a8e8821455dc71/Sem.%2012/Graphs/Adjacency_list_graph/AdjListGraph.h

class Graph {
    std::vector<std::vector<int>> adj;
public:
    Graph(size_t size);
    void addEdge(int start, int end);
    bool hasEdge(int start ,int end) const;

    size_t size() const;
};
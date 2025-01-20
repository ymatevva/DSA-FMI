#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    char data;
    vector<Node*> children;
    Node(char data) :data(data) {}
};

void dfsHelp(string currWord, Node* root, vector<string>& words) {
    if (!root) {
        return;
    }
    currWord += root->data;
    if (root->children.empty()) {
        words.push_back(currWord);
        return;
    }
    for (const auto& iter : root->children) {
        dfsHelp(currWord, iter, words);
    }
    currWord.pop_back();
}
void DFS(Node* root, vector<string>& words) {
    dfsHelp("", root, words);
}

void free(Node* root)
{
    for (Node* child : root->children)
        free(child);
    delete root;
}

int main()
{
    Node* root = new Node{ 'a' };

    root->children.push_back(new Node{ 'b' });
    root->children.push_back(new Node{ 'c' });
    root->children.push_back(new Node{ 'd' });
    root->children.at(0)->children.push_back(new Node{ 'x' });
    root->children.at(0)->children.push_back(new Node{ 'y' });

    vector<string>res;
    DFS(root, res);
    free(root);

    for (const auto& it : res) {
        std::cout << it << " ";
    }
}
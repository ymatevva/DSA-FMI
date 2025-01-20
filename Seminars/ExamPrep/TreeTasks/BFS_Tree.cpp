#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    char data;
    vector<Node*> children;
    Node(char data) :data(data) {}
};

void BFS(Node* root) {

    if (!root) {
        return;
    }

    queue<Node*> myQ;
    myQ.push(root);

    while (!myQ.empty()) {
        size_t currLevelSize = myQ.size();

        for (size_t i = 0; i < currLevelSize; i++)
        {
            Node* topEL = myQ.front();
            myQ.pop();

            std::cout << topEL->data << " ";
            for (const auto& iter : topEL->children) {
                myQ.push(iter);
            }
        }
        std::cout << std::endl;
    }

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

    BFS(root);
    free(root);
}
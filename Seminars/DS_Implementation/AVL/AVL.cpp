#include<iostream>
#include<queue>
#include<cstdint> 
using namespace std;


//only the rotations and the balance factor setting/getting are to be learned
template <typename T>
class AVL {
    class Node {
    public:
        T data;     
        Node* left;  
        Node* right; 
        Node(T val, Node* left = nullptr, Node* right = nullptr) :data(val), left(left), right(right) {}
    };

    Node* root = nullptr; 

  
    int getBF(Node* curr) {
        if (curr == nullptr) return 0;
        uintptr_t address = reinterpret_cast<uintptr_t>(curr); 
        return (address & 0b11); 
    }

  
    void setBF(Node* curr, int balanceFactor) {
        if (curr) {
            uintptr_t address = reinterpret_cast<uintptr_t>(curr); 
            address &= ~0b11;             
            address |= (balanceFactor & 0b11); 
            curr = reinterpret_cast<Node*>(address); 
        }
    }

  
    int getHeight(Node* curr) {
        if (curr == nullptr) return 0;
        int leftHeight = getHeight(curr->left);
        int rightHeight = getHeight(curr->right);
        return 1 + max(leftHeight, rightHeight);
    }

    Node* rightRotation(Node* curr) {
        Node* newNode = curr->left;
        curr->left = newNode->right;
        newNode->right = curr;
        
        setBF(curr, getBF(curr));
        setBF(newNode, getBF(newNode));

        return newNode;
    }

   
    Node* leftRotation(Node* curr) {
        Node* newNode = curr->right;
        curr->right = newNode->left;
        newNode->left = curr;

        setBF(curr, getBF(curr));
        setBF(newNode, getBF(newNode));
        return newNode;
    }

    Node* insertUtility(Node* curr, T val) {
       
        if (curr == nullptr) {
            Node* newNode = new Node(val);
          
            setBF(newNode, 0);
            return newNode;
        }

        if (val < curr->data) curr->left = insertUtility(curr->left, val);
        else if (val > curr->data) curr->right = insertUtility(curr->right, val);

        int balance = getHeight(curr->left) - getHeight(curr->right);
        setBF(curr, balance);

      
        if (balance > 1) {
            if (val < curr->left->data) {
                return rightRotation(curr);  
            }
            else {
                curr->left = leftRotation(curr->left);
                return rightRotation(curr); 
            }
        }
        else if (balance < -1) {
            if (val > curr->right->data) {
                return leftRotation(curr);  
            }
            else {
                curr->right = rightRotation(curr->right);
                return leftRotation(curr); 
            }
        }

        return curr;
    }

}

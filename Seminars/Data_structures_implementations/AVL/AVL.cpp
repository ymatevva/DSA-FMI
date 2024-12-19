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

    Node* removeUtility(Node* curr, T val) {      
        if (curr == nullptr) {

            return nullptr;
        }

       
        if (val < curr->data) curr->left = removeUtility(curr->left, val);
        else if (val > curr->data) curr->right = removeUtility(curr->right, val);
        else {  
           
            if (curr->left == nullptr && curr->right == nullptr) {
                delete curr;
                curr = nullptr;
            }
          
            else if (curr->left == nullptr) {
                Node* temp = curr;
                curr = curr->right;
                delete temp;
            }
            else if (curr->right == nullptr) {
                Node* temp = curr;
                curr = curr->left;
                delete temp;
            }
           
            else {
                Node* temp = curr->right;
                while (temp->left != nullptr) temp = temp->left;
                curr->data = temp->data;
                curr->right = removeUtility(curr->right, temp->data);
            }
        }

       
        if (curr == nullptr) return curr;
        int balance = getHeight(curr->left) - getHeight(curr->right);
        setBF(curr, balance);

        if (balance > 1) {
            if (getHeight(curr->left) >= getHeight(curr->right)) {
                return rightRotation(curr); 
            }
            else {
                curr->left = leftRotation(curr->left);
                return rightRotation(curr);  
            }
        }
        else if (balance < -1) {
            if (getHeight(curr->right) >= getHeight(curr->left)) {
                return leftRotation(curr);   
            }
            else {
                curr->right = rightRotation(curr->right);
                return leftRotation(curr);   
            }
        }

        return curr;
    }

   
    Node* searchUtility(Node* curr, T val) {
        if (curr == nullptr || curr->data == val) {
            return curr;
        }

        if (val < curr->data) {
            return searchUtility(curr->left, val);
        }
        else {
            return searchUtility(curr->right, val);
        }
    }

  
    void display_BFS() {
        if (root == nullptr) cout << "Tree is empty" << endl;
        else {
            queue<Node*> q;
            q.push(root);
            Node* curr;
            while (!q.empty()) {
                curr = q.front();
                q.pop();
                cout << curr->data << " ";
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            cout << endl;
        }
    }

public:
  
    void insert(T val) {
        root = insertUtility(root, val);
    }

    void remove(T val) {
        root = removeUtility(root, val);
    }

    Node* search(T val) {
        return searchUtility(root, val);
    }

    void inorder() {
        inorderUtility(root);
        cout << endl;
    }

    void levelOrder() {
        display_BFS();
    }
};

int main() {
    AVL<int> avl;
    avl.insert(9);
    avl.insert(5);
    avl.insert(10);
    avl.insert(0);
    avl.insert(6);
    avl.insert(11);
    avl.insert(-1);
    avl.insert(1);
    avl.insert(2);

    cout << "Level Order Traversal of AVL tree is: ";
    avl.levelOrder();

  
    avl.remove(10);
    cout << "Level Order Traversal after deletion of 10 is: ";
    avl.levelOrder();

    return 0;
}

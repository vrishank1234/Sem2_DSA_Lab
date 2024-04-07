#include "iostream"
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root=insertRecursive(root, val);
    }

    Node* insertRecursive(Node* root, int val) {
        if(root==nullptr) {
            return new Node(val);
        }

        if(val<root->data) {
            root->left=insertRecursive(root->left, val);
        } 
        else if(val>root->data) {
            root->right=insertRecursive(root->right, val);
        }

        return root;
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }

    void inorderTraversalRecursive(Node* root) {
        if(root==nullptr) {
            return;
        }
        inorderTraversalRecursive(root->left);
        cout<<root->data<<" ";
        inorderTraversalRecursive(root->right);
    }

    Node* findMin(Node* root) {
        while(root->left!=nullptr) {\
            root=root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if(root==nullptr) {
            cout<<"Cannot delete, tree is empty."<<endl;
            return root;
        }

        if(key<root->data) {
            root->left=deleteNode(root->left, key);
        } 
        else if(key>root->data) {
            root->right=deleteNode(root->right, key);
        } 
        else {
            if(root->left==nullptr) {
                Node* temp=root->right;
                delete root;
                return temp;
            } 
            else if(root->right==nullptr) {
                Node* temp=root->left;
                delete root;
                return temp;
            }

            Node* temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right, temp->data);
        }
        cout<<"Node deleted."<<endl;
        return root;
    }

    void deleteNode(int key) {
        root=deleteNode(root, key);
    }
};

int main() {
    BinarySearchTree bst;
    int choice, val;

    do {
        cout<<"\nBinary Search Tree Operations:"<<endl;
        cout<<"1. Insert a node"<<endl;
        cout<<"2. Inorder Traversal"<<endl;
        cout<<"3. Delete a node"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter value to insert: ";
                cin>>val;
                bst.insert(val);
                break;
            case 2:
                cout<<"Inorder Traversal: ";
                bst.inorderTraversal();
                cout<<endl;
                break;
            case 3:
                cout<<"Enter value to delete: ";
                cin>>val;
                bst.deleteNode(val);
                break;
            case 4:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while(choice!=4);

    return 0;
}
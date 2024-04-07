#include "iostream"
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while(!isEmpty()) {
            pop();
        }
        delete top;
    }

    void push(int val) {
        Node* newNode=new Node;
        newNode->data=val;
        newNode->next=top;
        top=newNode;
        cout<<"Pushed "<<val<<" onto the stack."<<endl;
    }

    void pop() {
        if(isEmpty()) {
            cout<<"Stack is empty. Cannot pop."<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        cout<<"Popped "<<temp->data<<" from the stack."<<endl;
        delete temp;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Stack is empty. Cannot peek."<<endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top==nullptr;
    }
};

int main() {
    Stack stack;
    int choice, value;
    do {
        cout<<"\nStack Menu:\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter value to push: ";
                cin>>value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout<<"Top element: "<<stack.peek()<<endl;
                break;
            case 4:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    } while(choice!=4);

    return 0;
}
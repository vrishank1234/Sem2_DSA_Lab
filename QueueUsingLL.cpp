#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
    private:
        Node* front;
        Node* rear;

    public:
        Queue() : front(nullptr), rear(nullptr) {}

        ~Queue() {
            while(!isEmpty()) {
                dequeue();
            }
        }

        bool isEmpty() {
            return front==nullptr;
        }

        void enqueue(int val) {
            Node* newNode=new Node(val);
            if(isEmpty()) {
                front=rear=newNode;
            } 
            else {
                rear->next=newNode;
                rear=newNode;
            }
            cout<<"Enqueue successful."<<endl;
        }

        void dequeue() {
            if(isEmpty()) {
                cout<<"Queue is empty, cannot remove further."<<endl;
                return;
            }
            Node* temp=front;
            front=front->next;
            delete temp;
            //cout<<"Dequeued element."<<endl;
        }

        void display() {
            if(isEmpty()) {
                cout<<"Queue is empty."<<endl;
                return;
            }
            Node* temp=front;
            cout<<"Queue: ";
            while(temp!=nullptr) {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};

int main() {
    Queue queue;
    int choice, value;
    do {
        cout<<"\nQueue Operations:"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                cout<<"Dequeued element"<<endl;
                break;
            case 3:
                queue.display();
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
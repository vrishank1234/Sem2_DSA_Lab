#include "iostream"
using namespace std;

struct queue {
    int front, rear, capacity;
    int *arr;

    queue(int s) : front(-1), rear(-1), capacity(s) {
        arr=new int[capacity];
    }

    ~queue() {
        delete[] arr;
    }

    bool isEmpty() {
        if(front==-1 && rear==-1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        return (rear==capacity-1);
    }

    void enqueue(int val) {
        if(isEmpty()) {
            front++;
            rear++;
            arr[rear]=val;
            cout<<"Enqueue successful."<<endl;
            return;
        }
        else if(isFull()) {
            cout<<"Queue is full cannot add further"<<endl;
            return;
        }
        arr[++rear]=val;
        cout<<"Enqueue successful"<<endl;
    }

    int dequeue() {
        if(isEmpty() || front==rear) {
            cout<<"Queue is empty, cannot remove further"<<endl;
            return -1;
        }
        return arr[front++];
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Nothing to peek, queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    int size, choice, value;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    queue que(size);

    do {
        cout<<"\nQueue Operations:\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                que.enqueue(value);
                break;
            case 2:
                cout<<"Dequeued element: "<<que.dequeue()<<endl;
                break;
            case 3:
                if(que.peek()==-1)
                    break;
                cout<<"Front element: "<<que.peek()<<endl;
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
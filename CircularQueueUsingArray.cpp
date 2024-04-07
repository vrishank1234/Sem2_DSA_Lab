
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
        return (front==-1 && rear==-1);
    }

    bool isFull() {
        return ((rear+1)%capacity == front);
    }

    void enqueue(int val) {
        if(isFull()) {
            cout<<"Queue is full, cannot add further."<<endl;
            return;
        }
        else if(isEmpty()) {
            front=rear=0;
        }
        else {
            rear=(rear+1)%capacity; //since circular can start from 0 again
        }
        arr[rear]=val;
        cout<<"Enqueue successful."<<endl;
    }

    int dequeue() {
        if(isEmpty()) {
            cout<<"Queue is empty, cannot remove further."<<endl;
            return -1;
        }
        int val=arr[front];
        if(front==rear) {
            front=rear = -1;
        }
        else {
            front=(front+1)%capacity;
        }
        return val;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Nothing to peek, queue is empty."<<endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        for(int i=0;i<capacity;i++) {
            cout<<arr[i];
        }
    }//NOT TO BE USED UNTIL REQUIRED TO SEE ENTIRE QUEUE AT ONCE
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

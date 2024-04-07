#include "iostream"
using namespace std;

struct Stack {
    int top;
    int capacity;
    int* array;
};

Stack* createStack(int c) {
    Stack* stack=new Stack();
    stack->capacity=c;
    stack->top=-1;
    stack->array=new int[stack->capacity];
    return stack;
}

int isFull(Stack* stack) {
    return stack->top==stack->capacity-1;
}

int isEmpty(Stack* stack) {
    return stack->top==-1;
}

void push(Stack* stack, int item) {
    if(isFull(stack))
        cout<<"Stack Overflow";
    else {
        stack->array[++stack->top]=item;
        cout<<item<<" pushed into stack\n";
    }
}

int pop(Stack* stack) {
    int item;
    if(isEmpty(stack)) {
        cout<<"Stack Underflow";
    }
    item=stack->array[stack->top--];
    return item;
}

int peek(Stack* stack) {
    if(isEmpty(stack)) {
        cout<<"Stack is empty";
    }
    int item=stack->array[stack->top];
    return item;
    
}

// function to display the stack
void display(Stack* stack) {
    if(isEmpty(stack))
        cout<<"Stack is empty";
    else {
        cout<<"Stack elements are: ";
        for(int i=stack->top;i>=0;i--) {
            cout<<stack->array[i]<<" ";
        }
    }
    cout<<endl;
}

int main() {
    int choice, item;
    cout<<"Enter the capacity of the stack: ";
    cin>>choice;
    Stack *stack=createStack(choice);
    do {
        cout<<"Press: 1 for push. 2 for pop. 3 for peek. 4 for Display. 5 to Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter the element to push: ";
                cin>>item;
                push(stack, item);
                break;
            case 2:
                cout<<pop(stack)<<" popped from stack\n";
                break;
            case 3:
                cout<<"Top element is "<<peek(stack)<<endl;
                break;
            case 4:
                display(stack);
                break;
            case 5:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    } while(choice!=5);
    return 0;
}
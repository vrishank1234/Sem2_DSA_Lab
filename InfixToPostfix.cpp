#include "iostream"
using namespace std;

struct Stack {
    char *arr;
    int top;
    int capacity;

    Stack(int c) {
        capacity=c;
        arr=new char[capacity];
        top=-1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char ch) {
        if(isFull()) {
            cout<<"Stack Overflow\n";
            return;
        }
        arr[++top]=ch;
    }

    char pop() {
        if(isEmpty()) {
            cout<<"Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if(isEmpty()) {
            cout<<"Stack is empty\n";
            return ' ';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top==-1;
    }
    bool isFull() {
        return top==capacity-1;
    }
};

int precedence(char op) {
    if(op=='+' || op=='-')
        return 1;
    if(op== '*' || op=='/')
        return 2;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix="";
    Stack s(infix.length());

    for(int i=0; i<infix.length();i++) {
        if(infix[i]>='a' && infix[i]<='z') {
            postfix+=infix[i];
        } 
        else if(infix[i]=='(') {
            s.push(infix[i]);
        } 
        else if(infix[i]==')') {
            while(!s.isEmpty() && s.peek()!='(') {
                postfix+=s.pop();
            }
            s.pop(); 
        } 
        else { 
            while(!s.isEmpty() && precedence(infix[i])<=precedence(s.peek())) {
                postfix+=s.pop();
            }
            s.push(infix[i]);
        }
    }

    while(!s.isEmpty()) {
        postfix+=s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout<<"Enter the infix expression: ";
    getline(cin, infix);

    bool isValid=true;
    Stack validationStack(infix.length());
    for (char c : infix) {
        if(c=='(') {
            validationStack.push(c);
        } 
        else if(c==')') {
            if(validationStack.isEmpty() || validationStack.pop()!='(') {
                isValid=false;
                break;
            }
        }
    }//infix validation on basis of brackets
    if(!validationStack.isEmpty()) {
        isValid=false;
    }

    if(!isValid) {
        cout<<"Invalid infix expression!\n";
        return 1;
    }

    cout<<"Infix Expression: "<<infix<<endl;
    cout<<"Postfix Expression: "<<infixToPostfix(infix)<<endl;
    return 0;
}
#include "iostream"
using namespace std;

struct stack {
    int top, capacity;
    int *arr;

    stack(int c) : top(-1), capacity(c) {
        arr=new int[capacity];
    }

    ~stack() {
        delete[] arr;
    }

    void push(int n) {
        if(top>=capacity-1) {
            cout<<"stack full, cannot add anyfurther."<<endl;
            return;
        }
        arr[++top]=n;
    }

    int pop() {
        return arr[top--];
    }

    int peek() {
        return arr[top];
    }

    void display() {
        for(int i=top;i>=0;i--) {
            cout<<arr[i]<<" ";
        }
    }
};




int evaluator(string str) {
    stack st(str.length());
    for(char ch: str) {
        if (isdigit(ch)) {
            st.push(ch-'0'); //inorder to correctly convert char to int without.
        }
        else {
            int op2=st.pop();
            int op1=st.pop();
            switch(ch) {
                case '+':
                    st.push(op1+op2);
                    break; case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                
                default:
                    cout<<"invalid experssion."<<endl;
                    return -1;
            }
        }
    }
    return st.pop();
}

int main() {
    string expression;
    cout<<"Enter expression: ";
    cin>>expression;
    cout<<"Evaluation: "<<evaluator(expression)<<endl;
}
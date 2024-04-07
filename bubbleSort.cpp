#include "iostream"
using namespace std;

void ascending(int *&arr, int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

}

void descending(int *&arr, int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]<arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void display(int *arr, int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main() {
    int size;
    cout<<"Enter number of elements: ";
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++) {
        cout<<"Enter value at "<<i+1<<": ";
        cin>>arr[i];
    }

    int choice;
    do {
        cout<<"Press 1 for ascending order, 2 for descending order and 3 for exiting: ";
        cin>>choice;
        if(choice==1) {
            ascending(arr, size);
            display(arr, size);
        }
        else if(choice==2) {
            descending(arr,size);
            display(arr, size);
        }
        else if(choice==3) {
            cout<<"Exiting..."<<endl;
        }
        else {
            cout<<"Invalid input. Please try again."<<endl;
        }
    } while(choice!=3);

    delete[] arr;

    return 0;
}
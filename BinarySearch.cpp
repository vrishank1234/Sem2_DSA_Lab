#include "iostream"
using namespace std;

int binarySearch(int *arr, int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void getValsAndSort(int *&arr, int sz) {
    for(int i=0;i<sz;i++) {
        cout<<"Enter value "<<i+1<<": ";
        cin>>arr[i];
    }

    for(int i=0;i<sz;i++) {
        for(int j=i+1;j<sz;j++) {
            if(arr[i]>arr[j]) {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main() {
    int choice;
    int size;
    cout<<"Enter number of elements: ";
    cin>>size;
    int *arr=new int[size];
    getValsAndSort(arr, size);
    do {
        cout<<"\nMenu:\n";
        cout<<"1. Search for elements\n";
        cout<<"2. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1: {
                int target;
                cout<<"Enter value to search: ";
                cin>>target;
                int index=binarySearch(arr, size, target);
                if(index!=-1) {
                    cout<<"Element found at index "<<index<<endl;
                }
                else {
                    cout<<"Element not found"<<endl;
                }
                break;
            }
            case 2:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    } while(choice!=2);
    delete[] arr;
    return 0;
}
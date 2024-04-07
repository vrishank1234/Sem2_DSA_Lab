#include "iostream"
using namespace std;

class Array
{
    private:
        int size;
        int *arr; //repreesnts the array.
    public:
        Array(int sz) {
            size=sz;
            arr=new int[size];
            for(int i=0;i<size;i++)
            {
                cout<<"Enter Val "<<i<<": ";
                cin>>arr[i];
            }
        } //initial array creation

        void display() {
            for(int i=0;i<size;i++) {
                if(i==0) {
                    cout<<arr[i];
                    continue;
                }
                cout<<" "<<arr[i];
            }
            cout<<endl;
        }

        void insertAtStart(int val) {
            int *arr1=new int[++size];

            for(int i=size-1;i>0;i--) {
                arr1[i]=arr[i-1];
            }
            arr1[0]=val;
            delete[] arr;

            arr=arr1;
            cout<<"Insert At start: ";
            display();
        }

        void insertAtGivenLocation(int val, int location) {
            if(location>size || location<0) {
                cout<<"Invalid location given."<<endl;
                return;
            }
            int *arr1=new int[++size];
            for(int i=0;i<location;i++) {
                arr1[i]=arr[i];
            }

            for(int i=location+1;i<size;i++) {
                arr1[i]=arr[i-1];
            }
            arr1[location]=val;

            delete[] arr;
            arr=arr1;
            cout<<"Insert At location: ";
            display();
        } //same as before location as values shift forward

        void insertAtBeforeLocation(int val, int location)
        {
            if(location>size || location<=0) {
                cout<<"Invalid location given."<<endl;
                return;
            }
            size++;
            int *arr1=new int[size];
            for(int i=0;i<=location;i++) {
                arr1[i]=arr[i];
            }
            for(int i=location;i<size;i++) {
                arr1[i]=arr[i-1];
            }
            arr1[location]=val;
            delete[] arr;

            arr=arr1;
            cout<<"Insert Before location: ";
            display();
        } //same as at given location as values shift forward

        void insertAfterLocation(int val, int location) {
            if(location>size || location<0) {
                cout<<"Invalid location given."<<endl;
                return;
            }
            int *arr1=new int[++size];
            for(int i=0;i<=location;i++) {
                arr1[i]=arr[i];
            }
            for(int i=location+1;i<size;i++) {
                arr1[i]=arr[i-1];
            }
            arr1[location+1]=val;

            delete[] arr;
            arr=arr1;
            cout<<"Insert After location: ";
            display();
        }

        void insertAtEnd(int val) {
            int *arr1=new int[++size];
            for(int i=0;i<size;i++) {
                arr1[i]=arr[i];
            }
            arr[size-1]=val;
            cout<<"Insert End: ";
            display();
        }

        void deleteFirst() {
            int *arr1=new int[--size];
            for(int i=1;i<=size;i++) {
                arr1[i-1]=arr[i];
            }
            delete[] arr;
            arr=arr1;
            cout<<"Delete First: ";
            display();
        }

        void deleteAtGivenLocation(int location) {
            if(location>size || location<=0) {
                cout<<"Invalid location."<<endl;
                return;
            }
            int *arr1=new int[--size];
            for(int i=0;i<=size;i++) {
                if(i>=location) {
                    if(i==location) {
                        continue;
                    }
                    arr1[i-1]=arr[i];
                }
                else {
                    arr1[i]=arr[i];
                }
            }
            delete[] arr;

            arr=arr1;
            cout<<"Delete At Given Location: ";
            display();
        }

        void deleteBeforeGivenLocation(int location) {
            if(location>size || location<=0) {
                cout<<"Invalid location."<<endl;
                return;
            }
            int *arr1=new int[--size];
            for(int i=0;i<=size;i++) {
                if(i>=location-1) {
                    if(i==location-1) {
                        continue;
                    }
                    arr1[i-1]=arr[i];
                }
                else {
                    arr1[i]=arr[i];
                }
            }
            delete[] arr;

            arr=arr1;
            cout<<"Delete At Before Location: ";
            display();
        }

        void deleteAfterGivenLocation(int location) {
            if(location>size || location<=0) {
                cout<<"Invalid location."<<endl;
                return;
            }
            int *arr1=new int[--size];
            for(int i=0;i<=size;i++) {
                if(i>location) {
                    if(i==location+1) {
                        continue;
                    }
                    arr1[i-1]=arr[i];
                }
                else {
                    arr1[i]=arr[i];
                }
            }
            delete[] arr;

            arr=arr1;
            cout<<"Delete At After Location: ";
            display();
        }

        void deleteEnd() {
            int *arr1=new int[--size];
            for(int i=0;i<size;i++) {
                arr1[i]=arr[i];
            }
            delete[] arr;

            arr=arr1;
            cout<<"Delete End: ";
            display();
        }
};

int main()
{
    int initialVAl = 0;
    cout << "Enter initail number of elements in array: ";
    cin >> initialVAl;
    Array arr(initialVAl);

    // arr.display();

    // arr.insertAtStart(-1);
    // arr.insertAtBeforeLocation(20, 3);
    // arr.insertAtGivenLocation(21, 3);
    // arr.insertAfterLocation(100, 5);
    // arr.insertAtEnd(99);

    // arr.deleteFirst();
    // arr.deleteAtGivenLocation(5);
    // arr.deleteBeforeGivenLocation(4);
    // arr.deleteAfterGivenLocation(1);
    // arr.deleteEnd();
    int choice, choice1, val, index;
    do {
        choice=0, choice1=0, val=0, index=0;
        cout<<"Enter 1 for insertion, 2 for deletion, or 3 to exit: ";
        cin>>choice;
        
        if(choice==1 || choice==2) {
            do {
                cout<<"Enter choice for ";
                if(choice==1) {
                    cout<<"insertion: ";
                    cout<<"\n1. Insertion at start";
                    cout<<"\n2. Insertion at end";
                    cout<<"\n4. Insertion after location";
                    cout<<"\n3. Insertion before location";
                    cout<<"\n5. Insertion at location\n";
                } else {
                    cout<<"deletion: ";
                    cout<<"\n1. Deletion at start";
                    cout<<"\n2. Deletion at end";
                    cout<<"\n3. Deletion before location";
                    cout<<"\n4. Deletion after location";
                    cout<<"\n5. Deletion at location\n";
                }
                cin>>choice1;
                
                if(choice1<1 || choice1>6) {
                    cout<<"Invalid choice! Please enter a number between 1 and 5."<<endl;
                    continue;
                } 
                else {
                    if(choice==1) {
                        switch(choice1) {
                            case 1:
                                cout<<"Insertion at start chosen."<<endl;
                                cout<<"Val to insert: ";
                                cin>>val;
                                arr.insertAtStart(val);
                                break;
                            case 2:
                            cout<<"Insertion at end chosen."<<endl;
                                cout<<"Val to insert: ";
                                cin>>val;
                                arr.insertAtEnd(val);
                                break;
                            case 3:
                                cout<<"Insertion before given location chosen."<<endl;
                                cout<<"Val to insert: ";
                                cin>>val;
                                cout<<"Enter index: ";
                                cin>>index;
                                arr.insertAtBeforeLocation(val, index);
                                break;
                            case 4:
                                cout<<"Insertion after given location chosen."<<endl;
                                cout<<"Val to insert: ";
                                cin>>val;
                                cout<<"Enter index: ";
                                cin>>index;
                                arr.insertAfterLocation(val, index);
                                break;
                            case 5:
                                cout<<"Insertion at given chosen."<<endl;
                                cout<<"Val to insert: ";
                                cin>>val;
                                cout<<"Enter index: ";
                                cin>>index;
                                arr.insertAtGivenLocation(val, index);
                                break;
                        }
                    } else {
                        switch(choice1) {
                            case 1:
                                cout<<"Deletion at start chosen."<<endl;
                                arr.deleteFirst();
                                break;
                            case 2:
                                cout<<"Deletion at end chosen."<<endl;
                                arr.deleteEnd();
                                break;
                            case 3:
                                cout<<"Deletion before location chosen."<<endl;
                                cout<<"Enter position to delete: ";
                                cin>>index;
                                arr.deleteBeforeGivenLocation(index);
                                break;
                            case 4:
                                cout << "Deletion after location chosen." << endl;
                                cout<<"Enter position to delete: ";
                                cin>>index;
                                arr.deleteAfterGivenLocation(index);
                                break;
                            case 5:
                                cout << "Deletion at location chosen." << endl;
                                cout<<"Enter position to delete: ";
                                cin>>index;
                                arr.deleteAtGivenLocation(index);
                                break;
                        }
                    }
                }
            } while(!(choice1>=1 && choice1<=5));
        } else if(choice==3) {
            cout<<"Exiting the program."<<endl;
            break;
        } else {
            cout<<"Invalid choice! Please enter 1, 2, or 3."<<endl;
        }
        
    } while(choice != 3);

    return 0;
    
}
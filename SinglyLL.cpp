#include "iostream"
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val): data(val), next(nullptr) {}
};

void insertAtStart(Node *&head, int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head=newNode;
    cout<<"Success"<<endl;
}

void insertAtEnd(Node *&head, int val) {
    Node *newNode= new Node(val);
    if(head==nullptr) {
        head=newNode;
        return;
    }
    Node *ptr=head;
    while (ptr->next!=nullptr) {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    cout<<"Success"<<endl;
}

void insertBeforeElement(Node *&head, int val, int target) {
    Node *newNode=new Node(val);
    if(head==nullptr) {
        cout<<"operation unsuccessful, list empty"<<endl;
        return;
    }
    Node *ptr=head;
    while(ptr->next!=nullptr && ptr->next->data!=target) {
        ptr=ptr->next;
    }
    if(ptr->next!=nullptr) {
        newNode->next=ptr->next;
        ptr->next=newNode;
    } 
    else {
        ptr->next=newNode;
    }
    cout<<"Success"<<endl;
}


void insertAfterElement(Node *&head, int val, int target) {
    Node *newNode=new Node(val);
    if(head==nullptr) {
        cout<<"operation unsuccessful, list empty."<<endl;
        return;
    }
    Node *ptr=head;
    while(ptr->next!=nullptr && ptr->data!=target) {
        ptr=ptr->next;
    } 
    if(ptr->next==nullptr && ptr->data!=target) {
        cout<<"target not found, value not added."<<endl;
    }
    else {
        newNode->next=ptr->next;
        ptr->next=newNode;
    }
    cout<<"Success"<<endl;
}

void deletefirst(Node *&head) {
    if(head==nullptr) {
        cout<<"cannot delete from empty"<<endl;
        return;
    }
    Node *temp=head;
    head=head->next;
    delete temp;
    cout<<"Success"<<endl;
}

void deleteLast(Node *&head) {
    if(head==nullptr) {
        cout<<"cannot delete from empty"<<endl;
        return;
    }
    Node *current=head;
    Node *previous=nullptr;
    while(current->next!=nullptr) {
        previous=current;
        current=current->next;
    }
    delete current;
    previous->next=nullptr;
    cout<<"Success"<<endl;
}

void deleteNode(Node *&head, int target) {
    if(head==nullptr) {
        cout<<"cannot delete from empty"<<endl;
        return;
    }
    Node *ptr=head;
    Node *prev=ptr;
    while(ptr->next!=nullptr && ptr->data!=target) {
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr->next!=nullptr && ptr->data!=target) {
        cout<<"cannot delete, value not found"<<endl;
        return;
    }
    else {
        prev->next=ptr->next;
        Node *temp=ptr;
        delete temp;
    }
    cout<<"Success"<<endl;
}

void deleteNodeBefore(Node* start, int num) {
    Node* ptr=start;
    Node* preptr=nullptr;
    while(ptr->next!=nullptr && ptr->next->data!=num) {
        preptr = ptr;
        ptr = ptr->next;
    }
    Node* temp = preptr->next;
    preptr->next = ptr->next;
    delete temp;
    cout<<"Node deleted.";
}

void deleteNodeAfter(Node* start, int num) {
    Node* ptr=start;
    while(ptr!=nullptr && ptr->data!=num) {
        ptr=ptr->next;
    }
    Node* temp=ptr->next;
    ptr->next=temp->next;
    delete temp;
}

void display(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node *head=nullptr;
    int choice, val, target;

    do {
        cout<<"\nLinked List Operations:"<<endl;
        cout<<"1. Insert at the beginning"<<endl;
        cout<<"2. Insert at the end"<<endl;
        cout<<"3. Insert before an element"<<endl;
        cout<<"4. Insert after an element"<<endl;
        cout<<"5. Delete first node"<<endl;
        cout<<"6. Delete last node"<<endl;
        cout<<"7. Delete a node with specific value"<<endl;
        cout<<"8. Delete node before a given node"<<endl;
        cout<<"9. Delete node after a given node"<<endl;
        cout<<"10. Display the linked list"<<endl;
        cout<<"11. Exit" << endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter value to insert at the beginning: ";
                cin>>val;
                insertAtStart(head, val);
                break;
            case 2:
                cout<<"Enter value to insert at the end: ";
                cin>>val;
                insertAtEnd(head, val);
                break;
            case 3:
                cout<<"Enter value to insert: ";
                cin>>val;
                cout<<"Enter the element before which to insert: ";
                cin>>target;
                insertBeforeElement(head, val, target);
                break;
            case 4:
                cout<<"Enter value to insert: ";
                cin>>val;
                cout<<"Enter the element after which to insert: ";
                cin>>target;
                insertAfterElement(head, val, target);
                break;
            case 5:
                deletefirst(head);
                break;
            case 6:
                deleteLast(head);
                break;
            case 7:
                cout<<"Enter the value to delete: ";
                cin>>val;
                deleteNode(head, val);
                break;
            case 8:
                cout<<"Enter the value of the node before which to delete: ";
                cin>>val;
                deleteNodeBefore(head, val);
                break;
            case 9:
                cout<<"Enter the value of the node after which to delete: ";
                cin>>val;
                deleteNodeAfter(head, val);
                break;
            case 10:
                display(head);
                break;
            case 11:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while(choice != 11);

    return 0;
}
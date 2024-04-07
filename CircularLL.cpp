#include "iostream"
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertionAtBeginning(Node*& head, int val) {
    Node* newNode=new Node(val);
    if(head==nullptr) {
        head=newNode;
        head->next=head;
    } else {
        Node* temp=head;
        while(temp->next!=head) {
            temp = temp->next;
        }
        newNode->next=head;
        head=newNode;
        temp->next=head;
    }
    cout<<"Node inserted at the beginning."<<endl;
}

void insertionAtEnd(Node*& head, int val) {
    Node* newNode=new Node(val);
    if(head==nullptr) {
        head=newNode;
        head->next=head;
    } else {
        Node* temp=head;
        while(temp->next!=head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }
    cout<<"Node inserted at the end."<<endl;
}

void insertionBeforeTarget(Node*& head, int val, int target) {
    if (head == nullptr) {
        cout<<"List is empty. Cannot perform insertion."<<endl;
        return;
    }
    if(head->data == target) {
        insertionAtBeginning(head, val);
        return;
    }
    Node* newNode=new Node(val);
    Node* temp=head;
    while(temp->next!=head && temp->next->data!=target) {
        temp = temp->next;
    }
    if(temp->next==head) {
        cout << "Target value not found. Insertion failed."<<endl;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    cout<<"Node inserted before the target value."<<endl;
}

void insertionAfterTarget(Node*& head, int val, int target) {
    if(head==nullptr) {
        cout<<"List is empty. Cannot perform insertion."<<endl;
        return;
    }
    Node* newNode=new Node(val);
    Node* temp=head;
    while(temp!=nullptr && temp->data!=target) {
        temp=temp->next;
    }
    if(temp==nullptr) {
        cout<<"Target value not found. Insertion failed."<<endl;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    cout<<"Node inserted after the target value."<<endl;
}

void deleteFirst(Node*& head) {
    if(head==nullptr) {
        cout<<"List is empty. Cannot perform deletion."<<endl;
        return;
    }
    if(head->next==head) {
        delete head;
        head=nullptr;
        cout<<"First node deleted."<<endl;
        return;
    }
    Node* temp=head;
    while(temp->next!=head) {
        temp=temp->next;
    }
    Node* toDelete=head;
    head=head->next;
    temp->next=head;
    delete toDelete;
    cout<<"First node deleted."<<endl;
}

void deleteLast(Node*& head) {
    if(head==nullptr) {
        cout<<"List is empty. Cannot perform deletion."<<endl;
        return;
    }
    if(head->next==head) {
        delete head;
        head=nullptr;
        cout<<"Last node deleted."<<endl;
        return;
    }
    Node* temp=head;
    Node* prev=nullptr;
    while(temp->next!=head) {
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    delete temp;
    cout<<"Last node deleted."<<endl;
}

void deleteBeforeTarget(Node*& head, int target) {
    if(head==nullptr || head->next==head) {
        cout<<"List is empty or contains only one node. Cannot perform deletion."<<endl;
        return;
    }
    if(head->next->data==target) {
        deleteFirst(head);
        return;
    }
    Node* temp=head;
    Node* prev=nullptr;
    while(temp->next!=head && temp->next->data!=target) {
        prev=temp;
        temp=temp->next;
    }
    if(temp->next==head) {
        cout<<"Target value not found. Deletion failed."<<endl;
        return;
    }
    Node* toDelete=prev->next;
    prev->next=temp->next;
    delete toDelete;
    cout<<"Node before the target value deleted."<<endl;
}

void deleteAfterTarget(Node*& head, int target) {
    if(head==nullptr) {
        cout<<"List is empty. Cannot perform deletion."<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=nullptr && temp->data!=target) {
        temp=temp->next;
    }
    if(temp==nullptr) {
        cout<<"Target value not found. Deletion failed."<<endl;
        return;
    }
    if(temp->next==head) {
        cout<<"No node after the target value. Deletion failed."<<endl;
        return;
    }
    Node* toDelete=temp->next;
    temp->next=toDelete->next;
    delete toDelete;
    cout<<"Node after the target value deleted."<<endl;
}

void deleteNode(Node*& head, int target) {
    if(head==nullptr) {
        cout<<"List is empty. Cannot perform deletion."<<endl;
        return;
    }
    if(head->data==target) {
        deleteFirst(head);
        return;
    }
    Node* temp=head;
    Node* prev=nullptr;
    while(temp->next!=head && temp->data!=target) {
        prev=temp;
        temp=temp->next;
    }
    if(temp->next==head) {
        cout<<"Target value not found. Deletion failed."<<endl;
        return;
    }
    prev->next=temp->next;
    delete temp;
    cout<<"Node with target value deleted."<<endl;
}

void displayList(Node* head) {
    if(head==nullptr) {
        cout<<"List is empty."<<endl;
        return;
    }
    Node* temp=head;
    do {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp!=head);
    cout<<endl;
}

int main() {
    Node* head=nullptr;
    int choice, val, target;

    do {
        cout<<"\nCircular Linked List Operations:"<<endl;
        cout<<"1. Insertion at the beginning"<<endl;
        cout<<"2. Insertion at the end"<<endl;
        cout<<"3. Insertion before a target"<<endl;
        cout<<"4. Insertion after a target"<<endl;
        cout<<"5. Delete first node"<<endl;
        cout<<"6. Delete last node"<<endl;
        cout<<"7. Delete node before a target"<<endl;
        cout<<"8. Delete node after a target"<<endl;
        cout<<"9. Delete a specific node"<<endl;
        cout<<"10. Display the list"<<endl;
        cout<<"11. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter value to insert at the beginning: ";
                cin>>val;
                insertionAtBeginning(head, val);
                break;
            case 2:
                cout<<"Enter value to insert at the end: ";
                cin>>val;
                insertionAtEnd(head, val);
                break;
            case 3:
                cout<<"Enter value to insert: ";
                cin>>val;
                cout<<"Enter the target value: ";
                cin>>target;
                insertionBeforeTarget(head, val, target);
                break;
            case 4:
                cout<<"Enter value to insert: ";
                cin>>val;
                cout<<"Enter the target value: ";
                cin>>target;
                insertionAfterTarget(head, val, target);
                break;
            case 5:
                deleteFirst(head);
                break;
            case 6:
                deleteLast(head);
                break;
            case 7:
                cout<<"Enter the target value: ";
                cin>>target;
                deleteBeforeTarget(head, target);
                break;
            case 8:
                cout<<"Enter the target value: ";
                cin>>target;
                deleteAfterTarget(head, target);
                break;
            case 9:
                cout<<"Enter the value of the node to delete: ";
                cin>>val;
                deleteNode(head, val);
                break;
            case 10:
                cout<<"Current list: ";
                displayList(head);
                break;
            case 11:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while(choice!=11);

    return 0;
}
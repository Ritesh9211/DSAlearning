#include<bits/stdc++.h>
using namespace std;
// namespace std;

// class  Node
//     {
//         public:
//         int data;
//         Node *next;
//         Node(int d){
//             data = d;
//             next = NULL;
//         }
//     };
class LinkList{
    struct  Node
    {
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        }
    };
    
    Node* head,*tail;

    public:
    LinkList(){
        head=NULL;
        tail=NULL;
    }

    void insertAtEnd(int d){
        Node* newNode = new Node(d);
        if(head==NULL){
            head=newNode;
            tail=head;
            return;
        }
        //insertion at O(1);
        tail->next = newNode;
        tail = tail->next;
        //at O(n);
        // Node* temp = head;
        // while(temp->next!=NULL){
        //     temp=temp->next;
        // }
        //     temp->next = newNode;
    }
    void insertAtBegining(int d){
        Node* newNode= new Node(d);
        if(head==NULL){
            head= newNode;
            tail=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void deleteNode(int d){
        //3cases 1. delete head node 2. delete last node 3.delete node in btw
        Node* curr=head;
        if(head==NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        if(head->data==d){
            head=head->next;
            delete(curr);
        }
        else{
            while(curr->next!=NULL && curr->next->data!=d){
                curr=curr->next;
            }
            if(curr->next==NULL){
                cout<<"Data does not exist"<<endl;
                return;
            }
            curr->next = curr->next->next;
        }
    }
    void deleteinone(int d){
        //if given to delete curr node
        //just copy the content of next to present node and delete next node
    }

    void print(){
        if(head==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        Node* curr=head;
        while(curr!=NULL){
            cout<<curr->data<<"->";
            curr = curr->next;
        }
    }
    
};

int main(){
    LinkList ll ;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4); 
    ll.insertAtBegining(5); 
    ll.deleteNode(5);
    ll.print();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

    void klastnumber(Node* head, int k){
    Node* temp = head;

    while (k--){
        if (temp == NULL){
            cout << "-1" << endl;
            return;
        }
        temp = temp->next;
    }

    Node* curr = head;
    while (temp != NULL){
        temp = temp->next;
        curr = curr->next;
    }

    cout << "kthlast " << curr->data << endl;
}


Node* deletemiddle(Node* head){
    //incase of even middle node delete second
    if(head->next==NULL) return NULL;
    Node* fast=head,*slow=head;
    Node* pre=NULL;
    while(fast->next!=NULL&& fast->next->next!=NULL){
        fast=fast->next->next;
        pre=slow;
        slow=slow->next;
    }
    if(fast->next!=NULL){
        pre=slow;
        slow=slow->next;
    }
        pre->next=slow->next;
   
    return head;

    /*
    if(head->next==NULL)
            return NULL;
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast= fast->next->next;
       
    } 

    prev->next= slow->next;
    return head;

    */

}

int main(){
    Node* head = createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(6);
    head->next->next->next->next->next->next=createNode(7);
    // print(head);
    klastnumber(head,3);
    head = deletemiddle(head);
    // 10
    // 69 37 72 69 100 84 48 68 87 83
    print(head);
    return 0;
}
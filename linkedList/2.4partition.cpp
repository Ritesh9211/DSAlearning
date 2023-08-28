#include <bits/stdc++.h>

using namespace std;

class LinkedList{
    struct  Node
    {
        int data;
        Node *next;
        Node(int d){
            data = d;
            next=NULL;
        }
    };

    Node* head,*tail;
    
    public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    
    void insert(int d){
        Node* newNode = new Node(d);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=tail->next;
        
    }
    void print(){
        Node* curr=head;
        while(curr!=NULL){
            cout<<curr->data<<"->";
            curr=curr->next;
        }
    }

    void partition(int val){
        vector<Node*>arr;
        Node* curr= head,*pre=NULL;
        while(curr!=NULL){
            if(curr->data >= val){
                pre->next=curr->next;
                curr->next=NULL;
                arr.push_back(curr);
                curr = pre->next;
            }
            else{
                pre=curr;
                curr=curr->next;
            }
        }
        while(arr.size())
        {
            Node* temp = arr[arr.size()-1];
            arr.pop_back();
            pre->next=temp;
            pre = pre->next;
        }
        
    }
    
};





int main(){
    LinkedList ll;
    ll.insert(3);
    ll.insert(5);
    ll.insert(8);
    ll.insert(5);
    ll.insert(10);
    ll.insert(2);
    ll.insert(1);
    ll.partition(5);
    ll.print();
    return 0;
}
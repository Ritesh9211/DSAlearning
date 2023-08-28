#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int data) : data(data), next(nullptr) {}
};

  ListNode* reverseNode(ListNode* curr){
        
        ListNode *temp, *pre=NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr=temp;
        }
        return pre;
    }
    


    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* l1 = reverseNode(a);
        ListNode* l2 = reverseNode(b);
 
        
         ListNode* ans = new ListNode();
        ListNode* temp=ans; //pointing to newNode;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
           if(l1!=NULL){
               sum +=l1->data;
               l1=l1->next;
           }
            if(l2!=NULL){
               sum +=l2->data;
               l2=l2->next;
           }
          
            sum+=carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp=temp->next;
           
        }
      ListNode * sol = reverseNode(ans->next);
        return sol;
    }

void print(ListNode* curr){
    while(curr!=NULL){
        cout<<curr->data;
        if(curr->next) cout<<"->";
        curr = curr->next;
    }
    cout<<endl;
}


// class LinkedList{
//     private: Node *head;
//     public: 
//     LinkedList(): head(nullptr){}
//     functions
// };


int main(){
      // Create example linked lists representing the numbers 342 and 465
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers represented by linked lists
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result as a linked list
    std::cout << "Result: ";
    print(result);

    return 0;
}
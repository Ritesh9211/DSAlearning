#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        if(head->next->next!=NULL && head->next->next->next==NULL){
            if(head->val!=head->next->next->val) return false;
            return true;
        }
        ListNode *temp1=head;
        ListNode *temp2=head;
        while(temp2->next!=NULL && temp2->next->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        ListNode *pre=NULL,*dummy;
        temp2 = temp1->next;
        temp1->next=NULL;
        while(temp2!=NULL){
            dummy=temp2->next;
            temp2->next=pre;
            pre=temp2;
            temp2=dummy;
        }
        temp1=head;
        
        
        while(temp1!=NULL && pre!=NULL){
            if(temp1->val != pre->val) return false;
            temp1 = temp1->next;
            pre = pre->next;
        }
        
        return true;
    }

    int main(){
        ListNode* l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(2);
        l1->next->next->next = new ListNode(1);
        if(isPalindrome(l1)) cout<<"true"<<endl;
        else cout<<"false"<<endl;

        return 0;
    }



// Frequently used bitwise operation tricks for competitive programming -
// Along with intuition of why the trick works.

// 1) Check if the number is odd
// X & 1 = 1

// (Works because only the last bit remains after operation)

// 2) Same logic be extended to check if the kth bit is set
// (X >> k) & 1 = 1

// 3) Flip the kth bit
// X = X ^ (1 << k)

// 4) Set and Unset Kth bit - Instead of XOR use OR/AND
// X = X | (1 << k)
// X = X & ~(1 << k)

// 5) Count set bits [Unlike other tips this one is C++ specific)
// Use __builtin_popcountll, very fast.

// 6) Check if the number is a power of 2
// X & (X - 1) = 0

// (Power of 2 has only one bit set, what happens if we subtract one from such a number, think AND with that)

// 7) Super handy in solving problems many times
// A + B = (A | B) + (A & B)

// (Proof - OR counts every bit once, we want to count bit set in both twice, hence the additional AND too).

// If you found this useful, like this to encourage me to write more such educational posts.
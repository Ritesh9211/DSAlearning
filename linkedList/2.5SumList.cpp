#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr) {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        int sum = x + y + carry;

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    if (carry > 0) {
        current->next = new ListNode(carry);
    }

    return dummyHead->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
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
    printLinkedList(result);

    return 0;
}




/*

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to add two numbers represented by linked lists
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = x + y + carry;

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        return dummyHead->next;
    }

    void printList() {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->val;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList l1, l2;

    l1.append(2);
    l1.append(4);
    l1.append(3);

    l2.append(5);
    l2.append(6);
    l2.append(4);

    ListNode* result = LinkedList::addTwoNumbers(l1.head, l2.head);

    std::cout << "Result: ";
    LinkedList::printList(result);

    return 0;
}

*/
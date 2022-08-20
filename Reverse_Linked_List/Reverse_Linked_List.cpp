#include <iostream>
#include <string>


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}    
};

class Solution {
public:
    static ListNode* reverseList(ListNode* head) {

        if (head == nullptr) {
            return nullptr;        
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode* prev = head;

        ListNode* cur = head->next;
        head->next = nullptr;

        while (cur->next != nullptr)
        {           

            ListNode*  next = cur->next;

            cur->next = prev;
            prev = cur;
            cur = next;



        
        } 
        cur->next = prev;

        return cur;

       
    }
};

int main()
{
    ListNode* head = nullptr;
    ListNode* one = nullptr;
    ListNode* two = nullptr;
    ListNode* three = nullptr;

    // allocate 3 nodes in the heap
    head = new ListNode(1);
    one = new ListNode(2);
    two = new ListNode(3);
    three = new ListNode(4);

    // Connect nodes
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = nullptr;

    ListNode* result = Solution::reverseList(head);
    std::string str_result = "";
    while (result != nullptr) {
  
        str_result += std::to_string(result->val);
        result = result->next;
    }

    if (str_result == "4321") {

        std::cout << "Test Access";
    }
    else {
        std::cout << "Test Denied";
    }
}

//if (head == NULL)
//return NULL;
//if (head->next == NULL)
//return head;
//// Previous pointer
//ListNode* previous = head;
//// Current pointer
//ListNode* curr = head->next;
//head->next = NULL;
//while (curr->next) {
//    ListNode* next = curr->next;
//    curr->next = previous;
//    previous = curr;
//    curr = next;
//}
//curr->next = previous;
//return curr;
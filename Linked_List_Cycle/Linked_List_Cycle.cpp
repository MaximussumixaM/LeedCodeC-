#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution
{
public:
	//Two pointers Algorithm
	static bool hasCycle(ListNode* head)
	{
		// if head is NULL then return false;
		if (head == NULL)
			return false;

		// making two pointers fast and slow and assignning them to head
		ListNode* fast = head;
		ListNode* slow = head;

		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;


			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
			if (fast == slow)
				return true;
		}

		// if traversal reaches to NULL this means no cycle.
		return false;
	}
};


int main()
{
	ListNode* head = NULL;
	ListNode* one = NULL;
	ListNode* two = NULL;
	ListNode* three = NULL;

	// allocate 3 nodes in the heap
	head = new ListNode(3);
	one = new ListNode(2);
	two = new ListNode(0);
	three = new ListNode(-4);

	// Connect nodes
	head->next = one;
	one->next = two;
	two->next = three;
	three->next = two;

	/*print
	while (head != NULL) {
		std::cout << head->val;
		head = head->next;
	}*/

	if (Solution::hasCycle(head) == true) {
		
		std::cout << "Test Access";
	}
	else {
		std::cout << "Test Denied";
	}
	
}

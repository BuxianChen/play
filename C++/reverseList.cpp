// 编译: g++ reverseList.cpp -o reverseList.exe
// 运行: ./reverseList

#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//递归版本
    ListNode* reverseList(ListNode* head) {
        if(head && head->next){
            ListNode *res = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return res;}
        else{
            return head;
        }
    }
};

ListNode* createList(int *arr, int n){
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	for(int i = 0; i < n; i++){
		p->next = new ListNode(*(arr++));
		p=p->next;
	}
	p = head->next;
	delete head;
	return p;
}

void printList(ListNode *head){
	std::cout << "[";
	while(head){
		std::cout<<head->val<<", ";
		head = head -> next;
	}
	std::cout << "]" << std::endl;
}

int main(){
	int arr[4] = {1, 2, 3, 4};
	Solution sol = Solution();
	ListNode *head = createList(arr, 4);
	printList(head);
	std::cout << "reversed:" << std::endl;
	printList(sol.reverseList(head));
	return 0;
}
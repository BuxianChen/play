/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ((headA == nullptr) || (headB == nullptr)) return nullptr;
        ListNode *p = headA, *q = headB;
        while(p!=q){
            p==nullptr ? p=headB : p=p->next;
            q==nullptr ? q=headA : q=q->next;
        }
        return p;
    }
};
};
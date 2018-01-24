//57
// 题目描述
// 在一个排序的链表中，存在重复的结点，
// 请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
    	ListNode *first = new ListNode(-1);
    	first->next = pHead;

    	//双指针游动，注意想象一下画面，就在一条链表上
    	ListNode *p = pHead;
    	ListNode *last = first;

    	while (p != nullptr && p->next != nullptr) 
    	{
    		if (p->val == p->next->val)
    		{
    			int val = p->val;
    			while (p != nullptr && p->val == val)
    				p = p->next;
    			last->next = p;
    		}
    		else
    		{
    			last = p;
    			p = p->next;
    		}
    	}
    	return first->next;
    }
};

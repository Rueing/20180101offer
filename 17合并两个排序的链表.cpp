//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
    	//是否为空链表
        if (pHead1 == nullptr)
        {
        	if (pHead2 == nullptr)
        		return nullptr;
        	return pHead2;
        }
        if (pHead2 == nullptr)
        	return pHead1;

        //确定头指针
        ListNode *pHead = nullptr;
        if (pHead1->val <= pHead2->val)
        {
        	pHead = pHead1;
        	pHead1 = pHead1->next;
        }
        else
        {
		pHead = pHead2;
        	pHead2 = pHead2->next;
        }
        	
        //当链表1、2都不为NULL时，逐一比较，使用3个指针pNode、pHead1、pHead2
        ListNode *pNode = pHead;
        while (pHead1 && pHead2)
        {
        	if (pHead1->val <= pHead2->val)
        	{
        		pNode->next = pHead1;
        		pHead1 = pHead1->next;
        		pNode = pNode->next;
        	}
        	else
        	{
        		pNode->next = pHead2;
        		pHead2 = pHead2->next;
        		pNode = pNode->next;
        	}
        }

        //某一链表为空时，另一链表全部补齐
        while (pHead1)
        {
        	pNode->next = pHead1;
        	pHead1 = pHead1->next;
        	pNode = pNode->next;
        }
        while (pHead2)
        {
        	pNode->next = pHead2;
        	pHead2 = pHead2->next;
        	pNode = pNode->next;
        }

        return pHead;
    }
    
        //递归法
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
    {
    	//每次都是寻找头部
    	if (pHead1 == nullptr)
    		return pHead2;
    	if (pHead2 == nullptr)
    		return pHead1;

    	ListNode *pHead = nullptr;
    	if (pHead1->val <= pHead2->val)
    	{
    		pHead = pHead1;
    		pHead1 = pHead1->next;
    		pHead->next = Merge(pHead1, pHead2);
    	}
    	else
    	{
    		pHead = pHead2;
    		pHead2 = pHead2->next;
    		pHead->next = Merge(pHead1, pHead2);
    	}

        return pHead;
    }
};

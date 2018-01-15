//输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
    	if (pListHead == nullptr || k == 0)
    		return nullptr;
    	//快指针
    	ListNode *pAhead = pListHead;
    	for (unsigned int i = 1; i <= k-1; ++i)//注意i也要定义为unsigned
    	{
    		//若k太大
    		if (pAhead->next == nullptr)
    			return nullptr;
    		else
    			pAhead = pAhead->next;
    	}
    	//慢指针
    	ListNode *pBehind = pListHead;
    	//直到快指针到达尾结点，慢指针就到达倒数第k
    	while (pAhead->next != nullptr)
    	{
    		pAhead = pAhead->next;
    		pBehind = pBehind->next;
    	}
        return pBehind;
    }
};

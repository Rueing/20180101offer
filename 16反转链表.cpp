/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

//特例：1、空链表；2、只有1个结点；
//注意：头部尾部（画图）
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
    	//需要3个指针
    	ListNode *pLeft = nullptr, *pCurr = pHead, *pRight = pHead->next;
    	while (pRight != nullptr)
    	{
    		//反转指向
    		pCurr->next = pLeft;

    		//遍历(3个指针各后移一步)
    		pLeft = pCurr;
    		pCurr = pRight;
    		pRight = pRight->next;
    	}
    	//原始的尾结点
    	pCurr->next = pLeft;
    	return pCurr;
    }
};

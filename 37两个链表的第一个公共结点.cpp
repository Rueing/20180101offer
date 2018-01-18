//37
// 题目描述
// 输入两个链表，找出它们的第一个公共结点。

// 思路：分析具有公共结点的两链表的结构特征
// 思路1、思路2、思路3

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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
    {
        int nlen1 = GetListNodeLength(pHead1);
        int nlen2 = GetListNodeLength(pHead2);
        int nlendiff = nlen1 < nlen2 ? nlen2 - nlen1 : nlen1 - nlen2;
        ListNode *pLong = pHead1;
        ListNode *pShort = pHead2;
        if (nlen1 < nlen2)
        	std::swap(pLong, pShort);

        for(int i = 0; i < nlendiff; ++i)
        	pLong = pLong->next;

        while(pLong && pShort && pLong != pShort)
        {
        	pLong = pLong->next;
        	pShort = pShort->next;
        }
        return pLong;
    }

    int GetListNodeLength(ListNode *pHead)
    {
    	if (!pHead)
    		return 0;
    	ListNode *pNode = pHead;
    	int length = 0;
    	while(pNode)
    	{
    		pNode = pNode->next;
    		++length;
    	}
    	return length;
    }
};

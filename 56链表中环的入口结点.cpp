//56
// 题目描述
// 一个链表中包含环，请找出该链表的环的入口结点。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

//思路：快慢指针(2倍速度)
//		 相遇时2x=x+nr --> x=nr（可取n=1，没什么影响）
//		 x=r，于是画图可知：让两指针分别从头结点、相遇结点出发
//		 相遇结点即为环的入口结点

//注意：若链表不具有环，那么存在->next=nullptr;
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	ListNode *pFast = pHead;
    	ListNode *pSlow = pHead;
    	while (pFast != nullptr && pFast->next != nullptr)
    	{
    		pFast = pFast->next->next;
    		pSlow = pSlow->next;
    		if (pFast == pSlow)
    		{
    			pSlow = pHead;
    			while (pFast != pSlow)
    			{
    				pFast = pFast->next;
    				pSlow = pSlow->next;
    			}
    			return pFast;
    		}
    	}
    	return nullptr;
    }
};

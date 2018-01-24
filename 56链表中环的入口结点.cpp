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
//	相遇时2x=x+nr --> x=nr（可取n=1，没什么影响）
//	x=r，于是画图可知：让两指针分别从头结点、相遇结点出发
//	相遇结点即为环的入口结点

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

    //法2：修改了链表
    ListNode* EntryNodeOfLoop2(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return NULL;

        ListNode* previous = pHead;
        ListNode* current = pHead->next;
        while (current != NULL)
        {
            previous->next = NULL;
            previous = current;
            current = current->next;
        }
        return previous;
    }

    //法3：哈希表
	// 用到了STL中的set，set有一个特性就是不能插入相同元素，
	// 这样只需遍历原List一次就可以判断出有没有环，还有环的入口地址。
	// s.insert(node).second这里在插入的同时也判断了插入是否成功，
	// 如果不成功表明set中已经有该元素了，该元素就是环的入口元素。
    ListNode* EntryNodeOfLoop3(ListNode* pHead)
    {
        set<ListNode*> s;
        ListNode* node = pHead;
        while (node != NULL){
            if (s.insert(node).second)
                node = node->next;
            else
                return node;
        }
        return node;  
    }
};

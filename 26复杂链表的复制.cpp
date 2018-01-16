//26
//首先理清 暴力解法的拷贝思路与步骤
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
        	return nullptr;

        //1、复制结点，并串起来
        RandomListNode *pCurrNode = pHead;
        while(pCurrNode)
        {
        	RandomListNode *pNewNode = new RandomListNode(pCurrNode->label);

        	pNewNode->next = pCurrNode->next;
        	pCurrNode->next = pNewNode;

        	pCurrNode = pNewNode->next;
        }

        //2、“移位”，完成*random的指向
        pCurrNode = pHead;
        while(pCurrNode)
        {
        	if(pCurrNode->random)
        		pCurrNode->next->random = pCurrNode->random->next;
        	
        	pCurrNode = pCurrNode->next->next;
        }

        //3、拆成 原始链表与拷贝链表
        pCurrNode = pHead;
        RandomListNode *pNewHead = pHead->next, *pNewNode = pNewHead;
        while(pNewNode->next)//链尾处，画图分析一下
        {
        	pCurrNode->next = pNewNode->next;
        	pNewNode->next = pCurrNode->next->next;

        	pCurrNode = pCurrNode->next;
        	pNewNode = pNewNode->next;
        }
        pCurrNode->next = nullptr;

        return pNewHead;
    }
};

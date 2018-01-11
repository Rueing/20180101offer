//5输入一个链表，从尾到头打印链表每个节点的值。

//只读

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {

    	if (!head)
    		return vector<int>();//判断是否为空链表

    	ListNode *pNode = head;
        //using std::stack;
		//using std::vector;
    	stack<ListNode* > hyStack;

    	while(pNode)
    	{
    		// std::stack   .push() .pop() .top()
    		hyStack.push(pNode);
    		pNode = pNode->next;//遍历
    	}

        vector<int> printList(hyStack.size());
        for(int i = 0; i < printList.size(); ++i)
        {
        	printList[i] = hyStack.top()->val;//注意是 .top()
        	hyStack.pop();
        }
        return printList;
    }
};

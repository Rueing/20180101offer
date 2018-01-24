//58
// 题目描述
// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。


//思路：注意树根结点的next=nullptr   !中序遍历!(0-9 10个结点的例子)
// 1、当前结点有右子树，那么中序遍历的下一结点就是它右子树的最左结点
// 2、当前结点没有右子树，且它是其父结点的左子结点，那么中序遍历的下一个结点就是它的父结点
// 3、当前结点没有右子树，且它是其父结点的右子结点，
//    那么中序遍历的下一个结点应该是当前结点所在左子树的根
//    因此我们可以顺着其父节点一直向上遍历, 直到找到一个是它父结点的左子结点的结点

// 1左右子树  23父结点


/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
    	if (!pNode)
    		return nullptr;

    	//没有右子树
    	if (pNode->right == nullptr)
    	{
    		while (pNode && pNode->next && pNode == pNode->next->right)
    			pNode = pNode->next;
    		return pNode->next;
    	}
    	else//存在右子树
    	{
    		pNode = pNode->right;
    		while (pNode->left)
    			pNode = pNode->left;
    		return pNode;
    	}
    }
};

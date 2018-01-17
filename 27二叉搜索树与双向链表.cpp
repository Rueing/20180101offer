//27 ***
// 题目描述
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

// 思路（与25相类似，都是遍历问题，只是多需要一步操作）
// 二叉搜索树、从小到大的排序 ---> 可以联想到 中序遍历！
// 由于需要更改指针指向，所以外加一指针，用于追踪。
// 在某子树中，分为3部分：左子树、根结点、右子树。
// 将 左子树最大的结点、根结点、右子树最小的结点 链接起来即可。

// pPre ---> pCurr
// pPre <--- pCurr

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree)
        	return nullptr;

        TreeNode *pConn = nullptr;
        ConvertBST(pRootOfTree, pConn);

        //追踪器在双向链表最后，返回头部即可
        while(pConn->left)
        	pConn = pConn->left;
        return pConn;
    }

    void ConvertBST(TreeNode *pCurr, TreeNode *&pPre)
    {
    	if (!pCurr)
    		return;
    	ConvertBST(pCurr->left, pPre);
    	pCurr->left = pPre;
    	if(pPre)
    		pPre->right = pCurr;
    	pPre = pCurr;
    	ConvertBST(pCurr->right, pPre);
    }
};

//函数中带有*&
//递归遇到叶结点处的分析

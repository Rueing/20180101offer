//39 ***

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
	// 题目描述
	// 输入一棵二叉树，求该树的深度。
	// 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

	//遍历问题，关键在于遍历到叶结点的返回值
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot)
            return 0;//返回0很关键
        
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        
        return (left > right) ? (left + 1) : (right + 1);// 叶结点处0+1
    }

//******************************************************************************//
    //输入一棵二叉树，判断该二叉树是否是平衡二叉树。
    //任意结点的左右子树深度相差不超过1即为平衡二叉树

    //法1：
    //调用TreeDepth计算每个结点的左右子树树深
    bool IsBalanced_Solution1(TreeNode* pRoot) 
    {

    	if (!pRoot)
    		return true;//返回true

    	int left = TreeDepth(pRoot->left);
    	int right = TreeDepth(pRoot->right);
    	int diff = std::abs(left - right);
    	if (diff > 1)
    		return false;

    	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

    //法2：***
    //采用后序遍历，遍历某一个结点时，已经遍历了它的左右子树，
    //那么记录它的深度即可，即可每遍历一个结点就可以判断每个结点是否平衡
    bool IsBalanced_Solution(TreeNode* pRoot) 
    {
    	int depth = 0;
    	return IsBalanced_Solution_Code(pRoot, depth);
    }

    bool IsBalanced_Solution_Code(TreeNode *pRoot, int &depth)
    {
    	if (!pRoot)
    	{
    		depth = 0;
    		return true;
    	}

    	int leftLen, rightLen;//左右子树的深度
    	if (IsBalanced_Solution_Code(pRoot->left, leftLen) && IsBalanced_Solution_Code(pRoot->right, rightLen))
    	{
    		int diff = (leftLen > rightLen) ? (leftLen - rightLen) : (rightLen - leftLen);
    		if(diff <= 1)
    		{
    			depth = (leftLen > rightLen) ? (leftLen + 1) : (rightLen + 1);
    			return true;
    		}
    	}
    	return false;
    }
};

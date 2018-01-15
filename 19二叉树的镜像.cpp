//19
// 思路：
// 递归
// 遍历每个结点，交换其左右子树。(左右都为叶结点也没关系)

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
    void Mirror(TreeNode *pRoot)
    {
    	if (pRoot == nullptr)
    		return;
	//前序
    	TreeNode *tempNode = pRoot->left;
    	pRoot->left = pRoot->right;
    	pRoot->right = tempNode;

    	Mirror(pRoot->left);
    	Mirror(pRoot->right);
    }
};

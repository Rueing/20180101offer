//18
// 思路：
// 递归1：在树A中遍历查找与树B的跟结点相等的结点R，若相等则执行递归2
// 递归2：分别比较树R与树B的左、右子树是否相等

// 边界条件：
// 递归1：遍历完，直至nullptr
// 递归2：树A已经遍历完了，既已是nullptr，而树B还未遍历完。返回false
// 	   树B遍历完了，返回true


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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		bool flag = false;
        
        if (pRoot1 != nullptr && pRoot2 != nullptr)
        {
        	//前序遍历
            if (pRoot1->val == pRoot2->val)
                flag = DoseTree1HaveTree2(pRoot1, pRoot2);
            if(flag == false)
            	flag = HasSubtree(pRoot1->left, pRoot2);
            if(flag == false)
            	flag = HasSubtree(pRoot1->right, pRoot2)
        }
        
        return flag;
    }

    bool DoseTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	//边界条件
    	//顺序注意
    	if (pRoot2 == nullptr)
    		return true;
    	if (pRoot1 == nullptr)
    		return false;
    	if (pRoot1->val != pRoot2->val)
    		return false;

    	return DoseTree1HaveTree2(pRoot1->left, pRoot2->left) && DoseTree1HaveTree2(pRoot1->right, pRoot2->right);
    }

};

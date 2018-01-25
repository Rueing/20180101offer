//61
// 题目描述
// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

// 思路：此题亦为 从上至下遍历。顺序改为了。可以联想到使用后入先出的堆栈，设置2个堆栈即可。
// 奇数行的结点：保存它的左右子结点顺序依次为：先左后右（先左子结点进堆栈stack2，再右）
// 偶数行的结点：保存它的左右子结点顺序依次为：先右后左（先右子结点进堆栈stack1，再左）
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) 
    {
        if (!pRoot)
        	return vector<vector<int> >();

        vector<vector<int> > res;
        vector<int> lineRes;

        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;

        TreeNode *temp = nullptr;
        stk1.push(pRoot);


        while(stk1.empty() == false || stk2.empty() == false)
        {
        	if (stk1.empty() == false)
        	{
        		while (stk1.empty() == false) //1
        		{
        			temp = stk1.top();
        			lineRes.push_back(temp->val);
        			if (temp->left)
        				stk2.push(temp->left);
        			if (temp->right)
        				stk2.push(temp->right);
        			stk1.pop();
        		}
        		res.push_back(lineRes);
        		lineRes.clear();
        	}
        	else
        	{
        		while (stk2.empty() == false) //2
        		{
        			temp = stk2.top();
        			lineRes.push_back(temp->val);
        			if (temp->right)
        				stk1.push(temp->right);
        			if (temp->left)
        				stk1.push(temp->left);
        			stk2.pop();
        		}
        		res.push_back(lineRes);
        		lineRes.clear();
        	}
        }
        return res;
    }  
    //注：1、2while各自循环完成后为“一空一满”
};

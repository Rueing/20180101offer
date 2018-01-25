//60
// 题目描述
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

// 思路：题23相似 层次遍历，使用队列+循环 进行遍历。
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
        	queue<TreeNode*> q;
        	q.push(pRoot);

        	TreeNode *pNode = nullptr;//队头

        	while (!q.empty())
        	{
        		int start = 0, end = q.size();
        		while(start++ < end)
        		{
        			pNode = q.front();
        			lineRes.push_back(pNode->val);
        			q.pop();
        			if (pNode->left)
        				q.push(pNode->left);
        			if (pNode->right)
        				q.push(pNode->right);
        		}
        		res.push_back(lineRes);
        		lineRes.clear();//记得清空lineRes
        	}

        	return res;
        } 
};

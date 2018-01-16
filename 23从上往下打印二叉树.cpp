//23
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
// 思路：
// 	层次遍历，采用队列！
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
    vector<int> PrintFromTopToBottom(TreeNode* root) 
    {
    	if (root == nullptr)
    		return vector<int>();

		vector<int> output;
    	queue<TreeNode*> hyQueue;
    	hyQueue.push(root);
    	
    	TreeNode *pNode = nullptr; //队头

    	while(!hyQueue.empty())//建立循环机制，这样的话，就是左右子树先入队，它才出队
    	{
    		pNode = hyQueue.front();//(跟堆栈一样  .top()   )
    		output.push_back(pNode->val);
    		if(pNode->left)
    			hyQueue.push(pNode->left);//左子树 入队
    		if(pNode->right)
    			hyQueue.push(pNode->right);//右子树 入队
    		hyQueue.pop();//“根节点”出队
    	}
    	return output;
    }
};
//**注意区分
// vector<int> A; 是 .push_back();
// stack<int> B; queue<TreeNode* > C; 是 .push();

//25 ***
// 递归求解 还是遍历问题，只不过最后多了一步！
// 路径指 从根结点-->叶结点
// 某一路径判断完后(即到达了叶子结点)，叶子结点回到它的父结点上！任一结点都要回到父节点，路径删除当前结点
// 递归终止条件：遇到叶子结点
// 传址！
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
    {
    	if (!root)
    		return vector<vector<int> >();
    	vector<vector<int> > output;
    	vector<int> path;
    	int sum = 0;
    	FindPathCode(root, output, path, expectNumber, sum);
    	return output;
    }

    void FindPathCode(TreeNode* pNode, vector<vector<int> > &output, vector<int> &path, int expectNumber, int sum)
    {
    	sum += pNode->val;
    	path.push_back(pNode->val);

    	if(pNode->left == nullptr && pNode->right == nullptr)//叶子结点
    		if(sum == expectNumber)
    			output.push_back(path);

    	if(pNode->left)
    		FindPathCode(pNode->left, output, path, expectNumber, sum);
    	if(pNode->right)
    		FindPathCode(pNode->right, output, path, expectNumber, sum);

    	path.pop_back();//路径回到父结点
    }
};

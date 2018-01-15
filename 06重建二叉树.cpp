/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
    {
      //判断pre、vin大小是否相同、是否为空
    	if (pre.size() != vin.size() || pre.empty())
    		return nullptr;
    	return reConstructBinaryTreeCode(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
    
private:
    TreeNode* reConstructBinaryTreeCode(vector<int> pre, vector<int> vin,
    									int preLeft, int preRight,
    									int vinLeft, int vinRight)
    {
    	//1.由前序确定根结点
    	TreeNode *root = new TreeNode(pre[preLeft]);

        //*.???前序中序只有一个结点时，且前序、中序元素不等：抛出异常
        if (preLeft == preRight)
            if (vinLeft == vinRight && pre[preLeft] == vin[vinLeft])
                return root;
        	else 
                throw std::runtime_error("cannot find root in vin");

    	//2.在中序中查询根结点
    	int vinRootIndex = vinLeft;
    	while (vinRootIndex <= vinRight && vin[vinRootIndex] != pre[preLeft])
    		++vinRootIndex;

    	//3.(在中序)计算左(右)子树序列的长度
    	if (vinRootIndex > vinRight)//细节：没有找着
    		throw std::runtime_error("cannot find root in vin");
    	int leftTreeSonLength = vinRootIndex - vinLeft;
    	int rightTreeSonlength = vinRight - vinRootIndex;

    	//4.回到前序(依据长度划分好左右子树)、中序(根结点左右)
    	//开始递归(6个参数)，注意看是否为根结点
    	//左子树
    	if (leftTreeSonLength > 0)
    		root->left = reConstructBinaryTreeCode(pre, vin,
    											   preLeft + 1, preLeft + leftTreeSonLength,
    											   vinLeft, vinRootIndex - 1);
    	//右子树
    	if (rightTreeSonlength > 0)
    		root->right = reConstructBinaryTreeCode(pre, vin,
    												preLeft + leftTreeSonLength + 1, preRight,
    												vinRootIndex + 1, vinRight);

    	return root;
    }
    
    
    
    
    
    
    /*三种遍历：分别打印出相应的序列*/
    //1、前序遍历
    void preOrder(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return;
        std::cout << pRoot->val << ' ';
        preOrder(pRoot->left);
        preOrder(pRoot->right);
    }
    //2、中序遍历
    void vinOrder(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return;
        vinOrder(pRoot->left);
        std::cout << pRoot->val << ' ';
        vinOrder(pRoot->right);
    }
    //3、后序遍历
    void afterOrder(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return;
        afterOrder(pRoot->left);
        afterOrder(pRoot->right);
        std::cout << pRoot->val << ' ';
    }
    

};

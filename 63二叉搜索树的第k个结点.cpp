//63
// 题目描述
// 给定一颗二叉搜索树，请找出其中的第k大的结点。
// 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
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
	//法1：中序遍历 一遍
    TreeNode* KthNode1(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k < 1)
        	return nullptr;
        vector<TreeNode*> vec;
        Inorder(pRoot, vec);
        if(k > vec.size())
        	return nullptr;
        return vec[k-1];
    }
    void Inorder(TreeNode *pRoot, vector<TreeNode*> &vec)
    {
    	if(!pRoot)
    		return;
    	Inorder(pRoot->left, vec);
    	vec.push_back(pRoot);
    	Inorder(pRoot->right, vec);
    }

    //法2：非递归（###循环法:利用堆栈）实现中序遍历
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
    	if(pRoot == nullptr || k < 1)
    		return nullptr;
    	int i = 1;
    	stack<TreeNode*> stk;
    	TreeNode *p = pRoot;

    	while(p != nullptr || stk.empty() == false)
    	{
    		while(p != nullptr)
    		{
    			stk.push(p);//后入先出
    			p = p->left;
    		}
    		p = stk.top();
    		stk.pop();

    		if(i++ == k)
    			return p;

    		p = p->right;//返回到右子结点
    	}
    	return nullptr;
    }
};

//法3：*** 递归法（比法1好）
class Solution {
    int count = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot){ 
                TreeNode *ret = KthNode(pRoot->left, k);
                if(ret) return ret;
                if(++count == k) return pRoot;
                ret = KthNode(pRoot->right,k);
                if(ret) return ret;
        }
        return nullptr;
    }
};

//24
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

// 思路：
// 递归，每一趟都遍历该序列的子序列
// **后序遍历
// 最后一个数是根结点值，依据下述划分左、右子树
// **二叉排序树
// 左子树所有结点值 < 根结点值
// 右子树所有结点值 > 根结点值

// 先设定 左右子树均满足，为ture

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) 
    {
        if(sequence.empty())
        	return false;
        return VerifySquenceOfBSTCode(sequence, 0, sequence.size() - 1);
    }

    bool VerifySquenceOfBSTCode(vector<int> seq, int left, int right)
    {
    	//不使用while，使用for，因为已知了它的length
        //遍历完！ 后序序列
    	int i = left;
    	for(; i < right; ++i)
    	{
    		if(seq[i] > seq[right])
    			break;
    	}
    	int j = i;
    	for(; j < right; ++j)
    	{
    		if(seq[j] < seq[right])
    			return false; 
    	}

    	//左子树
    	bool flagLeft = true;
    	if(i-1 >= left)
    		flagLeft = VerifySquenceOfBSTCode(seq, left, i-1);
    	//右子树
    	bool flagRight = true;
    	if(right-1 >= i)
    		flagRight = VerifySquenceOfBSTCode(seq, i, right-1);

    	return (flagLeft && flagRight);
    }
};

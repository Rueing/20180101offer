//52
// 题目描述
// 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
// 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
class Solution {
public:
    vector<int> multiply(const vector<int>& A) 
    {
    	if (A.size() <= 1)
    		return vector<int>();

    	//法1：双重循环遍历O(n^2)
    	//法2：不要重复计算，拆分，夹逼
    	int n = A.size();
    	vector<int> B(n, 1);
    	// C[i] = A[0] * A[1] * ... *A[i - 1]
    	int temp = 1;
    	for (int i = 0; i < n; ++i)
    	{
    		B[i] *= temp;
    		temp *= A[i];
    	}

    	// D[i] = A[i + 1] * A[i + 2] * ... *A[n - 1]
    	temp = 1;
    	for (int i = n - 1; i >= 0; --i)
    	{
    		B[i] *= temp;
    		temp *= A[i];
    	}

    	return B;
    }
};

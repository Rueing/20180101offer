//20
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
// 思路：
// 画图观察，每一圈之后，边界的变化(往里收缩):
// 		+1:left、up
// 		-1:right、dowm
// 边界条件：
// 		最后一圈：完整的4步，也可能只需要1步、2步、3步

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
    {
    	//矩阵为空，逻辑或判断前半部分为真则不执行后半部分
        if (matrix.empty() || matrix[0].empty())
            return vector<int>();

    	int up = 0, down = matrix.size() - 1;
    	int left = 0, right = matrix[0].size() - 1;

    	vector<int> outVector;

    	while(left <= right && up <= down)
    	{
	    	//从左到右
	    	for (int i = left; i <= right; ++i)
	    		outVector.push_back(matrix[up][i]);
	    	//从上到下
	    	if (up < down)
	    	{
	    		for (int i = up + 1; i <= down; ++i)
	    			outVector.push_back(matrix[i][right]);
	    	}
	    	//从右到左
	    	if (up < down && left < right)
	    	{
	    		for (int i = right - 1; i >= left; --i)
	    			outVector.push_back(matrix[down][i]);
	    	}
	    	//从下到上
	    	if (up < down - 1 && left < right)
	    	{
	    		for (int i = down - 1; i >= up + 1; --i)
	    			outVector.push_back(matrix[i][left]);
	    	}

	    	++left;
	    	--right;
	    	++up;
	    	--down;
    	}

    	return outVector;
    }
};

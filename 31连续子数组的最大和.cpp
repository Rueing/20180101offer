//31
// 题目描述
// HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,
// 他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,
// 问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
// 你会不会被他忽悠住？(子向量的长度至少是1)

// 思路：举例理解加法过程即可
//       **如何 sum<0，那么将sum至为下一数字！**
//       注意全为 负数 的情况！
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
    	if (array.empty())
    		throw std::runtime_error("array is empty!");
    	int sum = 0, sumMax = array[0];
    	for (int i = 0; i < array.size(); ++i)
    	{
    		if (sum < 0)
    			sum = array[i];
    		else
    			sum += array[i];

    		if (sum > sumMax)
    			sumMax = sum;
    	}
    return sumMax;
    }
};

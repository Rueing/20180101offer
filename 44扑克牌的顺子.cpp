//44
// 判断扑克牌是否为顺子（不考虑花色）

//思路：1、数组排序 2、统计0的数目 3、统计排序后相邻数字之间的间隔和 与0的数目比较即可

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) 
    {
        if (numbers.empty())
        	return false;
        int len = numbers.size();
        int numOfZero = 0;
        //数组排序
        std::sort(numbers.begin(), numbers.end());
        //统计0的数目
        int gap = 0;
        for (int i = 0; i < len && numbers[i] == 0; ++i)
        	++numOfZero;
        //间隔(遍历 相邻两个中的后面那个)
        for (int j = numOfZero + 1; j < len; ++j)
        {
        	if (numbers[j] == numbers[j - 1])
        		return false;
        	else
        	{
        		gap += numbers[j] - numbers[j - 1] - 1;
        		if (numOfZero < gap)//!每有gap时就比较，可能可以提前退出循环，返回false
        			return false;
        	}
        }
        return true;
    }

    //另一种思路：极大极小值的差值与0的个数比较，但还是需要计算是否存在重复数字
};

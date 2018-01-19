//41
// 可总结为 规律题。
class Solution {
public:
// 题目描述——和为S的连续正数序列
// 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
// 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
// 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
// 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
// 输出描述:
// 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

//思路：连续！的数组，和为S的所有序列。区间的增大(currSum <= s)与缩小(currSum > s)。P217
//		弄明白整个过程即可。
    vector<vector<int> > FindContinuousSequence(int sum) 
    {
        if (sum < 3)
        	return vector<vector<int> >();

        vector<vector<int> > output;
        vector<int> res;
        int small = 1, big = 2;
        int currSum = small + big;
        int end = (sum + 1) >> 1;

        while (small < end)
        {
        	if (currSum == sum)
        	{
        		for (int i = small; i <= big; ++i)
        			res.push_back(i);
        		output.push_back(res);
        		res.clear();//注意要清空

        		//继续下一步
        		++big;
        		currSum += big;
        	}
        	else if (currSum > sum)
        	{
        		currSum -= small;
        		++small;
        	}
        	else
        	{
        		++big;
        		currSum += big;
        	}
        }
        return output;
    }

// 题目描述
// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。
// 输出描述:
// 对应每个测试案例，输出两个数，小的先输出。

//思路：递增！的数组，和为s的2个数
//		从两端向中间扫描数组
//		currSum < s ---> small右移
//		currSum > s ---> big左移 

    vector<int> FindNumbersWithSum(vector<int> array,int sum) 
    {
        if (array.size() < 2)
        	return vector<int>();

        vector<int> output; 
        int start = 0, end = array.size() - 1;
        int currSum;
        //最终返回的值，乘积最小，此题可以变形求最大，
        //因为是递增序列，且从两端夹逼，故第一次出现的2个值的乘积是最小的)

        while (start < end)
        {
        	currSum = array[start] + array[end];
        	if (currSum == sum)
        	{
        		output.push_back(array[start]);
        		output.push_back(array[end]);
        		break;
        	}
        	else if (currSum < sum)
        		++start;
        	else
        		--end;
        }
        return output;
    }    
};

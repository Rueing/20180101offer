//34
// 题目描述
// 把只包含因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

// 思路：先理清丑数的概念 1 2 3 4 5 6 8 9 10 12......
// 每一个丑数都是之前存在的丑数*2或*3或*5，
// 下述方法利用空间上的开销节约时间开销，仅仅对丑数进行了计算
// 首先建立大小为index的数组，存储丑数。
// 设想一下，每一个丑数进行*2or*3or*5之后在ugly中都有它的位置
class Solution {
public:
    int GetUglyNumber_Solution(int index) 
    {
    	if (index <= 0)
    		return 0;

    	vector<int> ugly(index);
    	ugly[0] = 1;
    	int index2 = 0, index3 = 0, index5 = 0;

    	for (int i = 1; i < index; ++i)
    	{
    		ugly[i] = std::min(ugly[index2] * 2, std::min(ugly[index3] * 3, ugly[index5] * 5));
    		//此处注意：不能是elseif，因为存在并列关系
    		if (ugly[i] == ugly[index2] * 2)
    			++index2;
    		if (ugly[i] == ugly[index3] * 3)
    			++index3;
    		if (ugly[i] == ugly[index5] * 5)
    			++index5;
    	}
    	return ugly[index - 1];
    }
};


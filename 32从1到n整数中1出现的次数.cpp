//32
// 题目描述
// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
// ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

class Solution {
public:
    int NumberOf1Between1AndN_Solution1(int n)
    {
    	if(n < 1)
    		return 0;
    	int count = 0;
    	for (int i = 1; i <= n; ++i)
    		count += NumberOf1Between1AndN_Solution_1(i);

    	return count;
    }

    int NumberOf1Between1AndN_Solution_1(int n)
    {
    	int count = 0;
    	while(n)
    	{
    		if(n % 10 == 1)
    			++count;
    		n = n / 10;
    	}
    	return count;
    }


    //* 解法2 *  寻找规律
    //* n分为round,weight,former 另外还有每一位的base *
    //解法1中对1-n的每个数都计算，o(n*logn)，而解法2由于是1-n连续的，只对最后一个数即n计算，o(logn)
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if (n < 1)
    		return 0;
    	int count = 0;

    	int base = 1;//从个位开始
    	int weight;
    	int round = n;
    	while(round > 0)
    	{
    		weight = round % 10;
    		round /= 10;
    		if(weight == 0)
    			count += round * base;
    		if(weight == 1)
    			count += round * base + n % base + 1;
    		if(weight > 1)
    			count += round * base + base;

    		base *= 10;
    	}

    	return count;
    }
};

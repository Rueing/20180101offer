//40
// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

// 思路；先考虑这么一个问题：一个整型数组里除了1个数字只出现1次之外，其余都出现了2次。
// 		 进行位运算：与，即可得到这个数字	 
// 思维迁移：把这2个只出现1次的数字分离开来。
// 			 做“与”之后的二进制表示中必有一位不为0，以此来划分为2个子数组。
// 位运算时，注意优先级，保险加上括号！
class Solution {
public:
	//1、数组中只有1个数出现1次，其他都出现2次
	int FindOnceOtherTwice(vector<int> data)
	{
		if (data.empty())
			throw std::invalid_argument("array is empty!");
		int result;
		for (auto val : data)
			result ^= val;
		return result;
	}

	//2、数组中只有2个数出现1次，其他都出现2次
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
    {
    	if (data.empty())
    		return;
    	unsigned int xor_final = 0;
    	for (int i = 0; i < data.size(); ++i)
    		xor_final ^= data[i];

    	//寻找这2个数，在二进制表示中其中一个不同的地方
    	int AUnlikeflag = 0;
    	while (((xor_final & 1) == 0) && (AUnlikeflag < 8 * sizeof(int))) //AUnlikeflag < 8 * sizeof(int) 可省略?
    	{
    		++AUnlikeflag;
    		xor_final = xor_final >> 1;
    	}

    	for (int j = 0; j < data.size(); ++j)
    	{
    		if (((data[j] >> AUnlikeflag) & 1) == 0)
    			*num1 ^= data[j];
    		else
    			*num2 ^= data[j];
    	}
    }
};

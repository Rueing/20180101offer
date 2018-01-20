//47
// 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

//位运算。分三步走：(1)相加不进位--^ (2)求进位--& (3)存在进位，循环回到第一步
class Solution {
public:
    int Add(int num1, int num2)
    {
    	int sum, carry;
    	do
    	{
    		sum = num1 ^ num2;
    		carry = (num1 & num2) << 1;

    		num1 = sum;
    		num2 = carry;
    	}
    	while (num2 != 0);

    	return num1;
    }
};

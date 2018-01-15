输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

class Solution {
public:
	void reOrderArray(vector<int> &array)
	{
		if (array.size() <= 1)
			return;

		//利用辅助空间 存储奇数odd
		vector<int> temparray(array.size());
		int tempIndex = 0;
		for (auto x : array)
		{
			if (x & 1 == 1)
				temparray[tempIndex++] = x;
		}
		//偶数even后移
		int arrayIndex = array.size() - 1;
		for (int i = array.size() - 1; i >= 0; --i)
		{
			if (array[i] % 2 == 0) // array[i] & 1 == 0 有问题？
				array[arrayIndex--] = array[i];
		}
		//奇数odd 拷贝回来
		for (int i = 0; i < tempIndex; ++i)
		{
			array[i] = temparray[i];
		}
		return;
	}
};

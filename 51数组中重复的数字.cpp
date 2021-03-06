//51
// 题目描述
// 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
// 数组中某些数字是重复的，但不知道有几个数字是重复的。
// 也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
// 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) 
    {
    	if (numbers == nullptr || length <= 0)
    		return false;

    	//数组中的元素 值的大小 限定在[0, n-1]之间
    	for (int i = 0; i < length; ++i)
    	{
    		if (numbers[i] < 0 || numbers[i] > length - 1)
    			return false;
    	}

    	//遍历每一个数组元素，与下标比较
    	for (int i = 0; i < length; ++i)
    	{
    		while (numbers[i] != i)
    		{
    			if (numbers[i] == numbers[numbers[i]])
    			{
    				*duplication = numbers[i];
    				return true;
    			}
    			else
    			{
    				std::swap(numbers[i], numbers[numbers[i]]);
    			}
    		}
    	}
    	return false;
    }
    //思考一下：为何时间复杂度为 O(n);
    //数组中的每个数字最多只要交换两次就能找到属于它自己的位置，因而总交换次数 <=2n ?
};

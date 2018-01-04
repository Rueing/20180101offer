class Solution {
public:
/**大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39 */
    int Fibonacci(int n) 
    {
        int r01[2] = {0, 1};
        if (n < 2)
            return r01[n];
        int temp1 = 0;
        int temp2 = 1;
        int result;
        for (int i = 2; i <= n; ++i)
        {
            result = temp1 + temp2;
            
            temp1 = temp2;
            temp2 = result;
            
        }
        return result;
    }
    
/**青蛙跳台阶：考虑起步问题*/   
    
/**跳台阶：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。*/
    int jumpFloor(int number) 
    {
        if (number < 1)
            throw std::runtime_error("invaild input");
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;
        
        int temp1 = 1, temp2 = 2, result;
        for (int i = 3; i <= number; ++i)
        {
            result = temp1 + temp2;
            
            temp1 = temp2;
            temp2 = result;
        }
        return result;
    }

/**变态跳台阶：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。*/
//转化为数学问题：f(n)=2^(n-1)
    int jumpFloorII(int number) 
    {
        if (number <= 0)
            return -1;
        return pow(2, number-1);
    }    
    
/**我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？*/
    int rectCover(int number) 
    {
        if (number < 0)
            return -1;
        if (number <= 2)
            return number;
        
        int temp1 = 1, temp2 = 2, result;
        for (int i = 3; i <= number; ++i)
        {
            result = temp1 + temp2;
            
            temp1 = temp2;
            temp2 = result;
        }
        return result;
    }
};


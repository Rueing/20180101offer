//45
// 圆圈中最后剩下的数

class Solution {
public:
	//法1：用环形链表模拟圆圈***

    //法2：递推公式（推导一遍）
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1)
            return -1;
        int last = 0;
        for (int i = 2; i <= n; ++i)
        {
            last = (last + m) % i;
        }
        return last;
    }
};

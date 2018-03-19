//64
// 题目描述
// 如何得到一个数据流中的中位数？
// 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
// 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

    /**
     * 保持  大顶堆元素个数 >= 小顶堆+1 */

class Solution {
    priority_queue<int, vector<int>, less<int> > bigheap;
    priority_queue<int, vector<int>, greater<int> > smallheap;
     
public:
    void Insert(int num)
    {
        if(bigheap.empty() || num <= bigheap.top())
            bigheap.push(num);
        else
            smallheap.push(num);
        if(bigheap.size() == smallheap.size() + 2)
        {
            smallheap.push(bigheap.top())；
            bigheap.pop();
        }
        if(bigheap.size() + 1 == smallheap.size())
        {
            bigheap.push(smallheap.top())；
            smallheap.pop();
        }
    }
    double GetMedian()
    { 
      return bigheap.size() == smallheap.size() ? (bigheap.top() + smallheap.top()) / 2.0 : bigheap.top();
    }
};

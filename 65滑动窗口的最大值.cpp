//65
// 题目描述
// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
// 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
// 那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
// 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
// {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
// {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
class Solution {
public:
	//法1：暴力解法，时间复杂度o(mn)
    vector<int> maxInWindows1(const vector<int>& num, unsigned int size)
    {
        if(num.size() <= 0 || size > num.size() || size <= 0)
        	return vector<int>();

        vector<int> res;
        for(int i = 0; i <= num.size() - size; ++i)
        {
        	int max = num[i];
        	for(int j=i + 1; j < i + size; ++j)
        	{
        		if(num[j] > max)
        			max = num[j];
        	}
        	res.push_back(max);
        }
        return res;
    }

    //法2：利用 双端队列deque
    //1、从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
    //2、当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
    //3、把每次滑动的num下标加入队列
    //4、当滑动窗口首地址i大于等于size时才开始写入窗口最大值
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
    	if(num.size() < size || size < 1)
    		return vector<int>();

    	vector<int> res;
    	deque<int> deq;
    	for(unsigned int i = 0; i < num.size(); ++i)//o(n)
    	{
    		while(deq.size() && num[deq.back()] <= num[i])//1、尾部处理
    			deq.pop_back();
    		while(deq.size() && size < i - deq.front() + 1)//2、头部处理
    			deq.pop_front();
    		deq.push_back(i);//3
    		if(i >= size - 1)
    			res.push_back(num[deq.front()]);//4、头部必是最大值
    	}
    	return res;
    }
    //!!!!!! unsigned  ###头部处理处 
    //原先使用 deq.front() < i - size + 1 来判断会出错 因为起初 i-size 会出现负号！！
};

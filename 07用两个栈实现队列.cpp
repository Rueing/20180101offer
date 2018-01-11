//7 堆栈：后入先出， 队列：先入先出
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

class Solution
{
public:
    void push(int node) 
    {
        stack1.push(node);
    }

    int pop() 
    {
        
    	// 输出栈stack2为空，需要先将输入栈的数据压入stack2
        if(stack2.empty() == true)
        {
        	// 报错
        	if (stack1.empty() == true)
        		return -1;
        	while(stack1.empty() != true)
        	{
        		stack2.push(stack1.top());
        		stack1.pop();
        	}
        }
        // 此时 stack2不空，直接出栈即可
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

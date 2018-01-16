//21
//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
// 解法：辅助栈(存放最小值)
class Solution {
public:
    void push(int value) 
    {
        m_data.push(value);
        if (m_min.empty())
        	m_min.push(value);
        else
        {
        	if (value < m_min.top())
        		m_min.push(value);
        	else
        		m_min.push(m_min.top());        	
        }
    }

    void pop() 
    {
        if (m_data.empty())
        	throw std::runtime_error("stack is empty!");
        else
        {
        	m_data.pop();
        	m_min.pop();
        }
    }

    int top() //似乎比较多余？？
    {
        if (m_data.empty())
        	throw std::runtime_error("stack is empty!");
        else
        	return m_data.top();//????????
    }
    
    int min() 
    {
        if (m_data.empty())
        	throw std::runtime_error("stack is empty!");
        return m_min.top();
    }

private:
	stack<int> m_data;
	stack<int> m_min;
};

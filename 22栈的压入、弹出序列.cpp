//22
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
// 序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
// （注意：这两个序列的长度是相等的）
/**
 * 栈的压入和弹出序列
 * 思路：
 * 用一个栈模拟压入和弹出：
 *  循环入栈至所有元素都入栈
 *      每次判断栈顶元素是否等于弹出序列popV的当前元素
 *      如果是就循环弹出到不是为止
 * 最终栈为空说明压栈序列是对应的弹出序列，否则false
 * 特例：两个序列为空或长度不相等
 * 
 */
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
    	if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
    		return false;
        stack<int> hyStack;
        int index = 0;
        for(int val : pushV)
        {
        	hyStack.push(val);
        	//弹出后，while循环继续比较
        	//注意数组越界，堆栈溢出！    hyStack.empty() != true;
        	while(!hyStack.empty() && hyStack.top() == popV[index])
        	{
        		hyStack.pop();
        		++index;
        	}

        }
        if (hyStack.empty())
        	return true;
        else
        	return false;
    }
};

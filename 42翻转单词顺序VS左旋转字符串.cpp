//42
class Solution {
public:

// 题目描述
// “student. a am I” --> “I am a student.”。

//思路1：两步翻转
    string ReverseSentence(string str)
    {
        if (str.empty())
        	return "";

        //1、整个句子翻转
        int left = 0, right = str.size() - 1;
      	while(left < right)
        	std::swap(str[left++], str[right--]);

        //2、翻转每个单词
        //寻找分隔符
        left = 0;
        for(int i = 0; i < str.size(); ++i)
        {
        	if (str[i] == ' ')
        	{
        		right = i - 1;
	      		while(left < right)
        			std::swap(str[left++], str[right--]);
        		left = i + 1;
        	}
        	else if (i == str.size() - 1)
        	{
        		right = i;
	      		while(left < right)
        			std::swap(str[left++], str[right--]);
        	}
        }
        return str;
    }

//思路2：参考
//       堆栈的后入先出，建立2个栈
//		 同样是实现2次翻转
    string ReverseSentence_stack(string str)
    {
    	if (str.empty())
    		return "";
    	string output;
    	stack<char> stack1;
    	stack<char> stack2;

    	//1、一次翻转
    	for (auto c : str)
    		stack1.push(c);
    	//2、每个单词翻转
    	while (!stack1.empty())
    	{
    		if (stack1.top() != ' ')
    		{
    			stack2.push(stack1.top());
    			stack1.pop();
    		}
    		else//遇到分隔符' '
    		{
    			while (!stack2.empty())
    			{
    				output += stack2.top();
    				stack2.pop();
    			}
    			output += stack1.top();//空格也要加上
                	stack1.pop();//不要忘记！！！
    		}
    	}
    	//最后一次（最后一个单词）没有遇到分隔符' '，需要另行加上
    	while (!stack2.empty())
    	{
    		output += stack2.top();
    		stack2.pop();
    	}

    	return output;
    }


//******************************************************************************//
// 题目描述
// 循环左移
// 字符序列S=”abcXYZdef”,输出3位后的结果，即“XYZdefabc”。

    //法1：对于abcXYZdef，考虑他的自连接串abcXYZdefabcXYZdef，新的串正好是链接串的一个子串
    string LeftRotateString1(string str, int n) 
    {
        if (str.empty() || n < 0)
        	return "";
        int strLen = str.size();
        n %= strLen;
        str += str;
        return str.substr(n, strLen);
    }

    //法2：数学规律
    string LeftRotateString2(string str, int n) 
    {
        if (str.empty() || n < 0)
        	return "";
        string res(str);
        int strLen = str.size();
        n %= strLen;
        for (int i = 0; i < strLen; ++i)
        {
        	res[i] = str[(i + n) % strLen];
        }
    }

    //方法1、2都需要空间上的开销
    //法3：翻转问题
    //     ab|cdefg -> ba|gfedc -> cdefg|ab
    //	   先两部分翻转，再整体翻转
    string LeftRotateString(string str, int n) 
    {
    	if (str.empty() || n < 0)
    		return "";
    	int strLen = str.size();
    	n %= strLen;
    	//(1)两部分翻转
    	int left = 0, right = strLen - 1, mid = n - 1;
    	while (left < mid)
    		std::swap(str[left++], str[mid--]);
    	mid = n;
    	while (mid < right)
    		std::swap(str[mid++], str[right--]);
    	//(2)整体翻转
    	left = 0, right = strLen - 1;
    	while (left < right)
    		std::swap(str[left++], str[right--]);
    	return str;
    }    
};

//53
// 题目描述
// 请实现一个函数用来匹配包括'.'和'*'的正则表达式。
// 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
// 在本题中，匹配是指字符串的所有字符匹配整个模式。
// 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
class Solution {
public:
    bool match(char* str, char* pattern)
    {
    	if (str == nullptr && pattern == nullptr)
    		return false;

    	return matchCode(str, pattern);
    }

    bool matchCode(char *str, char *pattern)
    {
    	if (*str == '\0' && *pattern == '\0')
    		return true;
    	if (*str != '\0' && *pattern == '\0')//测试用例"", ".*"，因而(*str == '\0' && *pattern != '\0')不能加上
    		return false;

    	//pattern中下一位(j+1)是'*'时，特别考虑
    	if (*(pattern+1) == '*')
    	{
    		// s[i]==p[j] 时
    		//(1)*表示出现0次----------> (i, j+2)
    		//(2)*表示出现1次----------> (i+1, j+2)
    		//(3)*表示出现2次及以上----> (i+1, j)
    		if (*str == *pattern || (*str != '\0' && *pattern == '.'))
    			return matchCode(str, pattern+2) || matchCode(str+1, pattern+2) || matchCode(str+1, pattern);
    		else // s[i]!=p[j] 时
    			return matchCode(str, pattern+2);
    	}
    	// pattern中下一位(j+1)不是'*'时，正常考虑
    	else
    		if (*str == *pattern || (*str != '\0' && *pattern == '.'))
    			return matchCode(str+1, pattern+1);
    	
    	return false;
    }
};

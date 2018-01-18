//35
// 题目描述
// 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置

//解法1：暴力求解，遍历每一个字符，让它与之后的字符比较（时间复杂度o(n^2)）
//解法2：哈希表（散列表）（时间复杂度o(n)）--空间换时间
class Solution {
public:
    int FirstNotRepeatingChar(string str) 
    {
    	if (str.empty())
    		return -1;

    	std::unordered_map<char, int> mapCount;
    	for (auto c : str)
    		++mapCount[c];

    	for (int i = 0; i < str.size(); ++i)
    	{
    		if (mapCount[str[i]] == 1)
    			return i;
    	}
    	//没找着
    	return -1;  
    }
};

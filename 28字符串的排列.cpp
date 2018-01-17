//28

class Solution {
public:
// 题目描述(排列)
// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入描述:输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

// 思路：递归，str分为2部分，第一个字符、剩余字符。第一个字符与它们交换（包含自身）。
    vector<string> Permutation(string str) 
    {
        if(str.empty())
        	return vector<string>();
        set<string> setOutput;

        PermutationCode(setOutput, str, 0);

        vector<string> output(setOutput.begin(), setOutput.end());
        return output;
    }

    void PermutationCode(set<string> &setOutput, string str, int startHead)
    {
    	if(startHead == str.size() - 1)
    	{
    		setOutput.insert(str);
    		return;
    	}

    	for(int i = startHead; i <= str.size() - 1; ++i)
    	{
    		std::swap(str[startHead], str[i]);
    		PermutationCode(setOutput, str, startHead + 1);
    	}
    }


///////////////////////
    //组合
    
};


//33
// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

// 使用C++标准库（C++标准库 与 STL 关系？）

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) 
    {
    	string output = "";

    	std::sort(numbers.begin(), numbers.end(), [](int a, int b){
    		string A = std::to_string(a) + std::to_string(b);
    		string B = std::to_string(b) + std::to_string(a);
    		return A < B;
    	});//分号勿漏

    	for(int i = 0; i < numbers.size(); ++i)
    	{
    		output += std::to_string(numbers[i]);
    	}
        return output;
    }
};


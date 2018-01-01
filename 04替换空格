#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		//判断输入是够为空
		if (str == NULL || length <= 0)
			return;

		int i = 0;
		int numOfBlank = 0;
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
				++ numOfBlank;
			++i;
		}

		//字符串以'/0'字符结尾，但字符串长度不包含'/0'
		int old_lenth = i;
		int new_lenth = old_lenth + numOfBlank * 2;

		//判断新的字符长度是否超出给定的长度lenth
		if (new_lenth + 1 > length)
			return;

		//拷贝与替换
		int index_old = old_lenth;
		int index_new = new_lenth;
		while (index_new >= 0)
		{
			if (str[index_old] != ' ')
				str[index_new--] = str[index_old--];
			else
			{
				--index_old;
				str[index_new--] = '0';
				str[index_new--] = '2';
				str[index_new--] = '%';
			}
		}

	}
};


int main(int argc, char *argv[])
{
	char str[] = "We Are Happy"; //12个字符，不包括\0
	//char str[13] = "We Are Happy"; //不能为12，应是13
	cout << str << endl;
	cout << strlen(str) << endl;
	Solution s;
	s.replaceSpace(str, 20);
	cout << str << endl;

	return 0;
}

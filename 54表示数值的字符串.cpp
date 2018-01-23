//54
// 题目描述
// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
// 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == nullptr)
        	return false;
        if (*string == '+' || *string == '-')
        	++string;
        if (*string == '\0')
        	return false;

        bool numeric = true;

        scanDigits(&string);
        if (*string != '\0')
        {
        	//小数
        	if (*string == '.')
        	{
        		++string;
        		scanDigits(&string);
        		if (*string == 'e' || *string == 'E')
        			numeric = isExponential(&string);
        	}
        	//整数
        	else if (*string == 'e' || *string == 'E')
        		numeric = isExponential(&string);
        	//+or-之后是其它
        	else
        		numeric = false;//比如'+'之后是'-'
        }
        return numeric && *string == '\0';
    }

    void scanDigits(char **string)
    {
    	while(**string != '\0' && **string >= '0' && **string <= '9')
    		++(*string);
    }

    bool isExponential(char **string)
    {
    	++(*string);
    	if (**string == '+' || **string == '-')
    		++(*string);
    	if (**string == '\0')
    		return false;
    	scanDigits(string);
    	return (**string == '\0') ? true : false;
    }
};

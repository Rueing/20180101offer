class Solution
{
  public:
    int StrToInt(string str)
    {
        if (str.empty()) //空字符串
            return 0;
        int num = 0; //64位系统，long是8字节，int是4字节
        bool minus = false;
        for (size_t i = 0; i < str.size(); ++i)
            if ('0' <= str[i] && str[i] <= '9')
            {
                num = num * 10 + (str[i] - '0');
                if ((!minus && (num > std::numeric_limits<int>::max())) || (minus && (-num < std::numeric_limits<int>::min())))
                    throw std::range_error("value out of range");
            }

            else if (i == 0 && (str[i] == '+' || str[i] == '-'))
            {
                if (str.size() == 1)
                    return 0;
                if (str[i] == '-')
                    minus = true;
            }
            else
                return 0;
        if (minus)
            num = -num;
        return num;
    }
};

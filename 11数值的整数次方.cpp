class Solution {
public:
    double Power(double base, int exponent) 
    {
        //判断double、float类型是否为零不能用==0.0
        if ((base > -0.0000001) && (base < 0.0000001) && (exponent < 0))
            throw std::invalid_argument("0 cannot be denominator");
        double result = 1.0;
    	if (exponent < 0)
            result = 1.0 / PowerWithUnsignedExponent(base, std::abs(exponent));
        else
            result = PowerWithUnsignedExponent(base, exponent);
        return result;
    }
    
    double PowerWithUnsignedExponent(double base, unsigned int exponent)
    {
        double result = 1.0;
        for(int i = 1; i <= exponent; ++i)
        {
            result *= base;
        }
        return result;
    }
    
};

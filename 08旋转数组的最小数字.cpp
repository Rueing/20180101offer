//8
//方法1：最大值后面的即为最小值
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        if (rotateArray.size() == 0)
            return 0;
        if (rotateArray.size() == 1)
            return rotateArray[0];
        int i = 0;
        while(rotateArray[i] <= rotateArray[i+1])
        {
            ++i;
        }
        return rotateArray[i+1];

//方法2：此题为 有序查找！应当使用二分查找法或者差值查找
//除特例外，分两种情况，考虑 中间值 与 左边界     
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        if (rotateArray.empty())
            return 0;
        int mid = 0;
        int left = 0, right = rotateArray.size() - 1;
        //旋转0个元素(特例1)
        if (rotateArray[left] < rotateArray[right]) 
			return rotateArray[left];
        //当left、riht相邻时即到头了，riht即为最小值（旋转数组定义，12不能算是旋转数组？）
        while(left + 1 < right)
        {
            int mid = (left + right) >> 1;
			//特例{1,1,1,0,1}、{1,0,1,1,1} (特例2)
            if ((rotateArray[mid] == rotateArray[left]) && (rotateArray[mid] == rotateArray[right]))
                return findMinInOrder(rotateArray, left, right);
            if (rotateArray[mid] >= rotateArray[left])
                left = mid;
            else
                right = mid;
        }
        return rotateArray[right];
    }
    
    int findMinInOrder(vector<int> rotateArray, int left, int right)
    {
        int minNum = rotateArray[left];
        for (int i = left; i <= right; ++i)
        {
            if (minNum > rotateArray[i])
                minNum = rotateArray[i];
        }
        return minNum;
    }
};

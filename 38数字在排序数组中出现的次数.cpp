//38
// 统计一个数字在排序数组中出现的次数。

//思路：已排序 ---> 二分查找
//		两次二分查找
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) 
    {
        if (data.empty())
        	return 0;
        int first = GetNumberOfKFirst(data, k);
        int last = GetNumberOfKLast(data, k);
        if (first == -1 || last == -1)
        	return 0;

        return last - first + 1;
    }

    int GetNumberOfKFirst(vector<int> data, int k)
    {
    	int left = 0, right = data.size() - 1;
    	int mid;
    	while(left <= right)
    	{
    		mid = (left + right) >> 1;
    		if (data[mid] < k)
    			left = mid + 1;
    		else if (data[mid] > k)
    			right = mid - 1;
    		else if (mid == 0 || data[mid-1] != k)
    			return mid;
    		else
    			right = mid - 1;
    	}
    	return -1;//没找着first
    }

    int GetNumberOfKLast(vector<int> data, int k)
    {
    	int left = 0, right = data.size() - 1;
    	int mid;
    	while(left <= right)
    	{
    		mid = (left + right) >> 1;
    		if (data[mid] < k)
    			left = mid + 1;
    		else if (data[mid] > k)
    			right = mid - 1;
    		else if (mid == data.size() - 1 || data[mid+1] != k)
    			return mid;
    		else
    			left = mid + 1;
    	}
    	return -1;//没找着last
    }
};

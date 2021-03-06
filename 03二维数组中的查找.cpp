class Solution
{
public:
	bool Find(int target, vector<vector<int>> array)
	{
		if (array.size() == 0)
			return false;
		vector<int>::size_type i = 0;
		int j = array[0].size() - 1;
		bool flag = false;
		while ((i < array.size()) && (j >= 0))
		{
			if (target < array[i][j])
				--j;
			else if (target > array[i][j])
				++i;
			else
			{
				flag = true;
				break;
			}
		}
		return flag;
	}
};


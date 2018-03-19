class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        int size=input.size();
        if(size <= 0 || k > size || k <= 0)
            return vector<int>();
        //最大堆
        priority_queue<int, vector<int>, less<int> > Q(input.begin(), input.begin() + k);
        for (int i = k; i < size; ++i)
        {
            if (input[i] < Q.top())
            {
                Q.pop();
                Q.push(input[i]);
            }
        }
        vector<int> output(k);
        for (int i = k - 1; i >= 0; --i)
        {
            output[i] = Q.top();
            Q.pop();
        }
        return output;
    }
};

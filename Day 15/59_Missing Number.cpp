class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int s = 0;
        int c = 0;
        int n = nums.size();
        for (int i = 0; i <= n; i++)
        {
            s = s + i;
        }
        for (int i = 0; i < n; i++)
        {
            c = c + nums[i];
        }
        return s - c;
    }
};
class Solution
{
public:
    bool isValid(int mid, int k, vector<int> &nums)
    {
        int sum = 0;
        int count = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > mid)
            {
                count++;
                sum = nums[i];
            }
            if (count > k)
                return false;
        }
        return true;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isValid(mid, k, nums) == true)
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};
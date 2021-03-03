class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        const int n = nums.size() + 1;
        vector<int> v;
        int missing = -1, dup = -1;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            arr[nums[i]]++;
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            if (arr[i] == 2)
                missing = i;
            if (arr[i] == 0)
                dup = i;
        }
        v.push_back(missing);
        v.push_back(dup);
        return v;
    }
};
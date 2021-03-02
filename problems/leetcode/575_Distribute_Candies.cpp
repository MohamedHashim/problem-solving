class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int cnt = 1, max = candyType.size() / 2;
        sort(candyType.begin(), candyType.end());
        for (int i = 0; i < candyType.size() - 1; i++)
        {
            if (candyType[i] != candyType[i + 1])
                cnt++;
        }
        return min(max, cnt);
    }
};
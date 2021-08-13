class Solution {
    static bool cmp(int a , int b) {
        return abs(a) < abs(b);
    }
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map <int, int> mp;
        for (int a : arr)
            mp[a]++;

        sort(arr.begin(), arr.end(), cmp);

        for (int a : arr) {
            if (mp[a] == 0)
                continue;

            if (mp[2 * a] == 0)
                return false;
            else
            {
                mp[a]--;
                mp[2 * a]--;
            }
        }
        return true;
    }
};
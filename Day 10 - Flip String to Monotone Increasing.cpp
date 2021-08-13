class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int counter_flips = 0 , counter_one = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                counter_one++;
            else {
                counter_flips = min(counter_flips + 1 , counter_one);
            }
        }

        return counter_flips;
    }
};
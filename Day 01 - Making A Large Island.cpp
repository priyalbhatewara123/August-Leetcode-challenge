class Solution {

    int get(int i, int j , vector<vector<int>>& g) {
        return ((i < 0 || i >= g.size() || j < 0 || j >= g[0].size()) ? 0 : g[i][j]);
    }

    int paint(int i , int j , int color , vector<vector<int>>& g) {
        if (get(i, j, g) != 1)
            return 0;
        g[i][j] = color;

        return 1 + paint(i + 1, j, color, g) + paint(i - 1, j, color, g) + paint(i, j + 1, color, g) + paint(i, j - 1, color, g);
    }
public:
    int largestIsland(vector<vector<int>>& g) {
        int res = 0;
        vector<int> sizes = {0, 0};
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                if (g[i][j] == 1)
                    sizes.push_back(paint(i, j, sizes.size(), g));
            }
        }

        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                if (g[i][j] == 0) {
                    int sum = 1;
                    unordered_set <int> s;
                    s.insert(get(i + 1, j, g));
                    s.insert(get(i - 1, j, g));
                    s.insert(get(i, j + 1, g));
                    s.insert(get(i, j - 1, g));

                    for (auto x : s)
                        sum += sizes[x];

                    res = max(res , sum);
                }
            }
        }

        return res == 0 ? g.size() * g[0].size() : res;
    }
};
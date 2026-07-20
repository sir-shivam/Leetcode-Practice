class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        int tot = n * m;
        k %= tot;

        if (k == 0) return grid;

        vector<vector<int>> ans(n, vector<int>(m));

        for (int num = 0; num < tot; num++) {

            int i = num / m;
            int j = num % m;

            int newNum = (num + k) % tot;

            int ni = newNum / m;
            int nj = newNum % m;

            ans[ni][nj] = grid[i][j];
        }

        return ans;
    }
};
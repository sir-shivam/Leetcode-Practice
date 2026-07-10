class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        vector<int> fur(n);

        int r = 0;
        for (int l = 0; l < n; l++) {
            r = max(r, l);

            while (r + 1 < n && arr[r + 1].first - arr[l].first <= maxDiff)
                r++;

            fur[l] = r;
        }

        int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));

        up[0] = fur;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u > v)
                swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (fur[u] == u) {
                ans.push_back(-1);
                continue;
            }

            int curr = u;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][curr] < v) {
                    curr = up[k][curr];
                    steps += (1 << k);
                }
            }

            if (fur[curr] < v) {
                ans.push_back(-1);
            } else {
                ans.push_back(steps + 1);
            }
        }

        return ans;
    }
};
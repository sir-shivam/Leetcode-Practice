using pp = tuple<int, int, int>;

class DisJointset {

public:
    vector<int> sz;
    vector<int> par;

    DisJointset(int n) {
        sz.resize(n + 1, 1);

        par.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (par[x] == x)
            return x;

        return par[x] = find(par[x]);
    }

    void connect(int x, int y) {

        int u = find(x);
        int v = find(y);

        if (u == v)
            return;

        if (sz[u] >= sz[v]) {
            par[v] = u;
            sz[u] += sz[v];
        } else {
            par[u] = v;
            sz[v] += sz[u];
        }
    }
};

class Solution {

    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<tuple<int, int>> dis;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num = i * n + j;
                dis.push_back({grid[i][j], num});
            }
        }

        sort(dis.begin(), dis.end());

        DisJointset dsu(n * m + 1);
        vector<vector<bool>> active(n, vector<bool>(n, false));

        for (auto& [height, cell] : dis) {

            int r = cell / n;
            int c = cell % n;

            active[r][c] = true;

            for (auto& [dx, dy] : dir) {

                int nr = r + dx;
                int nc = c + dy;

                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                if (active[nr][nc]) {
                    dsu.connect(cell, nr * n + nc);
                }
            }

            if (dsu.find(0) == dsu.find(n * n - 1))
                return height;
        }

        return -1;
    }
};
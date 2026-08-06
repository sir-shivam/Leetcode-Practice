using pp = tuple<long long , int, int>;

class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost, int source,
                                      int target) {

        if (source == target) {
            return {0, power};
        }

        const long long INF = 1e18;

        vector<vector<pair<int, int>>> adj(n);

        for (auto& ed : edges) {
            int u = ed[0];
            int v = ed[1];
            int t = ed[2];

            adj[u].push_back({v, t});
        }

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        pq.push({0, power, source});

        vector<vector<long long>> dis(n,vector<long long>(power + 1, INF));
        dis[source][power] = 0;
        while (!pq.empty()) {

            auto [d, pow, node] = pq.top();

            pq.pop();
            
            if (d != dis[node][pow]) continue;

            if (pow < cost[node])
                continue;


            int np = pow - cost[node];

            for (auto& [a, t] : adj[node]) {
                if (1LL* t + d < dis[a][np]){

                    dis[a][np] = 1LL*t + d;
                    pq.push({1LL*t + d, pow - cost[node], a});
                }
            }
        }

        long long bestTime = INF;
        long long bestPower = -1;

        for (int p = 0; p <= power; p++) {
            if (dis[target][p] < bestTime) {
                bestTime = dis[target][p];
                bestPower = p;
            } else if (dis[target][p] == bestTime) {
                bestPower = max(bestPower, 1LL * p);
            }
        }

        if (bestTime == INF) return {-1, -1};
        return {bestTime, bestPower};
    }
};

using pp = pair<long long , int>;

class Solution {

    int const MOD = 1e9 + 7 ;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int , long long >>> adj(n );

        for(auto & rd : roads){
            int u = rd[0];
            int v = rd[1];

            long long  w = rd[2];

            adj[u].push_back({ v , w});

            adj[v].push_back({ u , w});
        }

        priority_queue<pp , vector<pp> , greater<pp>> pq;

        vector<pair<long long , long long > > dis(n , {LLONG_MAX , 0 } );


        pq.push({ 0 , 0 });

        dis[0].first = 0 ;
        dis[0].second = 1;

        while(!pq.empty()){
            auto [ d , node] = pq.top();

            pq.pop();

            // if(d > dis[node].first ) continue;

            for(auto & [a , w] : adj[node] ){
                if(dis[a].first == d + w){
                    dis[a].second = (dis[a].second + dis[node].second) % MOD;
                }else if(d+ w < dis[a].first ){
                    dis[a].first = d+w;
                    dis[a].second =  dis[node].second;
                    pq.push({d+w , a});
                }
            }
        }

        if(dis[n-1].first == LLONG_MAX ) return 0 ;


        return dis[n-1].second;
        

        
    }
};
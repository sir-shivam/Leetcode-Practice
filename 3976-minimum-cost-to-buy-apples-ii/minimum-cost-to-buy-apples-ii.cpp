class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        
        vector<vector<pair<int , long long >>> empty(n);
        vector<vector<pair<int , long long >>> carry(n);

        for( auto & rd : roads){
            int u = rd[0];
            int v = rd[1];
            int cost = rd[2];
            int tax = rd[3];

            empty[u].push_back({ v , cost});
            empty[v].push_back({ u , cost});

            carry[u].push_back({ v , 1LL *cost * tax});
            carry[v].push_back({ u , 1LL  * cost * tax});
        }

        const long long INF = 1e18;

        vector<int> ans( n );

        vector<long long > d1( n ) , d2( n);

        using pp = pair<long long , long long >;


        for( int src = 0 ; src < n ; src ++){
            fill(d1.begin() , d1.end() , INF);
            fill(d2.begin() , d2.end() , INF);

            
            priority_queue<pp , vector<pp> , greater<pp>> pq;

            d1[src] = 0 ;
            pq.push({ 0 , src});

            while(!pq.empty()){
                auto [dis , node]  = pq.top();
                pq.pop();

                if(dis > d1[node]) continue;

                for(auto & [ nxt , w] : empty[node]){
                    if(d1[nxt] > dis+ w){
                        d1[nxt] = dis + w;
                        pq.push({d1[nxt] , nxt});
                    }
                }
            }

            while(!pq.empty()) pq.pop();

            d2[src] = 0 ;
            pq.push({ 0 , src});

            while(!pq.empty()){
                auto [dis , node] = pq.top();

                pq.pop();

                if(dis > d2[node]) continue;

                for( auto & [nxt , w] : carry[node]){
                    if(d2[nxt] > dis + w ){
                        d2[nxt] = dis + w ;
                        pq.push({ d2[nxt] , nxt });
                    }
                }
            }

            long long best = prices[src];

            for( int shop = 0 ; shop < n ; shop ++ ){
                if( d1[shop] == INF || d2[shop] == INF) continue;

                best = min( best , d1[shop] + d2[shop] + 1LL * prices[shop]);
            }

            ans[src] = best ;
        }

        return ans;
    }
};
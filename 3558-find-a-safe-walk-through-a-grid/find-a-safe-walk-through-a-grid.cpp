class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> res(n,vector<int>(m,INT_MAX));

        res[0][0]=grid[0][0];

        deque<pair<int,int>> dq;

        dq.push_front({0,0});
        vector<int> rows={-1,0,1,0};
        vector<int> cols={0,1,0,-1};
        while(!dq.empty()){
          auto [r,c]=dq.front();
          dq.pop_front();

          for(int i=0;i<4;i++){
            int nr=r+rows[i];
            int nc=c+cols[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(res[nr][nc]>res[r][c]+grid[nr][nc]){
                    res[nr][nc]=res[r][c]+grid[nr][nc];
                     if(grid[nr][nc]==0){
                    dq.push_front({nr,nc});
                }
                else{
                    dq.push_back({nr,nc});
                }
                }
               
            }
          }

        }
        
          int minHealth=res[n-1][m-1];

          return health-minHealth>=1;

    }
};
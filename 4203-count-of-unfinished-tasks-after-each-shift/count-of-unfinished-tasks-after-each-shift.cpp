class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {

        int n = tasks.size();

        vector<long long > arr( n , 0 );

        arr[0] = 1LL * tasks[0];

        for( int i = 1 ; i < n ; i++){
            arr[i] = 1LL * arr[i-1] + tasks[i];
        }

        long long com = 0 ;

        int m = shifts.size();
        vector<int> ans( m );

        int a = 0 ;

        for( int i = 0 ; i < m ; i++){
            
            long long  tot = com + 1LL * shifts[i];

            auto  it = upper_bound( arr.begin() + a , arr.end() , tot ) - arr.begin();

            if( it == n ) {
                a = 0 ;
                com = 0 ;
            }else{
                a = it ;
                com = tot ;
                if( com < 0 ){
                    com = 0 ;
                }
            }
            ans[i] = ( n - it);
        }

        return ans;
    }
};
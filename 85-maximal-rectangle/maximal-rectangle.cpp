class Solution {

    int n ;
    vector<int> NSE( vector<int> & arr ){
        vector<int> nums( n , n  );

        stack<int > st ;

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(!st.empty()) {
                nums[i] = st.top();
            }

            st.push(i);
        }

        return nums;
    }

    vector<int> PSE(vector<int> & arr){
        vector<int> nums( n , -1);

        stack<int> st ;

        for( int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(!st.empty()) {
                nums[i] = st.top();
            }

            st.push(i);
        }

        return nums;
    }


    int largestRectangleArea(vector<int> heights) {
        n = heights.size();

    
        vector<int> nse = NSE(heights);

        vector<int> pse = PSE(heights);

        int  ans = 0 ;

        for(int i = 0 ; i < n ; i++){

            ans = max( ans , heights[i]);

            ans = max( ans , (heights[i] * ( nse[i] - pse[i] - 1)));

        }


        return ans;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        

        int ans = 0 ;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mat(n , vector<int> ( m ));

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j <m ; j++){
                mat[i][j] = matrix[i][j] - '0';
            }
        }


        ans = max( ans , largestRectangleArea(mat[0]));
        for( int i = 1 ; i < n ; i ++){
            for( int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0 ) continue;
                mat[i][j] = mat[i][j] + mat[i-1][j];
            }

            ans = max( ans , largestRectangleArea(mat[i]));
        }

        return ans;
    }
};
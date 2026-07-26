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
public:
    int largestRectangleArea(vector<int>& heights) {
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
};
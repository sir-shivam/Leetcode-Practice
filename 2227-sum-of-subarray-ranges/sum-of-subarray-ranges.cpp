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

    vector<int> NGE( vector<int> & arr ){
        vector<int> nums( n , n  );

        stack<int> st ;

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] <=  arr[i]){
                st.pop();
            }

            if(!st.empty()) {
                nums[i] = st.top();
            }

            st.push(i);
        }

        return nums;
    }

    vector<int> PGE(vector<int> & arr){
        vector<int> nums( n , -1);

        stack<int> st ;

        for( int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

            if(!st.empty()) {
                nums[i] = st.top();
            }

            st.push(i);
        }

        return nums;
    }

    int const MOD = 1;


public:
    long long subArrayRanges(vector<int>& nums) {
        n = nums.size();

        vector<int> nse = NSE(nums);

        vector<int> pse = PSE(nums);

        long long ans = 0 ;

        for( int i = 0 ; i < n ; i++){

            int left = i - pse[i];
            int right = nse[i] - i ;

            int len = right - left -1 ;

            long long ans1 = left * right;
            ans1 *= nums[i];
            

            ans = ( ans + ans1 );
        }

        vector<int> nge = NGE(nums);

        vector<int> pge = PGE(nums);

        long long ans2 = 0 ;

        for( int i = 0 ; i < n ; i++){

            int left = i - pge[i];
            int right = nge[i] - i ;

            int len = right - left -1 ;

            long long ans1 = left * right;
            ans1 *= nums[i];
            

            ans2 = ( ans2 + ans1 ) ;
        }

    
        return ans2 - ans ;



    }
};
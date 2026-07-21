class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st ;

        int n = nums2.size();

        vector<int> arr(n , -1);
        map<int , int> mpp;

        for( int i = n-1 ; i >= 0 ; i --){
            while(!st.empty() && st.top() <= nums2[i] ){
                st.pop();
            }

            if(!st.empty()){
                arr[i] = st.top();
            }

            mpp[nums2[i]] = i ;

            st.push(nums2[i]);
        }

        // for(auto & [a , b] : mpp){
        //     cout << a << " -"  << b << endl;;
        // }


        int m = nums1.size();
        vector<int> ans( m , -1);
        for( int i = 0 ;i < m ; i++){
            if(mpp.count(nums1[i])){
                ans[i] = arr[mpp[nums1[i]]];
            }
        }

        return ans;
        
    }
};
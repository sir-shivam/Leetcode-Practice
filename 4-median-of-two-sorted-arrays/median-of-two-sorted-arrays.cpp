class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        if( n == 0 && m == 0  ){
            return 0.0 ;
        }

        

        // median will be at position n + m / 2 ;

        if(  n > m ) return findMedianSortedArrays( nums2 , nums1);

        int l = 0 ;
        int r = n ;



        while( l <= r ){
            int i = ( l + r ) / 2;
            int j = ( n + m +1 ) / 2 - i;

            int l1 = i == 0 ? INT_MIN : nums1[i-1];
            int r1 = i == n ?INT_MAX :  nums1[i];

            int l2 = j == 0 ? INT_MIN : nums2[j-1];
            int r2 = j == m ? INT_MAX : nums2[j];

            if( l1 <= r2 && l2 <= r1){
                if(( m + n ) % 2 == 0) {
                    return ( max(l1 , l2 ) + min(r1 , r2 )) /2.0 ;
                }else{
                    return max( l1 , l2);
                }
            }else if( l1 > r2){
                r = i - 1;
            }else{
                l = i +1;
            }
        }

        return 0;

    }
};
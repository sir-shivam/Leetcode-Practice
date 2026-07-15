class Solution {

    void merge( int l , int mid , int r , vector<int> & nums){
        
        int left = l ;
        int right = mid+1;

        vector<int> arr;

        while( left <= mid && right <= r){
            if( nums[left] <= nums[right]){
                arr.push_back(nums[left]);
                left ++;
            }else{
                arr.push_back(nums[right]);
                right ++;
            }
        }

        while( left <= mid){
             arr.push_back(nums[left]);
                left ++;
        }
        
        while(right <= r){
             arr.push_back(nums[right]);
            right ++;
        }

        for(int i = l ; i  <= r ; i ++){
            nums[i] = arr[ i - l ] ;
        }
    }

    void help( int l , int r , vector<int> & nums){

        if( l >= r ) return ;
        int mid = l + ( r - l ) / 2;

        help( l , mid , nums);

        help( mid +1 , r , nums);

        merge( l , mid , r , nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        help( 0 , n-    1 , nums);
        return nums;
    }
};
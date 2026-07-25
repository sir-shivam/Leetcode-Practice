class Solution {
public:
    int trap(vector<int>& height) {
        

        int leftMax = 0 ;
        int rightMax = 0 ;

        int n = height.size();
        int l = 0 ;
        int r = n-1 ;


        long long ans = 0 ;

        while( l <= r){
            
            if(height[l] <= height[r]){
                if(height[l] >= leftMax){
                    leftMax = height[l];
                }else{
                    ans += leftMax - height[l];
                }

                l++;
            }else{
                if(height[r] >= rightMax){
                    rightMax = height[r];
                }else{
                    ans += rightMax - height[r];
                }

                r --;
            }
        }

        return ans;
    }
};
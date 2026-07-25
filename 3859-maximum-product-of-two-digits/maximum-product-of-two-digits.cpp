class Solution {
public:
    int maxProduct(int n) {
       vector<int> arr;
        while(n>0){
            arr.push_back(n%10);
            n=n/10;
        }
        long long maxAns=0;
        for(size_t i=0;i<arr.size()-1;i++){
            for(size_t j=i+1;j<arr.size();j++){
               long long ans= 1LL*arr[i]*arr[j];
                maxAns=max(ans,maxAns);
            }
        }


        return maxAns;
        
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
    vector<vector<int>> arr(n , vector<int> ( 26 , 0 ));

    for( int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < strs[i].size() ; j ++  ){
            arr[i][strs[i][j] - 'a'] ++;
        }
    }

    map< vector<int> , int> mpp;

    vector<int> ans( n , -1);

    int idx = 0 ;

    for( int i = 0 ; i < n ; i++){
        if( mpp.count(arr[i])){
            ans[i] = mpp[arr[i]];
        }else{
            mpp[arr[i]] = idx ;
            ans[i] = idx ++ ;
        }
    }

    vector<vector<string>> res( idx );

    for(int i= 0 ; i < n ; i++){
        res[ans[i]].push_back(strs[i]);
    }

    return res;

    }
};
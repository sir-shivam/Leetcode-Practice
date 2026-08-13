/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    map<TreeNode* , map<int , int>> dp;

    int help( TreeNode*  node , int prev ){

        // dont steal here 

        if(node == NULL) return 0 ;
        if(dp.count(node ) && dp[node].count(prev)) return dp[node][prev];

        int left  = help( node -> left , 0  );

        int right = help( node -> right , 0  );

        // stealing 
        int st = 0 ;

        if( prev == 0  ){
            int left =  help( node -> left , 1);
            int right =  help( node -> right , 1);

            st = node -> val + left + right;
        }

        return dp[node][prev] =    max( { st , left +right});

    }
public:
    int rob(TreeNode* root) {
        
        dp.clear();

        return help( root , 0 );
    }
};
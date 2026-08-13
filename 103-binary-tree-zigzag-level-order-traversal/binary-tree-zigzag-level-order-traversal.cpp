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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        int cnt = 0 ;

        if( root == NULL) return {};

        queue<TreeNode* > q;
        q.push(root);
        vector<vector<int>> ans;

        while(!q.empty()){


            int s = q.size();
            cnt ++;
            vector<int> curr(s);

            for( int i = 0 ; i < s ; i++){
                
                auto node = q.front();

                q.pop();

                int id = cnt % 2 ? i : s - i -1;
                

                curr[id] = node -> val;

                if(node -> left ) q.push(node -> left);
                if( node -> right ) q.push(node -> right);

            }

            ans.push_back(curr);
            

        }

        return ans;
    }
};
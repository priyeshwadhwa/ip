/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        
        int res = 0;
        subpathSums(root, sum, res);
        return res;        
    }
    
    vector<int> subpathSums(TreeNode* n, int sum, int &res)
    {
        if(!n) return {};
        
        vector<int> vec;
        auto l = subpathSums(n->left, sum , res);
        auto r = subpathSums(n->right, sum , res);
        for(auto i=l.begin();i!=l.end();i++)
        {
            if(n->val + *i == sum)
                res++;
            vec.push_back(n->val+*i);
        }
        for(auto i = r.begin();i!=r.end();i++)
        {
            if(n->val+*i==sum)
                res++;
            vec.push_back(n->val+*i);
        }
        
        if(n->val == sum) 
            res++;
        vec.push_back(n->val);
        return vec;
    }
};

// better java solution
    public int pathSum(TreeNode root, int sum) {
        HashMap<Integer, Integer> preSum = new HashMap();
        preSum.put(0,1);
        return helper(root, 0, sum, preSum);
    }
    
    public int helper(TreeNode root, int currSum, int target, HashMap<Integer, Integer> preSum) {
        if (root == null) {
            return 0;
        }
        
        currSum += root.val;
        int res = preSum.getOrDefault(currSum - target, 0);
        preSum.put(currSum, preSum.getOrDefault(currSum, 0) + 1);
        
        res += helper(root.left, currSum, target, preSum) + helper(root.right, currSum, target, preSum);
        preSum.put(currSum, preSum.get(currSum) - 1);
        return res;
    }
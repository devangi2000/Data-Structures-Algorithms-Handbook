// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
// or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. 
// You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please
// be creative and come up with different approaches yourself.

// Example 1:

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
// Example 4:

// Input: root = [1,2]
// Output: [1,2]
// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -1000 <= Node.val <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL)
                s.append("#,");
            else{
                s.append(to_string(curr->val) + ",");
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#"){
                curr->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ',');
            if(str == "#"){
                curr->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

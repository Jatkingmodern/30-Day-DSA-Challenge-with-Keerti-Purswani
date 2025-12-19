/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    int getLength(ListNode* &head) {
        int len = 0;
        ListNode* curr = head;

        while (curr) {
            len++;
            curr = curr->next;
        }

        return len;
    }

    TreeNode* solve(ListNode* &head, int n) {
        if (!head) return NULL;
        if (n <= 0) return NULL;
        // for left subtree
        TreeNode* leftSubtree = solve(head, n/2);
        TreeNode* root = new TreeNode(head->val);
        // connect root's left to leftsubtree
        root->left = leftSubtree;
        // update head same as i++
        head = head->next; // index count increases with one
        // for right subtree
        TreeNode* rightSubtree = solve(head, n - n/2 - 1); // remaing total node from right subtree
        // connect the root to rightSubtree
        root->right = rightSubtree;

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);

        return solve(head, n);
    }
};

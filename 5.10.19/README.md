## 538. Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

### Example:
```
Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
```

### My solution
```
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode *> nodevec;
        loadNode2Vec(root,nodevec);
        for (int i=nodevec.size()-2;i >= 0;i--) {
            nodevec[i]->val += nodevec[i+1]->val;
        }
        return root;
    }
    void loadNode2Vec(TreeNode *root,vector<TreeNode *> &nodevec){
        if (root == NULL)
            return ;
        loadNode2Vec(root->left,nodevec);
        nodevec.push_back(root);
        loadNode2Vec(root->right,nodevec);
    }
};
```

### Result
```
Runtime: 40 ms, faster than 97.78% of C++ online submissions for Convert BST to Greater Tree.
Memory Usage: 24.4 MB, less than 99.09% of C++ online submissions for Convert BST to Greater Tree.
```

### Analysis
The output of `In-Order Traversal` is a array from low to high. For example, `5 2 13 1 3 11 14 ->  1 2 3 5 11 13 14`.
and then `a[i]+=a[i+1] (i from size-2 to 0)`.

## 21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

### Example:
```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

### My solution
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL && l2==NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode * temp = NULL, * node = l1;
        while (node) {
            // occur in start, only run once
            // a most complex part
            if (l2 && l2->val < node->val){
                // reset the head point of l1
                l1 = l2;
                temp=l2->next;
                l2->next=node;
                l2=temp;
                // reset the begin 
                node=l1;
                // without node=node->next
                continue;
            }
            // occur in end
            if (node->next == NULL){
                node->next = l2;
                break;
            }
            // occur in middle
            if (l2 && l2->val < node->next->val && l2->val >= node->val) {
                temp = l2->next;
                insert(node,node->next,l2);
                l2=temp;
            }
            node = node->next;
        }
        return l1;
    }
    void insert(ListNode * before,ListNode * after,ListNode * insertnode){
        if (after == NULL||before == NULL||insertnode == NULL)
            return;
        before->next = insertnode;
        before->next->next = after;
    }
};
```

### Result
```
Runtime: 8 ms, faster than 99.54% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 9 MB, less than 99.71% of C++ online submissions for Merge Two Sorted Lists.
```

### Analysis
In this question, I have to consider many situations.
- `L1's length > l2's length` (notice the `l2==NULL`)
- `L1's length > l2's length` (solved in `//occur in end`)
- `Numbers in l2 entirely less or partially less than l1's numbers` (solved in `//occur in start and //occur in middle`)
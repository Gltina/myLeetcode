## 226. Invert Binary Tree
Invert a binary tree.

### Example:
```
Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

### My solution
``` C++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
           return root;
        invertTree(root->right);
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(temp);
        return root;
    }
};
```

### Result
```
Runtime: 4 ms, faster than 98.81% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.2 MB, less than 54.91% of C++ online submissions for Invert Binary Tree.
```

### Analysis
Using `In-Order Traversal` to solved it.

## 70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

### Example 1:
```
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```
### Example 2:
```
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

### My solution (not pass)
```C++
class Solution {
public:
	int climbStairs(int n) {
		int count_2 = 0, count_1 = 0;
		int steps = 0;
		for (int i = 0; i < n; i++) {
			count_2 = i;
			count_1 = n - count_2 * 2;
			if (count_1 < 0)
				break;
			steps += C((count_1 > count_2) ? count_1 : count_2, count_1 + count_2);
		}
		return steps;
	}
	// Cmn
	int C(int m, int n) {
		int up, down;
		up = multip(n-m+1,n);
		down = multip(1,m);
		return up / down;
	}
	int multip(int b,int e) {
		int sum = 1;
		for (int i = b; i <= e;i++) {
			sum *= i;
		}
		return sum;
	}
};
```

### Result
```
Runtime Error Message:
Line 28: Char 8: runtime error: signed integer overflow: 479001600 * 13 cannot be represented in type 'int' (solution.cpp)
Last executed input:
35
```

### Analysis
I will find another way to solve it.


## 728. Self Dividing Numbers
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

### Example 1:
```
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
```

### My solution
``` C++
class Solution {
public:
   vector<int> selfDividingNumbers(int left, int right) {
		int num[5] = { 0 };
		vector<int> result;
		bool satisf = true;
		unsigned int count = 0, a = 0;
		for (int N = left; N <= right; N++) {
			a = N, count = 0;
			for (int i = 0; i < 5; i++) {
				// Obtain each number
				num[i] = (N % (unsigned int)pow(10, i + 1)) / pow(10, i);
				// Curr num is vaild
				if (a){
					if (!num[i] || N % num[i] != 0) {
						satisf = false;
						break;
					}
					count++;
					a /= 10;
				}
			}// end for
			if (satisf) {
				result.push_back(N);
			}
			satisf = true;
		}// end for
		return result;
	}
};
```

### Result
```
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Self Dividing Numbers.
Memory Usage: 8.6 MB, less than 65.41% of C++ online submissions for Self Dividing Numbers.
```

### Analysis
``` C++
N: number
num:int num[]; // store each single number of N

num[i] = (N % (unsigned int)pow(10, i + 1)) / pow(10, i);
```

## 852. Peak Index in a Mountain Array
Let's call an array A a mountain if the following properties hold:
- A.length >= 3
- There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]

Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

### My solution
``` C++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
		for (int i = 1; i < A.size(); i++) {
			if (A[i] > A[i - 1])
				continue;
			else
				return i - 1;
		}
        return 0;
	}
};
```

### Result
```
Runtime: 16 ms, faster than 97.63% of C++ online submissions for Peak Index in a Mountain Array.
Memory Usage: 9.5 MB, less than 73.58% of C++ online submissions for Peak Index in a Mountain Array.
```

### Analysis
None


## 104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

### My solution
``` C++ 
//recursion
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right +1;
    }
};
```
or
``` C++
// no recursion
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int depth = 1;
        vector <TreeNode*>nodevec;
        nodevec.push_back(root);
		// Arrive the bottom when there are no rising of size()
        int b = 0,e = nodevec.size();
        while (b != e){
            for (int i=b;i<e;i++){
                if (nodevec[i]->left) nodevec.push_back(nodevec[i]->left);
                if (nodevec[i]->right)nodevec.push_back(nodevec[i]->right);
            }
            b = e;
            e = nodevec.size();
            if (e > b)
                depth ++;
        }
        return depth;
    }
};
```

### Result
```
// recursion
Runtime: 16 ms, faster than 99.00% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 19.2 MB, less than 80.45% of C++ online submissions for Maximum Depth of Binary Tree.
```
```
// no recursion
Runtime: 16 ms, faster than 99.00% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 19.4 MB, less than 55.93% of C++ online submissions for Maximum Depth of Binary Tree.
```
### Analysis
None
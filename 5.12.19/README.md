## 1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

### Example:
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

### My solution
``` C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0;i<nums.size();i ++) {
            for (int j=i+1;j <nums.size();j++) {
                if (nums[i] + nums[j] == target)
                    return vector<int>{i,j};
            }
        }
        return vector<int>();
    }
};
```

### Result
```
Runtime: 132 ms, faster than 36.80% of C++ online submissions for Two Sum.
Memory Usage: 9.4 MB, less than 83.32% of C++ online submissions for Two Sum.
```

### Analysis
None
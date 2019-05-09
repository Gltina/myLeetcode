## 448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in **O(n) runtime**? You may assume the returned list does not count as extra space.

### Example:
```
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
```

### My solution 
```C++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty())
            return nums;
        vector<int>result;
        for (int i=0;i<nums.size();i++) {
            while (nums[nums[i]-1] != nums[i]){
                my_swap(nums[nums[i]-1],nums[i]);
            }
        }// end for
		// Cannot operate in above for
        for (int i=0;i<nums.size();i++) {
            if(i+1 != nums[i])
                result.push_back(i+1);
        }
        return result;
    }
    void my_swap(int &a,int &b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
};
```

### Result
```
Runtime: 112 ms, faster than 96.66% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 14.9 MB, less than 99.49% of C++ online submissions for Find All Numbers Disappeared in an Array.
```

### Analysis
Using the strategy of `1 ≤ a[i] ≤ n`.

## 169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears **more than** `⌊ n/2 ⌋ `times.

You may assume that the array is **non-empty** and the majority element **always exist** in the array.

### Example 1:
```
Input: [3,2,3]
Output: 3
```
### Example 2:
```
Input: [2,2,1,1,1,2,2]
Output: 2
```

### My solution
``` C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int,int> res;
        for (int i=0;i<nums.size();i++){
            res[nums[i]]++;
            if (res[nums[i]] > nums.size()/2)
                return nums[i];
        }
        return 0;
    }
};
```
OR
```C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = 0;
        int count = 0;
        for (int i=0;i <nums.size();i++) {
            if (count == 0){
                curr = nums[i];
            }
            if (curr == nums[i]) {
                count ++;
            }
            else{
                count --;
            }
        }
		return curr;
    }
};
```

### Result
```
Runtime: 24 ms, faster than 61.96% of C++ online submissions for Majority Element.
Memory Usage: 11.2 MB, less than 67.48% of C++ online submissions for Majority Element.
```

```
Runtime: 20 ms, faster than 98.28% of C++ online submissions for Majority Element.
Memory Usage: 11.2 MB, less than 68.81% of C++ online submissions for Majority Element.
```

### Analsis
The first solution uses the map of STL. A relatively same solution is based on `sort` function. However, the second solution is wonderful since it uses the `Moore voting algorithm` *(but in my solution, which is more concise and trimmed)*.


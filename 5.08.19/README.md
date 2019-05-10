## 283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

### Example:
```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```
### Note:
You must do this **in-place** without making a copy of the array.
**Minimize** the total number of operations.

### My solution
``` C++
void moveZeroes(vector<int>& nums) {
        int temp=0,not_zero_index=0;
        for (int i=0;i< nums.size();i++) {
            not_zero_index = i;
            if (nums[i] == 0){
                for (int  j=i;j<nums.size();j++) {
                    if (nums[j] != 0){
                        not_zero_index = j;
                        break;
                    }
                } // end for
                //my_swap(nums[i],nums[not_zero_index]);
                temp = nums[i];
                nums[i] = nums[not_zero_index];
                nums[not_zero_index] = temp;
            }
        }
    }
```

```C++
void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i=0;i< nums.size();i++) {
            if (nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        for (int k=j;k<nums.size();k++) {
            nums[k] = 0;
        }
    }
```

### Result
```
Runtime: 20 ms, faster than 37.57% of C++ online submissions for Move Zeroes.
Memory Usage: 9.5 MB, less than 67.71% of C++ online submissions for Move Zeroes.
```
```
Runtime: 16 ms, faster than 99.12% of C++ online submissions for Move Zeroes.
Memory Usage: 9.7 MB, less than 7.63% of C++ online submissions for Move Zeroes.
```

### Analysis
This is a classic question. The difference between the first and second solution is there is no special search operation to locate `not_zero_index` in the first solution.

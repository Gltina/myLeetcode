class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int num[10000] = {0};
        for (int i=0;i< A.size();i++) {
            num[A[i]] ++;
            if (num[A[i]] >= A.size()/2){
                return A[i];
            }
        }
        return -1;
    }
};

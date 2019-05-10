class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int index = 0;
        for (int j = 0;j < S.size();j++){
            for (int i=0;i < J.size();i++){
                if (S[j] == J[i]){
                    index ++;
                }
            }
        }
        return index;
    }
};

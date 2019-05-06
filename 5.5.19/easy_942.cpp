// 加的时候从 0->N
// 减的时候从 N->0
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int b = 0,e = S.size();
        vector<int>result;
        for (int i=0;i<S.size();i++) {
            if (S[i] == 'I'){
                result.push_back(b);
                b++;
            }else{
                result.push_back(e);
                e--;
            }
        }// end for
        result.push_back(b);
        return result;
    }
};

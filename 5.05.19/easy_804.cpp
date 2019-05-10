class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> codes_vec;
        for (int i = 0;i < words.size();i ++) {
            string str;
            for (int j=0;j < words[i].size();j++) {
                str += code[words[i][j]-97];
            }
            if (!exist(codes_vec,str)){
                codes_vec.push_back(str);
            }
        }
        return codes_vec.size();
    }
    bool exist(vector<string> &codes_vec,string str){
        for (int i=0;i < codes_vec.size();i++){
            if (codes_vec[i] == str){
                return true;
            }
        }
        return false;
    }
    
};

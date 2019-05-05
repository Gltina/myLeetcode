class Solution {
public:
    string removeOuterParentheses(string S) {
		string str;
		string temp_str;
		int rcount = 0, lcount = 0;
		int j;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '(') {
				temp_str.clear();
				rcount = 0, lcount = 0;
				for (j = i; j < S.size(); j++) {
					if (S[j] == ')') {
						temp_str += S[j];
						lcount++;
						if (rcount == lcount) {
							break;
						}
					}
					else if (S[j] == '(') {
						temp_str += S[j];
						rcount++;
					}
				}// end for
			} // end if
			str += temp_str.substr(1, temp_str.size() - 2);
			i = j;
		}
		return str;
	}
};

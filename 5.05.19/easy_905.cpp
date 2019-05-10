class Solution {
public:
   vector<int> sortArrayByParity(vector<int>& A) {
		vector <int> resultvec;
		resultvec.resize(A.size(),0);
		int even_index = 0, odd_index = A.size() - 1;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] % 2 == 0 || A[i] == 0) {
				resultvec[even_index] = A[i];
				even_index++;
			}
			else {
				resultvec[odd_index] = A[i];
				odd_index--;
			}
		}
		return resultvec;

	}
};
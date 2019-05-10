class Solution {
public:
    	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); i++) {
			reverse_invert(A[i]);
		}
		return A;
	}
	void reverse_invert(vector<int> &vec) {
		for (int i = 0; i < vec.size() / 2; i++) {
			my_swap(vec, i, vec.size() - i - 1);
			vec[i] = (vec[i] == 0) ? 1 : 0;
			vec[vec.size() - i - 1] = (vec[vec.size() - i - 1] == 0) ? 1 : 0;
		}
		if(vec.size() %2 != 0)
			vec[vec.size()/2] = (vec[vec.size() / 2] == 0) ? 1 : 0;
	}
	void my_swap(vector<int> &vec, int a, int b) {
		int temp;
		temp = vec[a];
		vec[a] = vec[b];
		vec[b] = temp;
	}
};

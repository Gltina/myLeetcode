class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector <int> sorted;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] >= 0) {
				sorted.push_back(A[i] * A[i]);
			}
		}
		for (int i = 0; i < A.size(); i++) {
			if (A[i] < 0) {
				insert2sorted(A[i]*A[i],sorted);
			}
		}
		return sorted;
	}
	void insert2sorted(int num, vector <int> &sorted) {
		if (sorted.empty()) {
			sorted.push_back(num);
			return;
		}
		vector <int>::iterator insert_pos = sorted.end();
		for (vector <int>::iterator it = sorted.begin();
			it != sorted.end(); ++it
			) {
			if (num <= *it) {
				insert_pos = it;
				break;
			}
		}
		sorted.insert(insert_pos, num);
		return;
	}
};

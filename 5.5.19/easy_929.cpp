class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		string vaildemail;
		vector<string> vaildemails;
		for (int i = 0; i<emails.size(); i++) {
			bool copy_ok = true;
			bool pass_at = false;
			vaildemail.clear();
			for (int j = 0; j < emails[i].size(); j++) {
				if (emails[i][j] == '+') {
					copy_ok = false;
				}
				if (emails[i][j] == '@') {
					copy_ok = true;
					pass_at = true;
				}
				if (pass_at || (copy_ok && emails[i][j] != '.')) {
					vaildemail += emails[i][j];
				}
			}// end for 
			if (!exist(vaildemails, vaildemail)) {
				vaildemails.push_back(vaildemail);
			}
		}
		return vaildemails.size();
	}
	bool exist(vector<string>& emails, string email) {
		for (int i = 0; i<emails.size(); i++)
			if (emails[i] == email)
				return true;
		return false;
	}
};

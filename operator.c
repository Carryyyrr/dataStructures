#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player {
public:
	string score;
	Player(string score) : score(score) {};
	bool operator >(const Player& other)  const {
		int len = score.size();
		int scores1 = 0;
		int scores2 = 0;
		int cosc1 = 0;
		int cosc2 = 0;
		int tmp = 0;
		vector<int> fails1;
		vector<int> fails2;
		for (int i = 0; i < len; i++) {
			char c = score[i];
			if (c == '1') {
				scores1++;
				tmp++;
			}
			else if (c == '0') {
				if (cosc1 < tmp) {
					cosc1 = tmp;
				}
				tmp = 0;
				fails1.push_back(i);
			}
		}
		if (tmp > cosc1) {
			cosc1 = tmp;
		}
		tmp = 0;
		for (int i = 0; i < len; i++) {
			char c = other.score[i];
			if (c == '1') {
				scores2++;
				tmp++;
			}
			else if (c == '0') {
				if (cosc2 < tmp) {
					cosc2 = tmp;
				}
				tmp = 0;
				fails2.push_back(i);
			}
		}
		if (tmp > cosc2) {
			cosc2 = tmp;
		}
		if (scores1 > scores2) {
			return true;
		}
		else if (scores1 < scores2) {
			return false;
		}
		else {
			if (cosc1 > cosc2) {
				return true;
			}
			else if (cosc1 < cosc2) {
				return false;
			}
			else {
				for (int j = 0; j < (int)fails1.size(); j++) {
					if (fails1[j] > fails2[j]) {
						return true;
					}
					else if (fails1[j] < fails2[j]) {
						return false;
					}
				}
				return false;
			}
		}
	}
};


int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<int> nums;
	vector<Player> S;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		Player p(s);
		S.push_back(p);
		nums.push_back(i + 1);
	}
	for (int i = 0; i < n-1; i++) {
		Player tmp = S[i + 1];
		int j = i;
		while (j >= 0 && tmp > S[j] ) {
			swap(S[j], S[j + 1]);
			swap(nums[j], nums[j + 1]);
			j--;
		}
	}
	for (int i = 0; i < n-1; i++) {
		cout << nums[i] << ' ';
	}
	cout << nums[n - 1];
	return 0;
}

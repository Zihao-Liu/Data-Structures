#include "iostream"
#include "string"
#include "vector"
using namespace std;

class KMP {
private:
	vector<int> getnext(string pattern) {
		vector<int> next(pattern.size(), 0);
		int k = 0;
		for (int q = 0; q < pattern.size() - 1; q++) {
			while (k != 0 && pattern[q + 1] != pattern[k])
				k = next[k - 1];
			if (pattern[k] == pattern[q + 1])
				k++;
			next[q + 1] = k;
		}
		return next;
	}
public:
	int contain(string s,string p) {
		vector<int> next = getnext(p);
		int i = 0, j = 0;
		while (i < s.size()) {
			while (j > 0 && s[i] != p[j])
				j = next[j - 1];
			if (s[i] == p[j])
				j++;
			i++;
			if (j == p.size())
				return i - j;
		}
		return -1;
	}
};

int main() {
	string s = "BBC ABCDAB ABCDABCDABDE";
	string p = "ABCDABD";
	KMP k;
	cout << k.contain(s, p) << endl;
	system("pause");
}
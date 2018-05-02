#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class RadixSort {
private:
	int d;
	vector<pair<int, int>> nums;
	void countingsort() {
		int k = 9;
		vector<pair<int,int>> res(nums.size());
		vector<int> temp(k + 1, 0);
		for (int i = 0; i < nums.size(); i++)
			temp[nums[i].second]++;
		for (int i = 1; i < temp.size(); i++)
			temp[i] += temp[i - 1];
		for (int j = nums.size() - 1; j >= 0; j--) {
			res[temp[nums[j].second] - 1] = nums[j];
			temp[nums[j].second]--;
		}
		nums = res;
	}
public:
	RadixSort(vector<int> nums,int d = 0) {
		this->d = d;
		for (int i = 0; i < nums.size(); i++)
			this->nums.push_back(pair<int, int>(nums[i], 0));
	}

	vector<int> radixsort() {
		int count = 1;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < nums.size(); j++) 
				nums[j].second = (nums[j].first / count) % 10;
			count *= 10;
			countingsort();
		}
		vector<int> res(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++)
			res[i] = nums[i].first;
		return res;
	}
};

int main() {
	srand((unsigned)time(NULL));
	vector<int> nums;
	int n = 5;
	while (n--)
	{
		int max = 0;
		for (int i = 0; i < 10 + n; i++) {
			int temp = rand() % 998 + 1;
			max = max > temp ? max : temp;
			nums.push_back(temp);
		}
		cout << "排序前:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		RadixSort rs(nums,3);
		nums = rs.radixsort();
		cout << "排序后:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		nums.clear();
	}
	system("pause");
}
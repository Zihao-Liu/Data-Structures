#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class CountingSort {
private:
	int k;
	vector<int>nums;
public:
	CountingSort(int k,vector<int> nums) {
		this->k = k;
		this->nums = nums;
	}

	vector<int> countingsort() {
		vector<int> res(nums.size(), 0);
		vector<int> temp(k+1, 0);
		for (int i = 0; i < nums.size(); i++)
			temp[nums[i]]++;
		for (int i = 1; i < temp.size(); i++)
			temp[i] += temp[i - 1];
		for (int j = nums.size() - 1; j >= 0; j--) {
			res[temp[nums[j]]-1] = nums[j];
			temp[nums[j]]--;
		}
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
			int temp = rand() % 10 + 1;
			max = max > temp ? max : temp;
			nums.push_back(temp);
		}
		cout << "排序前:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		CountingSort cs(max,nums);
		nums = cs.countingsort();
		cout << "排序后:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		nums.clear();
	}
	system("pause");
}
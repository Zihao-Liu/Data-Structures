#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class MergeSort {
private:
	void merge(vector<int>& nums, int ls, int le, int re) {
		vector<int> temp(re - ls + 1, 0);
		int pos = 0;
		int i = ls, j = le + 1;
		while (i <= le && j <= re) {
			temp[pos++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
		}
		while (i <= le)
			temp[pos++] = nums[i++];
		while (j <= re)
			temp[pos++] = nums[j++];

		for (i = ls, j = 0; i <= re; i++, j++) {
			nums[i] = temp[j];
		}
	}
public:
	void mergesort(vector<int>& nums, int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mergesort(nums, left, mid);
			mergesort(nums, mid + 1, right);
			merge(nums, left, mid, right);
		}
	}
};

int main() {
	srand((unsigned)time(NULL));
	vector<int> nums;
	MergeSort ms;
	int n = 5;
	while (n--) {
		for (int i = 0; i < 20 + n; i++)
			nums.push_back(rand() % 200 + 1);
		cout << "排序前:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		ms.mergesort(nums, 0, nums.size() - 1);
		cout << "排序后:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		nums.clear();
	}
	system("pause");
}
#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class SelectSort {
private:
	void swap(vector<int>& nums, int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
public:
	void selectsort(vector<int>& nums) {
		for (int i = 0; i < nums.size()-1; i++) {
			int min = i;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] < nums[min])
					min = j;
			}
			swap(nums, min, i);
		}
	}
};

int main() {
	srand((unsigned)time(NULL));
	vector<int> nums;
	SelectSort ss;
	int n = 5;
	while (n--)
	{
		for (int i = 0; i < 20 + n; i++)
			nums.push_back(rand() % 200 + 1);
		cout << "排序前:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		ss.selectsort(nums);
		cout << "排序后:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		nums.clear();
	}
	system("pause");
}
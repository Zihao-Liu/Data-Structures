#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class BubbleSort {
private:
	void swap(vector<int>& nums, int i, int j) {
		int temp = nums[j];
		nums[j] = nums[i];
		nums[i] = temp;
	}
public:
	void bubblesort(vector<int>& nums) {
		int i, j;
		for (i = 0; i < nums.size()-1; i++) {
			for (j = 0; j < nums.size() - i - 1; j++) {
				if (nums[j] > nums[j + 1])
					swap(nums, j, j + 1);
			}
		}
	}
};

int main() {
	srand((unsigned)time(NULL));
	vector<int> nums;
	BubbleSort bs;
	int n = 5;
	while (n--)
	{
		for (int i = 0; i < 20 + n; i++)
			nums.push_back(rand() % 200 + 1);
		cout << "排序前:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		bs.bubblesort(nums);
		cout << "排序后:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		nums.clear();
	}
	system("pause");
}
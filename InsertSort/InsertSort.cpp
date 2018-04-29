#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class InsertSort {
public:
	void insertsort(vector<int>& nums) {
		int i, j;
		for (i = 1; i < nums.size(); i++) {
			int min = nums[i];
			for (j = i; j > 0 && nums[j - 1] > min; j--)
				nums[j] = nums[j - 1];
			nums[j] = min;
		}
	}
};

int main() {
	srand((unsigned)time(NULL));
	vector<int> nums;
	InsertSort is;
	int n = 5;
	while (n--)
	{
		for (int i = 0; i < 20 + n; i++)
			nums.push_back(rand() % 200 + 1);
		cout << "排序前:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		is.insertsort(nums);
		cout << "排序后:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		nums.clear();
	}
	system("pause");
}
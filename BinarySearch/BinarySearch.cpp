#include "iostream"
#include "vector"
#include "time.h"
#include "algorithm"
using namespace std;

class BinarySearch{
public:
	int binarysearch(vector<int> nums, int target) {
		cout << "搜索:" << target << " ";
		int left = 0, right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid - 1;
			else {
				cout << "在第" << mid << "位" << endl;
				return mid;
			}
		}
		cout << "元素不存在" << endl;
		return -1;
	}
};

int main() {
	srand((unsigned)time(NULL));
	vector<int> nums;
	BinarySearch bs;
	int n = 5;
	while (n--)
	{
		for (int i = 0; i < 20 + n; i++)
			nums.push_back(rand() % 100 + 1);
		sort(nums.begin(), nums.end());
		cout << "数组:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		for(int i =0;i<10;i++)
			bs.binarysearch(nums, rand() % 100);
		nums.clear();
	}
	system("pause");
}
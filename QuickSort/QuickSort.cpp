#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class QuickSort
{
  private:
	void swap(vector<int> &nums, int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	int partition(vector<int> &nums, int left, int right)
	{
		int i = left + 1, j = left + 1;
		for (j; j <= right; j++)
		{
			if (nums[j] <= nums[left])
			{
				swap(nums, i, j);
				i++;
			}
		}
		swap(nums, i - 1, left);
		return i - 1;
	}

  public:
	void quicksort(vector<int> &nums, int left, int right)
	{
		if (left < right)
		{
			int index = partition(nums, left, right);
			quicksort(nums, left, index - 1);
			quicksort(nums, index + 1, right);
		}
	}
};
int main()
{
	srand((unsigned)time(NULL));
	vector<int> nums;
	QuickSort qs;
	int n = 5;
	while (n--)
	{
		for (int i = 0; i < 20 + n; i++)
			nums.push_back(rand() % 200 + 1);
		cout << "排序前:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		qs.quicksort(nums, 0, nums.size() - 1);
		cout << "排序后:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		nums.clear();
	}
	system("pause");
}
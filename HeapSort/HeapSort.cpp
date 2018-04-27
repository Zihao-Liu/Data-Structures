#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class HeapSort
{
  private:
	int size;
	void swap(vector<int> &nums, int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	void max_heapify(vector<int> &nums, int i)
	{
		while (i < size)
		{
			int max = nums[i];
			int flag = i;
			int child = 2 * i + 1;
			if (child >= size)
				break;
			if (nums[child] > max)
			{
				max = nums[child];
				flag = child;
			}
			child++;
			if (child < size && nums[child] > max)
			{
				max = nums[child];
				flag = child;
			}
			if (flag == i)
				break;
			else
				swap(nums, flag, i);
			i = flag;
		}
	}
	void build_max(vector<int> &nums)
	{
		size = nums.size();
		int i = size / 2 - 1;
		for (i; i >= 0; i--)
			max_heapify(nums, i);
	}

  public:
	void heapsort(vector<int> &nums)
	{
		build_max(nums);
		for (int i = nums.size() - 1; i >= 1; i--)
		{
			swap(nums, i, 0);
			size--;
			max_heapify(nums, 0);
		}
	}
};

int main()
{
	srand((unsigned)time(NULL));
	vector<int> nums;
	HeapSort hs;
	int n = 5;
	while (n--)
	{
		for (int i = 0; i < 20 + n; i++)
			nums.push_back(rand() % 200 + 1);
		cout << "排序前:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		hs.heapsort(nums);
		cout << "排序后:" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		nums.clear();
	}
	system("pause");
}
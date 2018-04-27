#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class PriorityQueue
{
  private:
	int size;
	vector<int> nums;
	void swap(int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	void max_heapify(int i)
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
				swap(flag, i);
			i = flag;
		}
	}
	void build_max()
	{
		int i = size / 2 - 1;
		for (i; i >= 0; i--)
			max_heapify(i);
	}

  public:
	PriorityQueue(vector<int> nums)
	{
		this->nums = nums;
		size = nums.size();
		build_max();
		print();
	}

	int heap_maximum()
	{
		if (size < 0)
			return -1;
		else
		{
			cout << "最大值为:" << nums[0] << endl;
			print();
			return nums[0];
		}
	}

	int extract_max()
	{
		if (size < 0)
			return -1;
		size--;
		swap(0, size);
		max_heapify(0);
		cout << "去除最大值:" << nums[size] << endl;
		print();
		return nums[size];
	}

	void increase(int i, int newval)
	{
		if (i > size)
		{
			cout << "超出范围" << endl;
			return;
		}
		if (newval < nums[i])
		{
			cout << "新值小于旧值" << endl;
			return;
		}
		cout << "将第" << i << "个元素增加为:" << newval << endl;
		nums[i] = newval;
		int parent;
		for (i; i >= 0; i = parent)
		{
			parent = (i + 1) / 2 - 1;
			if (parent >= 0 && nums[parent] < nums[i])
				swap(i, parent);
			else
				break;
		}
		print();
	}

	void insert(int val)
	{
		nums[size++] = -1;
		increase(size - 1, val);
	}

	void print()
	{
		cout << "当前队列:";
		for (int i = 0; i < size; i++)
			cout << nums[i] << " ";
		cout << endl;
	}
};

int main()
{
	srand((unsigned)time(NULL));
	vector<int> nums;
	for (int i = 0; i < 20; i++)
		nums.push_back(rand() % 200 + 1);
	cout << "插入值:";
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	PriorityQueue pq(nums);
	pq.heap_maximum();
	pq.extract_max();
	pq.extract_max();
	pq.heap_maximum();
	pq.increase(rand() % 10, rand() % 500);
	pq.increase(rand() % 10, rand() % 500);
	pq.increase(rand() % 10, rand() % 500);
	pq.extract_max();
	pq.extract_max();
	pq.heap_maximum();
	system("pause");
}
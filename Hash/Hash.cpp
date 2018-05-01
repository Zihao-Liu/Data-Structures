#include "iostream"
#include "vector"
#include "time.h"
using namespace std;

class LinearProbing {
private:
	vector<pair<int, int>> hash;
	int size;
	int capacity;

	int position(int val) {
		int index = val % capacity;
		return index;
	}
public:
	LinearProbing(int n = 13) {
		capacity = n;
		size = 0;
		vector<pair<int, int>> temp(n, pair<int, int>(0, -1));
		hash = temp;
	}

	int search(int val) {
		int i = position(val);
		int j = i;
		do {
			if (hash[i].first == val && hash[i].second != -1) {
				return i;
			}
			if (i == capacity - 1)
				i = 0;
			else
				i++;
		} while (j != i);
		return -1;
	}

	void insert(int val) {
		if (size == capacity) {
			cout << "hash已满 ";
			return;
		}
		if (search(val) != -1) {
			cout << val << "(该值已存在) ";
			return;
		}
		cout << val << " ";
		int i = position(val);
		while (hash[i].second != -1) {
			if (i == capacity - 1)
				i = 0;
			else
				i++;
		}
		hash[i].first = val;
		hash[i].second = 1;
		size++;
	}

	void remove(int val) {
		if (size == 0) {
			cout << "hash已空 ";
			return;
		}
		int i = search(val);
		if (i == -1) {
			cout << val << "(该值不存在) ";
			return;
		}
		cout << val << " ";
		hash[i].second = -1;
	}

	void clear() {
		for (int i = 0; i < capacity; i++)
			hash[i].second = -1;
		size = 0;
	}

	void print() {
		cout << "\n当前哈希表:" << endl;
		for (int i = 0; i < capacity; i++) {
			if (hash[i].second != -1)
				cout << i << "    " << hash[i].first << endl;
		}

	}
};

class QuadraticProbing {
	vector<pair<int, int>> hash;
	int size;
	int capacity;

	int position(int val) {
		int index = val % capacity;
		return index;
	}
public:
	QuadraticProbing(int n = 13) {
		capacity = n;
		size = 0;
		vector<pair<int, int>> temp(n, pair<int, int>(0, -1));
		hash = temp;
	}

	int search(int val) {
		int i = position(val);
		int count = 1;
		int pos = i;
		while (1) {
			count++;
			pos = (i + count * count) % capacity;
			if (pos < 0)
				return -1;
			else if (hash[pos].second != -1 && hash[pos].first == val)
				return pos;
		}
	}

	void insert(int val) {
		if (size == capacity) {
			cout << "hash已满 ";
			return;
		}
		if (search(val) != -1) {
			cout << val << "(该值已存在) ";
			return;
		}
		cout << val << " ";
		int i = position(val);
		int count = 1;
		int pos = i;
		while (hash[pos].second != -1) {
			count++;
			pos = (i + count * count) % capacity;
			if (pos < 0)
				return;
		}
		hash[pos].first = val;
		hash[pos].second = 1;
		size++;
	}

	void remove(int val) {
		if (size == 0) {
			cout << "hash已空 ";
			return;
		}
		int i = search(val);
		if (i == -1) {
			cout << val << "(该值不存在) ";
			return;
		}
		cout << val << " ";
		hash[i].second = -1;
		size--;
	}

	void clear() {
		for (int i = 0; i < capacity; i++)
			hash[i].second = -1;
		size = 0;
	}

	void print() {
		cout << "\n当前哈希表:" << endl;
		for (int i = 0; i < capacity; i++) {
			if (hash[i].second != -1)
				cout << i << "    " << hash[i].first << endl;
		}

	}
};

struct Node {
	int val;
	Node *next;
	Node *previous;
	Node(int value) :val(value), previous(NULL), next(NULL) {};
};

struct Head {
	Node *head;
	Head() :head(new Node(0)) {};
};
class Chaining {
private:
	vector<Head> hash;
	int size;
	int capacity;

	int position(int val) {
		int index = val % capacity;
		return index;
	}
public:
	Chaining(int n = 13) {
		capacity = n;
		size = 0;
		vector<Head> temp(n);
		hash = temp;
	}

	Node* search(int val) {
		int i = position(val);
		Node *p = hash[i].head;
		while (p) {
			if (p->val == val)
				return p;
			p = p->next;
		}
		return NULL;
	}

	void insert(int val) {
		if (search(val) != NULL) {
			cout << val << "(该值已存在) ";
			return;
		}
		cout << val << " ";
		int i = position(val);
		Node *head = hash[i].head;
		Node *p = head->next;
		Node *temp = new Node(val);
		head->next = temp;
		temp->previous = head;
		temp->next = p;
		if (p)
			p->previous = temp;
		size++;
	}

	void remove(int val) {
		if (size == 0) {
			cout << "hash已空 ";
			return;
		}
		Node *temp = search(val);
		if (temp == NULL) {
			cout << val << "(该值不存在) ";
			return;
		}
		Node *p = temp->previous;
		if (temp->next)
			p->next = temp->next->next;
		else
			p->next = NULL;
		if (p->next)
			p->next->previous = p;
		delete(temp);
		size--;
	}

	void clear() {
		for (int i = 0; i < capacity; i++) {
			Node *p = hash[i].head->next;
			hash[i].head->next = NULL;
			while (p) {
				Node *temp = p->next;
				delete(p);
				p = temp;
			}
		}
		size = 0;
	}

	void print() {
		cout << "\n当前哈希表:" << endl;
		for (int i = 0; i < capacity; i++) {
			Node *p = hash[i].head->next;
			while (p) {
				cout << i << "   " << p->val << endl;
				p = p->next;
			}
		}
	}
};



int main() {
	srand((unsigned)time(NULL));
	LinearProbing lp;
	int n = 5;
	cout << "-----------线性探测----------" << endl;
	while (n--) {
		cout << "插入";
		for (int i = 0; i < 15; i++)
			lp.insert(rand() % 50 + 1);
		lp.print();
		for (int i = 0; i < 5; i++) {
			int val = rand() % 50 + 1;
			cout << "搜索:" << val;
			cout << "key为:" << lp.search(val) << endl;
		}
		cout << "\n删除:";
		for (int i = 0; i < 20; i++)
			lp.remove(rand() % 50 + 1);
		//lp.clear();
		lp.print();
		cout << "------------------------------" << endl;
	}
	cout << "-----------二次探测----------" << endl;
	n = 5;
	QuadraticProbing qp;
	while (n--) {
		cout << "插入";
		for (int i = 0; i < 15; i++)
			qp.insert(rand() % 50 + 1);
		qp.print();
		for (int i = 0; i < 5; i++) {
			int val = rand() % 50 + 1;
			cout << "搜索:" << val;
			cout << "key为:" << qp.search(val) << endl;
		}
		cout << "\n删除:";
		for (int i = 0; i < 20; i++)
			qp.remove(rand() % 50 + 1);
		//lp.clear();
		qp.print();
		cout << "------------------------------" << endl;
	}

	cout << "-----------分离链接----------" << endl;
	n = 5;
	Chaining ch;
	while (n--) {
		cout << "插入";
		for (int i = 0; i < 15; i++)
			ch.insert(rand() % 50 + 1);
		ch.print();
		for (int i = 0; i < 5; i++) {
			int val = rand() % 50 + 1;
			cout << "搜索:" << val;
			Node *temp = ch.search(val);
			if (temp)
				cout << "key为:" << temp->val << endl;
			else
				cout << "key为:" << "-1" << endl;
		}
		cout << "\n删除:";
		for (int i = 0; i < 20; i++)
			ch.remove(rand() % 50 + 1);
		//lp.clear();
		ch.print();
		cout << "------------------------------" << endl;
	}
	system("pause");
}
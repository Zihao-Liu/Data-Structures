#include "iostream"
using namespace std;

class ArrayQueue {
private:
	int rear;
	int fro;
	int *queue;
	int capacity;
	int t_back;
public:
	ArrayQueue(int capacity = 10) {
		fro = 0;
		rear = 0;
		this->capacity = capacity;
		queue = new int[capacity];
	}

	void push(int value) {
		cout << "入队:" << value << endl;
		if (fro == ((rear + 1) % capacity))
			cout << "队满" << endl;
		else {
			queue[rear] = value;
			rear = (rear + 1) % capacity;
			t_back = value;
		}
		print();
	}

	int pop() {
		cout << "出队:";
		if (rear!=fro) {
			cout << queue[fro] << endl;
			int temp = queue[fro];
			fro = (fro + 1) % capacity;
			print();
			return temp;
		}
		cout << "队空" << endl;
		print();
		return 0;
	}

	bool empty() {
		cout << "队空?" << (fro == rear) << endl;
		return fro == rear;
	}

	int size() {
		cout << "队大小:" << (rear - fro + capacity) % capacity << endl;
		return (rear - fro + capacity) % capacity;
	}

	int front() {
		cout << "队首:";
		if (rear != fro) {
			cout << queue[fro] << endl;
			print();
			return queue[fro];
		}
		cout << "队空" << endl;
		print();
		return 0;
	}

	int back() {
		cout << "队尾:";
		if (rear != fro) {
			cout << t_back << endl;
			print();
			return t_back;
		}
		cout << "队空" << endl;
		print();
		return 0;
	}

	void print() {
		cout << "当前队:";
		for (int i = fro; i != rear; i = (i+1)%capacity) {
			cout << queue[i] << ' ';
		}
		cout << endl;
	}
};

struct List {
	int value;
	List *next;
	List(int x) :value(x), next(NULL) {}
};
class LinkedQueue {
private:
	List *fro;
	List *rear;
	int csize;
public:
	LinkedQueue() {
		fro = new List(0);
		fro->next = NULL;
		rear = fro;
		csize = 0;
	}

	void push(int value) {
		cout << "入队:" << value << endl;
		List *temp = new List(value);
		temp->next = NULL;
		rear->next = temp;
		rear = temp;
		csize++;
		print();
	}

	int pop() {
		cout << "出队:";
		if (fro->next!=NULL) {
			List *temp = fro->next;
			fro->next = temp->next;
			csize--;
			cout << temp->value << endl;
			int v = temp->value;
			delete(temp);
			print();
			return v;
		}
		rear = fro;
		cout << "队空" << endl;
		print();
		return 0;
	}

	bool empty() {
		cout << "队空?" << (csize == 0) << endl;
		return csize == 0;
	}

	int size() {
		cout << "队大小:" << csize << endl;
		return csize;
	}

	int front() {
		cout << "队首:";
		if (fro->next != NULL) {
			cout << fro->next->value << endl;
			print();
			return fro->next->value;
		}
		cout << "队空" << endl;
		print();
		return 0;
	}

	int back() {
		cout << "队尾:";
		if (csize != 0) {
			cout << rear->value << endl;
			print();
			return rear->value;
		}
		cout << "队空" << endl;
		print();
		return 0;
	}
	void print() {
		cout << "当前队:";
		for (List *p = fro->next; p != NULL; p = p->next)
			cout << p->value << " ";
		cout << endl;
	}
};

void test1() {
	ArrayQueue q(5);
	cout << "-----数组实现-----" << endl;
	q.pop();q.empty();q.push(1);q.push(2);
	q.back();q.front();q.push(3);q.push(4);
	q.back();q.front();q.size();q.empty();
	q.pop();q.push(5);q.push(6);q.back();
	q.front();q.push(7);q.back();q.front();
	q.pop();q.pop();q.pop();q.back();q.front();
	q.pop(); q.pop(); q.pop(); q.back(); q.pop();
	q.push(8); q.front(); q.back();
}

void test2() {
	LinkedQueue q;
	cout << "-----链表实现-----" << endl;
	q.pop();q.empty();q.push(1);q.push(2);
	q.back();q.front();q.push(3);q.push(4);
	q.back();q.front();q.size();q.empty();
	q.pop();q.push(5);q.push(6);q.back();
	q.front();q.push(7);q.back();q.front();
	q.pop();q.pop();q.pop();q.back();q.front();
	q.pop(); q.pop(); q.pop(); q.back(); q.pop(); 
	q.push(8); q.front(); q.back();
}

int main() {
	test1();
	test2();
	system("pause");
}
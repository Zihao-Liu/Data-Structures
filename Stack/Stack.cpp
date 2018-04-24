#include "iostream"
#include "vector"
using namespace std;

class ArrayStack {
private:
	int ctop;
	vector<int> stack;
public:
	ArrayStack() {
		ctop = 0;
	}

	void push(int value) {
		cout << "入栈:" << value << endl;
		if (stack.size() <= ctop)
			stack.push_back(value);
		else
			stack[ctop] = value;
		ctop++;
		print();
	}

	int pop() {
		cout << "出栈:";
		if (ctop != 0) {
			cout << stack[ctop-1] << endl;
			return stack[--ctop];
		}
		cout << "空栈" << endl;
		return 0;
	}

	bool empty() {
		return ctop == 0;
	}

	int size() {
		return ctop;
	}

	int top() {
		cout << "栈顶:";
		if (ctop != 0) {
			cout << stack[ctop - 1] << endl;
			return stack[ctop - 1];
		}
		cout << "空栈" << endl;
		return 0;
	}

	void print() {
		cout << "当前栈:";
		for (int i = ctop-1; i >=0; i--) {
			cout << stack[i] << ' ';
		}
		cout << endl;
	}
};

struct List {
	int value;
	List *next;
	List(int x) :value(x), next(NULL) {}
};
class LinkedStack {
private:
	List *base;
	int csize;
public:
	LinkedStack() {
		base = new List(0);
		base->next = NULL;
		csize = 0;
	}

	void push(int value) {
		cout << "入栈:" << value << endl;
		List *temp = new List(value);
		temp->next = base->next;
		base->next = temp;
		csize++;
		print();
	}

	int pop() {
		cout << "出栈:";
		if (base->next) {
			List *temp = base->next;
			base->next = temp->next;
			csize--;
			cout << temp->value << endl;
			int v = temp->value;
			delete(temp);
			return v;
		}
		cout << "空栈" << endl;
		return 0;
	}

	bool empty() {
		return base->next==NULL;
	}

	int size() {
		return csize;
	}

	int top() {
		cout << "栈顶:";
		if (base->next) {
			cout << base->next->value << endl;
			return base->next->value;
		}
		cout << "空栈" << endl;
		return 0;
	}

	void print() {
		cout << "当前栈:";
		for (List *p = base->next; p != NULL; p = p->next)
			cout << p->value << " ";
		cout << endl;
	}
};

void test1() {
	ArrayStack s;
	cout << "-----数组实现-----" << endl;
	s.pop();
	s.print();
	s.top();
	s.push(1);
	s.push(2);
	s.top();
	s.pop();
	s.print();
	s.top();
	s.push(3);
	cout << "空栈?" << s.empty() << endl;
	s.pop();
	s.print();
	s.pop();
	s.print();
	s.pop();
	s.top();
	s.print();
	cout << "空栈?" << s.empty() << endl;
}

void test2() {
	LinkedStack s;
	cout << "-----链表实现-----" << endl;
	s.pop();
	s.print();
	s.top();
	s.push(1);
	s.push(2);
	s.top();
	s.pop();
	s.print();
	s.top();
	s.push(3);
	cout << "空栈?" << s.empty() << endl;
	s.pop();
	s.print();
	s.pop();
	s.print();
	s.pop();
	s.top();
	s.print();
	cout << "空栈?" << s.empty() << endl;
}

int main() {
	test1();
	test2();
	system("pause");
}
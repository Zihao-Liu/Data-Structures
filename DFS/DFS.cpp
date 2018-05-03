#include "iostream"
#include "vector"
#include "time.h"
#include "set"
#include "stack"
using namespace std;

class Matrix {
private:
	vector<vector<int>> M;
	int v;
public:
	Matrix(int n = 6) {
		v = n;
		vector<int> a(v, 0);
		vector<vector<int>> b(v, a);
		M = b;
	}
	void init(int src, int des) {
		if (M[src][des] == 0)
			cout << "起点:" << src << " 终点:" << des << endl;
		M[src][des] = 1;
	}

	void dfs(int src) {
		cout << "邻接矩阵遍历起点为:" << src << endl;
		set<int> visited;
		stack<int> tovisit;
		tovisit.push(src);
		set<int>::iterator it;
		while (!tovisit.empty()) {
			int s = tovisit.top();
			it = visited.find(s);
			if (it == visited.end())
				cout << s << " ";
			visited.insert(s);
			bool flag = false;
			for (int i = 0; i < v; i++) {
				if (i != s && M[s][i] == 1) {
					it = visited.find(i);
					if (it == visited.end()) {
						tovisit.push(i);
						flag = true;
						break;
					}
				}
			}
			if (!flag)
				tovisit.pop();
		}
		cout << endl;
	}

	void print() {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++)
				cout << M[i][j] << " ";
			cout << endl;
		}
	}
};

struct Node {
	int val;
	Node *next;
	Node(int value) :val(value), next(NULL) {};
};

class List {
private:
	vector<Node *> M;
	int v;
public:
	List(int n = 6) {
		v = n;
		for (int i = 0; i < v; i++)
			M.push_back(new Node(i));
	}

	void init(int src, int des) {
		if (src == des)
			return;

		Node *p = M[src];
		while (p->next) {
			if (p->next->val == des)
				return;
			p = p->next;
		}
		cout << "起点:" << src << " 终点:" << des << endl;
		p->next = (new Node(des));
	}

	void dfs(int src) {
		cout << "邻接表遍历起点为:" << src << endl;
		set<int> visited;
		stack<int> tovisit;
		tovisit.push(src);
		set<int>::iterator it;
		while (!tovisit.empty()) {
			int s = tovisit.top();
			it = visited.find(s);
			if(it==visited.end())
				cout << s << " ";
			visited.insert(s);

			Node *p = M[s]->next;
			int flag = false;
			while (p) {
				it = visited.find(p->val);
				if (it == visited.end()) {
					tovisit.push(p->val);
					flag = true;
					break;
				}
				p = p->next;
			}
			if(!flag)
				tovisit.pop();
		}
		cout << endl;
	}

	void print() {
		for (int i = 0; i < v; i++) {
			Node *p = M[i]->next;
			while (p) {
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
};

int main() {
	srand((unsigned)time(NULL));
	int n = 5;
	while (n--) {
		int v = rand() % 6 + 1;
		Matrix M(v);
		List L(v);
		for (int i = 0; i < 15; i++) {
			int src = rand() % v;
			int des = rand() % v;
			M.init(src, des);
			L.init(src, des);
		}
		cout << "图大小为：" << v << endl;
		cout << "----------邻接矩阵------------" << endl;
		M.print();
		cout << "----------邻接表------------" << endl;
		L.print();
		int src = rand() % v;
		M.dfs(src);
		L.dfs(src);
		src = rand() % v;
		M.dfs(src);
		L.dfs(src);
		cout << "----------------------------" << endl;
	}
	system("pause");
}
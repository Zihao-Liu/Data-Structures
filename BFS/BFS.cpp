#include "iostream"
#include "vector"
#include "time.h"
#include "set"
#include "queue"
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
		if(M[src][des]==0)
			cout << "起点:" << src << " 终点:" << des << endl;
		M[src][des] = 1;
	}

	void bfs(int src) {
		cout << "邻接矩阵遍历起点为:" << src << endl;
		set<int> visited;
		queue<int> tovisit;
		tovisit.push(src);
		while (!tovisit.empty()) {
			int s = tovisit.front();
			visited.insert(s);
			for (int i = 0; i < v; i++) {
				if (i != s && M[s][i] == 1) {
					set<int>::iterator it = visited.find(i);
					if (it == visited.end()) 
						tovisit.push(i);
					visited.insert(i);
				}
			}
			cout << s << " ";
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
	List(int n=6) {
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

	void bfs(int src) {
		cout << "邻接表遍历起点为:" << src << endl;
		set<int> visited;
		queue<int> tovisit;
		tovisit.push(src);
		while (!tovisit.empty()) {
			int s = tovisit.front();
			visited.insert(s);
			for (int i = 0; i < v; i++) {
				Node *p = M[s]->next;
				while (p) {
					set<int>::iterator it = visited.find(p->val);
					if (it == visited.end())
						tovisit.push(p->val);
					visited.insert(p->val);
					p = p->next;
				}
			}
			cout << s << " ";
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
		cout << "图大小为："<<v<< endl;
		cout << "----------邻接矩阵------------" << endl;
		M.print();
		cout << "----------邻接表------------" << endl;
		L.print();
		int src = rand() % v;
		M.bfs(src);
		L.bfs(src);
		src = rand() % v;
		M.bfs(src);
		L.bfs(src);
		cout << "----------------------------" << endl;
	}
	system("pause");
}
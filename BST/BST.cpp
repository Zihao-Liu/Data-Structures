#include "iostream"
#include "time.h"
#include "stack"
#include "queue"
using namespace std;

struct TreeNode {
	int value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val) :value(val), left(NULL), right(NULL) {};
};

struct PostFlag {
	int status;
	TreeNode *T;
	PostFlag(TreeNode *t) :status(0), T(t) {};
};

class BST {
public:
	TreeNode * search(TreeNode *head, int val) {
		while (head != NULL) {
			if (val < head->value)
				head = head->left;
			else if (val > head->value)
				head = head->right;
			else
				return head;
		}
		return NULL;
	}

	TreeNode* findMin(TreeNode *head) {
		while (head) {
			if (head->left)
				head = head->left;
			else
				return head;
		}
		cout << "无" << endl;
		return NULL;
	}

	TreeNode* findMax(TreeNode *head) {
		while (head) {
			if (head->right)
				head = head->right;
			else
				return head;
		}
		cout << "无" << endl;
		return NULL;
	}

	TreeNode* insert(TreeNode *head, int val) {
		if (search(head, val)) {
			return head;
		}
		cout << "插入:" << val << endl;
		return insert2(head, val);
	}

	TreeNode* insert2(TreeNode *head, int val) {
		if (head == NULL)
			return new TreeNode(val);
		if (val < head->value)
			head->left = insert2(head->left, val);
		else if (val > head->value)
			head->right = insert2(head->right, val);
		return head;
	}

	TreeNode* remove(TreeNode *head, int val) {

		if (search(head, val) == NULL) {
			return head;
		}
		cout << "删除:" << val << endl;
		return remove2(head, val);
	}

	TreeNode *remove2(TreeNode *head, int val) {
		if (val > head->value)
			head->right = remove2(head->right, val);
		else if (val < head->value)
			head->left = remove2(head->left, val);
		else {
			TreeNode *temp;
			if (head->left&&head->right) {
				temp = findMin(head->right);
				head->value = temp->value;
				head->right = remove2(head->right, temp->value);
			}
			else {
				temp = head;
				if (head->left)
					head = head->left;
				else if (head->right)
					head = temp->right;
				else
					head = NULL;
				delete(temp);
			}
		}
		return head;
	}

	void pre_rec(TreeNode *head) {
		if (head) {
			cout << head->value << " ";
			pre_rec(head->left);
			pre_rec(head->right);
		}
	}

	void in_rec(TreeNode *head) {
		if (head) {
			in_rec(head->left);
			cout << head->value << " ";
			in_rec(head->right);
		}
	}

	void post_rec(TreeNode *head) {
		if (head) {
			post_rec(head->left);
			post_rec(head->right);
			cout << head->value << " ";
		}
	}

	void pre_ite(TreeNode *head) {
		stack<TreeNode *> s;
		while (head) {
			if (head->left&&head->right) {
				if (s.empty() || head != s.top()) {
					cout << head->value << " ";
					s.push(head);
					head = head->left;
				}
				else {
					s.pop();
					head = head->right;
				}
			}
			else if (head->left) {
				cout << head->value << " ";
				head = head->left;
			}
			else if (head->right) {
				cout << head->value << " ";
				if (!s.empty() && head == s.top())
					s.pop();
				head = head->right;
			}
			else {
				cout << head->value << " ";
				if (!s.empty())
					head = s.top();
				else
					head = NULL;
			}
		}
	}

	void in_ite(TreeNode *head) {
		stack<TreeNode *> s;
		while (head) {
			if (head->left && (s.empty() || head != s.top())) {
				s.push(head);
				head = head->left;
			}
			else {
				cout << head->value << " ";
				if (!s.empty() && head == s.top())
					s.pop();
				if (head->right)
					head = head->right;
				else if (!s.empty())
					head = s.top();
				else
					break;
			}
		}
	}

	void post_ite(TreeNode *head) {
		stack<PostFlag *> s;
		while (head) {
			if (head->left && head->right) {
				if (s.empty() || head != s.top()->T) {
					s.push(new PostFlag(head));
					head = head->left;
				}
				else if (s.top()->status == 0) {
					s.top()->status = 1;
					head = head->right;
				}
				else {
					cout << head->value << " ";
					s.pop();
					head = s.empty() ? NULL : s.top()->T;
				}
			}
			else if (head->left) {
				if (s.empty() || head != s.top()->T) {
					s.push(new PostFlag(head));
					head = head->left;
				}
				else {
					cout << head->value << " ";
					s.pop();
					head = s.empty() ? NULL : s.top()->T;
				}
			}
			else if (head->right) {
				if (s.empty() || head != s.top()->T) {
					s.push(new PostFlag(head));
					head = head->right;
				}
				else {
					cout << head->value << " ";
					s.pop();
					head = s.empty() ? NULL : s.top()->T;
				}
			}
			else {
				cout << head->value << " ";
				head = s.empty() ? NULL : s.top()->T;
			}
		}
	}

	void level(TreeNode *head) {
		queue<TreeNode *> q;
		if (head == NULL)
			return;
		q.push(head);
		while (!q.empty()) {
			head = q.front();
			cout << head->value << " ";
			if (head->left)
				q.push(head->left);
			if (head->right)
				q.push(head->right);
			q.pop();
		}
	}
};


int main() {
	TreeNode *head = NULL;
	BST B;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++)
		head = B.insert(head, rand() % 20 + 1);

	cout << "最小值为:" << B.findMin(head)->value << endl;
	cout << "最大值为:" << B.findMax(head)->value << endl;
	cout << "先序遍历(递归)"; B.pre_rec(head); cout << endl;
	cout << "先序遍历(迭代)"; B.pre_ite(head); cout << endl;
	cout << "中序遍历(递归)"; B.in_rec(head); cout << endl;
	cout << "中序遍历(迭代)"; B.in_ite(head); cout << endl;
	cout << "后序遍历(递归)"; B.post_rec(head); cout << endl;
	cout << "后序遍历(迭代)"; B.post_ite(head); cout << endl;
	cout << "层次遍历"; B.level(head); cout << endl;


	for (int i = 0; i < 10; i++)
		head = B.remove(head, rand() % 20 + 1);
	cout << "最小值为:" << B.findMin(head)->value << endl;
	cout << "最大值为:" << B.findMax(head)->value << endl;
	cout << "先序遍历(递归)"; B.pre_rec(head); cout << endl;
	cout << "先序遍历(迭代)"; B.pre_ite(head); cout << endl;
	cout << "中序遍历(递归)"; B.in_rec(head); cout << endl;
	cout << "中序遍历(迭代)"; B.in_ite(head); cout << endl;
	cout << "后序遍历(递归)"; B.post_rec(head); cout << endl;
	cout << "后序遍历(迭代)"; B.post_ite(head); cout << endl;
	cout << "层次遍历"; B.level(head); cout << endl;

	for (int i = 0; i < 10; i++)
		head = B.insert(head, rand() % 20 + 1);
	cout << "最小值为:" << B.findMin(head)->value << endl;
	cout << "最大值为:" << B.findMax(head)->value << endl;
	cout << "先序遍历(递归)"; B.pre_rec(head); cout << endl;
	cout << "先序遍历(迭代)"; B.pre_ite(head); cout << endl;
	cout << "中序遍历(递归)"; B.in_rec(head); cout << endl;
	cout << "中序遍历(迭代)"; B.in_ite(head); cout << endl;
	cout << "后序遍历(递归)"; B.post_rec(head); cout << endl;
	cout << "后序遍历(迭代)"; B.post_ite(head); cout << endl;
	cout << "层次遍历"; B.level(head); cout << endl;

	for (int i = 0; i < 5; i++)
		head = B.remove(head, rand() % 20 + 1);
	cout << "最小值为:" << B.findMin(head)->value << endl;
	cout << "最大值为:" << B.findMax(head)->value << endl;
	cout << "先序遍历(递归)"; B.pre_rec(head); cout << endl;
	cout << "先序遍历(迭代)"; B.pre_ite(head); cout << endl;
	cout << "中序遍历(递归)"; B.in_rec(head); cout << endl;
	cout << "中序遍历(迭代)"; B.in_ite(head); cout << endl;
	cout << "后序遍历(递归)"; B.post_rec(head); cout << endl;
	cout << "后序遍历(迭代)"; B.post_ite(head); cout << endl;
	cout << "层次遍历"; B.level(head); cout << endl;
	system("pause");
}
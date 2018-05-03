# 数据结构
* [x] 栈
   - [x] 数组实现
      * [x] void push(int value)：入栈
      * [x] int pop()：返回栈顶元素并出栈
      * [x] int top()：返回栈顶元素
      * [x] int size()：返回当前栈内元素数量
      * [x] bool empty()：判断当前栈是否为空
      * [x] void print()：打印当前栈
   - [x] 链表实现
      * [x] void push(int value)：入栈
      * [x] int pop()：返回栈顶元素并出栈
      * [x] int top()：返回栈顶元素
      * [x] int size()：返回当前栈内元素数量
      * [x] bool empty()：判断当前栈是否为空    
      * [x] void print()：打印当前栈
* [x] 队列 
   - [x] 数组实现
      * [x] void push(int value)：入队
      * [x] int pop()：返回队首元素并出队
      * [x] int front()：返回队首元素
      * [x] int back()：返回队尾元素
      * [x] int size()：返回当前队内元素数量
      * [x] bool empty()：判断当前栈是否为空
      * [x] void print()：打印当前队列
   - [x] 链表实现
      * [x] void push(int value)：入队
      * [x] int pop()：返回队首元素并出队
      * [x] int front()：返回队首元素
      * [x] int back()：返回队尾元素
      * [x] int size()：返回当前队内元素数量
      * [x] bool empty()：判断当前栈是否为空
      * [x] void print()：打印当前队列
* [x] 二叉搜索树
   - [x] TreeNode * search(TreeNode *head, int val)：返回节点值为给定值的节点，不存在返回NULL
   - [x] TreeNode* findMin(TreeNode *head)：返回树中最小值的节点，若树为空返回NULL
   - [x] TreeNode* findMax(TreeNode *head)：返回树中最小值的节点，若树为空返回NULL
   - [x] TreeNode* insert(TreeNode *head, int val)：判断树中是否已有该值，若没有则调用insert
   - [x] TreeNode* insert2(TreeNode *head, int val)：插入给定值到树中
   - [x] TreeNode* remove(TreeNode *head, int val)：判断树中是否已有该值，若有则调用remove
   - [x] TreeNode *remove2(TreeNode *head, int val)：删除树中值为给定值的节点
   - [x] void pre_rec(TreeNode *head)：递归前序遍历
   - [x] void in_rec(TreeNode *head)：递归中序遍历
   - [x] void post_rec(TreeNode *head)：递归后序遍历
   - [x] void pre_ite(TreeNode *head)：迭代前序遍历
   - [x] void in_ite(TreeNode *head)：迭代中序遍历
   - [x] void post_ite(TreeNode *head)：迭代后序遍历
   - [x] void level(TreeNode *head)：层次遍历
* [x] 优先队列
   - [x] int heap_maximum()：返回当前队列最大值
   - [x] int extract_max()：返回队列最大值，并在队列中删除
   - [x] void increase(int i, int newval)：将第i个元素(从0开始)改为新值newval，若新值小于该元素旧值，不做改动
   - [x] void insert(int val)：插入新值
   - [x] void print()：打印当前队列
* [x] 排序
   - [x] 堆排序
   - [x] 快速排序
   - [x] 归并排序
   - [x] 插入排序
   - [x] 选择排序
   - [x] 冒泡排序
   - [x] 计数排序
   - [x] 基数排序
* [x] 查找
   - [x] 二分查找
   - [x] 哈希
      * [x] 线性探测
      * [x] 二次探测
      * [x] 分离链接
* [x] KMP
* [x] 图
   - [x] 邻接矩阵
      * [x] BFS
      * [x] DFS
   - [x] 邻接表
      * [x] BFS
      * [x] DFS
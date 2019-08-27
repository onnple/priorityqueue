# 优先队列（PriorityQueue)
最小二叉堆(binary heap)实现优先队列，原文地址：   


## 最小堆优先队列操作函数说明：

### 1、初始化最小堆优先队列
extern PriorityQueue *pqueue_init(int length);

### 2、检查最小堆优先队列是否为空
extern int pqueue_is_empty(PriorityQueue *queue);

### 3、检查最小堆优先队列是否已满
extern int pqueue_is_full(PriorityQueue *queue);

### 4、最小堆优先队列入队
extern int pqueue_push(PriorityQueue *queue, int key, Song *song);

### 5、获取队列顶部元素
extern QNode *pqueue_top(PriorityQueue *queue); // 获取顶部元素

### 6、顶部元素出队
extern int pqueue_pop(PriorityQueue *queue); // 释放顶部元素

### 7、index位置的元素降低delta
extern int pqueue_decrease(PriorityQueue *queue, int index, int delta);

### 8、index位置的元素提升delta
extern int pqueue_increase(PriorityQueue *queue, int index, int delta);

### 9、删除index位置的元素
extern int pqueue_delete(PriorityQueue *queue, int index);

### 10、使用一个数组构建一个优先队列
extern PriorityQueue *pqueue_build(QNode *list, int length);

### 11、遍历优先队列
extern void pqueue_traverse(PriorityQueue *queue);

### 12、释放优先队列
extern int pqueue_clear(PriorityQueue *queue);


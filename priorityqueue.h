//
// Created by Once on 2019/8/22.
//

#ifndef DATALGORITHM_PRIORITYQUEUE_H
#define DATALGORITHM_PRIORITYQUEUE_H

// 使用最小二叉堆使用优先队列

// 基本数据记录
typedef struct Song{
    char name[128];
    char singer[128];
} Song;

// 结点
typedef struct qnode{
    int key; // 关键字或优先级值
    Song song;
} QNode;

// 优先队列对外ADT
typedef struct priorityqueue{
    int length; // 数组长度
    int size; // 记录数量
    QNode **list; // 记录数组，使用一个数组表示一个二叉堆/二叉树
} PriorityQueue;

// 最小堆优先队列函数声明
extern PriorityQueue *pqueue_init(int length);
extern int pqueue_is_empty(PriorityQueue *queue);
extern int pqueue_is_full(PriorityQueue *queue);
extern int pqueue_push(PriorityQueue *queue, int key, Song *song);
extern QNode *pqueue_top(PriorityQueue *queue); // 获取顶部元素
extern int pqueue_pop(PriorityQueue *queue); // 释放顶部元素
extern int pqueue_decrease(PriorityQueue *queue, int index, int delta);
extern int pqueue_increase(PriorityQueue *queue, int index, int delta);
extern int pqueue_delete(PriorityQueue *queue, int index);
extern PriorityQueue *pqueue_build(QNode *list, int length);
extern void pqueue_traverse(PriorityQueue *queue);
extern int pqueue_clear(PriorityQueue *queue);

#endif //DATALGORITHM_PRIORITYQUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "priorityqueue.h"


static void priority_queue(void){
    PriorityQueue *queue = pqueue_init(13);
    Song s;
    strcpy(s.name, "shall we talk");
    strcpy(s.singer, "Eason");
    // 入队操作
    pqueue_push(queue, 62, &s);
    pqueue_push(queue, 41, &s);
    pqueue_push(queue, 30, &s);
    pqueue_push(queue, 28, &s);
    pqueue_push(queue, 16, &s);
    pqueue_push(queue, 22, &s);
    pqueue_push(queue, 12, &s);
    pqueue_push(queue, 19, &s);
    pqueue_push(queue, 11, &s);
    pqueue_push(queue, 15, &s);

    // 遍历所有元素
    pqueue_traverse(queue);

    pqueue_delete(queue, 2); // 删除第三个元素（16）

    pqueue_traverse(queue);

    pqueue_decrease(queue, 3, 9); // 将第四个元素降低9（19-9）

    pqueue_traverse(queue);

    pqueue_increase(queue, 1, 26); // 11+26=37

    pqueue_traverse(queue);

    // 根据优先队列是否为空遍历
    while(!pqueue_is_empty(queue)) {
        QNode *node = pqueue_top(queue); // 获取队头的元素
        printf("%d %s\n", node->key, node->song.name);
        pqueue_pop(queue); // 将队头元素出队释放
    }

    pqueue_clear(queue); // 清空和释放优先队列

    // 构建队列
    QNode list[9];
    for (int i = 0; i < 9; ++i) {
        list[i].key = i*i + 3;
        strcpy(list[i].song.name, "a");
        strcpy(list[i].song.singer, "b");
    }
    PriorityQueue *q = pqueue_build(list, 9);
    pqueue_traverse(q);
    pqueue_clear(q);
}

int main(void) {
    priority_queue();
    return 0;
}


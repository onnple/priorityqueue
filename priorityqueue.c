//
// Created by Once on 2019/8/22.
//

#include "priorityqueue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PriorityQueue *pqueue_init(int length){
    if(length < 1){
        perror("length for queue is too small.");
        return NULL;
    }
    PriorityQueue *queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if(!queue){
        perror("alloc mem for queue error.");
        return NULL;
    }
    queue->size = 0;
    queue->length = length;
    queue->list = (QNode**)malloc(length * sizeof(QNode*));
    if(!queue->list){
        perror("alloc mem for list error.");
        free(queue);
        return NULL;
    }
    return queue;
}

int pqueue_is_empty(PriorityQueue *queue){
    if(queue == NULL)
        return 1;
    return queue->size == 0;
}

int pqueue_is_full(PriorityQueue *queue){
    if(queue == NULL)
        return 0;
    return queue->length == queue->size;
}

static int parent(int i){
    return (i - 1) / 2;
}

static int left(int i){
    return 2 * i + 1;
}

static int right(int i){
    return 2 * i + 2;
}

int pqueue_push(PriorityQueue *queue, int key, Song *song){
    if(queue == NULL || song == NULL)
        return 0;
    QNode *node = (QNode*)malloc(sizeof(QNode));
    if(!node){
        perror("alloc mem for node error.");
        return 0;
    }
    node->key = key;
    strcpy(node->song.name, song->name);
    strcpy(node->song.singer, song->singer);
    int i;
    for (i = queue->size;i > 0 && key < queue->list[parent(i)]->key; i = parent(i))
        queue->list[i] = queue->list[parent(i)];
    queue->list[i] = node;
    queue->size++;
    return 1;
}

// 获取顶部元素
QNode *pqueue_top(PriorityQueue *queue){
    if(queue == NULL || queue->size == 0)
        return NULL;
    return queue->list[0];
}

// 释放顶部元素
int pqueue_pop(PriorityQueue *queue){
    if(queue == NULL || queue->size == 0)
        return 0;
    pqueue_delete(queue, 0);
    return 1;
}

int pqueue_increase(PriorityQueue *queue, int index, int delta){
    if(queue == NULL || queue->size == 0 || index < 0 || index >= queue->size || delta <= 0)
        return 0;
    int new_key = queue->list[index]->key + delta;
    QNode *node = queue->list[index];
    node->key = new_key;
    int i = index, child;
    while(left(i) < queue->size){
        child = left(i);
        if(right(i) < queue->size && queue->list[left(i)]->key > queue->list[right(i)]->key)
            child = right(i);
        if(new_key > queue->list[child]->key)
            queue->list[i] = queue->list[child];
        else
            break;
        i = child;
    }
    queue->list[i] = node;
    return 1;
}

int pqueue_decrease(PriorityQueue *queue, int index, int delta){
    if(queue == NULL || queue->size == 0 || index < 0 || index >= queue->size || delta <= 0)
        return 0;
    int new_key = queue->list[index]->key - delta;
    QNode *node = queue->list[index];
    node->key = new_key;
    int i;
    for (i = index; i > 0 && new_key < queue->list[parent(i)]->key; i = parent(i))
        queue->list[i] = queue->list[parent(i)];
    queue->list[i] = node;
    return 1;
}

int pqueue_delete(PriorityQueue *queue, int index){
    if(queue == NULL || queue->size == 0 || index < 0 || index >= queue->size)
        return 0;
    free(queue->list[index]);
    int key = queue->list[queue->size - 1]->key;
    int i = index, child;
    while(left(i) < queue->size){
        child = left(i);
        if(right(i) < queue->size && queue->list[left(i)]->key > queue->list[right(i)]->key)
            child = right(i);
        if(key > queue->list[child]->key)
            queue->list[i] = queue->list[child];
        else
            break;
        i = child;
    }
    queue->list[i] = queue->list[queue->size - 1];
    queue->size--;
    return 1;
}

PriorityQueue *pqueue_build(QNode *list, int length){
    if(list == NULL || length < 1)
        return NULL;
    PriorityQueue *queue = pqueue_init(length);
    if(!queue)
        return NULL;
    for (int i = 0; i < length; ++i) {
        QNode *node = (QNode*)malloc(sizeof(QNode));
        if(!node){
            perror("alloc mem for node error");
            for (int j = 0; j < i; ++j)
                free(queue->list[j]);
            return NULL;
        }
        node->key = list[i].key;
        strcpy(node->song.name, list[i].song.name);
        strcpy(node->song.singer, list[i].song.singer);
        queue->list[i] = node;
    }
    for (int k = length / 2; k >= 0; --k) {
        int key = queue->list[k]->key;
        QNode *node = queue->list[k];
        int i = k, child;
        while(left(i) < queue->size){
            child = left(i);
            if(right(i) < queue->size && queue->list[left(i)]->key > queue->list[right(i)]->key)
                child = right(i);
            if(key > queue->list[child]->key)
                queue->list[i] = queue->list[child];
            else
                break;
            i = child;
        }
        queue->list[i] = node;
    }
    queue->size = length;
    return queue;
}

void pqueue_traverse(PriorityQueue *queue){
    if(queue == NULL)
        return;
    for (int i = 0; i < queue->size; ++i) {
        printf("%d ", queue->list[i]->key);
    }
    printf("\n");
}

int pqueue_clear(PriorityQueue *queue){
    if(queue == NULL)
        return 0;
    for (int i = 0; i < queue->size; ++i) {
        free(queue->list[i]);
    }
    free(queue);
    return 1;
}

//
// Created by WAHAHA on 2023/10/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrCircularQueue.h"

// make and destroy
QueuePtr make_queue(void) {
    QueuePtr new_queue = NULL;
    new_queue = (QueuePtr) malloc(sizeof(Queue));
    if (NULL == new_queue) {
        printf("error in malloc!new_queue malloc failed!\n");
        exit(-1);
    }
    new_queue->front = 0;
    new_queue->rear = 0;
    new_queue->length = 0;
    return new_queue;
}

bool destroy_queue(QueuePtr Q) {
    clear_queue(Q);
    free(Q);
    return true;
}

// check status
bool is_empty_queue(QueuePtr Q) {
    return Q->front == Q->rear ? true : false;
}

int Queue_length(QueuePtr Q) {
    return Q->length;
}

//operations
bool push_queue(QueuePtr Q, QueueElemType e) {
    if (Q->length == QUEUE_SIZE) {
        printf("error in push_queue()!the queue is full!\n");
        return false;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % (QUEUE_SIZE + 1);
    Q->length++;
    return true;
}

bool pop_queue(QueuePtr Q, QueueElemType *e) {
    if (is_empty_queue(Q)) {
        printf("error in pop_queue()!the queue is empty!\n");
        return false;
    }
    if (NULL != e) {
        *e = Q->data[Q->front];
    }
    Q->front = (Q->front + 1) % (QUEUE_SIZE + 1);
    Q->length--;
    return true;
}

QueueElemType front_queue(QueuePtr Q) {
    if (is_empty_queue(Q)) {
        printf("error in front_queue()!the queue is empty!\n");
        exit(-1);
    }
    return Q->data[Q->front];
}

QueueElemType back_queue(QueuePtr Q) {
    if (is_empty_queue(Q)) {
        printf("error in back_queue()!the queue is empty!\n");
        exit(-1);
    }
    // rear指向的是队尾元素的下一个位置
    // 所以要减1,同时由于队列数组的长度为QUEUE_SIZE+1
    // 所以要加QUEUE_SIZE+1再取模
    return Q->data[(Q->rear - 1 + QUEUE_SIZE + 1) % (QUEUE_SIZE + 1)];
}

bool clear_queue(QueuePtr Q){
    Q->front = Q->rear = Q->length = 0;
    return true;
}

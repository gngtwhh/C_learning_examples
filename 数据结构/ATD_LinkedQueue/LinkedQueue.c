//
// Created by admin on 2023/10/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// make and destroy
QueuePtr make_queue(void) {
    QueuePtr new_queue = NULL;
    new_queue = (QueuePtr) malloc(sizeof(Queue));
    if (NULL == new_queue) {
        printf("error in malloc!new_queue malloc failed!\n");
        exit(-1);
    }
    new_queue->front = VOID_PTR;
    new_queue->tail = VOID_PTR;
    new_queue->queue_length = 0;
    return new_queue;
}

bool destroy_queue(QueuePtr Q) {
    clear_queue(Q);
    free(Q);
    return true;
}

// check status
bool is_empty_queue(QueuePtr Q) {
    return Q->queue_length == 0 ? true : false;
}

int Queue_length(QueuePtr Q) {
    return Q->queue_length;
}

//operations
bool push_queue(QueuePtr Q, QueueElementType e) {
    QueueNode *new_node = NULL;
    new_node = (QueueNode *) malloc(sizeof(QueueNode));
    if (NULL == new_node) {
        printf("error in malloc!new_node malloc failed!\n");
        return false;
    }
    new_node->value = e;
    if(is_empty_queue(Q)){
        Q->front = Q -> tail = new_node;
    }else {
        Q->tail->next = new_node;
        Q->tail = new_node;
    }
    Q->queue_length++;
    return true;
}

bool pop_queue(QueuePtr Q, QueueElementType *e) {
    if (is_empty_queue(Q)) {
        printf("error in pop_queue()!the queue is empty!\n");
        return false;
    }
    QueueNode *temp = Q->front;
    if(Q->front == Q->tail){
        Q->front = Q->tail = VOID_PTR;
    }else{
        Q->front = Q->front->next;
    }
    if (NULL != e) {
        *e = temp->value;
    }
    Q->queue_length--;
    free(temp);
    return true;
}

QueueElementType front_queue(QueuePtr Q){
    if (is_empty_queue(Q)) {
        printf("error in front_queue()!the queue is empty!\n");
        exit(-1);
    }
    return Q->front->value;
}
QueueElementType back_queue(QueuePtr Q){
    if (is_empty_queue(Q)) {
        printf("error in back_queue()!the queue is empty!\n");
        exit(-1);
    }
    return Q->tail->value;
}
bool clear_queue(QueuePtr Q){
    while (!is_empty_queue(Q)){
        pop_queue(Q, VOID_PTR);
    }
    return true;
}
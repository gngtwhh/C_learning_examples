//
// Created by WAHAHA on 2023/10/15.
//

#ifndef ADT_ARRCIRCULARQUEUE_ARRCIRCULARQUEUE_H
#define ADT_ARRCIRCULARQUEUE_ARRCIRCULARQUEUE_H

#define QUEUE_SIZE 20
#define VOID_PTR NULL
#define bool int
#define true 1
#define false 0

typedef int QueueElemType;
typedef struct {
    QueueElemType data[QUEUE_SIZE + 1];
    int front;
    int rear;
    int length;
} Queue, *QueuePtr;

// make and destroy
QueuePtr make_queue(void);
bool destroy_queue(QueuePtr Q);

// check status
bool is_empty_queue(QueuePtr Q);
int Queue_length(QueuePtr Q);

//operations
bool push_queue(QueuePtr Q, QueueElemType e);
bool pop_queue(QueuePtr Q, QueueElemType *e);
QueueElemType front_queue(QueuePtr Q);
QueueElemType back_queue(QueuePtr Q);
bool clear_queue(QueuePtr Q);

#endif //ADT_ARRCIRCULARQUEUE_ARRCIRCULARQUEUE_H

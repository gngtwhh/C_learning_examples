//
// Created by admin on 2023/10/11.
//

#ifndef ATD_QUEUE_LINKEDQUEUE_H
#define ATD_QUEUE_LINKEDQUEUE_H

#define bool int
#define true 1
#define false 0

#define VOID_PTR NULL
/*
#define STATUS_OK 1
#define STATUS_ERROR 0
*/

typedef int QueueElementType;

typedef struct QUEUE_NODE {
    QueueElementType value;
    struct QUEUE_NODE *next;
} QueueNode;

typedef struct {
    int queue_length;
    QueueNode *front;
    QueueNode *tail;
}Queue, *QueuePtr;

// make and destroy
QueuePtr make_queue(void);
bool destroy_queue(QueuePtr Q);

// check status
bool is_empty_queue(QueuePtr Q);
int Queue_length(QueuePtr Q);

//operations
bool push_queue(QueuePtr Q, QueueElementType e);
bool pop_queue(QueuePtr Q, QueueElementType *e);
QueueElementType front_queue(QueuePtr Q);
QueueElementType back_queue(QueuePtr Q);
bool clear_queue(QueuePtr Q);


#endif //ATD_QUEUE_LINKEDQUEUE_H

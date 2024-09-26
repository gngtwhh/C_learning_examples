#include <stdio.h>
#include "ArrCircularQueue.h"

int main() {
    int data[4] = {1, 2, 3, 4};
    QueuePtr queue = make_queue();
    for (int i = 0; i < 4; ++i) {
        push_queue(queue, data[i]);
    }
    printf("current len of queue is %d\n", Queue_length(queue));
    printf("current front of queue is %d\n", front_queue(queue));

    for (int i = 0; i < 3; ++i) {
        printf("pop\n");
        pop_queue(queue, VOID_PTR);
        printf("current front of queue is %d\n", front_queue(queue));
    }
    printf("current len of queue is %d\n", Queue_length(queue));
    push_queue(queue, 5);
    QueueElemType e;
    while (!is_empty_queue(queue)) {
        pop_queue(queue, &e);
        printf("%d ", e);
    }
    printf("\n");
    int data2[4] = {6, 7, 8, 9};
    for (int i = 0; i < 4; ++i) {
        push_queue(queue, data2[i]);
    }
    while (!is_empty_queue(queue)) {
        pop_queue(queue, &e);
        printf("%d ", e);
    }
    printf("\ncurrent len of queue is %d\n", Queue_length(queue));

    printf("destroy_queue\n");
    destroy_queue(queue);
    return 0;
}

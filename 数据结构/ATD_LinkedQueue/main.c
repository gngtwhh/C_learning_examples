//
// Created by WAHAHA on 2023/10/11.
//
/*
 * （3）建立链队列，并实现元素(4,5,7,6,8)入队，实现链队列的建立和入队的基本操作；
 * （4）实现元素(5,7)出队，实现链队列的出队的基本操作
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

int main(){
    printf("make_queue\n");
    QueuePtr queue = make_queue();
    int num[5] = {
            4,5,7,6,8
    };
    printf("pushing [4,5,7,6,8] into queue\n");
    for (int i = 0; i < 5; ++i) {
        push_queue(queue, num[i]);
    }

    printf("current len of queue is %d\n",Queue_length(queue));

    printf("current front_queue is %d\n", front_queue(queue));
    printf("pop_queue front_queue\n");
    pop_queue(queue, VOID_PTR);
    printf("current front_queue is %d\n", front_queue(queue));
    printf("pop_queue front_queue\n");
    pop_queue(queue, VOID_PTR);
    printf("current front_queue is %d\n", front_queue(queue));

    printf("current len of queue is %d\n",Queue_length(queue));
    printf("destroy_queue\n");
    destroy_queue(queue);
    return 0;
}
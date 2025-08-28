#include <stdio.h>
#include <stdlib.h>

struct DEqueue {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct DEqueue *q) {
    return q->r == q->f;
}

int isFull(struct DEqueue *q) {
    return q->r == q->size - 1;
}

void EnqueueR(struct DEqueue *q, int val) {
    if (isFull(q)) {
        printf("The queue is Full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element at rear: %d\n", val);  
    }
}

void Enqueuef(struct DEqueue *q, int val) {
    if (q->f == -1) {
        printf("Cannot add at the front, queue is full at the front.\n");
    } else {
        q->arr[q->f] = val;
        q->f--;
        printf("Enqueued element at front: %d\n", val);
    }
}

int Dequeuef(struct DEqueue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty\n");
        return -1;
    } else {
        q->f++;
        int val = q->arr[q->f];
        printf("Dequeued element from front: %d\n", val);
        return val;
    }
}

int DequeueR(struct DEqueue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty\n");
        return -1;
    } else {
        int val = q->arr[q->r];
        q->r--;
        printf("Dequeued element from rear: %d\n", val);
        return val;
    }
}

void printQueue(struct DEqueue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty\n");
    } else {
        printf("Current queue elements:\n ");
        for (int i = q->f + 1; i <= q->r; i++) {
            
            printf("%d\n", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct DEqueue s;
    s.size = 5;
    s.f = -1;
    s.r = -1; // Correct initialization
    s.arr = (int*)malloc(s.size * sizeof(int)); // Correct memory allocation
  
    EnqueueR(&s, 1);
    EnqueueR(&s, 2);
    EnqueueR(&s, 3);
    EnqueueR(&s, 4);

    printQueue(&s); // Print current queue elements

    Enqueuef(&s, 0); // Adding at front
    Enqueuef(&s, -1); // Adding another at front

    printQueue(&s); // Print current queue elements

    Dequeuef(&s); // Removing from front
    DequeueR(&s); // Removing from rear

    printQueue(&s); // Print current queue elements

    free(s.arr); // Free allocated memory
    return 0;
}

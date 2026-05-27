#include "Queue.h"

Queue::Queue() {

    front = 0;
    rear = -1;
}

bool Queue::isEmpty() {

    return rear < front;
}

void Queue::enqueue(int value) {

    rear++;

    arr[rear] = value;
}

int Queue::dequeue() {

    int value = arr[front];

    front++;

    return value;
}
#ifndef QUEUE_H
#define QUEUE_H

class Queue {

private:

    int arr[20000];

    int front;
    int rear;

public:

    Queue();

    bool isEmpty();

    void enqueue(int value);

    int dequeue();
};

#endif
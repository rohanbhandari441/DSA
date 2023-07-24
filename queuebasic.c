#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent the queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
bool isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to add an element to the rear of the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = data;
}

// Function to remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int removedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {
        // Queue becomes empty after dequeueing
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return removedItem;
}

// Function to get the element at the front of the queue without removing it
int front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->items[queue->front];
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    int choice, data;

    while (true) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(&myQueue, data);
                break;
            case 2:
                printf("Dequeued item: %d\n", dequeue(&myQueue));
                break;
            case 3:
                printf("Front of the queue: %d\n", front(&myQueue));
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Structure for the double-ended queue
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize a deque
void initDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

// Function to add an element to the front of the deque
void enqueueFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
        newNode->next = deque->front;
        deque->front = newNode;
    }
}

// Function to add an element to the rear of the deque
void enqueueRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        newNode->prev = deque->rear;
        deque->rear = newNode;
    }
}

// Function to remove an element from the front of the deque
int dequeueFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        exit(1);
    }
    struct Node* temp = deque->front;
    int data = temp->data;
    deque->front = temp->next;
    
    free(temp);
    return data;
}

// Function to remove an element from the rear of the deque
int dequeueRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        exit(1);
    }
   
    struct Node* temp = deque->rear->prev;
    temp->next = NULL;
    deque->rear = temp;
    free(temp);
    
}

// Function to display the elements of the deque
void displayDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the deque
void freeDeque(struct Deque* deque) {
    while (!isEmpty(deque)) {
        dequeueFront(deque);
    }
}

// Example usage
int main() {
    struct Deque deque;
    initDeque(&deque);

    enqueueFront(&deque, 1);
    enqueueFront(&deque, 2);
    enqueueRear(&deque, 3);
    enqueueRear(&deque, 4);

    displayDeque(&deque);

    printf("Dequeue front: %d\n", dequeueFront(&deque));
    printf("Dequeue rear: %d\n", dequeueRear(&deque));

    displayDeque(&deque);


    return 0;
}


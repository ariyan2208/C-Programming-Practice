#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

// Create Node
Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at Beginning
void insertBeginning(int data) {
    Node *newNode = createNode(data);

    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

// Insert at End
void insertEnd(int data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at Position
void insertPosition(int data, int pos) {
    if (pos == 1) {
        insertBeginning(data);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    Node *newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Delete from Beginning
void deleteBeginning() {
    if (head == NULL) return;

    Node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

// Delete from End
void deleteEnd() {
    if (head == NULL) return;

    Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev == NULL) {
        head = NULL;
    } else {
        temp->prev->next = NULL;
    }

    free(temp);
}

// Delete at Position
void deletePosition(int pos) {
    if (pos < 1 || head == NULL) return;

    Node *temp = head;

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Display Forward
void displayForward() {
    Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Display Backward
void displayBackward() {
    if (head == NULL) return;

    Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

// Search
void search(int key) {
    Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Not Found\n");
}

int main() {
    insertBeginning(20);
    insertBeginning(10);

    insertEnd(30);
    insertEnd(40);

    displayForward();

    insertPosition(25, 3);
    displayForward();

    deleteBeginning();
    displayForward();

    deleteEnd();
    displayForward();

    deletePosition(2);
    displayForward();

    displayBackward();

    search(30);

    return 0;
}

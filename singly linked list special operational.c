#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// helper function
struct Node* makeNode(int val) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = val;
    n->next = NULL;
    return n;
}

// Create Linked List
void createList() {
    int n, i, val;
    struct Node *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n < 0) { printf("Invalid number!\n"); return; }

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &val);
        struct Node *newnode = makeNode(val);

        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    printf("List Created Successfully!\n");
}

// Display Linked List
void display() {
    if (head == NULL) { printf("List is Empty!\n"); return; }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 1. Search an Element
void search() {
    int key, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value Found at Position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value Not Found!\n");
}

// 2. Find Position of an Element
void findPosition() {
    int key, pos = 1;
    printf("Enter value: ");
    scanf("%d", &key);

    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Position: %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value Not Found!\n");
}

// 3. Count Occurrences
void countOccurrence() {
    int key, count = 0;
    printf("Enter value: ");
    scanf("%d", &key);

    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) count++;
        temp = temp->next;
    }
    printf("Occurrences: %d\n", count);
}

// 4. Update Node Value
void updateNode() {
    int oldValue, newValue;
    printf("Enter old value: ");
    scanf("%d", &oldValue);

    struct Node *temp = head;
    while (temp != NULL && temp->data != oldValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value Not Found!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &newValue);
    temp->data = newValue;
    printf("Value Updated Successfully!\n");
}

// 5. Find Maximum Value
void findMax() {
    if (head == NULL) { printf("List is Empty!\n"); return; }

    int max = head->data;
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data > max) max = temp->data;
        temp = temp->next;
    }
    printf("Maximum Value: %d\n", max);
}

// 6. Find Minimum Value
void findMin() {
    if (head == NULL) { printf("List is Empty!\n"); return; }

    int min = head->data;
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data < min) min = temp->data;
        temp = temp->next;
    }
    printf("Minimum Value: %d\n", min);
}

// 7. Find Sum
void findSum() {
    int sum = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum: %d\n", sum);
}

// 8. Find Average
void findAverage() {
    if (head == NULL) { printf("List is Empty!\n"); return; }

    int sum = 0, count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    float average = (float)sum / count;
    printf("Average: %.2f\n", average);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Create Linked List\n2. Display Linked List\n3. Search an Element\n");
        printf("4. Find Position\n5. Count Occurrences\n6. Update Node Value\n");
        printf("7. Find Maximum Value\n8. Find Minimum Value\n9. Find Sum\n");
        printf("10. Find Average\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: findPosition(); break;
            case 5: countOccurrence(); break;
            case 6: updateNode(); break;
            case 7: findMax(); break;
            case 8: findMin(); break;
            case 9: findSum(); break;
            case 10: findAverage(); break;
            case 0: printf("Program Exited!\n"); return 0;
            default: printf("Invalid Choice!\n");
        }
    }
}

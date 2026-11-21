#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// হেল্পার ফাংশন: নতুন নোড তৈরি করে
struct Node* makeNode(int val) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Memory failed!\n");
        exit(1);
    }
    n->data = val;
    n->next = NULL;
    return n;
}
//helper function
void removeAfter(struct Node *prev, struct Node *target) {
    if (prev == NULL) {
        head = target->next;
    } else {
        prev->next = target->next;
    }
    free(target);
}

// Create Linked List
void createList() {
    int n, i, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n < 0) { printf("Invalid number!\n"); return; }

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &val);
        struct Node *newnode = makeNode(val);

        if (head == NULL) {
            head = newnode;
        } else {
            struct Node *temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newnode;
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

// 1. Delete First Node
void deleteBeginning() {
    if (head == NULL) { printf("List is Empty!\n"); return; }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("First Node Deleted!\n");
}

// 2. Delete Last Node
void deleteEnd() {
    if (head == NULL) { printf("List is Empty!\n"); return; }

    if (head->next == NULL) {
        deleteBeginning();
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Last Node Deleted!\n");
}

// 3. Delete from Specific Position (1-based)
void deletePosition() {
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL || pos < 1) { printf("Invalid Position or Empty List!\n"); return; }
    if (pos == 1) { deleteBeginning(); return; }

    struct Node *prev = head;
    for (i = 1; i < pos - 1 && prev != NULL; i++) {
        prev = prev->next;
    }

    if (prev == NULL || prev->next == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    removeAfter(prev, prev->next);
    printf("Node Deleted Successfully!\n");
}

// 4. Delete by Given Value
void deleteValue() {
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    if (head == NULL) { printf("List is Empty!\n"); return; }
    if (head->data == key) { deleteBeginning(); return; }

    struct Node *prev = head;
    while (prev->next != NULL && prev->next->data != key) {
        prev = prev->next;
    }

    if (prev->next == NULL) { printf("Value Not Found!\n"); return; }

    removeAfter(prev, prev->next);
    printf("Node Deleted Successfully!\n");
}

// 5. Delete After Given Value
void deleteAfterValue() {
    int key;
    printf("Enter value: ");
    scanf("%d", &key);

    struct Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) { printf("Value Not Found!\n"); return; }
    if (temp->next == NULL) { printf("No Node After This Value!\n"); return; }

    removeAfter(temp, temp->next);
    printf("Node Deleted Successfully!\n");
}

// 6. Delete Before Given Value
void deleteBeforeValue() {
    int key;
    printf("Enter value: ");
    scanf("%d", &key);

    if (head == NULL) { printf("List is Empty!\n"); return; }
    if (head->data == key) { printf("No Node Before This Value!\n"); return; }
    if (head->next != NULL && head->next->data == key) {
        deleteBeginning();
        return;
    }

    struct Node *curr = head;
    while (curr->next != NULL && curr->next->next != NULL && curr->next->next->data != key) {
        curr = curr->next;
    }

    if (curr->next == NULL || curr->next->next == NULL) {
        printf("Value Not Found!\n");
        return;
    }

    removeAfter(curr, curr->next);
    printf("Node Deleted Successfully!\n");
}

// 7. Delete Entire Linked List
void deleteList() {
    while (head != NULL) {
        deleteBeginning();
    }
    printf("Entire List Deleted!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Create Linked List\n2. Display Linked List\n3. Delete First Node\n");
        printf("4. Delete Last Node\n5. Delete from Position\n6. Delete by Value\n");
        printf("7. Delete After Value\n8. Delete Before Value\n9. Delete Entire List\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: display(); break;
            case 3: deleteBeginning(); break;
            case 4: deleteEnd(); break;
            case 5: deletePosition(); break;
            case 6: deleteValue(); break;
            case 7: deleteAfterValue(); break;
            case 8: deleteBeforeValue(); break;
            case 9: deleteList(); break;
            case 0: deleteList(); printf("Program Exited!\n"); return 0;
            default: printf("Invalid Choice!\n");
        }
    }
}

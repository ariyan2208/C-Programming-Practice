#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

//create new node
struct Node* createNode(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
   
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// 1. Create Linked List
void createList() {
    int n, i, val;
    struct Node *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &val);

        struct Node *newnode = createNode(val);

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    printf("Linked List Created Successfully!\n");
}

// 2. Display Linked List
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 3. Insert at Beginning
void insertBeginning() {
    int val;
    printf("Enter data: ");
    scanf("%d", &val);

    struct Node *newnode = createNode(val);
    newnode->next = head;
    head = newnode;

    printf("Node Inserted at Beginning!\n");
}

// 4. Insert at End
void insertEnd() {
    int val;
    printf("Enter data: ");
    scanf("%d", &val);

    struct Node *newnode = createNode(val);

    if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Node Inserted at End!\n");
}

// 5. Insert at Specific Position (1-based index)
void insertPosition() {
    int pos, val, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid Position!\n");
        return;
    }

    if (pos == 1) {
        insertBeginning();
        return;
    }

    struct Node *temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &val);

    struct Node *newnode = createNode(val);
    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node Inserted at Position %d!\n", pos);
}

// 6. Insert After Given Value
void insertAfterValue() {
    int key, val;
    printf("Enter value after which to insert: ");
    scanf("%d", &key);

    struct Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value Not Found!\n");
        return;
    }

    printf("Enter new data: ");
    scanf("%d", &val);

    struct Node *newnode = createNode(val);
    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node Inserted After %d!\n", key);
}

// 7. Insert Before Given Value
void insertBeforeValue() {
    int key, val;
    printf("Enter value before which to insert: ");
    scanf("%d", &key);

    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    if (head->data == key) {
        insertBeginning();
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value Not Found!\n");
        return;
    }

    printf("Enter new data: ");
    scanf("%d", &val);

    struct Node *newnode = createNode(val);
    newnode->next = temp;
    prev->next = newnode;

    printf("Node Inserted Before %d!\n", key);
}

// 8. Count Total Nodes
void countNodes() {
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total Nodes: %d\n", count);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Specific Position\n");
        printf("6. Insert After Given Value\n");
        printf("7. Insert Before Given Value\n");
        printf("8. Count Total Nodes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: display(); break;
            case 3: insertBeginning(); break;
            case 4: insertEnd(); break;
            case 5: insertPosition(); break;
            case 6: insertAfterValue(); break;
            case 7: insertBeforeValue(); break;
            case 8: countNodes(); break;
            case 0:
                printf("Program Exited!\n");
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

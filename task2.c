/*
===========================================================
 CODTECH Internship Task-2 (Advanced Level)
 Singly Linked List Implementation in C

 Features:
 1. Insert at Beginning
 2. Insert at End
 3. Insert at Position
 4. Delete from Beginning
 5. Delete from End
 6. Delete by Value
 7. Search Element
 8. Display List
 9. Count Nodes
10. Reverse List
11. Sort List
12. Free Entire List (Memory Cleanup)

===========================================================
*/

#include <stdio.h>
#include <stdlib.h>

/* Node Structure */
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Function Prototypes */
void insertBeginning(int);
void insertEnd(int);
void insertPosition(int, int);

void deleteBeginning();
void deleteEnd();
void deleteValue(int);

void searchNode(int);
void displayList();
void countNodes();
void reverseList();
void sortList();
void freeList();

/* Utility Function */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("❌ Memory Allocation Failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at Beginning */
void insertBeginning(int value) {
    struct Node *newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    printf("✅ Inserted %d at beginning.\n", value);
}

/* Insert at End */
void insertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("✅ Inserted %d at end.\n", value);
}

/* Insert at Specific Position */
void insertPosition(int value, int pos) {
    if (pos <= 0) {
        printf("❌ Invalid Position!\n");
        return;
    }

    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("❌ Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("✅ Inserted %d at position %d.\n", value, pos);
}

/* Delete from Beginning */
void deleteBeginning() {
    if (head == NULL) {
        printf("❌ List is empty!\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    printf("✅ Deleted %d from beginning.\n", temp->data);
    free(temp);
}

/* Delete from End */
void deleteEnd() {
    if (head == NULL) {
        printf("❌ List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        printf("✅ Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("✅ Deleted %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

/* Delete by Value */
void deleteValue(int value) {
    if (head == NULL) {
        printf("❌ List is empty!\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if (temp->data == value) {
        head = temp->next;
        free(temp);
        printf("✅ Deleted node with value %d.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Value %d not found!\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("✅ Deleted node with value %d.\n", value);
}

/* Search Node */
void searchNode(int value) {
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("✅ Value %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("❌ Value %d not found in list.\n", value);
}

/* Display List */
void displayList() {
    if (head == NULL) {
        printf("❌ List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("\nLinked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Count Nodes */
void countNodes() {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("✅ Total Nodes = %d\n", count);
}

/* Reverse List */
void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    printf("✅ Linked List Reversed Successfully!\n");
}

/* Sort List */
void sortList() {
    if (head == NULL) return;

    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("✅ Linked List Sorted Successfully!\n");
}

/* Free Entire List */
void freeList() {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("✅ Memory Freed. List Cleared.\n");
}

/* Main Menu */
int main() {
    int choice, value, pos;

    printf("\n========================================\n");
    printf("   CODTECH Internship Task-2 (PRO)\n");
    printf("   Advanced Singly Linked List System\n");
    printf("========================================\n");

    while (1) {
        printf("\n------------- MENU -------------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Count Nodes\n");
        printf("10. Reverse List\n");
        printf("11. Sort List\n");
        printf("12. Clear List\n");
        printf("13. Exit\n");
        printf("--------------------------------\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(value);
                break;

            case 8:
                displayList();
                break;

            case 9:
                countNodes();
                break;

            case 10:
                reverseList();
                break;

            case 11:
                sortList();
                break;

            case 12:
                freeList();
                break;

            case 13:
                freeList();
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("❌ Invalid choice! Try again.\n");
        }
    }

    return 0;
}

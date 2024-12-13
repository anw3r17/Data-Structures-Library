#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* ptr) {
    while (ptr != NULL) {
        printf("%4d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* enqueue(struct node* head, int data) {
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;
    if (head == NULL) {
        head = ptr;
    } else {
        struct node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
    }
    return head;
}

struct node* dequeue(struct node* head) {
    if (head == NULL) {
        printf("The queue is empty.\n");
    } else {
        struct node* ptr = head;
        head = head->next;
        free(ptr);
    }
    return head;
}

int main() {
    struct node* head = NULL;
    int choice, data;

    do {
        printf("Enter choice of operation:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Enter data:");
            scanf("%d", &data);
                head = enqueue(head, data);
                break;
            case 2:
                head = dequeue(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}

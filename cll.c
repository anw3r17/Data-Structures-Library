#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

void traversal(struct node *ptr) {
    struct node *start = ptr;
    do {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
}

struct node *insertatfirst(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    struct node *temp = head;
    if (head != NULL) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
    } else {
        ptr->next = ptr;
    }

    return ptr;
}

struct node *insertatend(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;

    if (head != NULL) {
        struct node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
    } else {
        ptr->next = ptr;
    }

    return ptr;
}

struct node *insertatindex(struct node *head, int data, int index) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main() {
    int n, data, index;
    printf("Enter the number of nodes:");
    scanf("%d", &n);

    struct node *head = NULL;
    struct node *current = NULL;

    for (int i = 0; i < n; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter the element for node %d:", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            current = newnode;
        } else {
            current->next = newnode;
            current = newnode;
        }
    }
    if (current != NULL) {
        current->next = head;
    }
    printf("Now enter the index where data is to be inserted at:");
    scanf("%d", &index);
    printf("Now enter the data to be inserted:");
    scanf("%d", &data);
    printf("\nThe Elements before insertion are:\n");
    traversal(head);
    head = insertatindex(head, data, index);
    printf("\nThe Elements after insertion are:\n");
    traversal(head);
    return 0;
}

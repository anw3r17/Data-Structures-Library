#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

void traversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* insertatfirst(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->prev = NULL;
    ptr->data = data;
    if (head != NULL) {
        head->prev = ptr;
    }
    return ptr;
}

struct node* insertatindex(struct node* head, int data, int index) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;
    if (p->next != NULL) {
        p->next->prev = ptr;
    }
    p->next = ptr;
    return head;
}

struct node* insertatend(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }
    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    return head;
}

int main() {
    int n, data, index;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    struct node* head = NULL;
    struct node* current = NULL;

    for (int i = 0; i < n; i++) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter the element for node %d:", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = current;
        if (head == NULL) {
            head = newnode;
        } else {
            current->next = newnode;
        }
        current = newnode;
    }

    printf("Now enter the index where data is to be inserted at:");
    scanf("%d", &index);
    printf("Now enter the data to be inserted:");
    scanf("%d", &data);

    printf("\nThe Elements before insertion are:\n");
    traversal(head);

    if (index == 0) {
        head = insertatfirst(head, data);
    } else if (index == n) {
        head = insertatend(head, data);
    } else if (index > 0 && index < n) {
        head = insertatindex(head, data, index);
    } else {
        printf("Invalid index! The data will not be inserted.\n");
    }

    printf("\nThe Elements after insertion are:\n");
    traversal(head);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct node{ 
    int data;
    struct node *next;
};
void traversal(struct node *ptr) {
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *start = ptr;
    do {
        printf("%4d", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}
struct node *insertatbeginning(struct node *head, int data) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    
    if (head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    struct node *start = head;
    while (head->next != start) {
        head = head->next;
    }

    head->next = ptr;
    ptr->next = start;
    return ptr;
}
struct node *insertatend(struct node *head, int data) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    struct node *start = head;
    while (head->next != start) {
        head = head->next;
    }

    head->next = ptr;
    ptr->next = start;
    return start;
}
struct node *insertatindex(struct node *head, int data, int index) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

   
    struct node *p = head;
    int i = 1;
    while (i != index - 1) {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main () {
    int choice, data, index;
    struct node *start= NULL;
    struct node *head= NULL;
    struct node *first=NULL;
    struct node *second=NULL;
    struct node *third=NULL;
    struct node *fourth=NULL;
    struct node *fifth=NULL;
    start = (struct node*)malloc(sizeof(struct node));
    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    fifth = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->next = first;
    first->next = second;
    first->data = 20;
    second->next = third;
    second->data = 30;
    third->next = fourth;
    third->data = 40;
    fourth->next = fifth;
    fourth->data = 50;
    fifth->next = start;
    fifth->data = 60;
    start->next = head;
    start->data = 5;
     do 
    {
        printf("\nCSLL before deletion:\n");
        traversal(head);
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Index\n");
        printf("3. Insert at End\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
               head = insertatbeginning(head, data);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                head = insertatindex(head, data, index);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertatend(head, data);
                break;

            case 4:
                printf("Linked List Elements:\n");
                traversal(head);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);
    return 0;

}
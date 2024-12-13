#include<stdio.h>
#include<stdlib.h>
struct node { 
    int data;
    struct node *next;
    struct node *prev;
};
void traversal(struct node *head){
    struct node *ptr =head;
    while(ptr!=NULL){
        printf("Element:%d\n", ptr->data);
        ptr=ptr->next;
    }
printf("\n");
}
struct node *deleteatbeginning(struct node *head){
    if(head == NULL){
        printf("The list is empty.");
    }
    else {
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
} }
struct node *deleteatindex(struct node *head, int index) {
        struct node *p = head;
        int i = 0;
        while(i != index -1){
            p = p->next;
            i++; }
     
struct node *temp = p -> next;
p->next = temp -> next;
temp-> next -> prev = p;
free(temp);
return head;
 }
struct node *deleteatend(struct node *head){
    if(head == NULL){
        printf("The list is empty.");
    }
    else { 
    struct node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return head;
}
}
int main () {
    int choice, index;
    struct node *head= NULL;
    struct node *first=NULL;
    struct node *second=NULL;
    struct node *third=NULL;
    struct node *fourth=NULL;
    struct node *fifth=NULL;
    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    fifth = (struct node*)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = first;
    first->prev = head;
    first->next = second;
    first->data = 20;
    second->prev = first;
    second->next = third;
    second->data = 30;
    third->prev = second;
    third->next = fourth;
    third->data = 40;
    fourth->prev = third;
    fourth->next = fifth;
    fourth->data = 50;
    fifth->prev = fourth;
    fifth->next = NULL;
    fifth->data = 60;
    do {
        printf("DLL before Deletion:");
        traversal(head);
        printf("\nMenu:\n");
        printf("1. Delete at Beginning\n");
        printf("2. Delete at Index\n");
        printf("3. Delete at End\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = deleteatbeginning(head);
                break;

            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                head = deleteatindex(head, index);
                break;

            case 3:
                head = deleteatend(head);
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

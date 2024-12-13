#include<stdio.h>
#include<stdlib.h>
struct node{ 
    int data;
    struct node *next;
};
struct node *insertatbeginning(struct node* head, int data){
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct node *insertatindex(struct node* head, int data, int index){
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node *insertatend(struct node* head, int data){
     struct node *ptr =(struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    return head;
}
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr= ptr->next;
    }
}
int main() {
    struct node *head = NULL;
    int choice, data, index;

    do {
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int seatnumber;
    char name[100];
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

void addseat(int seatnumber) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode -> seatnumber = seatnumber;
    newnode -> name[0] = '\0';
    newnode -> prev = NULL;
    newnode -> next = head;

    if (head != NULL) {
        head -> prev = newnode;
    }

    head = newnode;
}

void bookseat(int seatnumber, const char* name) {
    struct node* p = head;
    while (p != NULL) {
        if (p -> seatnumber == seatnumber) {
            if (p -> name[0] != '\0') {
                printf("Seat %d is already booked by %s.\n", seatnumber, p -> name);
            } else {
                strncpy(p->name, name, sizeof(p->name) - 1);
                p->name[sizeof(p->name) - 1] = '\0';
                printf("Seat %d booked successfully by %s.\n", seatnumber, name);
            }
            return;
        }
        p = p -> next;
    }

    printf("Seat %d not found in the Theatre.\n", seatnumber);
}

void unbookseat(int seatnumber) {
    struct node* p = head;
    while (p != NULL) {
        if (p -> seatnumber == seatnumber) {
            if (p -> name[0] != '\0') {
                p -> name[0] = '\0';
                printf("Seat %d unbooked successfully.\n", seatnumber);
            } else {
                printf("Seat %d is not booked.\n", seatnumber);
            }
            return;
        }
        p = p -> next;
    }

    printf("Seat %d not found in the theatre.\n", seatnumber);
}

void displayseats() {
    struct node* p = head;
    printf("Theatre Seat Status:\n");
    while (p != NULL) {
        if (p -> name[0] != '\0') {
            printf("Seat %d: Booked - %s\n", p -> seatnumber, p -> name);
        } else {
            printf("Seat %d: Available\n", p -> seatnumber);
        }
        p = p -> next;
    }
}

int main() {
    int numseats, choice, seatnumber;
    char name[100];

    printf("Enter the number of seats in the theatre: ");
    scanf("%d", &numseats);

    for (int i = 1; i <= numseats; i++) {
        addseat(i);
    }

    do {
        printf("\nTheatre Seat Booking\n");
        printf("1. Book Seat\n");
        printf("2. Unbook Seat\n");
        printf("3. Display Seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the seat number to book: ");
            scanf("%d", &seatnumber);
            printf("Enter the name of the person booking the seat: ");
            scanf("%s", name);
            bookseat(seatnumber, name);
            break;
        case 2:
            printf("Enter the seat number to unbook: ");
            scanf("%d", &seatnumber);
            unbookseat(seatnumber);
            break;
        case 3:
            displayseats();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

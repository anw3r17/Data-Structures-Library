struct node {
    int data;
    struct node *next;
};
struct node *deleteatbeginning(struct node *head) {
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteatindex(struct node *head, int index) {
    struct node *p = head;
    int i = 0;
    while (i != index - 1 && p->next != NULL) {
        p = p->next;
        i++;
    }

    if (p->next == NULL || i != index - 1) {
        printf("Index out of bounds.\n");
        return head;
    }

    struct node *temp = p->next;
    p->next = temp->next;
    free(temp);
    return head;
}

struct node *deleteatend(struct node *head) {
    struct node *p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }

    struct node *temp = p->next;
    p->next = NULL;
    free(temp);
    return head;
}
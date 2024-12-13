#include <stdio.h>
int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];
int delete();
void add(int item);
void bfs(int s, int n);
void push(int item);
int pop();

void main() {
    int n, i, s, ch, j;
    char c, dummy;
    printf("Enter the total number of Vertices:");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter 1 if %d has a node with %d else enter 0.", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    do {
        for (i = 1; i <= n; i++)
            vis[i] = 0;

        printf("\nMENU");
        printf("\n2.D.F.S");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        printf("Enter the Source Vertex:");
        scanf("%d", &s);

        switch (ch) {
            case 2:
                dfs(s, n);
                break;
        }

        printf("Do you want to continue(Y/N)? ");
        scanf(" %c", &c);
    } while ((c == 'y') || (c == 'Y'));
}

void bfs(int s, int n) {
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete();

    while (p != 0) {
        printf(" %d", p);

        for (i = 1; i <= n; i++) {
            if ((a[p][i] != 0) && (vis[i] == 0)) {
                add(i);
                vis[i] = 1;
            }
        }

        p = delete();
    }

    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n);
}

void add(int item) {
    if (rear == 19)
        printf("Queue is FULL.");
    else {
        if (rear == -1) {
            q[++rear] = item;
            front++;
        } else
            q[++rear] = item;
    }
}

int delete() {
    int k;

    if ((front > rear) || (front == -1))
        return (0);
    else {
        k = q[front++];
        return (k);
    }
}

void dfs(int s, int n) {
    int i;
    push(s);
    vis[s] = 1;

    while (top != -1) {
        s = pop();
        printf(" %d", s);

        for (i = 1; i <= n; i++) {
            if ((a[s][i] != 0) && (!vis[i])) {
                push(i);
                vis[i] = 1;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, n);
    }
}

void push(int item) {
    if (top == 19)
        printf("Stack Overflow");
    else
        stack[++top] = item;
}

int pop() {
    int item;

    if (top == -1)
        return 0;
    else {
        item = stack[top--];
        return item;
    }
}

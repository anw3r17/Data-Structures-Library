#include<stdio.h>
void main () {
int n, a[100], min_ind, i, j;
printf("Enter the size of Array:");
scanf("%d", &n);
printf("Enter the elements into the Array:");
for (i = 0; i < n; i++)
{
    scanf("%d", &a[i]);
}
for (i = 0; i < n; i++)
{
    min_ind = i;
    for ( j = i+1; j < n; j++)
    {
        if(a[j]<a[min_ind]){
            min_ind=j;
        }
    }
    if(min_ind!=i){
        int temp = a[min_ind];
        a[min_ind] = a[i];
        a[i] = temp;
    }
}
printf("After sorting:");
for ( i = 0; i < n; i++)
{
    printf("%d ", a[i]);
}

}
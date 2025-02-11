#include <stdio.h>
#define MAX 10
void display(int a[][MAX], int size);
int sparse(int a[][MAX], int b[][MAX], int row, int col);

nt main() {
int mat[MAX][MAX], s[MAX][MAX], sum[MAX][MAX];
int i, j,row,col,con,ch,sr;
printf("Enter the number of rows: ");
scanf("%d", &row);
printf("Enter the number of columns: ");
scanf("%d", &col);
printf("Enter the elements:\n");
for (i = 0; i < row; i++) {
for (j = 0; j < col; j++) {
scanf("%d", &mat[i][j]);
}
}
printf("The matrix is:\n");
for (i = 0; i < row; i++) {
for (j = 0; j < col; j++) {
printf("%d\t", mat[i][j]);
}
printf("\n");
}
sr = sparse(mat, s, row, col);
display(s, sr);
}


int sparse(int a[][MAX], int b[][MAX], int row, int col) {
int k = 1, i, j;
b[0][0] = row;
b[0][1] = col;
for (i = 0; i < row; i++) {
for (j = 0; j < col; j++) {
if (a[i][j] != 0) {
b[k][0] = i;
b[k][1] = j;
b[k][2] = a[i][j];
k++;
}
}
}
b[0][2] = k - 1;
return k - 1;
}

void display(int a[][MAX], int size) {
int i, j;
printf("\nSparse Matrix Representation:\n");
for (i = 0; i <= size; i++) {
for (j = 0; j < 3; j++) {
printf("%d\t", a[i][j]);
}
printf("\n");
}
}
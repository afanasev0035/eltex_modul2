#include <stdio.h>
#include <malloc.h>

// Ф-ия создания динамического массива----------------------------------------------------

int** create_dinamyk_massiv(int *n, int N) 
{
    int  **a; 
    a = (int**)malloc(sizeof(int*));
    a[0] = (int*)malloc(N * sizeof(int));
    *n = 1;
    return a;
}

// Ф-ия добавления новой строки в динамический массив-------------------------------------

int** add_string (int **a, int *n, int N)
{  *n = ++(*n);
   a = (int**)realloc(a,(*n)*sizeof(int*));
   a[*n-1] = (int*)malloc(N * sizeof(int));
   return a;
}

// Ф-ия удаления строки из динамического масства------------------------------------------

int** del_string (int **a, int *n)
{
    free(a[*n-1]);
    *n = --(*n);
    return a;
}

// Ф-ия добавления данных в динамический массив-------------------------------------------

void push(int **a, int*n, int *m, int val, int N) {
    if (*m >= 2) {
        a = add_string(a, n, N);
        *m = 0;
    }
    a[*n-1][*m]= val;
    *m = ++(*m);
}

// Ф-ия которая выводит значение в массиве, если рор переходит к предыдущему массиву, то удаляет нынешний линейный массив
void pop(int **a, int*n, int *m) 
{    printf("\n\ta[%d][%d] = [%d]\n", *n, *m, a[*n-1][*m-1]);
       if (*m == 0) {
       del_string(a, n);
        *m = 1;
    }else{--(*m);}
}

// Ф-ия печати динамического пассива-------------------------------------------------------

void print_massiv(int **a, int *n, int N)
{  for (int i = 0; i < *n; i++)
    {   
        for(int j = 0; j < N; j++)
        {
            printf("a[%d][%d] = [%d]\t", i, j, a[i][j]);
        } 
        printf("\n");
    }
}


int main (void)
{
 int **a; // указатель на указатель на строку элементов
 int q,w;
 q = 0; w = 0; // пришлось ввести эти переменные чтобы избежать ошибки сегментации
 int *n; // счетчик кол-ва строк
 n = &q;
 int *m; // счетчик кол-ва столбцов
 m = &w;  
 int N; // задание длины линейных массивов 
    int e;
 printf("\nВведите длину линейного массива\n");
 scanf("%d", &N);

 if (N < 1){printf("\nВы ввели некоректное значение\n");
 return 1;
 }
 
 a = create_dinamyk_massiv(n, N);

while(1)
{
printf("\n Что делаем?\n 1(push), 2(pop), 3(view), e(xit)\n");
scanf("%*c");
switch (getchar())
{
    case '1': printf("\nВведите число для добавления в массив\n");
              scanf("%d", &e);
              push(a, n, m, e, N);
              break;
    case '2': printf("\nВыводим элемент из массива\n");
              pop(a, n, m);
              break;
    case '3': printf("\nВыводим массив\n");
              print_massiv(a, n, N);
              break;
    case 'e': return;  
}
}         
return 0;
}

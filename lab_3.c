#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int NP = 100;
struct tovar 
{
  char name [BUFSIZ]; // наименование товара
  int price, quntity, percent; // цена товара, кол-во, процент надбавки
}; 

// Добавление элемента -----------------------------------------------------------------------

void addTovar (struct tovar *table, char name1[], int price1, int q, int per) 
{   
  int nn= size(table);
  if (nn >= 99) {
  printf("Таблиа переполнена");
  exit;
}
    strcpy(table[nn].name, name1);
    table[nn].price = price1;
    table[nn].quntity = q;
    table[nn].percent = per;
}

// Вывод таблицы ----------------------------------------------------------------------------

void showTovar (struct tovar *table) 
{printf("Имя \t Цена \t Кол-во \t Процент надбавки \n");
  int nn = size(table);
  for (int i = 0; i < nn; i++) {
    printf("%s\t %d\t %d\t\t %d\n", table[i].name, table[i].price, table[i].quntity, table[i].percent);
  }
}

// Компаратор для сортировки по имени --------------------------------------------------------

int cmpName (const void *a, const void *b) 
{
return strcmp(((const struct tovar *) a)->name, ((const struct tovar *) b)->name);
}

// Компаратор для сортировки по цене --------------------------------------------------------

int cmpPrice (const void *sortI, const void *sortJ) 
{
int sortI1=((const struct tovar *) sortI)->price;
int sortJ2=((const struct tovar *) sortJ)->price;
if (sortI1<sortJ2) {return -1;} else if (sortI1==sortJ2){return 0;} else {return 1;}
}

// Компаратор для сортировки по кол-ву --------------------------------------------------------

int cmpQuntity (const void *sortI, const void *sortJ) 
{
int sortI1=((const struct tovar *) sortI)->quntity;
int sortJ2=((const struct tovar *) sortJ)->quntity;
if (sortI1<sortJ2) {return -1;} else if (sortI1==sortJ2){return 0;} else {return 1;}
}

// Компаратор для сортировки по проценту ------------------------------------------------------

int cmpPercent (const void *sortI, const void *sortJ) 
{
int sortI1=((const struct tovar *) sortI)->percent;
int sortJ2=((const struct tovar *) sortJ)->percent;
if (sortI1<sortJ2) {return -1;} else if (sortI1==sortJ2){return 0;} else {return 1;}
}

// Функция сортировки структуры ----------------------------------------------------------------

void sort (struct tovar *table, int vybor) 
{ 
  int nn = size(table);
if (vybor == 1) // сортировка в поле имени
  {
    qsort(table, nn, sizeof(struct tovar), cmpName);
  }
if (vybor == 2) // сортировка в поле Цена
  {
    qsort(table, nn, sizeof(struct tovar), cmpPrice);
  }
if (vybor == 3) // сортировка в поле Кол-во
  {
    qsort(table, nn, sizeof(struct tovar), cmpQuntity);
  }
if (vybor == 4) // сортировка в поле процент надбавки
  {
    qsort(table, nn, sizeof(struct tovar), cmpPercent);
  }

}
 
// Функция поиска элемента структуре -----------------------------------------------------------

void search (struct tovar *table, int vybor, void* Q) 
{ int nn = size(table);
  if (vybor == 1) // поиск в поле Имени
  {
    for (int i = 0; i < nn; i++) 
    {
    if (strcmp(Q, table[i].name) == 0)
      {
        printf("%s\t %d\t %d\t\t %d\n", table[i].name, table[i].price, table[i].quntity, table[i].percent);
      }
    }
  }
  if (vybor == 2) // поиск в поле Цена
  {
    for (int i = 0; i < nn; i++) 
    {
    if (Q == table[i].price)
      {
        printf("%s\t %d\t %d\t\t %d\n", table[i].name, table[i].price, table[i].quntity, table[i].percent);
      }
    }
  }
  if (vybor == 3) // поиск в поле Кол-во
  {
    for (int i = 0; i < nn; i++) 
    {
    if (Q == table[i].quntity)
      {
        printf("%s\t %d\t %d\t\t %d\n", table[i].name, table[i].price, table[i].quntity, table[i].percent);
      }
    }
  }
  if (vybor == 4) // поиск в поле Процент надбавки
  {
    for (int i = 0; i < nn; i++) 
    {
    if (Q == table[i].percent)
      {
        printf("%s\t %d\t %d\t\t %d\n", table[i].name, table[i].price, table[i].quntity, table[i].percent);
      }
    }
  }
}

// Функция удаления записи ---------------------------------------------------------------------

void dell (struct tovar *table, int vybor) 
{ int nn = size(table);
  for (int i = vybor; i < nn; i++) 
  {
    table[i] = table [i+1];
  }
  return --nn;
}

// Функция редктирования записи -----------------------------------------------------------------

void editing (struct tovar *table, int vybor_stroki, int vybor_polya, void* izm) 
{
   if (vybor_polya == 1) // Редактирование поля Имени
  {
    strcpy(table[vybor_stroki].name, izm); 
  }
  if (vybor_polya ==2) // Редактирование поля Цены
  {
    table[vybor_stroki].price = izm;
  }
  if (vybor_polya == 3) // Редактирование поля Кол-ва
  {
    table[vybor_stroki].quntity = izm;
  }
  if (vybor_polya == 4) // Редактирование поля Процент надбавки
  {
    table[vybor_stroki].percent = izm;
  }
}

int size (struct tovar *table)
{
  int i = 0;
  while (strlen(table[i].name) != 0)
  {
  i++;
  }
  return i;
}



int main (void)
{
struct tovar table[NP];
int nn = 0;
int price;
int quntity;
int percent;
char name [BUFSIZ];
addTovar(table, "Tomat", 7, 98, 20);
addTovar(table, "Ogurec", 4, 89, 32);
addTovar(table, "Ananas", 7, 300, 140);
showTovar(table);
sort(table, 1);
search(table,1,"Ogurec");

while(1)
{
printf("\n what to do?\n1(add),2(view), 3(sort), 4(search), 5(dell), 6(edit), e(xit)\n");
switch (getchar())
{
case '1': printf("Введите наименование товара\n");
          scanf("%*c");
          fgets(name, BUFSIZ, stdin);
          printf("Введите цену товара\n");
          scanf("%d", &price);
          printf("Введите кол-во товара\n");
          scanf("%d", &quntity);
          printf("Введите процент надбавки товара\n");
          scanf("%d", &percent);
          addTovar(table, name, price, quntity, percent);
          break;
case '2': showTovar(table);
          break;
case '3': printf("По какому столбу будет производиться сортировка(указать нужно номер с 1-4)\n");
          scanf("%d", &price);
          sort(table,price);
          break;
case '4': printf("В каком столбце будет вестись поиск?\n");
          scanf("%d", &price);
          if (price == 1) {
          printf("Введите искомое значение?\n");    
          scanf("%*c");
          fgets(name, BUFSIZ, stdin);
          search(table, price, name); 
          }
          else 
          {
          printf("Введите искомое значение?\n");    
          scanf("%d", &quntity);
          search(table, price, quntity); 
          }  
          scanf("%*c");
          break;
case '5': printf("Введите номер удаляемой строки?\n");    
          scanf("%d", &price);
          dell(table, price);
          break; 
case '6': printf("Введите номер строки изменяемой ячейки?\n");    
          scanf("%d", &price);
          printf("Введите номер столбца изменяемой ячейки?\n");    
          scanf("%d", &quntity);
          if(quntity == 1)
          {printf("Введите значение?\n");
          scanf("%*c");
          fgets(name, BUFSIZ, stdin);  
          editing(table, price, quntity, name);
          }
          else
          {printf("Введите значение?\n");
          scanf("%d", &percent);
          editing(table, price, quntity, percent);
          }
          break; 
case 'e': return;    
}
}
}
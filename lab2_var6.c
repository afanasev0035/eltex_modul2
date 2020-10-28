#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

char *data_s (char **A, int i) {
  
    if (i == 0) {
A = (char**)malloc(sizeof(char*));
char string [BUFSIZ];
fgets(string, BUFSIZ, stdin);
A[i] = (char*) malloc((strlen(string) + 2));
strcpy(A[i], string);}         
     else {
A = (char**)realloc(A,(i + 2)*sizeof(char*));
char string [BUFSIZ];
fgets(string, BUFSIZ, stdin);
A[i] = (char*) malloc((strlen(string) + 2));
strcpy(A[i], string);}
return A;

}

int *dc (int *B, int i) {
    if (i == 0) {
B = (int*)malloc(sizeof(int));
scanf("%d", &B[i]);
    } else {
B = (int*)realloc(B, (i+1)*sizeof(int));
scanf("%d", &B[i]);}
return B;
}


void qq (char **name, int *dd, int *mm, int *yy, char **adres, int i)
{       
        printf("\n------------------------------------------------------------------------------------------------------------------");
        printf("\nИмя");
        printf("\tДата");
        printf("\tМесяц");
        printf("\tГод");
        printf("\tПрочее\n");

    for (int j = 0; j < i; j++) {
        printf("\n");
        printf("%s\t",name[j]);
        printf("%d\t",dd[j]);
        printf("%d\t",mm[j]);
        printf("%d\t",yy[j]);
        printf("%s\n",adres[j]);
    }
}

int main () {char **adres;
    char **name = NULL; int i = 0;
    
    int *dd;
    int *mm; 
    int *yy;
    while (1) {  
        printf("Введите имя------------------------------------------------------------------------------\n");
        name = data_s(name, i);
        if (strlen(name[i])==1) {break;}
        printf("Введите число------------------------------------------------------------------------------\n");
        dd = dc(dd, i);
        printf("Введите месяц-----------------------------------------------------------------------------------\n");
        mm = dc(mm, i);
        printf("Введите год----------------------------------------------------------------------------------------------\n");
        yy = dc(yy, i);
        printf("Введите примечание-------------------------------------------------------------------------------------------\n");
          scanf("%*c");
        adres = data_s(adres, i); 
       i = i + 1;
    }
   qq(name, dd, mm, yy, adres, i);


return 0;
}
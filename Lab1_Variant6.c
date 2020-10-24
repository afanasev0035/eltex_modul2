#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void del(char *A) {
  int w = strlen(A);
  for (int q = w; q >= 0; q--) {
              A[q]=A[q+1];
            }
}

int main () {

char str[105];
printf("Введите строку: ");
fgets(str, 105, stdin);
int n = 0;

for (int i = 0; i < strlen(str); i++){
    if (str[i] == ' ') n++;
} 

n++;
char slovar[n][20];
int schet = 0;

for (int i = 0; i < n; i++){
      for (int j = schet; j < strlen(str)-1; j++){
           if (str[j] != ' ') {
               slovar[i][j-schet] = str[j];
               slovar[i][j-schet+1] = '\0';
           }
           else {schet = j + 1;
               break;}
      }
      slovar[i][strlen(slovar[i])+1] = '\0';
      }

for (int i = 0; i < n; i++){
      for (int j = i+1; j < n; j++){
        if (strcmp(slovar[i], slovar[j]) == 0) {
            printf("%s\t%s\n", slovar[i], slovar[j]);
           del(slovar[j]);
           del(slovar[i]);
      }
}
}
del(str);
for (int i = 0; i < n; i++){
  if ((strlen(slovar[i]) != 0) && (strlen(slovar[i]) > 5)){
strcat(str, slovar[i]);
strcat(str, " ");
}}

printf("Полученная строка: %s",str);
return 0;
}

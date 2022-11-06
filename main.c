#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

 struct land{
    char co[4];
    char na[50];
    char ct[50];
    long po;
    long su;
};
int main() {
    struct land pays[10];
// The file represent the pointer  of it
FILE *fichiertxt,*xml;
int i=0;
char singeline[255];
fichiertxt= fopen("C:\\Users\\DELL\\CLionProjects\\pays.txt","w");
xml= fopen("C:\\Users\\DELL\\Documents\\Projects\\country.csv","r");
if(xml!=NULL){
     srand(time(NULL));
     int tab[10];
     while(i<10){
         tab[i]=rand()%239;
        // printf("%d\n", tab[i]);
         for(int j=0;j<i;j++) {
             if (tab[j]==tab[i]) {
                 i--;
                 break;
             }
         }
         i++;
     }
//     for(i=0;i<10;i++) {
//         printf("value : %d  \n", tab[i]);
//     } // To sheck the 10 number list
    i=0;
    fseek(xml,137,SEEK_SET);
     while (!feof(xml)){
         fgets(singeline, 255, xml);
         for(int linde_index=0;linde_index<10;linde_index++) {
             if (i == tab[linde_index]) {
                 //fprintf(fichiertxt, singeline);
                 char delim[]=",";
                 char  *dv= strtok(singeline,delim);
                 //printf(" line index : %d \n",i);// To check the line number on the table
                 //to print the value saved on the text file               printf("%s,", dv);
                 strcpy(pays[linde_index].co,dv);
                 dv = strtok(NULL, delim);
                 //to print the value saved on the text file    printf(" %s,", dv);
                 strcpy(pays[linde_index].na,dv);
                 fprintf(fichiertxt," %s,", pays[linde_index].co);
                 fprintf(fichiertxt," %s,", pays[linde_index].na);
                 // ------------------------
                 dv = strtok(NULL, delim);
                 strcpy(pays[linde_index].ct,dv);
                 //to print the value saved on the text file     printf("%s, ", dv);
                 fprintf(fichiertxt, " %s,", pays[linde_index].ct);
                 // -------------------------
                 dv = strtok(NULL, delim);
                 dv = strtok(NULL, delim);
                 //to print the value saved on the text file   printf(" %s,", dv);
                 fprintf(fichiertxt, " %s,",dv);
                //memccpy(pays[linde_index].su,dv,10,10);
                //Convert Char to long--
                 char **endpnt = NULL;
                 pays[linde_index].su=  strtol(dv, endpnt,10);
                 //printf("here : %li /",pays[linde_index].su);
                 // ------------------------
                 dv = strtok(NULL, delim);
                 dv = strtok(NULL, delim);
                 //to print the value saved on the text file      printf(" %s,", dv);
                 fprintf( fichiertxt," %s\n",dv);
                 // Convert Char to long
                 pays[linde_index].po=  strtol(dv, endpnt,10);
                 //* memccpy(pays[linde_index].po,dv,10,10);
                 //DIV line on the .txt file   fprintf(fichiertxt,"\n----------------\n");
                 //DIV line    printf("\n-----------  \n");
                 linde_index++;
             }
         }
         i++;
     }

     int pays_index=0;
     char fond ='N';
    printf("Les nome des pays ayant une surface plus grand que (1.000.000 Km2) :  \n");
    fond='N';
    while(pays_index<10){
        if(pays[pays_index].su>1000000) {
            fond='Y';
            printf("--> %s", pays[pays_index].na);
            printf(" avec une Surface de: %li \n",pays[pays_index].su);
        }
        if(pays_index==9&&fond=='N'){
            printf(" ! Aucune pays a une surface plus grand que 1.000.000 Km2\n");
        }
        pays_index++;
    }
    pays_index=0;
    printf("-------------------------------- \n");
    printf("les Code du pays appartenant au continent africain : \n");
     while(pays_index<10){
         if(strcmp(pays[pays_index].ct,"Africa")==0){
             fond='Y';
             printf("--> %s\n",pays[pays_index].co);
         // To check the country name    printf("--> %s\n",pays[pays_index].na);
         }
         if(pays_index==9&&fond=='N'){
             printf("Il n'existe pas de pays africain dans la liste \n");
         }
         pays_index++;
     }

     printf("-------------------------------- \n");
     printf("Les Donnees du pays du fichier pays.txt : \n");
    pays_index=0;
    while(pays_index<10){
        printf(" %s,",pays[pays_index].co);
        printf(" %s,",pays[pays_index].na);
        printf(" %s,",pays[pays_index].ct);
        printf(" %li,",pays[pays_index].po);
        printf(" %li \n",pays[pays_index].su);
        pays_index++;
    }
     fclose(xml);
     fclose(fichiertxt);
 }else{
     printf("le fichier n exisit pas !");
 }
    return 0;
}

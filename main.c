#include <stdio.h>
#include <stdlib.h>
struct s_studente{
    char nome[30+1];
    char cognome[30+1];
    int eta;
};
typedef struct s_studente studente;

struct s_elemento{
    studente v;
    struct s_elemento *next;
};
typedef struct s_elemento elemento;

void stampa(elemento *p);
int inserisci(elemento* punt);

int main(int argc, char** argv) {
    elemento *p,*punt;
    int i;
    int altri=-1;
    p=(elemento*)malloc(sizeof(elemento));
    //printf("Inserisci un valore: ");
    //scanf("%d",&(p->v));
    punt=p;
   
    while(altri!=0){
        
        altri=inserisci(punt);
        if(altri){
            punt->next=(elemento*)malloc(sizeof(elemento));
            punt=punt->next;
        }
    }
    punt->next=NULL;
    
    while(p!=NULL){
        stampa(p);
        p=p->next;
    }
    return (EXIT_SUCCESS);
}

int inserisci(elemento* punt){
    int altri;
    
    printf("Nome: ");
    scanf("%s",(punt->v.nome));
    printf("Cognome: ");
    scanf("%s",punt->v.cognome);
    printf("Età: ");
    scanf("%d",&(punt->v.eta));
    puts("");
    printf("Vuoi inserire altri numeri? (0 no - 1 si) ");
    scanf("%d",&altri);
    puts("");
    
    return altri;
}

void stampa(elemento *p){
    printf("Nome: %s\n",p->v.nome);
    printf("Cognome: %s\n",p->v.cognome);
    printf("Età: %d\n\n",p->v.eta);
}
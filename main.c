#include <stdio.h>
#include <stdlib.h>

struct s_elemento{
    int v;
    struct s_elemento *next;
};
typedef struct s_elemento elemento;

int main(int argc, char** argv) {
    elemento *p,*punt;
    int i;
    
    p=(elemento*)malloc(sizeof(elemento));
    printf("Inserisci un valore: ");
    scanf("%d",&(p->v));
    punt=p;
    
    while(punt->v!=0){
        punt->next=(elemento*)malloc(sizeof(elemento));
        punt=punt->next;
        printf("Inserisci un valore: ");
        scanf("%d",&(punt->v));
    }
    punt->next=NULL;
    
    while(p!=NULL){
        if(p->v){
            printf("%d",p->v);
            printf("->");
        }
        p=p->next;
    }
    return (EXIT_SUCCESS);
}


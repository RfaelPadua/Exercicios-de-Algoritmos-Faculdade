#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define InicioArranjo 0
#define MaxTam 1000

typedef int Apontador, TipoChave;

typedef struct{
    int ano;
    char montadora[50];
    char modelo[5];
    float valor;
} TipoItem;

typedef struct{
    TipoItem Item[MaxTam];
    Apontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);
void PopularLista(TipoLista *Lista);
void Insere(TipoItem item, TipoLista *Lista);
void ImprimeLista(TipoLista *Lista);
void ImprimeItem(TipoItem item);
void ListaVazia(TipoLista *Lista);
void Retira(int p, TipoLista *Lista);

float SomaValor(TipoLista *Lista);
float MediaValor(TipoLista *Lista);
TipoItem MaisCaro(TipoLista *Lista);
int MontadoraEstaPresente(char *montadora, TipoLista *Lista);
void Retira(int p, TipoLista *Lista);

int RetiraMontadora(char *montadora, TipoLista *Lista);
int RetiraModelo(char *modelo, TipoLista *Lista);
int UltimaLetraModeloVogal(TipoLista *Lista);
int MaiorLista(TipoLista *Lista1, TipoLista *Lista2);


int main(){
    TipoLista lista;
    FLVazia(&lista);

    PopularLista(&lista);

    printf("Soma dos valores: %.2f\n", SomaValor(&lista));
    printf("Media dos valores: %.2f\n", MediaValor(&lista));

    printf("\nO Carro mais caro eh: \n");
    ImprimeItem(MaisCaro(&lista));
    char montadoraInput1[50] = "Montadora 4";
    char montadoraInput2[50] = "Montadora 32";
    int aux = MontadoraEstaPresente(montadoraInput2, &lista);
    if(aux == -1){
        printf("A %s nao esta na lista.\n", montadoraInput2);
    }else{
        printf("O Carra da %s esta na posicao %d.\n", montadoraInput2, aux);
    }
    aux = MontadoraEstaPresente(montadoraInput1, &lista);
    if(aux == -1){
        printf("A %s nao esta na lista.\n", montadoraInput1);
    }else{
        printf("O Carra da %s esta na posicao %d.\n", montadoraInput1, aux);
    }

    aux = 12;

    Retira(aux, &lista);

    aux = 2;

    char auxchar[50] = "Montadora 0";

    Retira(aux, &lista);

    RetiraMontadora(auxchar, &lista);

    ImprimeLista(&lista);


}

void FLVazia(TipoLista *Lista){
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
}/*FLVazia*/

void Insere(TipoItem item, TipoLista *Lista){
    if(Lista->Ultimo >= MaxTam){
        printf("Lista cheia \n");
        return;
    }

    Lista->Item[Lista->Ultimo] = item;
    Lista->Ultimo++;
    
}/*Insere*/

void ImprimeLista(TipoLista *Lista){
    int i; 

    for(i = Lista->Primeiro; i< Lista->Ultimo; i++){
        ImprimeItem(Lista->Item[i]);

    }
}/*ImprimeLista*/

void ImprimeItem(TipoItem item){
    printf("Ano: %d\n", item.ano);
    printf("Montadora: %s\n", item.montadora);
    printf("Modelo: %s\n", item.modelo);
    printf("Valor: %.2f\n\n", item.valor);
    
}/*ImprimeItem*/

void PopularLista(TipoLista *Lista){
    TipoItem item;

    for(int i = 0; i < 5; i++){
        item.ano = 2000 + i;
        item.valor = 1000 + 1000*i;
        sprintf(item.montadora, "Montadora %d", i);
        sprintf(item.modelo, "M%d", i);
        Insere(item, Lista);
    }

}/*PopularLista*/

float SomaValor(TipoLista *Lista){
    float soma = 0;
    int i;

    for(i = 0; i < Lista->Ultimo; i++){
        soma += Lista->Item[i].valor;
    }

    return soma;
}/*SomaValor*/

float MediaValor(TipoLista *Lista){
    return SomaValor(Lista)/Lista->Ultimo;
}/*MediaValor*/

TipoItem MaisCaro(TipoLista *Lista){
    TipoItem item;
    int i;
    item = Lista->Item[Lista->Primeiro];

    for(i = Lista->Primeiro; i < Lista->Ultimo; i++){
        if(Lista->Item[i].valor > item.valor){
            item = Lista->Item[i];
        }
    }

    return item;
}/*MaisCaro*/

int MontadoraEstaPresente(char *montadora, TipoLista *Lista){
    
    int i;

    for(i = Lista->Primeiro; i < Lista->Ultimo; i++){
        if(!strcmp(montadora,Lista->Item[i].montadora)){
            return i;
        }
    }

    return -1;
}

void ListaVazia(TipoLista *Lista){
    if(Lista->Primeiro == Lista->Ultimo)
        printf("Lista Vazia\n");
    return; 
}/*ListaVazia*/

void Retira(int p, TipoLista *Lista){
    ListaVazia(Lista);

    int i;

    if(p > Lista->Ultimo){
        printf("Posicao invalida\n\n");
        return;
    }

    for(i = p; i < Lista->Ultimo-1; i++){
        Lista->Item[p] = Lista->Item[p+1];
    }

    Lista->Ultimo--;

}/*Retira*/

int RetiraMontadora(char *montadora, TipoLista *Lista){
    int i;

    for(i = Lista->Primeiro; i < Lista->Ultimo; i++){
        if(!strcmp(montadora, Lista->Item[i].montadora)){
            Retira(i, Lista);
            return 0;
        }
    }
    return -1;
}/*RetiraMontadora*/


int RetiraModelo(char *modelo, TipoLista *Lista){
    int i;

    for(i = Lista->Primeiro; i < Lista->Ultimo; i++){
        if(!strcmp(modelo, Lista->Item[i].montadora)){
            Retira(i, Lista);
            return 0;
        }
    }
    return -1;
}/*RetiraModelo*/


int UltimaLetraModeloVogal(TipoLista *Lista){
    char vogal[6] = "aeiou";
    int i, j, k;

    for(i = Lista->Primeiro; i < Lista->Ultimo; i++){
        for(j = 0; Lista->Item[i].modelo[j] != '\0'; j++){
            if(Lista->Item[i].modelo[j+1] == '\0'){
                for(k = 0; k < 5; k++){
                    if(tolower(Lista->Item[i].modelo[j]) == vogal[k]){
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}/*UltimaLetraModeloVogal*/

int MaiorLista(TipoLista *Lista1, TipoLista *Lista2){
    if(Lista1->Ultimo > Lista2->Ultimo){
        return 1;
    }else if(Lista1->Ultimo < Lista2->Ultimo){
        return 2;
    }else{
        return 0;
    }
}/*MaiorLista*/




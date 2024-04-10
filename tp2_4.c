#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define M 5

struct computadora{
    int velocidad, anio, cantidad;
    char *tipo_cpu;
}typedef PC;

PC cargarPc();
void mostrarLista(PC *lista);
void masVieja(PC *lista);
void cuchau(PC *lista);

int main(){
    puts("\n\n\t\t------CARGANDOOO-----");
    srand(time(NULL));
    PC *lista = (PC*)malloc(M*sizeof(PC));
    for (int i = 0; i < M; i++){
        *(lista + i)= cargarPc();
    }
    
    mostrarLista(lista);   
    masVieja(lista);
    cuchau(lista);

    for (int i = 0; i < M; i++){
        free(lista[i].tipo_cpu);
    }
    free(lista);
}

PC cargarPc(){
    PC compu;
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    compu.tipo_cpu = (char*)malloc(M*sizeof(char));
    int indice = rand()%6;
    compu.anio = 2015 + rand()%9;
    compu.cantidad = 1 + rand()%8;
    compu.velocidad = 1 + rand()%3;
    compu.tipo_cpu = strcpy(compu.tipo_cpu, tipos[indice]);

    return compu;
}

void mostrarLista(PC *lista){
    printf("\t\t   LISTADO DE PCs\n ");
    for (int i = 0; i < M; i++){
        printf("\n\t\tFicha tecnica PC %d\n", i+1);
        printf("CPU:\t\t\t%s\n",lista[i].tipo_cpu);
        printf("Anio de fabricacion:\t%d\n",lista[i].anio);
        printf("Nucleos:\t\t%d\n",lista[i].cantidad);
        printf("Velocidad:\t\t%d GHz\n\n",lista[i].velocidad);
    }
}

void masVieja(PC *lista){
    int k = 0, comparacion = lista[0].anio; 
    for (int i = 0; i < M; i++){
        if (lista[i].anio < comparacion){
            comparacion = lista[i].anio;
            k = i;
        }
    }
    puts("...COMPUTADORA MAS VIEJA...");
    printf("\n\t\tFicha tecnica PC\n");
    printf("CPU:\t\t\t%s\n",lista[k].tipo_cpu);
    printf("Anio de fabricacion:\t%d\n",lista[k].anio);
    printf("Nucleos:\t\t%d\n",lista[k].cantidad);
    printf("Velocidad:\t\t%d GHz\n\n",lista[k].velocidad);
}

void cuchau(PC *lista){
    int k = 0, comparacion = lista[0].velocidad; 
    for (int i = 0; i < M; i++){
        if (lista[i].velocidad > comparacion){
            comparacion = lista[i].velocidad;
            k = i;
        }
    }
    puts("...COMPUTADORA MAS VELOZ...");
    printf("\n\t\tFicha tecnica PC\n");
    printf("CPU:\t\t\t%s\n",lista[k].tipo_cpu);
    printf("Anio de fabricacion:\t%d\n",lista[k].anio);
    printf("Nucleos:\t\t%d\n",lista[k].cantidad);
    printf("Velocidad:\t\t%d GHz\n\n",lista[k].velocidad);
}
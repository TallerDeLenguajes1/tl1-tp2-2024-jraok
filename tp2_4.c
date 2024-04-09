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



int main(){
    puts("\n\n\t\t------CARGANDOOO-----");
    srand(time(NULL));
    PC *lista = (PC*)malloc(M*sizeof(PC));
    for (int i = 0; i < M; i++){
        *(lista + i)= cargarPc();
    }
    

}

PC cargarPc(){
    PC compu;
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    compu.tipo_cpu = (char*)malloc(M*sizeof(char));
    int indice;
    compu.anio = 2015 + rand()%9;
    compu.cantidad = 1 + rand()%8;
    compu.velocidad = 1 + rand()%3;
    do{ 
        indice = 0;       
        printf("\tIngrese el tipo de CPU que posee la PC");
        puts("1 --> Intel");
        puts("2 --> AMD");
        puts("3 --> Celeron");
        puts("4 --> Athlon");
        puts("5 --> Core");
        puts("6 --> Pentium");
        scanf("%d", &indice);
        if (indice < 1 && indice > 6){
            puts("VALOR FUERA DE RANGO");
        }
    } while (indice < 1 && indice > 6);
    
    compu.tipo_cpu = strcpy(compu.tipo_cpu, tipos[indice]);

    return compu;
}

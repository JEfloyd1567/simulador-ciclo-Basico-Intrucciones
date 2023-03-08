#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//registros del sistema:
int ACC = 0; // Acumulador
int ICR = 0; // Contador de instrucciones
int MDR = 0; // Registro de datos de memoria
int MAR = 0; // Registro de direccion de memoria
int UC = 0;  // Unidad de control instruccion set = 0, instruccion load = 1, instruccion add = 2, intruccion inc = 3, instruccion dec = 4, instruccion str = 5, intruccion show = 6, instruccion UC = 7, 

//memoria principal
int MEMORY[100];

//instrucciones:

void SET(int D1, int X){
    MEMORY[D1] = X;
    UC = 0;
}

void LDR(int D3){
    MDR = MEMORY[D3];
    ACC = MDR;
    MAR = MEMORY[D3];
    UC =  1;
}

void ADD(int D1, int D3, int D4){
    int sum;
    UC = 2;
    if (D3 == 0){
        sum = ACC + MEMORY[D1];
        MAR = sum;
    }
    else{
        sum = ACC + MEMORY[D1] + MEMORY[D3];
        MAR = sum;
    }
    if (D4 == 0){
        ACC = sum;
        MAR = ACC;
    }
    else{
        MEMORY[D4] = sum;
        MAR = MEMORY[D4];
    }
}

void INC(int D3){
    MEMORY[D3]++;
    UC = 3;
}

void DEC(int D3){
    MEMORY[D3]--;
    UC = 4;
}

void STR(int D3){
    MAR = ACC;
    MEMORY[D3] = ACC;
    UC = 5;
}

void SHW(int D2){
    UC = 6;
    if(D2 == 0){
        printf("ACC: %d\n", ACC);
        printf("MEMORY[%d]: %d\n", D2, MEMORY[D2]);
    } 
    else if(D2 == 1){
        printf("ICR: %d\n", ICR);
        printf("MEMORY[%d]: %d\n", D2, MEMORY[D2]);
    }
    else if(D2 == 2){
        printf("MAR: %d\n", MAR);
        printf("MEMORY[%d]: %d\n", D2, MEMORY[D2]);
    }
    else if(D2 == 3){
        printf("MDR: %d\n", MDR);
        printf("MEMORY[%d]: %d\n", D2, MEMORY[D2]);
    } 
    else{
        printf("MEMORY[%d]: %d\n", D2, MEMORY[D2]);
    }
    printf("UC: %d\n", UC);
}

void PAUSE(){
    // Imprimir valores de registros y memoria
    printf("REGISTROS:\n");
    printf("ACC: %d\n", ACC);
    printf("ICR: %d\n", ICR);
    printf("MDR: %d\n", MDR);
    printf("MAR: %d\n", MAR);
    printf("UC: %d\n", UC);
    printf("MEMORIA:\n");
    int i = 0;
    for (i = 0; i < 100; i++){
        printf("%d: %d\n", i, MEMORY[i]);
    }
}

void UCF(){
    UC = 7;
    printf("UC: %d\n", UC);
}

int main(){

    int instruccion;
    int D1, D2, D3, D4, X;
        // Inicializar memoria con ceros
    int i = 0;
    for (i = 0; i < 100; i++){
        MEMORY[i] = 0;
    }
    printf("para usar la instruccion SET: ingrese 1\n");
    printf("para usar la instruccion LDR: ingrese 2\n");
    printf("para usar la instruccion ADD: ingrese 3\n");
    printf("para usar la instruccion INC: ingrese 4\n");
    printf("para usar la instruccion DEC: ingrese 5\n");
    printf("para usar la instruccion STR: ingrese 6\n");
    printf("para usar la instruccion SHW: ingrese 7 (ACC = 0, ICR 1, MAR 2, MDR = 3, si desea ver solo el registro escriba solo el 4)\n");
    printf("para usar la instruccion PAUSE: ingrese 8\n");
    printf("para usar la instruccion END: ingrese 9\n");
    printf("para usar la instruccion UC: ingrese 10\n");
    printf("para usar la NULL: ingrese en vez de NULL un 0\n");
    
    while (1){
        printf("Ingrese la instruccion:\n");
        scanf("%d", &instruccion);
        switch (instruccion){
            case 1:
                printf("Ingrese D1 y X:\n");
                scanf("%d %d", &D1, &X);
                SET(D1, X);
                break;
            case 2:
                printf("Ingrese D3:\n");
                scanf("%d", &D3);
                LDR(D3);
                break;
            case 3:
                printf("Ingrese D1 y D3\n");
                scanf("%d %d", &D1, &D3);
                if (D3 == 0){
                    D4 = 0;
                } 
                else{
                    printf("Ingrese D4:\n");
                    scanf("%d", &D4);
                }
                ADD(D1, D3, D4);
                break;
            case 4:
                printf("Ingrese D3:\n");
                scanf("%d", &D3);
                INC(D3);
                break;
            case 5:
                printf("Ingrese D3:\n");
                scanf("%d", &D3);
                DEC(D3);
                break;
            case 6:
                printf("Ingrese D3:\n");
                scanf("%d", &D3);
                STR(D3);
                break;
            case 7:
                printf("Ingrese D2:\n");
                scanf("%d", &D2);
                SHW(D2);
                break;
            case 8:
                PAUSE();
                break;
            case 9:
                return 0;
                break;
            case 10:
                UCF();
            default:
                printf("invalido\n");
                break;
        }
        ICR++;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Lê um numero FLOAT
// Usado a passagem de parâmetro por referência
void lerNumeroReal(float *num) 
{
	printf("\tInforme um número REAL: ");
	scanf("%f", num);
}

// Lê um numero INT
// Usado a passagem de parâmetro por referência
void lerNumeroInt(int *num) 
{
	printf("\tInforme um número INTEIRO: ");
	scanf("%d", num);
}

// DOIS números reais
void lerDadosReal(float *n1, float *n2) {
	// Ler NUM 1
    printf("\n\tNÚMERO 1\n");
    lerNumeroReal(&*n1);

    // Ler NUM 2
    printf("\n\tNÚMERO 2\n");
    lerNumeroReal(n2);
}


// UM número real e OUTRO inteiro
void lerDadosRealInt(float * n1, int * n2) 
{
	// Ler NUM 1
	printf("\n\tNÚMERO 1\n");
	lerNumeroReal(&*n1);
	
	// Ler NUM 2
	printf("\n\tNÚMERO 2\n");
	lerNumeroInt(n2);
}

// O DIVISOR não pode ser ZERO
void lerDadosDivisao(float * n1, float * n2) 
{
    // Ler NUM 1
    printf("\n\tNÚMERO 1\n");
    lerNumeroReal(&*n1);

    do {
        // Ler NUM 2
        printf("\n\tNÚMERO 2\n");
        lerNumeroReal(n2);
    } while ( *n2 == 0);
}


// Calcula a multiplicação entre dois numeros
float multiplicacao(float x, float y) {

	int i, yInt;
	float soma, yDec;
	soma = 0;

	// Verificar sinal de Y
	if ( y > 0 ){
		yInt = floor(y);  // Pega a parte inteira de Y
		yDec = y - yInt;  // Pega a parte decimal de Y

		for (i = 1; i <= yInt; i++ ){
			soma = soma + x;   // POSITIVO ==> soma
		}

		return soma + (x / (1/yDec) ) ;   //Somando com a parte decimal de Y.

	} else if ( y < 0 ) {

		yInt = floor(y) + 1;  // Pega a parte inteira de Y
		yDec = y - yInt;  // Pega a parte decimal de Y

		for (i = -1; i >= yInt; i-- ){
			soma = soma - x;	// NEGATIVO ==> subtrai
		}

		return soma + (x / (1/yDec) ) ;   //Somando com a parte decimal de Y.

	} else {
		return 0;
	}

}

// Calcula X elevado e Y
float potencia(float x, int y) {

	int i;
	float mult;
	mult = 1;

	for (i = 1; i <= y; i++ ){
		mult = multiplicacao(mult,x);  // SIGNIFICA  mult = mult * x;
	}

	return mult;
}

int menu() {
    int opcao;
    do {
        printf("\n\n");
        printf("\t1 - Somar\n");
        printf("\t2 - Subtrair\n");
        printf("\t3 - Multiplicar\n");
        printf("\t4 - Dividir\n");
        printf("\t5 - Potência\n");
        printf("\t0 - Sair\n");
        printf("\tSua opção: ");
        scanf("%d", &opcao);
    } while (opcao < 0 && opcao > 5);
    
    return opcao;
}

int main() {

    float num1, num2, res;
    int opcao, expoente;

    do {
        opcao = menu();
        switch (opcao){
            case 0: break;  // SAIR

            case 1: // SOMAR
                    lerDadosReal(&num1, &num2);

                    printf("\n\n\tA SOMA entre %f e %f é: %f\n\n", num1, num2, num1 + num2);
                    break;

            case 2: // SUBTRAIR
                    lerDadosReal(&num1, &num2);

                    printf("\n\n\tA SUBTRACÃO entre %f e %f é: %f\n\n", num1, num2, num1 - num2);
                    break;

            case 3: // MULTIPLICAR
                    lerDadosReal(&num1, &num2);

                    res = multiplicacao(num1,num2);

                    printf("\n\n\tA MULTIPLICAÇÃO entre %f e %f é: %f\n\n", num1, num2, res);
                    break;

            case 4: // DIVISÃO
                    lerDadosDivisao(&num1, &num2);

                    printf("\n\n\tA DIVISÃO entre %f e %f é: %f\n\n", num1, num2, num1 / num2);
                    break;

            case 5: // POTENCIA
                    lerDadosRealInt(&num1, &expoente);

                    res = potencia(num1,expoente);

                    printf("\n\n\tA POTÊNCIA entre %f e %d é: %f\n\n", num1, expoente, res);
                    break;

            default:
                printf("\n\nOpção inválida!\n\n");
                break;

        }
        system("PAUSE");

    } while (opcao != 0);

    return 0;
}
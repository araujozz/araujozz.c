#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int CalculoDigitoVerificador(int cnpj[], int mult[], int N ){
    int soma = 0;
    for(int i=0; i<N; i++ ){
        soma += cnpj[i]*mult[i];
    }
    
    int resto = soma % 11;
        if (resto < 2){
         return 0;
       }
       else{
          return 11 - resto;
    }
    
}

int main()
{
    int cnpj[14];
    int mult1[12]={5,4,3,2,9,8,7,6,5,4,3,2};
    int mult2[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
    
    int i, j=0, tam;
	char entrada[50];
    printf("Entre com o CNPJ: ");
    gets(entrada);
    tam = strlen(entrada);
    for(i=0; i<tam; i++)
    {   if(entrada[i]>=48 && entrada[i]<=57)
        {   cnpj[j] = entrada[i]-48;
            j++;
        }
    }
    
    if(CalculoDigitoVerificador(cnpj,mult1,12) == cnpj [12] && 
    CalculoDigitoVerificador(cnpj,mult2,13) == cnpj[13]) 
    {
        printf("\nCNPJ valido!");
        
    }
    else{
        printf("\nCNPJ invalido!");
    }
    

    return 0;
}

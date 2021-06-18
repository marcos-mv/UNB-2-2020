// FEITO POR BRUNO E MARCOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparaArquivo( FILE *arq1, FILE *arq2, int tamanho );

int main(int argc, char **argv)
{
	// for(int a=0; a<argc; a++) {
    //     printf("%d argumento %s\n", a, argv[a]);
    // }
	int certo = 0;
	int incrementoArquivo = 1;
	int tamanhoArquivo = 0;
	int tamanhoArquivo2 = 0;

	for(int j=1; j<argc-1; j++){

	FILE *primeiroArquivo;
	primeiroArquivo=fopen(argv[j],"r");
	if(primeiroArquivo == NULL) {
		printf("O arquivo não abriu\n");
		return -1;
	}
	fseek( primeiroArquivo, 0, SEEK_END);
	tamanhoArquivo = ftell(primeiroArquivo);
	fseek( primeiroArquivo, 0 , SEEK_SET);
	fclose(primeiroArquivo);

	incrementoArquivo++;

		for(int m=incrementoArquivo; m<argc; m++) {

			FILE *segundoArquivo;
			segundoArquivo=fopen(argv[m],"r");
			if(segundoArquivo == NULL) {
				printf("O arquivo não abriu\n");
				return -1;
			}
			fseek( segundoArquivo, 0 ,SEEK_END);
			tamanhoArquivo2 = ftell(segundoArquivo);
			fseek( segundoArquivo, 0 , SEEK_SET);

			//printf("%d\n", tamanhoArquivo2);

			if (tamanhoArquivo == tamanhoArquivo2) {

			char arquivo2[tamanhoArquivo2];
			memset(arquivo2, 0, tamanhoArquivo2);
			fread(arquivo2, sizeof(arquivo2), 30, segundoArquivo);

			//printf("%s", arquivo2);

			certo = comparaArquivo(primeiroArquivo, segundoArquivo, tamanhoArquivo);

			//printf("%d\n", certo);

			if(certo == 1)
				printf("%s %s diferentes\n", argv[j], argv[m]);
			else 
				printf("%s %s iguais\n", argv[j], argv[m]);
			} else
				printf("%s %s diferentes\n", argv[j], argv[m]);

			fclose(segundoArquivo);	
		}
	};
	return 0;
}

int comparaArquivo( FILE *arq1, FILE *arq2, int tamanho ){
    int diferenca =0;
    char poschar1 = getc(arq1), poschar2 = getc(arq2);

    while ((poschar1!= EOF) && (poschar2 != EOF)){
        if (poschar1 != poschar2){
            diferenca++;
        }
        poschar1 = getc(arq1);
        poschar2 = getc(arq2);
    }  
    if(diferenca == 0){
        return 0;
    }
    else{
        return 1;
    }
}
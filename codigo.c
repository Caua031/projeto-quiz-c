#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "Perguntas.csv"
#define TAM 100

typedef struct{
    int id;
    char texto[250];
    char categoria[50];
    char curso[10];
    char resposta[4];
}Perguntas;

void novapergunta(){
    Perguntas a;
    FILE * arquivo;
    arquivo = fopen(ARQUIVO, "a");
    if (arquivo == NULL){ 
        perror("Erro ao abrir o arquivo"); /*Aula 8 exemplo 4*/
        return;
    }  
    printf("digite o ID: ");
    scanf("%d", &a.id);
    printf("Digite a pergunta: ");
    scanf(" %249[^\n]", a.texto);
    printf("Digite a categoria: ");
    scanf(" %49[^\n]", a.categoria);
    printf("Digite o curso: ");
    scanf(" %9[^\n]", a.curso);
    printf("Digite a resposta: ");
    scanf(" %3[^\n]", a.resposta);

    fprintf(arquivo, "%d;%s;%s;%s;%s\n", a.id, a.texto, a.categoria, a.curso, a.resposta);
    fclose(arquivo);
    printf("Pergunta salva com sucesso!\n");

}


int main(){
    novapergunta();

    return 0;
};

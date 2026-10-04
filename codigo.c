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


//Cadastro de nova pergunta - Henrick
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
//Consulta por Curso - Henrick
void consultaPorCurso(){
    char curso[4];
    Perguntas r;
    FILE * arquivo;
    arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL){ 
        perror("Erro ao abrir o arquivo"); /*Aula 8 exemplo 4*/
        return;
    }

    char linha[100];
    printf("Digite o curso: ");
    scanf(" %3[^\n]", curso);
    while (fgets(linha, 100, arquivo) != NULL){
        r.id = atoi(strtok(linha, ";")); //Explicar depois!!!!!!!!!!!!!
        strcpy(r.texto, strtok(NULL, ";"));
        strcpy(r.categoria, strtok(NULL, ";"));
        strcpy(r.curso, strtok(NULL, ";"));
        strcpy(r.resposta, strtok(NULL, ";"));

        if (strcmp(curso, r.curso)== 0){
        printf("ID: %d\n", r.id);
        printf("Pergunta: %s\n", r.texto);
        printf("Categoria: %s\n", r.categoria);
        printf("Curso: %s\n", r.curso);
        printf("Resposta: %s\n", r.resposta);
    
    ;
        }
    }
    fclose(arquivo);
}

//Atualização de pergunta - Raphael

//Exclusão de pergunta - Raphael
void excluirpergunta(){
    Perguntas lista[TAM];
    FILE * arquivo;
    char linha[400];
    int total = 0;
    int i;
    int id;
    int posicao = -1;

    arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }
    while (total < TAM && fgets(linha, sizeof(linha), arquivo) != NULL){
        if (sscanf(linha, "%d;%249[^;];%49[^;];%9[^;];%3[^\n]",
                   &lista[total].id, lista[total].texto, lista[total].categoria,
                   lista[total].curso, lista[total].resposta) == 5){
            total++;
        }
    }
    fclose(arquivo);

    printf("Digite o ID da pergunta que deseja excluir: ");
    scanf("%d", &id);
    for (i = 0; i < total; i++){
        if (lista[i].id == id){
            posicao = i;
        }
    }
    if (posicao == -1){
        printf("Pergunta nao encontrada!\n");
        return;
    }

    for (i = posicao; i < total - 1; i++){
        lista[i] = lista[i + 1];
    }
    total--;

    arquivo = fopen(ARQUIVO, "w");
    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }
    for (i = 0; i < total; i++){
        fprintf(arquivo, "%d;%s;%s;%s;%s\n", lista[i].id, lista[i].texto,
                lista[i].categoria, lista[i].curso, lista[i].resposta);
    }
    fclose(arquivo);
    printf("Pergunta excluida com sucesso!\n");
}


int main(){
    excluirpergunta();

    return 0;
}

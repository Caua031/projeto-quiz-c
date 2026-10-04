#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "Perguntas_2.csv"
#define TAM 520

typedef struct{
    int id;
    char texto[250];
    char categoria[50];
    char curso[10];
    char resposta[4];
}Perguntas;


//Cadastrar pergunta - Hnerick
void cadastrarpergunta(){
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

    printf("Categorias validas\nAlgoritmo\nDados\nTecnologia\nAprendizagem\nSistema\n");

    printf("Digite a categoria: ");
    scanf(" %49[^\n]", a.categoria);

    if (strcmp(a.categoria, "Algoritmo") != 0 && 
    strcmp(a.categoria, "Dados") != 0 && 
    strcmp(a.categoria, "Tecnologia") != 0 && 
    strcmp(a.categoria, "Aprendizagem") != 0 
    && strcmp(a.categoria, "Sistema") != 0){ // Um como comparador de string com nunmerios 
       
        printf("Categoria invalida!\n");
        fclose(arquivo);
        return;
    }

    printf("Digite o curso: ");
    scanf(" %9[^\n]", a.curso);

    printf("Cursos validos\nCC\nADS\nES\n");
        if (strcmp(a.curso, "CC") != 0 && 
        strcmp(a.curso, "ADS") != 0 && 
        strcmp(a.curso, "ES") != 0){

        printf("Curso invalido!\n");
        fclose(arquivo);
        return;
    }

    printf("Respostas validas - SIM/NAO\n");
    
    printf("Digite a resposta: ");
    scanf(" %3[^\n]", a.resposta);
    
    if (strcmp(a.resposta, "SIM") != 0 && 
    strcmp(a.resposta, "NAO") != 0){

        printf("Resposta invalida!\n");
        fclose(arquivo);
        return;
    }

    fprintf(arquivo, "%d;%s;%s;%s;%s\n", a.id, a.texto, a.categoria, a.curso, a.resposta);
    fclose(arquivo);
    printf("Pergunta salva com sucesso!\n");

}

//Consulta por curso - Hnerick
void consultaPorCurso(){
    char curso[4];
    int aux = 0; 
    Perguntas r;
    FILE * arquivo;
    arquivo = fopen(ARQUIVO, "r");

    if (arquivo == NULL){ 
        perror("Erro ao abrir o arquivo"); /*Aula 8 exemplo 4*/
        return;
    }

    char linha[TAM];

    printf("Digite o curso: ");
    scanf(" %3[^\n]", curso);

    if (strcmp(curso, "CC") != 0 && 
    strcmp(curso, "ADS") != 0 && 
    strcmp(curso, "ES") != 0   ){

        printf("Curso invalido!\n");
        fclose(arquivo);
        return;

    }

    while (fgets(linha, TAM, arquivo) != NULL){     
        r.id = atoi(strtok(linha, ";")); /*Explicar depois!!!!!!!!!!!!! ATOII*/
        strcpy(r.texto, strtok(NULL, ";"));
        strcpy(r.categoria, strtok(NULL, ";"));
        strcpy(r.curso, strtok(NULL, ";"));
        strcpy(r.resposta, strtok(NULL, ";"));

        if (strcmp(curso, r.curso)== 0){

        aux = 1;

        printf("ID: %d\n", r.id);
        printf("Pergunta: %s\n", r.texto);
        printf("Categoria: %s\n", r.categoria);
        printf("Curso: %s\n", r.curso);
        printf("Resposta: %s\n", r.resposta);
        
        ;
            
        }
       
        

    } if (aux == 0){
            printf("Nenhuma pergunta encontrada para o curso %s\n", curso);
        }fclose(arquivo);

}

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
    }while (total < TAM && fgets(linha, sizeof(linha), arquivo) != NULL){
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
    int op;

    do{
        system("cls"); /* Famoso limpa terminal */
        printf("\nGerenciador de QUIZ");
        printf("\n1 - Cadastrar pergunta");
        printf("\n2 - Listar perguntas");
        printf("\n3 - Consultar por categoria");
        printf("\n4 - Consultar por curso");
        printf("\n5 - Deletar pergunta");
        printf("\n6 - Atualizar pergunta");
        printf("\n0 - Sair");

        printf("\nEntre com a opcao desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                cadastrarpergunta();
                break;
            case 2:
                printf("Listar perguntas"); /*AJUSTAR DEPOIS QUE TIVER IMPLEMENTADO*/
                break;
            case 3:
                printf("Consultar por categoria"); /*AJUSTAR DEPOIS QUE TIVER IMPLEMENTADO*/
                break;
            case 4:
                consultaPorCurso();
                break;
            case 5:
                excluirpergunta();
                break;
            case 6:
                printf("Atualizar uma pergunta"); /*AJUSTAR DEPOIS QUE TIVER IMPLEMENTADO*/
                break;
            case 0:
                printf("Saindo...");
                break;
        }
        system("pause");
    } while(op != 0);

    return 0;
}

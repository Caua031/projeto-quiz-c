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

    printf("----------------------------------------\n");
    printf("digite o ID: ");
    scanf("%d", &a.id);

    printf("----------------------------------------\n");
    printf("Digite a pergunta: ");
    scanf(" %249[^\n]", a.texto);

    printf("----------------------------------------\n");
    printf("Categorias validas\nAlgoritmo\nDados\nTecnologia\nAprendizagem\nSistema\n");

    printf("----------------------------------------\n");
    printf("Digite a categoria: ");
    scanf(" %49[^\n]", a.categoria);

    if (strcasecmp(a.categoria, "Algoritmo") != 0 && 
    strcasecmp(a.categoria, "Dados") != 0 && 
    strcasecmp(a.categoria, "Tecnologia") != 0 && 
    strcasecmp(a.categoria, "Aprendizagem") != 0 
    && strcasecmp(a.categoria, "Sistema") != 0){ // Um como comparador de string com nunmerios 
       
        printf("Categoria invalida!\n");
        fclose(arquivo);
        return;
    }

    printf("----------------------------------------\n");
    printf("Cursos validos\nCC\nADS\nES\n");

    printf("----------------------------------------\n");
    printf("Digite o curso: ");
    scanf(" %9[^\n]", a.curso);

        if (strcasecmp(a.curso, "CC") != 0 && 
        strcasecmp(a.curso, "ADS") != 0 && 
        strcasecmp(a.curso, "ES") != 0){

        printf("Curso invalido!\n");
        fclose(arquivo);
        return;
    }

    printf("----------------------------------------\n");
    printf("Respostas validas - SIM/NAO\n");
    
    printf("----------------------------------------\n");
    printf("Digite a resposta: ");
    scanf(" %3[^\n]", a.resposta);
    
    if (strcasecmp(a.resposta, "SIM") != 0 && 
    strcasecmp(a.resposta, "NAO") != 0){

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

    printf("----------------------------------------\n");
    printf("Digite o curso: ");
    scanf(" %3[^\n]", curso);

    if (strcasecmp(curso, "CC") != 0 && 
    strcasecmp(curso, "ADS") != 0 && 
    strcasecmp(curso, "ES") != 0   ){

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

        if (strcasecmp(curso, r.curso)== 0){

        aux = 1;

        printf("----------------------------------------\n");
        printf("ID: %d\n", r.id);
        printf("Pergunta: %s\n", r.texto);
        printf("Categoria: %s\n", r.categoria);
        printf("Curso: %s\n", r.curso);
        printf("Resposta: %s\n", r.resposta);
        printf("----------------------------------------\n");
            
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

    printf("----------------------------------------\n");
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


//Atualizar pergunta - Raphael
void atualizarpergunta(){
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

    printf("----------------------------------------\n");
    printf("Digite o ID da pergunta que deseja atualizar: ");
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

    printf("----------------------------------------\n");
    printf("Pergunta atual: %s\n", lista[posicao].texto);
    printf("Digite a nova pergunta: ");
    scanf(" %249[^\n]", lista[posicao].texto);

    printf("----------------------------------------\n");
    printf("Categorias validas\nAlgoritmo\nDados\nTecnologia\nAprendizagem\nSistema\n");
    printf("----------------------------------------\n");
    printf("Digite a nova categoria: ");
    scanf(" %49[^\n]", lista[posicao].categoria);
    if (strcasecmp(lista[posicao].categoria, "Algoritmo") != 0 &&
        strcasecmp(lista[posicao].categoria, "Dados") != 0 &&
        strcasecmp(lista[posicao].categoria, "Tecnologia") != 0 &&
        strcasecmp(lista[posicao].categoria, "Aprendizagem") != 0 &&
        strcasecmp(lista[posicao].categoria, "Sistema") != 0){
        printf("Categoria invalida! Nada foi alterado.\n");
        return;
    }

    printf("----------------------------------------\n");
    printf("Cursos validos\nCC\nADS\nES\n");
    printf("Digite o novo curso: ");
    scanf(" %9[^\n]", lista[posicao].curso);
    if (strcasecmp(lista[posicao].curso, "CC") != 0 &&
        strcasecmp(lista[posicao].curso, "ADS") != 0 &&
        strcasecmp(lista[posicao].curso, "ES") != 0){
        printf("Curso invalido! Nada foi alterado.\n");
        return;
    }

    printf("----------------------------------------\n");
    printf("Respostas validas - SIM/NAO\n");
    printf("----------------------------------------\n");
    printf("Digite a nova resposta: ");
    scanf(" %3[^\n]", lista[posicao].resposta);
    if (strcasecmp(lista[posicao].resposta, "SIM") != 0 &&
        strcasecmp(lista[posicao].resposta, "NAO") != 0){
        printf("Resposta invalida! Nada foi alterado.\n");
        return;
    }

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
    printf("Pergunta atualizada com sucesso!\n");
}


//listar Perguntas --Cauã Diego
void listarPerguntas(){
    Perguntas a;
    FILE * arquivo;
    arquivo = fopen(ARQUIVO, "r");
    char linha[TAM]; // Variável para guardar a linha

    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }

    while (fgets(linha, TAM, arquivo) != NULL) {
        // 1. Corta o ID (texto) e converte para número inteiro com atoi
        a.id = atoi(strtok(linha, ";"));
        
        // 2. Corta as próximas partes e copia para a struct usando strcpy
        strcpy(a.texto, strtok(NULL, ";"));
        strcpy(a.categoria, strtok(NULL, ";"));
        strcpy(a.curso, strtok(NULL, ";"));
        strcpy(a.resposta, strtok(NULL, ";"));

        // 3. Mostra a pergunta formatada
        printf("----------------------------------------\n");
        printf("ID: %d\n", a.id);
        printf("Pergunta: %s\n", a.texto);
        printf("Categoria: %s\n", a.categoria);
        printf("Curso: %s\n", a.curso);
        printf("Resposta: %s\n", a.resposta);
    }

    fclose(arquivo);
}

//Consultar Categorias --Cauã Diego
void consultarPorCategoria(){
    char categoria[50];
    char linha[TAM];
    int aux = 0;

    Perguntas r;
    FILE * arquivo;
    arquivo = fopen(ARQUIVO, "r");

    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Mostra as opções para ajudar o usuário
    printf("----------------------------------------\n");
    printf("Categorias validas:\nAlgoritmo\nDados\nTecnologia\nAprendizagem\nSistema\n");
    printf("----------------------------------------\n");
    printf("Digite a categoria: ");
    scanf(" %49[^\n]", categoria);

    // Validação: Se não for nenhuma das 5, cancela
    if (strcasecmp(categoria, "Algoritmo") != 0 && 
        strcasecmp(categoria, "Dados") != 0 && 
        strcasecmp(categoria, "Tecnologia") != 0 && 
        strcasecmp(categoria, "Aprendizagem") != 0 && 
        strcasecmp(categoria, "Sistema") != 0) {
        
        printf("Categoria invalida!\n");
        fclose(arquivo);
        return;
    }

    // Loop para ler o arquivo linha por linha
    while (fgets(linha, TAM, arquivo) != NULL){     
        // Fatia os dados da linha atual
        r.id = atoi(strtok(linha, ";"));
        strcpy(r.texto, strtok(NULL, ";"));
        strcpy(r.categoria, strtok(NULL, ";"));
        strcpy(r.curso, strtok(NULL, ";"));
        strcpy(r.resposta, strtok(NULL, ";"));

        // Compara se a categoria da pergunta é a mesma que o usuário digitou
        if (strcasecmp(categoria, r.categoria) == 0){
            aux = 1; // Encontrou pelo menos uma

            printf("----------------------------------------\n");
            printf("ID: %d\n", r.id);
            printf("Pergunta: %s\n", r.texto);
            printf("Categoria: %s\n", r.categoria);
            printf("Curso: %s\n", r.curso);
            printf("Resposta: %s\n", r.resposta);
        }
    } 

    // Se saiu do loop e aux continua 0, nenhuma pergunta foi achada
    if (aux == 0){
        printf("Nenhuma pergunta encontrada para a categoria %s\n", categoria);
    }

    fclose(arquivo);
}


int main(){
    int op;

    do{
        system("cls"); /* Famoso limpa terminal */
        printf("-------Gerenciador de QUIZ-------\n");
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
                listarPerguntas();
                break;
            case 3:
               consultarPorCategoria();
                break;
            case 4:
                consultaPorCurso();
                break;
            case 5:
                excluirpergunta();
                break;
            case 6:
                atualizarpergunta();
                break;
            case 0:
                printf("Saindo...");
                break;
        }
        system("pause");
    } while(op != 0);

    return 0;
}

# Gerenciador de Quiz em C

Projeto desenvolvido em linguagem C para a disciplina da faculdade, com o objetivo de criar um sistema de gerenciamento de perguntas de um quiz por meio de um menu interativo no terminal.

O programa permite cadastrar, listar, consultar, atualizar e excluir perguntas armazenadas em um arquivo CSV.

## Objetivo do projeto

O projeto foi desenvolvido para praticar conceitos fundamentais da linguagem C e de manipulação de arquivos, estruturas e dados. Entre os principais conceitos utilizados estão:

- `struct` para organizar os dados das perguntas;
- funções para separar as diferentes operações do sistema;
- manipulação de arquivos com `fopen`, `fgets` e `fprintf`;
- leitura e tratamento de strings;
- uso de `strtok` para separar os campos do arquivo;
- conversão de texto para número com `atoi`;
- estruturas de repetição e decisão;
- validação das informações digitadas pelo usuário.

## Funcionalidades

O sistema possui as seguintes opções:

| Opção | Funcionalidade | Descrição |
|---|---|---|
| 1 | Cadastrar pergunta | Adiciona uma nova pergunta ao arquivo de dados. |
| 2 | Listar perguntas | Exibe todas as perguntas cadastradas. |
| 3 | Consultar por categoria | Filtra as perguntas de acordo com a categoria informada. |
| 4 | Consultar por curso | Filtra as perguntas de acordo com o curso informado. |
| 5 | Deletar pergunta | Remove uma pergunta utilizando seu ID. |
| 6 | Atualizar pergunta | Altera os dados de uma pergunta existente. |
| 0 | Sair | Encerra o programa. |

## Estrutura dos dados

As informações de cada pergunta são armazenadas por meio da `struct Perguntas`:

```c
typedef struct{
    int id;
    char texto[250];
    char categoria[50];
    char curso[10];
    char resposta[4];
} Perguntas;
```

Cada registro possui:

- **ID:** identificador da pergunta;
- **Texto:** pergunta apresentada ao usuário;
- **Categoria:** classificação da pergunta;
- **Curso:** curso relacionado à pergunta;
- **Resposta:** resposta esperada (`SIM` ou `NAO`).

## Formato do arquivo

Os dados são armazenados em um arquivo CSV utilizando `;` como separador entre os campos.

Exemplo:

```text
1;Voce gosta de resolver problemas de logica?;Raciocinio;CC;SIM
2;Voce se interessa por entender como os computadores funcionam?;Interesse;CC;SIM
```

A ordem dos campos é:

```text
ID;Pergunta;Categoria;Curso;Resposta
```

## Tecnologias utilizadas

- **C**
- **GCC** ou outro compilador compatível com C
- **Arquivo CSV** para armazenamento dos dados
- **Terminal/Prompt de Comando** para execução

## Como utilizar

Ao iniciar o programa, será apresentado um menu semelhante a:

```text
-------Gerenciador de QUIZ-------

1 - Cadastrar pergunta
2 - Listar perguntas
3 - Consultar por categoria
4 - Consultar por curso
5 - Deletar pergunta
6 - Atualizar pergunta
0 - Sair

Entre com a opcao desejada:
```

Basta informar o número da opção desejada e seguir as instruções exibidas no terminal.

### Exemplo de cadastro

Ao escolher a opção `1`, o sistema solicita:

```text
Digite o ID: 31
Digite a pergunta: Voce gosta de programar em C?
Digite a categoria: Tecnologia
Digite o curso: CC
Digite a resposta: SIM
```

Após validar os dados, a pergunta é adicionada ao arquivo.

## Validações

O sistema possui algumas validações para evitar registros fora do padrão definido pelo projeto.

### Categorias aceitas

- Algoritmo
- Dados
- Tecnologia
- Aprendizagem
- Sistema

### Cursos aceitos

- CC
- ADS
- ES

### Respostas aceitas

- SIM
- NAO

Caso seja informado um valor inválido, a operação é interrompida e uma mensagem de erro é apresentada.

## Organização do projeto

```text
projeto-quiz-c-main/
├── codigo.c
├── Perguntas.csv
└── README.md
```

## Conceitos de programação utilizados

O projeto reúne diversos conceitos estudados em programação em C, como:

**Estruturas (`struct`)**  
Utilizadas para representar uma pergunta com diferentes tipos de informação.

**Funções**  
Cada operação do sistema foi separada em uma função, como `cadastrarpergunta`, `listarPerguntas`, `consultarPorCategoria`, `consultaPorCurso`, `excluirpergunta` e `atualizarpergunta`.

**Manipulação de arquivos**  
Os dados são gravados e lidos de um arquivo utilizando funções da biblioteca `stdio.h`.

**Strings**  
A biblioteca `string.h` é utilizada para copiar e comparar textos, além de dividir os campos das linhas do arquivo.

**Estruturas de repetição**  
O sistema utiliza laços como `while`, `for` e `do...while` para percorrer registros e manter o menu funcionando até que o usuário escolha sair.

**Estruturas condicionais**  
São utilizadas instruções `if` e `switch` para realizar validações e direcionar as opções escolhidas no menu.

## Autores

Projeto acadêmico desenvolvido por:

- Cauã Diego
- Henrique
- Raphael

- ## Vídeo do projeto

[▶️ Assistir ao vídeo de apresentação]([https://youtu.be/k69ByjOWsPU?si=xnRV_1avD7DX46Qk])


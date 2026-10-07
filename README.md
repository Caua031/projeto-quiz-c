# 🎓 Gerenciador de Quiz Vocacional (C)

Projeto da **Aula 08** (manipulação de arquivos em C): um sistema de console para **gerenciar o banco de perguntas** de um quiz que ajuda o aluno a descobrir com qual curso de tecnologia ele mais se identifica: **CC**, **ES** ou **ADS**.

As perguntas ficam salvas em um arquivo `.csv`, e o programa permite cadastrar, listar, consultar, atualizar e excluir perguntas direto pelo terminal.

---

## 🎥 Vídeo de apresentação

▶️ **[ASSISTIR AO VÍDEO](https://www.youtube.com/watch?v=k69ByjOWsPU)**

---

## 👥 Integrantes

| Integrante | Funcionalidades desenvolvidas |
|---|---|
| **Cauã Diego** | Listar perguntas · Consultar por categoria |
| **Hnerick** | Cadastrar pergunta · Consultar por curso |
| **Raphael** | Atualizar pergunta · Excluir pergunta |

> Disciplina: **NOME DA DISCIPLINA** · Professora: **NOME DA PROFESSORA** · Curso/Turma: **CURSO / TURMA**

---

## ✨ Funcionalidades

| Opção | Função | O que faz |
|:---:|---|---|
| 1 | `cadastrarpergunta()` | Adiciona uma nova pergunta ao final do arquivo, validando categoria, curso e resposta |
| 2 | `listarPerguntas()` | Exibe todas as perguntas cadastradas |
| 3 | `consultarPorCategoria()` | Mostra apenas as perguntas de uma categoria |
| 4 | `consultaPorCurso()` | Mostra apenas as perguntas de um curso |
| 5 | `excluirpergunta()` | Remove uma pergunta a partir do ID |
| 6 | `atualizarpergunta()` | Altera texto, categoria, curso e resposta de uma pergunta a partir do ID |
| 0 | — | Encerra o programa |

---

## 🗂️ Estrutura do projeto

```
projeto-quiz-c/
├── codigo.c        # código-fonte do programa
├── Perguntas.csv   # banco de dados com 30 perguntas (10 por curso)
└── README.md       # este arquivo
```

---

## 📄 Formato dos dados

Cada linha do `Perguntas.csv` é uma pergunta, com os campos separados por **ponto e vírgula (`;`)**:

```
id;texto;categoria;curso;resposta
```

Exemplo:

```
1;Voce gosta de resolver problemas de logica?;Raciocinio;CC;SIM
```

| Campo | Descrição |
|---|---|
| `id` | Número inteiro que identifica a pergunta |
| `texto` | Enunciado da pergunta (até 249 caracteres) |
| `categoria` | Tema da pergunta |
| `curso` | Curso ao qual a pergunta se relaciona: `CC`, `ES` ou `ADS` |
| `resposta` | Resposta que indica afinidade com o curso: `SIM` ou `NAO` |

### Valores aceitos ao cadastrar, atualizar ou consultar

- **Categorias:** `Algoritmo`, `Dados`, `Tecnologia`, `Aprendizagem`, `Sistema`
- **Cursos:** `CC`, `ADS`, `ES`
- **Respostas:** `SIM`, `NAO`

A comparação não diferencia maiúsculas de minúsculas (`dados` = `Dados`). Se o valor for inválido, a operação é cancelada.

---

## 🖥️ Exemplo de uso

```
-------Gerenciador de QUIZ-------

1 - Cadastrar pergunta
2 - Listar perguntas
3 - Consultar por categoria
4 - Consultar por curso
5 - Deletar pergunta
6 - Atualizar pergunta
0 - Sair
Entre com a opcao desejada: 2
----------------------------------------
ID: 1
Pergunta: Voce gosta de resolver problemas de logica?
Categoria: Raciocinio
Curso: CC
Resposta: SIM
```

---

## 📚 Conceitos aplicados (Aula 08)

- **Manipulação de arquivos:** `fopen` (modos `"r"`, `"a"` e `"w"`), `fclose`, `fgets` e `fprintf`
- **Tratamento de erros:** `perror` quando o arquivo não pode ser aberto
- **Processamento de texto:** `strtok`, `sscanf`, `atoi`, `strcpy` e `strcasecmp`
- **Estruturas (`struct`):** o tipo `Perguntas` agrupa os dados de cada pergunta
- **Modularização:** uma função para cada operação, chamadas por um menu com `switch`
- **Validação de entrada:** categoria, curso e resposta são conferidos antes de salvar

---

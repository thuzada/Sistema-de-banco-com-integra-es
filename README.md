# Sistema Bancário em C

Este projeto é um sistema bancário simples desenvolvido em C que simula operações bancárias como criação de conta, depósitos, saques, transferências e geração de relatórios. O sistema é projetado para ser modular e fácil de expandir.

## Funcionalidades

- **Criar Conta**: Permite criar uma nova conta bancária com saldo inicial.
- **Listar Contas**: Exibe todas as contas criadas até o momento.
- **Depósito**: Permite realizar um depósito em uma conta específica.
- **Saque**: Realiza um saque de uma conta, verificando saldo suficiente.
- **Transferência**: Realiza uma transferência entre duas contas.
- **Relatórios**:
  - **Relatório Simples**: Exibe o saldo de todas as contas.
  - **Relatório Detalhado**: Exibe um histórico completo de transações.

## Estrutura do Projeto

O projeto é dividido em vários módulos para maior organização e facilidade de manutenção:

- **main.c**: Arquivo principal que contém o menu e chama as funções das outras partes do sistema.
- **conta.c** / **conta.h**: Define a estrutura da conta bancária e suas operações.
- **operacoes.c** / **operacoes.h**: Contém funções para operações bancárias como depósito, saque e transferência.
- **persistencia.c** / **persistencia.h**: Funções responsáveis pela leitura e gravação de dados das contas em arquivos.
- **relatorios.c** / **relatorios.h**: Funções para gerar relatórios simples e detalhados.

## Pré-requisitos

- Sistema operacional com compilador C (por exemplo, GCC no Linux ou MinGW no Windows).
- Nenhuma dependência externa.

## Compilação

Para compilar o projeto, execute o seguinte comando no terminal (dentro da pasta do projeto):

```bash
gcc main.c conta.c operacoes.c relatorios.c persistencia.c -o Banco

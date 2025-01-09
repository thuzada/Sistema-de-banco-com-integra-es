#include <stdio.h>
#include <stdlib.h>
#include "../include/conta.h"
#include "../include/operacoes.h"
#include "../include/database.h"
#include "../include/relatorios.h"
#define MAX_CONTAS 100

int main() {
    Conta contas[MAX_CONTAS];
    int numContas = 0;
    int opcao;
    sqlite3 *db;

    // Abrir o banco de dados
    if (!abrirBancoDados(&db)) {
        return 1;
    }

    // Carregar os dados das contas do banco de dados
    if (!carregarDadosBD(contas, &numContas, db)) {
        fprintf(stderr, "Erro ao carregar dados das contas.\n");
        fecharBancoDados(db);
        return 1;
    }

    do {
        printf("\n--- Menu ---\n");
        printf("1. Criar Conta\n");
        printf("2. Listar Contas\n");
        printf("3. Depósito\n");
        printf("4. Saque\n");
        printf("5. Relatório Simples\n");
        printf("6. Relatório Detalhado\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                criarConta(contas, &numContas, db);
                break;
            case 2:
                listarContas(contas, numContas);
                break;
            case 3:
                depositar(contas, numContas, db);
                break;
            case 4:
                sacar(contas, numContas, db);
                break;
            case 5:
                exibirRelatorioSimples(contas, numContas);
                break;
            case 6:
                exibirRelatorioDetalhado(contas, numContas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    // Fechar o banco de dados
    fecharBancoDados(db);

    return 0;
}
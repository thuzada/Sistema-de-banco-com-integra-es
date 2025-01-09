#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include "../include/operacoes.h"

void depositar(Conta contas[], int numContas, sqlite3 *db) {
    int id;
    double valor;
    char senha[50];
    char sql[256];
    char *errMsg = 0;

    printf("Digite o ID da conta: ");
    scanf("%d", &id);
    getchar(); // Limpar o buffer do teclado
    if (id <= 0 || id > numContas) {
        printf("Conta inválida.\n");
        return;
    }

    printf("Digite a senha da conta: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = 0; // Remove o newline

    // Verificar a senha
    if (strcmp(contas[id - 1].senha, senha) != 0) {
        printf("Senha incorreta.\n");
        return;
    }

    printf("Digite o valor a depositar: ");
    scanf("%lf", &valor);
    if (valor <= 0) {
        printf("Valor inválido.\n");
        return;
    }

    contas[id - 1].saldo += valor;
    snprintf(sql, sizeof(sql), "UPDATE contas SET saldo = %f WHERE id = %d;", contas[id - 1].saldo, id);
    if (sqlite3_exec(db, sql, NULL, NULL, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "Erro ao atualizar saldo: %s\n", errMsg);
        sqlite3_free(errMsg);
        return;
    }

    printf("Depósito realizado com sucesso! Novo saldo: %.2f\n", contas[id - 1].saldo);
}

void sacar(Conta contas[], int numContas, sqlite3 *db) {
    int id;
    double valor;
    char senha[50];
    char sql[256];
    char *errMsg = 0;

    printf("Digite o ID da conta: ");
    scanf("%d", &id);
    getchar(); // Limpar o buffer do teclado
    if (id <= 0 || id > numContas) {
        printf("Conta inválida.\n");
        return;
    }

    printf("Digite a senha da conta: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = 0; // Remove o newline

    // Verificar a senha
    if (strcmp(contas[id - 1].senha, senha) != 0) {
        printf("Senha incorreta.\n");
        return;
    }

    printf("Digite o valor a sacar: ");
    scanf("%lf", &valor);
    if (valor <= 0 || valor > contas[id - 1].saldo) {
        printf("Valor inválido.\n");
        return;
    }

    contas[id - 1].saldo -= valor;
    snprintf(sql, sizeof(sql), "UPDATE contas SET saldo = %f WHERE id = %d;", contas[id - 1].saldo, id);
    if (sqlite3_exec(db, sql, NULL, NULL, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "Erro ao atualizar saldo: %s\n", errMsg);
        sqlite3_free(errMsg);
        return;
    }

    printf("Saque realizado com sucesso! Novo saldo: %.2f\n", contas[id - 1].saldo);
}
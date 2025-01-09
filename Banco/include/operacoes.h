#ifndef OPERACOES_H
#define OPERACOES_H

#include "conta.h"
#include "../libs/sqlite3.h"

void depositar(Conta contas[], int numContas, sqlite3 *db);
void sacar(Conta contas[], int numContas, sqlite3 *db);
void transferir(Conta contas[], int numContas, sqlite3 *db);

#endif // OPERACOES_H
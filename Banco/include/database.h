#ifndef DATABASE_H
#define DATABASE_H

#include "../libs/sqlite3.h"
#include "conta.h"

int abrirBancoDados(sqlite3 **db);
int fecharBancoDados(sqlite3 *db);
int carregarDadosBD(Conta contas[], int *numContas, sqlite3 *db);
int salvarDadosBD(Conta contas[], int numContas, sqlite3 *db);

#endif // DATABASE_H
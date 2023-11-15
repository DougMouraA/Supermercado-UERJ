#ifndef SUPERMERCADO_H
# define SUPERMERCADO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cliente
{
    char codigoCl[10];
    char razaoSoc[40];
    char cnpj[19];
    char inscEst[15];
    char endereco[25];
    char tel[12];
    char email[20];
}               t_cliente;

typedef struct produto
{
    char codigoPdt[10];
    char produto[40];
    float preco;
}               t_pdt;

typedef struct pedido
{
    char numPedido[10];
    t_pdt codigoPdt[10];
    t_cliente codigoCl[10];
    int qtd;
    float total;
    char data[11];
};




#endif
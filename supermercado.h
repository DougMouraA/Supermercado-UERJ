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
    char codigoPdt[10];
    char codigoCl[10];
    int qtd;
    float total;
    char data[11];
}                  t_pedido;

// Produto
t_pdt *inserirProduto(t_pdt tabela[], int tamPdt);
void *removerProduto(t_pdt tabela[], char *codigo, int tamPdt);
float localizarProduto(t_pdt tabela[], int tamPdt, char *codigo);
void modificarProduto(t_pdt tabela[], int tamPdt, char *codigo);
void listarTabela(t_pdt tabela[], int tamPdt);
void salvarProdutos(t_pdt tabela[], int tamPdt);
int compararProdutos(const void *a, const void *b) ;
void ordenarProdutos(t_pdt *produtos, int numProdutos);

// Cliente
t_cliente *adicionarCliente(t_cliente bancoC[], int tamC);
void salvarCliente(t_cliente bancoC[], int tamC);

// Pedido
t_pedido *pedido(t_pdt tabela[], t_cliente bancoC[],t_pedido pedidos[] ,int tamC,\
int tamPdt, int tamPedido);
void notaFiscal(t_pdt tabela[], t_cliente bancoC[],t_pedido pedidos[] ,int tamC,\
int tamPdt, int tamPedido, char *codigoC, char *codigoPdt);
void totalVendas(t_pedido pedidos[], int tamPedido, char *data);
int aDataEValida(char *data);
void salvarPedido(t_pedido pedido[], int tamPedido);


#endif
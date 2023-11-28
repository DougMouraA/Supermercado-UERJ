#include "supermercado.h"

t_cliente *adicionarCliente(t_cliente bancoC[], int tamC)
{
    if (tamC < 15)
    {
        printf("Codigo do cliente: \n");
        scanf(" %10[^\n]", bancoC[tamC].codigoCl);
        printf("Razao Social: \n");
        scanf(" %40[^\n]", bancoC[tamC].razaoSoc);
        printf("CNPJ: \n");
        scanf(" %19[^\n]", bancoC[tamC].cnpj);
        printf("Inscricao Estadual (Se nao houver, insira ISENTO): \n");
        scanf(" %15[^\n]", bancoC[tamC].inscEst);
        printf("Endereco: \n");
        scanf(" %25[^\n]", bancoC[tamC].endereco);
        printf("Telefone: \n");
        scanf(" %12[^\n]", bancoC[tamC].tel);
        printf("E-ail: \n");
        scanf(" %20[^\n]", bancoC[tamC].email);
    }
    else
    {
        bancoC = realloc(bancoC, (tamC + 1) * sizeof(t_cliente));
        if (bancoC == NULL)
        {
            printf("Erro ao realocar memoria\n");
            return (NULL);
        }
        printf("Codigo do cliente: \n");
        scanf(" %10[^\n]", bancoC[tamC].codigoCl);
        printf("Razao Social: \n");
        scanf(" %40[^\n]", bancoC[tamC].razaoSoc);
        printf("CNPJ: \n");
        scanf(" %19[^\n]", bancoC[tamC].cnpj);
        printf("Inscricao Estadual (Se nao houver, insira ISENTO): \n");
        scanf(" %15[^\n]", bancoC[tamC].inscEst);
        printf("Endereco: \n");
        scanf(" %25[^\n]", bancoC[tamC].endereco);
        printf("Telefone: \n");
        scanf(" %12[^\n]", bancoC[tamC].tel);
        printf("E-ail: \n");
        scanf(" %20[^\n]", bancoC[tamC].email);
    }
    return (bancoC);
}

void salvarCliente(t_cliente bancoC[], int tamC)
{
    FILE *arquivo = fopen("clientes.bin", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for(int i = 0; i < tamC; i++)
    {
        fwrite(&bancoC[i], sizeof(t_cliente), 1, arquivo);
    }   
    fclose(arquivo);
}
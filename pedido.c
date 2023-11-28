#include "supermercado.h"
#include <time.h>

int aDataEValida(char *data)
{
    struct tm tmUsuario = {0}, tmAtual = {0};
    time_t tUsuario, tAtual;

    sscanf(data, "%d/%d/%d", &tmUsuario.tm_mday, &tmUsuario.tm_mon, &tmUsuario.tm_year);
    tmUsuario.tm_year -= 1900;
    tmUsuario.tm_mon -= 1; 

    time_t agora = time(NULL);
    struct tm *tmAgora = localtime(&agora);
    tmAtual.tm_year = tmAgora->tm_year;
    tmAtual.tm_mon = tmAgora->tm_mon;
    tmAtual.tm_mday = tmAgora->tm_mday;

    tUsuario = mktime(&tmUsuario);
    tAtual = mktime(&tmAtual);

    if (difftime(tUsuario, tAtual) < 0) {
        return 1;
    } else {
        return 0;
    }
}

t_pedido *pedido(t_pdt tabela[], t_cliente bancoC[],t_pedido pedidos[] ,int tamC,\
int tamPdt, int tamPedido)
{
    if (tamC == 0 || tamPdt == 0)
        printf("Nao ha produtos ou clientes cadastrados!\n");
    else
    {
        if (tamPedido < 15)
        {
            printf("Digite o numero do pedido : \n");
            scanf(" %10[^\n]", pedidos[tamPedido].numPedido);
            printf("Digite o codigo do produto : \n");
            scanf(" %10[^\n]", pedidos[tamPedido].codigoPdt);
            printf("Digite o codigo do cliente : \n");
            scanf(" %10[^\n]", pedidos[tamPedido].codigoCl);
            printf("Quantidade do produto: \n");
            scanf(" %d", &pedidos[tamPedido].qtd);
            pedidos[tamPedido].total = localizarProduto(tabela, tamPdt, pedidos[tamPedido].codigoPdt) * pedidos[tamPedido].qtd;
            printf("Digite a data do pedido (formato: dd/mm/aaaa): \n");
            scanf(" %10[^\n]", pedidos[tamPedido].data);
            if (!aDataEValida(pedidos[tamPedido].data))
            {
                printf("Data iformada invalida, insira uma data anterior a data atual: \n");
                scanf(" %10[^\n]", pedidos[tamPedido].data);
            }
        }
        else
        {
            pedidos = realloc(pedidos, (tamPedido + 1) * sizeof(t_pedido));
            printf("Digite o numero do pedido : \n");
            scanf(" %10[^\n]", pedidos[tamPedido].numPedido);
            printf("Digite o codigo do produto : \n");
            scanf(" %10[^\n]", pedidos[tamPedido].codigoPdt);
            printf("Digite o codigo do cliente : \n");
            scanf(" %10[^\n]", pedidos[tamPedido].codigoCl);
            printf("Quantidade do produto: \n");
            scanf(" %d", &pedidos[tamPedido].qtd);
            pedidos[tamPedido].total = localizarProduto(tabela, tamPdt, pedidos[tamPedido].codigoPdt) * pedidos[tamPedido].qtd;
            printf("Digite a data do pedido (formato: dd/mm/aaaa): \n");
            scanf(" %10[^\n]", pedidos[tamPedido].data);
            if (!aDataEValida(pedidos[tamPedido].data))
            {
                printf("Data iformada invalida, insira uma data anterior a data atual: \n");
                scanf(" %10[^\n]", pedidos[tamPedido].data);
            }
        }
        notaFiscal(tabela, bancoC, pedidos, tamC, tamPdt, tamPedido, \
        pedidos[tamPedido].codigoCl, pedidos[tamPedido].codigoPdt);
        return (pedidos);
    }
    return(pedidos);
}

void notaFiscal(t_pdt tabela[], t_cliente bancoC[],t_pedido pedidos[] ,int tamC,\
int tamPdt, int tamPedido, char *codigoC, char *codigoPdt)
{
    int pos = 0;
    int posPdt = 0;
    for (int i = 0; i < tamC; i++)
    {
        if (strcmp(bancoC[i].codigoCl, codigoC) == 0)
        {
            pos = i;
            break;
        }
    }

    for (int i = 0; i < tamPdt; i++)
    {
        if (strcmp(tabela[i].codigoPdt, codigoPdt) == 0)
        {
            posPdt = i;
            break;
        }
    }
    
    printf("Nota Fiscal\n");
    printf("Numero do Pedido: %s\n", pedidos[tamPedido].numPedido);
    printf("Codigo do Cliente: %s\n", bancoC[pos].codigoCl);
    printf("Razao Social: %s\n", bancoC[pos].razaoSoc);
    printf("CNPJ: %s\n", bancoC[pos].cnpj);
    printf("Inscricao Estadual: %s\n", bancoC[pos].inscEst);
    printf("Endereco: %s\n", bancoC[pos].endereco);
    printf("Telefone: %s\n", bancoC[pos].tel);
    printf("E-mail: %s\n", bancoC[pos].email);
    printf("Codigo do Produto: %s\n", tabela[posPdt].codigoPdt);
    printf("Nome do Produto: %s\n", tabela[posPdt].produto);
    printf("Valor Unidade: %.2f\n", tabela[posPdt].preco);
    printf("Quantidade: %d\n", pedidos[tamPedido].qtd);
    printf("Total: %.2f\n", pedidos[tamPedido].total);
    printf("Data: %s\n", pedidos[tamPedido].data);
}

void totalVendas(t_pedido pedidos[], int tamPedido, char *data)
{
    float total = 0;
    int totalQtd = 0;
    for (int i = 0; i < tamPedido; i++)
    {
        if (strcmp(pedidos[i].data, data) == 0)
        {
            total += pedidos[i].total;
            totalQtd += pedidos[i].qtd;
        }
    }
    printf("Na data %s foram vendidos %d iten e o valor arreacadado foi de R$%.2f.\n", data, totalQtd, total);
}

void salvarPedido(t_pedido pedido[], int tamPedido)
{
    FILE *arquivo = fopen("pedidos.bin", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for(int i = 0; i < tamPedido; i++)
    {
        fwrite(&pedido[i], sizeof(t_pedido), 1, arquivo);
    }   
    fclose(arquivo);
}

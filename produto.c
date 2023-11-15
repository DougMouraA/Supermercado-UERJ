#include "supermercado.h"

t_pdt *inserirProduto(FILE *arquivoProduto, t_pdt tabela[], int tam)
{
    if (tam < 15)
    {
        printf("Codigo do Produto: ");
        scanf(" %9[^\n]%s", tabela[tam].codigoPdt);
        printf("Nome do Produto: ");
        scanf(" %39[^\n]%s", tabela[tam].produto);
        printf("Preco: ");
        scanf(" %.2f", tabela[tam].preco);
    }
    else
    {
        tabela = realloc(tabela, (tam + 1) * sizeof(t_pdt));
        if (tabela == NULL)
        {
            printf("Erro ao realocar memoria\n");
            return;
        }
        printf("Codigo do Produto: ");
        scanf(" %9[^\n]%s", tabela[tam].codigoPdt);
        printf("Nome do Produto: ");
        scanf(" %39[^\n]%s", tabela[tam].produto);
        printf("Preco: ");
        scanf(" %.2f", tabela[tam].preco);
    }
    fwrite(tabela, sizeof(t_pdt), tam, arquivoProduto);
    return tabela;
}

void *removerProduto(t_pdt tabela[], char *codigo, int tam)
{
    int pos = 0;
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(tabela[i].codigoPdt, codigo) == 0)
            pos = i;
    }

    for (int i = pos; i < tam - 1; i++)
    {
        strcpy(tabela[i].codigoPdt, tabela[i+1].codigoPdt);
        strcpy(tabela[i].produto, tabela[i+1].produto);
        tabela[i].preco = tabela[i+1].preco;
    }
    return tabela;
}

void localizarProduto(t_pdt tabela[], int tam, char *codigo)
{
    int pos = 0;
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(tabela[i].codigoPdt, codigo) == 0)
        {
            pos = i;
            break;
        }
    }

    printf("Codigo do Produto: %s\n", tabela[pos].codigoPdt);
    printf("Codigo do Produto: %s\n", tabela[pos].produto);
    printf("Codigo do Produto: %.2f\n", tabela[pos].preco);
}

void modificarProduto(t_pdt tabela[], int tam, char *codigo)
{
    int pos = 0;
    int escolha;
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(tabela[i].codigoPdt, codigo) == 0)
        {
            pos = i;
            break;
        }
    }
    printf("1 - Modificar o codigo do prodto\n\
    2 - Modificar o nome do produto\n\
    3 - Modificar o preco do produto\n\
    4 - Modificar todas as informacoes do produto\n");
    scanf("%d", &escolha);
    switch (escolha)
    {
        case 1:
            printf("Digite o novo codigo do produto: \n");
            fgets(tabela[pos].codigoPdt, 10, stdin);
            break;

        case 2:
            printf("Digite o novo nome do produto: \n");
            fgets(tabela[pos].produto, 40, stdin);
            break;
        case 3:
            printf("Digite o novo preco: \n");
            scanf("%.2f", tabela[pos].preco);
            break;
        case 4:
            printf("Digite o novo codigo do produto: \n");
            fgets(tabela[pos].codigoPdt, 10, stdin);
            printf("Digite o novo nome do produto: \n");
            fgets(tabela[pos].produto, 40, stdin);
            printf("Digite o novo preco: \n");
            scanf("%.2f", tabela[pos].preco);
            break;
        default:
            printf("Opcao invalida!");
            break;
    }
}

void listarTabela(t_pdt tabela[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Codigo do Produto: %s\n", tabela[i].codigoPdt);
        printf("Codigo do Produto: %s\n", tabela[i].produto);
        printf("Codigo do Produto: %.2f\n", tabela[i].preco);
    }
}
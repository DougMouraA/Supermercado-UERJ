#include "supermercado.h"

void imprimirString(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) 
        printf("Caractere: %c, Valor ASCII: %d\n", str[i], (unsigned char)str[i]);
}

t_pdt *inserirProduto(t_pdt tabela[], int tamPdt)
{
    if (tamPdt < 15)
    {
        printf("Codigo do Produto: \n");
        scanf(" %10[^\n]", tabela[tamPdt].codigoPdt);
        printf("Nome do Produto: \n");
        scanf(" %40[^\n]", tabela[tamPdt].produto);
        printf("Preco: \n");
        scanf("%f", &tabela[tamPdt].preco);
    }
    else
    {
        tabela = realloc(tabela, (tamPdt + 1) * sizeof(t_pdt));
        if (tabela == NULL)
        {
            printf("Erro ao realocar memoria\n");
            return (NULL);
        }
        printf("Codigo do Produto: \n");
        scanf(" %10[^\n]", tabela[tamPdt].codigoPdt);
        printf("Nome do Produto: \n");
        scanf(" %40[^\n]", tabela[tamPdt].produto);
        printf("Preco: \n");
        scanf("%f", &tabela[tamPdt].preco);
    }
    return (tabela);
}

void *removerProduto(t_pdt tabela[], char *codigo, int tamPdt)
{
    int pos = -1;
    int i;
    if (tamPdt == 0)
    {
        printf("Estoque vazio!\n");
        return 0;
    }
    else
    {
        for (i = 0; i < tamPdt; i++)
        {
            if (strcmp(tabela[i].codigoPdt, codigo) == 0)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            printf("Produto nao encontrado!\n");
            return (tabela);
        }
        tabela = realloc(tabela, (tamPdt - 1) * sizeof(t_pdt));
        for (int i = pos; i < tamPdt - 1; i++)
        {
            strcpy(tabela[i].codigoPdt, tabela[i+1].codigoPdt);
            strcpy(tabela[i].produto, tabela[i+1].produto);
            tabela[i].preco = tabela[i+1].preco;
        }
        return (tabela);
    }
}

float localizarProduto(t_pdt tabela[], int tamPdt, char *codigo)
{
    int pos = 0;
    int i;

    if (tamPdt == 0)
    {
        printf("Estoque vazio!\n");
    }
    else
    {
        for (i = 0; i < tamPdt; i++)
        {
            if (strcmp(tabela[i].codigoPdt, codigo) == 0)
            {
                pos = i;
                break;
            }

        }
        if (i >= tamPdt)
        {
            printf("Produto nao encontrado!\n");
            return (0);
        }
        printf("Codigo do Produto: %s\n", tabela[pos].codigoPdt);
        printf("Nome do Produto: %s\n", tabela[pos].produto);
        printf("Valor do Produto: %.2f\n", tabela[pos].preco);
        return (tabela[pos].preco);
    }
    return (0);
}

void modificarProduto(t_pdt tabela[], int tamPdt, char *codigo)
{
    int pos = 0;
    int escolha;
    if (tamPdt == 0)
    {
        printf("Estoque vazio!\n");
        return;
    }
    else 
    {
        for (int i = 0; i < tamPdt; i++)
        {
            if (strcmp(tabela[i].codigoPdt, codigo) == 0)
            {
                pos = i;
                break;
            }
        }
        printf("1. Modificar o codigo do produto\n");
        printf("2. Modificar o nome do produto\n");
        printf("3. Modificar o preco do produto\n");
        printf("4. Modificar todas as informacoes do produto\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
            case 1:
                printf("Digite o novo codigo do produto: \n");
                scanf(" %10[^\n]", tabela[pos].codigoPdt);
                break;

            case 2:
                printf("Digite o novo nome do produto: \n");
                scanf(" %40[^\n]", tabela[pos].produto);
                break;
            case 3:
                printf("Digite o novo preco: \n");
                scanf("%f", &tabela[pos].preco);
                break;
            case 4:
                printf("Digite o novo codigo do produto: \n");
                scanf(" %10[^\n]", tabela[pos].codigoPdt);
                printf("Digite o novo nome do produto: \n");
                scanf(" %40[^\n]", tabela[pos].produto);
                printf("Digite o novo preco: \n");
                scanf("%f", &tabela[pos].preco);
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }
}

void listarTabela(t_pdt tabela[], int tamPdt)
{
    if (tamPdt == 0)
    {
        printf("Estoque vazio!\n");
    }
    else
    {
        qsort(tabela, tamPdt, sizeof(t_pdt), compararProdutos);
        for (int i = 0; i < tamPdt; i++)
        {
            printf("Codigo do Produto: %s\n", tabela[i].codigoPdt);
            printf("Nome do Produto: %s\n", tabela[i].produto);
            printf("Preço do Produto: %.2f\n", tabela[i].preco);
        }
    }
    
}

void salvarProdutos(t_pdt tabela[], int tamPdt)
{
    FILE *arquivo = fopen("produtos.bin", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for(int i = 0; i < tamPdt; i++)
    {
        fwrite(&tabela[i], sizeof(t_pdt), 1, arquivo);
    }   
    fclose(arquivo);
}


int compararProdutos(const void *a, const void *b) 
{
    t_pdt *produtoA = (t_pdt *)a;
    t_pdt *produtoB = (t_pdt *)b;
    return strcmp(produtoA->codigoPdt, produtoB->codigoPdt);
}

void ordenarProdutos(t_pdt *produtos, int numProdutos) 
{
    qsort(produtos, numProdutos, sizeof(t_pdt), compararProdutos);
}
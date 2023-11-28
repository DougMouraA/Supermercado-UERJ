#include "supermercado.h"

int main() {
    t_pdt *produtos = malloc(sizeof(t_pdt) * 15);
    t_cliente *clientes = malloc(sizeof(t_cliente) * 15);
    t_pedido *pedidos = malloc(sizeof(t_pedido) * 15);
    FILE *arquivoProdutos = fopen("produtos.bin", "rb");
    FILE *arquivoCliente = fopen("clientes.bin", "rb");
    FILE *arquivoPedido = fopen("pedidos.bin", "rb");
    fread(produtos, sizeof(t_pdt), 15, arquivoProdutos);
    fread(clientes, sizeof(t_cliente), 15, arquivoCliente);
    fread(pedidos, sizeof(t_pedido), 15, arquivoPedido);
    fclose(arquivoProdutos);
    fclose(arquivoCliente);
    fclose(arquivoPedido);

    int tamPdt = 15;
    int tamC = 0;
    int tamPedido = 0;
    int opcao = 0;
    while (1)
    {
        printf("1 - Inserir produto\n");
        printf("2 - Remover produto\n");
        printf("3 - Localizar produto\n");
        printf("4 - Modificar produto\n");
        printf("5 - Listar tabela de produtos\n");
        printf("6 - Adicionar cliente\n");
        printf("7 - Fazer pedido\n");
        printf("8 - Total de vendas\n");
        printf("9 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                produtos = inserirProduto(produtos, tamPdt);
                tamPdt++;
                salvarProdutos(produtos, tamPdt);
                break;
            case 2:
                printf("Digite o codigo do produto que deseja remover: \n");
                char codigo[10];
                scanf(" %10[^\n]", codigo);
                produtos = removerProduto(produtos, codigo, tamPdt);
                tamPdt--;
                salvarProdutos(produtos, tamPdt);
                break;
            case 3:
                printf("Digite o codigo do produto que deseja localizar: \n");
                char codigoPdt[10];
                scanf(" %10[^\n]", codigoPdt);
                localizarProduto(produtos, tamPdt, codigoPdt);
                break;
            case 4:
                printf("Digite o codigo do produto que deseja modificar: \n");
                char codigoPdtMod[10];
                scanf(" %10[^\n]", codigoPdtMod);
                modificarProduto(produtos, tamPdt, codigoPdtMod);
                salvarProdutos(produtos, tamPdt);
                break;
            case 5:
                listarTabela(produtos, tamPdt);
                break;
            case 6:
                clientes = adicionarCliente(clientes, tamC);
                tamC++;
                salvarCliente(clientes, tamC);
                break;
            case 7:
                pedidos = pedido(produtos, clientes, pedidos, tamC, tamPdt, tamPedido);
                tamPedido++;
                salvarPedido(pedidos, tamPedido);
                break;
            case 8:
                if (tamPedido == 0)
                    printf("Nao ha pedidos realizados!\n");
                else
                {
                    printf("Digite a data que deseja verificar as vendas (formato: dd/mm/aaaa): \n");
                    char data[11];
                    scanf(" %10[^\n]", data);
                    totalVendas(pedidos, tamPedido, data);
                }
                break;
            case 9:
                free(produtos);
                free(clientes);
                free(pedidos);
                return 0;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include "supermercado.h"

// #define MAX_PRODUTOS 15

// int main() {
//     t_pdt produtos[MAX_PRODUTOS];
//     FILE *arquivo = fopen("produtos.bin", "wb");

//     if (arquivo == NULL) {
//         printf("Não foi possível abrir o arquivo.\n");
//         return 1;
//     }

//     for (int i = 0; i < MAX_PRODUTOS; i++) {
//         printf("Digite o código do produto: ");
//         scanf(" %10[^\n]", produtos[i].codigoPdt);

//         printf("Digite o nome do produto: ");
//         scanf(" %40[^\n]", produtos[i].produto);

//         printf("Digite o preço do produto: ");
//         scanf("%f", &produtos[i].preco);

//         fwrite(&produtos[i], sizeof(t_pdt), 1, arquivo);
//     }

//     fclose(arquivo);

//     return 0;
// }
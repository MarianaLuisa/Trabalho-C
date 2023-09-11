#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//STRUCTS GLOBAIS
struct autenticacao
{
    char usuario[12];
    int senha;
};

struct produtos
{
    char nome[30];
    float preco;
    int codigo;
    int anovalidade;
    float pgrama;
    char marca[20];
};

//DECLARA��O DE VARI�VEIS GLOBAIS
void exibeMenu();
struct autenticacao a1;//= {"meu usu�rio", 123456};
void controlestoque();
void cadastroprod();
void buscaprod();
void sair();

struct produtos prod[100];

int numprodutos, i;

//MAIN--------------------------------------------------------------------------------------------------------------------------

int main()
{
    //DECLARA��O DE VARI�VEIS
    setlocale(LC_ALL,"Portuguese");
    char tentusuario[12];
    int tentsenha, cont;

    //ATRIBUI��O DO USU�RIO E SENHA
    strcpy(a1.usuario, "meu usuario");
    a1.senha=123456;

    //AUTENTICA��O DO USUARIO E SENHA
    autenticacao(a1);

    //EXIBIR MENU NOVAMENTE
    exibeMenu();

    //EXIBIR CONTROLE DE ESTOQUE
    controlestoque();

    return 0;
}

//MENU----------------------------------------------------------------------------------------------------------------------
void exibeMenu()
{
    printf("*****************************************************************************\n\n");
    printf("               SISTEMA DE GEST�O DE ESTOQUE - FARM�CIA MONI                  \n\n");
    printf("*****************************************************************************\n\n");

}


//AUTENTICA��O --------------------------------------------------------------------------------------------------------------
void autenticacao()
{
    char usuario[12], tentusuario[12];
    int senha, tentsenha,cont;
    do
    {
        system("cls");
        exibeMenu();
        printf("\n----> AUTENTICA��O DE USU�RIO\n\n");
        printf("Informe o seu usu�rio: ");
        fgets(tentusuario, 12, stdin);
        printf("Informe a sua senha: ");
        scanf("%d",&tentsenha);
        getchar();


        if (strcmp(a1.usuario, tentusuario)==0)
        {
            if (a1.senha==tentsenha)
            {
                printf("\nLOGADO\n");
                system("pause");
                cont=1;
            }
            else
            {
                printf("\nUSU�RIO E/OU SENHA N�O ENCONTRADOS.");
                cont=0;
            }
        }
        else
        {
            printf("\nUSU�RIO E/OU SENHA N�O ENCONTRADOS.");
            cont=0;
        }
    }
    while (cont!=1);
}

//CONTROLE ESTOQUE --------------------------------------------------------------------------------------------------------------
void controlestoque()
{
    int opt;
    do
    {
        system ("cls");
        exibeMenu();
        printf("\n-------> CONTROLE DE ESTOQUE\n");
        printf("\n1- Cadastro de produto");
        printf("\n2- Exibir estoque de produtos");
        printf("\n3- Busca de produto");
        printf("\n4- Sair do programa");


        printf("\n\nDIGITE UMA OP��O: ");
        scanf("%d", &opt);


        switch(opt)
        {
        case 1:
            cadastroprod();
            system("Pause");
            break;
        case 2:
            exibestoque();
            system("pause");
            break;
        case 3:
            buscaprod();
            system("pause");
            break;
        case 4:
            sair();
            system("pause");
        }

    }
    while ((opt>4) || (opt<1));
}


// CADASTRO DE PRODUTO --------------------------------------------------------------------------------------------------------------
void cadastroprod()
{
    //DECLARA��O DE VARIAVEIS - produtos[100]
    int i, aux, j;
    numprodutos=0;
    //struct produtos prod[100];

    setlocale(LC_ALL,"Portuguese");
    system ("cls");
    exibeMenu();
    printf("\n-------> CADASTRO DE PRODUTOS\n");





    do
    {
        for (i=0; i<100; i++)
        {
            printf("\n Informe o nome do produto: ");
            setbuf(stdin,0);
            fgets(prod[i].nome, 30, stdin);

            printf("\n Informe o marca do produto: ");
            setbuf(stdin,0);
            fgets(prod[i].marca, 20,stdin);

            printf("\n Informe o pre�o do produto: ");
            setbuf(stdin,0);
            scanf("%f", &prod[i].preco);

            printf("\n Informe o c�digo do produto: ");
            //setbuf(stdin,0);
            scanf("%d", &prod[i].codigo);

            printf("\n Informe o ano de validade do produto: ");
            setbuf(stdin,0);
            scanf("%d", &prod[i].anovalidade);

            printf("\n Informe o peso(em gramas) do produto: ");
            setbuf(stdin,0);
            scanf("%f", &prod[i].pgrama);
            setbuf(stdin,0);


            numprodutos++;


            do
            {
                system("CLS");
                exibeMenu();
                printf("\nPRODUTO CADASTRADO COM SUCESSO.\n");
                printf("\nDigite 1 - Cadastrar um novo produto \nDigite 2 - Retornar ao Controle de Estoque\n");
                scanf("%d", &aux);
            }
            while ((aux!=1) && (aux!=2));

            if (aux==1)
            {
                system("CLS");
                exibeMenu();
                int j=0;
            }
            if (aux==2)
            {
                system ("CLS");
                exibeMenu();
                controlestoque();
                break;
            }

        }
    }
    while(j==0);

}

//LISTA DE PRODUTOS --------------------------------------------------------------------------------------
void exibestoque()
{
    //DELCARA��O DE VARI�VEIS
    int aux2;

    //PADR�O
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    exibeMenu();
    printf("\n-------> LISTA DE PRODUTOS\n");

    printf("\nQuantidade de produtos cadastrados: %d\n", numprodutos);

    if (numprodutos>0)
    {
        for (int i=0; i<numprodutos; i++)
        {
            printf("\nNome do produto: %s", prod[i].nome);
        }
    }
    else
    {
        printf("N�o h� produtos cadastrados.\n ");
    }

    do
    {
        printf("\nDigite 0 para retornar ao Controle de Estoque.\n");
        scanf("%d",&aux2);
    }
    while(aux2!=0);

    if (aux2==0)
    {
        system("CLS");
        exibeMenu();
        controlestoque();
    }
}

//BUSCA DE PRODUTOS ----------------------------------------------------------------------------------
void buscaprod()
{
    //DECLARA��O DE VARI�VEIS
    char prodbuscado[30];
    int aux=0, aux2=1;

    do
    {
        //PADR�O
        setlocale(LC_ALL,"Portuguese");
        system("cls");
        exibeMenu();
        printf("\n-------> BUSCA DE PRODUTOS\n");

        //DIGITAR BUSCA
        printf("\ndigite sua busca e os dados do produto ser�o listados. ");
        printf("\nBuscar por: ");
        setbuf(stdin,0);
        fgets(prodbuscado, 30, stdin);
        printf("\n\n");

        //BUSCAR E LISTAR
        for(int cont=0; cont<=numprodutos; cont++)
        {
            if (strcmp(prod[cont].nome, prodbuscado)==0)
            {
                aux=1;
                printf("Nome do produto: %s", prod[cont].nome);
                printf("Marca: %s", prod[cont].marca);
                printf("Pre�o: %.2f", prod[cont].preco);
                printf("\nC�digo: %d", prod[cont].codigo);
                printf("\nAno de validade: %d", prod[cont].anovalidade);
                printf("\nPeso(em gramas): %2.f", prod[cont].pgrama);
            }

        }
        if (aux!=1)
        {
            printf("\nPRODUTO N�O ENCONTRADO.\n ");
            system("pause");
        }
    }
    while(aux!=1);

    do
    {
        printf("\n\n\nDigite 0 para retornar ao Controle de Estoque.");
        scanf("%d", &aux2);
    }
    while(aux2!=0);

    if(aux2==0)
    {
        controlestoque();
    }
}

//SA�DA DO PROGRAMA---------------------------------------------------------------------------------------------------------------------
void sair()
{
    //DECLARA��O DE VARI�VEIS
    int escolhasair;

    //CONFIRMA��O
    do
    {
        //PADR�O
        setlocale(LC_ALL,"Portuguese");
        system("cls");
        exibeMenu();

        printf("________________________________________\n");
        printf("VOC� REALMENTE DESEJA SAIR DO PROGRAMA?\n");
        printf("________________________________________\n");
        printf("\n 1-Sim, quero sair do programa.");
        printf("\n 2-N�o, quero retornar ao Controle de Estoque.\n");
        scanf("%d", &escolhasair);
    }
    while((escolhasair!=1) && (escolhasair!=2));

    //RESPOSTA
    if(escolhasair==1)
    {
        exit(0);
    }
    else
    {
        controlestoque();
    }
}

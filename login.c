#include<stdio.h>
#include<locale.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 200





int main(void){

    char login[15] = "hospital";
    char login1[15];
    char senha[15] = "hospital";
    char senha1[15];
    int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro
    int opcao = 0;
    int calcidade;
    int risco = 0;
    struct cadastro {
    char nome[SIZE];
    char email[SIZE];
    int numero, dia, mes, ano;
    char cpf[SIZE], telefone[SIZE], cep[SIZE], diag[SIZE];
    char rua[SIZE], bairro[SIZE], cidade[SIZE], estado[SIZE], comorbidade[10], quais[SIZE];
    };
        struct cadastro pac;

    int anoAtual;
    time_t data_ano;
    time(&data_ano);


    struct tm * data = localtime(&data_ano);
    anoAtual = (data -> tm_year+1900);


    while(!login_efetuado){
        printf("Digite o Login: ");
        scanf("%s", login1);

        printf("Digite a Senha: ");
        scanf("%s", senha1);

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
            printf("\n\nLOGADO!\n\n");
            login_efetuado = 1;
        }
        else
            printf("\n\nDADOS INVALIDOS!\n\n");
    }
{

    printf("*************************************\n\n");
    printf("***CADASTRO DE PACIENTES COM COVID***\n\n");
    printf("*************************************\n\n");

    printf("1) - CADASTRO DE PACIENTE\n");
    printf("2) - SAIR DO SISTEMA\n");
    printf("DIGITE A OPCAO DESEJADA: ");
    scanf("%d", &opcao);}

    if (opcao == 2) {
            printf("\n\nDESLOGADO!\n\n");
            return 0;


        }
        else (opcao == 1);{
            printf("\n\nCADASTRO\n\n");
    }

{

        fflush(stdin);
        FILE *ponteiroArquivo;
        ponteiroArquivo=(fopen("cadastros.txt", "a"));
        printf("\n\nNome do paciente: ");
        fgets(pac.nome, 200, stdin);

        printf("CPF: ");
        fflush(stdin);
        fgets(pac.cpf, 12, stdin);

        printf("Data de nascimento:");
        printf("\nDia: ");
        fflush(stdin);
        scanf("%d", &pac.dia);

        printf("Mes: ");
        fflush(stdin);
        scanf("%d", &pac.mes);

        printf("Ano: ");
        fflush(stdin);
        scanf("%d", &pac.ano);

        printf("Telefone: ");
        scanf(" %30[^\n]s", &pac.telefone);

        printf("CEP: ");
        scanf(" %30[^\n]s", &pac.cep);

        printf("Rua: ");
        scanf(" %30[^\n]s", &pac.rua);

        printf("Numero: ");
        fflush(stdin);
        scanf("%d", &pac.numero);

        printf("Bairro: ");
        scanf(" %30[^\n]s", &pac.bairro);

        printf("Cidade: ");
        scanf(" %30[^\n]s", &pac.cidade);

        printf("Estado: ");
        scanf(" %30[^\n]s", &pac.estado);

        printf("Email: ");
        scanf(" %30[^\n]s", &pac.email);

        printf("Data do diagnostico: ");
        scanf(" %30[^\n]s", &pac.diag);
        setbuf(stdin, NULL);

        printf("O paciente tem alguma comorbidade? 1. Sim / 0. Nao ");
        scanf("%d", &risco);
        setbuf(stdin, NULL);

        if(risco == 1)
        {
            strcpy(pac.comorbidade, "SIM");
            printf("Quais? ");

            fflush(stdin);
            fgets(pac.quais, 200, stdin);
        }
        else{
            strcpy(pac.comorbidade, "NÃO");
            strcpy(pac.quais, "Nenhum");
        }
        printf("\n");
        fprintf(ponteiroArquivo, "\nNome: %s", pac.nome);
        fprintf(ponteiroArquivo, "CPF: %s", pac.cpf);
        fprintf(ponteiroArquivo, "Data de nascimento: %d/%d/%d\n", pac.dia, pac.mes, pac.ano);
        fprintf(ponteiroArquivo, "Telefone: %s", pac.telefone);
        fprintf(ponteiroArquivo, "\nCEP: %s", pac.cep);
        fprintf(ponteiroArquivo, "\nRua: %s", pac.rua);
        fprintf(ponteiroArquivo, "\nNúmero: %i\n", pac.numero);
        fprintf(ponteiroArquivo, "Bairro: %s", pac.bairro);
        fprintf(ponteiroArquivo, "\nCidade: %s", pac.cidade);
        fprintf(ponteiroArquivo, "\nEstado: %s", pac.estado);
        fprintf(ponteiroArquivo, "\nEmail: %s", pac.email);
        fprintf(ponteiroArquivo, "\nData do diagnostico: %s", pac.diag);
        fprintf(ponteiroArquivo, "\nComorbidade: %s", pac.comorbidade);
        fprintf(ponteiroArquivo, "\nQuais comorbidade(s)? %s\n", pac.quais);
        calcidade = anoAtual - pac.ano;
        if (calcidade > 65 || risco == 1) {
            FILE *ponteiroRisco;
            ponteiroRisco=(fopen("grupoderisco.txt", "a"));
            fprintf(ponteiroRisco, "\nNome: %s", pac.nome);
            fprintf(ponteiroRisco, "\nCEP: %s", pac.cep);
            fprintf(ponteiroRisco, "\nIdade: %d\n", calcidade);
            printf("\n\nO Paciente foi identificado como pertencente ao grupo de risco.\n");
            fclose(ponteiroRisco);
    }
        fclose(ponteiroArquivo);

    }



    }







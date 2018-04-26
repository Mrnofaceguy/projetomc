#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>



void
menu_de_registo()
{
        printf("**Menu de registo**\n");
        printf("1) Login / antenticação\n");
        printf("2) Pedido de registo\n");
        printf("0) Sair\n");
}


/*
void
Menu()
{
        printf("1) Ver feed\n");
        printf("2) Ver tópicos\n");
        printf("3) Procurar tópicos mais ativos\n");
        printf("4) Subscrever tópico\n");
        printf("5) Publicar num tópico\n");
        printf("6) Gerir Lista de Subscrições\n");
        printf("7) Ver Estatísticas\n");
        printf("8) Logout\n");
        switch (input)
        {
                case 1:
                        Login();
                case 2:
                        //Pedido_de_registo();
                case 0:
                        return 0;
                default:
                        printf("A opção escolhida nao existe.Tente outra vez\n");
                        main();
        }
}


int
Login()
{
        char username[20];
        char passwd[20];
        char temp1[20];
        char temp2[20];
        char s[20];

        FILE *fp;
        fp = fopen("/net/areas/homes/up201704695/Documents/project_lab/SupCliente_assets/Dados_Login.txt","r");
        if(!fp)
                printf ("Erro na abertura do arquivo.");
        printf("Insira o username \n"); scanf("%s", username);
        printf("Insira a password \n"); scanf("%s",passwd);
        while (fgets(s,20,fp))
        {

                int i = 0;
                for (i = 0; s[i] != ';'; ++i)
                        temp1[i] = s[i];

                temp1[i] = '\0';
                ++i;

                int j = 0;
                for (; s[i] != ';'; ++i)
                        temp2[j++] = s[i];
                temp2[j] = '\0';

                for (i = 0; temp1[i] != '\0' || username[i] != '\0'; ++i)
                {
                        if (temp1[i] != username[i])
                        {
                                printf("Nome ou password incorretos. Deseja tentar outra vez?(y/n) ");
                                char continuar = 0;
                                scanf("%c", &continuar);

                                if(continuar == 'y')
                                        Login();
                                else
                                        menu_de_registo();
                        }
                }

                for (int i = 0; temp2[i] != '\0' || passwd[i] != '\0'; ++i)
                {
                        if (temp2[i] != passwd[i])
                        {
                                printf("Nome ou password incorretos. Deseja tentar outra vez?(y/n) ");
                                char continuar = 0;
                                scanf("%c", &continuar);
                                if(continuar == 'y')
                                        Login();
                                else
                                        menu_de_registo();
                        }
                }
        }

        fclose(fp);
        printf("nice.");

        return 0;
}

int
main()
{
        int input = 0;
        menu_de_registo();
        scanf("%d", &input);
        switch (input)
        {
                case 1:
                        Login();
                case 2:
                        Pedido_de_registo();
                case 0:
                        return 0;
                default:
                        printf("A opção escolhida nao existe.Tente outra vez\n");
                        main();
        }
}

int
Pedido_de_registo()
{
        char newusername[20];
        char newpasswd[20];
        char continuar = 0;
        printf("Insira um username (menos de vinte caracteres)\n"); scanf("%s", newusername);
        printf("Insira uma password (menos de vinte caracteres)\n"); scanf("%s\n", newpasswd);
        FILE *fp;
        fp = fopen("/net/areas/homes/up201704695/Documents/project_lab/Pedido_de_registo.txt","a");
        if(!fp)
                printf ("Erro na abertura do arquivo.");
        fprintf(fp, "%s;%s;", newusername, newpasswd);
        fclose(fp);
        printf("O seu pedido está a ser processado\n");

        printf("Se desejar ir para o menu de registo escolha a opção 1)\n Se desejar sair escolha outra opção qualquer\n");
        fflush(stdout);

        scanf("%c\n", &continuar);
        if(continuar == '1')
        {
                main();

        }
        return 0;

}

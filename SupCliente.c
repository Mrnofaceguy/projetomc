#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


typedef struct
{
	char username[30];
	char password[30];
        char email[100];
        char nome[30];
	int tipo;
} conta;
void clear();
void menu_de_registo();
void Pedido_de_registo();
void Login();

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void
menu_de_registo()
{
        clear();
        printf("**Menu de registo**\n");
        printf("1) Login / autenticação\n");
        printf("2) Pedido de registo\n");
        printf("0) Sair\n");
        int input = 0;
        scanf("%d", &input);
        switch (input)
        {
                case 1:
                        Login();
                case 2:
                        Pedido_de_registo();
                case 0:
                        return ;
                default:
                        printf("A opção escolhida nao existe.Tente outra vez\n");
                        menu_de_registo();
        }
}



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
	/*int input = 0;
        scanf("%d", &input);
        switch (input)
        {
                case 1:
                        Ver_feed();
                case 2:
                        Ver_topicos();
		case 3:
	               	Topicos_ativos();
		case 4:
	                Subscrever_topicos();
		case 5:
	                Publicar_topico();
		case 6:
		       	Gerir_subscricoes();
		case 7:
			Ver_estatisticas();
		case 8:
			menu_de_registo();
                default:
                        printf("A opção escolhida nao existe.Tente outra vez\n");
                        Menu();
        }*/
}

void
Pedido_de_registo()
{
	clear();
        char newusername[30];
        char newpasswd[30];
        char newname[30];
        char newemail[100];
        char continuar = 2;
        printf("Insira um nome (menos de vinte caracteres)\n"); scanf("%s\n", newname);
        printf("Insira uma username.Este vai ser usado no login. (menos de vinte caracteres)\n"); scanf("%s\n", newusername);
        printf("Insira uma password (menos de vinte caracteres)\n"); scanf("%s\n", newpasswd);
        printf("Insira uma email \n"); scanf("%s\n", newemail);

	if(strlen(newname) >= 20)
	{
		printf("Nome com carateres a mais. Tente outra vez");
		Pedido_de_registo();
	}
	if(strlen(newusername) >= 20)
	{
		printf("Username com carateres a mais. Tente outra vez");
		Pedido_de_registo();
	}
	if(strlen(newpasswd) >= 20)
	{
		printf("Password com carateres a mais. Tente outra vez");
		Pedido_de_registo();
	}
	if(strlen(newemail) >= 100)
	{
		printf("Email com carateres a mais. Tente outra vez");
		Pedido_de_registo();
	}

        FILE *fp;
        fp = fopen("Pedido_de_registo.txt","a");
        if(!fp)
                printf ("Erro na abertura do arquivo.");


        fprintf(fp, "%s;%s;%s;%s;\n", newusername, newpasswd, newname, newemail);
        fclose(fp);

        printf("O seu pedido está a ser processado\n");
	while (continuar != '0' || continuar != '1')
	{
		printf("Se desejar ir para o menu de registo escolha a opção 1)\n");
		printf("Se desejar sair escolha 0)\n");
        	fflush(stdout);
        	scanf("%c\n", &continuar);
        	if(continuar == '1')
                	menu_de_registo();
		if(continuar == '0')
			menu_de_registo();
		else
			printf("A opção escolhida nao existe.Tente outra vez\n" );
	}
        return ;

}

void
Login(conta utilizador[], int n)
{
        clear();
        system("CLS");

        char temp1[20];
        char temp2[20];
        char s[20];

        FILE *fp = fopen("Dados_Login.txt","rb");

        if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf("try again\n" );
                Login( utilizador, n);
        }

        printf("Insira o username \n"); scanf("%s",temp2);
        printf("Insira a password \n"); scanf("%s",temp2);

        while (fgets(s,20,fp))
        {

                int i = 0;
                for (i = 0; s[i] != ';'; ++i)
                        utilizador[n].username[i] = s[i];

                temp1[i] = '\0';
                ++i;

                int j = 0;
                for (; s[i] != ';'; ++i)
                        utilizador[n].password[j++] = s[i];
                temp2[j] = '\0';

                for (i = 0; temp1[i] != '\0' || utilizador[n].username[i] != '\0'; ++i)
                {
                        if (utilizador[n].username[i] != temp1[i])
                        {
                                printf("Nome ou password incorretos. Deseja tentar outra vez?(y/n) ");
                                char continuar ;
                                scanf("%c", &continuar);

                                if(continuar == 'y')
                                        Login( utilizador, n);
                                else
                                        menu_de_registo();
                        }
                }

                for (int i = 0; temp2[i] != '\0' || utilizador[n].password[i] != '\0'; ++i)
                {
                        if (utilizador[n].password[i] != temp2[i])
                        {
                                printf("Nome ou password incorretos. Deseja tentar outra vez?(y/n) ");
                                char continuar = 0;
                                scanf("%c", &continuar);
                                if(continuar == 'y')
                                        Login( utilizador, n);
                                else
                                        menu_de_registo();
                        }
                }
        }

        fclose(fp);
        printf("nice.");

        return ;
}

int
main()
{       clear();

        int n = 0;


        conta utilizador[200];
        menu_de_registo();

}

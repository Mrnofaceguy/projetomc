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

typedef struct
{
	char num_topico;
	char topico[150];
	char likes;
}Topicos;

void clear();
void menu_de_registo();
void Pedido_de_registo();
void Menu();
void Login();
void Alterar_nome();
void Alterar_password();
void Alterar_username();
void Subscrever_topicos();




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
		case 44:
	               	Menu();
                case 0:
                        return ;
                default:
                        printf("A opção escolhida nao existe.Tente outra vez\n");
                        menu_de_registo();
        }
}

void
Gerir_conta(conta utilizador[], int n)
{
	clear();
	printf("**Bem vindo**\n");
	printf("1) Alterar nome.\n");
	printf("2) Alterar username.\n");
	printf("3) Alterar password.\n");
	printf("0) Voltar.\n");
	int input = 13;
        scanf("%d", &input);
	switch (input)
        {
                case 1:
                        Alterar_nome( utilizador, n);
                case 2:
                        Alterar_username( utilizador, n);
		case 3:
	               	Alterar_password( utilizador, n);
                case 0:
                        Menu();
                default:
                        printf("A opção escolhida nao existe.Tente outra vez\n");
                        Gerir_conta(utilizador, n);
        }

}
void
Alterar_nome(conta utilizador[], int n)
{
	int tentativas = 0;
	char tempnome[30];
	char temp1[30];
        char temp2[30];
	char temp3[30];
	char temp4[100];
	char s[300];
	FILE *fp = fopen("Dados_Login.txt","r");
	FILE *fp1 = fopen("Dados_Login_temporario.txt","w");

        if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_nome (utilizador, n);
        }
	if(!fp1)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_nome (utilizador, n);
        }
	printf("Insira nome atual.\n"); scanf("%s\n",temp1);
	for(int i = 0; i < 30; i++)
	{
		if(utilizador[n].nome[i] != temp1[i])
		{
			printf("Nome errado.Tente outra vez\n");
			Alterar_nome(utilizador, n);
		}
	}
	while(tentativas < 3 )
	{
		printf("Insira nome novo.\n"); scanf("%s\n",tempnome);
		if(strlen(tempnome) >= 20)
		{
			printf("Tenta outra vez.\n");
			tentativas ++;
		}
		else
		{
			while (fgets(s,300,fp))
		        {

		                int i = 0;
		                for (i = 0; s[i] != ';'; ++i)
		                        temp1[i] = s[i];

		                temp1[i] = '\0';
		                ++i;

		                int j = 0;
		                for (; s[i] != ';'; ++i)
		                        temp2[j++] = s[i];
		                temp2[j++] = '\0';
				++i;

				int k = 0;
			       	for (; s[i] != ';'; ++i)
				       temp3[k++] = s[i];
			       	temp3[k++] = '\0';
			       	++i;

			       	int l = 0;
			       	for (; s[i] != ';'; ++i)
				       temp4[l++] = s[i];
			       	temp4[l++] = '\0';
			       	++i;

				for(int o = 0; temp1[o] != '\0'; ++o)
				{
					if(temp1[o] == utilizador[n].username[o] && temp2[o] == utilizador[n].password[o] && temp3[o] == utilizador[n].nome[o] && temp4[o] == utilizador[n].email[o])
						fprintf(fp1, "%s;%s;%s;%s;\n", utilizador[n].username, utilizador[n].password, tempnome, utilizador[n].email);
					else
						fprintf(fp1, "%s;%s;%s;%s;\n", utilizador[n].username, utilizador[n].password, utilizador[n].nome, utilizador[n].email);
				}
		       }
		 }
	}
	fclose (fp); fclose (fp1);

	FILE *fp3 = fopen("Dados_Login.txt","w");
	FILE *fp4 = fopen("Dados_Login_temporario.txt","r");

	while (fgets(s,300,fp4))
	{

		int i = 0;
		for (i = 0; s[i] != ';'; ++i)
			temp1[i] = s[i];

		temp1[i] = '\0';
		++i;

		int j = 0;
		for (; s[i] != ';'; ++i)
			temp2[j++] = s[i];
		temp2[j++] = '\0';
		++i;

		int k = 0;
		for (; s[i] != ';'; ++i)
		       temp3[k++] = s[i];
		temp3[k++] = '\0';
		++i;

		int l = 0;
		for (; s[i] != ';'; ++i)
		       temp4[l++] = s[i];
		temp4[l++] = '\0';
		++i;
		fprintf(fp3, "%s;%s;%s;%s;\n", utilizador[n].username, utilizador[n].password, utilizador[n].nome, utilizador[n].email);
	}
	fclose (fp3); fclose (fp4);
	menu_de_registo();

}
void
Alterar_username(conta utilizador[], int n)
{
	int tentativas = 0;
	char tempnome[30];
	char temp1[30];
        char temp2[30];
	char temp3[30];
	char temp4[100];
	char s[300];
	FILE *fp = fopen("Dados_Login.txt","r");
	FILE *fp1 = fopen("Dados_Login_temporario.txt","w");

        if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_nome (utilizador, n);
        }
	if(!fp1)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_nome (utilizador, n);
        }
	printf("Insira username atual.\n"); scanf("%s\n",temp1);
	for(int i = 0; i < 30; i++)
	{
		if(utilizador[n].username[i] != temp1[i])
		{
			printf("Nome errado.Tente outra vez\n");
			Alterar_nome(utilizador, n);
		}
	}
	printf("Tem tres tentativas.\n");
	while(tentativas < 3 )
	{
		printf("Insira username novo.\n"); scanf("%s\n",tempnome);
		if(strlen(tempnome) >= 20)
		{
			printf("Tenta outra vez.\n");
			tentativas ++;
		}
		else
		{
			while (fgets(s,300,fp))
		        {

		                int i = 0;
		                for (i = 0; s[i] != ';'; ++i)
		                        temp1[i] = s[i];

		                temp1[i] = '\0';
		                ++i;

		                int j = 0;
		                for (; s[i] != ';'; ++i)
		                        temp2[j++] = s[i];
		                temp2[j++] = '\0';
				++i;

				int k = 0;
			       	for (; s[i] != ';'; ++i)
				       temp3[k++] = s[i];
			       	temp3[k++] = '\0';
			       	++i;

			       	int l = 0;
			       	for (; s[i] != ';'; ++i)
				       temp4[l++] = s[i];
			       	temp4[l++] = '\0';
			       	++i;

				for(int o = 0; temp1[o] != '\0'; ++o)
				{
					if(temp1[o] == utilizador[n].username[o] && temp2[o] == utilizador[n].password[o] && temp3[o] == utilizador[n].nome[o] && temp4[o] == utilizador[n].email[o])
						fprintf(fp1, "%s;%s;%s;%s;\n", tempnome, utilizador[n].password, utilizador[n].nome, utilizador[n].email);
					else
						fprintf(fp1, "%s;%s;%s;%s;\n", utilizador[n].username, utilizador[n].password, utilizador[n].nome, utilizador[n].email);
				}
		       }
		 }
	}
	if(tentativas < 3)
	{
		fclose (fp); fclose (fp1);

		FILE *fp3 = fopen("Dados_Login.txt","w");
		FILE *fp4 = fopen("Dados_Login_temporario.txt","r");

		while (fgets(s,300,fp4))
		{

			int i = 0;
			for (i = 0; s[i] != ';'; ++i)
				temp1[i] = s[i];

			temp1[i] = '\0';
			++i;

			int j = 0;
			for (; s[i] != ';'; ++i)
				temp2[j++] = s[i];
			temp2[j++] = '\0';
			++i;

			int k = 0;
			for (; s[i] != ';'; ++i)
		       		temp3[k++] = s[i];
			temp3[k++] = '\0';
			++i;

			int l = 0;
			for (; s[i] != ';'; ++i)
		       		temp4[l++] = s[i];
			temp4[l++] = '\0';
			++i;
			fprintf(fp3, "%s;%s;%s;%s;\n", utilizador[n].username, utilizador[n].password, utilizador[n].nome, utilizador[n].email);
		}
		fclose (fp3); fclose (fp4);
		menu_de_registo();
	}
	else
		Gerir_conta(utilizador, n);
}
void
Alterar_password(conta utilizador[], int n)
{
	int tentativas = 0;
	char tempnome[30];
	char temp1[30];
        char temp2[30];
	char temp3[30];
	char temp4[100];
	char s[300];
	FILE *fp = fopen("Dados_Login.txt","r");
	FILE *fp1 = fopen("Dados_Login_temporario.txt","w");

        if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_nome (utilizador, n);
        }
	if(!fp1)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_nome (utilizador, n);
        }
	printf("Insira password atual.\n"); scanf("%s\n",temp1);
	for(int i = 0; i < 30; i++)
	{
		if(utilizador[n].password[i] != temp1[i])
		{
			printf("Nome errado.Tente outra vez\n");
			Alterar_nome(utilizador, n);
		}
	}
	printf("Tem tres tentativas.\n");
	while(tentativas < 3 )
	{
		printf("Insira password novo.\n"); scanf("%s\n",tempnome);
		if(strlen(tempnome) >= 20)
		{
			printf("Tenta outra vez.\n");
			tentativas ++;
		}
		else
		{
			while (fgets(s,300,fp))
		        {

		                int i = 0;
		                for (i = 0; s[i] != ';'; ++i)
		                        temp1[i] = s[i];

		                temp1[i] = '\0';
		                ++i;

		                int j = 0;
		                for (; s[i] != ';'; ++i)
		                        temp2[j++] = s[i];
		                temp2[j++] = '\0';
				++i;

				int k = 0;
			       	for (; s[i] != ';'; ++i)
				       temp3[k++] = s[i];
			       	temp3[k++] = '\0';
			       	++i;

			       	int l = 0;
			       	for (; s[i] != ';'; ++i)
				       temp4[l++] = s[i];
			       	temp4[l++] = '\0';
			       	++i;

				for(int o = 0; temp1[o] != '\0'; ++o)
				{
					if(temp1[o] == utilizador[n].username[o] && temp2[o] == utilizador[n].password[o] && temp3[o] == utilizador[n].nome[o] && temp4[o] == utilizador[n].email[o])
						fprintf(fp1, "%s;%s;%s;%s;\n", utilizador[n].username, tempnome, utilizador[n].nome, utilizador[n].email);
					else
						fprintf(fp1, "%s;%s;%s;%s;\n", utilizador[n].username, utilizador[n].password, utilizador[n].nome, utilizador[n].email);
				}
		       }
		 }
	}
	if(tentativas < 3)
	{
		fclose (fp); fclose (fp1);

		FILE *fp3 = fopen("Dados_Login.txt","w");
		FILE *fp4 = fopen("Dados_Login_temporario.txt","r");

		while (fgets(s,300,fp4))
		{

			int i = 0;
			for (i = 0; s[i] != ';'; ++i)
				temp1[i] = s[i];

			temp1[i] = '\0';
			++i;

			int j = 0;
			for (; s[i] != ';'; ++i)
				temp2[j++] = s[i];
			temp2[j++] = '\0';
			++i;

			int k = 0;
			for (; s[i] != ';'; ++i)
		       		temp3[k++] = s[i];
			temp3[k++] = '\0';
			++i;

			int l = 0;
			for (; s[i] != ';'; ++i)
		       		temp4[l++] = s[i];
			temp4[l++] = '\0';
			++i;
			fprintf(fp3, "%s;%s;%s;%s;\n", temp1, temp2, temp3, temp4);
		}
		fclose (fp3); fclose (fp4);
		menu_de_registo();
	}
	else
		Gerir_conta(utilizador, n);
}

void
Subscrever_topicos(Topicos topico[],conta utilizador[],int n, int p)
{
	char s[300];
	char input;
	FILE *fp = fopen("C:\\Users\\utilizador\\Desktop\\project_lab\\Topicos.txt","r");
	if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Subscrever_topicos(topico,p);
	}

	while (fgets(s,300,fp))
	{
		int i = 0;
		topico[p].num_topico = s[i++];
		i++;
		int j = 0;

                for (; s[i] != ';'; ++i)
			topico[p].topico[j++] = s[i];

		topico[p].topico[j++] = '\0';
		i++;
		topico[p].likes = s[i];

		printf("%d - %s. %d likes", topico[p].num_topico, topico[p].topico, topico[p].likes);
		printf("Deseja subscrever este tópico?(y/n)\n");
		scanf("%d", &input);
		if(input == 'y')
		{
			adicionar_topico(topico[p].num_topico,utilizador,n,p);
			Menu;
		}

	}


}

adicionar_topico(Topicos topico[], conta utilizador[], int n, int p)
{

}



void
Menu()
{
	clear();
	printf("**Menu**\n");
	printf("1) Gerir conta\n");
        printf("2) Ver feed\n");
	printf("3) Ver tópicos\n");
        printf("4) Procurar tópicos mais ativos\n");
        printf("5) Subscrever tópico\n");
        printf("6) Publicar num tópico\n");
        printf("7) Gerir Lista de Subscrições\n");
        printf("8) Ver Estatísticas\n");
        printf("9) Logout\n");
	/*int input = 0;
        scanf("%d", &input);
        switch (input)
        {
		case 1:
			Gerir_conta();
                case 2:
                        Ver_feed();
                case 3:
                        Ver_topicos();
		case 4:
	               	Topicos_ativos();
		case 5:
	                Subscrever_topicos();
		case 6:
	                Publicar_topico();
		case 7:
		       	Gerir_subscricoes();
		case 8:
			Ver_estatisticas();
		case 9:
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
        printf("Insira um nome (menos de vinte caracteres)\n"); scanf("%s", newname);
        printf("Insira uma username.Este vai ser usado no login. (menos de vinte caracteres)\n"); scanf("%s", newusername);
        printf("Insira uma password (menos de vinte caracteres)\n"); scanf("%s", newpasswd);
        printf("Insira uma email \n"); scanf("%s", newemail);

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
	menu_de_registo();
        return ;

}

void
Login(conta utilizador[], int n)
{
        clear();
        char temp1[20];
        char temp2[20];
        char s[50];

        FILE *fp = fopen("SupCliente_assets\\Dados_Login.txt","r");

        if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Login (utilizador, n);
        }

        printf("Insira o username \n"); scanf("%s",temp1);
        printf("Insira a password \n"); scanf("%s",temp2);

        while (fgets(s,50,fp))
        {

                int i = 0;
                for (i = 0; s[i] != ';'; ++i)
                        utilizador[n].username[i] = s[i];

                utilizador[n].username[i] = '\0';
                ++i;

                int j = 0;
                for (; s[i] != ';'; ++i)
                        utilizador[n].password[j++] = s[i];
                utilizador[n].password[j++] = '\0';

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
        Menu();

        return ;
}

void
main()
{
 	clear();
        int n = 0;
	int p = 0;
        conta utilizador[200];
	Topicos topico[200];
        menu_de_registo();

}

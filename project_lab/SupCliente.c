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
	char subscritos[50];
} conta;

conta utilizador[200];

typedef struct
{
	char num_topico[10];
	char topico[150];
	char likes[150];
	
}Topicos;

Topicos topico[200];

typedef struct
{
	char num_topico[10];
	char coments[1000];
}Posts;

Posts comentarios[200];


void clear();
void menu_de_registo();
void Pedido_de_registo();
void Menu();
void Login(int n);
void Alterar_nome();
void Alterar_password();
void Alterar_username();
void Subscrever_topicos();
void adicionar_topico();
void Ver_topicos();




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
                        Login(0);
                        break;
                case 2:
                        Pedido_de_registo();

                case 0:
                        return ;
                        break;
                default:
                        printf("A opção escolhida nao existe.Tente outra vez\n");
                        menu_de_registo();
        }
}

void
Gerir_conta(int n)
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
                        Alterar_nome(0);
                        break;
                case 2:
                        Alterar_username(0);
						break;
				case 3:
						Alterar_password(0);
						break;
                case 0:
                        Menu();
                        break;
                default:
                        printf("A opção escolhida nao existe.Tente outra vez\n");
                        Gerir_conta(0);
        }
	return ;
}
void
Alterar_nome(int n)
{
	int tentativas = 0;
	char tempnome[30];
	char temp1[30];
        char temp2[30];
	char temp3[30];
	char temp4[100];
	char temp5[300];
	char s[300];
	char p = 'a';
	FILE *fp = fopen("./SupCliente_assets/Dados_Login.txt","r");
	FILE *fp1 = fopen("./SupCliente_assets/Dados_Login_temporario.txt","w");

        if(!fp)
        {
                printf ("E1rro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_nome (n);
        }
	if(!fp1)
        {
                printf ("E2rro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_nome (n);
        }
    clear();    
	printf("Insira nome atual.(vai voltar ao menu de registo no fim da alteração)\n"); scanf("%s",temp1);

	if ( !(strcmp (utilizador[n].nome, temp1) == 0))
		{
			printf("Nome errado.Tente outra vez\n");
			Alterar_nome(n);
		}
	clear();
	printf("Tem tres tentativa.\n");
	while(tentativas < 3 && p != 'b' )
	{
		printf("Insira nome novo.\n"); scanf("%s",tempnome);
		if(strlen(tempnome) >= 20)
		{
			printf("Tenta outra vez.\n");
			tentativas ++;
		}
		else
		{
			while (fgets(s,300,fp) != NULL && s[0] != '\n')
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

				int m = 0;
				for (; s[i] != ';'; ++i)
			       		temp5[m++] = s[i];
				temp5[m++] = '\0';
				++i;

				if(strcmp (temp1, utilizador[n].username) == 0 && strcmp (temp2, utilizador[n].password) == 0)
					fprintf(fp1, "%s;%s;%s;%s;%s;\n", temp1, temp2, tempnome, temp4, temp5);
				else
					fprintf(fp1, "%s;%s;%s;%s;%s;\n", temp1,temp2, temp3, temp4, temp5);
				}
				p = 'b';
	 		 }
	 	}
	 	if(tentativas < 3)
	 	{
	 		fclose (fp); fclose (fp1);

	 		FILE *fp3 = fopen("./SupCliente_assets/Dados_Login.txt","w");
	 		FILE *fp4 = fopen("./SupCliente_assets/Dados_Login_temporario.txt","r");

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

	 			int m = 0;
				for (; s[i] != ';'; ++i)
			       		temp5[m++] = s[i];
				temp5[m++] = '\0';
				++i;

	 			fprintf(fp3, "%s;%s;%s;%s;%s;\n", temp1,temp2, temp3, temp4, temp5);
	 		}
	 		fclose (fp3); fclose (fp4);
	 		menu_de_registo();
	 		return;
	 	}

	 	else
	 		Gerir_conta(0);

}
void
Alterar_username(int n)
{
	int tentativas = 0;
	char tempnome[30];
	char temp1[30];
        char temp2[30];
	char temp3[30];
	char temp4[100];
	char temp5[300];
	char s[300];
	char p = 'a';
	FILE *fp = fopen("./SupCliente_assets/Dados_Login.txt","r");
	FILE *fp1 = fopen("./SupCliente_assets/Dados_Login_temporario.txt","w");

        if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_username (n);
        }
	if(!fp1)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_username (n);
        }
	printf("Insira username atual.\n"); scanf("%s",temp1);
	if ( !(strcmp (utilizador[n].username, temp1) == 0))
	{
		printf("usernameome errado.Tente outra vez\n");
		Alterar_username(n);
	}

	printf("Tem tres tentativas.\n");
	while(tentativas < 3 && p != 'b' )
	{
		printf("Insira username novo.\n"); scanf("%s",tempnome);
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

				int m = 0;
				for (; s[i] != ';'; ++i)
			       		temp5[m++] = s[i];
				temp5[m++] = '\0';
				++i;

				if(strcmp (temp1, utilizador[n].username) == 0 && strcmp (temp2, utilizador[n].password) == 0)
					fprintf(fp1, "%s;%s;%s;%s;%s;\n", tempnome, temp2, temp3, temp4, temp5);
				else
					fprintf(fp1, "%s;%s;%s;%s;%s;\n", temp1,temp2, temp3, temp4, temp5);
		       }
		       p = 'b';
		 }
	}
	if(tentativas < 3)
	{
		fclose (fp); fclose (fp1);

		FILE *fp3 = fopen("./SupCliente_assets/Dados_Login.txt","w");
		FILE *fp4 = fopen("./SupCliente_assets/Dados_Login_temporario.txt","r");

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
			fprintf(fp3, "%s;%s;%s;%s;%s;\n", temp1,temp2, temp3, temp4, temp5);
		}
		fclose (fp3); fclose (fp4);
		menu_de_registo();
	}
	else
		Gerir_conta(0);
	return;
}
void
Alterar_password(int n)
{
	int tentativas = 0;
	char tempnome[30];
	char temp1[30];
        char temp2[30];
	char temp3[30];
	char temp4[100];
	char temp5[300];
	char s[300];
	char p = 'a';
	FILE *fp = fopen("./SupCliente_assets/Dados_Login.txt","r");
	FILE *fp1 = fopen("./SupCliente_assets/Dados_Login_temporario.txt","w");

        if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_password (n);
        }
	if(!fp1)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Alterar_password (n);
        }
	printf("Insira password atual.\n"); scanf("%s",temp1);
	if ( !(strcmp (utilizador[n].password, temp1) == 0))
	{
		printf("Password errada.Tente outra vez\n");
			Alterar_password(n);
	}

	printf("Tem tres tentativas.\n");
	while(tentativas < 3 && p != 'b' )
	{
		printf("Insira password nova.\n"); scanf("%s",tempnome);
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

				int m = 0;
				for (; s[i] != ';'; ++i)
			       		temp5[m++] = s[i];
				temp5[m++] = '\0';
				++i;

				if(strcmp (temp1, utilizador[n].username) == 0 && strcmp (temp2, utilizador[n].password) == 0)
					fprintf(fp1, "%s;%s;%s;%s;%s;\n", temp1, tempnome, temp3, temp4, temp5);
				else
					fprintf(fp1, "%s;%s;%s;%s;%s;\n", temp1,temp2, temp3, temp4, temp5);
		       }
		       p = 'b';
		 }
	}
	if(tentativas < 3)
	{
		fclose (fp); fclose (fp1);

		FILE *fp3 = fopen("./SupCliente_assets/Dados_Login.txt","w");
		FILE *fp4 = fopen("./SupCliente_assets/Dados_Login_temporario.txt","r");

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
			fprintf(fp3, "%s;%s;%s;%s;%s;\n", temp1,temp2, temp3, temp4, temp5);
		}
		fclose (fp3); fclose (fp4);
		menu_de_registo();
	}
	else
		Gerir_conta(0);
	return;
}

void
Subscrever_topicos(int p)
{	
  clear();
	char s[300];
	int input;
	FILE *fp = fopen("Topicos.txt","r");
	if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Subscrever_topicos(0);
	}

	while (fgets(s,300,fp) != NULL && s[0] != '\n')
	{	
		clear();
		int i = 0;
		for (; s[i] != ';'; ++i)
			topico[p].num_topico[i] = s[i];
		topico[p].num_topico[i]	= '\0';
		i++;
		int j = 0;

                for (; s[i] != ';'; ++i)
			topico[p].topico[j++] = s[i];

		topico[p].topico[j++] = '\0';
		i++;
		int k = 0;
		for (; s[i] != ';'; ++i)
			topico[p].likes[k++] = s[i];
		topico[p].likes[k++] = '\0';

		printf("%s) %s. %s likes\n", topico[p].num_topico, topico[p].topico, topico[p].likes);
		printf("Deseja subscrever este tópico?Press 1(sim), Press 2(nao), Press 3(voltar)\n");
		scanf("%d", &input);
		if(input == 1)
		{
			adicionar_topico(0,0);

		}
		if(input == 3)
		{
			Menu();
			return;

		}
		

	}
	Menu();
	return;


}

void
adicionar_topico(int n,int p)
{
	char valor_comparar[100];
	FILE *fp = fopen("./SupCliente_assets/Dados_Login.txt","r");
	FILE *fp1 = fopen("./SupCliente_assets/Dados_Login_temporario.txt","w");

        if(!fp)
        {
                printf ("E1rro na abertura do arquivo.");
                printf ("try again\n");
                adicionar_topico(n,p);
        }
	if(!fp1)
        {
                printf ("E2rro na abertura do arquivo.");
                printf ("try again\n");
                adicionar_topico(n, p);
        }
	int j = 0;
	int k = 0;
	char temp1[30];
        char temp2[30];
	char temp3[30];
	char temp4[100];
	char temp5[300];
	char s[300];
	printf("Ola\n");
	int i = 0;
	if(utilizador[n].subscritos[0] != '\0')
	{
		while(utilizador[n].subscritos[i] != '\0')
		{
			k = 0;
			for(; utilizador[n].subscritos[i] != ','; ++i)
			{
				valor_comparar[k++] = utilizador[n].subscritos[i];

			}

			valor_comparar[k++] = '\0';
			++i;
			
			if((strcmp (valor_comparar, topico[p].num_topico ) == 0))
			{
				printf("Este topico já estava subscrito\n");
				printf("Ola\n");
				return;
			}
		}
	


	while (fgets(s,300,fp) != NULL && s[0] != '\n')
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

		int m = 0;
		for (; s[i] != ';'; ++i)
			temp5[m++] = s[i];
		temp5[m++] = '\0';
		++i;
		
		
		if(strcmp (temp1, utilizador[n].username) == 0 && strcmp (temp2, utilizador[n].password) == 0)
			fprintf(fp1, "%s;%s;%s;%s;%s,%s;\n", temp1, temp2, temp3, temp4,topico[p].num_topico, temp5);
		else
			fprintf(fp1, "%s;%s;%s;%s;%s;\n", temp1,temp2, temp3, temp4, temp5);
	}
	}
	
	else



{
	fclose (fp); fclose (fp1);

	FILE *fp3 = fopen("./SupCliente_assets/Dados_Login.txt","w");
	FILE *fp4 = fopen("./SupCliente_assets/Dados_Login_temporario.txt","r");

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

		int m = 0;
		for (; s[i] != ';'; ++i)
			temp5[m++] = s[i];
		temp5[m++] = '\0';
		++i;

		fprintf(fp3, "%s;%s;%s;%s;%s;\n", temp1,temp2, temp3, temp4, temp5);
	}
	fclose (fp3); fclose (fp4);
	return;
}


}

void
Ver_topicos(int p)
{
	clear();
	char s[300];
	int input;
	char a[10];
	int input2;
	FILE *fp = fopen("Topicos.txt","r");
	if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Ver_topicos(0);
	}

	while (fgets(s,300,fp) != NULL && s[0] != '\n')
	{	
		
		int i = 0;
		for (; s[i] != ';'; ++i)
			topico[p].num_topico[i] = s[i];
		topico[p].num_topico[i]	= '\0';
		
		i++;
		int j = 0;

                for (; s[i] != ';'; ++i)
			topico[p].topico[j++] = s[i];

		topico[p].topico[j++] = '\0';
		i++;
		int k = 0;
		for (; s[i] != ';'; ++i)
			topico[p].likes[k++] = s[i];
		topico[p].likes[k++] = '\0';

		printf("%s) %s. %s likes\n", topico[p].num_topico, topico[p].topico, topico[p].likes);
	}
	fclose(fp);
	FILE *fp1 = fopen("Topicos.txt","r");
	if(!fp)
    {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Ver_topicos(0);
	}
	printf("Escolha o numero do topico do qual quer ver as mensagens\n");
		scanf("%d", &input);
	while (fgets(s,300,fp1) != NULL && s[0] != '\n')
	{	
		int i = 0;
		for (; s[i] != ';'; ++i)
			topico[p].num_topico[i] = s[i];
		topico[p].num_topico[i]	= '\0';
		i++;
		int j = 0;

                for (; s[i] != ';'; ++i)
			topico[p].topico[j++] = s[i];

		topico[p].topico[j++] = '\0';
		i++;
		int k = 0;
		for (; s[i] != ';'; ++i)
			topico[p].likes[k++] = s[i];
		topico[p].likes[k++] = '\0';
		if(atoi(topico[p].num_topico) == input )
		{	
			clear();
			printf("%s) %s. %s likes\n", topico[p].num_topico, topico[p].topico, topico[p].likes);
			//Ver_coments();
			return;
		}
	}
	fclose(fp1);
	
	printf("Esse tópico não existe.Press 1 (para tentar outra vez) Press2(para voltar)");
	printf("Presse 1(tentar outra vez) ou Press 2(voltar)\n");
		
	while(input2 != 1 && input2 != 2)
	{

        scanf("%d", &input2);
		while(input2 != 1 && input2 != 2)
		{
			clear();
			printf("Opção invalida.\nPresse 1(tentar outra vez) ou Press 2(voltar)\n");
			scanf("%d", &input);
		}
		if(input2 == 1)
				Ver_topicos(0);
		if(input2 == 2)
			Menu();
	}
	
	return;


}

Ver_coments()
{
	clear();
	char s[300];
	int input;
	char a[10];
	int input2;
	FILE *fp = fopen("Topicos.txt","r");
	if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Ver_topicos(0);
	}

	while (fgets(s,300,fp) != NULL && s[0] != '\n')
	{	
		
		int i = 0;
		for (; s[i] != ';'; ++i)
			topico[p].num_topico[i] = s[i];
		topico[p].num_topico[i]	= '\0';
		
		i++;
		int j = 0;

                for (; s[i] != ';'; ++i)
			topico[p].topico[j++] = s[i];

		topico[p].topico[j++] = '\0';
		i++;
		int k = 0;
		for (; s[i] != ';'; ++i)
			topico[p].likes[k++] = s[i];
		topico[p].likes[k++] = '\0';

		printf("%s) %s. %s likes\n", topico[p].num_topico, topico[p].topico, topico[p].likes);
	}
	fclose(fp);

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
	int input = 0;
        scanf("%d", &input);
        if(input == 1)
			Gerir_conta(0);
	if(input == 5)
	{
		Subscrever_topicos(0);
		return;
	}
	
	if(input == 3)
	{
		Ver_topicos(0);
	}	
	/*switch (input)
        {
		case 1:
			Gerir_conta();
			break;

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
return ;
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
    clear();
        printf("Insira uma username.Este vai ser usado no login. (menos de vinte caracteres)\n"); scanf("%s", newusername);
    clear();
        printf("Insira uma password (menos de vinte caracteres)\n"); scanf("%s", newpasswd);
    clear();
        printf("Insira uma email \n"); scanf("%s", newemail);
    clear();

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
Login(int n)
{
        clear();
        char temp1[20];
        char temp2[20];
	int q = 0;
	int input = 0 ;
        char s[50];

        FILE *fp = fopen("./SupCliente_assets/Dados_Login.txt","r");

        if(!fp)
        {
                printf ("Erro na abertura do arquivo.");
                printf ("try again\n");
                Login (n);
        }

        printf("Insira o username \n"); scanf("%s",temp1);
	clear();
        printf("Insira a password \n"); scanf("%s",temp2);

        while (fgets(s,500,fp) != NULL && s[0] != '\n')
        {
				int i = 0;
		                for (i = 0; s[i] != ';'; ++i)
		                        utilizador[n].username[i] = s[i];

		                utilizador[n].username[i] = '\0';

		                ++i;

		                int j = 0;
		                for (; s[i] != ';'; ++i)
		                        utilizador[n].password[j++]= s[i];
		                utilizador[n].password[j++] = '\0';
						++i;

						int k = 0;
						for (; s[i] != ';'; ++i)
							 utilizador[n].nome[k++] = s[i];
						 utilizador[n].nome[k++] = '\0';
						++i;

						int l = 0;
						for (; s[i] != ';'; ++i)
							 utilizador[n].email[l++] = s[i];
						 utilizador[n].email[l++] = '\0';
						++i;

						int m = 0;
						for (; s[i] != ';'; ++i)
							 utilizador[n].subscritos[m++] = s[i];
						 utilizador[n].subscritos[m++] = '\0';


                if ( (strcmp (utilizador[n].username, temp1) == 0) && (strcmp (utilizador[n].password, temp2) == 0))
		{
			Menu();
			return;
                }
	}
	clear();
	printf("Username ou password incorretos deseja tentar outra vez.\n");
	printf("Presse 1(tentar outra vez) ou Press 2(voltar)\n");
	while(input != 1 && input != 2)
	{

        	scanf("%d", &input);
		while(input != 1 && input != 2)
		{
			clear();
			printf("Opção invalida.\nPresse 1(tentar outra vez) ou Press 2(voltar)\n");
			scanf("%d", &input);
		}
		if(input == 1)
			Login(0);
		if(input == 2)
			menu_de_registo();
	}
	return;
}



void
main()
{
 	clear();
	int p = 0;

	Topicos topico[200];
        menu_de_registo();

}

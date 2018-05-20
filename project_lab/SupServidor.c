#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#define FX "./info_util.txt"
#define PR "./Pedido_de_registo.txt"
#define HELL "./banlist.txt"
#define AD "./SupServidor_assets/admins.txt"

typedef struct user
{
  char username[30];
  char password[30];
  char email[100];
  char nome[30];
  
  
}user;
typedef struct admin
{ 
  char nome[30];
  char passwd[30];
}admin;
typedef struct ban
{
  char username[30];
  char email[100];
  char nome[30];
 
}ban;
typedef struct Topicos
{
	char num_topico[10];
	char topico[150];
	char likes[150];
	
}Topicos;

typedef struct Posts
{
	char num_topico[10];
	char coments[1000];
}Posts;

Topicos topico[200];
void Ver_topicos(int p);
Posts comentarios[200];


void menu();


void
Ver_coments(int o, int p)
{
  
	char s[300];
	char input;
	
	int input2;
	FILE *fp = fopen("./Posts.txt","r");
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
	      comentarios[o].num_topico[i] = s[i];
	    comentarios[0].num_topico[i]= '\0';
	    
	    i++;
	    if((strcmp (comentarios[o].num_topico, topico[p].num_topico) == 0))
	      {
		for (; s[i] != ';'; ++i)
		  {
		    int j = 0;
		    for(;s[i] != ','; ++i)
		      {
			comentarios[o].coments[j++] = s[i];
		      }
		    comentarios[o].coments[j++] = '\0';
		    printf("||%s.\n",comentarios[o].coments);
		  }	
	      }
	  }
	fclose(fp);
	
	printf(" Press 1(para voltar) ou press2(para voltar ao menu)");
	while(input2 != 1 && input2 != 2)
	  {
	    
	    scanf("%d", &input2);
	    while(input2 != 1 && input2 != 2)
	      {
		printf("Opção invalida, quer retentar?(y/n)/n");
		while(input !='y' && input != 'n')
		  {
		    
		    scanf("%c", &input);
		    while(input != 'n' && input != 'y')
		      {
			printf("Opção invalida, quer tentar outra vez? (y/n)\n");
			scanf("%c", &input);
		      }
		    if(input == 'y')
		      Ver_coments(o,p);
		    if(input == 'n')
		      return;
		  }
		  	
	
	      }
	  }
	  switch(input2)
	  {
		  case 1: Ver_topicos(p);return;
		  case 2: menu();return;
	  }
	  
}
void novo_topico()
{

	Topicos temp1;
	temp1.likes[0]= '0';
	temp1.likes[1]= '\0';
	int number_of_lines = 1;
    FILE *infile = fopen("./Topicos.txt", "r+");
    int ch;
    while (EOF != (ch=getc(infile)))
        if ('\n' == ch)
            ++number_of_lines;

	printf(" Qual o nome do novo topico?\n");
	scanf("%s", temp1.topico);
	char input;
	fclose(infile);
	infile = fopen("./Topicos.txt", "r+");
	char s[300];
	Topicos temp2;
	while (fgets(s,300,infile) != NULL && s[0] != '\n')
    {	
		int i = 0;
		for (; s[i] != ';'; ++i)
			temp2.num_topico[i] = s[i];
		temp2.num_topico[i]	= '\0';
		
		i++;
		int j = 0;

                for (; s[i] != ';'; ++i)
			temp2.topico[j++] = s[i];

		temp2.topico[j++] = '\0';
		i++;
		int k = 0;
		for (; s[i] != ';'; ++i)
			temp2.likes[k++] = s[i];
		temp2.likes[k++] = '\0';
		if(temp1.topico==temp2.topico)		
		{
			printf("O topico já existe, deseja tentar outra vez?(y/n)\n");
			while(input !='y' && input != 'n')
			{
      
			scanf("%c", &input);
			while(input != 'n' && input != 'y')
				{
					printf("Opção invalida, quer tentar outra vez? (y/n)\n");
					scanf("%c", &input);
				}
			if(input == 'y')
				{
					fclose(infile);
					novo_topico();
				}
			if(input == 'n')
				{
					fclose(infile);
					return;
				}
			}	
	
		}
	}
	FILE *post;
	post=fopen("Posts.txt","r+");
	char *l = NULL;
	ssize_t red;
    size_t le=0;
	while((red = getline(&l, &le, infile)) != -1)
		{}
	char *lx = NULL;
	ssize_t rd;
    size_t ly=0;
	while((rd = getline(&lx, &ly, post)) != -1)
		{}
	fprintf(infile, "%d;%s;%s;\n", number_of_lines, temp1.topico, temp1.likes);


	fprintf(post, "%d;,,,,,,,,,,;\n", number_of_lines);
	printf(" Topico criado!\n");
	fclose(infile);
	fclose(post);
}
void
Ver_topicos(int p)
{
  char s[300];
  int input;

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
                printf ("A re-tentar\n");
                Ver_topicos(0);
    }
	printf(" Escolha o numero do topico do qual quer ver as mensagens\n");
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
		printf("%s) %s. %s likes\n", topico[p].num_topico, topico[p].topico, topico[p].likes);
		Ver_coments(0, 0);
		return;
	      }
	    
	  }
	fclose(fp1);
	printf("Esse tópico não existe, quer retentar?(1/0)\n");
	while(input !=1 && input != 0)
	  {
	    
	    scanf("%d", &input);
	    while(input != 1 && input != 0)
	      {
		printf("Opção invalida, quer tentar outra vez? (1/0)\n");
		scanf("%d", &input);
	      }
	    if(input == 1)
	      Ver_topicos(p);
	    if(input == 0)	  
	      return;
	  }   
	return;
}
 
int user_exists(user u)
{
	char s[194];
	FILE *fx;
	fx=fopen(FX,"r");
	int i;
	int a;
	for (i=0;fgets(s,194,fx);++i)
		{
			a=1;
			int j=0;
			for(i=0;s[j]!=';';++i)
				{
					if (u.username[i]!=s[j])
						{
							a=0;
							break;
						}
					++j;
				}
			++j;
			for(i=0;s[j]!=';';++i)
				{
					if (u.email[i]!=s[j])
						{
							a=0;
							break;
						}
					++j;
				}
			++j;
			for(i=0;s[j]!=';';++i)
				{
					if (u.nome[i]!=s[j])
						{
							a=0;
							break;
						}
					++j;
				}
				
			if(a==1)
				{
					fclose(fx);
					return 1;
				}
		}
	return -1;
}      
	       
user new(char name[30],char pass[30], char email[100], char rname[30])
{
  user new;
  int i;
  for ( i = 0; name[i];++i){new.username[i]=name[i];}
  for (i= 0; pass[i];++i){new.password[i]=pass[i];}
  for (i = 0; email[i];++i){new.email[i]=email[i];}
  for (i = 0; rname[i];++i){new.nome[i]=rname[i];}
  return new;
}



void delet(unsigned int u)
{
	
    FILE *input = fopen(FX, "r"); 
    FILE *output = fopen("tempfile.txt", "w"); 
    char txt[1001] = "";
    unsigned int selected_line = u;
    unsigned int current_line = 1;
    while(fgets(txt, 1001, input) != NULL){
        if(current_line != selected_line){
            fputs(txt, output);
        }
        memset(txt, 0, sizeof(char) * 1001);
        current_line += 1;
    }
    fclose(input);
    fclose(output);
    remove(FX);
    rename("tempfile.txt", FX);
    return;
}

void grava2(ban u)
{
  FILE *hl;
  hl=fopen(HELL,"r+");
  char *l = NULL;
  ssize_t red;
  size_t le=0;
  while((red = getline(&l, &le, hl)) != -1)
	{}
  fprintf(hl,"%s;%s;%s;\n",u.username,u.email, u.nome);	
  fclose(hl);
}

void menu_de_registo()
{
  printf("1) Login / autenticação \n");
  printf("0) Sair \n");  
}



int isbanned(ban u)
{
	char s[133];
	FILE *hl;
	hl=fopen(HELL,"r");
	int i;
	int a;
	for (i=0;fgets(s,163,hl);++i)
		{
			a=1;
			int j=0;
			for(i=0;s[j]!=';';++i)
				{
					if (u.username[i]!=s[j])
						{
							a=0;
							break;
						}
					++j;
				}
			++j;
			for(i=0;s[j]!=';';++i)
				{
					if (u.email[i]!=s[j])
						{
							a=0;
							break;
						}
					++j;
				}
			++j;
			for(i=0;s[j]!=';';++i)
				{
					if (u.nome[i]!=s[j])
						{
							a=0;
							break;
						}
					++j;
				}								
			if(a==1)
				{
					fclose(hl);
					return 1;
				}
		}
	fclose(hl);
	return -1;
} 

void freshmeat()
{
  

  FILE *fx;
  FILE *stream;
  char *line = NULL;
  char *l = NULL;
  size_t len = 0;
  size_t le=0;
  ssize_t read;
  ssize_t red;
  stream = fopen(PR, "r");
  if (stream == NULL)
    return; 
  fx=fopen(FX,"r+");
  int i;
  char tempu[30];
  char tempp[30];
  char tempe[100];
  char tempn[30];
  
   while ((read = getline(&line, &len, stream)) != -1)
    {
	  while((red = getline(&l, &le, fx)) != -1)
	  {}
      user u;
      ban m;
      int j=0;
      i=0;
      for ( i=0; line[j] != ';';++i)
	{
	  tempu[i]=line[j];
	  ++j;
	}
      ++j;
      for ( i=0; line[j] != ';';++i)
	{
	  tempp[i]=line[j];
	  ++j;
	}	
      for (i=0; line[j] != ';';++i)
	{
	  tempe[i]=line[j];
	  ++j;
	}	
      for (i=0; line[j] != ';';++i)
	{
	  tempn[i]=line[j];
	  ++j;
	}	

      strcpy(u.username, tempu);
      strcpy(u.password, tempp);
      strcpy(u.email, tempe);
      strcpy(u.nome, tempn);
      strcpy(m.username, u.username);
      strcpy(m.email, u.email);
      strcpy(m.nome, u.nome);
      if ((isbanned(m)!=1) && (user_exists(u)!=1))
	{
		
	  fprintf(fx,"%s", line);
	}
    }
  
  fclose(stream);
  fclose(fx);
  stream=fopen(PR,"w");
  fclose(stream);
  printf(" Userlist atualizada\n");
  return;
  
}
void new_admin()
{
  char temp1[30];
  char temp2[30];
  char temp3[100];
  char temp4[30];

  int i;
  int a;
  printf("\n Escreva o nome de utilizador do admin:");
  scanf("%s", temp1);
  printf("\n Escreva a password do admin:");
  scanf("%s", temp2);
  printf("\n Escreva o email do admin:");
  scanf("%s", temp3);
  printf("\n Escreva o nome do admin:");
  scanf("%s", temp4);
  if(strlen(temp1) >= 20)
    {
      printf("Nome com carateres a mais. Tente outra vez");
      new_admin();return;
    }
  if(strlen(temp2) >= 20)
    {
      printf("Password com carateres a mais. Tente outra vez");
      new_admin();return;
    }
  if(strlen(temp4) >= 20)
    {
      printf("Password com carateres a mais. Tente outra vez");
      new_admin();return;
    }
  if(strlen(temp3) >= 100)
    {
      printf("Email com carateres a mais. Tente outra vez");
      new_admin();return;
    }
  FILE *ad;
  ad=fopen(AD,"r+");
  FILE *pr;
  pr=fopen(PR,"r+");
  char *l = NULL;
  ssize_t red;
  size_t le=0;
  while((red = getline(&l, &le, pr)) != -1)
			{}
  char s[62];
  char input;
  int x=0;
  for (i=0;fgets(s,62,ad);++i)
    {
      a=1;
      int j=0;
      for(i=0;s[j]!=';';++i)
	{
	  if (temp1[i]!=s[j])
	    {
	      a=0;
	      break;
	    }
	  ++j;
	}
      ++j;
      for(i=0;s[j]!=';';++i)
	{
	  if (temp2[i]!=s[j]){
	    a=0;
	    break;
	  }
	  ++j;
	}
    if(a==1)
		{
			x=1;
			break;
		}
    }
  fclose(ad);
  ad=fopen(AD,"r+");
  char *z = NULL;
  ssize_t zed;
  size_t ze=0;
  while((zed = getline(&z, &ze, ad)) != -1)
			{}
  
  if(x==0)
    {

      printf(" Novo admin aceite\n");
      fprintf(ad, "%s;%s;\n", temp1, temp2 );      
      fprintf(pr,"%s;%s;%s;%s;\n", temp1,temp2,temp3,temp4);	 
	  fclose(ad);
	  fclose(pr);
	  freshmeat();
      return;
    }
     
  printf("O admin já existe,quer retentar?(y/n)");
  scanf("%c", &input);
  while(input !='y' && input != 'n')
    {
      
      scanf("%c", &input);
      while(input != 'n' && input != 'y')
	{
	  printf("Opção invalida, quer tentar outra vez? (y/n)\n");
	  scanf("%c", &input);
	}
      if(input == 'y')
	new_admin();
      if(input == 'n')
	return;
    }
  
}

void BanHammer()
{ 
  char t1[30];
  char t2[100];
  char t3[30];
  int t5;
  printf(" Qual o utilizador a banir?\nLinha em que aparece ");
  scanf("%d", &t5);
  printf("\n Username:");
  scanf("%s", t1);  
  printf("\n Email:");
  scanf("%s", t2);
  printf("\n Nome:");
  scanf("%s", t3);
  ban m;
  strcpy(m.username,t1);
  strcpy(m.email,t2);
  strcpy(m.nome,t3);
  /*
  strcpy(u.password,t4);
  strcpy(u.username,t1);
  strcpy(u.email,t2);
  strcpy(u.nome,t3);
  if(user_exists(u)==-1)
  {
      printf("\nO Utilizador não existe, quer tentar outra vez? (y/n)\n");
      char y;
      scanf("%c", &y);
      if(y == 'y')
		BanHammer();
      else menu(); return;
  }
  * */
  if (isbanned(m)==-1)
    {	
      
      delet(t5);
      grava2(m);
      printf(" Feito!\n");
      return;
    }
  
  if(isbanned(m)==1) 
    {
      printf("O utilizador já se encontra banido, quer tentar outra vez? (y/n)\n");
      char y;
      scanf("%c", &y);
      if(y == 'y')
	BanHammer();
      else menu(); return;
    }
  
}				
void userlistprompt()
{
  printf(" O que deseja fazer? \n1) Re-imprimir a lista\n2) Banir utilizadores \n3) Voltar\n");
  
}
void userlist()
{
  FILE *stream;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
 
  stream = fopen(FX, "r");
  if (stream == NULL)
    printf("Sem utilizadores");
  
    
  while ((read = getline(&line, &len, stream)) != -1) {
    printf("%s", line);
  }
  userlistprompt();
  int input; 
  scanf("%d", &input);
  switch (input)
    {
    case 1: userlist(); break;
    case 2: BanHammer();break;
    case 3:  break;
    default: userlist(); break;
    }
  return;					
}
void menu_prompt()
{
  printf(" O que deseja fazer?\n""1) Listar os ulilizadores existentes\n""2) Fazer refresh dos utilizadores\n3) Adicionar admin\n4) Ver topicos\n5) Criar topico\nq) Sair\n");
  
}
void menu()
{	
  menu_prompt();
  char d;
  scanf("%s", &d);
  switch (d)
    {
    case '1': userlist(); menu();return;
    case '2': freshmeat();menu();return;
    case '3': new_admin();menu();return;
    case '4': Ver_topicos(0);menu(); return;
    case '5': novo_topico();menu();return;
    case 'q': exit(0);
    default: menu();return;
    }

  
}
void Login()
{

  char temp1[30];
  char temp2[30];
  char input;
  int i;
  int a=1;
  printf("Insira o username \n"); 
  scanf("%s", temp1);
  printf("Insira a password \n"); 
  scanf("%s", temp2);
  FILE *ad;
  ad=fopen(AD,"r");
  char s[61];
  for (i=0;fgets(s,62,ad);++i)
    {
      a=1;
      int j=0;
      for(i=0;s[j]!=';';++i)
	{
	  if (temp1[i]!=s[j])
	    {
	      a=0;
	      break;
	    }
	  ++j;
	}
      ++j;
      for(i=0;s[j]!=';';++i)
	{
	  if (temp2[i]!=s[j]){
	    a=0;
	    break;
	  }
	  ++j;
	}
    if(a==1)
		{
			printf("Login aceite\n");
			menu();
			return;
		}
    }
  
  printf("Username ou password incorretos deseja tentar outra vez?(y/n)\n");
  	  scanf("%c", &input);
  while(input !='y' && input != 'n')
    {
      
      scanf("%c", &input);
      while(input != 'n' && input != 'y')
	{
	  printf("Opção invalida, quer tentar outra vez? (y/n)\n");
	  scanf("%c", &input);
	}
      if(input == 'y')
	Login();
      if(input == 'n')
	return;
    }
  return;
}
   
	
	





int menu_ini()
{
  
  menu_de_registo();
  int input;
  scanf("%d", &input);
  switch (input)
    {
    case 1:  Login();break;
    case 0: return 0;
    default: printf("Erro no input, tente outra vez\n" ); menu_ini();
    }
  return 0;
}	       








int main()
{
 
  menu_de_registo();
  int input;
  scanf("%d", &input);
  switch (input)
    {
    case 1:  Login ();break;
    case 0: return 0;
    default: printf("Erro no input, tente outra vez\n" ); menu_ini();
    }
  return 0;
}




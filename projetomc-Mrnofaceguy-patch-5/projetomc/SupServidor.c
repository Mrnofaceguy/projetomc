#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#define FX "./SupServidor_assets/info_util.txt"
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
user database[1000];
user banlist[1000];
admin list[10];
void menu();
void listLoader()
{
	int n=0;
	FILE *ad;
	ad=fopen(AD,"r");
	int i;
	char s[61];
	for (i=0;fgets(s,61,ad);++i)
	{
		fgets(s,61,ad);
		n=0;
		int j=0;
		for(i=0;s[i]!=';';++i)
		{
			list[n].nome[j]=s[i];
			++j;
		}
		list[n].nome[j]='\0';
		++i;
		j=0;
		for(;s[i]!='\n';++i)
		{
			list[n].passwd[j]=s[i];
			++j;
		}
		list[n].passwd[j]=';';
		++i;
		j=0;
		++n;
	}
}

int compare(char a[], char b[])
{
	int i;
	int c=strlen(a);
	int d=strlen(b);
	if (c!=d)
	{	
		return -1;
	}
	for (i=0; i<c; ++i)
	{
		if (a[i]!=b[i])
		{
			return -1;
		}
		    
	}
	return 1;
}

void database_init()
{
	FILE *fx; 
	char s[194];
	int n=0;
	int i;
	int j=0;
	fx=fopen(FX,"r");
	while(fgets(s,194,fx))
	{
		fgets(s,194,fx);
		for(i=0;s[i]!=';';++i)
		{
			database[n].username[j]=s[i];
			++j;
		}
		database[n].username[j]='\0';
		++i;
		j=0;
		for(;s[i]!=';';++i)
		{
			database[n].password[j]=s[i];
			++j;
		}
		database[n].password[j]='\0';
		++i;
		j=0;
		for(;s[i]!=';';++i) 
		{
			database[n].email[j]=s[i];
			++j;
		}
		database[n].email[j]='\0';
		++i;
		j=0;
		for(;s[i]!=';';++i) 
		{
			database[n].nome[j]=s[i];
			++j;
		}
		database[n].nome[j]='\0';
		++i;
		j=0;
		++n;
	}
	fclose(fx);
}
int user_exists(user u)
{
	int i=0;
	while (database[i].username!='\0')
	{
		if (compare(database[i].username, u.username)==1 || compare(database[i].nome, u.nome)==1 || compare(database[i].email, u.email)==1)
		{
				return 1;
		}
		++i;
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

void banlist_init()
{
  
  	FILE *fx; 
	char s[162];
	int n=0;
	int i;
	int j;
	fx=fopen(HELL,"r");
	while(fgets(s,162,fx))
	{
		fgets(s,162,fx);
		j=0;
		for(;s[i]!=';';++i)
		{
			banlist[n].username[j]=s[i];
			++j;
		}
		banlist[n].username[j]='\0';
		i++;
		j=0;
		for(;s[i]!=';';++i) 
		{
			banlist[n].email[j]=s[i];
			++j;
		}
		banlist[n].email[j]='\0';
		i++;
		j=0;
		for(;s[i]!=';';++i)
		{
			banlist[n].nome[j]=s[i];
			++j;
		}
		banlist[n].nome[j]='\0';
		++n;
	}	
	fclose(fx);

}

void delet(user u)
{
	int i;
	FILE *fx;
	fx=fopen(FX,"r+");
	FILE *t;
	t=fopen("tempfile.txt","w+");
	char s[194];
	char e[194];
	int y=1;
	for (;fgets(s,194,fx);)
	{
		
		for(i=0;s[i]!=';';i++)
		{
			if(u.username[i]!= s[i])
			{
				y=0;
				break;
			}
		}
		if (y==0)
		{
			
			fprintf(t,"%s/n",s);
		}
		y=1;
	}
	fclose(fx);
	FILE *p;
	p=fopen(FX,"w");
	for (;fgets(e,194,t);)
	{
		
		fprintf(p,"%s/n",e);
	}
	fclose(p);
	fclose(t);
}
void grava(int l, user u)
{
 
  if (l==2)
  {
  	FILE *hl;
  	hl=fopen(HELL,"r+");
    fprintf(hl,"%s;%s;%s;\n",u.username,u.email, u.nome);
    delet(u);
    banlist_init();	
    fclose(hl);
  }
  
  else if (l==1)
  {
  	FILE *fx;
  	fx=fopen(FX,"r+");
    fprintf(fx,"%s;%s;%s;%s;\n", u.username, u.password, u.email, u.nome);		
	database_init();
	fclose(fx);

   }
}
void menu_de_registo()
{
        printf("1) Login / autenticação \n");
        printf("0) Sair \n");


}	


int isbanned(user u)
{	int i;
	for ( i=0;banlist[i].username!='\0';++i)
	{
		if (compare(u.username, banlist[i].username)==1)
			return 1;
	}
	return -1;
}
void freshmeat()
{
	 FILE *pr;		
	 char s[194];
	 user(u);
	 pr=fopen(PR,"r");
	 for(;fgets(s,194,pr);)
		{
			
			char tempu[30];
			char tempp[30];
			char tempe[100];
			char tempn[30];
			
			int i;
			for ( i=0; s[i] != ';';++i)
			{
				tempu[i]=s[i];	
			}
			for ( i=0; s[i] != ';';++i)
			{
				tempp[i]=s[i];	
			}	
			for (i=0; s[i] != ';';++i)
			{
				tempe[i]=s[i];	
			}	
			for (i=0; s[i] != ';';++i)
			{
				tempn[i]=s[i];	
			}	
			u=new(tempu, tempp, tempe, tempn);
			if ((isbanned(u)==-1) && (user_exists(u)==-1))
				grava(1,u);				
		}
	 
		
		database_init();
		fclose(pr);			
	 }
 
void BanHammer()
{ 
	char t1[30];
	char t2[100];
	char t3[30];
	printf("Qual o utilizador a banir?\n Nome de utilizador:");
	scanf("%s", t1);
	printf("\n Email:");
	scanf("%s", t2);
	printf("\n Nome:");
	scanf("%s", t3);
	user m;
	strcpy(m.username,t1);
	strcpy(m.email,t2);
	strcpy(m.nome,t3);
	if(user_exists(m)==-1)
	{
		printf("\n O Utilizador não existe, quer tentar outra vez? (y/n)\n");
		char y;
		scanf("%c", &y);
		if(y == 'y')
			BanHammer();
		else menu(); return;
	}
	if (isbanned(m)==-1)
	{	
		grava(2, m);
		delet(m);
		return;
	}
	else if(isbanned(m)==1) 
	{
		printf(" O utilizador já se encontra banido, quer tentar outra vez? (y/n)\n");
		char y;
		scanf("%c", &y);
		if(y == 'y')
			BanHammer();
		else menu(); return;
	}
	
}				
void userlistprompt()
{
	printf("O que deseja fazer? \n 1) Re-imprimir a lista\n 2) Banir utilizadores \n 3) Voltar\n");
	
}
void userlist()
{
	FILE *fx; 
	char s[194];
	fx=fopen(FX,"r");
	int i;
	int n;
	printf("Username;password;email;nome \n");
	for (i = 0; fgets(s,194,fx)!='\0';++i)
	{
		for(n=0; s[n]!='\n';++n)
		{
		printf("%c", s[n]);
		}
		printf("\n");
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
	printf("O que deseja fazer?\n""1) Listar os ulilizadores existentes\n""2) Fazer refresh dos utilizadores\n");
	
}
void menu()
{	
	menu_prompt();
	int input;
	scanf("%d", &input);
	switch (input)
	{
		case 1: userlist(); break;
		case 2: freshmeat();menu();
		default: break;
	}
	
}
void Login()
{
	listLoader();
	char temp1[30];
	char temp2[30];
	int input = 0;
	int i;
	int a=1;
    printf("Insira o username \n"); 
    scanf("%s", temp1);
    printf("Insira a password \n"); 
    scanf("%s", temp2);
	FILE *ad;
	ad=fopen(AD,"r");
	char s[61];
	for (i=0;fgets(s,61,ad);++i)
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
	
	printf("Username ou password incorretos deseja tentar outra vez.\n");
	printf("Presse 1(tentar outra vez) ou Press 2(voltar)\n");
	while(input != 1 && input != 2)
	{

        	scanf("%d", &input);
		while(input != 1 && input != 2)
		{
			printf("Opção invalida.\nPress  1(tentar outra vez) ou Press 2(voltar)\n");
			scanf("%d", &input);
		}
		if(input == 1)
			Login(0);
		if(input == 2)
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
	database_init();
	banlist_init();
	listLoader();  
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




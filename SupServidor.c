#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>
#define FX "SupServidor_assets/info_util.txt"
#define PR "Highway/Pedido_de_registo.txt"
#define Hell "highway/banlist.txt"
int var=195;
typedef struct
{
	char username[30];
	char password[30];
	char email[100];
	char nome[30];
	char tipo;
}user;
user database[1000];
user banlist[1000];
int compare(char a[], char b[])
{
	int i;
	for (i=0; a[i]!='\0'&&b[i]!='\0'; i++)
		if (a[i]!=b[i])
			return -1;
	return 1;
}
void database_init()
{
	FILE *fx; 
	char s[var];
	int n=0;
	int i;
	int j=0;
	fx=fopen(FX,"r");
	while(fgets(s,var,fx))
	{
		fgets(s,var,fx);
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
		for(i=0;s[i]!=';';++i) 
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
		database[n].tipo=s[i];
		++n;
	}
	fclose(fx);
}
int user_exists(user u)
{
	int i;
	for ( i = 0; i<1000; ++i)
	{
		if (compare(database[i].username, u.username)==1 || compare(database[i].nome, u.nome)==1 || compare(database[i].email, u.email)==1)
			return 1;
	}
	return -1;
}
user new(char name[30],char pass[30], char email[100], char rname[30], int type)
{
	user new;
	int i;
	for ( i = 0; name[i];++i){new.username[i]=name[i];}
	for (i= 0; pass[i];++i){new.password[i]=pass[i];}
	for (i = 0; email[i];++i){new.email[i]=email[i];}
	for (i = 0; rname[i];++i){new.nome[i]=rname[i];}
	new.tipo=type;
	return new;
}

void banlist_init()
{
  
  	FILE *fx; 
	char s[var];
	int n=0;
	int i;
	int j;
	fx=fopen(Hell,"r");
	while(fgets(s,var,fx)){
		fgets(s,var,fx);
		j=0;
		for(i=0;s[i]!=';';++i)
		{
			banlist[n].username[j]=s[i];
			++j;
		}
		banlist[n].username[j]='\0';
		i++;
		j=0;
		for(i=0;s[i]!=';';++i) 
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
void grava(int l, user u)
{
 
  if (l==2)
  {
  	FILE *hl;
  	hl=fopen(Hell,"r+");
    fprintf(hl,"%s;%s;%s\n",u.username,u.email, u.nome);
    banlist_init();	
    fclose(hl);
  }
  
  else if (l==1)
  {
  	FILE *fx;
  	fx=fopen(FX,"r+");
    fprintf(fx,"%s;%s;%s;%s%d\n", u.username, u.password, u.email, u.nome, u.tipo);		
	database_init();
	fclose(fx);

   }
}
void delet(user u)
{
	int i;
	FILE *fx;
	fx=fopen(FX,"r+");
	FILE *t;
	t=fopen("tempfile.txt","w+");
	char s[var];
	char e[var];
	int y=1;
	for (;fgets(s,var,fx);)
	{
		fgets(s,var,fx);
		for(i=0;s[i]!=';';i++)
		{
			if(compare(u.username, s)==-1)
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
	for (;fgets(e,var,t);)
	{
		fgets(e,var,t);
		fprintf(p,"%s/n",e);
	}
	fclose(p);
	fclose(t);
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
void BanHammer()
{ 
	user m;
	printf("Qual o utilizador a banir?\n Nome de utilizador:");
	scanf("%s",m.username);
	printf("\n Email:");
	scanf("%s", m.email);
	printf("\n Nome:");
	scanf("%s", m.nome);
	if(user_exists(m)==-1)
	{
		printf("\n O Utilizador não existe, quer tentar outra vez? (y/n)\n");
		char yn;
		scanf("%c", &yn);
		if(yn=='gdy')
			BanHammer();
		else return;
	if (isbanned(m)==-1)
	{	
		grava(2, m);
		delet(m);
		return;
	}
	else if(isbanned(m)==1) 
	{
		printf("O utilizador já se encontra banido, quer tentar outra vez? (y/n)\n");
		char yn;
		scanf("%c", &yn);
		if(yn=='y')
			BanHammer();
		else return;
	}
	}
}				
void userlistprompt()
{
	printf("O que deseja fazer? /n 1) Re-imprimir a lista/n 2) Banir utilizador/n 3) Voltar/n");
	
}
void userlist()
{
	int i;
	printf("Username, email, nome, tipo");
	for (i = 0; database[i].username!='\0';++i)
	{
		printf("%s, %s, %s, %d \n", database[i].username, database[i].email, database[i].nome, database[i].tipo);
	}
	userlistprompt();
	int input; 
	scanf("%d", &input);
	switch (input)
	{
		case 1: userlist(); break;
		case 2: BanHammer();break;
		case 3: return;break;
		default: userlist(); break;
	}
	return;					
}
void menu_prompt()
{
	printf("O que deseja fazer?/n 1) Listar os ulilizadores existentes,/n 2) Parar de aceitar novos utilizadores ");
	
}
void menu()
{	
	menu_prompt();
	int input;
	scanf("%d", &input);
	switch (input)
	{
		case 1: userlist(); break;
		case 2: break;
		default: menu(); break;
	}
	
}
void Login()
{
        char username[30];
        char password[30];
        char x;
        int i;
        int out=0;
        printf("Insira o username \n"); 
        scanf("%s", username);
        printf("Insira a password \n"); 
		scanf("%s",password);		
        for ( i=0; i < 100; ++i)
        {
        	if (compare(database[i].username, username))
        	{
        		if (compare(database[i].password, password))
        		{
        			if(database[i].tipo==1)
        			{
        				printf("Dados aceites");
        				menu();
        				out=1;
        				break;
        			}
        			else 
        			{
        				printf("Desculpe, esta conta não é de administrador");
        				printf("Quer tentar outra vez(y/n)?"); scanf("%c",&x);
        				if (x=='y')
        				{
        					x='n';
							Login();
						}
        				else {menu_de_registo ();}
        			}
        		}
        	else 
        	{
        		printf("Password errada.");
        		printf("Quer tentar outra vez(y/n)?"); scanf("%c",&x);
        		if (x=='y')
       		{
       			x='n';
              	Login();
      		}
       		else {menu_de_registo();}
        		}        		
        	}
		if(out==0)
		{
			printf("Utilizador não encontrado.");
			printf("Quer tentar outra vez(y/n)?"); scanf("%c",&x);
			if (x=='y')
			{
				x='n';
				Login();
			}
			else {menu_de_registo();}
        
                
        }
        			
	}
	
}

int smain()
{
  
  menu_de_registo();
  int input;
  scanf("%d", &input);
  switch (input)
  {
    case 1:  Login ();break;
    case 0: return 0;
    default: printf("Erro no input, tente outra vez\n" ); smain();
  }
  return 0;
}	       

    



void freshmeat()
{
	 FILE *pr;
	 FILE *fx;
	 FILE *hl;

	 char s[var];
	 user(u);
	 for(;;)
	 {
		pr=fopen(PR,"r");
		fx=fopen(FX,"r+");
		hl=fopen(Hell, "r+");
		 	for(;fgets(s,var,pr);)
			{
				fgets(s,var,pr);
				char tempu[30];
				char tempp[30];
				char tempe[100];
				char tempn[30];
				int tempt;
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
				tempt=s[i];
				u=new(tempu, tempp, tempe, tempn, tempt);
				if ((isbanned(u)==-1) && (user_exists(u)==-1))
					grava(1,u);				
			}
		 
		 	
			database_init();
			fclose(pr);
			fclose(fx);
			fclose(hl);
			
		
		 sleep(60);
	 }
 }


int main()
{
  freshmeat();  
  menu_de_registo();
  int input;
  scanf("%d", &input);
  switch (input)
  {
    case 1:  Login ();break;
    case 0: return 0;
    default: printf("Erro no input, tente outra vez\n" ); smain();
  }
}




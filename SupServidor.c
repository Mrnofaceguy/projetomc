#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>
#include<dos.h>
#define FX "SupServidor_assets/info_util.txt"
#define PR "Highway/Pedido_de_registo.txt"
#define Hell "highway/banlist.txt"
typedef user
{
	char username[30];
	char password[30];
	char email[100];
	char nome[30];
	int tipo;
}
int compare(char a[], char b[])
{
	int c=1;
	for (int i=0, a[i]&&b[i], i++)
		if (a[i]!=b[i])
			return -1;
	return 1;
}
user database_init(){
  user database[1000];
  FILE *fx; char s[1],n=0,i,j;
	fx=fopen(FX,"r");
	while(fgets(s,300,fx)){
		for(i=0;s[i]!=';';i++)
			database[n].username=s[i];
		i++;
		j=0;
		for(;s[i]!=';';i++)
			database[n].password[j++]=s[i];
		i++;
		j=0;
		for(i=0;s[i]!=';';i++) 
			database[n].email[j++]=s[i];
		i++;
		j=0;
		for(;s[i]!=';';i++) 
			database[n].nome[j++]=s[i];
		i++;
		j=0;
		database[n].tipo=s[i];
		n++;
	}
	fclose(fx);
  return database;
}
int user_exists(user u)
{
	user database=database_init();
	for (int i = 0, i<1000, ++i)
	{
		if (compare(database[i].username, u.username)==1 || compare(database[i].nome, u.nome)==1 || compare(database[i].email, u.email)==1)
			return 1;
	}
	return -1;
}
user new(char name[30],char pass[30], char email[100], char rname[30], int type)
{
	user new;
	for (int i = 0, name[i],++i){new.username[i]=name[i];}
	for (i= 0, pass[i],++i){new.password[i]=pass[i];}
	for (i = 0, email[i],++i){new.email[i]=email[i];}
	for (i = 0, rname[i],++i){new.nome[i]=rname[i];}
	new.tipo=type
	return new;
}
user banlist_init()
{
  	user banlist[1000];
  	FILE *fx; 
	char s[300];
	int n=0;
	int i;
	int j;
	fx=fopen(Hell,"r");
	while(fgets(s,300,fx)){
		for(i=0;s[i]!=';';i++)
			banlist[n].username[j++]=s[i];
		i++;
		j=0;
		for(i=0;s[i]!=';';i++) 
			banlist[n].email[j++]=s[i];
		i++;
		j=0;
		for(;s[i]!=';';i++) 
			banlist[n].nome[j++]=s[i];
		++n;
	}	
	fclose(fx);
  	return banlist;
}
void grava(int l, user u)
{
 
  if (l==2)
  {
  	FILE *hl;
  	hl=fopen(Hell,"r+");
    	fprintf(hl,"%s;%s;%s\n",u.username,
    	u.email, u.nome)	
  }
  
  else if (l==1)
  {
  	FILE *fx;
  	fx=fopen(FX,"r+");
    	fprintf(fx,"%s;%s;%s;%s%d\n", u.username, u.passwd, u.email, u.nome, u.tipo)		
		
   }
   fclose(fx);
}
void remove(user u)
{
	FILE *fx;
	fx=fopen(FX,"r+");
	FILE *t;
	t=fopen("tempfile.txt","w+");
	char s[300];
	char e[300];
	int y=1;
	for (,fgets(s,300,fx),)
	{
		for(i=0;s[i]!=';';i++){
			if(u.username[i]==s[i])
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
	for (,fgets(e,300,t),)
	{
		fprintf(p,"%s/n",t);
	}
	fclose(p);
	fclose(t);
}
void menu_de_registo()
{
        printf("1) Login / autenticação \n");
        printf("0) Sair \n");


}
void menu_prompt()
{
	printf("O que deseja fazer?/n 1) 
void menu()
{
	printf("
int Login(user database[]){
        char username[30];
        char passwd[30];
        char temp1[30];
        char temp2[30];
        char x;
        int u=1;
        int p=1;

        FILE *fp;
        fp = fopen(FX,"r");
        printf("Insira o username \n"); scanf("%s", username);
        printf("Insira a password \n"); scanf("%s",passwd);
        for (int i=0; i < 50; ++i)
        {

                for (int t = 0; temp1[t] != '\0' || database[t].nome != '\0';++t)
                {
                        if (temp1[t] != database[t].nome)
                        {
                                u= 0;
                                break;
                        }
                }

                for (int t = 0; temp2[t] != '\0' || database[t].password != '\0';++t)
                {
                        if (temp2[t] != database[t].password)
                        {
                                p=0;
                                break;
                        }
                }
                if (u + p == 2)
                {
                        printf ("Dados de login aceites/n");
                        // Menu ();
                        return 0;

                }
        }
        printf("Dados de login errados/n");
        printf("Quer tentar outra vez(y/n)?"); scanf("%c",&x);

        if (x=='y')
        {
                Login();
        }
        else {menu_de_registo ();}


}
int isbanned(user u)

{
	user banlist=banlist_init();
		
	for (int i=0,banlist[i],++i)
	{
		if (u.username==banlist[i].username)
			return 1;
	}
	return -1;
}
int BanHammer()
{ 
	user m;
	printf("Qual o utilizador a banir?/n Nome de utilizador:");
	scanf("%c", &m.username);
	printf("/n Email:");
	scanf("%c", &m.email);
	printf("/n Nome:"):
	scanf("%c", &m.nome);
	if (isbanned(m)==-1)
	{	
		grava(2, m);
		return;
	}
	else if(isbanned(m)==1) 
	{
		printf("O utilizador já se encontra banido, quer tentar outra vez? (y/n)");
		char yn;
		scanf("%c", yn);
		if(yn=="y")
			BanHammer();
		else return;
	}
}				
void userlistprompt()
{
	printf("O que deseja fazer? /n 1) Re-imprimir a lista/n 2) Banir utilizador/n 3) Voltar/n");
	
}
void userlist()
{
	database[]=database_init();
	printf("Username, email, nome, tipo");
	for (int i = 0, database[i],++i)
	{
		printf("%s, %s, %s, %d/n" database[i].username, database[i].email, database[i].nome, database[i].tipo);
	}
	userlistprompt();
	int input; 
	scanf("%d", &input);
	switch (input)
	{
		case 1: userlist(); break;
		case 2: BanHammer();break;
		case 3: return;break;
		case default: userlist(); break;
	}
	return						
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
    case default: printf("Erro no input, tente outra vez\n", ); Main();
  }
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
    case default: printf("Erro no input, tente outra vez\n", ); smain();
  }
}


 void freshmeat()
 {
	 pr=fopen(PR,"r");
	 fx=fopen(FX,"r+");
	 hl=fopen(Hell, "r+");
	 user s[];
	 for(,,)
	 {
		
		 if (fgets(s,200,pr)) {
		 	for(,fgets(s,200,pr),)
			{
				fgets(s,200,pr);
				char tempu[30];
				char tempp[30];
				char tempe[100];
				char tempn[30];
				int tempt;
				for (int i=0, s[i] != ';',++i)
				{
					tempu[i]=s[i];	
				}
				for ( i=0, s[i] != ';',++i)
				{
					tempp[i]=s[i];	
				}	
				for (=0, s[i] != ';',++i)
				{
					tempe[i]=s[i];	
				}	
				for (i=0, s[i] != ';',++i)
				{
					tempn[i]=s[i];	
				}	
				tempt=s[i];
				u=new(tempu, tempp, tempe, tempn, tempt);
				if (isbanned(u)==-1&&user_eists(u)==-1)
					grava(1,u);
				
			}
		 }
		 sleep(60);
	 }
 }
       


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
	while(fgets(s,22,fx)){
		for(i=0;s[i]!=';';i++) database[n].nome=s[i];
		database[n].nome=';';
		i++;
		j=0;
		for(;s[i]!=';';i++) database[n].password[j++]=s[i];
		database[n].password[j]=';';
		i++;
		j=0;
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
  FILE *fx; char s[30],n=0,i,j;
	fx=fopen(Hell,"r");
	while(fgets(s,22,fx)){
		for(i=0;s[i]!=';';i++) banlist[n].nome=s[i];
		banlist[n].nome=';';
		
	}
	fclose(fx);
  return banlist;
}
void menu_de_registo()
{
        printf("1) Login / autenticação \n");
        printf("0) Sair \n");


}
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
void userlistprompt()
{
	printf("O que deseja fazer?");
	printf("1) Re-imprimir a lista/n 2) ")
		
void userlist(){
	database[]=database_init();
	printf("Username, email, nome, tipo");
	for (int i = 0, database[i],++i)
	{
		printf("%s, %s, %s, %d/n" database[i].username, database[i].email, database[i].nome, database[i].tipo);
	}
	userlistprompt();

int main()
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
       

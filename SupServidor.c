#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>
#include<dos.h>
#define FX "SupServidor_assets/info_util.txt"
#define PR "Highway/Pedido_de_registo.txt"
#define Hell "highway/banlist.txt"
typedef user{
	char username[30];
	char password[30];
 char email[100];
 char nome[30];
	int tipo;

}
user database_init(){
  user database[1000];
  FILE *fx; char s[22],n=0,i,j;
	fx=fopen(FX,"r");
	while(fgets(s,22,fx)){
		for(i=0;s[i]!=';';i++) database[n].nome=s[i];
		database[n].nome=';';
		i++;
		j=0;
		for(;s[i]!=';';i++) database[n].passwd[j++]=s[i];
		database[n].passwd[j]=';';
		i++;
		j=0;
		n++;
	}
	fclose(fx);
  return database;
}
user new(char name[30],char pass[30], char email[100], char rname[30] ){
 user new;
		for (int i = 0, name[i],++i){new.username[i]=name[i];}
		for (i= 0, pass[i],++i){new.passwd[i]=pass[i];}
		for (i = 0, email[i],++i){new.email[i]=email[i];}
		for (i = 0, rname[i],++i){new.nome[i]=rname[i];}
  return new;
}
user banlist_init(){
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

                for (int t = 0; temp2[t] != '\0' || database[t].passwd != '\0';++t)
                {
                        if (temp2[t] != database[t].passwd)
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
int main()
{
  user database[1000] = database_init();
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
			return 0;
}
void grava(int l, user database[], int n)
{
  int i;
  if (l==0)
  {
  							FILE *fx;
  							fx=fopen(Hell,"r+");
  	}
  	else if (l==1)
  	{
  							FILE *fx;
  							fx=fopen(FX,"r+");
  	}
  for(i=0;i<n;i++)
    fprintf(fx,"%s;%s\n",database[i].nome,
    database[i].passwd;
    fclose(fx);
}
 void freshmeat()
 {
	 pr=fopen(PR,"r");
	 fx=fopen(FX,"r+");
	 hl=fopen(Hell, "r+");
	 user s;
	 for(,,)
	 {

		 if (fgets(s,60,pr)) {
		 	for(,fgets(s,60,pr),)
			{if (isbanned(fprintf("%c" s[]);
			}
		 }
		 sleep(60);
	 }
 }
       {
                        printf ("Dados de login aceites/n");
                        // Menu ();
                        return 0;

                }
        }
        printf("Dados de login errados/n");
        printf
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define FX "SupServidor_assets/info_util.txt"
typedef struct{
	char nome[20];
	char passwd[20];

} user;
user database_init(){
  user database[1000];
  FILE *fx; char s[22],n=0,i,j;
	fx=fopen(FX,"r");
	while(fgets(s,22,fx)){
		for(i=0;s[i]!=';';i++) database[n].nome[i]=s[i];
		database[n].nome[i]=';';
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
void menu_de_registo()
{
        printf("1) Login / autenticação \n");
        printf("0) Sair \n");


}
int Login(user database[]){
        char username[20];
        char passwd[20];
        char temp1[20];
        char temp2[20];
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
void grava(user database[], int n)
{
  int i;
  FILE *fx;
  fx=fopen(FX,"w");
  for(i=0;i<n;i++)
    fprintf(fx,"%s;%s\n",database[i].nome,
    database[i].passwd;
    fclose(fx);
}

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
//user database[50];
//ban banlist[100];
void menu();
/*void listLoader()
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
*/

/*int compare(char a[], char b[])
{
  int i;
  for (i=0; isprint(a[i])||isprint(b[i]); ++i)
    {
      if(( isprint(a[i]) || !isprint(b[i]) || ( !isprint(a[i]) || isprint(b[i]))))
	return -1;
      
      if (a[i]!=b[i])
	{
	  return -1;
	}
      
    }
  return 1;
  }*/

/*struct user database_init()  
{
  user database[50];
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
  return database ;
}
*/
int user_exists(user u)
{
  //struct user database[50] = database_init();
  user database[50];
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
  int z=0;
  int x=1;
  int c;
  while (z<=c)
      {
	x=1;
	// if (compare(database[z].username, u.username)==1 || compare(database[z].nome, u.nome)==1 || compare(database[z].email, u.email)==1)
	//	{
	//  return 1;
	//	}
	// ++z;
	
	//  return -1;
	for (c=0;database[z].username[c];++c)
	  if (database[z].username[c]!=u.username[c])
	    x=0;continue;
	for (c=0;database[z].username[c];++c)
	  if (database[z].nome[c]!=u.nome[c])
	    x=0;continue;
	for (c=0;database[z].username[c];++c)
	  if (database[z].email[c]!=u.email[c])
	    x=0; continue;
	if(x==1)
	  return 1;
	++z;
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
/*
ban banlist_init()
{
  ban banlist[100];
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
      for(;s[i]!=';'; ++i)
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
  return banlist;
}
*/
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
void grava( user u)
{
 


    
      FILE *fx;
      fx=fopen(FX,"r+");
      fprintf(fx,"%s;%s;%s;%s;\n", u.username, u.password, u.email, u.nome);		
      fclose(fx);
      
    
}
void grava2(ban u)
{
  FILE *hl;
  hl=fopen(HELL,"r+");
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
  ban banlist[100];
  FILE *hl; 
  char s[162];
  int n=0;
  int i;
  int j;
  int outu;
  int oute;
  int outn;
  hl=fopen(HELL,"r");
  while(fgets(s,162,hl))
    {
      //fgets(s,162,fx);
      outu=0;
      oute=0;
      outn=0;
      j=0;
      for(;s[i]!=';'; ++i)
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
  fclose(hl);
    int z=0;
  int x=1;
  int c;
  while (z<=c)
      {
	x=1;
	// if (compare(database[z].username, u.username)==1 || compare(database[z].nome, u.nome)==1 || compare(database[z].email, u.email)==1)
	//	{
	//  return 1;
	//	}
	// ++z;
	
	//  return -1;
	for (c=0;banlist[z].username[c];++c)
	  if (banlist[z].username[c]!=u.username[c])
	    x=0;continue;
	for (c=0;banlist[z].username[c];++c)
	  if (banlist[z].nome[c]!=u.nome[c])
	    x=0;continue;
	for (c=0;banlist[z].username[c];++c)
	  if (banlist[z].email[c]!=u.email[c])
	    x=0; continue;
	if(x==1)
	  return 1;
	++z;
      }
  return -1;

 
}
void freshmeat()
{
  
  FILE *pr;
  FILE *fx;
  char s[194];
  pr=fopen(PR,"r+");
  fx=fopen(FX,"r+");
  int i;
  for(;fgets(s,194,pr)!='\0';)
    {
      fgets(s,194,pr);
      user u;
      ban m;
      char tempu[30];
      char tempp[30];
      char tempe[100];
      char tempn[30];
      
      i=0;
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
      //u=new(tempu, tempp, tempe, tempn);
      strcpy(u.username, tempu);
      strcpy(u.password, tempp);
      strcpy(u.email, tempe);
      strcpy(u.nome, tempn);
      strcpy(m.username, u.username);
      strcpy(m.email, u.email);
      strcpy(m.nome, u.nome);
      if ((isbanned(m)!=1) && (user_exists(u)!=1))
	{
	  fprintf(fx,"%s",tempu);
	  fprintf(fx,"%s",tempp);
	  fprintf(fx,"%s",tempe);
	  fprintf(fx,"%s",tempn);

	}
    }
  
  fclose(pr);
  fclose(fx);
  pr=fopen(PR,"w");
  fclose(pr);
  return;
  
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
  ban m;
  user u;
  strcpy(m.username,t1);
  strcpy(m.email,t2);
  strcpy(m.nome,t3);
  strcpy(u.username,t1);
  strcpy(u.email,t2);
  strcpy(u.nome,t3);
  if(user_exists(u)==-1)
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
      grava2(m);
      delet(u);
      return;
    }
  
  if(isbanned(m)==1) 
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
    case 1: userlist(); menu();
    case 2: freshmeat();menu();
    default: break;
    }
  
}
void Login()
{

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



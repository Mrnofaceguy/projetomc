#include <stdio.h>



void menu_de_registo()
{
        printf("1) Login / autenticação \n");
        printf("0) Sair \n");


}
int Login(){
        char username[20];
        char passwd[20];
        char temp1[20];
        char temp2[20];
        char x;
        int u=1;
        int p=1;

        FILE *fp;
        fp = fopen("~/Documents/project_lab/SupServidor_assets/info_util.txt","r");
        printf("Insira o username \n"); scanf("%s", username);
        printf("Insira a password \n"); scanf("%s",passwd);
        for (int i=0; i < 50; ++i)
        {
                fscanf(fp, "%s %s", temp1, temp2);
                for (int t = 0; temp1[t] != '\0' || username[t] != '\0';++t)
                {
                        if (temp1[t] != username[t])
                        {
                                u= 0;
                                break;
                        }
                }

                for (int t = 0; temp2[t] != '\0' || passwd[t] != '\0';++t)
                {
                        if (temp2[t] != passwd[t])
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
        menu_de_registo();
        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
                Login ();
                break;
        case 0:
                return 0;

        }
}

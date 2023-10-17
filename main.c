#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>



void delay(int number_of_seconds)
{

    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

void main()
{
    int f=7,h=7,n,j,c,i,s,z=0,valide=1,random;
    system("color 6");
    char  carte[108][6]= {"1b","1b","2b","2b","3b","3b","4b","4b","5b","5b","6b","6b","7b","7b","8b","8b","9b","9b","0b","blk-b","blk-b","inv-b","inv-b","+2-b","+2-b",
                          "1v","1v","2v","2v","3v","3v","4v","4v","5v","5v","6v","6v","7v","7v","8v","8v","9v","9v","0v","blk-v","blk-v","inv-v","inv-v","+2-v","+2-v",
                          "1r","1r", "2r","2r","3r","3r","4r","4r","5r","5r","6r","6r","7r","7r","8r","8r","9r","9r","0r","blk-r","blk-r","inv-r","inv-r","+2-r","+2-r",
                          "1j","1j", "2j","2j","3j","3j","4j","4j","5j","5j","6j","6j","7j","7j","8j","8j","9j","9j","0j","blk-j","blk-j","inv-j","inv-j","+2-j","+2-j",
                          "joker","joker","joker","joker",
                          "+4","+4","+4","+4"
                         };
    char j1[100][8],j2[100][8];
    char t;
    char cst[8];
    char cj[8];
    int k=1,test=0,ind=1,pt=0,uno=0,uno1=0;
    int u=0,w=0,score1=0,score2=0,tour=1,pass,trouve=0,cc;
    char color;
    printf("|---------------------------------------------------|\n");
    printf("|-------------bienvebue au jeu uno------------------|\n");
    printf("|---------------------------------------------------|\n");
    printf("|---------------------------------------------------|\n");
    printf("|----------veuillez choisir un option---------------|\n");
    printf("|---------------------------------------------------|\n");
    printf("|---------------------------------------------------|\n");
    do{
    printf("  entrer 1 pour jouer contre machine \n  entrer 2 pour jouer contre autre joueuer \n  entrer 3 pour quitter\n ");
    scanf("%i",&n);system("cls");}while((n!=1)&&(n!=3)&&(n!=2));
    system("cls");
    if (n==3)
    {
        printf("au revoir!");
        exit(0);
    }
    else if(n==1)
    {
        for (tour=1; tour<3; tour++)
        {
           char carte[108][6]={"1b","1b","2b","2b","3b","3b","4b","4b","5b","5b","6b","6b","7b","7b","8b","8b","9b","9b","0b","blk-b","blk-b","inv-b","inv-b","+2-b","+2-b",
                          "1v","1v","2v","2v","3v","3v","4v","4v","5v","5v","6v","6v","7v","7v","8v","8v","9v","9v","0v","blk-v","blk-v","inv-v","inv-v","+2-v","+2-v",
                          "1r","1r", "2r","2r","3r","3r","4r","4r","5r","5r","6r","6r","7r","7r","8r","8r","9r","9r","0r","blk-r","blk-r","inv-r","inv-r","+2-r","+2-r",
                          "1j","1j", "2j","2j","3j","3j","4j","4j","5j","5j","6j","6j","7j","7j","8j","8j","9j","9j","0j","blk-j","blk-j","inv-j","inv-j","+2-j","+2-j",
                          "joker","joker","joker","joker",
                          "+4","+4","+4","+4"};

            f=7;
            h=7;
            printf("tour %i\n",tour);

            srand(time(NULL));


            printf("machine:\n");
            for(j=0; j<7; j++)
            {


                random=rand()%107;
                strcpy(j1[j],carte[random]);

                printf("%s\t|",j1[j]);

                for (i=0; i<108-k; i++)
                {
                    if (i>=random)
                        strcpy(carte[i],carte[i+1]);
                }
                k=1;
                (random)=(random-k);
                k++;
            }

            k=1;

            printf("\njoueur2:\n");
            for(j=0; j<7; j++)
            {
                random=rand()%100;
                strcpy(j2[j],carte[random]);

                printf("%s\t|",j2[j]);
                for (i=0; i<100-k; i++)
                {
                    if (i>=random)
                        strcpy(carte[i],carte[i+1]);
                }
                int k=1;
                (random)=(random-k);
                k++;
            }




            random=rand()%93;
            strcpy(cst,carte[random]);
            for (i=0; i<94-k; i++)
            {
                if (i>=random)
                    strcpy(carte[i],carte[i+1]);
            }

            printf("\ncarte sur table: %s\n\n",cst);
            printf(" taper 1 pour commencer");
            scanf("%i",&z);
            system("cls");

            int tj=2;



            do
            {

                srand(time(NULL));

                switch (cst[1])
                {  i=0;

                srand(time(NULL));
                case'j':
                case'v':
                case'r':
                case'b':
                        if (tj%2!=0)
                        {
                            printf("carte sur table :%s\n",cst);
                            printf("machine\n");
                            for (i=0; i<f; i++)
                            {
                                printf(" %i |",ind);
                                ind++;
                            }
                            ind=1;
                            i=1;
                            do
                            {



                                c=i;
                                strcpy(cj,j1[c-1]);i++;
                                if(i>=f)
                                    c=0;
                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                            while(c==0)
                            {
                                for (j=f; j<f+1; j++)
                                {
                                    random=rand()%(92-k);

                                    strcpy(j1[j],carte[random]);
                                    for (int c=0; c<92-k; c++)
                                    {
                                        if (c>=random)
                                        {
                                            strcpy(carte[c],carte[c+1]);

                                        }
                                    }k++;
                                }
                                f=f+1;
                                i=0;
                                system("cls");
                                printf("carte sur table :%s\n",cst);
                                printf("machine\n");

                                for (i=0; i<f; i++)
                                {

                                    printf(" %i |",ind);
                                    ind++;
                                }
                                ind=1;

                                do
                                {


                                    if((cst[0]==j1[f-1][0])||(cst[strlen(cst)-1]==j1[f-1][strlen(j1[f-1])-1])||(j1[f-1][0]=='j')|| (j1[f-1][1]=='4'))
                                    {
                                        strcpy(cj,j1[f-1]);
                                    }
                                    else
                                        c=100;
                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                            }
                            if ((c>0)&&(c<99))
                            {
                                do
                                {

                                    strcpy(cj,j1[c-1]);


                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                                j=0;
                                i=0;
                                strcpy(cst,cj);
                                if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                                {
                                    i=0;
                                    test=0;
                                    while((i<f)&&(test==0))
                                    {
                                        if (strcmp(cj,j1[i])==0)
                                        {
                                            for (j=i; j<f; j++)
                                                strcpy(j1[j],j1[j+1]);
                                            test=1 ;
                                        }
                                        else
                                            i++;
                                    }
                                }
                                f--;

                                tj++;
                            }
                            else if (c>99)
                                tj++;
                            tj++;
                            delay(3);
                        }

                        else if (tj%2==0)
                        {

                            printf("carte sur table :%s\n",cst);
                            printf("joueur2\n");
                            for (i=0; i<h; i++)
                            {
                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            do
                            {
                                printf("\n joueur une carte( 0 pour tirer ) :");
                                scanf("%i",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                            while(c==0)
                            {
                                for (j=h; j<h+1; j++)
                                {
                                    random=rand()%(92-k);

                                    strcpy(j2[j],carte[random]);
                                    for (int c=0;c<92-k;c++)
                                    {
                                        if (c>=random)
                                        {
                                            strcpy(carte[c],carte[c+1]);

                                        }
                                    }k++;
                                }
                                h=h+1;
                                i=0;
                                system("cls");
                                printf("carte sur table :%s\n",cst);
                                printf("joueur2\n");

                                for (i=0; i<h; i++)
                                {

                                    printf("%i:%s\t|",ind,j2[i]);
                                    ind++;
                                }
                                ind=1;

                                strcpy(cj,j2[c-1]);
                                do
                                {
                                    printf("\n joueur une carte (100 pour passer) :");
                                    scanf("%d",&c);
                                    strcpy(cj,j2[c-1]);
                                }
                                while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                            }
                            if ((c>0)&&(c<99))
                            {
                                do
                                {

                                    strcpy(cj,j2[c-1]);


                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                                j=0;
                                i=0;
                                strcpy(cst,cj);
                                if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                                {
                                    i=0;
                                    test=0;
                                    while((i<h)&&(test==0))
                                    {
                                        if (strcmp(cj,j2[i])==0)
                                        {
                                            for (j=i; j<h; j++)
                                                strcpy(j2[j],j2[j+1]);
                                            test=1 ;
                                        }
                                        else
                                            i++;
                                    }
                                }
                                h--;

                                tj++;
                            }
                            else if (c>99)
                                tj++;
                            tj++;
                        }

                    tj++;
                    system("cls");
                    u=0;
                    w=0;
                    break;

                case 'l':
                case 'n':

                    if (tj%2==0)
                    {

                        printf("carte sur table :%s\n",cst);
                        printf("machine\n");
                        for (i=0; i<f; i++)
                        {

                            printf(" %i |",ind);
                            ind++;
                        }
                        ind=1;
                        i=1;
                        do
                        {

                                c=i;
                                strcpy(cj,j1[c-1]);i++;
                                if(i>=f)
                                    c=0;
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=f; j<f+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            f=f+1;
                            i=0;
                            system("cls");
                            printf("carte sur table :%s\n",cst);
                            printf("machine\n");

                            for (i=0; i<f; i++)
                            {

                                printf(" %i ",ind);
                                ind++;
                            }
                            ind=1;

                            do
                                {


                                    if((cst[0]==j1[f-1][0])||(cst[strlen(cst)-1]==j1[f-1][strlen(j1[f-1])-1])||(j1[f-1][0]=='j')|| (j1[f-1][1]=='4'))
                                    {
                                        strcpy(cj,j1[f-1]);
                                    }
                                    else
                                        c=100;
                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));


                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j1[c-1]);

                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);
                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                i=0;
                                test=0;
                                while((i<f)&&(test==0))
                                {
                                    if (strcmp(cj,j1[i])==0)
                                    {
                                        for (j=i; j<f; j++)
                                            strcpy(j1[j],j1[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                            }
                            f--;


                        }
                        else if (c>99)
                            tj++;
delay(3);
                    }

                    else if (tj%2!=0)
                    {


                        printf("carte sur table :%s\n",cst);
                        printf("joueur2\n");
                        for (i=0; i<h; i++)
                        {

                            printf("%i:%s\t|",ind,j2[i]);
                            ind++;
                        }
                        ind=1;
                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j2[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=h; j<h+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            h=h+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur2\n");

                            for (i=0; i<h; i++)
                            {

                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j2[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));
                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j2[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);
                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                i=0;
                                test=0;
                                while((i<h)&&(test==0))
                                {
                                    if (strcmp(cj,j2[i])==0)
                                    {
                                        for (j=i; j<h; j++)
                                            strcpy(j2[j],j2[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                            }
                            h--;


                        }
                        else if (c>99)
                            tj++;
                    }

                    system("cls");

                    u=0;
                    w=0;
                    break;










                case '2':

                    if(tj%2==0)
                    {

                        if    (u==0)
                        {
                            for (j=h; j<h+2; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }

                            h=h+2;
                        }

                        printf("carte sur table :%s\n",cst);
                        printf("machine\n");
                        for (i=0; i<f; i++)
                        {
                             printf(" %i ",ind);
                            ind++;
                        }
                        ind=1;
                        i=1;
                        do
                        {

                             c=i;
                            strcpy(cj,j1[c-1]);i++;
                                if(i>=f)
                                    c=0;
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=f; j<f+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            f=f+1;
                            i=0;
                            system("cls");
                            printf("carte sur table :%s\n",cst);
                            printf("machine\n");

                            for (i=0; i<f; i++)
                            {

                                printf(" %i ",ind);
                                ind++;
                            }
                            ind=1;

                        do
                                {


                                    if((cst[0]==j1[f-1][0])||(cst[strlen(cst)-1]==j1[f-1][strlen(j1[f-1])-1])||(j1[f-1][0]=='j')|| (j1[f-1][1]=='4'))
                                    {
                                        strcpy(cj,j1[f-1]);
                                    }
                                    else
                                        c=100;
                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));


                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j1[c-1]);

                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);

                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                strcpy(cst,cj);

                                i=0;

                                test=0;
                                while((i<f)&&(test==0))
                                {
                                    if (strcmp(cj,j1[i])==0)
                                    {
                                        for (j=i; j<f; j++)
                                            strcpy(j1[j],j1[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                                f--;

                            }


                        }
                        else if (c>99)
                        {
                            w=1;
                            tj++;
                        }
                    delay(3); system("cls");
}

                    if(tj%2!=0)
                    {
                        if    (w==0)
                        {

                            for (j=f; j<f+2; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                } k++;
                            }

                            f=f+2;
                        }

                        printf("carte sur table :%s\n",cst);
                        printf("joueur2\n");
                        for (i=0; i<h; i++)
                        {
                            printf("%i:%s\t|",ind,j2[i]);
                            ind++;
                        }
                        ind=1;

                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j2[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=h; j<h+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            h=h+1;
                            i=0;
                            system("cls");
                            printf("carte sur table :%s\n",cst);
                            printf("joueur2\n");

                            for (i=0; i<h; i++)
                            {

                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j2[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j2[c-1]);

                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);

                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                strcpy(cst,cj);
                                i=0;

                                test=0;
                                while((i<h)&&(test==0))
                                {
                                    if (strcmp(cj,j2[i])==0)
                                    {
                                        for (j=i; j<h; j++)
                                            strcpy(j2[j],j2[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }


                                h--;


                            }


                        }
                        else if (c>99)
                        {
                            u=1;
                            tj++;
                        }
               system("cls");
     }



                    break;












                case 'o':


                    if (tj%2==0)
                    {
                        do
                        {
                            cc=rand()%4;
                            if(cc==1)
                                color='r';
                            else if(cc==2)
                                color='v';
                            else if(cc==3)
                                color='b';
                            else  if(cc==4)
                                color='j';
                        }
                        while((color!='r')&&(color!='j')&&(color!='b')&&(color!='v'));

                        system("cls");


                        switch(color)
                        {
                        case 'r':
                            strcpy(cst,"-r");
                            break;
                        case 'j':
                            strcpy(cst,"-j");
                            break;
                        case 'b':
                            strcpy(cst,"-b");
                            break;
                        case 'v':
                            strcpy(cst,"-v");
                            break;
                        }
                        printf("carte sur table :%s\n",cst);
                        printf("joueur2\n");
                        for (i=0; i<h; i++)
                        {
                            printf("%i:%s\t|",ind,j2[i]);
                            ind++;
                        }
                        ind=1;

                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j2[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=h; j<h+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            h=h+1;
                            i=0;
                            system("cls");
                            printf("carte sur table :%s\n",cst);
                            printf("joueur2\n");

                            for (i=0; i<h; i++)
                            {

                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j2[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j2[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);
                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                i=0;
                                test=0;
                                while((i<h)&&(test==0))
                                {
                                    if (strcmp(cj,j2[i])==0)
                                    {
                                        for (j=i; j<h; j++)
                                            strcpy(j2[j],j2[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                            }
                            h--;

                            tj++;
                        }
                        else if (c>99)
                            tj++;
                        tj++;
                    }
                    else if (tj%2!=0)
                    {

                        do
                        {
                            printf("donner le premier charactere du couleur:\n");
                            scanf("%c",&color);
                        }
                        while((color!='r')&&(color!='j')&&(color!='b')&&(color!='v'));
                        system("cls");

                        switch(color)
                        {
                        case 'r':
                            strcpy(cst,"-r");
                            break;
                        case 'j':
                            strcpy(cst,"-j");
                            break;
                        case 'b':
                            strcpy(cst,"-b");
                            break;
                        case 'v':
                            strcpy(cst,"-v");
                            break;
                        }
                        printf("cate sur table :%s\n",cst);
                        printf("machine\n");
                        for (i=0; i<f; i++)
                        {
                             printf(" %i ",ind);
                            ind++;
                        }
                        ind=1;
                        i=1;
                        do
                        {

                             c=i;
                            strcpy(cj,j1[c-1]);i++;
                                if(i>=f)
                                    c=0;
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=f; j<f+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            f=f+1;
                            i=0;
                            system("cls");
                            printf("carte sur table :%s\n",cst);
                            printf("machine\n");

                            for (i=0; i<f; i++)
                            {

                                 printf(" %i ",ind);
                                ind++;
                            }
                            ind=1;

  do
                                {


                                    if((cst[0]==j1[f-1][0])||(cst[strlen(cst)-1]==j1[f-1][strlen(j1[f-1])-1])||(j1[f-1][0]=='j')|| (j1[f-1][1]=='4'))
                                    {
                                        strcpy(cj,j1[f-1]);
                                    }
                                    else
                                        c=100;
                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));


                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j1[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);
                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                i=0;
                                test=0;
                                while((i<f)&&(test==0))
                                {
                                    if (strcmp(cj,j1[i])==0)
                                    {
                                        for (j=i; j<f; j++)
                                            strcpy(j1[j],j1[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                            }
                            f--;

                            tj++;
                        }
                        else if (c>99)
                            tj++;
                        tj++;
                   delay(3); }
                    tj++;
                    system("cls");
                    u=0;
                    w=0;
                    break;















                case '4':

                    if (tj%2==0)
                    {

 if    (u==0){


                        for (j=h; j<h+4; j++)
                        {
                            random=rand()%(92-k);

                            strcpy(j2[j],carte[random]);
                            for (int c=0; c<92-k; c++)
                            {
                                if (c>=random)
                                {
                                    strcpy(carte[c],carte[c+1]);

                                }
                            }k++;
                        }
                        h=h+4;}
                        do
                        {
                            printf("donner le premier charactere du couleur:\n");
                            cc=rand()%3;
                            if(cc==0)
                                color='r';
                            else if(cc==1)
                                color='v';
                            else if(cc==2)
                                color='b';
                            else  if(cc==3)
                                color='j';
                        }
                        while((color!='r')&&(color!='j')&&(color!='b')&&(color!='v'));
                        system("cls");

                        switch(color)
                        {
                        case 'r':
                            strcpy(cst,"-r");
                            break;
                        case 'j':
                            strcpy(cst,"-j");
                            break;
                        case 'b':
                            strcpy(cst,"-b");
                            break;
                        case 'v':
                            strcpy(cst,"-v");
                            break;
                        }
                        printf("carte sur table :%s\n",cst);
                        printf("machine\n");
                        for (i=0; i<f; i++)
                        {

                             printf(" %i ",ind);
                            ind++;
                        }
                        ind=1;
                        i=1;
                        do
                        {

                             c=i;
                            strcpy(cj,j1[c-1]);i++;
                                if(i>=f)
                                    c=0;
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=f; j<f+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            f=f+1;
                            i=0;
                            system("cls");
                            printf("carte sur table :%s\n",cst);
                            printf("machine\n");

                            for (i=0; i<f; i++)
                            {

                                 printf(" %i ",ind);
                                ind++;
                            }
                            ind=1;
  do
                                {


                                    if((cst[0]==j1[f-1][0])||(cst[strlen(cst)-1]==j1[f-1][strlen(j1[f-1])-1])||(j1[f-1][0]=='j')|| (j1[f-1][1]=='4'))
                                    {
                                        strcpy(cj,j1[f-1]);
                                    }
                                    else
                                        c=100;
                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));


                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j1[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);

                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                strcpy(cst,cj);

                                i=0;

                                test=0;
                                while((i<f)&&(test==0))
                                {
                                    if (strcmp(cj,j1[i])==0)
                                    {
                                        for (j=i; j<f; j++)
                                            strcpy(j1[j],j1[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                                f--;

                            }

                            tj++;
                        }
                        else if (c>99)
                            tj++;
                        tj++;
                 delay(3);   }

                    else if (tj%2!=0)
                    {

 if    (w==0){
                        for (j=f; j<f+4; j++)
                        {
                            random=rand()%(92-k);

                            strcpy(j1[j],carte[random]);
                            for (int c=0; c<92-k; c++)
                            {
                                if (c>=random)
                                {
                                    strcpy(carte[c],carte[c+1]);

                                }
                            }k++;
                        }
                        f=f+4;}
                        do
                        {
                            printf("donner le premier charactere du couleur:\n");
                            scanf("%c",&color);
                        }
                        while((color!='r')&&(color!='j')&&(color!='b')&&(color!='v'));
                        system("cls");

                        switch(color)
                        {
                        case 'r':
                            strcpy(cst,"-r");
                            break;
                        case 'j':
                            strcpy(cst,"-j");
                            break;
                        case 'b':
                            strcpy(cst,"-b");
                            break;

                        case 'v':
                            strcpy(cst,"-v");
                            break;
                        }
                        printf("carte sur table :%s\n",cst);
                        printf("joueur2\n");
                        for (i=0; i<h; i++)
                        {

                            printf("%i:%s\t|",ind,j2[i]);
                            ind++;
                        }
                        ind=1;
                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j2[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=h; j<h+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            h=h+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur2\n");


                            for (i=0; i<h; i++)
                            {

                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j2[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j2[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);

                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                strcpy(cst,cj);

                                i=0;

                                test=0;
                                while((i<h)&&(test==0))
                                {
                                    if (strcmp(cj,j2[i])==0)
                                    {
                                        for (j=i; j<h; j++)
                                            strcpy(j2[j],j2[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                                h--;

                            }

                            tj++;
                        }
                        else if (c>99)
                            tj++;
                        tj++;
                    }




                    system("cls");


                    break;





                }
                if(f==2) uno=0;
                if((f==1)&&(uno==0))
                {  printf("taper u pour UNO\n");

                    i=0;


                     while(i < 3 && (t!= 'u')||(t!= 'U'))
                    {
                        // delay of one second
                        delay(1);
                        if(i==2)
                        {
                            t='u';
                            printf("%c\n", t);
                        }
                        printf("%d seconds have passed\n", i + 1);
                        i++;
                    }
                    if((t == 'u'||t== 'U'))
                    {
                        printf("\nUNO\n");

                    }
                    else
                    {
                        printf(" \n+ 2 pour joueur 1 \n");
                        for (j=f; j<f+2; j++)
                        {
                            random=rand()%(92-k);

                            strcpy(j1[j],carte[random]);
                            for (int c=0; c<92-k; c++)
                            {
                                if (c>=random)
                                {
                                    strcpy(carte[c],carte[c+1]);

                                }
                            } k++;
                        }

                        f=f+2;


                    }
                    t=""; uno=1;
              delay(3);  }


                if(h==2) uno1=0;
                if((h==1)&&(uno1==0))
                {
                    printf("taper u pour UNO\n");

                    i=0;


                    while(i < 3 && (t!= 'u'||t!= 'U'))
                    {
                        // delay of one second
                        delay(1);
                        if(kbhit())
                        {
                            t = getch();
                            printf("%c\n", t);
                        }
                        printf("%d seconds have passed\n", i + 1);
                        i++;
                    }
                    if((t == 'u')||(t== 'U'))
                    {
                        printf("\nUNO\n");

                    }
                    else
                    {
                        printf(" \n+ 2 pour joueur 2 \n");
                        for (j=h; j<h+2; j++)
                        {
                            random=rand()%(92-k);

                            strcpy(j2[j],carte[random]);
                            for (int c=0; c<92-k; c++)
                            {
                                if (c>=random)
                                {
                                    strcpy(carte[c],carte[c+1]);

                                }
                            }k++;
                        }

                        h=h+2;

                    }
                    t=""; uno1=1;

              delay(3);  }
            }
            while((f!=0)&&(h!=0));

            if (h==0)
            {
                printf("\njouer 2:score%i",score2);
                for (i=0; i<f; i++)
                {
                    if((j1[i][1]=='2')||(j1[i][1]=='n')||(j1[i][1]=='l'))
                        score1=score1+20;

                    else if((j1[i][1]=='4')||(j1[i][1]=='o'))
                        score1=score1+50;
                    else
                    {
                        switch(j1[i][0])
                        {
                        case '0':
                            score1=score1+0;
                            break;
                        case '1':
                            score1=score1+1;
                            break;
                        case '2':
                            score1=score1+2;
                            break;
                        case '3':
                            score1=score1+3;
                            break;
                        case '4':
                            score1=score1+4;
                            break;
                        case '5':
                            score1=score1+5;
                            break;
                        case '6':
                            score1=score1+6;
                            break;
                        case '7':
                            score1=score1+7;
                            break;
                        case '8':
                            score1=score1+8;
                            break;
                        case '9':
                            score1=score1+9;
                            break;

                        }
                    }
                }
                printf("\njoueur 1:score %i",score1);
                printf("\njoueur 2 gagne tour %i",tour);
            }


            else if (f==0)
            {
                printf("\njouer 1:score:%i",score1);
                for (i=0; i<h; i++)
                {
                    if((j2[i][1]=='2')||(j2[i][1]=='n')||(j2[i][1]=='l'))
                        score2=score2+20;

                    else if((j2[i][1]=='4')||(j2[i][1]=='o'))
                        score2=score2+50;
                    else
                    {
                        switch(j2[i][0])
                        {
                        case '0':
                            score2=score2+0;
                            break;
                        case '1':
                            score2=score2+1;
                            break;
                        case '2':
                            score2=score2+2;
                            break;
                        case '3':
                            score2=score2+3;
                            break;
                        case '4':
                            score2=score2+4;
                            break;
                        case '5':
                            score2=score2+5;
                            break;
                        case '6':
                            score2=score2+6;
                            break;
                        case '7':
                            score2=score2+7;
                            break;
                        case '8':
                            score2=score2+8;
                            break;
                        case '9':
                            score2=score2+9;
                            break;

                        }
                    }

                }
                printf("\njoueur 2:score %i",score2);
                printf("\njoueur 1 gagne tour %i",tour);
            }




        if (tour==1){
            do
            {
                printf("\ntaper 1 pour jouer un autre tour:");
                scanf("%i",&pass);
            }
            while(pass!=1);


            system("cls");
        }
        if (score1>score2)
            printf("\n joueur 1 gagne ");
        else
            printf("\n joueur 2 gagne ");
    }
    }











    else if (n==2)
    {

        for (tour=1; tour<3; tour++)
        {
         char  carte[108][6]= {"1b","1b","2b","2b","3b","3b","4b","4b","5b","5b","6b","6b","7b","7b","8b","8b","9b","9b","0b","blk-b","blk-b","inv-b","inv-b","+2-b","+2-b",
                          "1v","1v","2v","2v","3v","3v","4v","4v","5v","5v","6v","6v","7v","7v","8v","8v","9v","9v","0v","blk-v","blk-v","inv-v","inv-v","+2-v","+2-v",
                          "1r","1r", "2r","2r","3r","3r","4r","4r","5r","5r","6r","6r","7r","7r","8r","8r","9r","9r","0r","blk-r","blk-r","inv-r","inv-r","+2-r","+2-r",
                          "1j","1j", "2j","2j","3j","3j","4j","4j","5j","5j","6j","6j","7j","7j","8j","8j","9j","9j","0j","blk-j","blk-j","inv-j","inv-j","+2-j","+2-j",
                          "joker","joker","joker","joker",
                          "+4","+4","+4","+4"
                         };
           f=7;
           h=7;


            printf("tour %i\n",tour);

            srand(time(NULL));


            printf("joueur1:\n");
            for(j=0; j<7; j++)
            {


                random=rand()%107;
                strcpy(j1[j],carte[random]);

                printf("%s\t|",j1[j]);

                for (i=0; i<108-k; i++)
                {
                    if (i>=random)
                        strcpy(carte[i],carte[i+1]);
                }
                k=1;
                (random)=(random-k);
                k++;
            }

            k=1;

            printf("\njoueur2:\n");
            for(j=0; j<7; j++)
            {
                random=rand()%100;
                strcpy(j2[j],carte[random]);

                printf("%s\t|",j2[j]);
                for (i=0; i<100-k; i++)
                {
                    if (i>=random)
                        strcpy(carte[i],carte[i+1]);
                }
                int k=1;
                (random)=(random-k);
                k++;
            }




            random=rand()%93;
            strcpy(cst,carte[random]);
            for (i=0; i<94-k; i++)
            {
                if (i>=random)
                    strcpy(carte[i],carte[i+1]);
            }
            printf("\ncarte sur table: %s\n\n",cst);
            printf(" taper 1 pour commencer");
            scanf("%i",&z);
            system("cls");

            int tj=2;



            do
            {
if(f==2) uno=0;
if(h==2) uno1=0;
                srand(time(NULL));

                switch (cst[1])
                {
                    srand(time(NULL));
                case'j':
                case'v':
                case'r':
                case'b':
                        if (tj%2!=0)
                        {


                            printf("cate sur table :%s\n",cst);
                            printf("joueur1\n");
                            for (i=0; i<f; i++)
                            {
                                printf("%i:%s\t|",ind,j1[i]);
                                ind++;
                            }
                            ind=1;
                            do
                            {
                                printf("\n joueur une carte( 0 pour tirer )  :");
                                scanf("%i",&c);
                                strcpy(cj,j1[c-1]);
                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                            while(c==0)
                            {
                                for (j=f; j<f+1; j++)
                                {
                                    random=rand()%(92-k);

                                    strcpy(j1[j],carte[random]);
                                    for (int c=0; c<92-k; c++)
                                    {
                                        if (c>=random)
                                        {
                                            strcpy(carte[c],carte[c+1]);

                                        }
                                    }k++;
                                }
                                f=f+1;
                                i=0;
                                system("cls");
                                printf("cate sur table :%s\n",cst);
                                printf("joueur1\n");

                                for (i=0; i<f; i++)
                                {

                                    printf("%i:%s\t|",ind,j1[i]);
                                    ind++;
                                }
                                ind=1;

                                strcpy(cj,j1[c-1]);
                                do
                                {
                                    printf("\n joueur une carte (100 pour passer) :");
                                    scanf("%d",&c);
                                    strcpy(cj,j1[c-1]);
                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                            }
                            if ((c>0)&&(c<99))
                            {
                                do
                                {

                                    strcpy(cj,j1[c-1]);


                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                                j=0;
                                i=0;
                                strcpy(cst,cj);
                                if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                                {
                                    i=0;
                                    test=0;
                                    while((i<f)&&(test==0))
                                    {
                                        if (strcmp(cj,j1[i])==0)
                                        {
                                            for (j=i; j<f; j++)
                                                strcpy(j1[j],j1[j+1]);
                                            test=1 ;
                                        }
                                        else
                                            i++;
                                    }
                                }
                                f--;

                                tj++;
                            }
                            else if (c>99)
                                tj++;
                            tj++;
                        }

                        else if (tj%2==0)
                        {

                            printf("cate sur table :%s\n",cst);
                            printf("joueur2\n");
                            for (i=0; i<h; i++)
                            {
                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            do
                            {
                                printf("\n joueur une carte( 0 pour tirer ) :");
                                scanf("%i",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                            while(c==0)
                            {
                                for (j=h; j<h+1; j++)
                                {
                                    random=rand()%(92-k);

                                    strcpy(j2[j],carte[random]);
                                    for (int c=0; c<92-k; c++)
                                    {
                                        if (c>=random)
                                        {
                                            strcpy(carte[c],carte[c+1]);

                                        }
                                    }k++;
                                }
                                h=h+1;
                                i=0;
                                system("cls");
                                printf("cate sur table :%s\n",cst);
                                printf("joueur2\n");

                                for (i=0; i<h; i++)
                                {

                                    printf("%i:%s\t|",ind,j2[i]);
                                    ind++;
                                }
                                ind=1;

                                strcpy(cj,j2[c-1]);
                                do
                                {
                                    printf("\n joueur une carte (100 pour passer) :");
                                    scanf("%d",&c);
                                    strcpy(cj,j2[c-1]);
                                }
                                while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                            }
                            if ((c>0)&&(c<99))
                            {
                                do
                                {

                                    strcpy(cj,j2[c-1]);


                                }
                                while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                                j=0;
                                i=0;
                                strcpy(cst,cj);
                                if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                                {
                                    i=0;
                                    test=0;
                                    while((i<h)&&(test==0))
                                    {
                                        if (strcmp(cj,j2[i])==0)
                                        {
                                            for (j=i; j<h; j++)
                                                strcpy(j2[j],j2[j+1]);
                                            test=1 ;
                                        }
                                        else
                                            i++;
                                    }
                                }
                                h--;

                                tj++;
                            }
                            else if (c>99)
                                tj++;
                            tj++;
                        }

                    tj++;
                    system("cls");
                    u=0;
                    w=0;
                    break;








                case 'l':
                case 'n':
                    c=1;
                    if (tj%2==0)
                    {

                        printf("cate sur table :%s\n",cst);
                        printf("joueur1\n");
                        for (i=0; i<f; i++)
                        {

                            printf("%i:%s\t|",ind,j1[i]);
                            ind++;
                        }
                        ind=1;
                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j1[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=f; j<f+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            f=f+1;
                            i=0;
                            system("cls");
                            printf("carte sur table :%s\n",cst);
                            printf("joueur1\n");

                            for (i=0; i<f; i++)
                            {

                                printf("%i:%s\t|",ind,j1[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j1[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j1[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j1[c-1]);

                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);
                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                i=0;
                                test=0;
                                while((i<f)&&(test==0))
                                {
                                    if (strcmp(cj,j1[i])==0)
                                    {
                                        for (j=i; j<f; j++)
                                            strcpy(j1[j],j1[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                            }
                            f--;


                        }
                        else if (c>99)
                            tj++;
                        tj++;
                    }

                    else if (tj%2!=0)
                    {


                        printf("cate sur table :%s\n",cst);
                        printf("joueur2\n");
                        for (i=0; i<h; i++)
                        {

                            printf("%i:%s\t|",ind,j2[i]);
                            ind++;
                        }
                        ind=1;
                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j2[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=h; j<h+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            h=h+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur2\n");

                            for (i=0; i<h; i++)
                            {

                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j2[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));
                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j2[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);
                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                i=0;
                                test=0;
                                while((i<h)&&(test==0))
                                {
                                    if (strcmp(cj,j2[i])==0)
                                    {
                                        for (j=i; j<h; j++)
                                            strcpy(j2[j],j2[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                            }
                            h--;


                        }
                        else if (c>99)
                            tj++;
                        tj++;
                    }
                    tj++;
                    system("cls");

                    u=0;
                    w=0;
                    break;










                case '2':

                    if(tj%2==0)
                    {

                        if    (u==0)
                        {
                            for (j=h; j<h+2; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }

                            h=h+2;
                        }

                        printf("cate sur table :%s\n",cst);
                        printf("joueur1\n");
                        for (i=0; i<f; i++)
                        {
                            printf("%i:%s\t|",ind,j1[i]);
                            ind++;
                        }
                        ind=1;

                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j1[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=f; j<f+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            f=f+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur1\n");

                            for (i=0; i<f; i++)
                            {

                                printf("%i:%s\t|",ind,j1[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j1[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j1[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j1[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);

                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                strcpy(cst,cj);

                                i=0;

                                test=0;
                                while((i<f)&&(test==0))
                                {
                                    if (strcmp(cj,j1[i])==0)
                                    {
                                        for (j=i; j<f; j++)
                                            strcpy(j1[j],j1[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                                f--;

                            }


                        }
                        else if (c>99)
                        {
                            w=1;
                            tj++;
                        }
                  system("cls");  }

                    if(tj%2!=0)
                    {
                        if    (w==0)
                        {

                            for (j=f; j<f+2; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }

                            f=f+2;
                        }

                        printf("cate sur table :%s\n",cst);
                        printf("joueur2\n");
                        for (i=0; i<h; i++)
                        {
                            printf("%i:%s\t|",ind,j2[i]);
                            ind++;
                        }
                        ind=1;

                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j2[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=h; j<h+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            h=h+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur2\n");

                            for (i=0; i<h; i++)
                            {

                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j2[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j2[c-1]);

                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);

                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                strcpy(cst,cj);
                                i=0;

                                test=0;
                                while((i<h)&&(test==0))
                                {
                                    if (strcmp(cj,j2[i])==0)
                                    {
                                        for (j=i; j<h; j++)
                                            strcpy(j2[j],j2[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }


                                h--;


                            }


                        }
                        else if (c>99)
                        {
                            u=1;
                            tj++;
                        }
                    system("cls");  }




                    break;












                case 'o':
                    do
                    {
                        printf("donner le premier charactere du couleur:\n");
                        scanf("%c",&color);
                    }
                    while((color!='r')&&(color!='j')&&(color!='b')&&(color!='v'));
                    system("cls");

                    if (tj%2==0)
                    {



                        switch(color)
                        {
                        case 'r':
                            strcpy(cst,"-r");
                            break;
                        case 'j':
                            strcpy(cst,"-j");
                            break;
                        case 'b':
                            strcpy(cst,"-b");
                            break;
                        case 'v':
                            strcpy(cst,"-v");
                            break;
                        }
                        printf("cate sur table :%s\n",cst);
                        printf("joueur2\n");
                        for (i=0; i<h; i++)
                        {
                            printf("%i:%s\t|",ind,j2[i]);
                            ind++;
                        }
                        ind=1;

                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j2[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=h; j<h+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            h=h+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur2\n");

                            for (i=0; i<h; i++)
                            {

                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j2[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j2[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);
                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                i=0;
                                test=0;
                                while((i<h)&&(test==0))
                                {
                                    if (strcmp(cj,j2[i])==0)
                                    {
                                        for (j=i; j<h; j++)
                                            strcpy(j2[j],j2[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                            }
                            h--;

                            tj++;
                        }
                        else if (c>99)
                            tj++;
                        tj++;
                    }
                    else if (tj%2!=0)
                    {

                        switch(color)
                        {
                        case 'r':
                            strcpy(cst,"-r");
                            break;
                        case 'j':
                            strcpy(cst,"-j");
                            break;
                        case 'b':
                            strcpy(cst,"-b");
                            break;
                        case 'v':
                            strcpy(cst,"-v");
                            break;
                        }
                        printf("cate sur table :%s\n",cst);
                        printf("joueur1\n");
                        for (i=0; i<f; i++)
                        {
                            printf("%i:%s\t|",ind,j1[i]);
                            ind++;
                        }
                        ind=1;

                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j1[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=f; j<f+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                } k++;
                            }
                            f=f+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur1\n");

                            for (i=0; i<f; i++)
                            {

                                printf("%i:%s\t|",ind,j1[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j1[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j1[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j1[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);
                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                i=0;
                                test=0;
                                while((i<f)&&(test==0))
                                {
                                    if (strcmp(cj,j1[i])==0)
                                    {
                                        for (j=i; j<f; j++)
                                            strcpy(j1[j],j1[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                            }
                            f--;

                            tj++;
                        }
                        else if (c>99)
                            tj++;
                        tj++;
                    }
                    tj++;
                    system("cls");
                    u=0;
                    w=0;
                    break;















                case '4':

                    if (tj%2==0)
                    {




                        for (j=h; j<h+4; j++)
                        {
                            random=rand()%(92-k);

                            strcpy(j2[j],carte[random]);
                            for (int c=0; c<92-k; c++)
                            {
                                if (c>=random)
                                {
                                    strcpy(carte[c],carte[c+1]);

                                }
                            }k++;
                        }
                        h=h+4;
                        do
                        {
                            printf("donner le premier charactere du couleur:\n");
                            scanf("%c",&color);
                        }
                        while((color!='r')&&(color!='j')&&(color!='b')&&(color!='v'));
                        system("cls");

                        switch(color)
                        {
                        case 'r':
                            strcpy(cst,"-r");
                            break;
                        case 'j':
                            strcpy(cst,"-j");
                            break;
                        case 'b':
                            strcpy(cst,"-b");
                            break;
                        case 'v':
                            strcpy(cst,"-v");
                            break;
                        }
                        printf("cate sur table :%s\n",cst);
                        printf("joueur1\n");
                        for (i=0; i<f; i++)
                        {

                            printf("%i:%s\t|",ind,j1[i]);
                            ind++;
                        }
                        ind=1;
                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j1[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=f; j<f+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j1[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                } k++;
                            }
                            f=f+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur1\n");

                            for (i=0; i<f; i++)
                            {

                                printf("%i:%s\t|",ind,j1[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j1[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j1[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j1[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);

                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                strcpy(cst,cj);

                                i=0;

                                test=0;
                                while((i<f)&&(test==0))
                                {
                                    if (strcmp(cj,j1[i])==0)
                                    {
                                        for (j=i; j<f; j++)
                                            strcpy(j1[j],j1[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                                f--;

                            }

                            tj++;
                        }
                        else if (c>99)
                            tj++;
                        tj++;
                    }

                    else if (tj%2!=0)
                    {


                        for (j=f; j<f+4; j++)
                        {
                            random=rand()%(92-k);

                            strcpy(j1[j],carte[random]);
                            for (int c=0; c<92-k; c++)
                            {
                                if (c>=random)
                                {
                                    strcpy(carte[c],carte[c+1]);

                                }
                            }k++;
                        }
                        f=f+4;
                        do
                        {
                            printf("donner le premier charactere du couleur:\n");
                            scanf("%c",&color);
                        }
                        while((color!='r')&&(color!='j')&&(color!='b')&&(color!='v'));
                        system("cls");

                        switch(color)
                        {
                        case 'r':
                            strcpy(cst,"-r");
                            break;
                        case 'j':
                            strcpy(cst,"-j");
                            break;
                        case 'b':
                            strcpy(cst,"-b");
                            break;

                        case 'v':
                            strcpy(cst,"-v");
                            break;
                        }
                        printf("cate sur table :%s\n",cst);
                        printf("joueur2\n");
                        for (i=0; i<h; i++)
                        {

                            printf("%i:%s\t|",ind,j2[i]);
                            ind++;
                        }
                        ind=1;
                        do
                        {
                            printf("\n joueur une carte :");
                            scanf("%i",&c);
                            strcpy(cj,j2[c-1]);
                        }
                        while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=0));
                        while(c==0)
                        {
                            for (j=h; j<h+1; j++)
                            {
                                random=rand()%(92-k);

                                strcpy(j2[j],carte[random]);
                                for (int c=0; c<92-k; c++)
                                {
                                    if (c>=random)
                                    {
                                        strcpy(carte[c],carte[c+1]);

                                    }
                                }k++;
                            }
                            h=h+1;
                            i=0;
                            system("cls");
                            printf("cate sur table :%s\n",cst);
                            printf("joueur2\n");


                            for (i=0; i<h; i++)
                            {

                                printf("%i:%s\t|",ind,j2[i]);
                                ind++;
                            }
                            ind=1;

                            strcpy(cj,j2[c-1]);
                            do
                            {
                                printf("\n joueur une carte (100 pour passer) :");
                                scanf("%d",&c);
                                strcpy(cj,j2[c-1]);
                            }
                            while((c==0)||(cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4')&&(c!=100));

                        }
                        if ((c>0)&&(c<99))
                        {
                            do
                            {

                                strcpy(cj,j2[c-1]);


                            }
                            while((cst[0]!=cj[0])&&(cst[strlen(cst)-1]!=cj[strlen(cj)-1])&&(cj[0]!='j')&&(cj[1]!='4'));
                            j=0;
                            i=0;
                            strcpy(cst,cj);

                            if ((cst[0]==cj[0])||(cst[strlen(cst)-1]==cj[strlen(cj)-1])||(cj[0]=='j')||(cj[1]=='4'))
                            {
                                strcpy(cst,cj);

                                i=0;

                                test=0;
                                while((i<h)&&(test==0))
                                {
                                    if (strcmp(cj,j2[i])==0)
                                    {
                                        for (j=i; j<h; j++)
                                            strcpy(j2[j],j2[j+1]);
                                        test=1 ;
                                    }
                                    else
                                        i++;
                                }
                                h--;

                            }

                            tj++;
                        }
                        else if (c>99)
                            tj++;
                        tj++;
                    }




                    system("cls");

                    u=0;
                    w=0;
                    break;





                }
          if(f==2) uno=0;
                if((f==1)&&(uno==0))
                {printf("\n taper U pour UNO \n");

                    i=0;


                    while(i < 3 && (t!= 'u' || t!= 'U'))
                    {

                        delay(1);
                        if(kbhit())
                        {
                            t = getch();
                            printf("%c\n", t);
                        }
                        printf("%d seconds have passed\n", i + 1);
                        i++;
                    }
                    if((t == 'u')||(t== 'U'))
                    {
                        printf("\nUNO\n");

                    }
                    else
                    {
                        printf(" \n+ 2 pour joueur 1 \n");
                        for (j=f; j<f+2; j++)
                        {
                            random=rand()%(92-k);

                            strcpy(j1[j],carte[random]);
                            for (int c=0; c<92-k; c++)
                            {
                                if (c>=random)
                                {
                                    strcpy(carte[c],carte[c+1]);

                                }
                            }k++;
                        }

                        f=f+2;


                    }
                    t="";
                    uno=1;
                }


              if(h==2) uno1=0;
              else if((h==1)&&(uno1==0))
                {printf("\n taper U pour UNO \n");

                    i=0;


                     while(i < 3 && (t!= 'u' || t!= 'U'))
                    {
                        // delay of one second
                        delay(1);
                        if(kbhit())
                        {
                            t = getch();
                            printf("%c\n", t);
                        }
                        printf("%d seconds have passed\n", i + 1);
                        i++;
                    }
                    if((t == 'u')||(t== 'U'))
                    {
                        printf("\nUNO\n");

                    }
                    else
                    {
                        printf(" \n+ 2 pour joueur 2 \n");
                        for (j=h; j<h+2; j++)
                        {
                            random=rand()%(92-k);

                            strcpy(j2[j],carte[random]);
                            for (int c=0; c<92-k; c++)
                            {
                                if (c>=random)
                                {
                                    strcpy(carte[c],carte[c+1]);

                                }
                            }k++;
                        }

                        h=h+2;

                    }
                    t="";
                  uno1=1;
                }
            }
            while((f!=0)&&(h!=0));

            if (h==0)
            {
                printf("\njouer 2:score%i",score2);
                for (i=0; i<f; i++)
                {
                    if((j1[i][1]=='2')||(j1[i][1]=='n')||(j1[i][1]=='l'))
                        score1=score1+20;

                    else if((j1[i][1]=='4')||(j1[i][1]=='o'))
                        score1=score1+50;
                    else
                    {
                        switch(j1[i][0])
                        {
                        case '0':
                            score1=score1+0;
                            break;
                        case '1':
                            score1=score1+1;
                            break;
                        case '2':
                            score1=score1+2;
                            break;
                        case '3':
                            score1=score1+3;
                            break;
                        case '4':
                            score1=score1+4;
                            break;
                        case '5':
                            score1=score1+5;
                            break;
                        case '6':
                            score1=score1+6;
                            break;
                        case '7':
                            score1=score1+7;
                            break;
                        case '8':
                            score1=score1+8;
                            break;
                        case '9':
                            score1=score1+9;
                            break;

                        }
                    }
                }
                printf("\njoueur 1:score %i",score1);
                printf("\njoueur 2 gagne tour %i",tour);
            }


            else if (f==0)
            {
                printf("\njouer 1:score:%i",score1);
                for (i=0; i<h; i++)
                {
                    if((j2[i][1]=='2')||(j2[i][1]=='n')||(j2[i][1]=='l'))
                        score2=score2+20;

                    else if((j2[i][1]=='4')||(j2[i][1]=='o'))
                        score2=score2+50;
                    else
                    {
                        switch(j2[i][0])
                        {
                        case '0':
                            score2=score2+0;
                            break;
                        case '1':
                            score2=score2+1;
                            break;
                        case '2':
                            score2=score2+2;
                            break;
                        case '3':
                            score2=score2+3;
                            break;
                        case '4':
                            score2=score2+4;
                            break;
                        case '5':
                            score2=score2+5;
                            break;
                        case '6':
                            score2=score2+6;
                            break;
                        case '7':
                            score2=score2+7;
                            break;
                        case '8':
                            score2=score2+8;
                            break;
                        case '9':
                            score2=score2+9;
                            break;

                        }
                    }

                }
                printf("\njoueur 2:score %i",score2);
                printf("\njoueur 1 gagne tour %i",tour);
            }




               if (tour==1){
            do
            {
                printf("\ntaper 1 pour jouer un autre tour:\n");
                scanf("%i",&pass);
            }
            while(pass!=1);}


            system("cls");
        }
        if (score1>score2)
            printf("joueur 2 gagne ");
        else
            printf("joueur 1 gagne ");
    }
}



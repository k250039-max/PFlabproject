#include<stdio.h>
int diceroller()
{
    int x=((rand()%6)+1);
    return x;
}
void printboard(int board[],int pos1,int pos2)
{
    int i;
    for(i=100;i>0;i--)
    {   
        if(i==pos1&&i==pos2)
        {
            printf("\033[33;2m%d\033[0m ", i);
        }
        else if (i==pos2)
        {
            printf("\033[90m%d\033[0m ", i);
        }
        else if(i==pos1)
        {
             printf("\033[95m%d\033[0m ", i); 
        }
        else{
            int color=board[i-1];
            if(color==-1)
            {
                printf("\033[31m");
            }
        else if(color==1)
            {
                printf("\033[32m");
            }
            else
            {
                printf("\033[0m");
            }
            printf("%d\033[0m ",i);
            if((i)%10==0&&i!=100 )
            {
                printf("\n");
            }
        }
        
        
    }
    printf("\n");
}
void threeprintboard(int board[], int pos1, int pos2, int pos3)
{
    for (int i = 100; i > 0; i--)
    {   
        if (i == pos1 && i == pos2 && i == pos3)
            printf("\033[33;2m%d\033[0m ", i);
        else if (i == pos1 && i == pos2)
            printf("\033[33;2m%d\033[0m ", i);
        else if (i == pos1 && i == pos3)
            printf("\033[93m%d\033[0m ", i);
        else if (i == pos2 && i == pos3)
            printf("\033[93m%d\033[0m ", i);
        else if (i == pos3)
            printf("\033[93m%d\033[0m ", i);
        else if (i == pos2)
            printf("\033[90m%d\033[0m ", i);
        else if (i == pos1)
            printf("\033[95m%d\033[0m ", i);
        else
        {
            int color = board[i-1];
            if (color == -1)
                printf("\033[31m");
            else if (color == 1)
                printf("\033[32m");
            else
                printf("\033[0m");
            
            printf("%d\033[0m ", i);

            if (i % 10 == 0 && i != 100)
                printf("\n");
        }
    }
    printf("\n");
}
void fourprintboard(int board[], int pos1, int pos2, int pos3, int pos4)
{
    for (int i = 100; i > 0; i--)
    {   
        if (i == pos1 && i == pos2 && i == pos3 && i == pos4)
            printf("\033[33;2m%d\033[0m ", i);
        else if ((i == pos1 && i == pos2 && i == pos3) || (i == pos1 && i == pos2 && i == pos4) || (i == pos1 && i == pos3 && i == pos4) || (i == pos2 && i == pos3 && i == pos4))
            printf("\033[33;2m%d\033[0m ", i);
        else if ((i == pos1 && i == pos2) || (i == pos1 && i == pos3) || (i == pos2 && i == pos3))
            printf("\033[93m%d\033[0m ", i);
        else if ((i == pos1 && i == pos4) || (i == pos2 && i == pos4) || (i == pos3 && i == pos4))
            printf("\033[93m%d\033[0m ", i);
        else if (i == pos4)
            printf("\033[34;2m%d\033[0m ", i);
        else if (i == pos3)
            printf("\033[93m%d\033[0m ", i);
        else if (i == pos2)
            printf("\033[90m%d\033[0m ", i);
        else if (i == pos1)
            printf("\033[95m%d\033[0m ", i);
        else
        {
            int color = board[i-1];
            if (color == -1)
                printf("\033[31m");
            else if (color == 1)
                printf("\033[32m");
            else
                printf("\033[0m");
            
            printf("%d\033[0m ", i);

            if (i % 10 == 0 && i != 100)
                printf("\n");
        }
    }
    printf("\n");
}
int twoplayer()
{
    srand(time(NULL));
    int pos1,pos2,pos3,dice,role1,role2;
    pos1=1,pos2=1,pos3=1;
    int board[100]={0};
    //snakes
    board[98]=-1,board[96]=-1,board[85]=-1,board[66]=-1,board[45]=-1,board[42]=-1,board[29]=-1;
    //ladders
    board[64]=1,board[43]=1,board[14]=1,board[3]=1,board[34]=1;
    while (1)
    {
        printf("Enter 1 to roll dice for player 1:");
        scanf("%d",&role1);

        if(role1==1)
        {

            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos1+dice>100)
            { 
                printf("\nMove not possible!");
            }
            else
            {   
                pos1+=dice;
                if(pos1==99)
                {
                    pos1 =  41;
                }
                else if(pos1==95)
                {
                    pos1=77;
                }
                else if(pos1==85)
                {
                    pos1=53;
                }
                else if(pos1==66)
                {
                    pos1=45;
                }
                else if(pos1==43)
                {
                    pos1=17;
                }
                else if(pos1==40)
                {
                    pos1=3;
                }
                else if(pos1==27)
                {
                    pos1=5;
                }
                else if(pos1==62)
                {
                    pos1=81;
                }
                else if(pos1==42)
                {
                    pos1=63;
                }
                else if(pos1==13)
                {
                    pos1=46;
                }
                else if(pos1==4)
                {
                    pos1=25;
                }
                else if(pos1==33)
                {
                    pos1=49;
                }
                printf("Player 1 current position is %d\n",pos1);
                if(pos1==100)
                {
                    printf("\nPlayer 1 is winner!");
                    return 1;
                } 
                printboard(board,pos1,pos2); 
            }       
        }
        else
        {
            if(pos1>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos1-=1;   
                printboard(board,pos1,pos2); 
            }
            
        }
        printf("Enter 1 to roll dice for player 2:");
        scanf("%d",&role2);
        if(role2==1)
        {
            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos2+dice>100)
            {
                printf("\nMove not possible!");
            }
            else
            {
                pos2+=dice;
                if(pos2==99)
                {
                    pos2 =  41;
                }
                else if(pos2==95)
                {
                    pos2=77;
                }
                else if(pos2==85)
                {
                    pos2=53;
                }
                else if(pos2==66)
                {
                    pos2=45;
                }
                else if(pos2==43)
                {
                    pos2=17;
                }
                else if(pos2==40)
                {
                    pos2=3;
                }
                else if(pos2==27)
                {
                    pos2=5;
                }
                else if(pos2==62)
                {
                    pos2=81;
                }
                else if(pos2==42)
                {
                    pos2=63;
                }
                else if(pos2==13)
                {
                    pos2=46;
                }
                else if(pos2==4)
                {
                    pos2=25;
                }
                else if(pos2==33)
                {
                    pos2=49;
                }
                printf("Player 2 current position is %d\n",pos2);
                if(pos2==100)
                {
                    printf("\nPlayer 2 is winner !!");
                    return 2;
                } 
                printboard(board,pos1,pos2);
            }    
        }
        else
        {
            if(pos2>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos2-=1;    
                printboard(board,pos1,pos2);
            }
            
        }
    }
}
int threeplayer()
{
    srand(time(NULL));
    int pos1,pos2,pos3,dice,role1,role2,roll3;
    pos1=1,pos2=1,pos3=3;
    int board[100]={0};
    //snakes
    board[98]=-1,board[96]=-1,board[85]=-1,board[66]=-1,board[45]=-1,board[42]=-1,board[29]=-1;
    //ladders
    board[64]=1,board[43]=1,board[14]=1,board[3]=1,board[34]=1;
    while (1)
    {
        printf("Enter 1 to roll dice for player 1:");
        scanf("%d",&role1);

        if(role1==1)
        {

            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos1+dice>100)
            { 
                printf("\nMove not possible!");
            }
            else
            {   
                pos1+=dice;
                if(pos1==99)
                {
                    pos1 =  41;
                }
                else if(pos1==95)
                {
                    pos1=77;
                }
                else if(pos1==85)
                {
                    pos1=53;
                }
                else if(pos1==66)
                {
                    pos1=45;
                }
                else if(pos1==43)
                {
                    pos1=17;
                }
                else if(pos1==40)
                {
                    pos1=3;
                }
                else if(pos1==27)
                {
                    pos1=5;
                }
                else if(pos1==62)
                {
                    pos1=81;
                }
                else if(pos1==42)
                {
                    pos1=63;
                }
                else if(pos1==13)
                {
                    pos1=46;
                }
                else if(pos1==4)
                {
                    pos1=25;
                }
                else if(pos1==33)
                {
                    pos1=49;
                }
                printf("Player 1 current position is %d\n",pos1);
                if(pos1==100)
                {
                    printf("\nPlayer 1 is winner!");
                    return 1;
                } 
                threeprintboard(board,pos1,pos2,pos3); 
            }       
        }
        else
        {
            if(pos1>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos1-=1;   
                threeprintboard(board,pos1,pos2,pos3); 
            }
            
        }
        printf("Enter 1 to roll dice for player 2:");
        scanf("%d",&role2);
        if(role2==1)
        {
            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos2+dice>100)
            {
                printf("\nMove not possible!");
            }
            else
            {
                pos2+=dice;
                if(pos2==99)
                {
                    pos2 =  41;
                }
                else if(pos2==95)
                {
                    pos2=77;
                }
                else if(pos2==85)
                {
                    pos2=53;
                }
                else if(pos2==66)
                {
                    pos2=45;
                }
                else if(pos2==43)
                {
                    pos2=17;
                }
                else if(pos2==40)
                {
                    pos2=3;
                }
                else if(pos2==27)
                {
                    pos2=5;
                }
                else if(pos2==62)
                {
                    pos2=81;
                }
                else if(pos2==42)
                {
                    pos2=63;
                }
                else if(pos2==13)
                {
                    pos2=46;
                }
                else if(pos2==4)
                {
                    pos2=25;
                }
                else if(pos2==33)
                {
                    pos2=49;
                }
                printf("Player 2 current position is %d\n",pos2);
                if(pos2==100)
                {
                    printf("\nPlayer 2 is winner !!");
                    return 2;
                } 
                threeprintboard(board,pos1,pos2,pos3);
            }    
        }
        else
        {
            if(pos2>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos2-=1;    
                threeprintboard(board,pos1,pos2,pos3);
            }
            
        }
        printf("Enter 1 to roll dice for player 3:");
        scanf("%d",&roll3);
        if(roll3==1)
        {
            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos3+dice>100)
            {
                printf("\nMove not possible!");
            }
            else
            {
                pos3+=dice;
                if(pos3==99)
                {
                    pos3 =  41;
                }
                else if(pos3==95)
                {
                    pos3=77;
                }
                else if(pos3==85)
                {
                    pos3=53;
                }
                else if(pos3==66)
                {
                    pos3=45;
                }
                else if(pos3==43)
                {
                    pos3=17;
                }
                else if(pos3==40)
                {
                    pos3=3;
                }
                else if(pos3==27)
                {
                    pos3=5;
                }
                else if(pos3==62)
                {
                    pos3=81;
                }
                else if(pos3==42)
                {
                    pos3=63;
                }
                else if(pos3==13)
                {
                    pos3=46;
                }
                else if(pos3==4)
                {
                    pos2=25;
                }
                else if(pos3==33)
                {
                    pos3=49;
                }
                printf("Player 3 current position is %d\n",pos3);
                if(pos3==100)
                {
                    printf("\nPlayer 3 is winner !!");
                    return 3;
                } 
                threeprintboard(board,pos1,pos2,pos3);
            }    
        }
        else
        {
            if(pos3>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos3-=1;    
                threeprintboard(board,pos1,pos2,pos3);
            }
            else
            {
                printf("\nWrong input!\n");
            }
        }
    }
}
int fourplayer()
{
    srand(time(NULL));
    int pos1,pos2,pos3,pos4,dice,role1,role2,roll3,roll4;
    pos1=1,pos2=1,pos3=1,pos4=1;
    int board[100]={0};
    board[98]=-1,board[96]=-1,board[85]=-1,board[66]=-1,board[45]=-1,board[42]=-1,board[29]=-1;
    board[64]=1,board[43]=1,board[14]=1,board[3]=1,board[34]=1;
    while (1)
    {
        printf("Enter 1 to roll dice for player 1:");
        scanf("%d",&role1);
        if(role1==1)
        {
            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos1+dice<=100)
            {
                pos1+=dice;
                if(pos1==99) pos1=41;
                else if(pos1==95) pos1=77;
                else if(pos1==85) pos1=53;
                else if(pos1==66) pos1=45;
                else if(pos1==43) pos1=17;
                else if(pos1==40) pos1=3;
                else if(pos1==27) pos1=5;
                else if(pos1==62) pos1=81;
                else if(pos1==42) pos1=63;
                else if(pos1==13) pos1=46;
                else if(pos1==4) pos1=25;
                else if(pos1==33) pos1=49;
                printf("Player 1 current position is %d\n",pos1);
                if(pos1==100) return 1;
                fourprintboard(board,pos1,pos2,pos3,pos4);
            }
            else printf("\nMove not possible!");
        }
        else
        {
            if(pos1>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos1-=1;
                fourprintboard(board,pos1,pos2,pos3,pos4);
            }
        }
        printf("Enter 1 to roll dice for player 2:");
        scanf("%d",&role2);
        if(role2==1)
        {
            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos2+dice<=100)
            {
                pos2+=dice;
                if(pos2==99) pos2=41;
                else if(pos2==95) pos2=77;
                else if(pos2==85) pos2=53;
                else if(pos2==66) pos2=45;
                else if(pos2==43) pos2=17;
                else if(pos2==40) pos2=3;
                else if(pos2==27) pos2=5;
                else if(pos2==62) pos2=81;
                else if(pos2==42) pos2=63;
                else if(pos2==13) pos2=46;
                else if(pos2==4) pos2=25;
                else if(pos2==33) pos2=49;
                printf("Player 2 current position is %d\n",pos2);
                if(pos2==100) return 2;
                fourprintboard(board,pos1,pos2,pos3,pos4);
            }
            else printf("\nMove not possible!");
        }
        else
        {
            if(pos2>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos2-=1;
                fourprintboard(board,pos1,pos2,pos3,pos4);
            }
        }
        printf("Enter 1 to roll dice for player 3:");
        scanf("%d",&roll3);
        if(roll3==1)
        {
            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos3+dice<=100)
            {
                pos3+=dice;
                if(pos3==99) pos3=41;
                else if(pos3==95) pos3=77;
                else if(pos3==85) pos3=53;
                else if(pos3==66) pos3=45;
                else if(pos3==43) pos3=17;
                else if(pos3==40) pos3=3;
                else if(pos3==27) pos3=5;
                else if(pos3==62) pos3=81;
                else if(pos3==42) pos3=63;
                else if(pos3==13) pos3=46;
                else if(pos3==4) pos3=25;
                else if(pos3==33) pos3=49;
                printf("Player 3 current position is %d\n",pos3);
                if(pos3==100) return 3;
                fourprintboard(board,pos1,pos2,pos3,pos4);
            }
            else printf("\nMove not possible!");
        }
        else
        {
            if(pos3>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos3-=1;
                fourprintboard(board,pos1,pos2,pos3,pos4);
            }
        }
        printf("Enter 1 to roll dice for player 4:");
        scanf("%d",&roll4);
        if(roll4==1)
        {
            dice=diceroller();
            printf("\033[0mYou got %d\n",dice);
            if(pos4+dice<=100)
            {
                pos4+=dice;
                if(pos4==99) pos4=41;
                else if(pos4==95) pos4=77;
                else if(pos4==85) pos4=53;
                else if(pos4==66) pos4=45;
                else if(pos4==43) pos4=17;
                else if(pos4==40) pos4=3;
                else if(pos4==27) pos4=5;
                else if(pos4==62) pos4=81;
                else if(pos4==42) pos4=63;
                else if(pos4==13) pos4=46;
                else if(pos4==4) pos4=25;
                else if(pos4==33) pos4=49;
                printf("Player 4 current position is %d\n",pos4);
                if(pos4==100) return 4;
                fourprintboard(board,pos1,pos2,pos3,pos4);
            }
            else printf("\nMove not possible!");
        }
        else
        {
            if(pos4>1)
            {
                printf("\nWrong input! -1 penalty\n");
                pos4-=1;
                fourprintboard(board,pos1,pos2,pos3,pos4);
            }
        }
    }
}


int main()
{
    printf("===============Snake Board Game===============");
    int choice;
    printf("\n1.2 players\n2.3players\n3.4players");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            twoplayer();
            break;
        }
        case 2:
        {
            threeplayer();
            break;
        }
        case 3:
        {
            fourplayer();
            break;
        }
        default:
        {
            printf("\nWrong input!");
            break;
        }
    }
    return 0;
}

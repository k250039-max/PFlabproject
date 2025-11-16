#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int diceroller()
{
    int x=((rand()%6)+1);
    return x;
}
void printboard(int board[],int pos1,int pos2)
{
    for(int i=100;i>0;i--)
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
int main()
{
    srand(time(NULL));
    int pos1,pos2,dice,role1,role2;
    pos1=1,pos2=1;
    int board[100]={0};
    //snakes
    board[98]=-1,board[95]=-1,board[85]=-1,board[66]=-1,board[45]=-1,board[42]=-1,board[29]=-1;
    //ladders
    board[64]=1,board[43]=1,board[14]=1,board[5]=1,board[34]=1;
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
                printf("Your current position is %d\n",pos1);
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
                printf("Your current position is %d\n",pos2);
                printboard(board,pos1,pos2);
            }    
        }
        if(pos1==100||pos2==100)
        {
            if(pos1==100)
            {
                printf("\nPlayer 1 won!");
            }
            if(pos2==100)
            {
                printf("\nPlayer 2 won!");
            }
            return 1;
        }
    }

}
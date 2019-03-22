#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#define  ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4




void setMatrix(int A[][4]);
void showMatrix(int A[][4]);
int readKey();
int checkWin(int A[][4]);
int shiftRight(int A[][4]);
int shiftLeft(int A[][4]);
int shiftUp(int A[][4]);
int shiftDown(int A[][4]);

void setmatrix(int A[][3]);
void showmatrix(int A[][3]);
int readkey();
int checkwin(int A[][3]);
int shiftright(int A[][3]);
int shiftleft(int A[][3]);
int shiftup(int A[][3]);
int shiftdown(int A[][3]);

void set_Matrix(int A[][5]);
void show_Matrix(int A[][5]);
int read_Key();
int check_Win(int A[][5]);
int shift_Right(int A[][5]);
int shift_Left(int A[][5]);
int shift_Up(int A[][5]);
int shift_Down(int A[][5]);

main()
{
    system("color 2F");
    int N;
    printf("\n\t\t\t\t\t\t  Welcome to Puzzle game 1.0\n");
    printf("\n\t\t\t\t\t\t\t1. Easy Level \n\t\t\t\t\t\t\t2. Medium Level \n\t\t\t\t\t\t\t3. Hard level\n\t\t\t\t\t\t\t4. Exit\n");
    scanf("\n\n\t\t\t\t\t\t\t%d",&N);

    if(N==1)
    {
        int A[3][3],move=300;
    setmatrix(A);
    while(move)
    {
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMove remaining: %d",move);
         showmatrix(A);
         if(checkwin(A)){
            printf("\nCongratulations! You win in %d moves",300-move);
            printf("\nPress any key to exit...");
            exit(0);
         }
         switch(readkey())
         {
         case ESC:
             exit(0);
         case UP:
             if(!shiftup(A))
                 move++;
             break;
         case DOWN:
            if(!shiftdown(A))
                move++;
             break;
         case LEFT:
            if(!shiftleft(A))
                move++;
             break;
         case RIGHT:
              if(!shiftright(A))
                move++;
             break;
         default:
            move++;
         }
         system("cls");
         move--;

    }
    printf("You lost, Try again");
    getch();
    }
    else if(N==2)
    {
    int A[4][4],move=400;
    setMatrix(A);
    while(move)
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t\tMove remaining: %d",move);
         showMatrix(A);
         if(checkWin(A)){
            printf("\nCongratulations! You win in %d moves",500-move);
            printf("\nPress any key to exit...");
            exit(0);
         }
         switch(readKey())
         {
         case ESC:
             exit(0);
         case UP:
             if(!shiftUp(A))
                 move++;
             break;
         case DOWN:
            if(!shiftDown(A))
                move++;
             break;
         case LEFT:
            if(!shiftLeft(A))
                move++;
             break;
         case RIGHT:
              if(!shiftRight(A))
                move++;
             break;
         default:
            move++;
         }
         system("cls");
         move--;

    }
        printf("You lost, Try again");
    getch();
    }
    else if(N==3)
    {
     int A[5][5],move=500;
    set_Matrix(A);
    while(move)
    {
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMove remaining: %d",move);
         show_Matrix(A);
         if(check_Win(A)){
            printf("\nCongratulations! You win in %d moves",500-move);
            printf("\nPress any key to exit...");
            exit(0);
         }
         switch(read_Key())
         {
         case ESC:
             exit(0);
         case UP:
             if(!shift_Up(A))
                 move++;
             break;
         case DOWN:
            if(!shift_Down(A))
                move++;
             break;
         case LEFT:
            if(!shift_Left(A))
                move++;
             break;
         case RIGHT:
              if(!shift_Right(A))
                move++;
             break;
         default:
            move++;
         }

         system("cls");

         move--;
          if(move==0)
             printf("\n\n\n\n\t\t\t\t\tYou lost, Try again");

    }

    getch();

    }
    else
        exit(0);

}




int shiftRight(int A[][4]){
    int i,j,temp,zeroFound=0;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==0)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i][j-1];
        A[i][j-1]=temp;
        return(1);
}
int shiftLeft(int A[][4]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==3)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i][j+1];
        A[i][j+1]=temp;
        return(1);
}
int shiftUp(int A[][4]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==3)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i+1][j];
        A[i+1][j]=temp;
        return(1);
}
int shiftDown(int A[][4]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==0)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i-1][j];
        A[i-1][j]=temp;
        return(1);
}

int checkWin(int A[][4])
{
    int i,j,k=0;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
                k<15?k++:(k=0);
            if(A[i][j]!=k)
                return(0);

        }
    }
    return(1);
}
int readKey(){
    int ch; /*code of pressed key*/
    ch=getch();
    if(ch==224)
        ch=getch();
    switch(ch)
    {
    case 27:
        return(ESC);
    case 72:
        return(UP);
    case 80:
        return(DOWN);
    case 75:
        return(LEFT);
    case 77:
        return(RIGHT);
    default:
        return (5);
    }
}

void showMatrix(int A[][4]){
int i,j;
printf("\n\n\n\t\t\t\t\t\t------------------------\n\t\t\t\t\t\t|");
for(i=0;i<=3;i++){
    for(j=0;j<=3;j++){
        if(A[i][j]!=0)
            printf(" %-2d | ",A[i][j]);
        else
            printf("    | ");

    }
    printf("\n\t\t\t\t\t\t------------------------\n\t\t\t\t\t\t");
    if(i!=3)
        printf("|");
}
}

void setMatrix(int A[][4]){
    int pool[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int maxIndex=14,index,i,j;
    srand(time(NULL));

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(maxIndex>=0){
                index=rand()%(maxIndex+1);
                A[i][j]=pool[index];
                pool[index]=pool[maxIndex];
                maxIndex--;
            }
            else
                A[i][j]=0;


            }
        }
    }




int shiftright(int A[][3]){
    int i,j,temp,zeroFound=0;
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==0)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i][j-1];
        A[i][j-1]=temp;
        return(1);
}
int shiftleft(int A[][3]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==2)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i][j+1];
        A[i][j+1]=temp;
        return(1);
}
int shiftup(int A[][3]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==2)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i+1][j];
        A[i+1][j]=temp;
        return(1);
}
int shiftdown(int A[][3]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==0)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i-1][j];
        A[i-1][j]=temp;
        return(1);
}

int checkwin(int A[][3])
{
    int i,j,k=0;
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
                k<8?k++:(k=0);
            if(A[i][j]!=k)
                return(0);

        }
    }
    return(1);
}
int readkey(){
    int ch; /*code of pressed key*/
    ch=getch();
    if(ch==224)
        ch=getch();
    switch(ch)
    {
    case 27:
        return(ESC);
    case 72:
        return(UP);
    case 80:
        return(DOWN);
    case 75:
        return(LEFT);
    case 77:
        return(RIGHT);
    default:
        return (5);
    }
}

void showmatrix(int A[][3]){
int i,j;
printf("\n\n\n\t\t\t\t\t\t------------------\n\t\t\t\t\t\t|");
for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
        if(A[i][j]!=0)
            printf(" %-2d | ",A[i][j]);
        else
            printf("    | ");

    }
    printf("\n\t\t\t\t\t\t------------------\n\t\t\t\t\t\t");
    if(i!=2)
        printf("|");
}
}

void setmatrix(int A[][3]){
    int pool[8]={1,2,3,4,5,6,7,8};
    int maxIndex=7,index,i,j;
    srand(time(NULL));

    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if(maxIndex>=0){
                index=rand()%(maxIndex+1);
                A[i][j]=pool[index];
                pool[index]=pool[maxIndex];
                maxIndex--;
            }
            else
                A[i][j]=0;


            }
        }
    }




 int shift_Right(int A[][5]){
    int i,j,temp,zeroFound=0;
    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==0)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i][j-1];
        A[i][j-1]=temp;
        return(1);
}
int shift_Left(int A[][5]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==4)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i][j+1];
        A[i][j+1]=temp;
        return(1);
}
int shift_Up(int A[][5]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==4)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i+1][j];
        A[i+1][j]=temp;
        return(1);
}
int shift_Down(int A[][5]){
     int i,j,temp,zeroFound=0;
    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==0)
        return(0);//shiftinf not possible
    else
        temp=A[i][j];
        A[i][j]=A[i-1][j];
        A[i-1][j]=temp;
        return(1);
}

int check_Win(int A[][5])
{
    int i,j,k=0;
    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
                k<24?k++:(k=0);
            if(A[i][j]!=k)
                return(0);

        }
    }
    return(1);
}
int read_Key(){
    int ch; /*code of pressed key*/
    ch=getch();
    if(ch==224)
        ch=getch();
    switch(ch)
    {
    case 27:
        return(ESC);
    case 72:
        return(UP);
    case 80:
        return(DOWN);
    case 75:
        return(LEFT);
    case 77:
        return(RIGHT);
    default:
        return (5);
    }
}

void show_Matrix(int A[][5]){
int i,j;
printf("\n\n\t\t\t\t\t\t------------------------------\n\t\t\t\t\t\t|");
for(i=0;i<=4;i++){
    for(j=0;j<=4;j++){
        if(A[i][j]!=0)
            printf(" %-2d | ",A[i][j]);
        else
            printf("    | ");

    }
    printf("\n\t\t\t\t\t\t------------------------------\n\t\t\t\t\t\t");
    if(i!=4)
        printf("|");
}
}

void set_Matrix(int A[][5]){
    int pool[24]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
    int maxIndex=23,index,i,j;
    srand(time(NULL));

    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
            if(maxIndex>=0){
                index=rand()%(maxIndex+1);
                A[i][j]=pool[index];
                pool[index]=pool[maxIndex];
                maxIndex--;
            }
            else
                A[i][j]=0;


            }
        }
    }


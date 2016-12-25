
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


char startup[10][11]= {' ','A','B','C','D','E','F','G','H',' ','\n','8','_','.','_','.','_','.','_','.','8','\n','7','.','_','.','_','.','_','.','_','7','\n','6','_','.','_','.','_','.','_','.','6','\n','5','.','_','.','_','.','_','.','_','5',
                       '\n','4','_','.','_','.','_','.','_','.','4','\n','3','.','_','.','_','.','_','.','_','3','\n','2','_','.','_','.','_','.','_','.','2','\n',
                       '1','.','_','.','_','.','_','.','_','1','\n',' ','A','B','C','D','E','F','G','H'
                      };

char  def[10][11]= {' ','A','B','C','D','E','F','G','H',' ','\n','8','R','N','B','Q','K','B','N','R','8','\n','7','P','P','P','P','P','P','P','P','7','\n','6','_','.','_','.','_','.','_','.','6','\n','5','.','_','.','_','.','_','.','_','5',
                    '\n','4','_','.','_','.','_','.','_','.','4','\n','3','.','_','.','_','.','_','.','_','3','\n','2','p','p','p','p','p','p','p','p','2','\n',
                    '1','r','n','b','q','k','b','n','r','1','\n',' ','A','B','C','D','E','F','G','H'
                   };

char board[10][11]= {' ','A','B','C','D','E','F','G','H',' ','\n','8','R','N','B','Q','K','B','N','R','8','\n','7','P','P','P','P','P','P','P','P','7','\n','6','_','.','_','.','_','.','_','.','6','\n','5','.','_','.','_','.','_','.','_','5',
                     '\n','4','_','.','_','.','_','.','_','.','4','\n','3','.','_','.','_','.','_','.','_','3','\n','2','p','p','p','p','p','p','p','p','2','\n',
                     '1','r','n','b','q','k','b','n','r','1','\n',' ','A','B','C','D','E','F','G','H'
                    };

char arrstrt[4]= {'0','0','0','0'};  //SAVES PLAYERS INPUT IN CHARACTERS
char move_record[1000][6]= {'0','0','0','0','0','0'};
int moveRecordSize=0;
int turn;
int arrpostn[4];     //KEEPS THE KING POSITION
int after_check=0;
char A[1][40]= {'1','|',' '};
char B[1][40]= {'2','|',' '};
int columnSize1=2,columnSize2=2;





int get_crpint (char y)  //get corresponding board row and column from user input
{
    int i;
    int x=0,counter=0;

    char array_char[]= {'A','B','C','D','E','F','G','H'};  //board column
    char array_char1[]= {'1','2','3','4','5','6','7','8'};  //board row
    for(i=0; i<8; i++)
    {
        if(array_char[i]==y)
        {
            x=i+1;             //board column

        }

        else if(y==array_char1[i])
        {
            x=y-'0';
            x=9-x;          //board row

        }

    }


    return x;
}

void printArray(int x,int y,char A[][y]) //PRINT ARRAY
{

    int i,j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("  %c",A[i][j]);     //prints out arrays

        }
        printf("\n");
    }
    return;
}
void move(int x,int y ,char board[][y],int arrint[],int i)  //actual move function
{


   //CHECKS WETHER IT IS AN EMPTY SQUARE
    if((board[arrint[3]][arrint[2]]== '_'||board[arrint[3]][arrint[2]]=='.')&&(board[arrint[1]][arrint[0]]!='_'&& board[arrint[1]][arrint[0]]!= '.') )
    {

        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];

        board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];

    }
    //IF NOT CHECKS WHETHER IT IS A MOVE FOR PLAYER 1 TO TAKE A PIECE FROM PLAYER TWO
    else if(board[arrint[1]][arrint[0]]>'a'&&board[arrint[1]][arrint[0]]<'z'&&board[arrint[3]][arrint[2]]>'A'&&board[arrint[3]][arrint[2]]<'Z')
    {


        B[0][columnSize1] =board[arrint[3]][arrint[2]];
        move_record[moveRecordSize][4]=board[arrint[3]][arrint[2]];
        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
        board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
        B[0][columnSize1-1]='|';
        columnSize1=columnSize1+2;

    }
     //IF NOT CHECKS WHETHER IT IS A MOVE FOR PLAYER 2 TO TAKE A PIECE FROM PLAYER 1
    else if(board[arrint[1]][arrint[0]]>'A'&&board[arrint[1]][arrint[0]]<'Z'&&board[arrint[3]][arrint[2]]>'a'&&board[arrint[3]][arrint[2]]<'z')
    {

        A[0][columnSize2] =board[arrint[3]][arrint[2]];
        move_record[moveRecordSize][4]=board[arrint[3]][arrint[2]];
        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
        board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
        A[0][columnSize2-1]='|';
        columnSize2=columnSize2+2;
    }
   //IF NON OF THE ABOVE IT IS AN INVALID MOVE
    else
    {
        printf("CANNOT MOVE!! PLEASE ENTER A VALID MOVE111 \n\n");
        if(turn==1)
            {                      //RETURN BACK TO THE PLAYER WITH THE INVALID ENTRY
                while(getchar()!='\n');
                return scanInput1(arrstrt,5);
            }
        else if(turn==2)
            {
             while(getchar()!='\n');
             return scanInput2(arrstrt,5);
           }


    }

}

int rook (int arrint[],int arraySize)    //ALLOWED ROOK MOVES VALIDATIONS   //EITHER MOVING THROUGH SAME COLUMNS OR SAME ROWS
{
    int flag=1;
    if(arrint[1]==arrint[3])        //SAME ROW
    {
        if(arrint[0]>arrint[2])     //ROOK MOVING LEFTWARDS
        {
            int column;

            for(column=arrint[0]; (column>arrint[2]+1)&&(flag==1); column--) //CHECKS WHETHER THE SQUARES AHEAD ARE EMPTY
            {
                if(board[arrint[1]][column-1]=='.');
                else if(board[arrint[1]][column-1]=='_');
                else flag=0;
            }
            if(flag==1)
            {
                if((board[arrint[1]][arrint[2]]>'a')&&(board[arrint[1]][arrint[2]]<'z')&&((board[arrint[1]][arrint[0]]=='R')||(board[arrint[1]][arrint[0]]=='Q')));
                else if((board[arrint[1]][arrint[2]]>'A')&&(board[arrint[1]][arrint[2]]<'Z')&&((board[arrint[1]][arrint[0]]=='r')||(board[arrint[1]][arrint[0]]=='q')));
                else if(board[arrint[1]][arrint[2]]=='.');
                else if(board[arrint[1]][arrint[2]]=='_');
                else
                {
                    flag=0;
                }
            }

        }
        else if (arrint[0]<arrint[2])      //ROOK MOVING RIGHTWARDS
        {
            int column;
            for(column=arrint[0]; (column<arrint[2]-1)&&(flag==1); column++)   //CHECKS WHETHER THE SQUARES AHEAD ARE EMPTY
            {
                if(board[arrint[1]][column+1]=='.');
                else if(board[arrint[1]][column+1]=='_');
                else flag=0;
            }
            if(flag==1)
            {
                if((board[arrint[1]][arrint[2]]>'a')&&(board[arrint[1]][arrint[2]]<'z')&&((board[arrint[1]][arrint[0]]=='R')||(board[arrint[1]][arrint[0]]=='Q')));
                else if((board[arrint[1]][arrint[2]]>'A')&&(board[arrint[1]][arrint[2]]<'Z')&&((board[arrint[1]][arrint[0]]=='r')||(board[arrint[1]][arrint[0]]=='q')));
                else if(board[arrint[1]][arrint[2]]=='.');
                else if(board[arrint[1]][arrint[2]]=='_');
                else
                {
                    flag=0;
                }
            }
        }
        else
        {
            flag=0;
        }

    }
    else if(arrint[0]==arrint[2])   //SAME COLUMN
    {
        if(arrint[1]>arrint[3])    //ROOK MOVING UPWARDS
        {
            int row;

            for(row=arrint[1]; (row>arrint[3]+1)&&(flag==1); row--)   //CHECKS WHETHER THE SQUARES ON ITS MOVE ARE EMPTY
            {
                if (board[row-1][arrint[0]]=='.');
                else if(board[row-1][arrint[0]]=='_');
                else flag=0;
            }
            if(flag==1)
            {
                if((board[arrint[3]][arrint[0]]>'a')&&(board[arrint[3]][arrint[0]]<'z')&&((board[arrint[1]][arrint[0]]=='R')||(board[arrint[1]][arrint[0]]=='Q')));
                else if((board[arrint[3]][arrint[0]]>'A')&&(board[arrint[3]][arrint[0]]<'Z')&&((board[arrint[1]][arrint[0]]=='r')||(board[arrint[1]][arrint[0]]=='q')));
                else if(board[arrint[3]][arrint[0]]=='.');
                else if(board[arrint[3]][arrint[0]]=='_');
                else
                {
                    flag=0;
                }
            }
        }
        else if(arrint[1]<arrint[3])   //ROOK MOVING DOWNWARDS
        {
            int row;

            for(row=arrint[1]; (row<arrint[3]-1)&&(flag==1); row++)  //CHECKS WHETHER THE SQUARES ON ITS MOVE ARE EMPTY
            {
                if (board[row+1][arrint[0]]=='.');
                else if(board[row+1][arrint[0]]=='_');
                else flag=0;
            }
            if (flag==1)
            {
                if((board[arrint[3]][arrint[0]]>'a')&&(board[arrint[3]][arrint[0]]<'z')&&((board[arrint[1]][arrint[0]]=='R')||(board[arrint[0]][arrint[1]]=='Q')));
                else if((board[arrint[3]][arrint[0]]>'A')&&(board[arrint[3]][arrint[0]]<'Z')&&((board[arrint[1]][arrint[0]]=='r')||(board[arrint[1]][arrint[2]]=='q')));
                else if(board[arrint[3]][arrint[0]]=='.');
                else if(board[arrint[3]][arrint[0]]=='_');
                else
                {
                    flag=0;
                }
            }
        }
        else
        {
            flag=0;
        }

    }
    else
    {
        flag=0;   //IT IS AN INVALID MOVE
    }

    return flag;
}

int king(int arrint[], int arraySize)   //ALLOWED KING MOVES VALIDATIONS  //ONE SQUARE ANYWHERE
{
    int flag;
    if(arrint[1]==arrint[3])    //SAME ROW
    {
        if(abs(arrint[0]-arrint[2])==1)
        {
            if(board[arrint[3]][arrint[2]]=='.')
              flag=1;
            else if(board[arrint[3]][arrint[2]]=='_')
              flag=1;
            else if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&(board[arrint[1]][arrint[0]]=='K'))
              flag=1;
            else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&(board[arrint[1]][arrint[0]]=='k'))
              flag=1;
            else
              flag=0;
        }
    }
    else if(arrint[0]==arrint[2])     //SAME COLUMN
    {
        if(abs(arrint[1]-arrint[3])==1)
        {
            if(board[arrint[3]][arrint[2]]=='.')
              flag=1;
            else if(board[arrint[3]][arrint[2]]=='_')
              flag=1;
            else if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&(board[arrint[1]][arrint[0]]=='K'))
              flag=1;
            else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&(board[arrint[1]][arrint[0]]=='k'))
              flag=1;
            else
              flag=0;
        }
    }
    else if(abs(arrint[0]-arrint[2])==1)   //MOVING DIAGONALLY
    {
        if(abs(arrint[1]-arrint[3])==1)
        {
            if(board[arrint[3]][arrint[2]]=='.')
              flag=1;
            else if(board[arrint[3]][arrint[2]]=='_')
              flag=1;
            else if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&(board[arrint[1]][arrint[0]]=='K'))
              flag=1;
            else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&(board[arrint[1]][arrint[0]]=='k'))
              flag=1;
            else
              flag=0;
        }

    }
    else
    {
        flag=0;  //IT IS AN INVALID MOVE


        }
        return flag;

}

int bishop(int arrint[],int arraySize)  //ALLOWED BISHOP MOVES VALIDATIONS //DIAGONALLY
{
    int flag;
    if(abs(arrint[0]-arrint[2])==abs(arrint[1]-arrint[3]))
    {
        flag=1;
        if(arrint[1]<arrint[3])
        {
            if(arrint[0]<arrint[2])
            {
                int i;

                for(i=1; (i+arrint[0]<arrint[2])&&(flag==1); i++)
                {

                    if(board[arrint[1]+i][arrint[0]+i]=='_');
                    else if(board[arrint[1]+i][arrint[0]+i]=='.');
                    else flag=0;
                }
                if(flag==1)
                {
                    if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&((board[arrint[1]][arrint[0]]=='B')||(board[arrint[1]][arrint[0]]=='Q')));

                    else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&((board[arrint[1]][arrint[0]]=='b')||(board[arrint[1]][arrint[0]]=='q')));
                    else if(board[arrint[3]][arrint[2]]=='_');
                    else if(board[arrint[3]][arrint[2]]=='.');
                    else
                    {
                        flag=0;
                    }

                }
            }
            else if(arrint[0]>arrint[2])
            {

                int i,j;

                for(i=1; (arrint[2]<arrint[0]-i)&&(flag==1); i++)
                {
                    if(board[arrint[1]+i][arrint[0]-i]=='_');
                    else if(board[arrint[1]+i][arrint[0]-i]=='.');
                    else flag=0;
                }
                if(flag==1)
                {
                    if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&((board[arrint[1]][arrint[0]]=='B')||(board[arrint[1]][arrint[0]]=='Q')));

                    else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&((board[arrint[1]][arrint[0]]=='b')||(board[arrint[1]][arrint[0]]=='q')));
                    else if(board[arrint[3]][arrint[2]]=='_');
                    else if(board[arrint[3]][arrint[2]]=='.');
                    else
                    {
                        flag=0;
                    }
                }
            }

        }

        else if (arrint[1]>arrint[3])
        {
            if(arrint[0]<arrint[2])
            {
                int i,j;
                for(i=1; (arrint[2]>arrint[0]+i)&&(flag==1); i++)
                {

                    if(board[arrint[1]-i][arrint[0]+i]=='.');
                    else if (board[arrint[1]-i][arrint[0]+i]=='_');
                    else flag=0;
                }
                if(flag==1)
                {
                    if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&((board[arrint[1]][arrint[0]]=='B')||(board[arrint[1]][arrint[0]]=='Q')));

                    else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&((board[arrint[1]][arrint[0]]=='b')||(board[arrint[1]][arrint[0]]=='q')));
                    else if(board[arrint[3]][arrint[2]]=='_');
                    else if(board[arrint[3]][arrint[2]]=='.');
                    else flag=0;
                }
            }

            else if (arrint[0]>arrint[2])
            {
                int i,j;
                for(i=1; (arrint[2]<arrint[0]-i)&&(flag==1); i++)
                {

                    if(board[arrint[1]-i][arrint[0]-i]=='.');
                    else if (board[arrint[1]-i][arrint[0]-i]=='_');
                    else flag=0;
                }
                if(flag==1)
                {
                    if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&((board[arrint[1]][arrint[0]]=='B')||(board[arrint[1]][arrint[0]]=='Q')));

                    else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&((board[arrint[1]][arrint[0]]=='b')||(board[arrint[1]][arrint[0]]=='q')));
                    else if(board[arrint[3]][arrint[2]]=='_');
                    else if(board[arrint[3]][arrint[2]]=='.');
                    else flag=0;
                }
            }

        }
        else flag=0;
    }
    else
    {

        flag=0;
    }
    return flag;
}

int queen(int arrint[],int arraySize)  //ALLOWED QUEEN MOVES
{
    int flag=1;
    if(arrint[1]==arrint[3])   //CALLS ROOK MOVES VALIDATIONS
    {
        flag=rook(arrint,arraySize);
    }
    else if(arrint[0]==arrint[2])
    {
        flag=rook(arrint,arraySize);
    }
    else if(abs(arrint[0]-arrint[2])==abs(arrint[1]-arrint[3]))  //CALLS BISHOP MOVES VALIDATIONS
    {
        flag=bishop(arrint,arraySize) ;
    }
    else
    {
      flag=0;

    }
  return flag;

}

void promotion(char arrstrt[],int arraySize1,int arrint[],int arraySize2)   //POWN PROMOTION FUNCTION
{
    int i;

    if(arrint[3]==1)  //PLAYER ONE REACHES FIRST ROW
    {
        printf("PROMOTION \n");
        printf("ENTER THE PIECE OF PROMOTION:\n");
        while(getchar()!='\n');

        scanf("%c",&arrstrt[0]);


        switch(arrstrt[0])
        {
        case 'n':
            board[1][arrint[2]]='n';
            move_record[moveRecordSize][5]='n'; //SAVEING PROMOTION PIECE FOR UNDO/REDO CALLS

            break;
        case 'b':
            board[1][arrint[2]]='b';
            move_record[moveRecordSize][5]='b';

            break;
        case 'r':
            board[1][arrint[2]]='r';
            move_record[moveRecordSize][5]='r';

            break;
        case 'q':
            board[1][arrint[2]]='q';
            move_record[moveRecordSize][5]='q';

            break;
        default:
        {
            printf("INVALID ENTRY\n"); //IF NON OF THE PIECES ABOVE IT IS AN INVALID ENTRY
            return promotion( arrstrt,4,arrint,4);
        }

    }
    }
    else if(arrint[3]==8)   //PLAYER TWO PAWN REACHES LAST ROW
    {   printf("PROMOTION \n");
        printf("ENTER THE PIECE OF PROMOTION:\n");
        while(getchar()!='\n');


        scanf("%c",&arrstrt[0]);

        switch(arrstrt[0])
        {
        case 'N':
            board[8][arrint[2]]='N';
            move_record[moveRecordSize][5]='N';

            break;
        case 'B':
            board[8][arrint[2]]='B';
            move_record[moveRecordSize][5]='B';

            break;
        case 'R':
            board[8][arrint[2]]='R';
            move_record[moveRecordSize][5]='R';

            break;
        case 'Q':
            board[8][arrint[2]]='Q';
            move_record[moveRecordSize][5]='Q';

            break;
        default:
        {
            printf("INVALID ENTRY!\n");

            return promotion(arrstrt,4,arrint,4);
        }


    }

    }
    else;


    }

int pawn(int arrint[],int arraySize)  //PAWN MOVES VALIDATIONS
{
    int flag=1;


    if(board[arrint[1]][arrint[0]]=='p') //PLAYER ONE PAWN
    {
        if((arrint[3]==arrint[1]-1)&&(arrint[0]==arrint[2]))  //PAWN MOVES ONE EMPTY SQUARE AHEAD
        {
            if(board[arrint[3]][arrint[2]]=='_')
            {
                flag=1;

            }

            else if (board[arrint[3]][arrint[2]]=='.')
            {
                flag=1;

            }

            else
            {
                flag=0;  //IF NOT RETURN INVALID ENTRY
            }

        }
        else if((arrint[3]==arrint[1]-1)&&(abs(arrint[0]-arrint[2])==1)) //PAWN MOVES ONE SQAURE DIAGONALLY ON CONDITION IT TAKES AN OPPONENTS PIECE
        {
            if(board[arrint[3]][arrint[2]]=='_')
            {

                flag=0; //IF EMPTY SQUARE RETURN INVALID ENTRY
            }
            else if (board[arrint[3]][arrint[2]]=='.')
            {

                flag=0;
            }    //IF EMPTY SQUARE RETURN INVALID ENTRY
            else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z'))
            {

                flag=1;

            }

            else flag=0;

        }
        else  if(arrint[1]==7)  //PAWN SPECIAL MOVE TWO SQYARES AHEAD ON FIRST MOVE
        {
            if((abs(arrint[1]-arrint[3])==2)&&(arrint[0]==arrint[2]))
            {
                if((board[arrint[3]][arrint[2]]=='.')&&(board[arrint[3]+1][arrint[2]]=='_'))  //CHECKS WHETHER IT IS AN EMPTY SQUARE AHEAD
                    flag=1;
                else if((board[arrint[3]][arrint[2]]=='_')&&(board[arrint[3]+1][arrint[2]]=='.'))
                    flag=1;
                else
                {
                    flag=0;
                }

            }

            else flag=0;
        }

        else
        {
            flag=0;

        }
    }


    else if(board[arrint[1]][arrint[0]]=='P') //PLAYER TWO PAWN
    {
        if((arrint[3]==arrint[1]+1)&&(arrint[0]==arrint[2]))
        {
            if(board[arrint[3]][arrint[2]]=='_')
            {

                flag=1;

            }

            else if (board[arrint[3]][arrint[2]]=='.')
            {

                flag=1;

            }

            else
            {

                flag=0;

            }
        }
        else if((arrint[3]==arrint[1]+1)&&(abs(arrint[0]-arrint[2])==1))
        {
            if(board[arrint[3]][arrint[2]]=='_')
            {
                flag=0;
            }
            else if (board[arrint[3]][arrint[2]]=='.')
            {
                flag=0;
            }
            else if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z'))
            {
                flag=1;
            }

            else
            {

                flag=0;

            }
        }

        else if(arrint[1]==2) //PLAYER TWO PAWN SPECIAL MOVE TWO SQUARES AHEAD ON FIRST MOVE
        {
            if((abs(arrint[1]-arrint[3])==2)&&(arrint[0]==arrint[2]))
            {
                if((board[arrint[3]][arrint[2]]=='.')&&(board[arrint[3]-1][arrint[2]]=='_'))
                    flag=1;
                else if((board[arrint[3]][arrint[2]]=='_')&&(board[arrint[3]-1][arrint[2]]=='.'))
                    flag=1;
                else
                {
                    flag=0;
                }

            }

            else
            {

                flag=0;
            }
        }

        else flag=0;
    }

    else
    {
        flag=0; //IF NON OF THE ABOVE RETURN INVALID ENTRY
    }

    return flag;
}

int knight(int arrint[],int arraySize)  //ALLOWED KNIGHT MOVES VALIDATIONS //L SHAPE ANY DIRECTION
{
    int flag;
    if(abs(arrint[3]-arrint[1])==2)
    {
        if(abs(arrint[2]-arrint[0])==1)
        {
            if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&(board[arrint[1]][arrint[0]]=='N')) //PLAYER TWO KNIGHT TAKES PLAYER 1
            flag=1;                                                                                                        //PIECES
            else if(board[arrint[3]][arrint[2]]=='.') flag=1;
            else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&(board[arrint[1]][arrint[0]]=='n')) //PLAYER ONE KNIGHT TAKES PLAYER2
            flag=1;                                                                                                           //PIECES
            else if(board[arrint[3]][arrint[2]]=='_') flag=1;    //WHETHER AN EMPTY SPACE
           else
            flag=0;
        }
        else
        {
                flag=0; //IF NOT RETURN INVALID ENTRY
            }
    }

    else if(abs(arrint[2]-arrint[0])==2)
    {
        if(abs(arrint[3]-arrint[1])==1)
        {
           if((board[arrint[3]][arrint[2]]>'a')&&(board[arrint[3]][arrint[2]]<'z')&&(board[arrint[1]][arrint[0]]=='N'))
            flag=1;
            else if(board[arrint[3]][arrint[2]]=='.') flag=1;
            else if((board[arrint[3]][arrint[2]]>'A')&&(board[arrint[3]][arrint[2]]<'Z')&&(board[arrint[1]][arrint[0]]=='n'))
            flag=1;
            else if(board[arrint[3]][arrint[2]]=='_') flag=1;
           else
            flag=0;
        }
        else
        {
                flag=0;  //IF NOT RETURN INVALID ENTRY
            }
    }
    else
    {
            flag=0;  //IF NOT RETURN INVALID ENTRY
        }
        return flag;

}


void king_position2(int x,int y,char board[][y]){   //DETERMINES PLAYER 2 KING ON THE BOARD
    int i,j,flag=0;
//if(turn==1)

    for(i=0; i<x&&flag==0; i++)   //SCANNING THE BOARD
    {
        for(j=0; j<y&&flag==0; j++)
        {
            if(board[i][j]=='K')
            {
                flag=1;
            }
        }
    }
    i=i-1;
    j=j-1;
    arrpostn[0]=j;   //SAVE THE KINGS POSITION IN AN ARRAY
    arrpostn[1]=i;


}


void king_position1(int x,int y,char board[][y]){ //DETERMINES PLAYER 1 KING ON THE BOARD
//else if(turn==2)
    int i,j,flag=0;

    for(i=0; i<x&&flag==0; i++)  //SCANNING THE BOARD
    {
        for(j=0; j<y&&flag==0; j++)
        {
            if(board[i][j]=='k')
            {
                flag=1;
            }
        }
    }
    i=i-1;
    j=j-1;
    arrpostn[0]=j;   //SAVING KINGS POSITION IN AN ARRAY
    arrpostn[1]=i;


}

int check1(int arrpostn[],int arraySize,int x,int y,char board[][y]) //CHECKS PLAYER TWO KING
{
    int i,j,k,flag=0,check=0;
    j=arrpostn[0]; //INITIALIZING J WITH THE COLUMN POSITION OF THE KING ON THE BOARD
    i=arrpostn[1];  //INITIALIZING I WITH THE ROW POSITION OF THE KING ON THE BOARD

    int z;
    int checkArray[4]={0};



    if(board[i+1][j+1]=='p')  //KING IS CHECKED BY A PAWN
    {

        check=1;
    }
    if(board[i+1][j-1]=='p') //KING IS CHECKED BY A PAWN
    {

        check=1;
    }
    for(k=j+1; k<=8&&check==0; k++)  //SCANNING THE BOARD SEARCHING FOR A PLAYER TWO PIECES
    {
        if(board[i][k]=='_');
        else if(board[i][k]=='.');
        else if(board[i][k]>'A'&&board[i][k]<'Z')
            break;                                 //NO CHECK
        else if(board[i][k]=='r')
        {
            checkArray[0]=k;
            checkArray[1]=i;
            checkArray[2]=j;
            checkArray[3]=i;
            z=rook(checkArray,4);  //CHECKS WHETHER THE ROOK CAN ACTUALLY MOVE TO THE KING
            if(z==1)
            {

                check=1;
            } //ROOK CAN MOVE //KING IN CHECK
            else
            {
                check=0; //ROOK CAN NOT MOVE //KING IS NOT CHECKED BY THIS PIECE
                break;
            }
        }
        else if(board[i][k]=='q')
        {
            checkArray[0]=k;
            checkArray[1]=i;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            } //QUEEN CAN MOVE //KING IS CHECKED
            else
            {
                check=0;  //QUEEN CAN NOT MOVE //KING IS NOT CHECKED
                break;
            }
        }
    }

    for(k=j-1; k>=1&&check==0; k--)    //LEFTWARES
    {
        if(board[i][k]=='_');
        else if(board[i][k]=='.');
        else if(board[i][k]>'A'&&board[i][k]<'Z')
            break;
        else if(board[i][k]=='r')
        {
            checkArray[0]=k;
            checkArray[1]=i;
            checkArray[2]=j;
            checkArray[3]=i;
            z=rook(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i][k]=='q')
        {
            checkArray[0]=k;
            checkArray[1]=i;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }
    for(k=i+1; k<=8&&check==0; k++)        //DOWNWARDS
    {
        if(board[k][j]=='_');
        else if(board[k][j]=='.');
        else if(board[k][j]>'A'&&board[k][j]<'Z')
            break;
        else if(board[k][j]=='r')
        {
            checkArray[0]=j;
            checkArray[1]=k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=rook(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[k][j]=='q')
        {
            checkArray[0]=j;
            checkArray[1]=k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }
    for(k=i-1; k>=1&&check==0; k--)        //UPWARDS
    {
        if(board[k][j]=='_');
        else if(board[k][j]=='.');
        else if(board[k][j]>'A'&&board[k][j]<'Z')
        {
            break;

        }
        else if(board[k][j]=='r')
        {
            checkArray[0]=j;
            checkArray[1]=k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=rook(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[k][j]=='q')
        {
            checkArray[0]=j;
            checkArray[1]=k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }

    for(k=1; ((i+k)<=8)&&((j+k)<=8)&&(check==0); k++)  //DIAGONAL TO THE RIGHT DOWNWARDS

    {


        if(board[i+k][j+k]=='_');
        else if(board[i+k][j+k]=='.');
        else if(board[i+k][j+k]>'A'&&board[i+k][j+k]<'Z')
        {
            break;
        }
        else if(board[i+k][j+k]=='b')
        {
            checkArray[0]=(j+k);
            checkArray[1]=(i+k);
            checkArray[2]=j;
            checkArray[3]=i;
            z=bishop(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i+k][j+k]=='q')
        {
            checkArray[0]=(j+k);
            checkArray[1]=(i+k);
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }



    for(k=1; ((j-k)>=1)&&((i+k)<=8)&&(check==0); k++) //DIAGONAL TO THE LEFT DOWNWARDS
    {
        if(board[i+k][j-k]=='_');
        else if(board[i+k][j-k]=='.');
        else if(board[i+k][j-k]>'A'&&board[i+k][j-k]<'Z')
        {
            break;

        }
        else if(board[i+k][j-k]=='b')
        {
            //king_position2(10,11,board);
            checkArray[0]=(j-k);
            checkArray[1]=(i+k);
            checkArray[2]=j;
            checkArray[3]=i;

            z=bishop(checkArray,4);

            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i+k][j-k]=='q')
        {
            checkArray[0]=(j-k);
            checkArray[1]=(i+k);
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }

    }


    for(k=1; ((i-k)>=1)&&((j-k)>=1)&&(check==0); k++)  //DIAGONAL TO THE LEFT UPWARDS
    {

        if(board[i-k][j-k]=='_');
        else if (board[i-k][j-k]=='.' );
        else if (board[i-k][j-k]>'A'&& board[i-k][j-k]<'Z')
        {
            break;

        }
        else if(board[i-k][j-k]=='b')
        {
            checkArray[0]=(j-k);
            checkArray[1]=(i-k);
            checkArray[2]=j;
            checkArray[3]=i;
            z=bishop(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i-k][j-k]=='q')
        {
            checkArray[0]=(j-k);
            checkArray[1]=(i-k);
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }


    for(k=1; ((i-k)>=1)&&((j+k)<=8)&&(check==0); k++)       //DIAGONAL TO THE RIGHT UPWARDS
    {
        if(board[i-k][j+k]=='_');
        else if(board[i-k][j+k]=='.');
        else if(board[i-k][j+k]>'A'&&board[i-k][j+k]<'Z')
        {
            break;
        }
        else if(board[i-k][j+k]=='b')
        {
            checkArray[0]=(j+k);
            checkArray[1]=(i-k);
            checkArray[2]=j;
            checkArray[3]=i;
            z=bishop(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i-k][j+k]=='q')
        {
            checkArray[0]=(j+k);
            checkArray[1]=(i-k);
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }
//CHECKS WHETHER THE KING IS THREATENED BY A KNIGHT IN ANY DIRECTION
    if(board[i-2][j+1]=='n')
    {

        check=1;
    }
    else if(board[i+2][j+1]=='n')
    {

        check=1;

    }
    else if(board[i-2][j-1]=='n')
    {

        check=1;
    }
    else if(board[i+2][j-1]=='n')
    {

        check=1;
    }
    else if(board[i-1][j+2]=='n')
    {

        check=1;
    }
    else if(board[i+1][j+2]=='n')
    {

        check=1;
    }
    else if(board[i-1][j-2]=='n')
    {

        check=1;
    }
    else if(board[i+1][j-2]=='n')
    {

        check=1;
    }

    return check;

}


int checkmate1(int l,int m,char board[][m],int arrpostn[],int arraySize){ //CHECKMATE FUNCTION TO KING OF PLAYER TWO
    int i,j,s,r;
    int virtualArray[4]={0};
    char stored_piece[1];

    int flag=1;  //ASSUMING KING IS IN CHECK
    int x,y;

    for(i=1; (i<9)&&(flag==1); i++)
    {
        for(j=1; (j<9)&&(flag==1); j++)
        {
            if(board[i][j]=='K')     //SCANNING FOR KING POSITION ON THE BOARD
            {
                for(s=1; (s<9)&&(flag==1); s++)
                {
                    for(r=1; (r<9)&&(flag==1); r++)
                    {
                        virtualArray[0]=j;
                        virtualArray[1]=i;
                        virtualArray[2]=r;
                        virtualArray[3]=s;
                        arrpostn[0]=r;
                        arrpostn[1]=s;
                        arrpostn[2]=0;
                        arrpostn[3]=0;
                        x=king(virtualArray,4); //CHECKS IF KING CAN MOVE

                        if(x==1)
                        {

                            stored_piece[0]=board[virtualArray[3]][virtualArray[2]]; //TOKEN
                            board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                            board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                            y=check1(arrpostn,4,10,11,board);  //CHECKS WHETHER KING WOULD STILL BE IN CHECK
                            if (y==0)                          //THERE IS NO CHECK
                            {
                                virtualArray[0]=r;
                                virtualArray[1]=s;
                                virtualArray[2]=j;
                                virtualArray[3]=i;
                                board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                board[virtualArray[1]][virtualArray[0]]=stored_piece[0];
                                flag=0;

                            }
                            else
                            {
                                virtualArray[0]=r;
                                virtualArray[1]=s;
                                virtualArray[2]=j;
                                virtualArray[3]=i;
                                board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                board[virtualArray[1]][virtualArray[0]]=stored_piece[0];





                            }
                        }

                    }
                }

            }

        }

    }

    if(flag==1)     //THE KING IS STILL IN CHECK
    {
        for(i=1; (i<9)&&(flag==1); i++)
        {
            for(j=1; (j<9) &&(flag==1); j++)
            {
                if(board[i][j]>'A'&&board[i][j]<'Z') //SCANNING THE BOARD FOR PLAYER 2 PIECES
                {
                    for(s=1; (s<9)&&(flag==1); s++)
                    {

                        for(r=1; (r<9)&&(flag==1); r++)
                        {

                            virtualArray[0]=j;
                            virtualArray[1]=i;
                            virtualArray[2]=r;
                            virtualArray[3]=s;
                            switch(board[i][j])   //THE PIECE FOUND
                            {
                            case'Q':
                                x=queen(virtualArray,4);

                                if(x==1)  //IT CAN MOVE
                                {


                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                                    king_position2(10,11,board); //CALLS PLAYER TWO KING ON THE BOARD
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)                     //THERE IS NO CHECK
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]= stored_piece[0];
                                        flag=0;

                                    }
                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]= stored_piece[0];

                                    }
                                }
                                break;

                            case'B':
                                x=bishop(virtualArray,4);
                                if(x==1)    //IT CAN MOVE
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];
                                    king_position2(10,11,board);
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)    //CHECK IS NO LONGER THERE
                                    {



                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]= stored_piece[0];
                                        flag=0;
                                    }

                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]= stored_piece[0];

                                    }
                                }
                                break;


                            case'R':
                                x=rook(virtualArray,4);
                                if(x==1)
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                                    king_position2(10,11,board);
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];
                                        flag=0;
                                    }
                                    else
                                    {

                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]= stored_piece[0];

                                    }
                                }
                                break;

                            case'N':
                                x=knight(virtualArray,4);
                                if(x==1)
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                                    king_position2(10,11,board);
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];
                                        flag=0;
                                    }
                                    else
                                    {

                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                    }
                                }
                                break;


                            case 'P':
                                x=pawn(virtualArray,4);
                                if(x==1)
                                {
                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                                    king_position2(10,11,board);

                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                        flag=0;
                                    }
                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                    }
                                }
                                break;

                            }

                        }

                    }


                }

            }
        }

    }
    return flag;
}

int stalemate1(int l,int m,char board[][m],int arrpostn[],int arraySize){ //STALEMATE FUNCTION TO KING OF PLAYER TWO

    int i,j,s,r;
    int virtualArray[4]={0};
    char stored_piece[1];   //ARRAY FOR STORING PIECES IN STUDYING MOVES/VIRTUAL MOVES

    int flag=1;
    int x,y;

    for(i=1; (i<9)&&(flag==1); i++)
    {
        for(j=1; (j<9)&&(flag==1); j++)
        {
            if(board[i][j]=='K')
            {
                for(s=1; (s<9)&&(flag==1); s++)
                {
                    for(r=1; (r<9)&&(flag==1); r++)
                    {
                        virtualArray[0]=j;
                        virtualArray[1]=i;
                        virtualArray[2]=r;
                        virtualArray[3]=s;
                        arrpostn[0]=r;
                        arrpostn[1]=s;
                        arrpostn[2]=0;
                        arrpostn[3]=0;
                        x=king(virtualArray,4);

                        if(x==1)
                        {

                            stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                            board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                            board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                            y=check1(arrpostn,4,10,11,board);
                            if (y==0)
                            {
                                virtualArray[0]=r;
                                virtualArray[1]=s;
                                virtualArray[2]=j;
                                virtualArray[3]=i;

                                board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                flag=0;

                            }
                            else
                            {
                                virtualArray[0]=r;
                                virtualArray[1]=s;
                                virtualArray[2]=j;
                                virtualArray[3]=i;

                                board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                board[virtualArray[1]][virtualArray[0]]=stored_piece[0];




                            }
                        }

                    }
                }

            }

        }

    }

    if(flag==1)     //KING IS STILL IN CHECK
    {
        for(i=1; (i<9)&&(flag==1); i++)
        {
            for(j=1; (j<9) &&(flag==1); j++)
            {
                if(board[i][j]>'A'&&board[i][j]<'Z')
                {
                    for(s=1; (s<9)&&(flag==1); s++)
                    {

                        for(r=1; (r<9)&&(flag==1); r++)
                        {

                            virtualArray[0]=j;
                            virtualArray[1]=i;
                            virtualArray[2]=r;
                            virtualArray[3]=s;
                            switch(board[i][j])
                            {
                            case'Q':
                                x=queen(virtualArray,4);
                                if(x==1)
                                {


                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                                    king_position2(10,11,board);
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                        flag=0;

                                    }
                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                    }
                                }
                                break;

                            case'B':
                                x=bishop(virtualArray,4);
                                if(x==1)
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];


                                    king_position2(10,11,board);
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {



                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                        flag=0;
                                    }

                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                    }
                                }
                                break;


                            case'R':
                                x=rook(virtualArray,4);
                                if(x==1)
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                                    king_position2(10,11,board);
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                        flag=0;
                                    }
                                    else
                                    {

                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                    }
                                }
                                break;

                            case'N':
                                x=knight(virtualArray,4);
                                if(x==1)
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                                    king_position2(10,11,board);
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                        flag=0;
                                    }
                                    else
                                    {

                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                    }
                                }
                                break;


                            case 'P':
                                x=pawn(virtualArray,4);
                                if(x==1)
                                {


                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];

                                    king_position2(10,11,board);
                                    y=check1(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                        flag=0;
                                    }
                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                    }
                                }
                                break;

                            }

                        }

                    }


                }

            }
        }

    }
    return flag;
}


int check2(int arrpostn[],int arraySize,int x,int y,char board[][y]) //CHECKS PLAYER ONE KING
{
    int i,j,k,z,flag=0,check=0;
    int checkArray[4]={0};
    j=arrpostn[0];   //COPYING KING COLUMN POSITION ON THE BOARD
    i=arrpostn[1];    //COPYING KING ROW POSITION ON THE BOARD


    if(board[i-1][j+1]=='P')  //KING IS CHECKED BY A PAWN
    {

        check=1;
    }
    if(board[i-1][j-1]=='P')  //KING IS CHECKED BY A PAWN
    {

        check=1;
    }
    for(k=j+1; k<=8&&check==0; k++)      //SEARCHING RIGHTWARDS
    {
        if(board[i][k]=='_');
        else if(board[i][k]=='.');
        else if(board[i][k]>'a'&&board[i][k]<'z')  //KING IS NOT CHECKED IN THIS DIRECTION
            break;
        else if(board[i][k]=='R')
        {
            checkArray[0]=k;
            checkArray[1]=i;
            checkArray[2]=j;
            checkArray[3]=i;
            z=rook(checkArray,4);
            if(z==1)       //ROOK CAN MOVE  //KING IS IN CHECK
            {
                check=1;
            }
            else
            {
                check=0;        //ROOK CANNOT MOVE //NO CHECK
                break;
            }
        }
        else if(board[i][k]=='Q')
        {

            checkArray[0]=k;
            checkArray[1]=i;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {
                check=1;      //QUEEN CAN MOVE   //CHECK
            }
            else
            {
                check=0;        //NO CHECK
                break;
            }
        }
    }

    for(k=j-1; k>=1&&check==0; k--)           //SEARCHING LEFTWARDS
    {
        if(board[i][k]=='_');
        else if(board[i][k]=='.');
        else if(board[i][k]>'a'&&board[i][k]<'z')
            break;
        else if(board[i][k]=='R')
        {

            checkArray[0]=k;
            checkArray[1]=i;
            checkArray[2]=j;
            checkArray[3]=i;
            z=rook(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i][k]=='Q')
        {
            checkArray[0]=k;
            checkArray[1]=i;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }
    for(k=i+1; k<=8&&check==0; k++)                //SEARCHING DOWNWARDS
    {
        if(board[k][j]=='_');
        else if(board[k][j]=='.');
        else if(board[k][j]>'a'&&board[k][j]<'z')
            break;
        else if(board[k][j]=='R')
        {

            checkArray[0]=j;
            checkArray[1]=k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=rook(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[k][j]=='Q')
        {

            checkArray[0]=j;
            checkArray[1]=k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }
    for(k=i-1; k>=1&&check==0; k--)        //SEARCHING UPWARDS
    {
        if(board[k][j]=='_');
        else if(board[k][j]=='.');
        else if(board[k][j]>'a'&&board[k][j]<'z')
        {
            break;

        }
        else if(board[k][j]=='R')
        {
            checkArray[0]=j;
            checkArray[1]=k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=rook(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[k][j]=='Q')
        {
            checkArray[0]=j;
            checkArray[1]=k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }

    for(k=1; ((i+k)<=8)&&((j+k)<=8)&&(check==0); k++) //DIAGONALLY DOWNWARDS TO THE RIGHT

    {

        if(board[i+k][j+k]=='_');
        else if(board[i+k][j+k]=='.');
        else if(board[i+k][j+k]>'a'&&board[i+k][j+k]<'z')
        {
            break;
        }
        else if(board[i+k][j+k]=='B')
        {

            checkArray[0]=j+k;
            checkArray[1]=i+k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=bishop(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i+k][j+k]=='Q')
        {

            checkArray[0]=j+k;
            checkArray[1]=i+k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }



    for(k=1; ((j-k)>=1)&&(check==0)&&((i+k)<=8); k++) //VERTICALLY DOWANWARDS TO THE LEFT
    {
        if(board[i+k][j-k]=='_');
        else if(board[i+k][j-k]=='.');
        else if(board[i+k][j-k]>'a'&&board[i+k][j-k]<'z')
        {
            break;

        }
        else if(board[i+k][j-k]=='B')
        {
            checkArray[0]=j-k;
            checkArray[1]=i+k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=bishop(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i+k][j-k]=='Q')
        {
            checkArray[0]=j-k;
            checkArray[1]=i+k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {

                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }

    }


    for(k=1; ((i-k)>=1)&&((j-k)>=1)&&(check==0); k++)   //DIAGONALLY UPWARDS TO THE LEFT
    {

        if(board[i-k][j-k]=='_');
        else if (board[i-k][j-k]=='.' );
        else if (board[i-k][j-k]>'a'&& board[i-k][j-k]<'z')
        {
            break;

        }
        else if    (board[i-k][j-k]=='B')
        {
            checkArray[0]=j-k;
            checkArray[1]=i-k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=bishop(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i-k][j-k]=='Q')
        {
            checkArray[0]=j-k;
            checkArray[1]=i-k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }


    for(k=1; ((i-k)>=1)&&((j+k)<=8)&&(check==0); k++)
    {

        if(board[i-k][j+k]=='_');
        else if(board[i-k][j+k]=='.');
        else if(board[i-k][j+k]>'a'&&board[i-k][j+k]<'z')
        {
            break;
        }
        else if(board[i-k][j+k]=='B')
        {
            checkArray[0]=j+k;
            checkArray[1]=i-k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=bishop(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        else if(board[i-k][j+k]=='Q')
        {

            checkArray[0]=j+k;
            checkArray[1]=i-k;
            checkArray[2]=j;
            checkArray[3]=i;
            z=queen(checkArray,4);
            if(z==1)
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
    }                          //IF THREATENED BY A KNIGHT ANYWHERE

    if(board[i-2][j+1]=='N')
    {

        check=1;
    }
    else if(board[i+2][j+1]=='N')
    {

        check=1;

    }
    else if(board[i-2][j-1]=='N')
    {

        check=1;
    }
    else if(board[i+2][j-1]=='N')
    {

        check=1;
    }
    else if(board[i-1][j+2]=='N')
    {
        check=1;
    }
    else if(board[i+1][j+2]=='N')
    {

        check=1;
    }
    else if(board[i-1][j-2]=='N')
    {

        check=1;
    }
    else if(board[i+1][j-2]=='N')
    {

        check=1;
    }

    return check;

}





int stalemate2(int l,int m,char board[][m],int arrpostn[],int arraySize){ // stalemate to king player 1
    char stored_piece[1];
    int i,j,s,r;
    int virtualArray[4];

    int flag=1;
    int x,y;

    for(i=1; (i<9)&&(flag==1); i++)
    {
        for(j=1; (j<9)&&(flag==1); j++)
        {
            if(board[i][j]=='k')
            {
                for(s=1; (s<9)&&(flag==1); s++)
                {
                    for(r=1; (r<9)&&(flag==1); r++)
                    {
                        virtualArray[0]=j;
                        virtualArray[1]=i;
                        virtualArray[2]=r;
                        virtualArray[3]=s;
                        x=king(virtualArray,4);
                        arrpostn[0]=r;
                        arrpostn[1]=s;
                        arrpostn[2]=0;
                        arrpostn[3]=0;
                        if(x==1)
                        {


                            stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                            board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                            board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];



                            y=check2(arrpostn,4,10,11,board);
                            if (y==0)
                            {
                                virtualArray[0]=r;
                                virtualArray[1]=s;
                                virtualArray[2]=j;
                                virtualArray[3]=i;

                                board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                board[virtualArray[1]][virtualArray[0]]=stored_piece[0];



                                flag=0;

                            }
                            else
                            {
                                virtualArray[0]=r;
                                virtualArray[1]=s;
                                virtualArray[2]=j;
                                virtualArray[3]=i;

                                board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                            }
                        }

                    }
                }

            }

        }

    }

    if(flag==1)    //KING IS STILL CHECKED
    {
        for(i=1; (i<9)&&(flag==1); i++)
        {
            for(j=1; (j<9) &&(flag==1); j++)
            {
                if(board[i][j]>'a'&&board[i][j]<'z')
                {
                    for(s=1; (s<9)&&(flag==1); s++)
                    {

                        for(r=1; (r<9)&&(flag==1); r++)
                        {

                            virtualArray[0]=j;
                            virtualArray[1]=i;
                            virtualArray[2]=r;
                            virtualArray[3]=s;
                            switch(board[i][j])
                            {
                            case'q':
                                x=queen(virtualArray,4);
                                if(x==1)
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];




                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;



                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                        flag=0;

                                    }
                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                    }
                                }
                                break;

                            case'b':
                                x=bishop(virtualArray,4);
                                if(x==1)
                                {
                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];




                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {



                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                        flag=0;
                                    }

                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                    }
                                }
                                break;


                            case'r':
                                x=rook(virtualArray,4);
                                if(x==1)
                                {
                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];


                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];

                                        flag=0;
                                    }
                                    else
                                    {

                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];



                                    }
                                }
                                break;

                            case'n':
                                x=knight(virtualArray,4);
                                if(x==1)
                                {
                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];


                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];



                                        flag=0;
                                    }
                                    else
                                    {

                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]= stored_piece[0];


                                    }
                                }
                                break;


                            case 'p':
                                x=pawn(virtualArray,4);
                                if(x==1)
                                {
                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];



                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];



                                        flag=0;
                                    }
                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                    }
                                }
                                break;

                            }

                        }

                    }


                }

            }
        }

    }

    return flag;
}

int checkmate2(int l,int m,char board[][m],int arrpostn[],int arraySize){ // checkmate to king player 1
    char stored_piece[1];
    int i,j,s,r;
    int virtualArray[4]={0};

    int flag=1;
    int x,y;

    for(i=1; (i<9)&&(flag==1); i++)
    {
        for(j=1; (j<9)&&(flag==1); j++)
        {
            if(board[i][j]=='k')            //SCANNNING FOR KING POSITION ON THE BOARD
            {
                for(s=1; (s<9)&&(flag==1); s++)
                {
                    for(r=1; (r<9)&&(flag==1); r++)
                    {

                        virtualArray[0]=j;
                        virtualArray[1]=i;
                        virtualArray[2]=r;
                        virtualArray[3]=s;
                        x=king(virtualArray,4);

                        if(x==1)               //CHECKS WETHER KING CAN MOVE
                        {


                            stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                            board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                            board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];


                            arrpostn[0]=r;
                            arrpostn[1]=s;
                            arrpostn[2]=0;
                            arrpostn[3]=0;
                            y=check2(arrpostn,4,10,11,board); //CHECKS WETHER IT IS STILL IN CHECK
                            if (y==0)                               //IT IS NO LONGER IN CHECK
                            {
                                virtualArray[0]=r;
                                virtualArray[1]=s;
                                virtualArray[2]=j;
                                virtualArray[3]=i;

                                board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                board[virtualArray[1]][virtualArray[0]]= stored_piece[0];



                                flag=0;

                            }
                            else
                            {
                                virtualArray[0]=r;
                                virtualArray[1]=s;
                                virtualArray[2]=j;
                                virtualArray[3]=i;

                                board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                            }
                        }

                    }
                }

            }

        }

    }

    if(flag==1)     //KING IS STILL IN CHECK
    {
        for(i=1; (i<9)&&(flag==1); i++)
        {
            for(j=1; (j<9) &&(flag==1); j++)
            {
                if(board[i][j]>'a'&&board[i][j]<'z')  //SEARCHING FOR PLAYER 1 PIECES
                {
                    for(s=1; (s<9)&&(flag==1); s++)
                    {

                        for(r=1; (r<9)&&(flag==1); r++)
                        {

                            virtualArray[0]=j;
                            virtualArray[1]=i;
                            virtualArray[2]=r;
                            virtualArray[3]=s;
                            switch(board[i][j])
                            {
                            case'q':

                                x=queen(virtualArray,4);
                                if(x==1)     //IT CAN MOVE
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];




                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);  //CHECKS WETHER KING IS STILL IN CHECK
                                    if(y==0)                           //NO LONGER IN CHECK
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;



                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]= stored_piece[0];

                                        flag=0;

                                    }
                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                    }
                                }
                                break;

                            case'b':
                                x=bishop(virtualArray,4);
                                if(x==1)
                                {
                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];


                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {



                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;
                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                        flag=0;
                                    }

                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]= stored_piece[0];


                                    }
                                }
                                break;


                            case'r':
                                x=rook(virtualArray,4);
                                if(x==1)
                                {
                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];


                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                        flag=0;
                                    }
                                    else
                                    {

                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];



                                    }
                                }
                                break;

                            case'n':
                                x=knight(virtualArray,4);
                                if(x==1)
                                {
                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];


                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;


                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];



                                        flag=0;
                                    }
                                    else
                                    {

                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                    }
                                }
                                break;


                            case 'p':

                                x=pawn(virtualArray,4);
                                if(x==1)
                                {

                                    stored_piece[0]=board[virtualArray[3]][virtualArray[2]];
                                    board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                    board[virtualArray[1]][virtualArray[0]]=startup[virtualArray[1]][virtualArray[0]];



                                    king_position1(10,11,board);
                                    y=check2(arrpostn,4,10,11,board);
                                    if(y==0)
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];



                                        flag=0;
                                    }
                                    else
                                    {
                                        virtualArray[0]=r;
                                        virtualArray[1]=s;
                                        virtualArray[2]=j;
                                        virtualArray[3]=i;

                                        board[virtualArray[3]][virtualArray[2]]=board[virtualArray[1]][virtualArray[0]];
                                        board[virtualArray[1]][virtualArray[0]]=stored_piece[0];


                                    }
                                }
                                break;

                            }

                        }

                    }


                }

            }
        }

    }

    return flag;
}



int scanInput1(char arrstrt[],int arrSize)  //TAKES INPUT FROM PLAYER ONE
{
    int i,flag=0,x=0,j=0,y,undo=0,redo=0,ret=0,save=0,load=0;
    int arrint[4]={0};
    int arrayInteger[4]={0};
    char stored_piece[1];
    for (i=0; (i<4)&&(undo==0)&&(redo==0)&&(save==0)&&(load==0); i++) //INPUT
    {

        scanf("%c",&arrstrt[i]);

        if(arrstrt[0]=='U')                      //UNDO
        {
            ret=1;

            while(getchar()!='\n');
            undo=undoo(arrstrt,5,arrint,4);
            if(undo==0)
            {
                return scanInput1(arrstrt,4);
            }

        }
        else if(arrstrt[0]=='R')                //REDO
        {


            while(getchar()!='\n');
            redo=redoo(arrstrt,5,arrint,4);
            if(redo==0)
            {
                return scanInput1(arrstrt,4);
            }

        }
        else if(arrstrt[0]=='S')             //SAVE
        {
            save=2;



        }
        else if(arrstrt[0]=='L')                //LOAD
        {
            load=3;
        }
        else if(arrstrt[i]=='\n'){
        printf("CANNOT MOVE !!! PLEASE ENTER A VALID MOVE \n");
       // while(getchar()!='\n');
        return scanInput1(arrstrt,4);

    }
    }
    for(i=0; (i<4)&&(flag==0)&&(undo==0)&&(redo==0)&&(load==0)&&(save==0); i++)  //CHANGING CHARS TO CORRESPONDING INT
    {
        arrint[i]=get_crpint(arrstrt[i]);
        arrayInteger[i]=get_crpint(arrstrt[i]);

        if((arrint[i]==0)||((arrstrt[0]>=49)&&(arrstrt[0]<=56))||((arrstrt[2]>=49)&&(arrstrt[2]<=56)))      //VALIDATION
        {
            printf("CANNOT MOVE !! PLEASE ENTER A VALID MOVE \n");
            while(getchar()!='\n');
            return scanInput1(arrstrt,4);

            flag=1;

        }
    }
    if((undo==0)&&(redo==0)&&(save==0)&&(load==0))
    {
        int temp[2]= {arrint[0],arrint[1]};

        switch(board[arrint[1]][arrint[0]])       //PIECE CASE
        {
        case 'p':
            x=pawn(arrint,4);
            if(x==1)
            {
                if(after_check==2)   //IF A MOVE AFTER BEING CHECKED
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];                        //MOVE
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)                      //IF STILL IN CHECK
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)                             //SAVING THE MOVE FOR UNDO/REDO
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }
                        promotion(arrstrt,4,arrayInteger,4);
                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        promotion(arrstrt,4,arrayInteger,4);
                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE \n");    //INVALID MOVE
                while(getchar()!='\n');
                return scanInput1(arrstrt,4);
            }
            break;
        case'b':
            x=bishop(arrint,4);
            if(x==1)
            {
                if(after_check==2)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE10 \n");
                while(getchar()!='\n');
                return scanInput1(arrstrt,4);
            }
            break;
        case'r':
            x=rook(arrint,4);
            if(x==1)
            {
                if(after_check==2)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]= stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]= stored_piece[0];
                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE10 \n");
                while(getchar()!='\n');
                return scanInput1(arrstrt,4);
            }
            break;
        case'n':
            x=knight(arrint,4);
            if(x==1)
            {
                if(after_check==2)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];

                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE10 \n");
                while(getchar()!='\n');
                return scanInput1(arrstrt,4);
            }
            break;
        case'k':
            x=king(arrint,4);
            if(x==1)
            {
                if(after_check==2)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE \n");
                while(getchar()!='\n');
                return scanInput1(arrstrt,4);
            }
            break;
        case'q':
            x=queen(arrint,4);
            if(x==1)
            {
                if(after_check==2)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];

                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position1(10,11,board);
                    y=check2(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput1(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE10 \n");
                while(getchar()!='\n');
                return scanInput1(arrstrt,4);
            }
            break;
        default:
        {
            printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE16 \n");
            while(getchar()!='\n');
            return scanInput1(arrstrt,4);
        }

        }
    }

    if(ret==1)
    {
        return undo;
    }
    else if(save==2)
    {
        return save;

    }
    else if(load==3)
    {
        return load;
    }
    else
    {
        return redo;
    }
}

int scanInput2(char arrstrt[],int arrsize)    //TAKES INPUT FROM PLAYER TWO
{
    int i,flag=0,x=0,j=0,y,undo=0,redo=0,ret=0,save=0,load=0;
    int arrint[4]={0};
    int arrayInteger[4]={0};
    char stored_piece[1];
    for (i=0; (i<4)&&(undo==0)&&(redo==0)&&(save==0)&&(load==0); i++)
    {

        scanf("%c",&arrstrt[i]);

        if(arrstrt[0]=='U')
        {
            ret=1;

            while(getchar()!='\n');
            undo=undoo(arrstrt,5,arrint,4);
            if(undo==0)
            {
                return scanInput2(arrstrt,4);
            }

        }
        else if(arrstrt[0]=='R')
        {


            while(getchar()!='\n');
            redo=redoo(arrstrt,5,arrint,4);
            if(redo==0)
            {
                return scanInput2(arrstrt,4);
            }

        }
        else if(arrstrt[0]=='S')
        {
            save=2;



        }
        else if(arrstrt[0]=='L')
        {
            load=3;
        }
        else if(arrstrt[i]=='\n')
        {
        printf("CANNOT MOVE !!! PLEASE ENTER A VALID MOVE \n");
        return scanInput2(arrstrt,4);
        }
    }
    for(i=0; (i<4)&&(flag==0)&&(undo==0)&&(redo==0)&&(load==0)&&(save==0); i++)
    {
        arrint[i]=get_crpint(arrstrt[i]);
        arrayInteger[i]=get_crpint(arrstrt[i]);

        if((arrint[i]==0)||((arrstrt[0]>=49)&&(arrstrt[0]<=56))||((arrstrt[2]>=49)&&(arrstrt[2]<=56)))
        {

            printf("CANNOT MOVE !! PLEASE ENTER A VALID MOVE \n");
            while(getchar()!='\n');
            return scanInput2(arrstrt,4);

            flag=1;

        }
    }
    if((undo==0)&&(redo==0)&&(save==0)&&(load==0))
    {
        int temp[2]= {arrint[0],arrint[1]};

        switch(board[arrint[1]][arrint[0]])
        {
        case 'P':
            x=pawn(arrint,4);
            if(x==1)
            {
                if(after_check==1)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }
                        promotion(arrstrt,4,arrayInteger,4);
                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        promotion(arrstrt,4,arrayInteger,4);
                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE \n");
                while(getchar()!='\n');
                return scanInput2(arrstrt,4);
            }
            break;
        case'B':
            x=bishop(arrint,4);
            if(x==1)
            {
                if(after_check==1)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]= stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE10 \n");
                while(getchar()!='\n');
                return scanInput2(arrstrt,4);
            }
            break;
        case'R':
            x=rook(arrint,4);
            if(x==1)
            {
                if(after_check==1)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE \n");
                while(getchar()!='\n');
                return scanInput2(arrstrt,4);
            }
            break;
        case'N':
            x=knight(arrint,4);
            if(x==1)
            {
                if(after_check==1)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]= stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE10 \n");
                while(getchar()!='\n');
                return scanInput2(arrstrt,4);
            }
            break;
        case'K':
            x=king(arrint,4);
            if(x==1)
            {
                if(after_check==1)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];

                    //move(10,11,board,arrint,4);
                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {


                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]= stored_piece[0];
                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE10 \n");
                while(getchar()!='\n');
                return scanInput2(arrstrt,4);
            }
            break;
        case'Q':
            x=queen(arrint,4);
            if(x==1)
            {
                if(after_check==1)
                {
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];


                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING IS CHECKED !!PLEASE ENTER A VALID MOVE \n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }

                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);


                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }

                        moveRecordSize++;

                    }

                }

                else
                {

                    //move(10,11,board,arrint,4);
                    stored_piece[0]=board[arrint[3]][arrint[2]];
                    board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                    board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];
                    king_position2(10,11,board);
                    y=check1(arrpostn,4,10,11,board);
                    if(y==1)
                    {

                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];

                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];

                        printf("CANNOT MOVE !! YOUR KING WILL BE CHECKED !!! PLEASE ENTER ANOTHER MOVE:\n");
                        while(getchar()!='\n');
                        return scanInput2(arrstrt,4);
                    }
                    else
                    {
                        arrint[0]=arrint[2];
                        arrint[1]=arrint[3];
                        arrint[2]=temp[0];
                        arrint[3]=temp[1];


                        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];
                        board[arrint[1]][arrint[0]]=stored_piece[0];
                        move(10,11,board,arrayInteger,4);



                        for(i=0; i<4; i++)
                        {
                            move_record[moveRecordSize][i]=arrstrt[i];
                            move_record[moveRecordSize+1][i]='0';
                        }


                        moveRecordSize++;
                    }
                }
            }


            else
            {
                printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE10 \n");
                while(getchar()!='\n');
                return scanInput2(arrstrt,4);
            }
            break;
        default:
        {
            printf("CANNONT MOVE !! PLEASE ENTER A VALID MOVE \n");
            while(getchar()!='\n');
            return scanInput2(arrstrt,4);
        }

        }
    }

    if(ret==1)
    {
        return undo;
    }
    else if(save==2)
    {
        return save;

    }
    else if(load==3)
    {
        return load;
    }
    else
    {
        return redo;
    }
}





int undoo(char arrstrt[],int arraysize1,char arrint[],int arraysize2){ // TO UNDO USER MOVES
    int i,y=1;
    if(moveRecordSize==0)
    {
        printf("CANNOT UNDO MORE !!!THIS IS THE FIRST MOVE \n PLEASE ENTER A VALID MOVE :"); // BEFORE THE FIRST MOVE ANY MOVE CANNOT BE UNDONE
        y=0;
    }
    else                                                      // IMPORTS THE PREVIOUS MOVE FROM MOVE_RECORD ARRAY
    {
        arrstrt[0]=move_record[moveRecordSize-1][2];
        arrstrt[1]=move_record[moveRecordSize-1][3];
        arrstrt[2]=move_record[moveRecordSize-1][0];
        arrstrt[3]=move_record[moveRecordSize-1][1];

        for(i=0; i<4; i++)
        {
            arrint[i]=get_crpint(arrstrt[i]);
        }

        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];

        board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];

        if((move_record[moveRecordSize-1][4]>'a')&&(move_record[moveRecordSize-1][4]<'z'))  // IMPORTS PLAYER 1 TAKEN OUT PIECES FROM MOVE_RECORD ARRAY
        {
            board[arrint[1]][arrint[0]]=move_record[moveRecordSize-1][4];
            A[0][columnSize2-2]=' ';
            A[0][columnSize2-2]=' ';
            columnSize2=columnSize2-2;
        }


        else if((move_record[moveRecordSize-1][4]>'A')&&(move_record[moveRecordSize-1][4]<'Z')) // IMPORTS PLAYER 2 TAKEN OUT PIECES FROM MOVE_RECORD ARRAY
        {
            board[arrint[1]][arrint[0]]=move_record[moveRecordSize-1][4];
            B[0][columnSize1-2]=' ';
            B[0][columnSize1-1]=' ';
            columnSize1=columnSize1-2;
        }

        if((move_record[moveRecordSize-1][5]>'A')&&(move_record[moveRecordSize-1][5]<'Z'))  // EXCHANGES PROMOTED PIECE WITH A PAWN
        {
            board[arrint[3]][arrint[2]]='P';
        }
        else if((move_record[moveRecordSize-1][5]>'a')&&(move_record[moveRecordSize-1][5]<'z'))
        {
            board[arrint[3]][arrint[2]]='p';

        }

        moveRecordSize--;
        //PRINTING OUT BOARDS
        system("cls");
        printf("\n");
        printArray(10,11,board);
        printf("\n|");
        printArray(1,30,A);
        printf("\n|");
        printArray(1,30,B);
    }
    return y;
}


int redoo(char arrstrt[],int arraySize1,char arrint[],int arraySize2)  //TO REDO PLAYER MOVES
{
    int i,y=1;
    if(move_record[moveRecordSize][0]=='0')       //AFTER THE LAST MOVE , ANY MORE MOVES CANNOT BE REDONE
    {
        printf("CANNOT REDO MORE !!!THIS IS THE LAST MOVE \nPLEASE ENTER A VALID MOVE :");
        y=0;
    }
    else
    {
        // IMPORTS THE NEXT MOVE FROM MOVE_RECORD ARRAY
        arrstrt[0]=move_record[moveRecordSize][0];
        arrstrt[1]=move_record[moveRecordSize][1];
        arrstrt[2]=move_record[moveRecordSize][2];
        arrstrt[3]=move_record[moveRecordSize][3];

        for(i=0; i<4; i++)
        {
            arrint[i]=get_crpint(arrstrt[i]);
        }
        board[arrint[3]][arrint[2]]=board[arrint[1]][arrint[0]];

        board[arrint[1]][arrint[0]]=startup[arrint[1]][arrint[0]];



        if((move_record[moveRecordSize][4]>'a')&&(move_record[moveRecordSize][4]<'z'))  //RESTORES  PLAYER 1 TAKEN OUT PIECES
        {

            A[0][columnSize2]=move_record[moveRecordSize][4];
            A[0][columnSize2-1]='|';
            columnSize2=columnSize2+2;
        }


        if((move_record[moveRecordSize][4]>'A')&&(move_record[moveRecordSize][4]<'Z'))  //RESTORES PLAYER 2 TAKEN OUT PIECES
        {

            B[0][columnSize1]=move_record[moveRecordSize][4];
            B[0][columnSize1-1]='|';
            columnSize1=columnSize1+2;
        }

        if((move_record[moveRecordSize][5]>'A')&&(move_record[moveRecordSize][5]<'Z'))  // RESTORES THE PROMOTRD PIECE
        {
            board[arrint[3]][arrint[2]]=move_record[moveRecordSize][5];
        }
        else if((move_record[moveRecordSize][5]>'a')&&(move_record[moveRecordSize][5]<'z'))
        {
            board[arrint[3]][arrint[2]]=move_record[moveRecordSize][5];

        }

        moveRecordSize++;               //PRINTING OUT BOARDS
        system("cls");
        printf("\n");
        printArray(10,11,board);
        printf("\n|");
        printArray(1,30,A);
        printf("\n|");
        printArray(1,30,B);
    }
    return y;
}



int main()
{
    int status=1;
    int i=0,j=0;
    FILE *save;


    printf("SIMPLE CHESS PROGRAM.\n ENTER YOUR MOVES IN CAPITAL LETTERS(A2A4)\n Undo:U \t Redo:R \t Save Game:S \t Load:L\n\n");
    printArray(10,11,board);
    printf("\n");
    int x,y,z,s;
    int T;

    while(status)    //INFINITE LOOP ENDS AT CHECKMATES/STALEMATES
    {

        turn=1;
        while (turn==1)
        {
            printf("PLayer one turn :");
            z=scanInput1(arrstrt,4);
            if(z==1)
            {
                break;
            }
            else if(z==2)
            {
                save= fopen("save.txt","w");

                fwrite(board,110,1,save);


                fwrite(A,40,1,save);

                fwrite(B,40,1,save);
                fprintf(save,"1");

                fclose(save);

                while (getchar()!='\n');
                printf("GAME SAVED! ENTER A MOVE:");

                scanInput1(arrstrt,4);



            }




            else if(z==3)
            {
                save=fopen("save.txt","r");
                if(save==NULL){
                    printf("FILE NOT FOUND!! YOU HAVE NOT SAVED A GAME YET.");
                    printf("Please enter a valid move.");
                    scanInput1(arrstrt,4);
                }
                else{

                fread(board,110,1,save);

                fread(A,40,1,save);

                fread(B,40,1,save);

                fscanf(save,"%d",&T);

                fclose(save);

                if(T==1)
                {
                    printf("Player one turn:");
                    while(getchar()!='\n');
                    scanInput1(arrstrt,4);
                }
                else if(T==2)
                {
                    printf("Player two turn:");
                    while(getchar()!='\n');
                    scanInput2(arrstrt,4);
                }

            }
            }
            while(getchar()!='\n');
            system("cls");
            printf("\n");
            printArray(10,11,board);
            printf("\n|");
            printArray(1,30,A);
            printf("\n|");
            printArray(1,30,B);

            king_position2(10,11,board);
            y=check1(arrpostn,4,10,11,board);

            if(y==1)
            {
                x=checkmate1(10,11,board,arrpostn,4);
                if(x==1)
                {
                    printf("CHECKMATE !!!! PLAYER 1 WON \n");
                    status=0;
                    break;
                }
                else
                {
                    printf("PLAYER TWO IS CHECKED !!!!\n");
                    after_check=1;
                }


            }
            else
            {
                king_position2(10,11,board);
                s=stalemate1(10,11,board,arrpostn,4);

                if(s==1)
                {

                    printf("STALEMATE !!! PLAYER TWO HAS NO MOVES \n");
                    status=0;
                    break;


                }
            }

            turn=2;
        }
        if((x==1) || (s==1))
        {
            break;
        }

        turn=2;
        while(turn==2)
        {

            printf("PLayer two turn :");


            z=scanInput2(arrstrt,4);

            if(z==1)
            {

                break;
            }
            else if(z==2)
            {



                save= fopen("save.txt","w");

                fwrite(board,110,1,save);


                fwrite(A,40,1,save);

                fwrite(B,40,1,save);
                fprintf(save,"2");

                fclose(save);
                printf("GAME SAVED! ENETR A MOVE");


                while (getchar()!='\n');
                scanInput2(arrstrt,4);



            }




            else if(z==3)
            {
                save=fopen("save.txt","r");
                if(save==NULL){
                    printf("ERROR! FILE NOT FOUND. YOU HAVE NOT SAVED A GAME YET.\n");
                    printf("PLEASE ENTER A VALID MOVE=");
                    scanInput2(arrstrt,4);
                }
                else{

                fread(board,110,1,save);

                fread(A,40,1,save);

                fread(B,40,1,save);
                scanf(save,"%d",&T);


                fclose(save);
                }

                if(T==1)
                {
                    printf("Player one turn");

                    while(getchar()!='\n');
                    scanInput1(arrstrt,4);
                }
                else if(T==2)
                {
                    printf("Player two turn");
                    while(getchar()!='\n');
                    scanInput2(arrstrt,4);
                }




            }
            while(getchar()!='\n');



            system("cls");
            printf("\n");
            printArray(10,11,board);
            printf("\n|");
            printArray(1,30,A);
            printf("\n|");
            printArray(1,30,B);

            king_position1(10,11,board);
            y=check2(arrpostn,4,10,11,board);
            if(y==1)
            {
                x=checkmate2(10,11,board,arrpostn,4);
                if(x==1)
                {
                    printf("CHECKMATE !!! PLAYER 2 WON \n");
                    status=0;
                }
                else
                {
                    printf("PLAYER ONE IS CHECKED !!!! \n");
                    after_check=2;
                }
            }
            else
            {
                king_position1(10,11,board);
                s=stalemate2(10,11,board,arrpostn,4);
                if(s==1)
                {
                    printf("STALEMATE !!! PLAYER ONE HAS NO MOVES \n");
                    status=0;
                    break;


                }
            }

            turn=1;
            //while(getchar()!='\n');
        }
        if((x==1) || (s==1))
        {
            break;
        }



    }

    return 0;
}






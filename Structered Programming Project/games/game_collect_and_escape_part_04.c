#pragma once

#include "game_components/game_utility.c"

typedef struct
{
    int x,y;
} CnEp4_Player;

int play_collect_and_escape_part_04(void);

int CnEp4_initialze_obstacle(char arr[][100]);

int CnEp4_moving_array(char arr[][100], int last);

int CnEp4_generate_new_obstacle(char arr[][100], int last);
void CnEp4_first_greater_block_generating(char arr[][100], int last, int current, int row_num);
void CnEp4_last_greater_block_generating(char arr[][100], int last, int current, int row_num);

int CnEp4_navigation(char arr[][100]);

void CnEp4_printarray(char arr[][100]);

void CnEp4_collison_screen(void);

    CnEp4_Player CnEp4_player;
    int CnEp4_game_difficulty = 1;

int play_collect_and_escape_part_04(void)
{
    initialize_main_screen();
    setGameViewport(22, 6, 100, 32);

    char arr[40][100];

    int last = CnEp4_initialze_obstacle(arr);

    //gameloop
    int result = CnEp4_moving_array(arr, last);

    system("cls");

    return result;
}

int CnEp4_initialze_obstacle(char arr[][100])
{
    //initializing everything to space
    for(int i=0; i<40; i++)
    {
        for(int j=0; j<100; j++)
            arr[i][j]=32;
    }

    //initialize the unused sides 0 to 25 and 75 to 100
    for(int i=0; i<40; i++)
    {
        for(int j=0; j<25; j++)
            arr[i][j]=219;
    }


    for(int i=0; i<40; i++)
    {
        for(int j=75; j<100; j++)
            arr[i][j]=219;
    }

    int current, last;

    srand(time(0));

    current= rand()%35;

    //initializing player position
    CnEp4_player.x=35;
    CnEp4_player.y = current+7+24;

    arr[35][CnEp4_player.y]='[';
    arr[35][(CnEp4_player.y)+1]=']';

    //initializing lowest/4th block

    for(int i=30; i<40; i++)
    {
        for(int j=25; j<current+25; j++)
            arr[i][j]=219;
    }

    for(int i=30; i<40; i++)
    {
        for(int j=current+40; j<75; j++)
            arr[i][j]=219;
    }

    last= current;

    //initializing middle/3rd block

    current=rand()%35;

    //the following lines are basically for visuals, dont try to understand this at home

    if(current>=last)
        CnEp4_first_greater_block_generating(arr, last, current, 20);



    if(current<last)
        CnEp4_last_greater_block_generating(arr, last, current, 20);



    last= current;


    //initializing top visible block/2nd block

    current=rand()%35;

    if(current>=last)
        CnEp4_first_greater_block_generating(arr, last, current, 10);



    if(current<last)
        CnEp4_last_greater_block_generating(arr, last, current, 10);



    last= current;
    //initializing secret/not visible/first block

    current=rand()%35;

    if(current>=last)
        CnEp4_first_greater_block_generating(arr, last, current, 0);

    if(current<last)
        CnEp4_last_greater_block_generating(arr, last, current, 0);

    return current;
}

int CnEp4_moving_array(char arr[][100], int last)
{


    for(int i = 1; i < 99; i++)
    {
        main_screen[39][25 + i] = 196;
    }

    main_screen[40][25] = 'P';
    main_screen[40][26] = 'r';
    main_screen[40][27] = 'o';
    main_screen[40][28] = 'g';
    main_screen[40][29] = 'r';
    main_screen[40][30] = 'e';
    main_screen[40][31] = 's';
    main_screen[40][32] = 's';
    main_screen[40][33] = ':';

    CnEp4_printarray(arr);


    show_main_screen();
    system("cls");


    int num=10, target;


    int current;
    srand(time(0));

    if(CnEp4_game_difficulty==0)
        target=580;
    else
        target=1100;


    int escape_loop=0;

    while(1)
    {
        //player navigating

       int result= CnEp4_navigation(arr);

        if(result==-1)
            return -1;

        for(int i=39; i>0; i--)
        {
            for(int j=0; j<100; j++)
            {

//blocks moving below
                arr[i][j]=arr[i-1][j];



//condition to not move player
                if(arr[i][j]=='[' )


                    arr[i][j]=32;

                if(arr[i][j]==']' )


                    arr[i][j]=32;



                arr[CnEp4_player.x][CnEp4_player.y]='[';
                arr[CnEp4_player.x][(CnEp4_player.y)+1]=']';

            }
        }



        //system("cls");
        resetCursorPosition();

        CnEp4_printarray(arr);

        for(int k=0; (k< (90*escape_loop)/target) && k<90 ; k++)
            main_screen[40][35 + k] = 219;
        for(int k=(90*escape_loop)/target ; k<90; k++)
            main_screen[40][35 + k] = ' ';

        show_main_screen();

        if(CnEp4_game_difficulty==0)
        delay(275111111);
        else if (CnEp4_game_difficulty==1 && escape_loop<800)
            delay(275111111);
        else
            delay(175111111);

        //collison detection
        if(( arr[(CnEp4_player.x)-1][CnEp4_player.y]!=32) && (arr[CnEp4_player.x][(CnEp4_player.y)-1]!=32))
        {
            for(int x=0; x<3; x++)
            {
                //system("cls");
                resetCursorPosition();

                CnEp4_collison_screen();
            }

            pressEnterToContinue();
            system("cls");
            return 0;
        }

        if(( arr[(CnEp4_player.x)-1][CnEp4_player.y+1]!=32) && (arr[CnEp4_player.x][(CnEp4_player.y)+2]!=32))
        {

            for(int x=0; x<3; x++)
            {
                //system("cls");
                resetCursorPosition();

                CnEp4_collison_screen();
            }

            pressEnterToContinue();
            system("cls");
            return 0;
        }

        if(CnEp4_game_difficulty==0)
        {
            if(escape_loop<50)
                delay(993333333);
            else if(escape_loop<180)
                delay(500000000);
            else if(escape_loop<300)
                delay(217777777);
            else if(escape_loop<420)
                delay(73333333);

        }
        else if(CnEp4_game_difficulty==1)
        {
            if(escape_loop<40)
                delay(333333333);
            else if(escape_loop<150)
                delay(100000000);
            else if(escape_loop<280)
                delay(77777777);
            else if(escape_loop<600)
                delay(33333333);


        }
        //updating secret block when all 10 rows of previous secret block is moved below

        if(num==0 && escape_loop<target )
        {
            last=CnEp4_generate_new_obstacle(arr,last);

            num=10;
        }
        else
            num--;

        if(escape_loop==target)
        {
            for(int i=0; i<10; i++)
            {
                for(int j=5; j<95; j++)
                    arr[i][j]=32;
            }
        }

        if(escape_loop>target+26)
            return 1;
            else if(escape_loop>target+13)
            delay(333333333);




        escape_loop++;


    }

    return 0;
}

void CnEp4_printarray(char arr[][100])
{
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<100; j++)
            main_screen[9 + i][25 + j] = arr[10 + i][j];
    }

}

int CnEp4_generate_new_obstacle(char arr[][100], int last)
{
    int current;

    current= rand()%35;

    if(current>=last)
    {
        for(int i=0; i<10; i++)
        {
            for(int j=25; j<75; j++)
                arr[i][j]=32;
        }

        CnEp4_first_greater_block_generating(arr, last, current, 0);

    }

    if(current<last)
    {
        for(int i=0; i<10; i++)
        {
            for(int j=25; j<75; j++)
                arr[i][j]=32;
        }



        CnEp4_last_greater_block_generating(arr, last, current, 0);


    }

    return current;

}

void CnEp4_last_greater_block_generating(char arr[][100], int last, int current, int row_num)
{
    for(int i=row_num; i<row_num+10; i++)
    {
        for(int j=25; j<current+25; j++)
            arr[i][j]=219;
    }

    for(int i=row_num; i<row_num+5; i++)
    {
        for(int j=current+40; j<75; j++)
            arr[i][j]=219;
    }

    for(int i=row_num+5; i<row_num+10; i++)
    {
        for(int j=last+40; j<75; j++)
            arr[i][j]=219;
    }

}

void CnEp4_first_greater_block_generating(char arr[][100], int last, int current, int row_num)
{
    for(int i=row_num; i<row_num+5; i++)
    {
        for(int j=25; j<current+25; j++)
            arr[i][j]=219;

    }

    for(int i=row_num+5; i<row_num+10; i++)
    {
        for(int j=25; j<last+25; j++)
            arr[i][j]=219;
    }

    for(int i=row_num; i<row_num+10; i++)
    {
        for(int j=current+40; j<75; j++)
            arr[i][j]=219;
    }

}

int CnEp4_navigation(char arr[][100])
{

    if((GetAsyncKeyState(VK_LEFT) & 0X8000) )
    {
        for(int i=0; i<3; i++)
        {
            if(arr[CnEp4_player.x][(CnEp4_player.y)-1]==32)
            {
                CnEp4_player.y=(CnEp4_player.y)-1;

                arr[CnEp4_player.x][CnEp4_player.y]='[';
                arr[CnEp4_player.x][CnEp4_player.y+1]=']';
                arr[CnEp4_player.x][CnEp4_player.y+2]=32;


            }
        }
    }
    else if((GetAsyncKeyState(VK_RIGHT) & 0X8000) )
    {
        for(int i=0; i<3; i++)
        {
            if(arr[CnEp4_player.x][(CnEp4_player.y)+2]==32)
            {
                CnEp4_player.y=(CnEp4_player.y)+1;

                arr[CnEp4_player.x][CnEp4_player.y]='[';
                arr[CnEp4_player.x][CnEp4_player.y+1]=']';
                arr[CnEp4_player.x][CnEp4_player.y-1]=32;

            }
        }
    }
    else if((GetAsyncKeyState(VK_UP) & 0X8000) )
    {
        for(int i=0; i<3; i++)
        {
            if((arr[CnEp4_player.x-1][CnEp4_player.y]==32) && (arr[CnEp4_player.x-1][(CnEp4_player.y)+1]==32) && CnEp4_player.x>=15)
            {
                CnEp4_player.x=(CnEp4_player.x)-1;

                arr[CnEp4_player.x][CnEp4_player.y]='[';
                arr[CnEp4_player.x][CnEp4_player.y+1]=']';
                arr[CnEp4_player.x+1][CnEp4_player.y]=32;
                arr[CnEp4_player.x+1][CnEp4_player.y+1]=32;


            }
        }
    }

    else if((GetAsyncKeyState(VK_DOWN) & 0X8000) )
    {
        for(int i=0; i<3; i++)
        {
            if((arr[CnEp4_player.x+1][CnEp4_player.y]==32) && (arr[CnEp4_player.x+1][(CnEp4_player.y)+1]==32) && CnEp4_player.x<=35)
            {
                CnEp4_player.x=(CnEp4_player.x)+1;

                arr[CnEp4_player.x][CnEp4_player.y]='[';
                arr[CnEp4_player.x][CnEp4_player.y+1]=']';
                arr[CnEp4_player.x-1][CnEp4_player.y]=32;
                arr[CnEp4_player.x-1][CnEp4_player.y+1]=32;

            }
        }
    }
       else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
    {
        //add pause game function

       // if(goToMainMenu==1)
            return -1;
    }

    return 0;



}

void CnEp4_collison_screen(void)
{

    srand(time(0));
    int random;
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<100; j++)
        {
            random=rand()%2;

            if(random==0)
                main_screen[9 + i][25 + j] = 219;
            else
                main_screen[9 + i][25 + j] = ' ';

        }

    }

    show_main_screen();
}

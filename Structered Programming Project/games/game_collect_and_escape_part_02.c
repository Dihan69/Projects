#pragma once

#include "game_components/game_utility.c"

int play_collect_and_escape_part_02(void);

int CnEp2_moving_array(char arr[][100], int level);

void CnEp2_generate_element(char arr[][100], int time_spent);

void CnEp2_brick_generation(char arr[][100], int row_num);

void CnEp2_generate_board(char arr[][100]);

int CnEp2_move_board(char arr[][100], int board_pos);

void CnEp2_printarray(char arr[][100]);

    int CnEp2_game_difficulty=0;

int play_collect_and_escape_part_02(void)
{
    initialize_main_screen();
    setGameViewport(22, 6, 100, 32);

    int bad;

    char arr[40][100];

    for(int i=0; i<39; i++)
    {
        for(int j=0; j<100; j++)
            arr[i][j]=32;
    }
    for(int j=0; j<100; j++)
        arr[39][j]='T';

    bad = CnEp2_moving_array(arr, 0);

    return bad;
}

void CnEp2_generate_element(char arr[][100], int time_spent)
{
    srand(time(0));

    CnEp2_brick_generation(arr, 10);

    if(time_spent==0)
        return;

    CnEp2_brick_generation(arr, 6);

    if(time_spent==1)
        return;

    CnEp2_brick_generation(arr, 2);

    if(time_spent==2)
        return;

    CnEp2_brick_generation(arr, 8);

    if(time_spent==3)
        return;

    CnEp2_brick_generation(arr, 4);
}

void CnEp2_brick_generation(char arr[][100], int row_num)
{
    int type=rand()%6;
    int column=rand()%10;
    int section=rand()%10;

    if(section==10 && column==10)
        column=column-1;

    if(type==0)
    {
        arr[row_num][section*10+column]=219;
        arr[row_num][section*10+column+1]=219;
        arr[row_num-1][section*10+column]=219;
        arr[row_num-1][section*10+column+1]=219;
    }
    else if(type==1)
    {
        arr[row_num][section*10+column]=219;
        arr[row_num][section*10+column+1]=219;
        arr[row_num-1][section*10+column]=219;
    }

    else if(type==2)
    {
        arr[row_num][section*10+column]=219;
        arr[row_num][section*10+column+1]=219;

        arr[row_num-1][section*10+column+1]=219;
    }
    else if(type==3)
    {
        arr[row_num][section*10+column]=219;
        arr[row_num][section*10+column+1]=219;
    }
    else if(type==4)
    {
        arr[row_num][section*10+column]=219;
    }
    else if(type==5)
    {
        arr[row_num][section*10+column+1]=219;
    }
}

int CnEp2_moving_array(char arr[][100], int level)
{
    main_screen[39][25] = 'P';
    main_screen[39][26] = 'r';
    main_screen[39][27] = 'o';
    main_screen[39][28] = 'g';
    main_screen[39][29] = 'r';
    main_screen[39][30] = 'e';
    main_screen[39][31] = 's';
    main_screen[39][32] = 's';
    main_screen[39][33] = ':';

    int board_pos=49;
    CnEp2_generate_element(arr, level );
    CnEp2_generate_board(arr);

    int good=0, bad=0;

    int num=10;

    int target;
    int gameloop=0;
    if(CnEp2_game_difficulty==0)
        target=1300;
    else target=2500;

    int speed=1;

    while(1)
    {
        board_pos= CnEp2_move_board(arr, board_pos);

        if(board_pos==-1)
            return -1;

        resetCursorPosition();
        CnEp2_printarray(arr);

        for(int k=0; k< (90*gameloop)/target; k++)
            main_screen[39][35 + k] = 219;
        for(int k=(90*gameloop)/target ; k<90; k++)
            main_screen[39][35 + k] = ' ';

        show_main_screen();
        delay(211111111);

        //checking if object was caught
        for(int j=0; j<99; j++)
        {
            if(speed>=1 && arr[37][j]==(char)219 && arr[38][j]!=32)
                bad++;

            if(speed>=2 && arr[36][j]==(char)219 && arr[38][j]!=32)
                bad++;

            if(speed>=3 && arr[35][j]==(char)219 && arr[38][j]!=32)
                bad++;
        }

        //moving rest of object below
        for(int s=0; s<speed; s++)
        {
            for(int i=37-s; i>0; i--)
            {
                for(int j=0; j<100; j++)
                {


                    arr[i][j]=arr[i-1][j];
                }

            }
        }

        //generating new object if all objects of upper secret block is moved below

        if(num<=0)
        {
            for(int i=0; i<=10; i++)
            {
                for(int j=0; j<100; j++)
                    arr[i][j]=32;
            }
            CnEp2_generate_element(arr,level);

            num=10;

        }
        else if(gameloop<=1100)
            num--;
        else if(gameloop<=1800)
            num-=2;
        else
            num-=3;

        //increasing object generation
        if(gameloop<=100)
            level=0;
        else  if(gameloop<=200)
            level=1;
        else  if(gameloop<=300)
            level=2;
        else  if(gameloop<=450)
            level=3;
        else  if(gameloop<=700)
            level=4;

        if(gameloop>1100)
            speed=2;
        else if(gameloop>1800)
            speed=3;


        if( gameloop>=target)
            return bad;

        gameloop++;

    }
}

void CnEp2_generate_board(char arr[][100])
{
    arr[38][49]=206;
    arr[38][48]=219;
    arr[38][50]=219;
    arr[38][47]=180;
    arr[38][51]=195;
    arr[38][46]='(';
    arr[38][52]=')';

}

int CnEp2_move_board(char arr[][100], int board_pos)
{

    if(GetAsyncKeyState(VK_LEFT) & 0X8000)
    {
        if( board_pos>=4)
        {
            for(int j=0; j<=98; j++)
                arr[38][j]=arr[38][j+1];

            arr[38][99]=32;

            board_pos--;
        }
    }

    else if(GetAsyncKeyState(VK_RIGHT) & 0X8000)
    {
        if( board_pos<=95)
        {
            for(int j=99; j>0; j--)
                arr[38][j]=arr[38][j-1];

            arr[38][0]=32;

            board_pos++;
        }
    }
    else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
    {
        int feedback = ingame_menu_screen();

        if(feedback == 1) return -1;
    }

    return board_pos;
}

void CnEp2_printarray(char arr[][100])
{
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<100; j++)
            main_screen[9 + i][25 + j] = arr[10 + i][j];
    }
}

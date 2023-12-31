#pragma once

#include "game_components/game_utility.c"
#include "game_swarm_survive.c"

int play_collect_and_escape_part_03(int bad);

int CnEp3_navigation(char level[][81], int level_letter);

void CnEp3_initialize_ordering(char level[][81], int no);
void CnEp3_initialize_ordering1(char level[][81]);
void CnEp3_initialize_ordering2(char level[][81]);
void CnEp3_initialize_ordering3(char level[][81]);
void CnEp3_initialize_ordering4(char level[][81]);

void CnEp3_printing_array(char level[][81]);

void CnEp3_collison_screen(void);

int play_collect_and_escape_part_03(int bad)
{
    //
    initialize_main_screen();
    setGameInstructionTab(23, 2, 81, 41);
    setGameInstructionTab(113, 5, 25, 3);

    main_screen[8][120] = 'N';
    main_screen[8][121] = 'e';
    main_screen[8][122] = 'x';
    main_screen[8][123] = 't';
    main_screen[8][125] = 't';
    main_screen[8][126] = 'a';
    main_screen[8][127] = 'r';
    main_screen[8][128] = 'g';
    main_screen[8][129] = 'e';
    main_screen[8][130] = 't';
    main_screen[8][131] = ':';
    //

    int result;

    char level[41][81];

    int no;

    if(bad==0)
        no=1;
    else if (bad<10)
        no=2;
    else if (bad<25)
        no=3;
    else if(bad>=25)
        no=4;


    while(1)
    {
        main_screen[8][133] = 'A';

        CnEp3_initialize_ordering(level, no);
        CnEp3_printing_array(level);


        result = CnEp3_navigation(level, no*5);
        system("cls");

        if(result == -1)
            return -1;

        else if(result == -2)
            return 0;

        else if(result == 1)
            return 1;
    }
}

void CnEp3_initialize_ordering(char level[][81], int no)
{
    for(int i=0; i<41; i++)
    {
        for(int j=0; j<81; j++)
            level[i][j]=32;
    }
    level[1][1]='x';

    level[0][0]=201;
    level[0][80]=187;
    level[40][0]=200;
    level[40][80]=188;

    for(int i=  1; i<40; i++)
        level[i][0]=186;
    for(int i=1; i<40; i++)
        level[i][80]=186;

    for(int i=1; i<80; i++)
        level[0][i]=205;
    for(int i=1; i<80; i++)
        level[40][i]=205;


    if(no==1)
        CnEp3_initialize_ordering1(level);
    else if(no==2)
        CnEp3_initialize_ordering2(level);
    else if(no==3)
        CnEp3_initialize_ordering3(level);
    else if(no==4)
        CnEp3_initialize_ordering4(level);



}

void CnEp3_initialize_ordering2(char level[][81])
{
    //done
    level[33][8]='A';
    level [3][2]='B';
    level[38][76]='C';
    level[4][6]='D';
    level[3][33]='E';
    level[5][73]='F';
    level[19][19]='G';
    level[29][49]='H';
    level[1][7]='I';
    level[4][3]='J';


}

void CnEp3_initialize_ordering1(char level[][81])
{
    //done
    level[10][21]='A';
    level[32][65]='B';
    level[21][43]='C';
    level[6][46]='D';
    level[34][6]='E';
}

void CnEp3_initialize_ordering3(char level[][81])
{
    //done
    level[14][10]='A';
    level[9][5]='B';
    level[13][8]='C';
    level[12][7]='D';
    level[13][3]='E';
    level[12][11]='F';
    level[30][8]='G';
    level[34][33]='H';
    level[4][36]='I';
    level[24][19]='J';
    level[2][35]='K';
    level[1][66]='L';
    level[39][77]='M';
    level[18][55]='N';
    level[10][8]='O';
}

void CnEp3_initialize_ordering4(char level[][81])
{
    level[6][6]='A';
    level[3][8]='B';
    level[4][1]='C';
    level[5][7]='D';
    level[2][43]='E';
    level[14][25]='F';
    level[27][6]='G';
    level[38][4]='H';
    level[13][2]='I';
    level[25][42]='J';
    level[4][64]='K';
    level[3][12]='L';
    level[6][17]='M';
    level[6][44]='N';
    level[8][37]='O';
    level[7][39]='P';
    level[30][14]='Q';
    level[28][69]='R';
    level[30][10]='S';
    level[27][54]='T';
}

void CnEp3_printing_array(char level[][81])
{
    for(int i=0; i<41; i++)
    {
        for(int j=0; j<81; j++)
            main_screen[4 + i][25 + j] = level[i][j];
    }

    show_main_screen();
}

int CnEp3_navigation(char level[][81], int level_letter)
{
    int current_pos_x, current_pos_y, prev_pos_x, prev_pos_y, num=0, first_step_done=0;

    current_pos_x =1;
    current_pos_y=1;

    system("pause>nul");
    //system("cls");
    resetCursorPosition();

    int swarm_result=1, swarm_played=0;


    while(1)
    {

        if((GetAsyncKeyState(VK_DOWN) & 0X8000) )
        {
            prev_pos_x=current_pos_x;
            prev_pos_y=current_pos_y;
            (current_pos_x)=(current_pos_x)+1;


            level[current_pos_x][current_pos_y]='v';

            first_step_done=1;
        }
        else if  ((GetAsyncKeyState(VK_RIGHT) & 0X8000) )
        {
            prev_pos_x=current_pos_x;
            prev_pos_y=current_pos_y;
            (current_pos_y)=(current_pos_y)+1;


            level[current_pos_x][current_pos_y]='>';

            first_step_done=1;
        }
          else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
    {
        int feedback = ingame_menu_screen();

        if(feedback == 1) return -1;
    }

        if(first_step_done)
            break;

    }

    CnEp3_printing_array(level);
    main_screen[8][133] = (char)(num+65);

    while(1)
    {

        system("pause>nul");
        //system("cls");
        resetCursorPosition();

        if((GetAsyncKeyState(VK_UP) & 0X8000) && current_pos_x!=1 && (level[current_pos_x-1][current_pos_y]== 32 || (level[current_pos_x-1][current_pos_y]== num+65  ) ))
        {
            //thee 2nd part of previous condition is to check if where next move will be is a free space or a letter that comes next. Below one is to increase letter condition if it is matched.

            if((level[current_pos_x-1][current_pos_y]== num+65  ))
                num++;

            if(level[current_pos_x][current_pos_y]=='>')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_x--;
                level[prev_pos_x][prev_pos_y]=217;
                level[current_pos_x][current_pos_y]='^';


            }
            else if (level[current_pos_x][current_pos_y]=='<')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_x--;
                level[prev_pos_x][prev_pos_y]=192;
                level[current_pos_x][current_pos_y]='^';
            }
            else if (level[current_pos_x][current_pos_y]=='^')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_x--;
                level[prev_pos_x][prev_pos_y]=179;
                level[current_pos_x][current_pos_y]='^';
            }

        }

        else if((GetAsyncKeyState(VK_DOWN) & 0X8000) && current_pos_x!=39 && (level[current_pos_x+1][current_pos_y]== 32 || (level[current_pos_x+1][current_pos_y]== num+65  ) ))
        {
            if((level[current_pos_x+1][current_pos_y]== num+65 ))
                num++;

            if(level[current_pos_x][current_pos_y]=='>')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_x++;
                level[prev_pos_x][prev_pos_y]=191;
                level[current_pos_x][current_pos_y]='v';


            }
            else if (level[current_pos_x][current_pos_y]=='<')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_x++;
                level[prev_pos_x][prev_pos_y]=218;
                level[current_pos_x][current_pos_y]='v';
            }
            else if (level[current_pos_x][current_pos_y]=='v')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_x++;
                level[prev_pos_x][prev_pos_y]=179;
                level[current_pos_x][current_pos_y]='v';
            }

        }
        else if((GetAsyncKeyState(VK_LEFT) & 0X8000) && current_pos_y!=1  && (level[current_pos_x][current_pos_y-1]== 32 || (level[current_pos_x][current_pos_y-1]== num+65  )  ))
        {
            if((level[current_pos_x][current_pos_y-1]== num+65  ))
                num++;

            if(level[current_pos_x][current_pos_y]=='<')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_y--;
                level[prev_pos_x][prev_pos_y]=196;
                level[current_pos_x][current_pos_y]='<';


            }
            else if (level[current_pos_x][current_pos_y]=='^')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_y--;
                level[prev_pos_x][prev_pos_y]=191;
                level[current_pos_x][current_pos_y]='<';
            }
            else if (level[current_pos_x][current_pos_y]=='v')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_y--;
                level[prev_pos_x][prev_pos_y]=217;
                level[current_pos_x][current_pos_y]='<';
            }

        }

        else if((GetAsyncKeyState(VK_RIGHT) & 0X8000) && current_pos_y!=79 && (level[current_pos_x][current_pos_y+1]== 32 || (level[current_pos_x][current_pos_y+1]== num+65  )  ))
        {
            if((level[current_pos_x][current_pos_y+1]== num+65  ))
                num++;

            if(level[current_pos_x][current_pos_y]=='>')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_y++;
                level[prev_pos_x][prev_pos_y]=196;
                level[current_pos_x][current_pos_y]='>';


            }
            else if (level[current_pos_x][current_pos_y]=='^')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_y++;
                level[prev_pos_x][prev_pos_y]=218;
                level[current_pos_x][current_pos_y]='>';
            }
            else if (level[current_pos_x][current_pos_y]=='v')
            {
                prev_pos_x=current_pos_x;
                prev_pos_y=current_pos_y;
                current_pos_y++;
                level[prev_pos_x][prev_pos_y]=192;
                level[current_pos_x][current_pos_y]='>';
            }

        }
        else if (GetAsyncKeyState(VK_SPACE) & 0X8000)
        {
            return 0;
        }
        else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
        {
            int feedback = ingame_menu_screen();

            if(feedback == 1) return -1;
        }

        if(num==level_letter)
        {
            return 1;
        }
        else if (num%5==4 && swarm_played==0)
        {
            system("cls");
            CnEp3_collison_screen();
            delay(555555555);
            resetCursorPosition();

            CnEp3_collison_screen();
            delay(555555555);
            resetCursorPosition();

            CnEp3_collison_screen();
            delay(555555555);
            resetCursorPosition();
            system("cls");

            swarm_result = play_swarm_survive();
            system("cls");

            if(swarm_result==-1)
                return -1;

            CnEp3_collison_screen();
            delay(555555555);
            resetCursorPosition();
            delay(555555555);

            initialize_main_screen();
            setGameInstructionTab(23, 2, 81, 41);
            setGameInstructionTab(113, 5, 25, 3);

            main_screen[8][120] = 'N';
            main_screen[8][121] = 'e';
            main_screen[8][122] = 'x';
            main_screen[8][123] = 't';
            main_screen[8][125] = 't';
            main_screen[8][126] = 'a';
            main_screen[8][127] = 'r';
            main_screen[8][128] = 'g';
            main_screen[8][129] = 'e';
            main_screen[8][130] = 't';
            main_screen[8][131] = ':';

            swarm_played=1;
        }
        else if(num%5!=4)
            swarm_played=0;


        if(swarm_result==0)
            return -2;

        main_screen[8][133] = (char)(num+65);
        CnEp3_printing_array(level);
    }
}

void CnEp3_collison_screen(void)
{
    int random;
    for(int i=0; i<48; i++)
    {
        for(int j=0; j<148; j++)
        {
            random=rand()%2;

            if(random==0)
                main_screen[1 + i][1 + j] = 219;
            else
                main_screen[1 + i][1 + j] = ' ';
        }
    }

    show_main_screen();
}


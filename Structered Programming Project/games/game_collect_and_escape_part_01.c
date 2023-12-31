#pragma once

#include "game_components/game_utility.c"

int play_collect_and_escape_part_01(void);

int CnEp1_navigation_entry(char arr[][100], int *player_x, int *player_y);

void CnEp1_generate_bullet(char arr[][100]);
int CnEp1_shoot_bullet(char arr[][100]);
void CnEp1_clear_bullet(char arr[][100]);

void CnEp1_game3_generate_enemy (char arr[][100], int game3_x[], int game3_y[], int game3_enemy);
int CnEp1_game3_navigate_enemy (char arr[][100], int game3_x[], int game3_y[], int game3_enemy);

void CnEp1_print_entry(char arr[][100]);

void CnEp1_collison_screen();

    int CnEp1_game_difficulty=0;

int play_collect_and_escape_part_01()
{
    initialize_main_screen();
    setGameViewport(23, 5, 100, 30);

    int door1_opened=0, door2_opened=0, door3_opened=0, overal_result=0;


        srand(time(0));

        char arr[30][100]=
        {

            "####################################################################################################",//0
            "##                                                                                               <##",//1
            "##                                                                                               <##",//2
            "##                                                                                               <##",//3
            "##>                         #######################################################>              ##",//4
            "##                         <#                                                     #              <##",//5
            "##>                         #                                                     #>              ##",//6
            "##                         <#                                                     #              <##",//7
            "##>                         #                                                     #>              ##",//8
            "##                         <#                                                     #               ##",//9
            "##>                         #                                                     ##################",//10
            "############        #########                                                                       ",//11
            ".                                                                                                   ",//12
            ".[]                                                                                                 ",//13
            ".                                                                                                   ",//14
            "############        #########                                                                       ",//15
            "##                          #                                                     ##################",//16
            "##                          #                                                     #               ##",//17
            "##                          #                                                     #               ##",//18
            "##                          #                                                     #               ##",//19
            "##                          #                                                     #               ##",//20
            "##                          #                                                     #               ##",//21
            "##                          #                                                     #               ##",//22
            "##                          #                                                     #               ##",//23
            "##                          #                                                     #               ##",//24
            "##                          #######################################################               ##",//25
            "##                                                                                                ##",//26
            "##                                                                                                ##",//27
            "##                                                                                                ##",//28
            "####################################################################################################",//29
        };
           //0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789

        int pos_x, pos_y;
        int *player_x= &pos_x, *player_y= &pos_y;

        *player_x=13;
        *player_y=1;



        if(!door1_opened)
        {
            arr[9][90]='K';
            arr[12][27]='|';
            arr[13][27]='|';
            arr[14][27]='|';
        }

        int questionX[5], questionY[5], key_num=rand()%5;

        if(!door2_opened)
        {
            arr[12][28]='|';
            arr[13][28]='|';
            arr[14][28]='|';


            questionX[0]=rand()%12;
            questionY[0]=rand()%13;

            questionX[0]=questionX[0]+17;
            questionY[0]= questionY[0]+2;

            //17 to 28 and //2 to 14

            arr[questionX[0]][questionY[0]]='?';

            questionX[1]=rand()%12;
            questionY[1]=rand()%13;

            questionX[1]=questionX[1]+17;
            questionY[1]=questionY[1]+15;
            //17 to 28 and 15 to 27

            arr[questionX[1]][questionY[1]]='?';

            questionX[2]=rand()%3;
            questionY[2]=rand()%28;

            questionX[2]=questionX[2]+26;
            questionY[2]= questionY[2]+28;

            //26 to 28 and 28 to 55

            arr[questionX[2]][questionY[2]]='?';


            questionX[3]=rand()%3;
            questionY[3]=rand()%27;

            questionX[3]=questionX[3]+26;
            questionY[3]= questionY[3]+56;

            //26 to 28 and 56 to 82

            arr[questionX[3]][questionY[3]]='?';

            //19 to 28 and 83 to 97

            questionX[4]=rand()%10;
            questionY[4]=rand()%15;

            questionX[4]= questionX[4]+19;
            questionY[4]= questionY[4]+83;

            arr[questionX[4]][questionY[4]]='?';







        }

        int start_game3=0;


        if(!door3_opened)
        {
            start_game3=1;

            arr[11][82]='|';
            arr[12][82]='|';
            arr[13][82]='|';
            arr[14][82]='|';
            arr[15][82]='|';
        }



        for(int i=0; i<30; i++)
        {
            for(int j=0; j<100; j++)
                if(arr[i][j]=='#')
                    arr[i][j]=219;
                else if(arr[i][j]=='.')
                    arr[i][j]=179;


        }






        int result=0;
        //result=1 when bullet failed, result=2 when bullet completed //result 3 when game3 complete //result 4 when overal game is complete

        int game3_enemy;

        if(CnEp1_game_difficulty==0)
            game3_enemy=7;
        else
        game3_enemy=15;

        int game3_x[game3_enemy], game3_y[game3_enemy], game3_loop=0, game3_key=0, game3_result=0;



        while(1)
        {

        //add delay here to change game speed
            delay(191111111);

            result= CnEp1_navigation_entry(arr, &pos_x, &pos_y);

        if(result==4)
            {
                overal_result=1;
                break;
        }

        if(result == -1)
            return -1;



            if(!door3_opened)
            {
                if( (*player_y >28 && *player_y <81) && (*player_x >4 && *player_x <25) && start_game3==1 )
                {
                    start_game3=2;

                    CnEp1_print_entry(arr);

                    resetCursorPosition();
                    delay(555555555);

                    arr[12][28]=179;

                    CnEp1_print_entry(arr);

                    resetCursorPosition();
                    delay(555555555);
                    arr[13][28]=179;
                    CnEp1_print_entry(arr);

                    resetCursorPosition();
                    delay(555555555);
                    arr[14][28]=179;

                }
            }

            if(result==1)
                break;

            if(!door1_opened && arr[9][90]!='K')
            {
                door1_opened=1;
                CnEp1_clear_bullet(arr);

                CnEp1_print_entry(arr);

                resetCursorPosition();
                delay(555555555);


                arr[12][27]=32;
                CnEp1_print_entry(arr);

                resetCursorPosition();
                delay(555555555);

                arr[13][27]=32;
                CnEp1_print_entry(arr);
                delay(555555555);

                resetCursorPosition();

                arr[14][27]=32;

                CnEp1_print_entry(arr);

                resetCursorPosition();


            }

            if(!door2_opened)
            {
                if((arr[questionX[key_num]][questionY[key_num]]) != '?')
                {

                    door2_opened=1;
                    CnEp1_clear_bullet(arr);

                    for(int i=0; i<5; i++)
                    {
                        if(i!=key_num)
                            arr[questionX[i]][questionY[i]]=32;
                    }

                    CnEp1_print_entry(arr);

                    resetCursorPosition();
                    delay(555555555);


                    arr[12][28]=32;
                    CnEp1_print_entry(arr);

                    resetCursorPosition();
                    delay(555555555);

                    arr[13][28]=32;
                    CnEp1_print_entry(arr);
                    delay(555555555);

                    resetCursorPosition();

                    arr[14][28]=32;

                    CnEp1_print_entry(arr);

                    resetCursorPosition();
                }
                else
                {
                    for(int i=0; i<5; i++)
                    {
                        if(arr[questionX[i]][questionY[i]]!='?')
                        {
                            result=1;
                            break;
                        }
                    }
                }

            }
            if(result==1)
                break;

            if(!door1_opened)
                result= CnEp1_shoot_bullet(arr);

            if(result==1)
                break;
            if(!door1_opened)
                CnEp1_generate_bullet(arr);



            if(start_game3==2)
            {
                CnEp1_game3_generate_enemy(arr,game3_x, game3_y,game3_enemy );
                start_game3=3;
            }

            if(start_game3==3)
            {
                //will return 0 normally, 1 if completed, 2 if collison happened
                game3_result= CnEp1_game3_navigate_enemy(arr,game3_x, game3_y,game3_enemy);

                if(game3_loop==300)
                {
                    game3_key=rand()%game3_enemy;
                    arr[game3_x[game3_key]][game3_y[game3_key]]='K';
                }
                if(game3_loop==350)
                {
                    for(int p=0; p<game3_enemy; p++)
                        arr[game3_x[p]][game3_y[p]]=223;

                    game3_loop=0;
                }
                else
                    game3_loop++;
            }

            //player himself went to hit the box through navigation
            if(result==3 || game3_result==2)
            {
                 for(int p=0; p<game3_enemy; p++)
                        arr[game3_x[p]][game3_y[p]]=178;

                        resetCursorPosition();
                        CnEp1_print_entry(arr);
                       delay(31111111);


                        for(int p=0; p<game3_enemy; p++)
                        arr[game3_x[p]][game3_y[p]]=177;

                        resetCursorPosition();
                        CnEp1_print_entry(arr);
                        delay(31111111);

                        for(int p=0; p<game3_enemy; p++)
                        arr[game3_x[p]][game3_y[p]]=176;

                        resetCursorPosition();
                        CnEp1_print_entry(arr);
                        delay(31111111);

                        for(int p=0; p<game3_enemy; p++)
                        arr[game3_x[p]][game3_y[p]]=223;

                        game3_loop=0;
                          resetCursorPosition();

                          result=0;
                          game3_result=0;
            }

    //collection detection
            if(game3_loop>300 && game3_loop<350 && arr[game3_x[game3_key]][game3_y[game3_key]]!='K' &&game3_result==0 )
                game3_result=1;

            if(game3_result==1)
            {
                  for(int p=0; p<game3_enemy; p++)
                        arr[game3_x[p]][game3_y[p]]=32;

                        arr[*player_x][*player_y]='[';
                        arr[*player_x][(*player_y)+1]=']';

                CnEp1_print_entry(arr);

                resetCursorPosition();
                delay(555555555);

                arr[11][82]=32;
                CnEp1_print_entry(arr);

                resetCursorPosition();
                delay(555555555);
                arr[12][82]=32;
                CnEp1_print_entry(arr);

                resetCursorPosition();
                delay(555555555);
                arr[13][82]=32;
                CnEp1_print_entry(arr);

                resetCursorPosition();
                delay(555555555);
                arr[14][82]=32;
                CnEp1_print_entry(arr);

                resetCursorPosition();
                delay(555555555);
                arr[15][82]=32;

                game3_result=5;
                start_game3=4;
            }

            CnEp1_print_entry(arr);

            resetCursorPosition();
            delay(31111111);
            //need to dodge bullets and collect key, collecting this key will stop the bullets so the way back is safe and also one door
        }

        //result is 1 if collison happened
        if(result==1)
        {
            resetCursorPosition();
            CnEp1_collison_screen();
        }

        system("cls");

     if(overal_result==1)
            return 1;
    else return 0;


}

void CnEp1_game3_generate_enemy (char arr[][100], int game3_x[], int game3_y[], int game3_enemy)
{
    int random_x, random_y;

    for(int i=0; i<game3_enemy; i++)
    {
        while(1)
        {
            random_x= rand()%20;
            random_y =rand()%52;
            if(arr[random_x+5][random_y+29]==32)
            {
                arr[random_x+5][random_y+29]=223;
                game3_x[i]=random_x+5;
                game3_y[i]=random_y+29;
                break;
            }
        }
    }
}

int CnEp1_game3_navigate_enemy (char arr[][100], int game3_x[], int game3_y[], int game3_enemy)
{
    int direction, result=0;

    //direction equal to 0 for up, 1 for down, 2 for left, 3 for right
    //4 for up-left, 5 for up-right, 6 for down-left, 7 for down-right

    for(int i=0; i<game3_enemy; i++)
    {
        direction=rand()%8;

        if(direction==0)
        {
            if(arr[game3_x[i]-1][game3_y[i]]==32)
            {
                arr[game3_x[i]-1][game3_y[i]]=arr[game3_x[i]][game3_y[i]];
                arr[game3_x[i]][game3_y[i]]=32;

                game3_x[i]=game3_x[i]-1;
            }
            else if(arr[game3_x[i]-1][game3_y[i]]=='[' || arr[game3_x[i]-1][game3_y[i]]==']' )
            {
                if (arr[game3_x[i]][game3_y[i]]=='K')
                    return 1;
                else
                result=2;
            }
        }

        else if(direction==1)
        {
            if(arr[game3_x[i]+1][game3_y[i]]==32)
            {
                arr[game3_x[i]+1][game3_y[i]]=arr[game3_x[i]][game3_y[i]];
                arr[game3_x[i]][game3_y[i]]=32;

                game3_x[i]=game3_x[i]+1;
            }
            else if(arr[game3_x[i]+1][game3_y[i]]=='[' || arr[game3_x[i]+1][game3_y[i]]==']' )
            {
                if (arr[game3_x[i]][game3_y[i]]=='K')
                    return 1;
                else
                result=2;
            }
        }

        else if(direction==2)
        {
            if(arr[game3_x[i]][game3_y[i]-1]==32)
            {
                arr[game3_x[i]][game3_y[i]-1]= arr[game3_x[i]][game3_y[i]];
                arr[game3_x[i]][game3_y[i]]=32;

                game3_y[i]=game3_y[i]-1;
            }
            else if(arr[game3_x[i]][game3_y[i]-1]=='[' || arr[game3_x[i]][game3_y[i]-1]==']' )
            {
                if (arr[game3_x[i]][game3_y[i]]=='K')
                    return 1;
                else
                result=2;
            }
        }

        else if(direction==3)
        {
            if(arr[game3_x[i]][game3_y[i]+1]==32)
            {
                arr[game3_x[i]][game3_y[i]+1]=  arr[game3_x[i]][game3_y[i]];
                arr[game3_x[i]][game3_y[i]]=32;

                game3_y[i]=game3_y[i]+1;

            }
            else if(arr[game3_x[i]][game3_y[i]+1]=='[' || arr[game3_x[i]][game3_y[i]+1]==']' )
            {
                if (arr[game3_x[i]][game3_y[i]]=='K')
                    return 1;
                else
                result=2;
            }
        }

        else  if(direction==4)
        {
            if(arr[game3_x[i]-1][game3_y[i]-1]==32)
            {
                arr[game3_x[i]-1][game3_y[i]-1]= arr[game3_x[i]][game3_y[i]];
                arr[game3_x[i]][game3_y[i]]=32;

                game3_x[i]=game3_x[i]-1;
                game3_y[i]=game3_y[i]-1;
            }
            else if(arr[game3_x[i]-1][game3_y[i]-1]=='[' || arr[game3_x[i]-1][game3_y[i]-1]==']' )
            {
                if (arr[game3_x[i]][game3_y[i]]=='K')
                    return 1;
                else
                result=2;
            }
        }

        else  if(direction==5)
        {
            if(arr[game3_x[i]-1][game3_y[i]+1]==32)
            {
                arr[game3_x[i]-1][game3_y[i]+1]=arr[game3_x[i]][game3_y[i]];
                arr[game3_x[i]][game3_y[i]]=32;

                game3_x[i]=game3_x[i]-1;
                game3_y[i]=game3_y[i]+1;
            }
            else if(arr[game3_x[i]-1][game3_y[i]+1]=='[' || arr[game3_x[i]-1][game3_y[i]+1]==']' )
            {
                if (arr[game3_x[i]][game3_y[i]]=='K')
                    return 1;
                else
                result=2;
            }
        }

        else  if(direction==6)
        {
            if(arr[game3_x[i]+1][game3_y[i]-1]==32)
            {
                arr[game3_x[i]+1][game3_y[i]-1]= arr[game3_x[i]][game3_y[i]];
                arr[game3_x[i]][game3_y[i]]=32;

                game3_x[i]=game3_x[i]+1;
                game3_y[i]=game3_y[i]-1;
            }
            else if(arr[game3_x[i]+1][game3_y[i]-1]=='[' || arr[game3_x[i]+1][game3_y[i]-1]==']' )
            {
                if (arr[game3_x[i]][game3_y[i]]=='K')
                    return 1;
                else
                result=2;
            }
        }

        else  if(direction==7)
        {
            if(arr[game3_x[i]+1][game3_y[i]+1]==32)
            {
                arr[game3_x[i]+1][game3_y[i]+1]=arr[game3_x[i]][game3_y[i]];
                arr[game3_x[i]][game3_y[i]]=32;

                game3_x[i]=game3_x[i]+1;
                game3_y[i]=game3_y[i]+1;
            }
        }
        else if(arr[game3_x[i]+1][game3_y[i]+1]=='[' || arr[game3_x[i]+1][game3_y[i]+1]==']' )
            {
                if (arr[game3_x[i]][game3_y[i]]=='K')
                    return 1;
                else
                result=2;
            }
    }

    return result;
}

int CnEp1_navigation_entry(char arr[][100], int *player_x, int *player_y)
{
    int pos_x= *player_x, pos_y= *player_y;

    if((GetAsyncKeyState(VK_RIGHT) & 0X8000) && pos_y<99 )
    {
        if(pos_y==98)
            return 4;

        if(arr[pos_x][pos_y+2]=='-')
            return 1;
        else   if(arr[pos_x][pos_y+2]==(char)223)
            return 3;

        if(arr[pos_x][pos_y+2]==32 || arr[pos_x][pos_y+2]=='K' || arr[pos_x][pos_y+2]=='?'    )
        {
            arr[pos_x][pos_y]=32;
            arr[pos_x][pos_y+1]='[';
            arr[pos_x][pos_y+2]=']';

            pos_y++;
        }
    }
    else if((GetAsyncKeyState(VK_LEFT) & 0X8000) && pos_y>0 )
    {
        if(arr[pos_x][pos_y-1]=='-')
            return 1;
            else if(arr[pos_x][pos_y-1]==(char)(223))
            return 3;

        if(arr[pos_x][pos_y-1]==32 || arr[pos_x][pos_y-1]=='K' || arr[pos_x][pos_y-1]=='?'  )
        {
            arr[pos_x][pos_y+1]=32;
            arr[pos_x][pos_y-1]='[';
            arr[pos_x][pos_y]=']';

            pos_y--;

        }
    }

    else if((GetAsyncKeyState(VK_UP) & 0X8000) )
    {

        if(arr[pos_x-1][pos_y]=='-' || arr[pos_x-1][pos_y+1]=='-')
            return 1;
            else  if(arr[pos_x-1][pos_y]==(char)223 || arr[pos_x-1][pos_y+1]== (char)223)
            return 3;

        if((arr[pos_x-1][pos_y]==32 && arr[pos_x-1][pos_y+1]==32) || (arr[pos_x-1][pos_y]=='K' || arr[pos_x-1][pos_y+1]=='K') || (arr[pos_x-1][pos_y]=='?' || arr[pos_x-1][pos_y+1]=='?') )
        {
            arr[pos_x-1][pos_y]='[';
            arr[pos_x-1][pos_y+1]=']';

            arr[pos_x][pos_y]=32;
            arr[pos_x][pos_y+1]=32;

            pos_x--;
        }
    }

    else if((GetAsyncKeyState(VK_DOWN) & 0X8000) )
    {
        if(arr[pos_x+1][pos_y]=='-' || arr[pos_x+1][pos_y+1]=='-')
            return 1;
            else if(arr[pos_x+1][pos_y]==(char)223 || arr[pos_x+1][pos_y+1]==(char)223)
            return 3;

        if((arr[pos_x+1][pos_y]==32 && arr[pos_x+1][pos_y+1]==32) ||  arr[pos_x+1][pos_y]=='K' || arr[pos_x+1][pos_y+1]=='K' ||  arr[pos_x+1][pos_y]=='?' || arr[pos_x+1][pos_y+1]=='?' )
        {
            arr[pos_x+1][pos_y]='[';
            arr[pos_x+1][pos_y+1]=']';

            arr[pos_x][pos_y]=32;
            arr[pos_x][pos_y+1]=32;

            pos_x++;
        }
    }
      else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
    {
        int feedback = ingame_menu_screen();

        if(feedback == 1) return -1;
    }

    *player_x= pos_x;
    *player_y= pos_y;

    return 0;
}

void CnEp1_generate_bullet(char arr[][100])
{
    int shoot;

    int chance;

    if(CnEp1_game_difficulty ==0)
        chance=30;
    else
        chance=18;

    shoot=rand()%chance;

    if(shoot==0)
        arr[1][96]='-';

    shoot=rand()%chance;

    if(shoot==0)
        arr[2][96]='-';

    shoot=rand()%chance;

    if(shoot==0)
        arr[3][96]='-';

    shoot=rand()%(chance+10);

    if(shoot==0)
        arr[4][3]='-';

    shoot=rand()%(chance-5);

    if(shoot==0)
        arr[4][84]='-';

    shoot=rand()%(chance+10);

    if(shoot==0)
        arr[5][26]='-';

    shoot=rand()%(chance-5);

    if(shoot==0)
        arr[5][96]='-';

    shoot=rand()%(chance+10);

    if(shoot==0)
        arr[6][3]='-';

    shoot=rand()%(chance-5);

    if(shoot==0)
        arr[6][84]='-';


    shoot=rand()%(chance+10);

    if(shoot==0)
        arr[7][26]='-';

    shoot=rand()%(chance-5);

    if(shoot==0)
        arr[7][96]='-';

    shoot=rand()%(chance+10);

    if(shoot==0)
        arr[8][3]='-';

    shoot=rand()%(chance-5);

    if(shoot==0)
        arr[8][84]='-';

    shoot=rand()%(chance+10);

    if(shoot==0)
        arr[9][26]='-';

    shoot=rand()%(chance+10);

    if(shoot==0)
        arr[10][3]='-';
}

int CnEp1_shoot_bullet(char arr[][100])
{
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<96; j++)
            if(arr[i][j+1]=='-')
            {
                if(arr[i][j]=='[' || arr[i][j]==']')
                    return 1;

                arr[i][j]=arr[i][j+1];
                arr[i][j+1]=32;
            }

        arr[i][1]=219;

        if(arr[i][96]=='-')
            arr[i][96]=32;
    }

    for(int i=4; i<=10; i+=2)
    {
        for(int j=28; j>2; j--)

            if(arr[i][j-1]=='-')
            {
                if(arr[i][j]=='[' || arr[i][j]==']')
                    return 1;

                arr[i][j]=arr[i][j-1];
                arr[i][j-1]=32;
            }

        if(arr[i][3]=='-')
            arr[i][3]=22;

        arr[i][28]=219;
    }

    for(int i=4; i<=8; i+=2)
    {
        for(int j=98; j>84; j--)
            if(arr[i][j-1]=='-')
            {
                if(arr[i][j]=='[' || arr[i][j]==']')
                    return 1;

                arr[i][j]=arr[i][j-1];
                arr[i][j-1]=32;
            }


        if(arr[i][84]=='-')
            arr[i][84]=22;

        arr[i][98]=219;
    }

    for(int i=5; i<=9; i+=2)
    {
        for(int j=1; j<26; j++)
            if(arr[i][j+1]=='-')
            {
                if(arr[i][j]=='[' || arr[i][j]==']')
                    return 1;

                arr[i][j]=arr[i][j+1];
                arr[i][j+1]=32;
            }

        if(arr[i][26]=='-')
            arr[i][26]=22;

        arr[i][1]=219;
    }

    for(int i=5; i<=7; i+=2)
    {
        for(int j=82; j<96; j++)
            if(arr[i][j+1]=='-')
            {
                if(arr[i][j]=='[' || arr[i][j]==']')
                    return 1;

                arr[i][j]=arr[i][j+1];
                arr[i][j+1]=32;
            }

        if(arr[i][96]=='-')
            arr[i][96]=22;

        arr[i][82]=219;
    }

    return 0;
}

void CnEp1_clear_bullet(char arr[][100])
{
    for(int i=1; i<=3; i++)
    {
        for(int j=2; j<=96; j++)
            arr[i][j]=32;
    }

    for(int i=4; i<=10; i+=2)
    {
        for(int j=27; j>2; j--)
            arr[i][j]=32;
    }

    for(int i=4; i<=8; i+=2)
    {
        for(int j=97; j>=84; j--)
            arr[i][j]=32;
    }

    for(int i=5; i<=9; i+=2)
    {
        for(int j=2; j<=26; j++)
            arr[i][j]=32;
    }

    for(int i=5; i<=7; i+=2)
    {
        for(int j=83; j<=96; j++)
            arr[i][j]=32;
    }
}

void CnEp1_print_entry(char arr[][100])
{
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            main_screen[8 + i][26 + j] = arr[i][j];
        }
    }

    show_main_screen();
}

void CnEp1_collison_screen()
{
    srand(time(0));

    int random;

    for(int i=0; i<30; i++)
    {
        for(int j=0; j<100; j++)
        {
            random=rand()%2;

            if(random==0)
                main_screen[8 + i][26 + j] = 219;
            else
                main_screen[8 + i][26 + j] = ' ';

        }
    }

    show_main_screen();
}

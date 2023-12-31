#pragma once

#include "game_components/game_utility.c"

int play_mixmatch(void);

void mixmatch_create_symbol (char arr[][24]);
void mixmatch_print_symbol(char arr[][24], int targetX, int targetY);

int mixmatch_row_navigation(char arr[][24], int targetX, int targetY);
void mixmatch_selecting_row(int row_num, char arr[][24]);
int mixmatch_moving_row(int row_num, char arr[][24], int targetX, int targetY);
void mixmatch_removing_row_selection(int row_num, char arr[][24]);

int mixmatch_collum_navigation(char arr[][24], int targetX, int targetY);
void mixmatch_selecting_collum(int collum_num, char arr[][24]);
int mixmatch_moving_collum(int collum_num, char arr[][24], int targetX, int targetY);
void mixmatch_removing_collum_selection(int collum_num, char arr[][24]);

int mixmatch_checking_match(int collum_num, char arr[][24], int targetX, int targetY );

int mixmatch_game_difficulty = 0;
int mixmatch_moveleft;
int mixmatch_attempt = 0;


int play_mixmatch(void)
{
    mixmatch_attempt = 0;

    initialize_main_screen();

    setGameAccessoryTab(37, 9, 32, 26);
    setGameInstructionTab(83, 16, 27, 6);

    char arr[24][24];

    srand(time(0));

    int target;

    if(mixmatch_game_difficulty==0)
        target=3;
    else
        target=5;

    while(1)
    {
        if(mixmatch_game_difficulty==0)
            mixmatch_moveleft= 95-mixmatch_attempt*15;
        else
            mixmatch_moveleft=80-mixmatch_attempt*10;

        mixmatch_create_symbol(arr);

        int step=0, next=1, side=1, result=0;

        int targetX, targetY;

        targetX= 2*(rand()%10)+3;
        targetY= 2*(rand()%10)+3;

        while(1)
        {
            if(next)
                step = mixmatch_row_navigation(arr, targetX, targetY);
            else
                step=0;


            if(step == 69)
            {
                result=0;
                break;
            }
            else if(step==-1)
                return -1;

            if(step==0)
                side= 0;
            else
                side=1;
            //side is used to see if row is going to move or collum, 1 for row, 0 for collum

            if(step==0)
                step= mixmatch_collum_navigation(arr, targetX, targetY);

            if(step==69)
            {
                result=0;
                break;
            }
            else if(step==-1)
                return -1;


            if(step!=0)
            {
                if(side==1)
                {

                    mixmatch_selecting_row(step, arr);
                    result=mixmatch_moving_row(step, arr, targetX, targetY);
                    next=1;

                    if(step==69)
                    {
                        result=0;
                        break;
                    }

                    if(result==-1)
                        return -1;

                }

                else if(side==0)
                {
                    mixmatch_selecting_collum(step, arr);
                    result=mixmatch_moving_collum(step, arr, targetX, targetY);
                    next=0;

                    if(step==69)
                    {
                        result=0;
                        break;
                    }

                    if(result==-1)
                        return -1;
                }


            }
            else next=1;

            if(result)
                break;
        }

        if(result)
            mixmatch_attempt++;
        else
            return 0;//return fail

        system("cls");

        if(mixmatch_attempt==target)
            return 1; //return success
    }
}

void mixmatch_create_symbol (char arr[][24])
{
    int random;

    srand(time(0));

    for(int i=0; i<24; i++)
    {
        for(int j=0; j<24; j++)
            arr[i][j]=32;
    }

    arr[1][1]=201;
    arr[1][23]=187;
    arr[23][1]=200;
    arr[23][23]=188;

    arr[3][0]='>';

    for(int i=2; i<23; i++)
        arr[i][1]=186;

    for(int i=2; i<23; i++)
        arr[i][23]=186;

    for(int j=2; j<23; j++)
        arr[1][j]=205;

    for(int j=2; j<23; j++)
        arr[23][j]=205;

    for(int i=3; i<23; i+=2)
    {
        for(int j=3; j<23; j+=2)
        {
            random= rand()%5;

            if(random==0)
                arr[i][j]= 157;
            else if(random==1)
                arr[i][j]=254;
            else if(random==2)
                arr[i][j]= 240;
            else if(random==3)
                arr[i][j]=79;
            else if(random==4)
                arr[i][j]=146;
        }
    }
}

void mixmatch_print_symbol(char arr[][24], int targetX, int targetY)
{
    for(int k = 0; k < 9; k++)
    {
        main_screen[12][48 + 2 * k] = '1' + k;
    }

    main_screen[12][66] = '1';
    main_screen[12][67] = '0';

    for(int k = 0; k < 9; k++)
    {
        main_screen[16 + 2 * k][40] = '[';
        main_screen[16 + 2 * k][41] = '0';
        main_screen[16 + 2 * k][42] = '1' + k;
        main_screen[16 + 2 * k][43] = ']';
    }

    main_screen[34][40] = '[';
    main_screen[34][41] = '1';
    main_screen[34][42] = '0';
    main_screen[34][43] = ']';

    for(int i=0; i<24; i++)
    {
        for(int j=0; j<24; j++)
        {
            main_screen[13 + i][45 + j] = arr[i][j];
        }
    }

    int target;

    if(mixmatch_game_difficulty==0)
        target=3;
    else
        target=5;

    char status[4][26];

    sprintf(status[0], "Target row           : %.2d", (targetX-3)/2+1);
    sprintf(status[1], "Target column        : %.2d", (targetY-3)/2+1);
    sprintf(status[2], "Move remaining       : %.2d", mixmatch_moveleft);
    sprintf(status[3], "Phase left to unlock : %.2d", target- mixmatch_attempt);

    for(int k = 0; k < 4; k++)
    {
        for(int l = 0; l < strlen(status[k]); l++)
        {
            main_screen[19 + k][86 + l] = status[k][l];
        }
    }

    show_main_screen();
}

int mixmatch_row_navigation(char arr[][24], int targetX, int targetY)
{


    int position=3, result=0, final=0;

    for(int i=3; i<=21; i+=2)
    {
        if(arr[i][0]== '>')
        {
            position=i;

            result=1;
            break;
        }
    }

    if(result==0)
        arr[position][0]='>';


    system("cls");

    while(1)
    {
        mixmatch_print_symbol(arr, targetX, targetY);

        system("pause>nul");

        if((GetAsyncKeyState(VK_UP) & 0X8000) )
        {
            if(position!=3)
            {
                position-=2;
                arr[position][0]= '>';
                arr[position+2][0]=32;
                mixmatch_moveleft--;
            }

            else
            {
                position=21;
                arr[position][0]='>';
                arr[3][0]=32;
                mixmatch_moveleft--;
            }

        }
        else if ((GetAsyncKeyState(VK_DOWN) & 0X8000)  )
        {
            if(position!=21)
            {
                position+=2;
                arr[position][0]= '>';
                arr[position-2][0]=32;
                mixmatch_moveleft--;
            }
            else
            {
                position=3;
                arr[position][0]='>';
                arr[21][0]=32;
                mixmatch_moveleft--;
            }

        }

        else if(GetAsyncKeyState(VK_RETURN) & 0X8000 )
        {
            // arr[position][0]=32;
            final=position;
            break;
        }
        else if(GetAsyncKeyState(VK_SPACE) & 0X8000 )
        {
            arr[position][0]=32;
            final=0;
            break;

        }
        else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
        {
            int feedback = ingame_menu_screen();

            if(feedback == 1) return -1;
        }





        if(mixmatch_moveleft==0)
            return 69;

        resetCursorPosition();
        //delay(199999999);


    }

    return final;
}



int mixmatch_collum_navigation(char arr[][24], int targetX, int targetY)
{
    int position=3,result=0, final;


    for(int i=3; i<=21; i+=2)
    {
        if(arr[0][i]== 'v')
        {
            position=i;
            result==1;
            break;
        }
    }

    if(result==0)
        arr[0][position]='v';

    system("cls");

    while(1)
    {
        mixmatch_print_symbol(arr, targetX, targetY);

        system("pause>nul");

        if((GetAsyncKeyState(VK_LEFT) & 0X8000) )
        {
            if(position!=3)
            {
                position-=2;
                arr[0][position]= 'v';
                arr[0][position+2]=32;
                mixmatch_moveleft--;
            }

            else
            {
                position=21;
                arr[0][position]='v';
                arr[0][3]=32;
                mixmatch_moveleft--;
            }

        }
        else if ((GetAsyncKeyState(VK_RIGHT) & 0X8000)  )
        {
            if(position!=21)
            {
                position+=2;
                arr[0][position]= 'v';
                arr[0][position-2]=32;
                mixmatch_moveleft--;
            }
            else
            {
                position=3;
                arr[0][position]='v';
                arr[0][21]=32;
                mixmatch_moveleft--;
            }

        }

        else if(GetAsyncKeyState(VK_RETURN) & 0X8000 )
        {
            //arr[0][position]=32;
            final=position;
            break;
        }
        else if(GetAsyncKeyState(VK_SPACE) & 0X8000 )
        {
            arr[0][position]=32;
            final=0;
            break;
        }
        else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
        {
            int feedback = ingame_menu_screen();

            if(feedback == 1) return -1;
        }


        if(mixmatch_moveleft==0)
            return 69;



        resetCursorPosition();
        //delay(199999999);


    }

    return final;
}

void mixmatch_selecting_row(int row_num, char arr[][24])
{
    arr[row_num-1][2]=218;
    arr[row_num][2]=179;
    arr[row_num+1][2]=192;

    arr[row_num-1][22]=191;
    arr[row_num][22]=179;
    arr[row_num+1][22]=217;

    for(int i=3; i<22; i++)
        arr[row_num-1][i]=196;

    for(int i=3; i<22; i++)
        arr[row_num+1][i]=196;

}

void mixmatch_removing_row_selection(int row_num, char arr[][24])
{

    arr[row_num-1][2]=32;
    arr[row_num][2]=32;
    arr[row_num+1][2]=32;

    arr[row_num-1][22]=32;
    arr[row_num][22]=32;
    arr[row_num+1][22]=32;

    for(int i=3; i<22; i++)
        arr[row_num-1][i]=32;

    for(int i=3; i<22; i++)
        arr[row_num+1][i]=32;

}

int mixmatch_moving_row(int row_num, char arr[][24], int targetX, int targetY)
{
    char temp;

    int result;


    while(1)
    {
        system("cls");
        mixmatch_print_symbol(arr, targetX, targetY);
        system("pause>nul");

        if((GetAsyncKeyState(VK_LEFT) & 0X8000) )
        {
            temp = arr[row_num][3];

            for(int i=3; i<21; i+=2)
            {
                arr[row_num][i] = arr[row_num][i+2];
            }

            arr[row_num][21] = temp;
        }
        else if ((GetAsyncKeyState(VK_RIGHT) & 0X8000)  )
        {

            temp= arr[row_num][21];

            for(int i=21; i>=5; i-=2)

                arr[row_num][i]=arr[row_num][i-2];


            arr[row_num][3]=temp;
        }


        else if (GetAsyncKeyState(VK_RETURN) & 0X8000 )
        {
            mixmatch_removing_row_selection(row_num, arr);
            if(mixmatch_checking_match(row_num,arr, targetX, targetY))
                result=1;
            else
                result=0;
            break;


        }
        else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
        {
            int feedback = ingame_menu_screen();

            if(feedback == 1) return -1;
        }


    }

    return result;

}



void mixmatch_selecting_collum(int collum_num, char arr[][24])
{
    arr[2][collum_num-1]=218;
    arr[2][collum_num]=196;
    arr[2][collum_num+1]=191;

    arr[22][collum_num-1]=192;
    arr[22][collum_num]=196;
    arr[22][collum_num+1]=217;

    for(int i=3; i<22; i++)
        arr[i][collum_num-1]=179;

    for(int i=3; i<22; i++)
        arr[i][collum_num+1]=179;

}

int mixmatch_moving_collum(int collum_num, char arr[][24], int targetX, int targetY)
{
    char temp;

    int result;

    while(1)
    {
        system("cls");
        mixmatch_print_symbol(arr, targetX, targetY);


        system("pause>nul");

        if((GetAsyncKeyState(VK_UP) & 0X8000) )
        {
            temp= arr[3][collum_num];

            for(int i=3; i<21; i+=2)

                arr[i][collum_num]=arr[i+2][collum_num];


            arr[21][collum_num]=temp;


        }
        else if ((GetAsyncKeyState(VK_DOWN) & 0X8000)  )
        {

            temp= arr[21][collum_num];

            for(int i=21; i>=5; i-=2)

                arr[i][collum_num]=arr[i-2][collum_num];


            arr[3][collum_num]=temp;
        }


        else if (GetAsyncKeyState(VK_RETURN) & 0X8000 )
        {
            mixmatch_removing_collum_selection(collum_num, arr);
            if(mixmatch_checking_match(1,arr, targetX, targetY))
                result=1;
            else
                result=0;

            break;


        }
        else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
        {
            int feedback = ingame_menu_screen();

            if(feedback == 1) return -1;
        }


    }

    return result;
}

void mixmatch_removing_collum_selection(int collum_num, char arr[][24])
{
    arr[2][collum_num-1]=32;
    arr[2][collum_num]=32;
    arr[2][collum_num+1]=32;

    arr[22][collum_num-1]=32;
    arr[22][collum_num]=32;
    arr[22][collum_num+1]=32;

    for(int i=3; i<22; i++)
        arr[i][collum_num-1]=32;

    for(int i=3; i<22; i++)
        arr[i][collum_num+1]=32;
}

int mixmatch_checking_match(int collum_num, char arr[][24], int targetX, int targetY )
{
    int result=1;

    for(int i=3; i<21; i+=2)
    {
        if(arr[targetX][i]!= arr[targetX][i+2])
        {
            result=0;
            break;
        }
    }

    for(int i=3; i<21; i+=2)
    {
        if(arr[i][targetY]!= arr[i+2][targetY])
        {
            result=0;
            break;
        }
    }

    return result;
}

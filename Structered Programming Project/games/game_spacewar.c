#pragma once

#include "game_components/game_utility.c"

typedef struct
{
    int x, y;
} spacewar_Player;

int play_spacewar(void);

int spacewar_main_function(void);

void spacewar_generate_player_position(char arr[][120], int x, int y);
int spacewar_move_player(char arr[][120]);
void spacewar_clear_previous_player_position(char arr[][120],int x, int y);

void spacewar_destroy_player(char arr[][120], int x, int y);

void spacewar_generate_player_bullet(char arr[][120], int level);
void spacewar_move_player_bullet(char arr[][120]);

void spacewar_generate_enemy1(char arr[][150], int x, int y);
void spacewar_generate_enemy2(char arr[][150], int x, int y);
void spacewar_generate_enemy3(char arr[][150], int x, int y);

void spacewar_move_enemy(char arr[][150]);
void spacewar_move_enemy2(char arr[][150]);

void spacewar_generate_enemy_bullet1(char enemy_bullet[][120], char enemy[][150]);
void spacewar_generate_enemy_bullet2(char enemy_bullet[][120], char enemy[][150]);
void spacewar_generate_enemy_bullet3(char enemy_bullet[][120], char enemy[][150]);

void spacewar_move_enemy_bullet(char arr[][120], int level);

void spacewar_wave1(char enemy[][150]);
void spacewar_wave2(char enemy[][150]);
void spacewar_wave3(char enemy[][150]);
void spacewar_wave4(char enemy[][150]);
void spacewar_wave5(char enemy[][150]);
void spacewar_wave6(char enemy[][150]);
void spacewar_wave7(char enemy[][150]);
void spacewar_wave8(char enemy[][150]);
void spacewar_wave9(char enemy[][150]);
void spacewar_wave10(char enemy[][150]);

int spacewar_collision_detection3(char overal[][120], char player[][120], char player_bullet[][120], char enemy[][150], char enemy_bullet[][120]);
int spacewar_collision_detection2(char overal[][120], char player[][120], char player_bullet[][120], char enemy[][150], char enemy_bullet[][120]);
int spacewar_collision_detection1(char overal[][120], char player[][120], char player_bullet[][120], char enemy[][150], char enemy_bullet[][120]);

void spacewar_print_normally(char overal[][120], int stop_bullet);

    spacewar_Player spacewar_player;

    int spacewar_bullet_charge = 100;
    int spacewar_enemy3_pos = 8;
    int spacewar_enemy3_move_direction = 0;
    int spacewar_enemy3_core_destroyed = 0;

    int spacewar_game_difficulty = 1;

int play_spacewar(void)
{

    initialize_main_screen();
    setGameViewport(12, 3, 120, 38);

    for(int i = 1; i < 119; i++)
    {
        main_screen[41][15 + i] = 196;
        main_screen[43][15 + i] = 196;
    }

    main_screen[42][18] = 'C';
    main_screen[42][19] = 'h';
    main_screen[42][20] = 'a';
    main_screen[42][21] = 'r';
    main_screen[42][22] = 'g';
    main_screen[42][23] = 'e';
    main_screen[42][25] = 'l';
    main_screen[42][26] = 'e';
    main_screen[42][27] = 'f';
    main_screen[42][28] = 't';
    main_screen[42][29] = ':';


    int result= spacewar_main_function();

    return result;
}

int spacewar_main_function(void)
{
    char player[35][120];
    char player_bullet[35][120];
    char enemy[35][150];
    char enemy_bullet[35][120];
    char overal[35][120];

    spacewar_bullet_charge=100;
    spacewar_enemy3_pos=8;
    spacewar_enemy3_move_direction=0;
    spacewar_enemy3_core_destroyed=0;

    //srand(time(0));

    long long int gameloop=-30;
    int stop_bullet=0;
    int pause=0;
    int result=1;
    int level=0;

    spacewar_player.x=15;
    spacewar_player.y=2;

    for(int i=0; i<35; i++)
    {
        for(int j=0; j<120; j++)
            player[i][j]=32;
    }
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<120; j++)
            player_bullet[i][j]=32;
    }
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<150; j++)
            enemy[i][j]=32;
    }
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<120; j++)
            enemy_bullet[i][j]=32;
    }
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<120; j++)
            overal[i][j]=32;
    }


    spacewar_generate_player_position(player, spacewar_player.x, spacewar_player.y );

    while(1)
    {
        int result= spacewar_move_player(player);
        if(result==-1)
            return -1;

        if(!stop_bullet)
            spacewar_generate_player_bullet(player_bullet,level);


        if(spacewar_bullet_charge==0)
            stop_bullet=1;

        if(stop_bullet==1 && spacewar_bullet_charge==0)
            pause++;

        if( pause==15 && stop_bullet==1 &&spacewar_bullet_charge<=95)
            spacewar_bullet_charge+=5;

        if(stop_bullet==1 && spacewar_bullet_charge==100)
        {
            stop_bullet=0;
            pause=0;
        }

        spacewar_move_player_bullet(player_bullet);

        if(gameloop<750)
            level=0;
        else if(gameloop<1400)
            level=1;
        else level=2;

         if(spacewar_game_difficulty==0)
         {
         if(gameloop==0)
             spacewar_wave1(enemy);
         else if(gameloop==150)
             spacewar_wave2(enemy);
         else if(gameloop==300)
             spacewar_wave3(enemy);
         else if(gameloop==450)
             spacewar_wave4(enemy);
             else if(gameloop==600)
             spacewar_wave5(enemy);

         else if(gameloop==750)
             spacewar_wave7(enemy);
             else if(gameloop==900)
                spacewar_wave7(enemy);
             else if(gameloop==1050)
                spacewar_wave8(enemy);
             else if(gameloop==1200)
                spacewar_wave8(enemy);
             else if(gameloop==1400)
                spacewar_wave10(enemy);

         }
         else if (spacewar_game_difficulty==1)
         {
         if(gameloop==0)
             spacewar_wave3(enemy);
         else if(gameloop==150)
             spacewar_wave4(enemy);
         else if(gameloop==300)
             spacewar_wave5(enemy);
         else if(gameloop==450)
             spacewar_wave6(enemy);
             else if(gameloop==600)
             spacewar_wave6(enemy);

             else if(gameloop==750)
             spacewar_wave8(enemy);
             else if(gameloop==900)
                spacewar_wave8(enemy);
             else if(gameloop==1050)
                spacewar_wave9(enemy);
             else if(gameloop==1200)
                spacewar_wave9(enemy);
             else if(gameloop==1400)
                spacewar_wave10(enemy);

         }



        if(gameloop<=1400+40)
            spacewar_move_enemy(enemy);
        else if(gameloop%100 >60 )
            spacewar_move_enemy2(enemy);

         if(gameloop<750)
             spacewar_generate_enemy_bullet1(enemy_bullet,enemy);
         else if(gameloop<1350)
         spacewar_generate_enemy_bullet2(enemy_bullet, enemy);

        else
        spacewar_generate_enemy_bullet3(enemy_bullet, enemy);

        spacewar_move_enemy_bullet(enemy_bullet, level);

        if(gameloop<750)
        result= spacewar_collision_detection1(overal, player, player_bullet, enemy, enemy_bullet);
         else if(gameloop<1400)
        result= spacewar_collision_detection2(overal, player, player_bullet, enemy, enemy_bullet);
          else
        result= spacewar_collision_detection3(overal, player, player_bullet, enemy, enemy_bullet);


        if(spacewar_enemy3_core_destroyed==5)
        {
            for(int k=0; k<5; k++)
            {for(int x=spacewar_enemy3_pos;x<spacewar_enemy3_pos+19;x++)
            {
                for(int y=88; y<105; y++)
                { int random=rand()%3;
                    overal[x][y]=176+random;
                    enemy[x][y]=32;
                }
            }
            delay(55555555);
                    resetCursorPosition();
              spacewar_print_normally(overal, stop_bullet);
        }

        delay(55555555);
                    resetCursorPosition();
              spacewar_print_normally(overal, stop_bullet);

              return 1;


        }


        resetCursorPosition();


          if(!result)
            {


                for(int k=0; k<5; k++)

                {
                    delay(55555555);
                    resetCursorPosition();
                    spacewar_destroy_player(overal, spacewar_player.x, spacewar_player.y);
                    spacewar_print_normally(overal, stop_bullet);
                }

                return 0;
            }

        spacewar_print_normally(overal, stop_bullet);



        gameloop++;
    }
}

int spacewar_collision_detection1(char overal[][120], char player[][120], char player_bullet[][120], char enemy[][150], char enemy_bullet[][120])
{
    int result =1;

    for(int i=0; i<35; i++)
    {
        for(int j=0; j<120; j++)
        {



            if((enemy[i][j]=='<' || enemy[i][j]=='=' ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  ) )
            {
                //destroying outer wing of plane
                overal[i][j]=177;
                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }
            else if (enemy[i][j]=='{' &&   (enemy[i-1][j+1]=='=' || enemy[i+1][j+1]=='='  ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  )  )
            {

        overal[i][j]='{';
                player_bullet[i][j]=32;

                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }
            else if( (enemy[i][j]=='{' && enemy[i][j-1]!='<' && enemy[i-1][j+1]!='=' && enemy[i+1][j+1]!='=' ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  )  )
            {
                //detroying frontal wing of enemy
                overal[i][j]=177;
                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }

            else  if(spacewar_game_difficulty==0 && enemy_bullet[i][j]=='o' && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' || player_bullet[i][j-4]=='*'   ))
            {
                //bullets destroying each other

                overal[i][j]=32;
                enemy_bullet[i][j]=32;
                player_bullet[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
                player_bullet[i][j-4]=32;

            }
            else  if(spacewar_game_difficulty==1 && enemy_bullet[i][j]=='o' && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' || player_bullet[i][j-4]=='*'  || player_bullet[i][j-5]=='*' || player_bullet[i][j-6]=='*'   ))
            {
                //bullets destroying each other

                overal[i][j]=32;
                enemy_bullet[i][j]=32;
                player_bullet[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
                player_bullet[i][j-4]=32;
                player_bullet[i][j-5]=32;
                player_bullet[i][j-6]=32;
            }

            else if( (enemy[i][j]=='C' && enemy[i][j-1]!='{') && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  ))
            {
                //destroying the whole enemy
                overal[i][j]=177;
                overal[i][j+1]=177;
                player_bullet[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
                enemy[i][j]=32;
                enemy[i][j+1]=32;
            }
            else if((player[i][j]!=32 || player[i][j-1]!=32) && (enemy[i][j]!=32))
                result=0;
            else if(spacewar_game_difficulty==0 && (  player[i][j]!=32|| player[i][j-1]!=32 || player[i][j-2]!=32) && enemy_bullet[i][j]!=32)
                result=0;
            else if(spacewar_game_difficulty==1 && (  player[i][j]!=32|| player[i][j-1]!=32 || player[i][j-2]!=32 || player[i][j-3]!=32 || player[i][j-4]!=32 ) && enemy_bullet[i][j]!=32)
                result=0;


            else  if(enemy[i][j]!=32)
                overal[i][j]= enemy[i][j];
            else   if(enemy_bullet[i][j]!=32)
                overal[i][j]= enemy_bullet[i][j];
            else if(player[i][j]!=32)
                overal[i][j]= player[i][j];
            else if(player_bullet[i][j]!=32)
                overal[i][j]= player_bullet[i][j];
            else
                overal[i][j]= player[i][j];


        }
    }

    return result;


}

int spacewar_collision_detection2(char overal[][120], char player[][120], char player_bullet[][120], char enemy[][150], char enemy_bullet[][120])
{
    int result =1, x,y, destroyed=0;

    for(int i=0; i<35; i++)
    {
        for(int j=0; j<120; j++)
        {


            if((enemy[i][j]=='=' && enemy[i][j-1]==32 ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  ) )
            {
                overal[i][j]=177;
                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }
            else if( (enemy[i][j]=='/' && enemy [i-2][j+3]!='=' && enemy[i-3][j+2]!='=' && enemy[i][j+1]=='=') && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  ) )
            {
                overal[i][j]=177;
                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }


            else if( (enemy[i][j]=='\\' && enemy [i+2][j+3]!='=' && enemy[i+3][j+2]!='=' && enemy[i][j+1]=='=' ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  ) )
            {
                overal[i][j]=177;
                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }
            else if((enemy[i][j]==':' && enemy[i][j-1]!='=' && enemy[i][j+1]=='[') && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ))
            {
                if(enemy[i-1][j-1]!='='&&  enemy[i+1][j-1] !='=' )
                {

                    overal[i][j]=177;
                    if(enemy[i-1][j]==':')
                    {
                        overal[i-1][j]=177;
                        enemy[i-1][j]=32;
                    }
                    else
                    {
                        overal[i+1][j]=177;
                        enemy[i+1][j]=32;
                    }

                    player_bullet[i][j]=32;
                    enemy[i][j]=32;
                    player_bullet[i][j-1]=32;
                    player_bullet[i][j-2]=32;
                    player_bullet[i][j-3]=32;
                }
                else
                {
                    overal[i][j]=':';
                    player_bullet[i][j]=32;
                    enemy[i][j]=':';
                    player_bullet[i][j-1]=32;
                    player_bullet[i][j-2]=32;
                    player_bullet[i][j-3]=32;
                }
            }

            else if((enemy[i][j]=='[' && enemy[i][j-1]!=':' ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ))
            {


                overal[i][j]=177;
                if(enemy[i-1][j]=='[')
                {
                    overal[i-1][j]=177;
                    enemy[i-1][j]=32;
                }
                else
                {
                    overal[i+1][j]=177;
                    enemy[i+1][j]=32;
                }

                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;

            }
            else if((enemy[i][j]=='C' && enemy[i][j-1]!='[') && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ))
            {
                x=i;
                y=j;
                destroyed=1;

            }
            else  if(spacewar_game_difficulty==0 && enemy_bullet[i][j]=='o' && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' || player_bullet[i][j-4]=='*'   ))
            {
                //bullets destroying each other

                overal[i][j]=32;
                enemy_bullet[i][j]=32;
                player_bullet[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
                player_bullet[i][j-4]=32;

            }
            else  if(spacewar_game_difficulty==1 && enemy_bullet[i][j]=='o' && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' || player_bullet[i][j-4]=='*'  || player_bullet[i][j-5]=='*' || player_bullet[i][j-6]=='*'   ))
            {
                //bullets destroying each other


                overal[i][j]=32;
                enemy_bullet[i][j]=32;
                player_bullet[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
                player_bullet[i][j-4]=32;
                player_bullet[i][j-5]=32;
                player_bullet[i][j-6]=32;
            }

            else if(enemy[i][j]!=32 && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ) )

            {
                //destroy bullet that hits undestroyable part
                overal[i][j]=enemy[i][j];
                player_bullet[i][j]=32;

                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }

            else if((player[i][j]!=32 || player[i][j-1]!=32) && (enemy[i][j]!=32))
                result=0;
            else if(spacewar_game_difficulty==0 && (  player[i][j]!=32|| player[i][j-1]!=32 || player[i][j-2]!=32) && enemy_bullet[i][j]!=32)
                result=0;
            else if(spacewar_game_difficulty==1 && (  player[i][j]!=32|| player[i][j-1]!=32 || player[i][j-2]!=32 || player[i][j-3]!=32 || player[i][j-4]!=32 ) && enemy_bullet[i][j]!=32)
                result=0;

            else  if(enemy[i][j]!=32 )
                overal[i][j]= enemy[i][j];

            else   if(enemy_bullet[i][j]!=32)
                overal[i][j]= enemy_bullet[i][j];
            else if(player[i][j]!=32)
                overal[i][j]= player[i][j];
            else if(player_bullet[i][j]!=32)
                overal[i][j]= player_bullet[i][j];
            else
                overal[i][j]= player[i][j];
        }

    }

    if(destroyed)
    {
        for(int i=x-6; i<=x+6; i++)
        {
            for(int j=y-4; j<=y+10; j++)

            {
                overal[i][j]=177;
                enemy[i][j]=32;
            }
        }
    }

    return result;


}

int spacewar_collision_detection3(char overal[][120], char player[][120], char player_bullet[][120], char enemy[][150], char enemy_bullet[][120])
{
    int result =1, x,y, destroyed=0;

    for(int i=0; i<35; i++)
    {
        for(int j=0; j<120; j++)
        {


            if((enemy[i][j]=='='  ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  ) )


            {
                overal[i][j]=177;
                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;

            }
            else if ((enemy[i][j]=='<' && enemy[i-2][j+1]==32 && enemy[i+2][j+1]!='=' )   && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  ))

            {
                overal[i][j]=177;
                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;

            }
            else if ((enemy[i][j]=='<' && enemy[i+2][j+1]==32 && enemy[i+2][j+1]!='='  )   && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*'  ))

            {
                overal[i][j]=177;
                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;

            }
                 else if((enemy[i][j]=='[' && enemy[i][j-1]!='<' ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ))
            {


                overal[i][j]=177;


                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;

            }
                 else if((enemy[i][j]=='(' && enemy[i][j-1]!='[' ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ))
            {


                overal[i][j]=177;


                    overal[i+1][j]=177;
                    enemy[i+1][j]=32;

                    overal[i-1][j]=177;
                    enemy[i-1][j]=32;



                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;

            }
            else if ((enemy[i][j]=='C' && enemy[i][j-1]==32 ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ))
            {


                overal[i][j]=177;





                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;

                spacewar_enemy3_core_destroyed++;

            }
            else if(spacewar_enemy3_core_destroyed==4 && enemy[i][j]=='{'  && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ) )


            {

                overal[i][j]=177;





                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }
            else if ((enemy[i][j]==':' && enemy[i][j-1]==32 ) && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ))
            {


                overal[i][j]=177;





                player_bullet[i][j]=32;
                enemy[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;



            }

                else  if(spacewar_game_difficulty==0 && enemy_bullet[i][j]=='o' && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' || player_bullet[i][j-4]=='*' || player_bullet[i][j-2]=='*'  ))
            {
                //bullets destroying each other

                overal[i][j]=32;
                enemy_bullet[i][j]=32;
                player_bullet[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
                player_bullet[i][j-4]=32;

            }
            else  if(spacewar_game_difficulty==1 && enemy_bullet[i][j]=='o' && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' || player_bullet[i][j-4]=='*'  || player_bullet[i][j-5]=='*' || player_bullet[i][j-6]=='*' || player_bullet[i][j-7]=='*'   ))
            {
                //bullets destroying each other


                overal[i][j]=32;
                enemy_bullet[i][j]=32;
                player_bullet[i][j]=32;
                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
                player_bullet[i][j-4]=32;
                player_bullet[i][j-5]=32;
                player_bullet[i][j-6]=32;
            }







            else if(enemy[i][j]!=32 && ( player_bullet[i][j]=='*'|| player_bullet[i][j-1]=='*' || player_bullet[i][j-2]=='*' || player_bullet[i][j-3]=='*' ) )

            {
                //destroy bullet that hits undestroyable part
                overal[i][j]=enemy[i][j];
                player_bullet[i][j]=32;

                player_bullet[i][j-1]=32;
                player_bullet[i][j-2]=32;
                player_bullet[i][j-3]=32;
            }

            else if(spacewar_game_difficulty==0 && (  player[i][j]!=32|| player[i][j-1]!=32 || player[i][j-2]!=32 || player[i][j-3]!=32 || player[i][j-4]!=32 ) && enemy_bullet[i][j]!=32)
                result=0;
            else if(spacewar_game_difficulty==1 && (  player[i][j]!=32|| player[i][j-1]!=32 || player[i][j-2]!=32 || player[i][j-3]!=32 || player[i][j-4]!=32 || player[i][j-5]!=32 || player[i][j-6]!=32 ) && enemy_bullet[i][j]!=32)
                result=0;

            else  if(enemy[i][j]!=32 )
                overal[i][j]= enemy[i][j];

            else   if(enemy_bullet[i][j]!=32)
                overal[i][j]= enemy_bullet[i][j];
            else if(player[i][j]!=32)
                overal[i][j]= player[i][j];
            else if(player_bullet[i][j]!=32)
                overal[i][j]= player_bullet[i][j];
            else
                overal[i][j]= player[i][j];
        }

    }


    return result;

}

int spacewar_move_player(char arr[][120])
{
    if((GetAsyncKeyState(VK_UP) & 0x8000) && spacewar_player.x>0)
    {
        spacewar_clear_previous_player_position(arr, spacewar_player.x, spacewar_player.y);
        (spacewar_player.x)--;
        spacewar_generate_player_position(arr, spacewar_player.x, spacewar_player.y);

    }
    else    if((GetAsyncKeyState(VK_DOWN) & 0x8000) && spacewar_player.x<30)
    {
        spacewar_clear_previous_player_position(arr, spacewar_player.x, spacewar_player.y);
        (spacewar_player.x)++;
        spacewar_generate_player_position(arr, spacewar_player.x, spacewar_player.y);

    }
    else    if((GetAsyncKeyState(VK_LEFT) & 0x8000) && spacewar_player.y>1)
    {
        spacewar_clear_previous_player_position(arr, spacewar_player.x, spacewar_player.y);
        (spacewar_player.y)--;
        spacewar_generate_player_position(arr, spacewar_player.x, spacewar_player.y);

    }
    else    if((GetAsyncKeyState(VK_RIGHT) & 0x8000) && spacewar_player.y<70)
    {
        spacewar_clear_previous_player_position(arr, spacewar_player.x, spacewar_player.y);
        (spacewar_player.y)++;
        spacewar_generate_player_position(arr, spacewar_player.x, spacewar_player.y);

    }
       else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
    {
        int feedback = ingame_menu_screen();

        if(feedback == 1) return -1;
    }

    return 0;

}

void spacewar_generate_player_bullet(char arr[][120], int level)
{
    int decrease;

    if(level==0)
        decrease=10;
    else if(level==1)
        decrease=6;
    else if(level==2)
        decrease=4;
    if(GetAsyncKeyState(VK_SPACE) & 0x8000 && spacewar_bullet_charge!=0)
    {
        arr[(spacewar_player.x)+1][(spacewar_player.y)+6]='*';
        arr[(spacewar_player.x)+3][(spacewar_player.y)+6]='*';
        if(spacewar_bullet_charge>decrease)
            spacewar_bullet_charge-=decrease;
        else spacewar_bullet_charge=0;
    }
    else if((GetAsyncKeyState(0x46) & 0x8000) &&spacewar_bullet_charge!=0)
    {
        arr[(spacewar_player.x)+2][(spacewar_player.y)+6]='*';
        if(spacewar_bullet_charge>(decrease-2))
            spacewar_bullet_charge-=(decrease-2);
        else
            spacewar_bullet_charge=0;

    }
    else if(spacewar_bullet_charge<=99)
        spacewar_bullet_charge+=3;

    if(spacewar_bullet_charge>100)
        spacewar_bullet_charge=100;
}

void spacewar_move_player_bullet(char arr[][120])
{
    for(int k=0; k<3; k++)
    {
        for(int i=0; i<35; i++)
        {
            for(int j=119; j>0; j--)
            {
                arr[i][j]=arr[i][j-1];
                //arr[i][j-1]=32;
            }
            arr[i][0]=32;
        }
    }
}

void spacewar_generate_enemy1 (char arr[][150], int x, int y)
{
    arr[x][y]='<';
    arr[x][y+1]='{';
    arr[x][y+2]='C';
    arr[x-1][y+2]='=';
    arr[x+1][y+2]='=';
    arr[x][y+3]=')';
}

void spacewar_generate_enemy3(char arr[][150], int x, int y)
{


    arr[x][y + 6] = '_';
    arr[x][y + 7] = '-';
    arr[x][y + 8] = '"';
    arr[x][y + 9] = '\\';


    arr[x + 1][y + 5] = '/';
    arr[x + 1][y + 8] = '"';
    arr[x + 1][y + 9] = ':';


    arr[x + 2][y + 3] = '=';
    arr[x + 2][y + 4] = ':';
    arr[x + 2][y + 5] = '|';
    arr[x + 2][y + 6] = ':';
    arr[x + 2][y + 9] = '[';


    arr[x + 3][y + 4] = '/';
    arr[x + 3][y + 5] = ':';
    arr[x + 3][y + 8] = '\\';
    arr[x + 3][y + 9] = '\\';


    arr[x + 4][y + 2] = '<';
    arr[x + 4][y + 3] = '[';
    arr[x + 4][y + 4] = '(';
    arr[x + 4][y + 5] = 'C';
    arr[x + 4][y + 6] = '>';
    arr[x + 4][y + 9] = '"';
    arr[x + 4][y + 10] = '\\';
    arr[x + 4][y + 11] = '_';


    arr[x + 5][y + 3] = '/';
    arr[x + 5][y + 5] = '/';
    arr[x + 5][y + 7] = '/';
    arr[x + 5][y + 8] = '\\';
    arr[x + 5][y + 9] = ':';
    arr[x + 5][y + 10] = '\\';
    arr[x + 5][y + 11] = '_';
    arr[x + 5][y + 12] = '\\';
    arr[x + 5][y + 13] = '_';


    arr[x + 6][y + 1] = '<';
    arr[x + 6][y + 2] = '[';
    arr[x + 6][y + 3] = '(';
    arr[x + 6][y + 4] = 'C';
    arr[x + 6][y + 5] = '>';
    arr[x + 6][y + 6] = '_';
    arr[x + 6][y + 7] = '\\';
    arr[x + 6][y + 8] = ':';
    arr[x + 6][y + 9] = '\\';
    arr[x + 6][y + 10] = '/';
    arr[x + 6][y + 11] = '_';
    arr[x + 6][y + 12] = '_';
    arr[x + 6][y + 13] = 'E';


    arr[x + 7][y + 2] = '.';
    arr[x + 7][y + 3] = '\\';
    arr[x + 7][y + 5] = '_';
    arr[x + 7][y + 6] = '_';
    arr[x + 7][y + 7] = '_';
    arr[x + 7][y + 9] = '.';
    arr[x + 7][y + 10] = '/';


    arr[x + 8][y + 1] = '/';
    arr[x + 8][y + 2] = '_';
    arr[x + 8][y + 3] = '/';
    arr[x + 8][y + 4] = '_';
    arr[x + 8][y + 5] = '_';
    arr[x + 8][y + 8] = '\\';
    arr[x + 8][y + 9] = '\\';


    arr[x + 9][y] = '{';
    arr[x + 9][y + 1] = ':';
    arr[x + 9][y + 2] = '(';
    arr[x + 9][y + 3] = 'C';
    arr[x + 9][y + 5] = ']';
    arr[x + 9][y + 7] = ')';
    arr[x + 9][y + 9] = '[';


    arr[x + 10][y + 1] = '\\';
    arr[x + 10][y + 2] = '"';
    arr[x + 10][y + 3] = '\\';
    arr[x + 10][y + 4] = '"';
    arr[x + 10][y + 5] = '"';
    arr[x + 10][y + 8] = '/';
    arr[x + 10][y + 9] = '/';


    arr[x + 11][y + 2] = '\'';
    arr[x + 11][y + 3] = '/';
    arr[x + 11][y + 5] = '"';
    arr[x + 11][y + 6] = '"';
    arr[x + 11][y + 7] = '"';
    arr[x + 11][y + 9] = '\'';
    arr[x + 11][y + 10] = '\\';
    arr[x + 11][y + 11] = '_';
    arr[x + 11][y + 12] = '_';


    arr[x + 12][y + 1] = '<';
    arr[x + 12][y + 2] = '[';
    arr[x + 12][y + 3] = '(';
    arr[x + 12][y + 4] = 'C';
    arr[x + 12][y + 5] = '>';
    arr[x + 12][y + 6] = '"';
    arr[x + 12][y + 7] = '/';
    arr[x + 12][y + 8] = ':';
    arr[x + 12][y + 9] = '/';
    arr[x + 12][y + 10] = '\\';
    arr[x + 12][y + 11] = '_';
    arr[x + 12][y + 13] = 'E';


    arr[x + 13][y + 3] = '\\';
    arr[x + 13][y + 5] = '\\';
    arr[x + 13][y + 7] = '\\';
    arr[x + 13][y + 8] = '/';
    arr[x + 13][y + 9] = ':';
    arr[x + 13][y + 10] = '/';
    arr[x + 13][y + 11] = '_';
    arr[x + 13][y + 12] = '/';
    arr[x + 13][y + 13] = '"';


    arr[x + 14][y + 2] = '<';
    arr[x + 14][y + 3] = '[';
    arr[x + 14][y + 4] = '(';
    arr[x + 14][y + 5] = 'C';
    arr[x + 14][y + 6] = '>';
    arr[x + 14][y + 9] = '_';
    arr[x + 14][y + 10] = '/';


    arr[x + 15][y + 4] = '\\';
    arr[x + 15][y + 5] = ':';
    arr[x + 15][y + 8] = '/';
    arr[x + 15][y + 9] = '/';


    arr[x + 16][y + 3] = '=';
    arr[x + 16][y + 4] = ':';
    arr[x + 16][y + 5] = '|';
    arr[x + 16][y + 6] = ':';
    arr[x + 16][y + 9] = '[';


    arr[x + 17][y + 5] = '\\';
    arr[x + 17][y + 8] = '_';
    arr[x + 17][y + 9] = ':';


    arr[x + 18][y + 6] = '"';
    arr[x + 18][y + 7] = '-';
    arr[x + 18][y + 8] = '_';
    arr[x + 18][y + 9] = '/';
}

void spacewar_move_enemy(char arr[][150])
{
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<149; j++)
        {

            arr[i][j]=arr[i][j+1];

            arr[i][149]=32;
        }

    }

}

void spacewar_move_enemy2(char arr[][150])
{


    if(spacewar_enemy3_move_direction==0)
    {
        for(int i=0; i<35; i++)
        {
            for(int j=0; j<149; j++)
            {

                arr[i][j]=arr[i+1][j];

                arr[34][j]=32;
            }

        }
        spacewar_enemy3_pos--;

        if(spacewar_enemy3_pos==1)
            spacewar_enemy3_move_direction=1;
    }
    else if(spacewar_enemy3_move_direction==1 && spacewar_enemy3_pos<16)
    {
        for(int i=34; i>0; i--)
        {
            for(int j=0; j<149; j++)
            {

                arr[i][j]=arr[i-1][j];

                arr[0][j]=32;
            }

        }
        spacewar_enemy3_pos++;
        if(spacewar_enemy3_pos==15)
            spacewar_enemy3_move_direction=0;
    }

}

void spacewar_generate_enemy_bullet1(char enemy_bullet[][120], char enemy[][150])
{
    int chance;

    if(spacewar_game_difficulty==0)
        chance=30;
    else chance=18;

    for(int i=1; i<34; i++)
    {
        for(int j=0; j<120; j++)
        {
            if(enemy[i][j]=='<')
            {
                int shoot=rand()%chance;
                if(shoot==1)
                    enemy_bullet[i][j-1]='o';
            }
            else if(enemy[i][j]=='=')
            {
                int shoot=rand()%(chance*3);
                if(shoot==1)
                    enemy_bullet[i][j-1]='o';
            }
        }
    }
}

void spacewar_generate_enemy_bullet2(char enemy_bullet[][120], char enemy[][150])
{
    int chance;

    if(spacewar_game_difficulty==0)
        chance=120;
    else chance=75;

    for(int i=1; i<34; i++)
    {
        for(int j=40; j<120; j++)
        {
            if(enemy[i][j]=='=')
            {
                int shoot=rand()%chance;
                if(shoot==0)
                    enemy_bullet[i][j-2]='o';
            }
        }
    }

}

void spacewar_generate_enemy_bullet3(char enemy_bullet[][120], char enemy[][150])
{
    int chance;


    for(int i=1; i<34; i++)
    {
        for(int j=0; j<110; j++)
        {
            if(enemy[i][j]=='=')
            {
                if(spacewar_game_difficulty==0)
                    chance=20;
                else
                    chance=13;
                int shoot=rand()%chance;
                if(shoot==0)
                    enemy_bullet[i][j-2]='o';
            }
            else  if(enemy[i][j]=='<')
            {
                if(spacewar_game_difficulty==0)
                    chance=25;
                else
                    chance=16;
                int shoot=rand()%chance;
                if(shoot==0)
                    enemy_bullet[i][j-2]='o';

            }
            else  if(enemy[i][j]=='{')
            {
                if(spacewar_game_difficulty==0)
                    chance=7;
                else
                    chance=4;
                int shoot=rand()%chance;
                if(shoot==0)
                {
                    enemy_bullet[i][j-2]='o';


                }
            }
        }
    }
}

void spacewar_move_enemy_bullet(char arr[][120], int level)
{
    int speed;

    if(level==2)

    {if(spacewar_game_difficulty==0)
        speed=3;
    else
        speed=5;
    }
    else
         {if(spacewar_game_difficulty==0)
        speed=2;
    else
        speed=4;
    }
    for(int k=0; k<speed; k++)

    {
        for(int i=0; i<35; i++)
        {
            for(int j=0; j<119; j++)
            {

                arr[i][j]=arr[i][j+1];

                arr[i][119]=32;
            }

        }
    }

}

void spacewar_print_normally(char overal[][120], int stop_bullet)
{
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<120; j++)
        {
            main_screen[6 + i][15 + j] = overal[i][j];
        }
    }

    for(int i=0; i<spacewar_bullet_charge; i++)
        if(!stop_bullet)
            main_screen[42][32 + i] = 219;
        else
            main_screen[42][32 + i] = 176;

    for(int i=spacewar_bullet_charge; i<100; i++)
        main_screen[42][32 + i] = ' ';

    show_main_screen();
    delay(411111111);
}

void spacewar_generate_enemy2(char arr[][150], int x, int y)
{
    arr[x][y]='/';
    arr[x+1][y]='\\';
    arr[x][y+1]= '=';
    arr[x+1][y+1]='=';
    arr[x][y+2]=':';
    arr[x+1][y+2]=':';
    arr[x][y+3]='[';
    arr[x+1][y+3]='[';
    arr[x-1][y+3]='_';
    arr[x-2][y+3]='=';
    arr[x-3][y+3]=':';
    arr[x-3][y+2]='=';
    arr[x+2][y+3]='"';
    arr[x+3][y+3]='=';
    arr[x+4][y+3]=':';
    arr[x+4][y+2]='=';
    arr[x+2][y+4]='\\';
    arr[x+3][y+4]='(';
    arr[x+4][y+4]='|';
    arr[x+5][y+4]='\\';
    arr[x-1][y+4]='/';
    arr[x-2][y+4]='(';
    arr[x-3][y+4]='|';
    arr[x-4][y+4]='/';

    arr[x][y+5]='C';
    arr[x+1][y+5]='C';
    arr[x-1][y+5]='/';
    arr[x-2][y+5]='G';
    arr[x-3][y+5]=':';
    arr[x-5][y+5]='-';
    arr[x+2][y+5]='\\';
    arr[x+3][y+5]='G';
    arr[x+4][y+5]=':';
    arr[x+6][y+5]='"';
    arr[x+2][y+6]='"';
    arr[x+6][y+6]='.';
    arr[x-1][y+6]='_';
    arr[x-5][y+6]='-';

    arr[x][y+7]='C';
    arr[x+1][y+7]='C';
    arr[x+3][y+7]='|';
    arr[x+5][y+7]='_';
    arr[x+6][y+7]='_';
    arr[x-2][y+7]='|';
    arr[x-4][y+7]='"';
    arr[x-5][y+7]='"';

    arr[x][y+8]=']';
    arr[x+1][y+8]=']';
    arr[x+3][y+8]=':';
    arr[x+4][y+8]='|';
    arr[x+5][y+8]=':';
    arr[x+6][y+8]='/';
    arr[x-2][y+8]=':';
    arr[x-3][y+8]='|';
    arr[x-4][y+8]=':';
    arr[x-5][y+8]='\\';

    arr[x][y+9]=')';
    arr[x+1][y+9]=')';
    arr[x+2][y+9]='_';
    arr[x-1][y+9]='"';

    arr[x-1][y+10]='_';
    arr[x-1][y+11]='"';
    arr[x+2][y+10]='"';
    arr[x+2][y+11]='_';

    arr[x-1][y+12]='_';
    arr[x-2][y+12]=':';
    arr[x-3][y+12]='/';
    arr[x+2][y+12]='"';
    arr[x+3][y+12]=':';
    arr[x+4][y+12]='\\';

    arr[x][y+13]='|';
    arr[x+1][y+13]='|';
    arr[x+3][y+13]='|';
    arr[x+4][y+13]='_';
    arr[x-2][y+13]='|';
    arr[x-3][y+13]='"';

    arr[x][y+14]='|';
    arr[x+1][y+14]='|';
    arr[x+2][y+14]=':';
    arr[x+3][y+14]='|';
    arr[x+5][y+14]='"';
    arr[x-1][y+14]=':';
    arr[x-2][y+14]='|';
    arr[x-4][y+14]='_';

    arr[x-3][y+15]=']';
    arr[x+4][y+15]=']';


}

void spacewar_wave1(char enemy[][150])
{
    spacewar_generate_enemy1(enemy,10, 130);
    spacewar_generate_enemy1(enemy,25, 130);
}

void spacewar_wave2(char enemy[][150])
{
    spacewar_generate_enemy1(enemy,7, 130);
    spacewar_generate_enemy1(enemy,18, 131);
    spacewar_generate_enemy1(enemy,29, 130);

}

void spacewar_wave3(char enemy[][150])
{
    spacewar_generate_enemy1(enemy,5, 130);
    spacewar_generate_enemy1(enemy,11, 131);
    spacewar_generate_enemy1(enemy,17, 132);
    spacewar_generate_enemy1(enemy,23, 131);
    spacewar_generate_enemy1(enemy,29, 130);

}

void spacewar_wave4(char enemy[][150])
{
    spacewar_generate_enemy1(enemy,5, 130);
    spacewar_generate_enemy1(enemy,10, 132);
    spacewar_generate_enemy1(enemy,15, 133);
    spacewar_generate_enemy1(enemy,20, 133);
    spacewar_generate_enemy1(enemy,25, 132);
    spacewar_generate_enemy1(enemy,30, 130);

}

void spacewar_wave5(char enemy[][150])
{
    spacewar_generate_enemy1(enemy,2, 129);
    spacewar_generate_enemy1(enemy,6, 130);
    spacewar_generate_enemy1(enemy,10, 131);
    spacewar_generate_enemy1(enemy,14, 133);
    spacewar_generate_enemy1(enemy,17, 135);
    spacewar_generate_enemy1(enemy,20, 133);
    spacewar_generate_enemy1(enemy,24, 131);
    spacewar_generate_enemy1(enemy,28, 130);
    spacewar_generate_enemy1(enemy,32, 129);



}

void spacewar_wave6(char enemy[][150])
{
    spacewar_generate_enemy1(enemy,2, 130);
    spacewar_generate_enemy1(enemy,5, 130);
    spacewar_generate_enemy1(enemy,8, 131);
    spacewar_generate_enemy1(enemy,11, 131);
    spacewar_generate_enemy1(enemy,14, 132);
    spacewar_generate_enemy1(enemy,17, 134);
    spacewar_generate_enemy1(enemy,20, 134);
    spacewar_generate_enemy1(enemy,23, 132);
    spacewar_generate_enemy1(enemy,26, 131);
    spacewar_generate_enemy1(enemy,29, 130);
    spacewar_generate_enemy1(enemy,32, 130);

}

void spacewar_wave7(char enemy[][150])
{
    spacewar_generate_enemy2(enemy,15, 125);
}

void spacewar_wave8(char enemy[][150])
{
    spacewar_generate_enemy2(enemy,9, 125);
    spacewar_generate_enemy2(enemy,25, 125);
}

void spacewar_wave9(char enemy[][150])
{
    spacewar_generate_enemy2(enemy,6, 120);
    spacewar_generate_enemy2(enemy,17, 134);

    spacewar_generate_enemy2(enemy,27, 120);
}

void spacewar_wave10(char enemy[][150])
{
    spacewar_generate_enemy3(enemy, 8, 130);
}

void spacewar_generate_player_position(char arr[][120], int x, int y)
{
    arr[x][y] = '|';
    arr[x][y + 1] = '"';
    arr[x][y + 2] = '\\';

    arr[x + 1][y] = ':';
    arr[x + 1][y + 1] = '|';
    arr[x + 1][y + 2] = ':';
    arr[x + 1][y + 3] = '=';
    arr[x + 1][y + 4] = '.';

    arr[x + 2][y] = '[';
    arr[x + 2][y + 1] = '+';
    arr[x + 2][y + 2] = ']';
    arr[x + 2][y + 3] = '|';
    arr[x + 2][y + 4] = '[';
    arr[x + 2][y + 5] = ')';

    arr[x + 3][y + 4] = '\'';
    arr[x + 3][y + 3] = '=';
    arr[x + 3][y + 2] = ':';
    arr[x + 3][y + 1] = '|';
    arr[x + 3][y] = ':';

    arr[x + 4][y + 2] = '/';
    arr[x + 4][y + 1] = '_';
    arr[x + 4][y] = '|';
}

void spacewar_clear_previous_player_position(char arr[][120],int x, int y)
{
    arr[x][y] = ' ';
    arr[x][y + 1] = ' ';
    arr[x][y + 2] = ' ';

    arr[x + 1][y] = ' ';
    arr[x + 1][y + 1] = ' ';
    arr[x + 1][y + 2] = ' ';
    arr[x + 1][y + 3] = ' ';
    arr[x + 1][y + 4] = ' ';

    arr[x + 2][y] = ' ';
    arr[x + 2][y + 1] = ' ';
    arr[x + 2][y + 2] = ' ';
    arr[x + 2][y + 3] = ' ';
    arr[x + 2][y + 4] = ' ';
    arr[x + 2][y + 5] = ' ';

    arr[x + 3][y + 4] = ' ';
    arr[x + 3][y + 3] = ' ';
    arr[x + 3][y + 2] = ' ';
    arr[x + 3][y + 1] = ' ';
    arr[x + 3][y] = ' ';

    arr[x + 4][y + 2] = ' ';
    arr[x + 4][y + 1] = ' ';
    arr[x + 4][y] = ' ';
}

void spacewar_destroy_player(char arr[][120], int x, int y)
{
    int random;



    arr[x][y] = (rand()%2)*2+176;
    arr[x][y + 1] = (rand()%2)*2+176;
    arr[x][y + 2] = (rand()%2)*2+176;

    arr[x + 1][y] = (rand()%2)*2+176;
    arr[x + 1][y + 1] = (rand()%2)*2+176;
    arr[x + 1][y + 2] = (rand()%2)*2+176;
    arr[x + 1][y + 3] = (rand()%2)*2+176;
    arr[x + 1][y + 4] = (rand()%2)*2+176;

    arr[x + 2][y] = (rand()%2)*2+176;
    arr[x + 2][y + 1] = (rand()%2)*2+176;
    arr[x + 2][y + 2] = (rand()%2)*2+176;
    arr[x + 2][y + 3] = (rand()%2)*2+176;
    arr[x + 2][y + 4] = (rand()%2)*2+176;
    arr[x + 2][y + 5] = (rand()%2)*2+176;

    arr[x + 3][y + 4] = (rand()%2)*2+176;
    arr[x + 3][y + 3] = (rand()%2)*2+176;
    arr[x + 3][y + 2] = (rand()%2)*2+176;
    arr[x + 3][y + 1] = (rand()%2)*2+176;
    arr[x + 3][y] = (rand()%2)*2+176;

    arr[x + 4][y + 2] = (rand()%2)+176;
    arr[x + 4][y + 1] = (rand()%2)*2+176;
    arr[x + 4][y] = (rand()%2)*2+176;

}

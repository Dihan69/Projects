#pragma once

#include "game_components/game_utility.c"

typedef struct
{
    float x, y;
    int hitpoints;
} fps_EInfo;

int play_fps(void);

    int fps_game_difficulty = 0;

int play_fps(void)
{
    srand(time(0));

    initialize_main_screen();
    setGameViewport(2, 2, 140, 40);

    int nScreenWidth = 140;			// Console Screen Size X (columns)
    int nScreenHeight = 40;			// Console Screen Size Y (rows)

    int nMapWidth = 45;				// World Dimensions
    int nMapHeight = 45;

    int dPlayerHit = 0;
    int dPlayerKills = 0;          // Player kill points
    int dPlayerHealth = 500;          // Player health points

    float fPlayerX = 42.0f;			// Player Start Position
    float fPlayerY = 3.0f;
    float fPlayerA = 0.0f;			// Player Start Rotation
    float fFOV = 3.14159f / 4.0f;	// Field of View
    float fDepth = 20.0f;			// Maximum rendering distance
    float fSpeed = 5.0f;			// Walking Speed

    float fESpeed = 2.5f;			// Enemy Walking Speed

    char game_screen[40][140];

    char map[2][45][46] =
    {
        {
            "  ########                                   ",
            "  #......#                      #############",
            "  #..G...#####                  #...........#",
            "  #..........##                ##...........#",
            "  #...........##################............#",
            "  #.........................................#",
            "  #.........................................#",
            " ##......................................####",
            "##......................G................#   ",
            "#........................................#   ",
            "#........................................##  ",
            "#.........................................###",
            "#............######.........................#",
            "#............#    #.........................#",
            "#..G.........#    #.........................#",
            "#...........##    #..........#######........#",
            "#####.......#     #..........#     #......G.#",
            "    ##......#     #..........#     #........#",
            "     #......#     #.......G..#     #......###",
            "     ########     #.........##     #.....##  ",
            "                  #......####      #.....#   ",
            "                  #......#      ####.....#   ",
            "                  #......#     ##........#   ",
            "                  #......#     #.........#   ",
            "                 ##......#     #.........####",
            "  ########     ###.......#     #............#",
            "  #......#     #.........#######............#",
            "  #..G...##    #............................#",
            "  #.......###  #............................#",
            "  #.........#  #..G.......................G.#",
            "  #.........#  #............................#",
            "  #.........#  #####.....................####",
            "  #.........#      ##...................##   ",
            "  #.........##      #...............#####    ",
            "  #..........####   #..............##        ",
            "  #.............#   #..............#         ",
            " ##.............#####..............#         ",
            "##.............................#####         ",
            "#.............................##             ",
            "#.............................#              ",
            "#.............................#              ",
            "#.............................#              ",
            "#####...G....###########...G..#              ",
            "    ##......##         #......#              ",
            "     ########          ########              "
        },
        {
            "          ############                       ",
            "          #..........#                       ",
            " ##########.......G..########################",
            " #..........................................#",
            " #..........................................#",
            " #..........................................#",
            "##...................############...........#",
            "#....................#          #..G........#",
            "#................#####          #...........#",
            "#..G.............#              #...........#",
            "#................#              #..#####....#",
            "#................#              #..#   #....#",
            "##...............#        #######..#   #....#",
            " #...............#        #........#  ##....#",
            " #............G..#        #.G......#  #.....#",
            " #...............##########........#  #.....#",
            " #...............#.................#  #..G..#",
            " ##....###########.................#  #.....#",
            "  #...##  #........................#  #.....#",
            "  #...#   #........................#  #.....#",
            "  #...#   #...G..................###  ##...##",
            "  #...#   #......................#     #...# ",
            "  #...##  #...................G..#     #...# ",
            " ##....####........####..........#     #...# ",
            " #.................#  #..........#     #...# ",
            " #..G..............#  ############     #...# ",
            " #.................#                   #...# ",
            " #....#########....#             #######...# ",
            " #...##       #....#             #.........# ",
            " #...#        #....########   ####.........# ",
            " #...#    #####...........#   #.....G......# ",
            " #...#  ###.............G.#   #............# ",
            " #...#  #.................#####............# ",
            " #...#  #..................................# ",
            " #...#  #..G............................#### ",
            "##...#  #...............................#    ",
            "#....#  #.............#############.....#    ",
            "#....#  #............##           ##....#    ",
            "#.G..#  #............#             #....#    ",
            "#....## #............#  ############....#    ",
            "#.....###............#  #...............#    ",
            "#.................G..####...............#    ",
            "#.....................................G.#    ",
            "#.......................................#    ",
            "#########################################    "
        }
    };

    int map_index = fps_game_difficulty;

    fps_EInfo enemy_info_map[45][45];

    for(int i = 0; i < nMapHeight; i++)
    {
        for(int j = 0; j < nMapWidth; j++)
        {
            enemy_info_map[i][j].x = 0.0f;
            enemy_info_map[i][j].y = 0.0f;

            enemy_info_map[i][j].hitpoints = 0;
        }
    }

	float fElapsedTime = 0.003;
	int dElapsedShootTime = 0;

	int enemy_gen_delay = 0;

	int link_break = -1;
	int gauge = 500;

	int target = 10 + (5 * map_index);

	int gun_fire_type = 0;

    while(1)
    {
		// Handle ACW Rotation
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
        {
			fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;
        }

		// Handle CW Rotation
		else if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
        {
			fPlayerA += (fSpeed * 0.75f) * fElapsedTime;
        }

		// Handle Forwards movement & collision
		else if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;

			if(map[map_index][(int)fPlayerY][(int)fPlayerX] == 'E')
            {
                dPlayerHit = 1;
            }

			if (map[map_index][(int)fPlayerY][(int)fPlayerX] != '.')
			{
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		// Handle Backwards movement & collision
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;

			if(map[map_index][(int)fPlayerY][(int)fPlayerX] == 'E')
            {
                dPlayerHit = 1;
            }

			if (map[map_index][(int)fPlayerY][(int)fPlayerX] != '.')
			{
				fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		// Handle Rightwards movement & collision
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			fPlayerX += cosf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY -= sinf(fPlayerA) * fSpeed * fElapsedTime;

			if(map[map_index][(int)fPlayerY][(int)fPlayerX] == 'E')
            {
                dPlayerHit = 1;
            }

			if (map[map_index][(int)fPlayerY][(int)fPlayerX] != '.')
			{
				fPlayerX -= cosf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY += sinf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		// Handle Leftwards movement & collision
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			fPlayerX -= cosf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY += sinf(fPlayerA) * fSpeed * fElapsedTime;

			if(map[map_index][(int)fPlayerY][(int)fPlayerX] == 'E')
            {
                dPlayerHit = 1;
            }

			if (map[map_index][(int)fPlayerY][(int)fPlayerX] != '.')
			{
				fPlayerX += cosf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= sinf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

        //Handling Firing
		else if((GetAsyncKeyState((unsigned short)'F') & 0x8000) && dElapsedShootTime == 0)
		{
            dElapsedShootTime = 13;

            gun_fire_type = rand() % 4;
		}

		else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            link_break = 1;
        }

        //In-game menu
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            int feedback = ingame_menu_screen();

            if(feedback == 1) return -1;
        }

        //Showing Game Over Screen
        if(dPlayerHealth <= 0)
        {
            return 0;
        }

        //Game win Condition
        if(target == 0)
        {
            delay(4111111111);
            return 1;
        }

        //Rendering 3D View Based On 2D Map
		for (int x = 0; x < nScreenWidth; x++)
		{
			// For each column, calculate the projected ray angle into world space
			float fRayAngle = (fPlayerA - fFOV/2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

			// Find distance to wall
			float fStepSize = 0.1f;		  // Increment size for ray casting, decrease to increase
			float fDistanceToWall = 0.0f; //                                      resolution

			int bHit = 0;		// Set when ray hits a block
			int bHitWall = 0;		// Set when ray hits wall block
			int bHitEnemy = 0;		// Set when ray hits enemy block
			int bHitGate = 0;		// Set when ray hits gate block
			int bWallBoundary = 0;		// Set when ray hits boundary between two wall blocks
			int bEnemyBoundary = 0;		// Set when ray hits boundary between two enemy blocks
			int bGateBoundary = 0;		// Set when ray hits boundary between two gate blocks

			float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
			float fEyeY = cosf(fRayAngle);

			// Incrementally cast ray from player, along ray angle, testing for
			// intersection with a block
			while (!bHit && fDistanceToWall < fDepth)
			{
				fDistanceToWall += fStepSize;
				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				// Test if ray is out of bounds
				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
				{
					bHit = 1;			// Just set distance to maximum depth
					fDistanceToWall = fDepth;
				}

				// Ray is inbounds so test to see if the ray cell is a wall block
                else if (map[map_index][nTestY][nTestX] == '#')
                {
                    // Ray has hit and it is wall
					bHit = 1;
					bHitWall = 1;

					// To highlight tile boundaries, cast a ray from each corner
					// of the tile, to the player. The more coincident this ray
					// is to the rendering ray, the closer we are to a tile
					// boundary, which we'll shade to add detail to the walls
					float pW[4][2];

					// Test each corner of hit tile, storing the distance from
					// the player, and the calculated dot product of the two rays
					for (int tx = 0, ec = 0; tx < 2; tx++)
                        for (int ty = 0; ty < 2; ty++, ec++)
                        {
							// Angle of corner to eye
							float vy = (float)nTestY + ty - fPlayerY;
							float vx = (float)nTestX + tx - fPlayerX;
							float d = sqrt(vx*vx + vy*vy);
							float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
							pW[ec][0] = d;
							pW[ec][1] = dot;
						}

					// Sort Pairs from closest to farthest
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3 - i; j++)
                        {
                            if(pW[j][0] > pW[j + 1][0])
                            {
                                float temp;

                                temp = pW[j][0];
                                pW[j][0] = pW[j + 1][0];
                                pW[j + 1][0] = temp;

                                temp = pW[j][1];
                                pW[j][1] = pW[j + 1][1];
                                pW[j + 1][1] = temp;
                            }
                        }
                    }

                    // First two/three are closest (we will never see all four)
                    float fBound = 0.01;
                    if (acos(pW[0][1]) < fBound) bWallBoundary = 1;
                    if (acos(pW[1][1]) < fBound) bWallBoundary = 1;
                }

                //to see if ray approaches enemy
                else if (map[map_index][nTestY][nTestX] == 'E')
                {
                    if(x == 69 && dElapsedShootTime)
                    {
                        enemy_info_map[nTestY][nTestX].hitpoints--;
                    }

                    if(enemy_info_map[nTestY][nTestX].hitpoints == 0)
                    {
                        dPlayerKills++;
                        map[map_index][nTestY][nTestX] = '.';

                        enemy_info_map[nTestY][nTestX].x = 0.0f;
                        enemy_info_map[nTestY][nTestX].y = 0.0f;
                        continue;
                    }

                    // Ray has hit and it is enemy
					bHit = 1;
                    bHitEnemy = 1;

                    // To highlight tile boundaries, cast a ray from each corner
					// of the tile, to the player. The more coincident this ray
					// is to the rendering ray, the closer we are to a tile
					// boundary, which we'll shade to add detail to the walls
					float pE[4][2];

					// Test each corner of hit tile, storing the distance from
					// the player, and the calculated dot product of the two rays
					for (int tx = 0, ec = 0; tx < 2; tx++)
                        for (int ty = 0; ty < 2; ty++, ec++)
                        {
							// Angle of corner to eye
							float vy = (float)nTestY + ty - fPlayerY;
							float vx = (float)nTestX + tx - fPlayerX;

							float d = sqrt(vx*vx + vy*vy);

							float dot = (fEyeX * vx / d) + (fEyeY * vy / d);

							pE[ec][0] = d;
							pE[ec][1] = dot;
						}

					// Sort Pairs from closest to farthest
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3 - i; j++)
                        {
                            if(pE[j][0] > pE[j + 1][0])
                            {
                                float temp;

                                temp = pE[j][0];
                                pE[j][0] = pE[j + 1][0];
                                pE[j + 1][0] = temp;

                                temp = pE[j][1];
                                pE[j][1] = pE[j + 1][1];
                                pE[j + 1][1] = temp;
                            }
                        }
                    }

                    // First two/three are closest (we will never see all four)
                    float fBound = 0.01;
                    if (acos(pE[0][1]) < fBound) bEnemyBoundary = 1;
                    if (acos(pE[1][1]) < fBound) bEnemyBoundary = 1;
                }

                //to see if ray approaches gateway
                else if (map[map_index][nTestY][nTestX] == 'G')
                {
                    // Ray has hit and it is gateway
					bHit = 1;
                    bHitGate = 1;

                    // To highlight tile boundaries, cast a ray from each corner
					// of the tile, to the player. The more coincident this ray
					// is to the rendering ray, the closer we are to a tile
					// boundary, which we'll shade to add detail to the walls
					float pG[4][2];

					// Test each corner of hit tile, storing the distance from
					// the player, and the calculated dot product of the two rays
					for (int tx = 0, ec = 0; tx < 2; tx++)
                        for (int ty = 0; ty < 2; ty++, ec++)
                        {
							// Angle of corner to eye
							float vy = (float)nTestY + ty - fPlayerY;
							float vx = (float)nTestX + tx - fPlayerX;

							float d = sqrt(vx*vx + vy*vy);

							float dot = (fEyeX * vx / d) + (fEyeY * vy / d);

							pG[ec][0] = d;
							pG[ec][1] = dot;
						}

					// Sort Pairs from closest to farthest
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3 - i; j++)
                        {
                            if(pG[j][0] > pG[j + 1][0])
                            {
                                float temp;

                                temp = pG[j][0];
                                pG[j][0] = pG[j + 1][0];
                                pG[j + 1][0] = temp;

                                temp = pG[j][1];
                                pG[j][1] = pG[j + 1][1];
                                pG[j + 1][1] = temp;
                            }
                        }
                    }

                    // First two/three are closest (we will never see all four)
                    float fBound = 0.01;
                    if (acos(pG[0][1]) < fBound) bGateBoundary = 1;
                    if (acos(pG[1][1]) < fBound) bGateBoundary = 1;
                }
            }

			// Calculate distance to ceiling and floor
			int nCeiling = (float)(nScreenHeight/2.0) - nScreenHeight / ((float)fDistanceToWall);
			int nFloor = nScreenHeight - nCeiling;

			// Shader walls based on distance
			short nShade = ' ';

			if(bHitWall)
            {
                if (fDistanceToWall <= fDepth / 4.0f)			nShade = 219;	// Very close
                else if (fDistanceToWall < fDepth / 3.0f)		nShade = 178;
                else if (fDistanceToWall < fDepth / 2.0f)		nShade = 177;
                else if (fDistanceToWall < fDepth)				nShade = 176;
                else											nShade = ' ';		// Too far away
            }

            if(bHitEnemy)
            {
                if (fDistanceToWall <= fDepth / 3.0f)		    nShade = "\334\335\336\337"[rand() % 4];    // Very close
                else if (fDistanceToWall < fDepth / 2.0f)		nShade = "\36\37"[rand() % 2];
                else if (fDistanceToWall < fDepth)				nShade = "<>"[rand() % 2];
                else											nShade = ' ';		                        // Too far away
            }

            if(bHitGate)
            {
                if (fDistanceToWall <= fDepth / 3.0f)		    nShade = 232;       // Very close
                else if (fDistanceToWall < fDepth / 2.0f)		nShade = 237;
                else if (fDistanceToWall < fDepth)				nShade = 233;
                else											nShade = ' ';		// Too far away
            }

			if (bWallBoundary)		nShade = ' '; // Black it out

			if (bEnemyBoundary) // Enemy edge
            {
                if (fDistanceToWall <= fDepth / 3.0f)		    nShade = 186;       // Very close
                else if (fDistanceToWall < fDepth / 2.0f)		nShade = 179;
                else if (fDistanceToWall < fDepth)				nShade = 'x';
                else											nShade = ' ';		// Too far away
            }

            if (bGateBoundary) // Gate edge
            {
                if (fDistanceToWall <= fDepth / 3.0f)		    nShade = '1';       // Very close
                else if (fDistanceToWall < fDepth / 2.0f)		nShade = '!';
                else if (fDistanceToWall < fDepth)				nShade = ':';
                else											nShade = ' ';		// Too far away
            }

			for (int y = 0; y < nScreenHeight; y++)
			{
				// Each Row
				if(y <= nCeiling)
					game_screen[y][x] = ' ';
				else if(y > nCeiling && y <= nFloor)
					game_screen[y][x] = nShade;
				else // Floor
				{
					// Shade floor based on distance
					float b = 1.0f - (((float)y -nScreenHeight/2.0f) / ((float)nScreenHeight / 2.0f));

					if (b < 0.25)		nShade = '#';
					else if (b < 0.5)	nShade = 'x';
					else if (b < 0.75)	nShade = '.';
					else if (b < 0.9)	nShade = '-';
					else				nShade = ' ';

					game_screen[y][x] = nShade;
				}
			}
		}

		//Display map
		game_screen[0][1] = 218;
        game_screen[0][39] = 191;
        game_screen[16][1] = 192;
        game_screen[16][39] = 217;

        for(int i = 1; i < 16; i++)
        {
            game_screen[i][1] = 179;
            game_screen[i][2] = ' ';
            game_screen[i][38] = ' ';
            game_screen[i][39] = 179;
        }

        for(int j = 2; j < 39; j++)
        {
            game_screen[0][j] = 196;
            game_screen[16][j] = 196;
        }

        for(int k = 0; k < 4; k++) //directions
        {
            game_screen[6 + k][1] = "WEST"[k];
            game_screen[6 + k][39] = "EAST"[k];
        }

        for(int k = 0; k < 5; k++) //directions
        {
            game_screen[0][18 + k] = "NORTH"[k];
            game_screen[16][18 + k] = "SOUTH"[k];
        }

        int mapFocusX, mapFocusY;

        if((int)fPlayerX - 17 < 0) mapFocusX = 0;
        else if((int)fPlayerX + 17 > 44) mapFocusX = 10;
        else mapFocusX = (int)fPlayerX - 17;

        if((int)fPlayerY - 7 < 0) mapFocusY = 0;
        else if((int)fPlayerY + 7 > 44) mapFocusY = 30;
        else mapFocusY = (int)fPlayerY - 7;

        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 35; j++)
            {
                if(mapFocusY + i == (int)fPlayerY && mapFocusX + j == (int)fPlayerX)
                {
                    game_screen[1 + i][37 - j] = 'P';
                }
                else
                {
                    game_screen[1 + i][37 - j] = map[map_index][mapFocusY + i][mapFocusX + j];
                }
            }
        }

        //Setting Gunpoint
        if(dElapsedShootTime)
        {
            //gunfire effect
            for(int i = 0; i < 5; i += 4)
            {
                for(int j = 0; j < 9; j += 8)
                {
                    game_screen[17 + i][65 + j] = ((rand() % 2) ? (176 + (rand() % 3)) : ' ');
                }
            }

            int gun_fire_shade = 177 + (rand() % 2);

            if(gun_fire_type == 0)
            {
                game_screen[14][65] = gun_fire_shade;
                game_screen[14][66] = gun_fire_shade;
                game_screen[15][63] = gun_fire_shade;
                game_screen[15][64] = gun_fire_shade;
                game_screen[16][61] = gun_fire_shade;
                game_screen[16][62] = gun_fire_shade;
                game_screen[17][59] = gun_fire_shade;
                game_screen[17][60] = gun_fire_shade;
                game_screen[18][59] = gun_fire_shade;
                game_screen[18][60] = gun_fire_shade;
                game_screen[19][59] = gun_fire_shade;
                game_screen[19][60] = gun_fire_shade;
                game_screen[20][59] = gun_fire_shade;
                game_screen[20][60] = gun_fire_shade;

                game_screen[15][74] = gun_fire_shade;
                game_screen[15][75] = gun_fire_shade;
                game_screen[16][76] = gun_fire_shade;
                game_screen[16][77] = gun_fire_shade;
                game_screen[17][78] = gun_fire_shade;
                game_screen[17][79] = gun_fire_shade;
                game_screen[18][78] = gun_fire_shade;
                game_screen[18][79] = gun_fire_shade;

                for(int k = 0; k < 5; k++)
                {
                    game_screen[24][69 + k] = gun_fire_shade;
                }

                game_screen[23][74] = gun_fire_shade;
                game_screen[23][75] = gun_fire_shade;

                game_screen[22][76] = gun_fire_shade;
                game_screen[22][77] = gun_fire_shade;
            }
            else if(gun_fire_type == 1)
            {
                for(int k = 0; k < 5; k++)
                {
                    game_screen[14][69 + k] = gun_fire_shade;
                }

                game_screen[15][74] = gun_fire_shade;
                game_screen[15][75] = gun_fire_shade;
                game_screen[16][76] = gun_fire_shade;
                game_screen[16][77] = gun_fire_shade;
                game_screen[17][78] = gun_fire_shade;
                game_screen[17][79] = gun_fire_shade;
                game_screen[18][78] = gun_fire_shade;
                game_screen[18][79] = gun_fire_shade;
                game_screen[19][78] = gun_fire_shade;
                game_screen[19][79] = gun_fire_shade;

                game_screen[19][59] = gun_fire_shade;
                game_screen[19][60] = gun_fire_shade;
                game_screen[20][59] = gun_fire_shade;
                game_screen[20][60] = gun_fire_shade;
                game_screen[21][59] = gun_fire_shade;
                game_screen[21][60] = gun_fire_shade;
                game_screen[22][61] = gun_fire_shade;
                game_screen[22][62] = gun_fire_shade;
                game_screen[23][63] = gun_fire_shade;
                game_screen[23][64] = gun_fire_shade;

                for(int k = 0; k < 5; k++)
                {
                    game_screen[24][69 - k] = gun_fire_shade;
                }
            }
            else if(gun_fire_type == 2)
            {
                for(int k = 0; k < 9; k++)
                {
                    main_screen[14][65 + k] = gun_fire_shade;
                }

                main_screen[15][63] = gun_fire_shade;
                main_screen[15][64] = gun_fire_shade;
                main_screen[16][61] = gun_fire_shade;
                main_screen[16][62] = gun_fire_shade;

                game_screen[20][59] = gun_fire_shade;
                game_screen[20][60] = gun_fire_shade;
                game_screen[21][59] = gun_fire_shade;
                game_screen[21][60] = gun_fire_shade;
                game_screen[22][61] = gun_fire_shade;
                game_screen[22][62] = gun_fire_shade;
                game_screen[23][63] = gun_fire_shade;
                game_screen[23][64] = gun_fire_shade;

                game_screen[19][78] = gun_fire_shade;
                game_screen[19][79] = gun_fire_shade;
                game_screen[20][78] = gun_fire_shade;
                game_screen[20][79] = gun_fire_shade;
                game_screen[21][78] = gun_fire_shade;
                game_screen[21][79] = gun_fire_shade;

                for(int k = 1; k < 5; k++)
                {
                    game_screen[24][69 + k] = gun_fire_shade;
                }

                game_screen[23][74] = gun_fire_shade;
                game_screen[23][75] = gun_fire_shade;

                game_screen[22][76] = gun_fire_shade;
                game_screen[22][77] = gun_fire_shade;
            }

            //firing sequence
            switch(dElapsedShootTime)
            {
                case 12:
                case 11:
                case 10:
                case 4:
                case 3:
                case 2:
                    game_screen[17][65] = 218;
                    game_screen[17][69] = 186;
                    game_screen[17][73] = 191;

                    game_screen[19][64] = 205;
                    game_screen[19][65] = 205;
                    game_screen[19][69] = 197;
                    game_screen[19][73] = 205;
                    game_screen[19][74] = 205;

                    game_screen[21][65] = 192;
                    game_screen[21][69] = 186;
                    game_screen[21][73] = 217;
                    break;

                case 8:
                case 7:
                case 6:
                    game_screen[17][65] = 201;
                    game_screen[17][69] = 179;
                    game_screen[17][73] = 187;

                    game_screen[19][64] = 196;
                    game_screen[19][65] = 196;
                    game_screen[19][69] = 206;
                    game_screen[19][73] = 196;
                    game_screen[19][74] = 196;

                    game_screen[21][65] = 200;
                    game_screen[21][69] = 179;
                    game_screen[21][73] = 188;
                    break;
            }

            dElapsedShootTime--;
        }
        else
        {
            //without firing
            game_screen[17][65] = 218;
            game_screen[17][69] = 179;
            game_screen[17][73] = 191;

            game_screen[19][64] = 196;
            game_screen[19][65] = 196;
            game_screen[19][69] = '+';
            game_screen[19][73] = 196;
            game_screen[19][74] = 196;

            game_screen[21][65] = 192;
            game_screen[21][69] = 179;
            game_screen[21][73] = 217;
        }

        //Setting Player Stat
        char text1[9] = " HEALTH ";

        game_screen[0][78] = 201;
        game_screen[1][78] = 179;
        game_screen[2][78] = 200;

        for(int k = 0; k < 8; k++)
        {
            game_screen[1][79 + k] = text1[k];

            if(k == 0 || k == 7)
            {
                game_screen[0][79 + k] = ' ';
                game_screen[2][79 + k] = ' ';
            }
            else
            {
                game_screen[0][79 + k] = 196;
                game_screen[2][79 + k] = 196;
            }
        }

        game_screen[0][87] = 203;
        game_screen[1][87] = 222;
        game_screen[2][87] = 202;
        game_screen[0][138] = 187;
        game_screen[1][138] = 221;
        game_screen[2][138] = 188;

        for(int k = 0; k < ((dPlayerHealth + 9) / 10); k++)
        {
            game_screen[0][88 + k] = 220;
            game_screen[2][88 + k] = 223;
            game_screen[1][88 + k] = 178;
        }

        for(int k = ((dPlayerHealth + 9) / 10); k < 50; k++)
        {
            game_screen[0][88 + k] = 220;
            game_screen[2][88 + k] = 223;
            game_screen[1][88 + k] = 176;
        }

        char text2[17] = " GATE-LINK LEFT ", text3[12];

        sprintf(text3, "%9d  ", target);

        game_screen[3][109] = 201;
        game_screen[4][109] = 179;
        game_screen[5][109] = 200;

        for(int k = 0; k < 16; k++)
        {
            game_screen[4][110 + k] = text2[k];

            if(k == 0 || k == 15)
            {
                game_screen[3][110 + k] = ' ';
                game_screen[5][110 + k] = ' ';
            }
            else
            {
                game_screen[3][110 + k] = 196;
                game_screen[5][110 + k] = 196;
            }
        }

        game_screen[3][126] = 203;
        game_screen[4][126] = 179;
        game_screen[5][126] = 202;

        for(int k = 0; k < 11; k++)
        {
            game_screen[3][127 + k] = 196;
            game_screen[4][127 + k] = text3[k];
            game_screen[5][127 + k] = 196;
        }

        game_screen[3][138] = 187;
        game_screen[4][138] = 179;
        game_screen[5][138] = 188;

        char text4[8] = " KILLS ", text5[12];

        sprintf(text5, "%9d  ", dPlayerKills);

        game_screen[3][84] = 201;
        game_screen[4][84] = 179;
        game_screen[5][84] = 200;

        for(int k = 0; k < 7; k++)
        {
            game_screen[4][85 + k] = text4[k];

            if(k == 0 || k == 6)
            {
                game_screen[3][85 + k] = ' ';
                game_screen[5][85 + k] = ' ';
            }
            else
            {
                game_screen[3][85 + k] = 196;
                game_screen[5][85 + k] = 196;
            }
        }

        game_screen[3][92] = 203;
        game_screen[4][92] = 179;
        game_screen[5][92] = 202;

        for(int k = 0; k < 11; k++)
        {
            game_screen[3][93 + k] = 196;
            game_screen[4][93 + k] = text5[k];
            game_screen[5][93 + k] = 196;
        }

        game_screen[3][104] = 187;
        game_screen[4][104] = 179;
        game_screen[5][104] = 188;

        char text6[20] = " FACING SOUTH      ";

        if(sin(fPlayerA) >= 0.0 && cos(fPlayerA) >= 0.0)
        {
            if(sin(fPlayerA) >= 0.0 && sin(fPlayerA) < 0.38268)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "SOUTH     "[k];
                }
            }
            else if(sin(fPlayerA) >= 0.38268 && sin(fPlayerA) < 0.92388)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "SOUTH-WEST"[k];
                }
            }
            else if(sin(fPlayerA) >= 0.92388 && sin(fPlayerA) < 1.0)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "WEST      "[k];
                }
            }
        }
        else if(sin(fPlayerA) >= 0.0 && cos(fPlayerA) < 0.0)
        {
            if(sin(fPlayerA) >= 0.0 && sin(fPlayerA) < 0.38268)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "NORTH     "[k];
                }
            }
            else if(sin(fPlayerA) >= 0.38268 && sin(fPlayerA) < 0.92388)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "NORTH-WEST"[k];
                }
            }
            else if(sin(fPlayerA) >= 0.92388 && sin(fPlayerA) < 1.0)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "WEST      "[k];
                }
            }
        }
        else if(sin(fPlayerA) < 0.0 && cos(fPlayerA) < 0.0)
        {
            if(sin(fPlayerA) < 0.0 && sin(fPlayerA) >= -0.38268)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "NORTH     "[k];
                }
            }
            else if(sin(fPlayerA) < -0.38268 && sin(fPlayerA) >= -0.92388)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "NORTH-EAST"[k];
                }
            }
            else if(sin(fPlayerA) < -0.92388 && sin(fPlayerA) >= -1.0)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "EAST      "[k];
                }
            }
        }
        else if(sin(fPlayerA) < 0.0 && cos(fPlayerA) >= 0.0)
        {
            if(sin(fPlayerA) < 0.0 && sin(fPlayerA) >= -0.38268)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "SOUTH     "[k];
                }
            }
            else if(sin(fPlayerA) < -0.38268 && sin(fPlayerA) >= -0.92388)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "SOUTH-EAST"[k];
                }
            }
            else if(sin(fPlayerA) < -0.92388 && sin(fPlayerA) >= -1.0)
            {
                for(int k = 0; k < 10; k++)
                {
                    text6[8 + k] = "EAST      "[k];
                }
            }
        }

        game_screen[6][116] = 201;
        game_screen[7][116] = 179;
        game_screen[8][116] = 200;

        for(int k = 0; k < 19; k++)
        {
            game_screen[7][117 + k] = text6[k];

            game_screen[6][117 + k] = 196;
            game_screen[8][117 + k] = 196;
        }

        game_screen[6][136] = 187;
        game_screen[7][136] = 179;
        game_screen[8][136] = 188;

		//Setting Frame
		for(int i = 0; i < nScreenHeight; i++)
        {
            for(int j = 0; j < nScreenWidth; j++)
            {
                main_screen[5 + i][5 + j] = game_screen[i][j];
            }
        }

        //Setting Gate link Status
        if(link_break == 1)
        {
            int gate_found = 0;

            for(int i = -1; i < 2; i++)
            {
                for(int j = -1; j < 2; j++)
                {
                    if((int)fPlayerX + j < nMapWidth && (int)fPlayerX + j >= 0 && (int)fPlayerY + i < nMapHeight && (int)fPlayerY + i >= 0 && map[map_index][(int)fPlayerY + i][(int)fPlayerX + j] == 'G')
                    {
                        gauge--;

                        setGameAccessoryTab(22, 38, 100, 1);

                        main_screen[39][71] = ' ';
                        main_screen[39][72] = 'S';
                        main_screen[39][73] = 'T';
                        main_screen[39][74] = 'A';
                        main_screen[39][75] = 'T';
                        main_screen[39][76] = 'U';
                        main_screen[39][77] = 'S';
                        main_screen[39][78] = ' ';

                        for(int k = 0; k < (100 * (500 - gauge))/ 500; k++)
                        {
                            main_screen[41][24 + k] = 178;
                        }

                        for(int k = (100 * (500 - gauge))/ 500; k < 100; k++)
                        {
                            main_screen[41][24 + k] = ' ';
                        }

                        if(gauge == 0)
                        {
                            map[map_index][(int)fPlayerY + i][(int)fPlayerX + j] = '.';

                            int p = (int)fPlayerY + i;
                            int q = (int)fPlayerX + j;

                            for(int l = -7 + (map_index * 2); l < 8 - (map_index * 2); l++)
                            {
                                for(int k = -7 + (map_index * 2); k < 8 - (map_index * 2); k++)
                                {
                                    if(q + k < nMapWidth && q + k >= 0 && p + l < nMapHeight && p + l >= 0 && map[map_index][p + l][q + k] == 'E')
                                    {
                                        map[map_index][p + l][q + k] = '.';
                                    }
                                }
                            }

                            gauge = 500;
                            target--;
                        }

                        link_break = 0;

                        gate_found = 1;
                        break;
                    }

                    if(i == 0 && j == -1) j++;
                }

                if(gate_found) break;
            }

            if(link_break != 0) link_break = -1;
        }
        else if(link_break == 0)
        {
            gauge = 500;
            clear_main_screen(22, 38, 104, 7);
            link_break = -1;
        }

        //Getting hit from enemy
        if(dPlayerHit)
        {
            dPlayerHealth--;

            if(rand() % 2)
            {
                for(int k = 0; k < 10; k++)
                {
                    int i = 7 + (rand() % 36);

                    int j_max = 75 + (rand() % 70);

                    for(int j = 5 + (rand() % 70); j < j_max; j++)
                    {
                            main_screen[i][j] = 176 + (rand() % 3);
                    }
                }
            }
            else
            {
                for(int k = 0; k < 5; k++)
                {
                    int i = 7 + (rand() % 36);

                    int j_max = 37 + (rand() % 38);

                    for(int j = 5 + (rand() % 30); j < j_max; j++)
                    {
                        main_screen[i][j] = 176 + (rand() % 3);
                    }

                    j_max = 112 + (rand() % 33);

                    for(int j = 75 + (rand() % 38); j < j_max; j++)
                    {
                        main_screen[i][j] = 176 + (rand() % 3);
                    }
                }
            }

            dPlayerHit = 0;
        }

		// Display Frame
        show_main_screen();
        delay(5000000);

        //Enemy Movement
        for(int i = 0; i < nMapHeight; i++)
        {
            for(int j = 0; j < nMapWidth; j++)
            {
                if(map[map_index][i][j] == 'E')
                {
                    map[map_index][i][j] = '.';

                    float oldEnemyPosX = enemy_info_map[i][j].x;
                    float oldEnemyPosY = enemy_info_map[i][j].y;

                    if(fPlayerX > enemy_info_map[i][j].x) (enemy_info_map[i][j].x) += (fESpeed * fElapsedTime);
                    else if(fPlayerX < enemy_info_map[i][j].x) (enemy_info_map[i][j].x) -= (fESpeed * fElapsedTime);

                    if(fPlayerY > enemy_info_map[i][j].y) (enemy_info_map[i][j].y) += (fESpeed * fElapsedTime);
                    else if(fPlayerY < enemy_info_map[i][j].y) (enemy_info_map[i][j].y) -= (fESpeed * fElapsedTime);

                    if((int)fPlayerX == (int)enemy_info_map[i][j].x && (int)fPlayerY == (int)enemy_info_map[i][j].y)
                    {
                        dPlayerHit = 1;

                        enemy_info_map[i][j].x = oldEnemyPosX;
                        enemy_info_map[i][j].y = oldEnemyPosY;

                        map[map_index][(int)enemy_info_map[i][j].y][(int)enemy_info_map[i][j].x] = 'M';
                    }
                    else if(map[map_index][(int)enemy_info_map[i][j].y][(int)enemy_info_map[i][j].x] != '.')
                    {
                        enemy_info_map[i][j].x = oldEnemyPosX;
                        enemy_info_map[i][j].y = oldEnemyPosY;

                        map[map_index][(int)enemy_info_map[i][j].y][(int)enemy_info_map[i][j].x] = 'M';
                    }
                    else
                    {
                        map[map_index][(int)enemy_info_map[i][j].y][(int)enemy_info_map[i][j].x] = 'M';

                        enemy_info_map[(int)enemy_info_map[i][j].y][(int)enemy_info_map[i][j].x].x = enemy_info_map[i][j].x;
                        enemy_info_map[(int)enemy_info_map[i][j].y][(int)enemy_info_map[i][j].x].y = enemy_info_map[i][j].y;
                        enemy_info_map[(int)enemy_info_map[i][j].y][(int)enemy_info_map[i][j].x].hitpoints = enemy_info_map[i][j].hitpoints;

                        if(i != (int)enemy_info_map[i][j].y && j != (int)enemy_info_map[i][j].x)
                        {
                            enemy_info_map[i][j].x = 0.0f;
                            enemy_info_map[i][j].y = 0.0f;

                            enemy_info_map[i][j].hitpoints = 0;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < nMapHeight; i++)
        {
            for(int j = 0; j < nMapWidth; j++)
            {
                if(map[map_index][i][j] == 'M') map[map_index][i][j] = 'E';
            }
        }

        //Enemy Generation
        if(enemy_gen_delay == 750 - (200 * map_index))
        {
            for(int i = 0; i < nMapHeight; i++)
            {
                for(int j = 0; j < nMapWidth; j++)
                {
                    if(map[map_index][i][j] == 'G')
                    {
                        int player_spotted = 0;

                        for(int l = -7 - (map_index * 2); l < 8 + (map_index * 2); l++)
                        {
                            for(int k = -7 - (map_index * 2); k < 8 + (map_index * 2); k++)
                            {
                                if(l == 0 && k == 0) k++;

                                if(i + l == (int)fPlayerY && j + k == (int)fPlayerX)
                                {
                                    player_spotted = 1;

                                    int enemy_spawned = 0;

                                    for(int p = -7 - (map_index * 2); p < 8 + (map_index * 2); p++)
                                    {
                                        for(int q = -7 - (map_index * 2); q < 8 + (map_index * 2); q++)
                                        {
                                            if(p >= (-3 + (map_index * 2)) && p <= (3 - (map_index * 2)) && q == (-3 + (map_index * 2))) q += (7 - (map_index * 4));

                                            if(i + p < nMapHeight && i + p >= 0 && j + q < nMapWidth && j + q >= 0 && rand() % 2 && map[map_index][i + p][j + q] == '.')
                                            {
                                                map[map_index][i + p][j + q] = 'E';

                                                enemy_info_map[i + p][j + q].x = j + q * 1.0f;
                                                enemy_info_map[i + p][j + q].y = i + p * 1.0f;

                                                enemy_info_map[i + p][j + q].hitpoints = 250;

                                                enemy_spawned = 1;
                                                break;
                                            }
                                        }

                                        if(enemy_spawned) break;
                                    }

                                    break;
                                }
                            }

                            if(player_spotted) break;
                        }
                    }
                }
            }

            enemy_gen_delay = 0;
        }
        else enemy_gen_delay++;
    }

    return 0;
}


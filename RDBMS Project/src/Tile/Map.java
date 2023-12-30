package Tile;

import MainPackage.GamePanel;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Map extends TileManager{

    GamePanel gp;
    BufferedImage worldMap[];

    public Map(GamePanel gp) {
        super(gp);
        this.gp=gp;


        createWorldMap();

    }


    public void createWorldMap()
    {
        worldMap= new BufferedImage[gp.maxMap];

        for(int i=0; i<gp.maxMap; i++)
        {


            int worldMapWidth= gp.tileSize*gp.maxWorldCol[i];
            int worldMapHeight=gp.tileSize*gp.maxWorldRow[i];

            worldMap[i]= new BufferedImage(worldMapWidth, worldMapHeight, BufferedImage.TYPE_INT_ARGB);
            Graphics2D g2= (Graphics2D) worldMap[i].createGraphics();

            int col=0;
            int row=0;

            while(col <gp.maxWorldCol[i] && row < gp.maxWorldRow[i])
            {
                int tileNum= fixMap(mapTileNum[i][col][row]);
                int x= gp.tileSize*col;
                int y =gp.tileSize*row;
                g2.drawImage(tile[tileNum].image, x, y , null);

                col++;

                if(col==gp.maxWorldCol[i])
                {
                    col=0;
                    row++;
                }
            }
        }

    }

    public void drawFullMapScreen(Graphics2D g2)
    {
        g2.setColor(Color.black);
        g2.fillRect(0,0, gp.screenWidth, gp.screenWidth);

        int width= gp.screenWidth;
        int height=gp.screenHeight;
        int x= 0;
        int y= 0;

        g2.drawImage(worldMap[gp.currentMap], x, y, width, height, null);

        double scale=(double)(gp.tileSize*  gp.maxWorldCol[gp.currentMap])/width;
        double scale2=(double)(gp.tileSize*  gp.maxWorldRow[gp.currentMap])/height;
        int playerX= (int) (gp.player.BoyWorldX/scale)-12;
        int playerY= (int) ( gp.player.BoyWorldY/scale2)-12;
        int playerSize= (int)(gp.tileSize/scale)*4;



        g2.drawImage(gp.player.down[0], playerX, playerY, playerSize, playerSize, null);

         playerX= (int) (gp.player.GirlWorldX/scale)-12;
         playerY= (int) ( gp.player.GirlWOrldY/scale2)-12;


        g2.drawImage(gp.player.down_girl[1], playerX, playerY, playerSize, playerSize, null);
    }

    public int fixMap(int i)
    {
        if(i>=15 && i<=17)
            i=2;
        else if( i>=19 && i<=26)
            i=5;
        else if(i>=105 && i<=114)
            i=81;
        else if(i==64 || i==65)
            i=45;
        else if(i>=118 && i<=125)
            i=120;

        return i;
    }
}

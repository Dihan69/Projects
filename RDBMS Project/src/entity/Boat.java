package entity;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class Boat extends Entity{

    public BufferedImage all[]=new BufferedImage[8];

    public Boat(GamePanel gp) {
        super(gp);
        speed=2;
        spriteNum=4;
        height=128;
        width=128;
        getImage();
    }

    public void getImage()
    {
        try
        {
            all[0]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("travel/boat-left-all.png"));
            all[1]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("travel/boat-left-down-all.png"));
            all[2]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("travel/boat-down.png"));
            all[3]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("travel/boat-right-down-all.png"));
            all[4]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("travel/boat-right-all.png"));
            all[5]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("travel/boat-right-up-all.png"));
            all[6]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("travel/boat-up-all.png"));
            all[7]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("travel/boat-left-up-all.png"));


        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    public int press_delay=0;

    public void update()
    {
        gp.player.GirlWorldX=worldX;
        gp.player.GirlWOrldY=worldY;
        gp.player.BoyWorldY=worldY;
        gp.player.BoyWorldX=worldX;
        gp.player.worldX=worldX;
        gp.player.worldY=worldY;

        if(gp.keyH.downPressed && gp.keyH.rightPressed && press_delay<=0)
        {
            if(spriteNum!=3)
            {   press_delay=5;

                if(spriteNum>=4 && spriteNum<=6)
                    spriteNum=(--spriteNum)%8;
                else
                spriteNum=(++spriteNum)%8;
            }
            else
            {
                worldX+=speed/2;
                worldY+=speed/2;
            }


        }
        else     if(gp.keyH.downPressed && gp.keyH.leftPressed && press_delay<=0)
        {
            if(spriteNum!=1)
            {  press_delay=5;

                if(spriteNum>=2 && spriteNum<=4)
                    spriteNum=(--spriteNum)%8;
                else
                    spriteNum=(++spriteNum)%8;
            }
            else
            {
                worldX-=speed/2;
                worldY+=speed/2;
            }


        }
        else     if(gp.keyH.upPressed && gp.keyH.rightPressed && press_delay<=0)
        {
            if(spriteNum!=5)
            {  press_delay=5;

                if(spriteNum>=6 && spriteNum<=7 || spriteNum==0)
                    spriteNum=(--spriteNum)%8;
                else
                spriteNum=(++spriteNum)%8;
            }
            else
            {
                worldX+=speed/2;
                worldY-=speed/2;
            }


        }
        else     if(gp.keyH.upPressed && gp.keyH.leftPressed && press_delay<=0)
        {
            if(spriteNum!=7)
            {
                press_delay=5;

                if(spriteNum<=2)
                    spriteNum=(--spriteNum)%8;
                else
                spriteNum=(++spriteNum)%8;
            }
            else
            {
                worldX-=speed/2;
                worldY-=speed/2;
            }


        }
        else if(gp.keyH.downPressed && press_delay<=0)
        {
            if(spriteNum!=2)
            {
                press_delay=5;

                if(spriteNum>=3 && spriteNum<=5)
                    spriteNum=(--spriteNum)%8;
                else
                spriteNum=(++spriteNum)%8;
            }
            else
                worldY+=speed;


        }
        else if(gp.keyH.rightPressed && press_delay<=0)
        {
            if(spriteNum!=4)
            {
                press_delay=5;

                if(spriteNum>=5 && spriteNum<=7)
                    spriteNum=(--spriteNum)%8;
                else
                spriteNum=(++spriteNum)%8;
            }
            else
                worldX+=speed;


        }
        else if(gp.keyH.upPressed && press_delay<=0)
        {
            if(spriteNum!=6)
            {
                press_delay=5;
                if(spriteNum==7 || spriteNum<=1)
                    spriteNum=(--spriteNum)%8;
                else
                spriteNum=(++spriteNum)%8;
            }
            else
                worldY-=speed;


        }
        else if(gp.keyH.leftPressed && press_delay<=0)
        {
            if(spriteNum!=0)
            {
                press_delay=5;

                if(spriteNum>=1 && spriteNum<=3)
                    spriteNum=(--spriteNum)%8;
                else
                spriteNum=(++spriteNum)%8;
            }
            else
                worldX-=speed;


        }


        if(press_delay>0)
            press_delay--;
    }

    public void draw(Graphics2D g2)
    {
        g2.drawImage(all[spriteNum], gp.player.screenX, gp.player.screenY, height, width, null);
    }
}

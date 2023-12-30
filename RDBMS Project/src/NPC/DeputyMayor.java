package NPC;

import MainPackage.GamePanel;
import entity.Entity;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class DeputyMayor extends Entity {

    int id=5;

    String movement []={"left", "stop", "down", "stop", "left", "stop", "right", "up", "right" ,"stop", "up" , "stop", "left", "stop"};
    int distance[]={596, -400 , 1068, -500, 532, -200, 531, 144,961, -450, 924, -300, 364, -100 };



    public int current_movement=0, current_distance=0;


    public DeputyMayor(GamePanel gp) {
        super(gp);
        speed=1;

        worldX=2200;
        worldY=1100;

        height=55;
        width=55;

        getImage();
    }


    public void getImage()
    {


        try
        {
            for(int i=0; i<4; i++)
            {
                left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/"+id+"/left"+(i+1)+".png"));
                up[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/"+id+"/up"+(i+1)+".png"));
                right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/"+id+"/right"+(i+1)+".png"));
                down[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/"+id+"/down"+(i+1)+".png"));


            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }



    public void update()
    {

        if(current_state=="not quest") {
            if (current_distance == 0) {
                if (movement[current_movement] != "stop")
                    direction = movement[current_movement];

                current_distance = distance[current_movement];


                current_movement=(++current_movement)% movement.length;
            } else {
                if (current_distance > 0)
                    current_distance--;
                else if (current_distance < 0)
                    current_distance++;

            }




            if (current_distance >= 0)
            {
                switch (direction) {
                    case "up":
                        worldY -= speed;

                        break;


                    case "down":
                        worldY += speed;

                        break;

                    case "left":

                        worldX -= speed;
                        break;
                    case "right":

                        worldX += speed;
                        break;
                }

                spriteCounter++;

                if (spriteCounter > 10) {
                    spriteNum = (++spriteNum) % 4;
                    spriteCounter = 0;
                }

            }
            else
                spriteNum=0;


        }
        else if(current_state=="quest 3 start")
        {

            if (spriteCounter > 10) {
                spriteNum = (++spriteNum) % 4;
                spriteCounter = 0;
            }

            spriteCounter++;


            if(worldY>1122 && direction=="up")
                worldY-=speed;
            else if(worldY<=1122 && direction=="up")
                direction="right";

            if(worldX<1880 && direction=="right")
                worldX+=speed;
           else if(worldX>=1880 && direction=="right")
                spriteNum=0;



        }


    }

    public void draw(Graphics2D g2)
    {

        int screenX=worldX-gp.player.worldX+gp.player.screenX;
        int screenY=worldY-gp.player.worldY+gp.player.screenY;


        if(worldX+gp.tileSize>gp.player.worldX-gp.player.screenX &&
                worldX-gp.tileSize< gp.player.worldX+gp.player.screenX &&
                worldY+gp.tileSize>gp.player.worldY - gp.player.screenY &&
                worldY- gp.tileSize<gp.player.worldY +gp.player.screenY) {
            BufferedImage image = null;


            if (direction == "up")
                image = up[spriteNum];
            else if (direction == "down")
                image = down[spriteNum];
            else if (direction == "right")
                image = right[spriteNum];
            else if (direction == "left")
                image = left[spriteNum];

            g2.drawImage(image, screenX, screenY,  height, width, null);


        }
    }
}

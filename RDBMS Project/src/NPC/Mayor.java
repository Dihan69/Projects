package NPC;

import MainPackage.GamePanel;
import entity.Entity;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class Mayor extends Entity {

    int id=11;

    String movement []={"left", "stop", "down", "stop", "right", "stop","up","stop", "left", "stop"};
    int distance[]={200, -300, 100, -250, 400, -280, 100, -150, 200, -200 };

    String temp_direction;



    public int current_movement=0, current_distance=0;


    public Mayor(GamePanel gp) {
        super(gp);
        speed=1;

        worldX=2200;
        worldY=1050;

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
        else if(current_state=="dialogue start")
        {


            temp_direction=direction;

            int x=0, y=0;

            if(gp.player.currentDialogue=="boy")
            {
                x=gp.player.BoyWorldX;
                y=gp.player.BoyWorldY;
            }
            else if(gp.player.currentDialogue=="girl")
            {
                x=gp.player.GirlWorldX;
                y=gp.player.GirlWOrldY;
            }

            if(x-worldX<-20 )
            {
                direction="left";

                if(gp.player.currentDialogue=="boy")
                gp.player.direction="right";
                else if(gp.player.currentDialogue=="girl")
                    gp.player.girlDirection="right";

            }
            else  if(x-worldX>20 )
            {
                direction="right";

                if(gp.player.currentDialogue=="boy")
                    gp.player.direction="left";
                else if(gp.player.currentDialogue=="girl")
                    gp.player.girlDirection="left";

            }
            else  if(y-worldY<-20 )
            {
                direction="up";

                if(gp.player.currentDialogue=="boy")
                    gp.player.direction="down";
                else if(gp.player.currentDialogue=="girl")
                    gp.player.girlDirection="down";

            }
            else  if(y-worldY>20 )
            {
                direction="down";

                if(gp.player.currentDialogue=="boy")
                    gp.player.direction="up";
                else if(gp.player.currentDialogue=="girl")
                    gp.player.girlDirection="up";

            }

            if(gp.quest.current_active_quest_id==3 && gp.quest.quest[3].current_phase==0)
                direction="left";

            current_state="dialogue going";




        }
        else if(current_state=="dialogue end")
        {
            direction=temp_direction;
            current_state="not quest";
        }



    }



    public void draw(Graphics2D g2)
    {

         screenX=worldX-gp.player.worldX+gp.player.screenX;
         screenY=worldY-gp.player.worldY+gp.player.screenY;


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

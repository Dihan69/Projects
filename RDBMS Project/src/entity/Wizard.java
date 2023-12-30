package entity;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

public class Wizard extends Entity{
    String movement []={"left", "stop", "down", "stop", "right", "stop","up","stop", "left", "stop"};
    int distance[]={100, -300, 100, -250, 200, -280, 100, -150, 100, -200 };


    public String temp_direction;

    BufferedImage [] beam_left=new BufferedImage[3];
    BufferedImage [] beam_right=new BufferedImage[3];
    BufferedImage [] beam_down=new BufferedImage[3];
    BufferedImage [] beam_up=new BufferedImage[3];

    BufferedImage [] slash_left=new BufferedImage[4];
    BufferedImage [] slash_right=new BufferedImage[4];
    BufferedImage [] slash_down=new BufferedImage[4];
    BufferedImage [] slash_up=new BufferedImage[4];

    public int current_movement=0, current_distance=0;

    int max_slash=8;
    public Entity slash_effect[]=new Entity[max_slash];

    BufferedImage slash_effect_left, slash_effect_right, slash_effect_up, slash_effect_down;
    BufferedImage beam[]=new BufferedImage[10];
    int max_beam=20;

    public Entity beam_effect[]= new Entity[max_beam];
    public Wizard(GamePanel gp) {
        super(gp);
        speed=1;

        worldX=7672;
        worldY=1132;


        height=75;
        width=75;

        getImage();
    }


    public void getImage()
    {


        try
        {
            for(int i=0; i<4; i++)
            {
                left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/walk/left/"+(i+1)+".png"));
                up[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/walk/up/"+(i+1)+".png"));
                right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/walk/right/"+(i+1)+".png"));
                down[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/walk/down/"+(i+1)+".png"));

                slash_left[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/attack/slash/left/"+(i+1)+".png"));
                slash_right[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/attack/slash/right/"+(i+1)+".png"));
                slash_up[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/attack/slash/up/"+(i+1)+".png"));
                slash_down[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/attack/slash/down/"+(i+1)+".png"));

            }

            for(int i=0; i<3; i++)
            {
                beam_left[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/attack/beam/left/"+(i+1)+".png"));
                beam_right[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/attack/beam/right/"+(i+1)+".png"));
                beam_up[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/attack/beam/up/"+(i+1)+".png"));
                beam_down[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/attack/beam/down/"+(i+1)+".png"));

            }

            for(int i=0; i<10; i++)
                beam[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/effect/beam/"+(i+1)+".png"));

            slash_effect_left= ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/effect/slash/left/1.png"));
            slash_effect_up= ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/effect/slash/up/1.png"));
            slash_effect_down= ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/effect/slash/down/1.png"));
            slash_effect_right= ImageIO.read(getClass().getClassLoader().getResourceAsStream("NPC/wizard/effect/slash/right/1.png"));

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }



    public void update()
    {
        if(current_state!="enemy")

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
        else
        {
            enemy_logic();
        }


    }

    int event_counter=0;

    public void enemy_logic()
    {
        move_beam();
        move_slash();

        if(event_counter==0)
        {
            Random random = new Random();

            int event = random.nextInt(2);

            if(event==1)
            {
                fire_slash();
                action="slash";
                spriteNum=0;
            }
            else
            {
                fire_beam();
                action="beam";
                spriteNum=0;
            }

            event_counter=200;
        }

        if(event_counter==100)
        {
            if(direction=="up")
            {
                worldX=2180;
                worldY=960;
                direction="left";
            }
            else if(direction=="left")
            {
                worldX=1700;
                worldY=764;

                direction="down";
            }
            else if(direction=="down")
            {
                worldX=1148;
                worldY=960;
                direction="right";
            }
            else if(direction=="right")
            {
                worldX=1704;
                worldY=1192;
                direction="up";
            }
        }

        if(event_counter>0)
            event_counter--;

        spriteCounter++;


         if(action=="slash")
        {
            if(spriteCounter>8)
            {
                spriteCounter=0;

                if(spriteNum>=3)
                {
                    action="idle";
                    spriteNum=0;
                }
                else
                    spriteNum++;
            }
        }
        else if(action=="beam")
        {
            if(spriteCounter>8)
            {
                spriteCounter=0;

                if(spriteNum>=2)
                {
                    action="idle";
                    spriteNum=0;
                }
                else
                    spriteNum++;
            }
        }



    }


    public void fire_slash()
    {
        for (int i = 0; i < max_slash; i++) {

            slash_effect[i] = new Entity(gp);

            slash_effect[i].current_health=80;

            slash_effect[i].height=85;
            slash_effect[i].width=85;
            slash_effect[i].current_health=120;
            slash_effect[i].speed=8;

        }

        slash_effect[0].worldX=gp.player.GirlWorldX-300;
        slash_effect[0].worldY=gp.player.GirlWOrldY-150;
        slash_effect[0].direction="right";

        slash_effect[1].worldX=gp.player.GirlWorldX+300;
        slash_effect[1].worldY=gp.player.GirlWOrldY+150;
        slash_effect[1].direction="left";

        slash_effect[2].worldX=gp.player.BoyWorldX-300;
        slash_effect[2].worldY=gp.player.BoyWorldY-150;
        slash_effect[2].direction="right";

        slash_effect[3].worldX=gp.player.BoyWorldX+300;
        slash_effect[3].worldY=gp.player.BoyWorldY+150;
        slash_effect[3].direction="left";


        slash_effect[4].worldX=gp.player.GirlWorldX-150;
        slash_effect[4].worldY=gp.player.GirlWOrldY-250;
        slash_effect[4].direction="down";

        slash_effect[5].worldX=gp.player.GirlWorldX+150;
        slash_effect[5].worldY=gp.player.GirlWOrldY+250;
        slash_effect[5].direction="up";

        slash_effect[6].worldX=gp.player.BoyWorldX-150;
        slash_effect[6].worldY=gp.player.BoyWorldY-250;
        slash_effect[6].direction="down";

        slash_effect[7].worldX=gp.player.BoyWorldX+150;
        slash_effect[7].worldY=gp.player.BoyWorldY+250;
        slash_effect[7].direction="up";
    }

    public void fire_beam() {
        for (int i = 0; i < max_beam; i++) {

            beam_effect[i] = new Entity(gp);

            beam_effect[i].current_health=80;

            beam_effect[i].height=35;
            beam_effect[i].width=35;

            Random random= new Random();

            int X = random.nextInt(120);
            int Y = random.nextInt(60);

            if (direction == "right" ) {
                beam_effect[i].worldX=1050+X;
                beam_effect[i].worldY=600+i*Y;
                beam_effect[i].direction="right";
                beam_effect[i].speed=11;
            }
            else    if (direction == "left" ) {
                beam_effect[i].worldX=2230-X;
                beam_effect[i].worldY=600+i*Y;
                beam_effect[i].direction="left";
                beam_effect[i].speed=11;
            }
            else    if (direction == "up" ) {
                beam_effect[i].worldX=1000+i*X;
                beam_effect[i].worldY=1300-Y;
                beam_effect[i].direction="up";

                beam_effect[i].speed=8;
            }
            else if(direction=="down")
            {
                beam_effect[i].worldX=1000+i*X;
                beam_effect[i].worldY=600+Y;
                beam_effect[i].direction="down";
                beam_effect[i].speed=8;
            }

        }
    }

    public void move_beam()
    {
        for(int i=0; i<max_beam; i++)
        {
            if(beam_effect[i]!=null)
            {
                if(direction=="left")
                    beam_effect[i].worldX-=beam_effect[i].speed;
                else if(direction=="right")
                    beam_effect[i].worldX+=beam_effect[i].speed;
                else if(direction=="up")
                    beam_effect[i].worldY-=beam_effect[i].speed;
                else if(direction=="down")
                    beam_effect[i].worldY+=beam_effect[i].speed;

                beam_effect[i].spriteCounter++;

                if(beam_effect[i].spriteCounter>8)
                {
                    beam_effect[i].spriteCounter=0;

                    if(beam_effect[i].spriteNum<=9)
                        beam_effect[i].spriteNum++;
                    else
                    {
                        beam_effect[i]=null;
                    }


                }
            }
        }
    }

    public void move_slash()
    {
        for(int i=0; i<max_slash; i++)
        {
            if(slash_effect[i]!=null)
            {
                if(slash_effect[i].direction=="left")
                    slash_effect[i].worldX-=slash_effect[i].speed;
                else if(slash_effect[i].direction=="right")
                    slash_effect[i].worldX+=slash_effect[i].speed;
                else if(slash_effect[i].direction=="up")
                    slash_effect[i].worldY-=slash_effect[i].speed;
                else if(slash_effect[i].direction=="down")
                    slash_effect[i].worldY+=slash_effect[i].speed;

              if(slash_effect[i].current_health>0)
                  slash_effect[i].current_health--;
              else
                  slash_effect[i]=null;
            }
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

        if(current_state!="enemy")
         {
        if (direction == "up")
            image = up[spriteNum];
        else if (direction == "down")
            image = down[spriteNum];
        else if (direction == "right")
            image = right[spriteNum];
        else if (direction == "left")
            image = left[spriteNum];
         }
        else
        {
            if(action=="idle")
            {
                if (direction == "up")
                    image = up[spriteNum];
                else if (direction == "down")
                    image = down[spriteNum];
                else if (direction == "right")
                    image = right[spriteNum];
                else if (direction == "left")
                    image = left[spriteNum];
            }
            else if(action=="slash")
            {
                if (direction == "up")
                    image = slash_up[spriteNum];
                else if (direction == "down")
                    image = slash_down[spriteNum];
                else if (direction == "right")
                    image = slash_right[spriteNum];
                else if (direction == "left")
                    image = slash_left[spriteNum];
            }
            else if(action=="beam")
            {
                if (direction == "up")
                    image = beam_up[spriteNum];
                else if (direction == "down")
                    image = beam_down[spriteNum];
                else if (direction == "right")
                    image = beam_right[spriteNum];
                else if (direction == "left")
                    image = beam_left[spriteNum];
            }
        }




            g2.drawImage(image, screenX, screenY,  height, width, null);


        }

        draw_beam(g2);
        draw_slash(g2);
    }

    public void draw_beam(Graphics2D g2)
    {
        for(int i=0; i<max_beam; i++)
        {
            if(beam_effect[i]!=null)
            {
                int worldX=beam_effect[i].worldX;
                int worldY=beam_effect[i].worldY;


                int screenX=worldX-gp.player.worldX+gp.player.screenX;
                int screenY=worldY-gp.player.worldY+gp.player.screenY;



                if(worldX+gp.tileSize>gp.player.worldX-gp.player.screenX &&
                        worldX-gp.tileSize< gp.player.worldX+gp.player.screenX &&
                        worldY+gp.tileSize>gp.player.worldY - gp.player.screenY &&
                        worldY- gp.tileSize<gp.player.worldY +gp.player.screenY) {
                    BufferedImage image=null;

                    if(beam_effect[i].spriteNum<=9)
                        image = beam[beam_effect[i].spriteNum];


                    g2.drawImage(image, screenX, screenY,  beam_effect[i].height, beam_effect[i].width, null);


                }
            }
        }

    }

    public void draw_slash(Graphics2D g2)
    {
        for(int i=0; i<max_slash; i++)
        {
            if(slash_effect[i]!=null)
            {
                int worldX=slash_effect[i].worldX;
                int worldY=slash_effect[i].worldY;


                int screenX=worldX-gp.player.worldX+gp.player.screenX;
                int screenY=worldY-gp.player.worldY+gp.player.screenY;



                if(worldX+gp.tileSize>gp.player.worldX-gp.player.screenX &&
                        worldX-gp.tileSize< gp.player.worldX+gp.player.screenX &&
                        worldY+gp.tileSize>gp.player.worldY - gp.player.screenY &&
                        worldY- gp.tileSize<gp.player.worldY +gp.player.screenY) {
                    BufferedImage image=null;

                    if (slash_effect[i].direction == "up")
                        image = slash_effect_up;
                    else if (slash_effect[i].direction == "down")
                        image = slash_effect_down;
                    else if (slash_effect[i].direction == "left")
                        image = slash_effect_left;
                    else if (slash_effect[i].direction == "right")
                        image = slash_effect_right;


                    g2.drawImage(image, screenX, screenY,  slash_effect[i].height, slash_effect[i].width, null);


                }
            }
        }

    }

}

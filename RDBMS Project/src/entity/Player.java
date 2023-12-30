package entity;

import MainPackage.GamePanel;
import MainPackage.KeyHandler;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class Player extends Entity{



    KeyHandler keyH;

    public int BoyWorldX =1000, GirlWorldX=1100;
    public int BoyWorldY=7100, GirlWOrldY=7200;



    public final int screenX;
    public final int screenY;

    public int girl_max_health, girl_current_health;

    public String currentActive="boy";

    public int switchdelay=0;


    public String  girlDirection="down";

    public String girl_action="walk";

    public int[] inventory= new int[40];

    public int invetory_size=9;

    public String currentDialogue="";

    public int sword_power;

    public int boyspriteNum=0, girlspriteNum=0;

    public int girl_last_hit_time=0;

    public int boyspriteCounter=0, girlspriteCounter=0;

    public BufferedImage up_girl[]= new BufferedImage[4];
    public BufferedImage right_girl[]= new BufferedImage[4];
    public BufferedImage left_girl[]= new BufferedImage[4];
    public BufferedImage down_girl[]= new BufferedImage[4];

    public BufferedImage up_attack_boy[]=new BufferedImage[4];
    public BufferedImage down_attack_boy[]=new BufferedImage[4];
    public BufferedImage right_attack_boy[]=new BufferedImage[4];
    public BufferedImage left_attack_boy[]=new BufferedImage[4];

    public BufferedImage up_attack_girl[]=new BufferedImage[4];
    public BufferedImage down_attack_girl[]=new BufferedImage[4];
    public BufferedImage right_attack_girl[]=new BufferedImage[4];
    public BufferedImage left_attack_girl[]=new BufferedImage[4];

    public Player(GamePanel gp, KeyHandler keyH)
    {
        super(gp);
        this.gp=gp;
        this.keyH=keyH;
        screenX=gp.screenWidth/2-gp.tileSize/2;
        screenY=gp.screenHeight/2-gp.tileSize/2;



        solidArea= new Rectangle(19, 26, 21,16 );

        setDefaultValues();
        getPlayerImage();
    }

    public void setDefaultValues()
    {

        speed=4;
        height=58;
        width=58;
        sword_power=5;

        direction="down";

        max_health=50;
        current_health=max_health-30;

        girl_max_health=50;
        girl_current_health=girl_max_health-40;
        last_hit_time=0;




    }



    public void getPlayerImage()
    {
      /*  for(int i=0; i<4; i++)
        {
            left[i]= new BufferedImage;
            down[i]= new BufferedImage;
            up[i]= new BufferedImage;
            right[i]= new BufferedImage;
        }*/

        try
        {
            for(int i=0; i<4; i++)
            {
                left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Player Boy/left"+(i+1)+".png"));
                up[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Player Boy/up"+(i+1)+".png"));
                right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Player Boy/right"+(i+1)+".png"));
                down[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Player Boy/down"+(i+1)+".png"));

                left_attack_boy[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Boy Attack/left"+i+".png"));
                up_attack_boy[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Boy Attack/up"+i+".png"));
                down_attack_boy[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Boy Attack/down"+i+".png"));
                right_attack_boy[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Boy Attack/right"+i+".png"));

                left_girl[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Player Girl/left"+(i+1)+".png"));
                up_girl[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Player Girl/up"+(i+1)+".png"));
                right_girl[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Player Girl/right"+(i+1)+".png"));
                down_girl[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Player Girl/down"+(i+1)+".png"));

                left_attack_girl[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Girl Attack/left"+i+".png"));
                up_attack_girl[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Girl Attack/up"+i+".png"));
                down_attack_girl[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Girl Attack/down"+i+".png"));
                right_attack_girl[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Player/Girl Attack/right"+(i+1)+".png"));
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public boolean done=false;
    public void update()
    {
        for(int i=0; i<invetory_size; i++)
            inventory[i]=5;


        if(gp.gameState==gp.playState) {
            boy_update();

            girl_update();
        }
        if(keyH.spacePressed && switchdelay==0)
        {
            if(currentActive=="boy")
                currentActive="girl";
            else
                currentActive="boy";
            switchdelay=30;
        }
        else if(switchdelay>0)
            switchdelay--;

        if(keyH.b_pressed && gp.gameState==gp.playState)
        {
            gp.gameState=gp.boatState;

            gp.boat.worldX=5000;
            gp.boat.worldY=7000;
        }

        if(currentActive=="boy")
        {
            worldX=BoyWorldX;
            worldY=BoyWorldY;
        }
        else
        {
            worldX=GirlWorldX;
            worldY=GirlWOrldY;
        }

        if(direction =="up" || direction =="down")
            speed=4;
        else
            speed=4;

        System.out.println(BoyWorldX+","+BoyWorldY);
      //  System.out.println(screenX+","+screenY);
    }

    void boy_update()
    {

        if(action=="walk")
        {
            if(keyH.a_pressed || keyH.d_pressed || keyH.s_pressed || keyH.w_pressed ||  keyH.LctrlPressed) {


                    if (keyH.w_pressed == true) {

                        direction = "up";

                    } else if (keyH.s_pressed == true) {

                        direction = "down";
                    } else if (keyH.d_pressed == true) {

                        direction = "right";
                    } else if (keyH.a_pressed == true) {

                        direction = "left";
                    }
                    else if(keyH.LctrlPressed)
                    {
                        action="attack";
                        boyspriteCounter=0;
                        boyspriteNum=0;
                        return;
                    }

                    collisonOn = false;

                    if (gp.playerGameCollisonOn == true)
                        gp.cChecker.checkTilePlayer(this, false);

                    if (collisonOn == false) {
                        switch (direction) {
                            case "up":
                                BoyWorldY -= speed;
                                break;
                            case "down":
                                BoyWorldY += speed;
                                break;
                            case "left":
                                BoyWorldX -= speed;
                                break;
                            case "right":

                                BoyWorldX += speed;
                                break;
                        }
                    }

                if(gp.playerGameCollisonOn==true)
                {
                    gp.cChecker.check_decoraton_player(false, this);
                    gp.cChecker.check_object_player(false, this);
                }

                    boyspriteCounter++;

                    if (boyspriteCounter > 10) {
                        boyspriteNum = (++boyspriteNum) % 4;
                        boyspriteCounter = 0;
                    }




            }
        }
        else if(action=="attack") {

            boyspriteCounter++;

            if (boyspriteCounter > 4 && boyspriteNum < 3) {
                boyspriteNum++;
                boyspriteCounter = 0;
            }
            else if(boyspriteNum==3 && boyspriteCounter>12)
            {
                boyspriteNum=0;
                boyspriteCounter=0;
                action="walk";

            }
        }

        if(last_hit_time>0)
            last_hit_time--;


    }

    void girl_update()
    {
        if(girl_action=="walk")
        {
            if(keyH.upPressed || keyH.downPressed || keyH.leftPressed || keyH.rightPressed || keyH.RctrlPressed) {
                if (keyH.upPressed == true) {

                    girlDirection = "up";

                }
                else if (keyH.downPressed == true) {

                    girlDirection = "down";
                }
                else if (keyH.rightPressed == true) {

                    girlDirection = "right";
                }

                else if (keyH.leftPressed == true) {

                    girlDirection = "left";
                }
                else if(keyH.RctrlPressed)
                {
                    girl_action="attack";
                    girlspriteCounter=0;
                    girlspriteNum=0;
                    return;
                }

                collisonOn=false;

                if(gp.playerGameCollisonOn==true)
                    gp.cChecker.checkTilePlayer(this, true);

                if(collisonOn==false)
                {
                    switch(girlDirection){
                        case "up":
                            GirlWOrldY -= speed;
                            break;
                        case "down":
                            GirlWOrldY += speed;
                            break;
                        case "left":
                            GirlWorldX-= speed;
                            break;
                        case "right":

                            GirlWorldX+= speed;
                            break;
                    }
                }

                if(gp.playerGameCollisonOn==true)
                {
                    gp.cChecker.check_object_player(true, this);
                    gp.cChecker.check_decoraton_player(true, this);
                }






                girlspriteCounter++;

                if (girlspriteCounter > 10) {
                    girlspriteNum = (++girlspriteNum) % 4;
                    girlspriteCounter = 0;
                }
            }
        }
        else if(girl_action=="attack")
        {
            girlspriteCounter++;

            if (girlspriteCounter > 4 && girlspriteNum < 3) {
                girlspriteNum++;
                girlspriteCounter = 0;
            }
            else if(girlspriteNum==3 && girlspriteCounter>12)
            {
                girlspriteNum=0;
                girlspriteCounter=0;
                girl_action="walk";

            }
        }

        if(girl_last_hit_time>0)
            girl_last_hit_time--;
    }

    public void draw(Graphics2D g2)
    {
       BufferedImage image = null;

       if(direction =="up")
       {
           if(action=="walk")
           image= up[boyspriteNum];
           else if(action=="attack")
               image= up_attack_boy[boyspriteNum];

       }
       else if(direction =="down")
       {
           if(action=="walk")
           image= down[boyspriteNum];
           else if(action=="attack")
               image= down_attack_boy[boyspriteNum];

       }
       else if(direction =="right")
       {
           if(action=="walk")
           image=right[boyspriteNum];
           else if(action=="attack")
               image= right_attack_boy[boyspriteNum];

       }
       else if(direction =="left")
       {
           if(action=="walk")
           image=left[boyspriteNum];
           else if(action=="attack")
               image= left_attack_boy[boyspriteNum];
       }

       if(last_hit_time%2==0)
       {
           if(currentActive=="boy")
               g2.drawImage(image, screenX, screenY,  height, width, null);
           else
               g2.drawImage(image, screenX+ (BoyWorldX-GirlWorldX), screenY+ (BoyWorldY-GirlWOrldY), height, width, null);
       }


        if(girlDirection=="up")
        {
            if(girl_action=="walk")
            image= up_girl[girlspriteNum];
            else if (girl_action=="attack")
                image = up_attack_girl[girlspriteNum];
        }
        else if(girlDirection=="down")
        {
            if(girl_action=="walk")
            image= down_girl[girlspriteNum];
            else if (girl_action=="attack")
                image = down_attack_girl[girlspriteNum];

        }
        else if(girlDirection=="right")
        {
            if(girl_action=="walk")
            image=right_girl[girlspriteNum];
            else if (girl_action=="attack")
                image = right_attack_girl[girlspriteNum];

        }
        else if(girlDirection=="left")
        {
            if(girl_action=="walk")
            image=left_girl[girlspriteNum];
            else if (girl_action=="attack")
                image = left_attack_girl[girlspriteNum];
        }

        if(girl_last_hit_time%2==0)
        {
            if(currentActive=="girl")
                g2.drawImage(image, screenX, screenY,  height, width, null);
            else
                g2.drawImage(image, screenX+(GirlWorldX-BoyWorldX), screenY+(GirlWOrldY-BoyWorldY), height, width, null);
        }
    }





}

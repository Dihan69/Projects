package Enemy;

import MainPackage.GamePanel;
import entity.Entity;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

import static java.lang.Math.abs;
import static java.lang.Math.max;

public class Hedgehog extends Entity {

    public BufferedImage [] idle_up_left = new BufferedImage[4];
    public BufferedImage [] idle_up_right = new BufferedImage[4];
    public BufferedImage [] idle_down_left = new BufferedImage[4];
    public BufferedImage [] idle_down_right = new BufferedImage[4];
    public BufferedImage [] idle_left = new BufferedImage[4];
    public BufferedImage [] idle_right = new BufferedImage[4];

    public BufferedImage [] walk_up_left = new BufferedImage[4];
    public BufferedImage [] walk_up_right = new BufferedImage[4];
    public BufferedImage [] walk_down_left = new BufferedImage[4];
    public BufferedImage [] walk_down_right = new BufferedImage[4];
    public BufferedImage [] walk_left = new BufferedImage[4];
    public BufferedImage [] walk_right = new BufferedImage[4];

    public BufferedImage [] attack_up_left = new BufferedImage[4];
    public BufferedImage [] attack_up_right = new BufferedImage[4];
    public BufferedImage [] attack_down_left = new BufferedImage[4];
    public BufferedImage [] attack_down_right = new BufferedImage[4];
    public BufferedImage [] attack_left = new BufferedImage[4];
    public BufferedImage [] attack_right = new BufferedImage[4];

    public int eventCounter=0;

    boolean target_girl=false;

    public boolean playerInRange=false;



    public Hedgehog(GamePanel gp)
    {
        super(gp);
        speed=2;
        solidArea=new Rectangle(20, 20, 84-20, 60-20);

        height=100;
        width=80;

        damageSolidArea=new Rectangle(0,0,height,width);

        action="idle";
        direction="left";
        max_health=30;
        current_health=max_health;
        hit_damage=2;

        getImage();

    }

    public void getImage()
    {
        try
        {
            for(int i=0; i<4; i++)
            {
                idle_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/idle/up-left/"+(i+1)+".png"));
                idle_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/idle/up-right/"+(i+1)+".png"));
                idle_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/idle/down-left/"+(i+1)+".png"));
                idle_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/idle/down-right/"+(i+1)+".png"));
                idle_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/idle/left/"+(i+1)+".png"));
                idle_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/idle/right/"+(i+1)+".png"));

                attack_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/attack/up-left/"+(i+1)+".png"));
                attack_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/attack/up-right/"+(i+1)+".png"));
                attack_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/attack/down-left/"+(i+1)+".png"));
                attack_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/attack/down-right/"+(i+1)+".png"));
                attack_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/attack/left/"+(i+1)+".png"));
                attack_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/attack/right/"+(i+1)+".png"));

                walk_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/walk/up-left/"+(i+1)+".png"));
                walk_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/walk/up-right/"+(i+1)+".png"));
                walk_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/walk/down-left/"+(i+1)+".png"));
                walk_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/walk/down-right/"+(i+1)+".png"));
                walk_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/walk/left/"+(i+1)+".png"));
                walk_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Hedgehog/walk/right/"+(i+1)+".png"));



            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void update()
    {
        if(playerInRange==false)
        {
            if (eventCounter == 0)
            {
                Random random = new Random();

                int event = random.nextInt(2);

                eventCounter = 400;

                if (event == 0)
                    action = "walk";
                else
                    action = "idle";
            }
            else
            {
                if (eventCounter % 80 == 0 && action == "walk")
                    direction_change_logic();

                eventCounter--;
            }


            if (action == "walk")
                normal_movement_logic();

            spriteCounter++;

            if (spriteCounter > 10) {
                spriteNum = (++spriteNum) % 4;
                spriteCounter = 0;
            }
        }
        else
            target_player_logic();


        player_range_checker_logic();

        if (playerInRange == false)
            speed = 2;
        else speed = 4;

        if(last_hit_time>0)
            last_hit_time--;

        if(action=="idle" || action=="attack-idle")
            gp.cChecker.check_player_enemy_hit(this);
        if(action=="attack")
            gp.cChecker.check_enemy_damage_player(this);


    }

    public void draw(Graphics2D g2)
    {


        int screenX=worldX-gp.player.worldX+gp.player.screenX;
        int screenY=worldY-gp.player.worldY+gp.player.screenY;


        if(worldX+gp.tileSize>gp.player.worldX-gp.player.screenX &&
                worldX-gp.tileSize< gp.player.worldX+gp.player.screenX &&
            worldY+gp.tileSize>gp.player.worldY - gp.player.screenY &&
            worldY- gp.tileSize<gp.player.worldY +gp.player.screenY)
        {
            BufferedImage image=null;

            if(action=="idle" || action=="attack-idle")
            {
                if(direction=="up-left")
                    image=idle_up_left[spriteNum];
                else if(direction=="up-right")
                    image=idle_up_right[spriteNum];
                else if(direction=="down-left")
                    image=idle_down_left[spriteNum];
                else if(direction=="down-right")
                    image=idle_down_right[spriteNum];
                else if(direction=="left")
                    image=idle_left[spriteNum];
                else if(direction=="right")
                    image=idle_right[spriteNum];


            }
            else if(action=="walk")
        {
            if(direction=="up-left")
                image=walk_up_left[spriteNum];
            else if(direction=="up-right")
                image=walk_up_right[spriteNum];
            else if(direction=="down-left")
                image=walk_down_left[spriteNum];
            else if(direction=="down-right")
                image=walk_down_right[spriteNum];
            else if(direction=="left")
                image=walk_left[spriteNum];
            else if(direction=="right")
                image=walk_right[spriteNum];


        }
            else if(action=="attack")
            {
                if(direction=="up-left")
                    image=attack_up_left[spriteNum];
                else if(direction=="up-right")
                    image=attack_up_right[spriteNum];
                else if(direction=="down-left")
                    image=attack_down_left[spriteNum];
                else if(direction=="down-right")
                    image=attack_down_right[spriteNum];
                else if(direction=="left")
                    image=attack_left[spriteNum];
                else if(direction=="right")
                    image=attack_right[spriteNum];
            }

            g2.drawImage(image, screenX, screenY,  height, width, null);

            if(last_hit_time>0)
            {
                int outline_width = 2, hp_bar_width = 35, hp_bar_start = 20;

                double oneScale = (double) hp_bar_width / max_health;
                double hpBarValue = oneScale * current_health;

                if (current_health < 0)
                    hpBarValue = 0;

                g2.setColor(new Color(35, 35, 35));
                g2.fillRect(screenX + hp_bar_start - outline_width, screenY - 15 - outline_width, hp_bar_width + outline_width * 2, 10 + outline_width * 2);
                g2.setColor(new Color(255, 0, 30));
                g2.fillRect(screenX + hp_bar_start, screenY - 15, (int) hpBarValue, 10);

            }
        }

    }

    public void locked_moving_area_logic()
    {
        if(worldX<800 || worldX>4200)
            collisonOn=true;
        if(worldY<4000 || worldY>7000)
            collisonOn=true;
    }

    public void target_player_logic()
    {
        int targetX, targetY;

        if (target_girl == false) {
            targetX = gp.player.BoyWorldX;
            targetY = gp.player.BoyWorldY;

        } else {
            targetX = gp.player.GirlWorldX;
            targetY = gp.player.GirlWOrldY;
        }

        if(action=="attack" && eventCounter%30==0) {





            if (targetX < worldX && targetY < worldY) {
                Random random = new Random();

                int event = random.nextInt(4);

                if (event <4)
                    direction = "up-left";
                else
                    direction = "left";
            } else if (targetX < worldX && targetY >= worldY) {
                Random random = new Random();

                int event = random.nextInt(4);

                if (event <4)
                    direction = "down-left";
                else
                    direction = "left";
            } else if (targetX >= worldX && targetY >= worldY) {
                Random random = new Random();

                int event = random.nextInt(4);

                if (event <4)
                    direction = "down-right";
                else
                    direction = "right";
            } else if (targetX >= worldX && targetY < worldY) {
                Random random = new Random();

                int event = random.nextInt(4);

                if (event <4)
                    direction = "up-right";
                else
                    direction = "right";
            }
        }


        if(eventCounter%20==0)
            if(abs(targetY-worldY)<25)
            {
                if(worldX<targetX)
                    direction="right";
                else if(worldX>targetX)
                direction="left";
            }


        if(action=="attack")
        {
            int loop_counter=0;

            while (true) {

            loop_counter++;
            if(loop_counter>1000)
                break;

                switch (direction) {
                    case "up-left":
                        worldY -= speed - 1;
                        worldX -= speed / 2;
                        break;

                    case "up-right":
                        worldY -= speed - 1;
                        worldX += speed / 2;
                        break;

                    case "down-left":
                        worldY += speed - 1;
                        worldX -= speed / 2;
                        break;
                    case "down-right":
                        worldY += speed - 1;
                        worldX += speed / 2;
                        break;
                    case "left":

                        worldX -= speed;
                        break;
                    case "right":

                        worldX += speed;
                        break;
                }

                collisonOn = false;

                gp.cChecker.checkTile(this);
                gp.cChecker.check_decoraton(this);

                locked_moving_area_logic();


                if (collisonOn == false)
                    break;
                else {
                    switch (direction) {
                        case "up-left":
                            worldY += speed - 1;
                            worldX += speed / 2;
                            break;

                        case "up-right":
                            worldY += speed - 1;
                            worldX -= speed / 2;
                            break;

                        case "down-left":
                            worldY -= speed - 1;
                            worldX += speed / 2;
                            break;
                        case "down-right":
                            worldY -= speed - 1;
                            worldX -= speed / 2;
                            break;
                        case "left":

                            worldX += speed;
                            break;
                        case "right":

                            worldX -= speed;
                            break;
                    }

                    direction_change_logic();
                }

            }
        }




        if(eventCounter==600)
        {
            action="attack";
            spriteNum=0;
        }
        else if(eventCounter==590)
            spriteNum=1;
        else if(eventCounter==580)
            spriteNum=2;
        else if(eventCounter<580)
        {

            spriteCounter++;

            if (spriteCounter > 10) {
                if(spriteNum==2)
                    spriteNum=3;
                else if(spriteNum==3)
                    spriteNum=2;

                spriteCounter = 0;
            }
        }
        else if(eventCounter>600)
        {
            spriteCounter++;

            if (spriteCounter > 10) {
                spriteNum = (++spriteNum) % 4;
                spriteCounter = 0;
            }

        }

         if(eventCounter==0)
        {
            eventCounter=800;
            action="attack-idle";
        }

        eventCounter--;




    }

    public void normal_movement_logic()
    {
        int loop_counter=0;

        while (true) {

            loop_counter++;
            if(loop_counter>1000)
                break;

            switch (direction) {
                case "up-left":
                    worldY -= speed - 1;
                    worldX -= speed / 2;
                    break;

                case "up-right":
                    worldY -= speed - 1;
                    worldX += speed / 2;
                    break;

                case "down-left":
                    worldY += speed - 1;
                    worldX -= speed / 2;
                    break;
                case "down-right":
                    worldY += speed - 1;
                    worldX += speed / 2;
                    break;
                case "left":

                    worldX -= speed;
                    break;
                case "right":

                    worldX += speed;
                    break;
            }

            collisonOn = false;

            gp.cChecker.checkTile(this);
            gp.cChecker.check_decoraton(this);

            locked_moving_area_logic();


            if (collisonOn == false)
                break;
            else {
                switch (direction) {
                    case "up-left":
                        worldY += speed - 1;
                        worldX += speed / 2;
                        break;

                    case "up-right":
                        worldY += speed - 1;
                        worldX -= speed / 2;
                        break;

                    case "down-left":
                        worldY -= speed - 1;
                        worldX += speed / 2;
                        break;
                    case "down-right":
                        worldY -= speed - 1;
                        worldX -= speed / 2;
                        break;
                    case "left":

                        worldX += speed;
                        break;
                    case "right":

                        worldX -= speed;
                        break;
                }

                direction_change_logic();
            }

        }
    }

    public void player_range_checker_logic()
    {

        if(playerInRange==false && abs(gp.player.BoyWorldX-worldX)<350 && abs(gp.player.BoyWorldY-worldY)<300)
        {

            eventCounter=600;

            playerInRange=true;
            target_girl=false;
            action="attack";

        }
        else  if( playerInRange==false && abs(gp.player.GirlWorldX-worldX)<350 && abs(gp.player.GirlWOrldY-worldY)<300)
        {


            eventCounter=600;
            playerInRange=true;
            target_girl=true;
            action="attack";


        }
        if(playerInRange==true && (abs(gp.player.BoyWorldX-worldX)>500 || abs(gp.player.BoyWorldY-worldY)>300) && (abs(gp.player.GirlWorldX-worldX)>500 || abs(gp.player.GirlWOrldY-worldY)>300) )
        {
            playerInRange=false;
            action="idle";
            eventCounter=200;
        }
    }

    public void direction_change_logic()
    {
        Random random = new Random();

        int event= random.nextInt(3);



        if(direction=="left")
        {
            if(event==0)
                direction="up-left";
            else if(event==1)
                direction="left";
            else if(event==2)
                direction="down-left";

        }
        else if (direction=="right")
        {
            if(event==0)
                direction="up-right";
            else if(event==1)
                direction="right";
            else if(event==2)
                direction="down-right";
        }
        else if(direction=="up-left")
        {
            if(event==0)
                direction="up-left";
            else if(event==1)
                direction="left";
            else if(event==2)
                direction="up-right";
        }
        else if(direction=="up-right")
        {
            if(event==0)
                direction="up-left";
            else if(event==1)
                direction="right";
            else if(event==2)
                direction="up-right";
        }
        else if(direction=="down-left")
        {
            if(event==0)
                direction="down-left";
            else if(event==1)
                direction="left";
            else if(event==2)
                direction="down-right";

        }
        else if(direction=="down-right")
        {
            if(event==0)
                direction="down-left";
            else if(event==1)
                direction="right";
            else if(event==2)
                direction="down-right";
        }



    }
}

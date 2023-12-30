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

public class Bull extends Entity {

    public BufferedImage[] idle_up_left = new BufferedImage[4];
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

    public BufferedImage [] run_up_left = new BufferedImage[6];
    public BufferedImage [] run_up_right = new BufferedImage[6];
    public BufferedImage [] run_down_left = new BufferedImage[6];
    public BufferedImage [] run_down_right = new BufferedImage[6];
    public BufferedImage [] run_left = new BufferedImage[6];
    public BufferedImage [] run_right = new BufferedImage[6];

    public BufferedImage [] rage_up_left = new BufferedImage[6];
    public BufferedImage [] rage_up_right = new BufferedImage[6];
    public BufferedImage [] rage_down_left = new BufferedImage[6];
    public BufferedImage [] rage_down_right = new BufferedImage[6];
    public BufferedImage [] rage_left = new BufferedImage[6];
    public BufferedImage [] rage_right = new BufferedImage[6];

    public BufferedImage [] attack_up_left = new BufferedImage[4];
    public BufferedImage [] attack_up_right = new BufferedImage[4];
    public BufferedImage [] attack_down_left = new BufferedImage[4];
    public BufferedImage [] attack_down_right = new BufferedImage[4];
    public BufferedImage [] attack_left = new BufferedImage[4];
    public BufferedImage [] attack_right = new BufferedImage[4];

    public int eventCounter=0;

    boolean target_girl=false;

    int rage_counter=0;

    public boolean playerInRange=false;

    public Bull(GamePanel gp)
    {
        super(gp);

        speed=2;
        solidArea=new Rectangle(25,25, 50, 50);


        height=90;
        width=90;
        action="idle";
        direction="left";
        last_hit_time=0;
        max_health=40;
        current_health=max_health;
        hit_damage=3;

        damageSolidArea=new Rectangle(0,0,height,width);

        getImage();
    }
    public void getImage()
    {
        try
        {

            for(int i=0; i<4; i++)
            {
                idle_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/idle/up-left/"+(i+1)+".png"));
                idle_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/idle/up-right/"+(i+1)+".png"));
                idle_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/idle/down-left/"+(i+1)+".png"));
                idle_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/idle/down-right/"+(i+1)+".png"));
                idle_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/idle/left/"+(i+1)+".png"));
                idle_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/idle/right/"+(i+1)+".png"));

                attack_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/attack/up-left/"+(i+1)+".png"));
                attack_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/attack/up-right/"+(i+1)+".png"));
                attack_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/attack/down-left/"+(i+1)+".png"));
                attack_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/attack/down-right/"+(i+1)+".png"));
                attack_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/attack/left/"+(i+1)+".png"));
                attack_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/attack/right/"+(i+1)+".png"));

                walk_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/walk/up-left/"+(i+1)+".png"));
                walk_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/walk/up-right/"+(i+1)+".png"));
                walk_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/walk/down-left/"+(i+1)+".png"));
                walk_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/walk/down-right/"+(i+1)+".png"));
                walk_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/walk/left/"+(i+1)+".png"));
                walk_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/walk/right/"+(i+1)+".png"));

            }

            for(int i=0; i<6; i++)
            {
                run_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/run/up-left/"+(i+1)+".png"));
                run_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/run/up-right/"+(i+1)+".png"));
                run_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/run/down-left/"+(i+1)+".png"));
                run_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/run/down-right/"+(i+1)+".png"));
                run_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/run/left/"+(i+1)+".png"));
                run_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/run/right/"+(i+1)+".png"));


                rage_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/rage/up-left/"+(i+1)+".png"));
                rage_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/rage/up-right/"+(i+1)+".png"));
                rage_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/rage/down-left/"+(i+1)+".png"));
                rage_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/rage/down-right/"+(i+1)+".png"));
                rage_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/rage/left/"+(i+1)+".png"));
                rage_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Bull/rage/right/"+(i+1)+".png"));






            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void update() {
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
        else {

            if(action=="run")
            speed = 4;
            else if(action=="attack")
                speed=5;
        }

        if(last_hit_time>0)
        last_hit_time--;

        gp.cChecker.check_player_enemy_hit(this);

        if(action=="attack")
            hit_damage=3;
        else
            hit_damage=1;

        if(action!="idle" && action!="rage")
        gp.cChecker.check_enemy_damage_player(this);





    }


    public void draw(Graphics2D g2) {

        int screenX=worldX-gp.player.worldX+gp.player.screenX;
        int screenY=worldY-gp.player.worldY+gp.player.screenY;


        if(worldX+gp.tileSize>gp.player.worldX-gp.player.screenX &&
                worldX-gp.tileSize< gp.player.worldX+gp.player.screenX &&
                worldY+gp.tileSize>gp.player.worldY - gp.player.screenY &&
                worldY- gp.tileSize<gp.player.worldY +gp.player.screenY)
        {
            BufferedImage image=null;

            if(action=="idle")
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
            else if(action=="run")
            {
                if(direction=="up-left")
                    image=run_up_left[spriteNum];
                else if(direction=="up-right")
                    image=run_up_right[spriteNum];
                else if(direction=="down-left")
                    image=run_down_left[spriteNum];
                else if(direction=="down-right")
                    image=run_down_right[spriteNum];
                else if(direction=="left")
                    image=run_left[spriteNum];
                else if(direction=="right")
                    image=run_right[spriteNum];
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
            else if(action=="rage")
            {
                if(direction=="up-left")
                    image=rage_up_left[spriteNum];
                else if(direction=="up-right")
                    image=rage_up_right[spriteNum];
                else if(direction=="down-left")
                    image=rage_down_left[spriteNum];
                else if(direction=="down-right")
                    image=rage_down_right[spriteNum];
                else if(direction=="left")
                    image=rage_left[spriteNum];
                else if(direction=="right")
                    image=rage_right[spriteNum];
            }


            g2.drawImage(image, screenX, screenY,  height, width, null);

            //------------------------------------------------
            //DRAW HP BAR
            //--------------------------------------------------
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
    public void locked_moving_area_logic()
    {
        if(worldX<800 || worldX>5630)
            collisonOn=true;
        if(worldY<6870 || worldY>8700)
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

        if((action=="run" && eventCounter%30==0) || (action=="rage")) {





            if (targetX < worldX && targetY < worldY) {

                    direction = "up-left";

            } else if (targetX < worldX && targetY >= worldY) {

                    direction = "down-left";

            } else if (targetX >= worldX && targetY >= worldY) {

                    direction = "down-right";

            } else if (targetX >= worldX && targetY < worldY) {

                    direction = "up-right";

            }
        }

        if(action=="rage" && abs(targetY-worldY)<80)
        {
            if(worldX<targetX)
                direction="right";
            else if(worldX>targetX)
                direction="left";
        }


        if(eventCounter%2==0)
        {
            if(action=="run" && abs(targetY-worldY)<10)
            {
                if(worldX<targetX)
                    direction="right";
                else if(worldX>targetX)
                    direction="left";
            }

            if(action=="run" && abs(targetY-worldY)<80 && abs(targetX-worldX)<150)
            {
                action="attack";
                spriteNum=0;
            }


        }


        if(action=="run")
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
        else if(action=="attack")
        {
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


           if(collisonOn==true)
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

        }






            spriteCounter++;

        if(action=="run")
        {
            if (spriteCounter > 7) {


                spriteNum=(++spriteNum)%6;

                spriteCounter = 0;
            }
        }
        else if(action=="rage")
        {
            if (spriteCounter > 5) {


                if(spriteNum<5)
                    spriteNum++;
                else    if(spriteNum==5)
                {
                    if(rage_counter==2)
                    {
                        rage_counter=0;
                        action="run";
                    }
                    else
                    {
                        spriteNum=0;
                        rage_counter++;
                    }


                }

                spriteCounter = 0;


            }
        }
        else if(action=="attack")
        {
            if (spriteCounter > 10) {


                if(spriteNum<3)
                    spriteNum++;
                else    if(spriteNum==3)
                    action="rage";

                spriteCounter = 0;


            }
        }



        if(eventCounter==0)
        {
            eventCounter=800;

        }
    else
        eventCounter--;




    }



    public void player_range_checker_logic()
    {

        if(playerInRange==false && gp.player.action=="attack" && abs(gp.player.BoyWorldX-worldX)<550 && abs(gp.player.BoyWorldY-worldY)<400)
        {

            eventCounter=600;

            playerInRange=true;
            target_girl=false;
            action="rage";

        }
        else  if( playerInRange==false && gp.player.girl_action=="attack" && abs(gp.player.GirlWorldX-worldX)<550 && abs(gp.player.GirlWOrldY-worldY)<400)
        {


            eventCounter=600;
            playerInRange=true;
            target_girl=true;
            action="rage";


        }
        if(playerInRange==true && (abs(gp.player.BoyWorldX-worldX)>600 || abs(gp.player.BoyWorldY-worldY)>500) && (abs(gp.player.GirlWorldX-worldX)>600 || abs(gp.player.GirlWOrldY-worldY)>500) )
        {
            playerInRange=false;
            action="idle";
            eventCounter=200;
        }
    }


}

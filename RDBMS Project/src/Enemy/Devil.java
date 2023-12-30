package Enemy;

import MainPackage.GamePanel;
import entity.Entity;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

import static java.lang.Math.abs;

public class Devil extends Entity {


    public BufferedImage[] walk_up= new BufferedImage[4];
    public BufferedImage [] walk_down= new BufferedImage[4];
    public BufferedImage [] walk_left= new BufferedImage[4];
    public BufferedImage [] walk_right= new BufferedImage[4];



    boolean playerInRange=false;
    boolean target_girl=false;

    int eventCounter=0;

    public Devil(GamePanel gp) {
        super(gp);

        speed=1;
        solidArea=new Rectangle(5, 5, 41-5, 41-5);




        height=45;
        width=45;

        damageSolidArea=new Rectangle(0,0,height,width);
        action="idle";
        direction="left";
        max_health=10;
        current_health=max_health;
        hit_damage=1;


        getImage();
    }


    public void getImage()
    {
        try
        {
            for(int i=0; i<4; i++) {


                walk_up[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/devil/up/" + (i + 1) + ".png"));
                walk_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/devil/right/" + (i + 1) + ".png"));
                walk_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/devil/left/" + (i + 1) + ".png"));
                walk_down[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/devil/down/" + (i + 1) + ".png"));

            }






        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void update() {

        if (playerInRange == false) {

            if (eventCounter == 0) {
                Random random = new Random();

                int event = random.nextInt(1);

                eventCounter = 200;

                if (event == 0)
                    action = "walk";
                else
                    action = "idle";
            } else {
                if (eventCounter % 60 == 0 && action == "walk") {
                    direction_change_logic();
                }

                eventCounter--;
            }


            if (action == "walk") {

                int loop_counter=0;

                while (true) {

                    loop_counter++;
                    if(loop_counter>1000)
                        break;

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

                    collisonOn = false;

                    gp.cChecker.checkTile(this);


                    if(is_locked==true)
                        locked_moving_area_logic();


                    if (collisonOn == false)
                        break;
                    else {
                        switch (direction) {
                            case "up":
                                worldY += speed;

                                break;


                            case "down":
                                worldY -= speed;

                                break;

                            case "left":

                                worldX += speed;
                                break;
                            case "right":

                                worldX -= speed;
                                break;
                        }
                    }

                    direction_change_logic();
                }


            }
            spriteCounter++;

            if (spriteCounter > 10) {
                spriteNum = (++spriteNum) % 4;


                spriteCounter = 0;
            }
        }
        else
            target_player_logic();

        player_range_checker_logic();

        if(playerInRange==false)
            speed=1;
        else
            speed=2;

        if(last_hit_time>0)
            last_hit_time--;

        gp.cChecker.check_player_enemy_hit(this);

        if(action!="idle")
            gp.cChecker.check_enemy_damage_player(this);

    }

    public void direction_change_logic()
    {
        Random random = new Random();

        int event= random.nextInt(4);

        switch(event){
            case 0:
                direction="up";
                break;
            case 1:
                direction="down";
                break;
            case 2:
                direction="right";
                break;
            case 3:
                direction="left";
                break;
        }
    }

    public int detectionX=100;
    public int detectionY=100;
    public void player_range_checker_logic()
    {

        if(eventCounter>600 || (playerInRange==true && (action=="walk"||action=="attack") && (abs(gp.player.BoyWorldX-worldX)>300 || abs(gp.player.BoyWorldY-worldY)>200) && (abs(gp.player.GirlWorldX-worldX)>300 || abs(gp.player.GirlWOrldY-worldY)>200)) )
        {
            playerInRange=false;
            action="idle";

        }
        else if(playerInRange==false && abs(gp.player.BoyWorldX-worldX)<detectionX && abs(gp.player.BoyWorldY-worldY)<detectionY)
        {

            eventCounter=600;

            playerInRange=true;
            target_girl=false;
            action="walk";

        }
        else  if( playerInRange==false && abs(gp.player.GirlWorldX-worldX)<detectionX && abs(gp.player.GirlWOrldY-worldY)<detectionY)
        {


            eventCounter=600;
            playerInRange=true;
            target_girl=true;
            action="walk";



        }

    }

    public  void target_player_logic()
    {
        int targetX, targetY;

        if (target_girl == false) {
            targetX = gp.player.BoyWorldX;
            targetY = gp.player.BoyWorldY;

        } else {
            targetX = gp.player.GirlWorldX;
            targetY = gp.player.GirlWOrldY;
        }

        if(action=="walk" && eventCounter%8==0) {


            if (targetY > worldY && targetX>worldX)
            {
                Random random=new Random();

                int event= random.nextInt(2);

                if(event==0)
                    direction = "down";
                else
                    direction="right";
            }
            else if (targetY < worldY && targetX>worldX)
            {
                Random random=new Random();

                int event= random.nextInt(2);

                if(event==0)
                    direction = "up";
                else
                    direction="right";
            }
            else if (targetY > worldY && targetX<worldX)
            {
                Random random=new Random();

                int event= random.nextInt(2);

                if(event==0)
                    direction = "down";
                else
                    direction="left";
            }
            else if (targetY < worldY && targetX<worldX)
            {
                Random random=new Random();

                int event= random.nextInt(2);

                if(event==0)
                    direction = "up";
                else
                    direction="left";
            }

        }

        if(eventCounter%10==0)
        {
            if(abs(targetX-worldX)<15)
            {
                if(worldY<targetY)
                    direction="down";
                else if(worldY>targetY)
                    direction="up";
            }

            if(abs(targetY-worldY)<15)
            {
                if(worldX<targetX)
                    direction="right";
                else if(worldX>targetX)
                    direction="left";
            }


        }


        if(action=="walk")
        {
            int loop_counter=0;

            while (true) {

                loop_counter++;
                if(loop_counter>1000)
                    break;

                switch (direction) {
                    case "up":
                        worldY -= speed ;

                        break;


                    case "down":
                        worldY += speed ;

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
                        case "up":
                            worldY += speed ;

                            break;


                        case "down":
                            worldY -= speed ;

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





        if(action=="walk") {
            spriteCounter++;

            if (spriteCounter > 10) {
                spriteNum = (++spriteNum) % 4;

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


    public void draw(Graphics2D g2) {
        int screenX = worldX - gp.player.worldX + gp.player.screenX;
        int screenY = worldY - gp.player.worldY + gp.player.screenY;


        if (worldX + gp.tileSize > gp.player.worldX - gp.player.screenX &&
                worldX - gp.tileSize < gp.player.worldX + gp.player.screenX &&
                worldY + gp.tileSize > gp.player.worldY - gp.player.screenY &&
                worldY - gp.tileSize < gp.player.worldY + gp.player.screenY) {
            BufferedImage image = null;


                if (direction == "up")
                    image = walk_up[spriteNum];
                else if (direction == "down")
                    image = walk_down[spriteNum];
                else if (direction == "left")
                    image = walk_left[spriteNum];
                else if (direction == "right")
                    image = walk_right[spriteNum];





            g2.drawImage(image, screenX, screenY, height, width, null);

            //------------------------------------------------
            //DRAW HP BAR
            //--------------------------------------------------
            if (last_hit_time > 0) {
                int outline_width = 2, hp_bar_width = 35, hp_bar_start = 7;

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

    public void locked_moving_area_logic() {
        if (is_locked == true) {
            if (worldX < lock_low_x || worldX > lock_high_x)
                collisonOn = true;

            if (worldY < lock_low_y || worldY > lock_high_y)
                collisonOn = true;
        }
    }
}

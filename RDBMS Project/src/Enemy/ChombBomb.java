package Enemy;

import MainPackage.GamePanel;
import entity.Entity;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

import static java.lang.Math.abs;

public class ChombBomb extends Entity {

    public int type;

    public BufferedImage[][] idle_up= new BufferedImage[4][4];
    public BufferedImage[][] idle_down= new BufferedImage[4][4];

    public BufferedImage[][] idle_left= new BufferedImage[4][4];
    public BufferedImage[][] idle_right= new BufferedImage[4][4];

    public BufferedImage [][] walk_up= new BufferedImage[4][6];
    public BufferedImage [][] walk_down= new BufferedImage[4][6];
    public BufferedImage [][] walk_left= new BufferedImage[4][6];
    public BufferedImage [][] walk_right= new BufferedImage[4][6];

    public BufferedImage [][] pre_blast_up=new BufferedImage[4][7];
    public BufferedImage [][] pre_blast_down=new BufferedImage[4][7];
    public BufferedImage [][] pre_blast_left=new BufferedImage[4][7];
    public BufferedImage [][] pre_blast_right=new BufferedImage[4][7];

    public BufferedImage [][] regrow_up = new BufferedImage[4][4];
    public BufferedImage [][] regrow_down = new BufferedImage[4][4];
    public BufferedImage [][] regrow_left = new BufferedImage[4][4];
    public BufferedImage [][] regrow_right = new BufferedImage[4][4];

    public BufferedImage [][] blast= new BufferedImage[4][6];

    boolean playerInRange=false;
    boolean target_girl=false;



    public int eventCounter=0;


    public ChombBomb(GamePanel gp)
    {
        super(gp);

        speed=1;
        solidArea=new Rectangle(10, 20, 40-10, 53-20);
        damageSolidArea=solidArea;

        Random random= new Random();
        type= random.nextInt(4);


        height=55;
        width=55;
        action="idle";
        direction="left";
        max_health=15;
        current_health=max_health;
        hit_damage=1;


        getImage();

    }

    public void getImage()
    {
        try
        {
            for(int i=0; i<4; i++)
            {

                idle_up[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/idle/up/"+(i+1)+".png"));
                idle_down[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/idle/down/"+(i+1)+".png"));
                idle_left[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/idle/left/"+(i+1)+".png"));
                idle_right[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/idle/right/"+(i+1)+".png"));

                idle_up[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/idle/up/"+(i+1)+".png"));
                idle_down[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/idle/down/"+(i+1)+".png"));
                idle_left[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/idle/left/"+(i+1)+".png"));
                idle_right[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/idle/right/"+(i+1)+".png"));

                idle_up[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/idle/up/"+(i+1)+".png"));
                idle_down[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/idle/down/"+(i+1)+".png"));
                idle_left[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/idle/left/"+(i+1)+".png"));
                idle_right[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/idle/right/"+(i+1)+".png"));

                idle_up[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/idle/up/"+(i+1)+".png"));
                idle_down[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/idle/down/"+(i+1)+".png"));
                idle_left[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/idle/left/"+(i+1)+".png"));
                idle_right[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/idle/right/"+(i+1)+".png"));

                regrow_up[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/regrow/up/"+(i+1)+".png"));
                regrow_down[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/regrow/down/"+(i+1)+".png"));
                regrow_left[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/regrow/left/"+(i+1)+".png"));
                regrow_right[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/regrow/right/"+(i+1)+".png"));

                regrow_up[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/regrow/up/"+(i+1)+".png"));
                regrow_down[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/regrow/down/"+(i+1)+".png"));
                regrow_left[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/regrow/left/"+(i+1)+".png"));
                regrow_right[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/regrow/right/"+(i+1)+".png"));

                regrow_up[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/regrow/up/"+(i+1)+".png"));
                regrow_down[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/regrow/down/"+(i+1)+".png"));
                regrow_left[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/regrow/left/"+(i+1)+".png"));
                regrow_right[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/regrow/right/"+(i+1)+".png"));

                regrow_up[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/regrow/up/"+(i+1)+".png"));
                regrow_down[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/regrow/down/"+(i+1)+".png"));
                regrow_left[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/regrow/left/"+(i+1)+".png"));
                regrow_right[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/regrow/right/"+(i+1)+".png"));


            }


            for(int i=0; i<6; i++) {

                walk_up[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/walk/up/" + (i + 1) + ".png"));
                walk_down[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/walk/down/" + (i + 1) + ".png"));
                walk_left[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/walk/left/" + (i + 1) + ".png"));
                walk_right[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/walk/right/" + (i + 1) + ".png"));

                walk_up[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/walk/up/" + (i + 1) + ".png"));
                walk_down[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/walk/down/" + (i + 1) + ".png"));
                walk_left[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/walk/left/" + (i + 1) + ".png"));
                walk_right[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/walk/right/" + (i + 1) + ".png"));

                walk_up[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/walk/up/" + (i + 1) + ".png"));
                walk_down[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/walk/down/" + (i + 1) + ".png"));
                walk_left[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/walk/left/" + (i + 1) + ".png"));
                walk_right[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/walk/right/" + (i + 1) + ".png"));

                walk_up[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/walk/up/" + (i + 1) + ".png"));
                walk_down[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/walk/down/" + (i + 1) + ".png"));
                walk_left[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/walk/left/" + (i + 1) + ".png"));
                walk_right[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/walk/right/" + (i + 1) + ".png"));

                blast[0][i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/blast/" + (i + 1) + ".png"));
                blast[1][i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/blast/" + (i + 1) + ".png"));
                blast[2][i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/blast/" + (i + 1) + ".png"));
                blast[3][i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/blast/" + (i + 1) + ".png"));


            }

            for(int i=0; i<7; i++) {

                pre_blast_up[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/pre-blast/up/" + (i + 1) + ".png"));
                pre_blast_down[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/pre-blast/down/" + (i + 1) + ".png"));
                pre_blast_left[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/pre-blast/left/" + (i + 1) + ".png"));
                pre_blast_right[0][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/blue/pre-blast/right/" + (i + 1) + ".png"));

                pre_blast_up[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/pre-blast/up/" + (i + 1) + ".png"));
                pre_blast_down[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/pre-blast/down/" + (i + 1) + ".png"));
                pre_blast_left[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/pre-blast/left/" + (i + 1) + ".png"));
                pre_blast_right[1][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/green/pre-blast/right/" + (i + 1) + ".png"));

                pre_blast_up[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/pre-blast/up/" + (i + 1) + ".png"));
                pre_blast_down[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/pre-blast/down/" + (i + 1) + ".png"));
                pre_blast_left[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/pre-blast/left/" + (i + 1) + ".png"));
                pre_blast_right[2][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/pink/pre-blast/right/" + (i + 1) + ".png"));

                pre_blast_up[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/pre-blast/up/" + (i + 1) + ".png"));
                pre_blast_down[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/pre-blast/down/" + (i + 1) + ".png"));
                pre_blast_left[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/pre-blast/left/" + (i + 1) + ".png"));
                pre_blast_right[3][i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Chomb Bomb/yellow/pre-blast/right/" + (i + 1) + ".png"));

            }
            } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    @Override
    public void update() {

        if (playerInRange == false) {

            if (eventCounter == 0) {
                Random random = new Random();

                int event = random.nextInt(2);

                eventCounter = 200;

                if (event == 0)
                    action = "walk";
                else
                    action = "idle";
            } else {
                if (eventCounter % 40 == 0 && action == "walk") {
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
                    gp.cChecker.check_decoraton(this);

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

                if (action == "walk")
                    spriteNum = (++spriteNum) % 6;
                else if (action == "idle")
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
        {
            speed=5;
        }

        if(last_hit_time>0)
            last_hit_time--;

        if(action!="blast" && action!="blast-wait")
        gp.cChecker.check_player_enemy_hit(this);

        if(action=="blast")
            gp.cChecker.check_enemy_damage_player(this);

    }




    @Override
    public void draw(Graphics2D g2) {

        int screenX = worldX - gp.player.worldX + gp.player.screenX;
        int screenY = worldY - gp.player.worldY + gp.player.screenY;


        if (worldX + gp.tileSize > gp.player.worldX - gp.player.screenX &&
                worldX - gp.tileSize < gp.player.worldX + gp.player.screenX &&
                worldY + gp.tileSize > gp.player.worldY - gp.player.screenY &&
                worldY - gp.tileSize < gp.player.worldY + gp.player.screenY) {
            BufferedImage image = null;

            if (action == "idle" ) {
                if (direction == "up")
                    image = idle_up[type][spriteNum];

                else if (direction == "down")
                    image = idle_down[type][spriteNum];

                else if (direction == "left")
                    image = idle_left[type][spriteNum];
                else if (direction == "right")
                    image = idle_right[type][spriteNum];


            } else if (action == "walk" || action=="attack") {
                 if (direction == "up")
                    image = walk_up[type][spriteNum];

                else if (direction == "down")
                    image = walk_down[type][spriteNum];
                else if (direction == "left")
                    image = walk_left[type][spriteNum];
                else if (direction == "right")
                    image = walk_right[type][spriteNum];


            }
            else if(action=="pre-blast")
            {
                if (direction == "up")
                    image = pre_blast_up[type][spriteNum];

                else if (direction == "down")
                    image = pre_blast_down[type][spriteNum];
                else if (direction == "left")
                    image = pre_blast_left[type][spriteNum];
                else if (direction == "right")
                    image = pre_blast_right[type][spriteNum];
            }
            else if(action=="blast")
            {
                image=blast[type][spriteNum];
            }
            else if(action=="regrow")
            {
                if (direction == "up")
                    image = regrow_up[type][spriteNum];

                else if (direction == "down")
                    image = regrow_down[type][spriteNum];
                else if (direction == "left")
                    image = regrow_left[type][spriteNum];
                else if (direction == "right")
                    image = regrow_right[type][spriteNum];
            }

            g2.drawImage(image, screenX, screenY,  height, width, null);

            //------------------------------------------------
            //DRAW HP BAR
            //--------------------------------------------------
            if(last_hit_time>0 &&  (action!="blast" && action!="blast-wait"))
            {
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

    public int detectionX=250;
    public int detectionY=220;


    public void player_range_checker_logic()
    {

        if(playerInRange==false && abs(gp.player.BoyWorldX-worldX)<detectionX && abs(gp.player.BoyWorldY-worldY)<detectionY)
        {

            eventCounter=600;

            playerInRange=true;
            target_girl=false;
            action="attack";

        }
        else  if( playerInRange==false && abs(gp.player.GirlWorldX-worldX)<detectionX && abs(gp.player.GirlWOrldY-worldY)<detectionY)
        {


            eventCounter=600;
            playerInRange=true;
            target_girl=true;
            action="attack";


        }
        if(playerInRange==true && action=="attack" && (abs(gp.player.BoyWorldX-worldX)>500 || abs(gp.player.BoyWorldY-worldY)>300) && (abs(gp.player.GirlWorldX-worldX)>500 || abs(gp.player.GirlWOrldY-worldY)>300) )
        {
            playerInRange=false;
            action="idle";
            eventCounter=200;
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

        if(action=="attack" && eventCounter%8==0) {


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

            if( action=="attack" && (abs(targetX-worldX)<40) && (abs(targetY-worldY)<40)    )
            {
                action="pre-blast";
            }



        }


        if(action=="attack")
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





    if(action=="attack") {
    spriteCounter++;

    if (spriteCounter > 10) {
        spriteNum = (++spriteNum) % 6;

        spriteCounter = 0;
    }
}
    else if(action=="pre-blast")
    {
        spriteCounter++;

        if (spriteCounter > 3) {

            if(spriteNum<6)
                spriteNum++;
            else if(spriteNum==6)
            {
                spriteNum=0;
                action="blast";
            }


            spriteCounter = 0;
        }
    }
    else if(action=="blast")
    {
        spriteCounter++;

        if (spriteCounter > 3) {

            if(spriteNum<5)
                spriteNum++;
            else if(spriteNum==5)
            {
                spriteNum=0;
                action="blast-wait";
                eventCounter=100;
            }


            spriteCounter = 0;
        }
    }
    else if(action=="regrow")
    {
        spriteCounter++;

        if (spriteCounter > 10) {

            if(spriteNum<3)
                spriteNum++;
            else if(spriteNum==3)
            {
                spriteNum=0;
                action="attack";

            }


            spriteCounter = 0;
        }
    }

        if(eventCounter==0)
        {
            if(action=="blast-wait")
            {
                action="regrow";
            }

            eventCounter=800;
        }
        else
            eventCounter--;




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

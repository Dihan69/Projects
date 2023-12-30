package Enemy;

import MainPackage.GamePanel;
import entity.Entity;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

import static java.lang.Math.abs;

public class Pumpkin extends Entity {


    public BufferedImage[] walk_up= new BufferedImage[4];
    public BufferedImage [] walk_down= new BufferedImage[4];
    public BufferedImage [] walk_left= new BufferedImage[4];
    public BufferedImage [] walk_right= new BufferedImage[4];

    public BufferedImage idle_up, idle_down, idle_left, idle_right;

    public BufferedImage change_up, change_down, change_left, change_right;

    public BufferedImage[] attack_up= new BufferedImage[2];
    public BufferedImage [] attack_down= new BufferedImage[2];
    public BufferedImage [] attack_left= new BufferedImage[2];
    public BufferedImage [] attack_right= new BufferedImage[2];

    public BufferedImage [] effect= new BufferedImage[3];

    public Entity projectile []= new  Entity[5];

    public BufferedImage  showpiece;

    boolean playerInRange=false;
    boolean target_girl=false;



    public int eventCounter=0;

    public Pumpkin(GamePanel gp)
    {
        super(gp);

        speed=2;
        solidArea=new Rectangle(10, 20, 40-10, 53-20);
        damageSolidArea=solidArea;



        height=70;
        width=70;



        action="show";
        direction="left";
        max_health=20;
        current_health=max_health;


        getImage();
    }

    public void getImage()
    {
        try
        {
            for(int i=0; i<4; i++) {


                walk_up[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/move/up/" + (i + 1) + ".png"));
                walk_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/move/right/" + (i + 1) + ".png"));
                walk_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/move/left/" + (i + 1) + ".png"));
                walk_down[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/move/down/" + (i + 1) + ".png"));

            }


            for(int i=0; i<2; i++) {


                attack_up[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/attack/up/" + (i + 1) + ".png"));
                attack_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/attack/right/" + (i + 1) + ".png"));
                attack_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/attack/left/" + (i + 1) + ".png"));
                attack_down[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/attack/down/" + (i + 1) + ".png"));

            }

            idle_up = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/idle/up/1.png"));
            idle_right = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/idle/right/1.png"));
            idle_left = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/idle/left/1.png"));
            idle_down = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/idle/down/1.png"));

            change_up = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/change/up/1.png"));
            change_right = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/change/right/1.png"));
            change_left = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/change/left/1.png"));
            change_down = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/change/down/1.png"));

            showpiece = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/showpiece/1.png"));

            for(int i=0; i<3; i++)
                effect[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/attack/effect/fireball(static)/short range/"+(i+1)+".png"));

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void update() {

        move_projectile();

        if (playerInRange == false) {

            if(eventCounter==0 && action=="idle")
            {
                action="change";
                eventCounter=15;
        }
            if(eventCounter==0 && action=="change")
            {
                action="show";
            }

            if(eventCounter>0)
                eventCounter--;

        }
        else
            target_player_logic();

        player_range_checker_logic();

        if(last_hit_time>0)
            last_hit_time--;


            gp.cChecker.check_player_enemy_hit(this);

            for(int i=0; i<projectile.length; i++)
            {
                if(projectile[i]!=null)
                {
                    gp.cChecker.check_enemy_damage_player(projectile[i]);
                }

            }


    }

    public int detectionX=150;
    public int detectionY=120;

    public void player_range_checker_logic()
    {

        if(playerInRange==false && abs(gp.player.BoyWorldX-worldX)<detectionX && abs(gp.player.BoyWorldY-worldY)<detectionY)
        {

            eventCounter=15;

            playerInRange=true;
            target_girl=false;
            action="change";

        }
        else  if( playerInRange==false && abs(gp.player.GirlWorldX-worldX)<detectionX && abs(gp.player.GirlWOrldY-worldY)<detectionY)
        {


            eventCounter=15;
            playerInRange=true;
            target_girl=true;
            action="change";


        }
        if(playerInRange==true && (action!="idle" || action!="show" || action!="change") && (abs(gp.player.BoyWorldX-worldX)>500 || abs(gp.player.BoyWorldY-worldY)>300) && (abs(gp.player.GirlWorldX-worldX)>500 || abs(gp.player.GirlWOrldY-worldY)>300) )
        {
            playerInRange=false;
            action="idle";
            eventCounter=100;
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

   if(action=="change")
   {
       if(eventCounter==0)
       {
           action="walk";
           eventCounter=300;
       }
   }
   else if(action=="walk")
   {
       if(eventCounter%10==0) {


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

           /*if( action=="attack" && (abs(targetX-worldX)<40) && (abs(targetY-worldY)<40)    )
           {
               action="pre-blast";
           }*/



       }



       if(abs(targetX-worldX)<8)
       {
           action="attack";

           if(worldY<targetY)
               direction="down";
           else if(worldY>targetY)
               direction="up";

           eventCounter=50;

       }

       if(abs(targetY-worldY)<8)
       {
           action="attack";

           if(worldX<targetX)
               direction="right";
           else if(worldX>targetX)
               direction="left";

       eventCounter=50;
       }

       int loop_counter=0;

       while (true) {

           loop_counter++;
           if (loop_counter > 1000)
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

               direction_change_logic();
           }
       }

       if(eventCounter==0)
           eventCounter=200;
   }
   else if(action=="attack")
   {
       if(eventCounter==0) {
           eventCounter = 50;
           action="walk";
       }

       if(eventCounter==40)
           shoot_projectile();
   }

       if(eventCounter>0)
       eventCounter--;

       if(action=="walk")
       {
           spriteCounter++;

           if (spriteCounter > 10) {
               spriteNum = (++spriteNum) % 4;

               spriteCounter = 0;
           }
       }
       else if (action=="attack")
       {
           spriteCounter++;

           if (spriteCounter > 10) {
               if(eventCounter>25)
               spriteNum = (++spriteNum) % 2;
            else
                spriteNum=0;

               spriteCounter = 0;
           }
       }

    }

    public void shoot_projectile()
    {
        for(int i=0; i<5; i++)
        {
            if(projectile[i]==null)
            {
                projectile[i]= new Entity(gp);

                if(direction=="left")
                {
                    projectile[i].direction="left";
                    projectile[i].worldX=worldX-5;
                    projectile[i].worldY=worldY+height/2;
                }
                else if(direction=="right")
                {
                    projectile[i].direction="right";
                    projectile[i].worldX=worldX+width+5;
                    projectile[i].worldY=worldY+height/2;
                }
                else if(direction=="up")
                {
                    projectile[i].direction="up";
                    projectile[i].worldX=worldX+width/2;
                    projectile[i].worldY=worldY-5;
                }
                else if(direction=="down")
                {
                    projectile[i].direction="down";
                    projectile[i].worldX=worldX+width/2;
                    projectile[i].worldY=worldY+height+5;
                }

                projectile[i].width=28;
                projectile[i].height=28;
                projectile[i].speed=6;
                projectile[i].solidArea=new Rectangle(-2,-2, 32, 32);
                projectile[i].current_health =260;
                projectile[i].hit_damage=2;

                break;
            }

        }
    }

    public void move_projectile()
    {
        for(int i=0; i<5; i++)
        {
            if(projectile[i]!=null)
            {
                switch (projectile[i].direction) {
                    case "up":
                        projectile[i].worldY -= projectile[i].speed;

                        break;


                    case "down":
                        projectile[i].worldY += projectile[i].speed;

                        break;

                    case "left":

                        projectile[i].worldX -= projectile[i].speed;
                        break;
                    case "right":

                        projectile[i].worldX += projectile[i].speed;
                        break;
                }

                projectile[i].collisonOn=false;

                gp.cChecker.check_decoraton(projectile[i]);

                projectile[i].current_health--;

                if(projectile[i].collisonOn==true || projectile[i].current_health ==0)
                    projectile[i]=null;





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

    public void draw(Graphics2D g2) {
        int screenX = worldX - gp.player.worldX + gp.player.screenX;
        int screenY = worldY - gp.player.worldY + gp.player.screenY;


        if (worldX + gp.tileSize > gp.player.worldX - gp.player.screenX &&
                worldX - gp.tileSize < gp.player.worldX + gp.player.screenX &&
                worldY + gp.tileSize > gp.player.worldY - gp.player.screenY &&
                worldY - gp.tileSize < gp.player.worldY + gp.player.screenY) {
            BufferedImage image = null;

            if(action=="show")
                image=showpiece;
            else if (action == "idle" ) {
                if (direction == "up")
                    image = idle_up;

                else if (direction == "down")
                    image = idle_down;

                else if (direction == "left")
                    image = idle_left;
                else if (direction == "right")
                    image = idle_right;


            } else if (action == "change" ) {
                if (direction == "up")
                    image = change_up;

                else if (direction == "down")
                    image = change_down;

                else if (direction == "left")
                    image = change_left;
                else if (direction == "right")
                    image = change_right;


            }

            else if (action == "walk") {
                if (direction == "up")
                    image = walk_up[spriteNum];

                else if (direction == "down")
                    image = walk_down[spriteNum];
                else if (direction == "left")
                    image = walk_left[spriteNum];
                else if (direction == "right")
                    image = walk_right[spriteNum];


            }

            else if (action == "attack") {
                if (direction == "up")
                    image = attack_up[spriteNum];

                else if (direction == "down")
                    image = attack_down[spriteNum];
                else if (direction == "left")
                    image = attack_left[spriteNum];
                else if (direction == "right")
                    image = attack_right[spriteNum];


            }




            g2.drawImage(image, screenX, screenY,  height, width, null);

            //------------------------------------------------
            //DRAW HP BAR
            //--------------------------------------------------
            if(last_hit_time>0)
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

        for(int i=0; i<5; i++)
        {
            if(projectile[i]!=null)
            {
                 screenX = projectile[i].worldX - gp.player.worldX + gp.player.screenX;
                 screenY = projectile[i].worldY - gp.player.worldY + gp.player.screenY;


                if (projectile[i].worldX + gp.tileSize > gp.player.worldX - gp.player.screenX &&
                        projectile[i].worldX - gp.tileSize < gp.player.worldX + gp.player.screenX &&
                        projectile[i].worldY + gp.tileSize > gp.player.worldY - gp.player.screenY &&
                        projectile[i].worldY - gp.tileSize < gp.player.worldY + gp.player.screenY) {

                BufferedImage image= effect[projectile[i].spriteNum];

                    g2.drawImage(image, screenX, screenY,  projectile[i].height, projectile[i].width, null);

                }
                }
            }
        }



    }


package Enemy;

import MainPackage.GamePanel;
import entity.Entity;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

import static java.lang.Math.abs;

public class Plant extends Entity {

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

    public BufferedImage [] attack_up_left = new BufferedImage[4];
    public BufferedImage [] attack_up_right = new BufferedImage[4];
    public BufferedImage [] attack_down_left = new BufferedImage[4];
    public BufferedImage [] attack_down_right = new BufferedImage[4];
    public BufferedImage [] attack_left = new BufferedImage[4];
    public BufferedImage [] attack_right = new BufferedImage[4];

    public int eventCounter=0;

    boolean target_girl=false;

    public boolean playerInRange=false;
    public Plant(GamePanel gp) {
        super(gp);

        solidArea=new Rectangle(10, 10, 80-20, 80-20);

        height=80;
        width=80;

        damageSolidArea=new Rectangle(0,0,height,width);

        action="idle";
        direction="left";
        max_health=70;
        current_health=max_health;
        hit_damage=5;

        getImage();


    }

    public void getImage()
    {
        try
        {
            for(int i=0; i<4; i++)
            {
                idle_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/idle/up-left/"+(i+1)+".png"));
                idle_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/idle/up-right/"+(i+1)+".png"));
                idle_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/idle/down-left/"+(i+1)+".png"));
                idle_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/idle/down-right/"+(i+1)+".png"));
                idle_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/idle/left/"+(i+1)+".png"));
                idle_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/idle/right/"+(i+1)+".png"));

                attack_up_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/attack/up-left/"+(i+1)+".png"));
                attack_up_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/attack/up-right/"+(i+1)+".png"));
                attack_down_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/attack/down-left/"+(i+1)+".png"));
                attack_down_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/attack/down-right/"+(i+1)+".png"));
                attack_left[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/attack/left/"+(i+1)+".png"));
                attack_right[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/plant/attack/right/"+(i+1)+".png"));




            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void update()
    {

        if(action=="idle")
            idle_state_logic();
        else if(action=="attack")
            attack_state_logic();

        player_range_checker_logic();

        if(eventCounter>0)
            eventCounter--;
        else
            eventCounter=100;

        if(action=="attack")
        {
            damage_region_fix();
            gp.cChecker.check_enemy_damage_player(this);
        }

        gp.cChecker.check_player_enemy_hit(this);

    }

    public void idle_state_logic()
    {
        if(eventCounter==0)
        {

                Random random = new Random();

                int X = random.nextInt(6);

                switch(X) {
                    case 0:
                        direction="left";
                        break;
                    case 1:
                        direction="right";
                        break;
                    case 2:
                        direction="up-left";
                        break;
                    case 3:
                        direction="up-right";
                        break;
                    case 4:
                        direction="down-left";
                        break;
                    case 5:
                        direction="down-right";
                        break;
                }



        }



        spriteCounter++;

        if (spriteCounter > 11) {
            spriteNum = (++spriteNum) % 4;
            spriteCounter = 0;
        }


    }

    public void damage_region_fix()
    {
        if(direction=="left")
            solidArea=new Rectangle(5, 28, 63-5, 77-28);
        else if(direction=="right")
            solidArea=new Rectangle(10, 28, 90-10, 77-28);
        else if(direction=="up-left")
            solidArea=new Rectangle(8, 6, 63-8, 77-6);
        else if(direction=="up-right")
            solidArea=new Rectangle(19, 6, 87-19, 77-6);
        else if(direction=="down-left")
            solidArea=new Rectangle(8, 17, 63-8, 85-17 );
        else if(direction=="down-right")
            solidArea=new Rectangle(20, 17, 87-20, 85-17);
    }

    public void attack_state_logic()
    {
        int playerX, playerY;

            if(target_girl==true)
            {
                playerX=gp.player.GirlWorldX;
                playerY=gp.player.GirlWOrldY;
            }
            else
            {
                playerX=gp.player.BoyWorldX;
                playerY=gp.player.BoyWorldY;
            }

            int playerHeight=gp.player.height;
            int playerWidth=gp.player.width;

            if(playerX>worldX) {


                if (Math.abs(playerY - worldY) < 30)
                    direction = "right";
                else if(playerY+playerHeight/2<worldY)
                    direction="up-right";
                else if(playerY>worldY+height/2)
                    direction="down-right";
            }
            else {
                if (Math.abs(playerY - worldY) < 30)
                    direction = "left";
                else if(playerY+playerHeight/2<worldY)
                    direction="up-left";
                else if(playerY>worldY+height/2)
                    direction="down-left";
            }

        spriteCounter++;

        if (spriteCounter > 7) {
            spriteNum = (++spriteNum) % 4;
            spriteCounter = 0;
        }
    }

    public void player_range_checker_logic()
    {
        int range_limit=70;

        if(  playerInRange==false && gp.player.BoyWorldX-worldX>-(range_limit) && gp.player.BoyWorldX-worldX<(range_limit+50) && abs(gp.player.BoyWorldY-worldY)<range_limit)
        {

            eventCounter=300;

            playerInRange=true;
            target_girl=false;
            action="attack";
            spriteNum=0;

        }
        else  if(  playerInRange==false && gp.player.GirlWorldX-worldX>-(range_limit) && gp.player.GirlWorldX-worldX<(range_limit+50)  && abs(gp.player.GirlWOrldY-worldY)<range_limit)
        {


            eventCounter=300;
            playerInRange=true;
            target_girl=true;
            action="attack";
            spriteNum=0;


        }
        if(playerInRange==true && (abs(gp.player.BoyWorldX-worldX)>range_limit || abs(gp.player.BoyWorldY-worldY)>range_limit) && (abs(gp.player.GirlWorldX-worldX)>range_limit || abs(gp.player.GirlWOrldY-worldY)>range_limit) )
        {
            playerInRange=false;
            action="idle";
            eventCounter=100;
        }
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
                int outline_width = 2, hp_bar_width = 50, hp_bar_start = 20;

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
}

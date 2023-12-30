package Enemy;

import MainPackage.GamePanel;
import entity.Entity;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

public class FinalBoss extends Entity {

    BufferedImage title, boss_health_bar;

    public BufferedImage  ani1, ani2, ani3, ani4, ani5, ani6, left0, left1, left2, left3;

    public int dying_animation= 0, dying_animation_delay=3;

    public BufferedImage other0, other1, hyper0, hyper1;

    public BufferedImage spark0, spark1, spark2, spark3, spark4, spark5, spark6, spark7, spark8;

    public BufferedImage blast0, blast1, blast2, blast3, blast4, blast5, blast6, blast7, blast8, blast9;

    public BufferedImage flame_start[]=new BufferedImage[4];
    public BufferedImage flame_loop[]=new BufferedImage[8];

    public BufferedImage flame_end[]=new BufferedImage[5];

    public Entity flame[]= new Entity[30];

    public BufferedImage [] left_ray= new BufferedImage[30];
    public BufferedImage [] right_ray= new BufferedImage[30];

    public Entity [] spark = new Entity[10];

    public Entity [] ray= new Entity[30];

    public BufferedImage [] teleport= new BufferedImage[8];

    public BufferedImage [] slash_left= new BufferedImage[5];
    public BufferedImage [] slash_right= new BufferedImage[5];

    public Entity []blast= new Entity[18];




        public BufferedImage [] fireball_image=new BufferedImage[4];

        public Entity [] fireball= new Entity[40];

    int activity_delay=120;
    public int hit_delay;

    public boolean slashed=false;


    public FinalBoss(GamePanel gp) {
        super(gp);

        solidArea = new Rectangle(149, 71, 261-149, 343-71);
        //    player_bullet = new Weapon[10];


        speed = 3;
        direction = "left";
        action="idle";

        height = 420;
        width = 420;
        can_shoot = false;


        max_health = 100;
        current_health = max_health;

        hit_damage=30;


        //player width is 96 px which is equal to gp.tileSize(48) *2 =96

        getEnemyImage();

        getWeaponImage();



    }

    public void getWeaponImage()
    {
        try {



            spark0 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/0.png"));
            spark1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/1.png"));
            spark2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/2.png"));
            spark3 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/3.png"));
            spark4 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/4.png"));
            spark5 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/5.png"));
            spark6 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/6.png"));
            spark7 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/7.png"));
            spark8 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/spark/8.png"));

            blast0 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/0.png"));
            blast1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/1.png"));
            blast2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/2.png"));
            blast3 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/3.png"));
            blast4 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/4.png"));
            blast5 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/5.png"));
            blast6 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/6.png"));
            blast7 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/7.png"));
            blast8 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/8.png"));
            blast9 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/blast/9.png"));

            for(int i=0; i<4; i++)
                flame_start[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/flame/start/" + i + ".png"));

            for(int i=0; i<8; i++)
                flame_loop[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/flame/loop/" + i + ".png"));

            for(int i=0; i<5; i++)
                flame_end[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/flame/end/" + i + ".png"));


            for (int i = 0; i < 30; i++) {
                left_ray[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/ray/" + i + ".png"));
            }

            for (int i = 0; i < 30; i++) {
                right_ray[i] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/fx/ray/right/"+ i+" - Copy.png"));
            }




            for(int i=0; i<3; i++)
                fireball_image[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/Pumpkin/attack/effect/fireball(static)/short range/"+(i+1)+".png"));




        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void getEnemyImage() {
        try {

            left[0] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/idle/0.png"));
            left[1] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/idle/1.png"));
            left[2] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/idle/2.png"));
            left[3] = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/idle/3.png"));

            other0= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/attack/other/0.png"));
            other1= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/attack/other/1.png"));

            hyper0= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/attack/hyper/0.png"));
            hyper1= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/attack/hyper/1.png"));




            for(int i=0; i<8; i++)
                teleport[i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/teleport/"+i+".png"));

            for(int i=0; i<5; i++)
                slash_left[i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/attack/slash/left-hand/"+i+".png"));
            for(int i=0; i<5; i++)
                slash_right[i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Enemy/knight/attack/slash/right-hand/"+i+".png"));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }




    public void draw(Graphics2D g2)
    {

        int screenX = worldX - gp.player.worldX + gp.player.screenX;
        int screenY = worldY - gp.player.worldY + gp.player.screenY;



            BufferedImage image = null;


            if(action=="idle") {

                    image = left[spriteNum];

            }
            else if(action=="slash")
            {
                if(current_state!="left_slash_start" && current_state!="right_slash_start")
                {
                    image=teleport[spriteNum];
                }
                else if(current_state=="right_slash_start")
                {
                    image=slash_right[spriteNum];
                }
                else if(current_state=="left_slash_start")
                    image=slash_left[spriteNum];
            }
            else if(action=="teleport")
            {
                image=teleport[spriteNum];
            }
            else if(action=="flame" || action=="fireball")
            {
                if(spriteNum==0)
                    image=other0;
                else
                    image=other1;
            }



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

            draw_flame(g2);
            draw_fireball(g2);


    }

    public int event_counter=0;
    public boolean sleep=false;

    public void update()
    {

        if(sleep==false)
        {
            if(action=="slash")
                fire_slash();
            else if(action=="teleport")
                fire_teleport();

            move_flame();
            move_fireball();

            if(event_counter==0)
            {
                Random random = new Random();

                int event = random.nextInt(1);

                if(event==1)
                {
                   current_state="teleport";
                    action="slash";
                    spriteNum=0;

                    event_counter=200;
                }
                else if(event==1)
                {
                    fire_flame();
                    action="flame";
                    spriteNum=0;

                    event_counter=300;
                }
                else if(event==0)
                {
                    fire_fireball();
                    action="fireball";
                    spriteNum=0;

                    event_counter=300;
                }


            }

            if(event_counter==220)
            {
                action="teleport";
                spriteNum=0;
                spriteCounter=0;
            }



            if(event_counter>0)
                event_counter--;
        }




        if(action=="idle")
        {
            spriteCounter++;

            if(spriteCounter>8)
            {
                spriteNum=(++spriteNum)%4;
                spriteCounter=0;
            }
        }
        else if(action=="flame" || action=="fireball")
        {
            spriteCounter++;

            if(spriteCounter>10)
            {
                spriteCounter=0;

                spriteNum++;

                if(spriteNum==2)
                {
                    spriteNum=0;
                    action="idle";
                }
            }
        }

    }


    public void fire_slash()
    {
        spriteCounter++;

        if(spriteCounter>6)
        {
            spriteCounter=0;

            if(current_state!="left_slash_start" && current_state!="right_slash_start" ) {
                spriteNum++;

                if (spriteNum == 4)
                    teleport();
                else if (spriteNum == 8) {
                    if (current_state == "left_slash")
                        current_state = "left_slash_start";
                    else
                        current_state = "right_slash_start";

                    spriteNum = 0;
                }
            }
            else if(current_state=="left_slash_start" || current_state=="right_slash_start")
            {
                spriteNum++;

                if(spriteNum==5)
                {
                    action="teleport";
                    spriteNum=0;
                }


            }

        }
    }

    public void fire_teleport()
    {
        spriteCounter++;

        if(spriteCounter>6)
        {
            spriteCounter=0;

            spriteNum++;

            if(spriteNum==4)
                teleport();
            else if(spriteNum==8)
            {
                spriteNum=0;
                action="idle";
            }
        }
    }

    public void fire_fireball()
    {
        for(int i=0; i<10; i++)
        {
            fireball[i]=new Entity(gp);

            fireball[i].direction="right";

            Random random=new Random();

            int X= random.nextInt(50);
            int Y= random.nextInt(1148-550)+550;
            int speed=random.nextInt(3);

            fireball[i].speed=10+speed;

            fireball[i].worldX=800+X;
            fireball[i].worldY=Y;
            fireball[i].current_health=150;
        }

        for(int i=10; i<20; i++)
        {
            fireball[i]=new Entity(gp);

            fireball[i].direction="left";

            Random random=new Random();

            int X= random.nextInt(50);
            int Y= random.nextInt(1148-550)+550;
            int speed=random.nextInt(3);

            fireball[i].speed=10+speed;

            fireball[i].worldX=2450-X;
            fireball[i].worldY=Y;
            fireball[i].current_health=150;
        }

        for(int i=20; i<30; i++)
        {
            fireball[i]=new Entity(gp);

            fireball[i].direction="down";

            Random random=new Random();

            int X= random.nextInt(2450-900)+900;
            int Y= random.nextInt(50);
            int speed=random.nextInt(3);

            fireball[i].speed=6+speed;

            fireball[i].worldX=X;
            fireball[i].worldY=450+Y;
            fireball[i].current_health=150;
        }

        for(int i=30; i<40; i++)
        {
            fireball[i]=new Entity(gp);

            fireball[i].direction="up";

            Random random=new Random();

            int X= random.nextInt(2450-900)+900;
            int Y= random.nextInt(50);
            int speed=random.nextInt(3);

            fireball[i].speed=6+speed;

            fireball[i].worldX=X;
            fireball[i].worldY=1230-Y;
            fireball[i].current_health=150;
        }
    }

    public void move_fireball()
    {
        for(int i=0; i<fireball.length; i++)
        {
            if(fireball[i]!=null)
            {
                switch (fireball[i].direction) {
                    case "up":
                        fireball[i].worldY -= fireball[i].speed;

                        break;


                    case "down":
                        fireball[i].worldY +=fireball[i].speed;

                        break;

                    case "left":

                        fireball[i].worldX -= fireball[i].speed;
                        break;
                    case "right":

                        fireball[i].worldX += fireball[i].speed;
                        break;
                }

                fireball[i].spriteCounter++;

                if(fireball[i].spriteCounter>5)
                {
                    fireball[i].spriteCounter=0;

                    fireball[i].spriteNum=(++fireball[i].spriteNum)%3;
                }

                fireball[i].current_health--;

                if(fireball[i].current_health ==0)
                    fireball[i]=null;







            }
        }
    }


    public void teleport()
    {
        if(action=="slash")
        {
            Random random = new Random();

            int event = random.nextInt(2);

            if(event==0)
            {
                current_state="left_slash";

                int boy = random.nextInt(2);

                if(boy==0)
                {
                    worldX = gp.player.GirlWorldX - 280;

                    worldY = gp.player.GirlWOrldY - 220;
                }
                else
                {
                    worldX = gp.player.BoyWorldX - 280;

                    worldY = gp.player.BoyWorldY - 220;
                }
            }
            else
            {
                current_state="right_slash";

                int boy = random.nextInt(2);

                if(boy==0)
                {
                    worldX = gp.player.GirlWorldX - 20;

                    worldY = gp.player.GirlWOrldY - 220;
                }
                else
                {
                    worldX = gp.player.BoyWorldX - 20;

                    worldY = gp.player.BoyWorldY - 220;
                }
            }
        }
        else if(action=="teleport")
        {
            Random random=new Random();

            int X= random.nextInt(2340-1000)+1000;
            int Y= random.nextInt(1148-575)+575;

            worldX=X;
            worldY=Y;
        }
    }

    public void fire_flame()
    {

        for(int i=0; i<flame.length; i++)
        {
            Random random = new Random();

            flame[i]= new Entity(gp);

            int x= random.nextInt(2470-1000)+1000;
            int y= random.nextInt(1300-575)+575;

            flame[i].worldX=x;
            flame[i].worldY=y;
            flame[i].action="start";
        }
    }

    public void move_flame()
    {
        for(int i=0; i<flame.length; i++)
        {
            if(flame[i]!=null)
            {
                flame[i].spriteCounter++;

                if(flame[i].action=="start")
                {
                    if(flame[i].spriteCounter>4)
                    {
                        flame[i].spriteCounter=0;

                        flame[i].spriteNum++;

                        if(flame[i].spriteNum==4)
                        {
                            flame[i].spriteNum=0;
                            flame[i].action="loop";

                        }
                    }
                }
                else if(flame[i].action=="loop")
                {
                    if(flame[i].spriteCounter>6)
                    {
                        flame[i].spriteCounter=0;

                        flame[i].spriteNum++;

                        if(flame[i].spriteNum==8)
                        {
                            flame[i].spriteNum=0;

                            flame[i].action="end";

                        }
                    }
                }
                else if(flame[i].action=="end")
                {
                    if(flame[i].spriteCounter>4)
                    {
                        flame[i].spriteCounter=0;

                        flame[i].spriteNum++;

                        if(flame[i].spriteNum==2)
                        {
                            flame[i]=null;

                        }
                    }
                }
            }
        }
    }

    public void draw_flame(Graphics2D g2) {



        for (int i = 0; i < flame.length; i++) {
            if (flame[i] != null) {

                if(i==0)
                    System.out.println(flame[i].action+","+flame[i].spriteNum);

                BufferedImage image=null;

                if(flame[i].action=="start")
                {
                    image=flame_start[spriteNum];
                }
                else if(flame[i].action=="loop")
                {
                    image=flame_loop[spriteNum];
                }
                else if(flame[i].action=="end")
                    image=flame_end[spriteNum];


                int screenX = flame[i].worldX - gp.player.worldX + gp.player.screenX;
                int screenY =flame[i].worldY - gp.player.worldY + gp.player.screenY;


                g2.drawImage(image, screenX,screenY , 80, 110, null);

            }


        }
    }

    public void draw_fireball(Graphics2D g2)

    { for (int i = 0; i < fireball.length; i++) {
        if (fireball[i] != null) {



            BufferedImage image=fireball_image[fireball[i].spriteNum];



            int screenX = fireball[i].worldX - gp.player.worldX + gp.player.screenX;
            int screenY =fireball[i].worldY - gp.player.worldY + gp.player.screenY;


            g2.drawImage(image, screenX,screenY , 28, 28, null);

        }


    }

    }




}

package entity;

import MainPackage.GamePanel;
import Tile.SuperObject;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class Dungeon extends Entity{

    public BufferedImage []trap2_image = new BufferedImage[5];
    public BufferedImage []trap3_image= new BufferedImage[5];

    public BufferedImage lazer_image;

    int trap2_count=10;
    public Entity trap2[]= new Entity[trap2_count];

    public int trap3_count=5;
    public Entity trap3[]= new Entity[trap3_count];

    public int lazer_count=10;
    public Entity lazer[]= new Entity[lazer_count];

    public Dungeon(GamePanel gp) {
        super(gp);

        current_health=100;

        for(int i=0; i<trap2_count; i++)
        {
            trap2[i]=new Entity(gp);
            trap2[i].height=100;
            trap2[i].width=100;
            trap2[i].action="increasing";
        }
        set_trap2_position();

        for(int i=0; i<trap3_count; i++)
        {
            trap3[i]=new Entity(gp);
            trap3[i].height=90;
            trap3[i].width=90;
            trap3[i].action="stop";
        }

        for(int i=0; i<lazer_count; i++)
        {
            lazer[i]=new Entity(gp);
            lazer[i].action="visible";
        }

        set_trap3_position();
        set_lazer_position();

        getImage();
    }

    public void getImage()
    {
        try
        {
        for(int i=0; i<5; i++)
        {
            trap2_image[i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Trap/spike-trap-2/"+(i+1)+".png"));
            trap3_image[i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Trap/spike-trap-3/"+(i+1)+".png"));
        }

        lazer_image=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Trap/Lazer/0.png"));

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void set_trap2_position()
    {
        trap2[0].worldX=980;
        trap2[0].worldY=1050;

        trap2[1].worldX=1047;
        trap2[1].worldY=1050;

        trap2[2].worldX=1036;
        trap2[2].worldY=1313;

        trap2[3].worldX=1192;
        trap2[3].worldY=1353;

        trap2[4].worldX=1300;
        trap2[4].worldY=1361;

        trap2[5].worldX=1100;
        trap2[5].worldY=1400;

    }

    public void set_trap3_position()
    {
        trap3[0].worldX=980;
        trap3[0].worldY=1160;

        trap3[1].worldX=1047;
        trap3[1].worldY=1160;
    }

    public void set_lazer_position()
    {
        lazer[0].worldX=980;
        lazer[0].worldY=1250;
        lazer[0].width=160;
    }

    public void draw(Graphics2D g2)
    {


        for(int i=0; i<trap2_count; i++)
        {


            worldX=trap2[i].worldX;
            worldY=trap2[i].worldY;

            int screenX = worldX - gp.player.worldX + gp.player.screenX;
            int screenY = worldY - gp.player.worldY + gp.player.screenY;



            if (worldX + gp.tileSize > gp.player.worldX - gp.player.screenX &&
                    worldX - gp.tileSize < gp.player.worldX + gp.player.screenX &&
                    worldY + gp.tileSize > gp.player.worldY - gp.player.screenY &&
                    worldY - gp.tileSize < gp.player.worldY + gp.player.screenY) {



                g2.drawImage(trap2_image[trap2[i].spriteNum], screenX, screenY, 90, 90, null);



            }
        }

        for(int i=0; i<trap3_count; i++)
        {


            worldX=trap3[i].worldX;
            worldY=trap3[i].worldY;

            int screenX = worldX - gp.player.worldX + gp.player.screenX;
            int screenY = worldY - gp.player.worldY + gp.player.screenY;



            if (worldX + gp.tileSize > gp.player.worldX - gp.player.screenX &&
                    worldX - gp.tileSize < gp.player.worldX + gp.player.screenX &&
                    worldY + gp.tileSize > gp.player.worldY - gp.player.screenY &&
                    worldY - gp.tileSize < gp.player.worldY + gp.player.screenY) {



                g2.drawImage(trap3_image[trap3[i].spriteNum], screenX, screenY, 90, 90, null);



            }
        }

        for(int i=0; i<lazer_count; i++)
        {


            worldX=lazer[i].worldX;
            worldY=lazer[i].worldY;

            int screenX = worldX - gp.player.worldX + gp.player.screenX;
            int screenY = worldY - gp.player.worldY + gp.player.screenY;



            if (worldX + gp.tileSize > gp.player.worldX - gp.player.screenX &&
                    worldX - gp.tileSize < gp.player.worldX + gp.player.screenX &&
                    worldY + gp.tileSize > gp.player.worldY - gp.player.screenY &&
                    worldY - gp.tileSize < gp.player.worldY + gp.player.screenY) {


            if(lazer[i].action=="visible")
                g2.drawImage(lazer_image, screenX, screenY, lazer[i].width, 40, null);



            }
        }



    }

    public void update()
    {


        update_trap2();
        update_trap3();
        lazer_update();
    }

    public void update_trap2()
    {
        for(int i=0; i<trap2_count; i++)
        {
            trap2[i].spriteCounter++;

            if(trap2[i].spriteCounter>10)
            {
                if(trap2[i].spriteNum==1 && trap2[i].action=="decreasing")
                {
                    trap2[i].action="increasing";
                    trap2[i].spriteNum=0;
                    trap2[i].spriteCounter=-30;
                }
                else if(trap2[i].spriteNum==3 && trap2[i].action=="increasing")
                {
                    trap2[i].action="decreasing";
                    trap2[i].spriteNum=4;
                    trap2[i].spriteCounter=-30;
                }
                else if(trap2[i].action=="increasing")
                    trap2[i].spriteNum++;
                else if(trap2[i].action=="decreasing")
                    trap2[i].spriteNum--;
            }
        }
    }

    public void update_trap3()
    {
        check_trap3_collison();

        for(int i=0; i<trap3_count; i++)
        {
            trap3[i].spriteCounter++;

            if(trap3[i].spriteCounter>10)
            {
                if(trap3[i].spriteNum==1 && trap3[i].action=="decreasing")
                {
                    trap3[i].action="stop";
                    trap3[i].spriteNum=0;
                    trap3[i].spriteCounter=-10;
                }
                else if(trap3[i].spriteNum==3 && trap3[i].action=="increasing")
                {
                    trap3[i].action="decreasing";
                    trap3[i].spriteNum=4;
                    trap3[i].spriteCounter=-30;
                }
                else if(trap3[i].action=="increasing")
                    trap3[i].spriteNum++;
                else if(trap3[i].action=="decreasing")
                    trap3[i].spriteNum--;
                else if(trap3[i].action=="attack")
                {
                    trap3[i].action="increasing";
                    trap3[i].spriteCounter=-35;
                }
                else
                    spriteCounter=0;
            }

        }
    }



    public void check_trap3_collison()
    {
        Rectangle entity1 = new Rectangle();

        Player e=gp.player;

        for(int k=0; k<2; k++) {

            if (k == 0) {
                entity1.x = e.BoyWorldX + e.solidArea.x;
                entity1.y = e.BoyWorldY + e.solidArea.y;
                entity1.height = e.solidArea.height;
                entity1.width = e.solidArea.width;
            } else {
                entity1.x = e.GirlWorldX + e.solidArea.x;
                entity1.y = e.GirlWOrldY + e.solidArea.y;
                entity1.height = e.solidArea.height;
                entity1.width = e.solidArea.width;
            }

            for (int i = 0; i < trap3_count; i++) {
                Entity d = trap3[i];


                Rectangle entity2 = new Rectangle();

                entity2.x = d.worldX ;
                entity2.y = d.worldY ;
                entity2.height = d.height;
                entity2.width = d.width;


                if (entity1.intersects(entity2)) {
                    {
                        if(trap3[i].action=="stop")
                       trap3[i].action="attack";
                    }
                }


            }

        }
    }

    public void lazer_update() {
        for (int i = 0; i < lazer_count; i++) {
            lazer[i].spriteCounter++;

            if (lazer[i].spriteCounter > 50) {

                if(lazer[i].action=="invisible")
                lazer[i].action="visible";
                else
                    lazer[i].action="invisible";

                lazer[i].spriteCounter=0;
            }

        }
    }
}

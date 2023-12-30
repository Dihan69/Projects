package MainPackage;

import Tile.Decoration;
import Tile.SuperObject;
import entity.Entity;
import entity.Player;

import java.awt.*;

public class CollisionChecker {

    GamePanel gp;

    public CollisionChecker (GamePanel gp)
    {
        this.gp=gp;
    }

    public void checkTile(Entity entity)
    {

        int entityLeftWorldX= entity.worldX+entity.solidArea.x;
        int entityRightWorldX= entity.worldX+entity.solidArea.x+entity.solidArea.width;
        int entityTopWorldY= entity.worldY+entity.solidArea.y;
        int entityBottomWorldY= entity.worldY+entity.solidArea.y+entity.solidArea.height;

        int entityLeftCol= entityLeftWorldX/gp.tileSize;
        int entityRightCol= entityRightWorldX/gp.tileSize;
        int entityTopRow= entityTopWorldY/gp.tileSize;
        int entityBottomRow= entityBottomWorldY/gp.tileSize;

        int tileNum1, tileNum2;


           if(entity.direction=="up" || entity.direction=="up-left" || entity.direction=="up-right") {
               entityTopRow = (entityTopWorldY - entity.speed) / gp.tileSize;
               tileNum1 = gp.tileM.mapTileNum[entity.map][entityLeftCol][entityTopRow];
               tileNum2 = gp.tileM.mapTileNum[entity.map][entityRightCol][entityTopRow];

               if (gp.tileM.tile[tileNum1].collison == true || gp.tileM.tile[tileNum2].collison == true)
                   entity.collisonOn = true;
           }

        if(entity.direction=="down" || entity.direction=="down-left" || entity.direction=="down-right") {

            entityBottomRow = (entityBottomWorldY + entity.speed) / gp.tileSize;
            tileNum1 = gp.tileM.mapTileNum[entity.map][entityLeftCol][entityBottomRow];
            tileNum2 = gp.tileM.mapTileNum[entity.map][entityRightCol][entityBottomRow];


            if (gp.tileM.tile[tileNum1].collison == true || gp.tileM.tile[tileNum2].collison == true)
                entity.collisonOn = true;

        }

        if(entity.direction=="left" || entity.direction=="down-left" || entity.direction=="up-left") {
            entityLeftCol = (entityLeftWorldX - entity.speed) / gp.tileSize;
            tileNum1 = gp.tileM.mapTileNum[entity.map][entityLeftCol][entityTopRow];
            tileNum2 = gp.tileM.mapTileNum[entity.map][entityLeftCol][entityBottomRow];

            if (gp.tileM.tile[tileNum1].collison == true || gp.tileM.tile[tileNum2].collison == true)
                entity.collisonOn = true;

        }

        if(entity.direction=="right" || entity.direction=="down-right" || entity.direction=="up-right") {
                entityRightCol= (entityRightWorldX+entity.speed)/gp.tileSize;
                tileNum1=gp.tileM.mapTileNum[entity.map][entityRightCol][entityTopRow];

                tileNum2=gp.tileM.mapTileNum[entity.map][entityRightCol][entityBottomRow];

                if(gp.tileM.tile[tileNum1].collison==true  || gp.tileM.tile[tileNum2].collison==true  )
                    entity.collisonOn=true;

        }

    }

    public void checkTilePlayer(Player entity, boolean girl)
    {
        int X, Y;
        String direction;

        if(girl==true)
        {
            X=entity.GirlWorldX;
            Y=entity.GirlWOrldY;
            direction=entity.girlDirection;
        }
        else
        {
            X=entity.BoyWorldX;
            Y=entity.BoyWorldY;
            direction=entity.direction;
        }

        int entityLeftWorldX= X+entity.solidArea.x;
        int entityRightWorldX= X+entity.solidArea.x+entity.solidArea.width;
        int entityTopWorldY= Y+entity.solidArea.y;
        int entityBottomWorldY= Y+entity.solidArea.y+entity.solidArea.height;

        int entityLeftCol= entityLeftWorldX/gp.tileSize;
        int entityRightCol= entityRightWorldX/gp.tileSize;
        int entityTopRow= entityTopWorldY/gp.tileSize;
        int entityBottomRow= entityBottomWorldY/gp.tileSize;

        int tileNum1, tileNum2;

        switch(direction)
        {
            case "up":
                entityTopRow= (entityTopWorldY-entity.speed)/gp.tileSize;
                tileNum1=gp.tileM.mapTileNum[gp.currentMap][entityLeftCol][entityTopRow];
                tileNum2=gp.tileM.mapTileNum[gp.currentMap][entityRightCol][entityTopRow];

                if(  gp.tileM.tile[tileNum1].collison==true  || gp.tileM.tile[tileNum2].collison==true)
                    entity.collisonOn=true;

                break;

            case "down":

                entityBottomRow= (entityBottomWorldY+entity.speed)/gp.tileSize;
                tileNum1=gp.tileM.mapTileNum[gp.currentMap][entityLeftCol][entityBottomRow];
                tileNum2=gp.tileM.mapTileNum[gp.currentMap][entityRightCol][entityBottomRow];



                if(gp.tileM.tile[tileNum1].collison==true  || gp.tileM.tile[tileNum2].collison==true  )
                    entity.collisonOn=true;

                break;

            case "left":

                entityLeftCol= (entityLeftWorldX-entity.speed)/gp.tileSize;
                tileNum1=gp.tileM.mapTileNum[gp.currentMap][entityLeftCol][entityTopRow];
                tileNum2=gp.tileM.mapTileNum[gp.currentMap][entityLeftCol][entityBottomRow];

                if(gp.tileM.tile[tileNum1].collison==true  || gp.tileM.tile[tileNum2].collison==true  )
                    entity.collisonOn=true;

                break;

            case "right":

                entityRightCol= (entityRightWorldX+entity.speed)/gp.tileSize;
                tileNum1=gp.tileM.mapTileNum[gp.currentMap][entityRightCol][entityTopRow];

                tileNum2=gp.tileM.mapTileNum[gp.currentMap][entityRightCol][entityBottomRow];

                if(gp.tileM.tile[tileNum1].collison==true  || gp.tileM.tile[tileNum2].collison==true  )
                    entity.collisonOn=true;

                break;
        }

    }


    public void check_decoraton_player(boolean girl, Player e)
    {


        Rectangle entity1 = new Rectangle();

        if(girl==true) {
            entity1.x = e.GirlWorldX + e.solidArea.x;
            entity1.y = e.GirlWOrldY + e.solidArea.y;
        }
        else
        {
            entity1.x = e.BoyWorldX + e.solidArea.x;
            entity1.y = e.BoyWorldY + e.solidArea.y;
        }
        entity1.height = e.solidArea.height;
        entity1.width = e.solidArea.width;


        if(gp.currentMap==0)
        for(int i=0; i<gp.decM.current_dec; i++)
        {
            Decoration d=gp.decM.dec[gp.currentMap][i];



                Rectangle entity2 = new Rectangle();

                entity2.x = d.worldX + gp.decM.decSolidArea[d.image_no].x;
                entity2.y = d.worldY +gp.decM.decSolidArea[d.image_no].y;
                entity2.height = gp.decM.decSolidArea[d.image_no].height;
                entity2.width = gp.decM.decSolidArea[d.image_no].width;



                if(entity1.intersects(entity2))
                {
                    if(girl==false)

                    {
                        switch (e.direction) {
                            case "up":
                                e.BoyWorldY += e.speed;
                                break;
                            case "down":
                                e.BoyWorldY -= e.speed;
                                break;
                            case "left":
                                e.BoyWorldX += e.speed;
                                break;
                            case "right":

                                e.BoyWorldX -= e.speed;
                                break;
                        }
                    }
                    else if(girl==true)
                    {
                        switch (e.girlDirection) {
                            case "up":
                                e.GirlWOrldY += e.speed;
                                break;
                            case "down":
                                e.GirlWOrldY -= e.speed;
                                break;
                            case "left":
                                e.GirlWorldX += e.speed;
                                break;
                            case "right":
                                e.GirlWorldX -= e.speed;
                                break;
                        }
                    }


                }




        }


    }

    public void check_object_player(boolean girl, Player e)
    {


        Rectangle entity1 = new Rectangle();

        if(girl==true) {
            entity1.x = e.GirlWorldX + e.solidArea.x;
            entity1.y = e.GirlWOrldY + e.solidArea.y;
        }
        else
        {
            entity1.x = e.BoyWorldX + e.solidArea.x;
            entity1.y = e.BoyWorldY + e.solidArea.y;
        }
        entity1.height = e.solidArea.height;
        entity1.width = e.solidArea.width;

        if(gp.currentMap==0)
        for(int i=0; i<gp.objM.current_obj; i++)
        {
            if(gp.objM.world_obj[gp.currentMap][i]!=null && gp.objM.world_obj[gp.currentMap][i].collison==true) {
            SuperObject d=gp.objM.world_obj[gp.currentMap][i];



            Rectangle entity2 = new Rectangle();

            entity2.x = d.worldX + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.x;
            entity2.y = d.worldY +gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.y;
            entity2.height = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.height;
            entity2.width = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.width;



            if(entity1.intersects(entity2)) {
                if (girl == false) {
                    switch (e.direction) {
                        case "up":
                            e.BoyWorldY += e.speed;
                            break;
                        case "down":
                            e.BoyWorldY -= e.speed;
                            break;
                        case "left":
                            e.BoyWorldX += e.speed;
                            break;
                        case "right":

                            e.BoyWorldX -= e.speed;
                            break;
                    }
                } else if (girl == true) {
                    switch (e.girlDirection) {
                        case "up":
                            e.GirlWOrldY += e.speed;
                            break;
                        case "down":
                            e.GirlWOrldY -= e.speed;
                            break;
                        case "left":
                            e.GirlWorldX += e.speed;
                            break;
                        case "right":
                            e.GirlWorldX -= e.speed;
                            break;
                    }
                }

            }
            }




        }


    }


    public void check_object(Entity e)
    {


        Rectangle entity1 = new Rectangle();


        entity1.x = e.worldX + e.solidArea.x;
        entity1.y = e.worldY + e.solidArea.y;
        entity1.height = e.solidArea.height;
        entity1.width = e.solidArea.width;

        if(gp.currentMap==0)
        for(int i=0; i<gp.objM.current_obj; i++)
        {

                if(gp.objM.world_obj[gp.currentMap][i]!=null && gp.objM.world_obj[gp.currentMap][i].collison==true) {
                    SuperObject d = gp.objM.world_obj[gp.currentMap][i];


                    Rectangle entity2 = new Rectangle();

                    entity2.x = d.worldX + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.x;
                    entity2.y = d.worldY + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.y;
                    entity2.height = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.height;
                    entity2.width = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.width;


                    if (entity1.intersects(entity2)) {
                        e.collisonOn = true;
                    }


                }



        }


    }

    public void check_object_touch(Player e, int i)
    {


        Rectangle entity1 = new Rectangle();


        for(int k=0; k<2; k++) {

            if(k==0) {
                entity1.x = e.BoyWorldX + e.solidArea.x;
                entity1.y = e.BoyWorldY + e.solidArea.y;
                entity1.height = e.solidArea.height;
                entity1.width = e.solidArea.width;
            }
            else
            {
                entity1.x = e.GirlWorldX + e.solidArea.x;
                entity1.y = e.GirlWOrldY + e.solidArea.y;
                entity1.height = e.solidArea.height;
                entity1.width = e.solidArea.width;
            }

            if (gp.objM.world_obj[gp.currentMap][i] != null) {
                SuperObject d = gp.objM.world_obj[gp.currentMap][i];


                Rectangle entity2 = new Rectangle();

                entity2.x = d.worldX + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.x;
                entity2.y = d.worldY + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.y;
                entity2.height = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.height;
                entity2.width = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.width;


                if (entity1.intersects(entity2)) {
                    {

                        gp.player.inventory[gp.objM.world_obj[0][i].id]++;

                            gp.objM.world_obj[gp.currentMap][i] = null;
                    }
                }


            }


        }
    }

    public void check_object_sword_hit(int i) {
        for (int k = 0; k < 2; k++) {

            String action;
            int spriteNum, spriteCounter;

            if(k==0)
            {
                spriteNum=gp.player.boyspriteNum;
                spriteCounter=gp.player.boyspriteCounter;
                action=gp.player.action;
            }
            else
            {
                spriteNum=gp.player.girlspriteNum;
                spriteCounter=gp.player.girlspriteCounter;
                action=gp.player.girl_action;
            }

            if(action=="attack" && spriteCounter==5 && spriteNum==3)
            {

            }
            else
            continue;


            Player e = gp.player;
            Rectangle entity1 = new Rectangle();

            int x, y;
            String direction;
            if (k == 0) {
                x = e.BoyWorldX;
                y = e.BoyWorldY;
                direction = e.direction;
            } else {
                x = e.GirlWorldX;
                y = e.GirlWOrldY;
                direction = e.girlDirection;
            }

            if (direction == "down") {
                entity1.x = x + 25;
                entity1.y = y + 41;
                entity1.height = 32 - 25;
                entity1.width = 57 - 41;
            } else if (direction == "up") {
                entity1.x = x + 25;
                entity1.y = y + 1;
                entity1.height = 32 - 25;
                entity1.width = 18 - 1;
            } else if (direction == "right") {
                entity1.x = x + 35;
                entity1.y = y + 31;
                entity1.height = 57 - 35;
                entity1.width = 39 - 31;
            } else if (direction == "left") {
                entity1.x = x + 0;
                entity1.y = y + 31;
                entity1.height = 22 - 0;
                entity1.width = 39 - 31;
            }



                if (gp.objM.world_obj[gp.currentMap][i] != null) {
                    SuperObject d = gp.objM.world_obj[gp.currentMap][i];


                    Rectangle entity2 = new Rectangle();

                    entity2.x = d.worldX + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.x;
                    entity2.y = d.worldY + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.y;
                    entity2.height = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.height;
                    entity2.width = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.width;


                    if (entity1.intersects(entity2)) {
                        gp.objM.world_obj[gp.currentMap][i].current_state++;

                        gp.player.inventory[gp.objM.world_obj[0][i].id]+=gp.objM.solo_obj[gp.objM.world_obj[0][i].id].increase_amount;

                        if(gp.objM.world_obj[gp.currentMap][i].current_state==gp.objM.world_obj[gp.currentMap][i].max_state)
                            gp.objM.world_obj[gp.currentMap][i]=null;



                    }
                }

            }
        }


    public void check_object_double_sword_hit(int i) {

        boolean boy_hit=false;
        boolean girl_hit=false;


        if(gp.currentMap==0)
        for (int k = 0; k < 2; k++) {

            String action;
            int spriteNum, spriteCounter;

            if(k==0)
            {
                spriteNum=gp.player.boyspriteNum;

                action=gp.player.action;
            }
            else
            {
                spriteNum=gp.player.girlspriteNum;

                action=gp.player.girl_action;
            }

            if(gp.objM.world_obj[gp.currentMap][i].hit_delay<=0 && action=="attack" &&  (spriteNum==2 || spriteNum==3))
            {
                if(k!=0)
                gp.objM.world_obj[gp.currentMap][i].hit_delay=50;

            }
            else
            {
                if(gp.objM.world_obj[gp.currentMap][i].hit_delay>0)
                gp.objM.world_obj[gp.currentMap][i].hit_delay--;
                continue;
            }


            Player e = gp.player;
            Rectangle entity1 = new Rectangle();

            int x, y;
            String direction;
            if (k == 0) {
                x = e.BoyWorldX;
                y = e.BoyWorldY;
                direction = e.direction;
            } else {
                x = e.GirlWorldX;
                y = e.GirlWOrldY;
                direction = e.girlDirection;
            }

            if (direction == "down") {
                entity1.x = x + 25;
                entity1.y = y + 41;
                entity1.height = 32 - 25;
                entity1.width = 57 - 41;
            } else if (direction == "up") {
                entity1.x = x + 25;
                entity1.y = y + 1;
                entity1.height = 32 - 25;
                entity1.width = 18 - 1;
            } else if (direction == "right") {
                entity1.x = x + 35;
                entity1.y = y + 31;
                entity1.height = 57 - 35;
                entity1.width = 39 - 31;
            } else if (direction == "left") {
                entity1.x = x + 0;
                entity1.y = y + 31;
                entity1.height = 22 - 0;
                entity1.width = 39 - 31;
            }



            if (gp.objM.world_obj[gp.currentMap][i] != null) {
                SuperObject d = gp.objM.world_obj[gp.currentMap][i];


                Rectangle entity2 = new Rectangle();

                entity2.x = d.worldX + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.x;
                entity2.y = d.worldY + gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.y;
                entity2.height = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.height;
                entity2.width = gp.objM.solo_obj[gp.objM.world_obj[gp.currentMap][i].id].solidArea.width;


                if (entity1.intersects(entity2)) {

                    System.out.println("Hi");

                    if(k==0)
                        boy_hit=true;
                    else
                        girl_hit=true;


                }
            }

        }

        if(boy_hit==true && girl_hit==true)
        {
            gp.objM.world_obj[gp.currentMap][i].current_state++;

            gp.player.inventory[gp.objM.world_obj[0][i].id]+=gp.objM.solo_obj[gp.objM.world_obj[0][i].id].increase_amount;

            if(gp.objM.world_obj[gp.currentMap][i].current_state==gp.objM.world_obj[gp.currentMap][i].max_state)
                gp.objM.world_obj[gp.currentMap][i]=null;
        }
    }


    public void check_player_enemy_hit(Entity e) {
        for (int k = 0; k < 2; k++) {

            String action;
            int spriteNum, spriteCounter;

            if (k == 0) {
                spriteNum = gp.player.boyspriteNum;
                spriteCounter = gp.player.boyspriteCounter;
                action = gp.player.action;
            } else {
                spriteNum = gp.player.girlspriteNum;
                spriteCounter = gp.player.girlspriteCounter;
                action = gp.player.girl_action;
            }

            if (action == "attack" && spriteCounter == 5 && spriteNum == 3) {

            } else
                continue;


            Player p = gp.player;
            Rectangle entity1 = new Rectangle();

            int x, y;
            String direction;
            if (k == 0) {
                x = p.BoyWorldX;
                y = p.BoyWorldY;
                direction = p.direction;
            } else {
                x = p.GirlWorldX;
                y = p.GirlWOrldY;
                direction = p.girlDirection;
            }

            if (direction == "down") {
                entity1.x = x + 25;
                entity1.y = y + 41;
                entity1.height = 32 - 25;
                entity1.width = 57 - 41;
            } else if (direction == "up") {
                entity1.x = x + 25;
                entity1.y = y + 1;
                entity1.height = 32 - 25;
                entity1.width = 18 - 1;
            } else if (direction == "right") {
                entity1.x = x + 35;
                entity1.y = y + 31;
                entity1.height = 57 - 35;
                entity1.width = 39 - 31;
            } else if (direction == "left") {
                entity1.x = x + 0;
                entity1.y = y + 31;
                entity1.height = 22 - 0;
                entity1.width = 39 - 31;
            }

            Rectangle entity2 = new Rectangle();

            entity2.x = e.worldX + e.damageSolidArea.x;
            entity2.y = e.worldY + e.damageSolidArea.y;
            entity2.height = e.damageSolidArea.height;
            entity2.width = e.damageSolidArea.width;

            if(entity2.intersects(entity1))
            {
                e.got_hit=true;
                e.last_hit_time=300;
                e.current_health-=gp.player.sword_power;
            }
        }
    }

    public void check_enemy_damage_player(Entity e)
    {

        Rectangle entity1 = new Rectangle();


        entity1.x = e.worldX + e.solidArea.x;
        entity1.y = e.worldY + e.solidArea.y;
        entity1.height = e.solidArea.height;
        entity1.width = e.solidArea.width;

        for(int k=0; k<2; k++)
        {
            boolean girl;

            if(k==0)
                girl=true;
            else
                girl=false;

            Rectangle entity2=new Rectangle();

            if(girl==true) {
                entity2.x = gp.player.GirlWorldX + e.solidArea.x;
                entity2.y = gp.player.GirlWOrldY + e.solidArea.y;
            }
            else
            {
                entity2.x = gp.player.BoyWorldX + e.solidArea.x;
                entity2.y = gp.player.BoyWorldY + e.solidArea.y;
            }
            entity2.height = e.solidArea.height;
            entity2.width = e.solidArea.width;

            if(entity1.intersects(entity2) )
            {
                if(girl==true && gp.player.girl_last_hit_time==0)
                {
                    gp.player.girl_last_hit_time=50;
                    gp.player.girl_current_health-=e.hit_damage;
                }
                else if( girl==false && gp.player.last_hit_time==0)
                {
                    gp.player.last_hit_time=50;
                    gp.player.current_health-=e.hit_damage;
                }
            }
        }
    }


    public void check_decoraton(Entity e)
    {


        Rectangle entity1 = new Rectangle();


        entity1.x = e.worldX + e.solidArea.x;
        entity1.y = e.worldY + e.solidArea.y;
        entity1.height = e.solidArea.height;
        entity1.width = e.solidArea.width;

        for(int i=0; i<gp.decM.current_dec; i++)
        {
            Decoration d=gp.decM.dec[0][i];



            Rectangle entity2 = new Rectangle();

            entity2.x = d.worldX + gp.decM.decSolidArea[d.image_no].x;
            entity2.y = d.worldY +gp.decM.decSolidArea[d.image_no].y;
            entity2.height = gp.decM.decSolidArea[d.image_no].height;
            entity2.width = gp.decM.decSolidArea[d.image_no].width;



            if(entity1.intersects(entity2))
            {
                e.collisonOn=true;
            }




        }

        check_object(e);


    }


}

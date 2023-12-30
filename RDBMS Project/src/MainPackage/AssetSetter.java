package MainPackage;

import Enemy.*;
import NPC.DeputyMayor;
import NPC.Mayor;
import NPC.SantaOldMan;
import entity.Dungeon;
import entity.Wizard;

import java.util.Random;

public class AssetSetter {

    GamePanel gp;

    public AssetSetter(GamePanel gp)
    {
        this.gp=gp;
    }

    public void setEnemy() {

   /*     for(int i=0; i<gp.enemy_count; i++)
            gp.enemy[i]=null;*/

        /*for (int i = 0; i < 6; i++) {

            if(gp.enemy[0][i]==null) {

                System.out.println(i);

                gp.enemy[0][i] = new Hedgehog(gp);

                while (true) {
                    Random random1 = new Random();

                    int X = random1.nextInt(4200 - 2500) + 2500;

                    Random random2 = new Random();

                    int Y = random2.nextInt(6900 - 4176) + 4176;


                    gp.enemy[0][i].worldX = X;
                    gp.enemy[0][i].worldY = Y;

                    gp.enemy[0][i].collisonOn = false;

                    gp.cChecker.checkTile(gp.enemy[0][i]);
                    gp.cChecker.check_decoraton(gp.enemy[0][i]);

                    if (gp.enemy[0][i].collisonOn == false)
                        break;

                }
            }
        }*/
     /*   for (int i = 6; i < 20; i++) {

            if(gp.enemy[0][i]==null)
            {
                System.out.println(i);
            gp.enemy[0][i] = new ChombBomb(gp);

            while (true) {
                Random random1 = new Random();

                int X = random1.nextInt(8200 - 880) + 880;

                Random random2 = new Random();

                int Y = random2.nextInt(6900 - 3176) + 3176;


                gp.enemy[0][i].worldX = X;
                gp.enemy[0][i].worldY = Y;

                gp.enemy[0][i].collisonOn=false;

                gp.cChecker.checkTile(gp.enemy[0][i]);
                gp.cChecker.check_decoraton(gp.enemy[0][i]);

                if(gp.enemy[0][i].collisonOn==false)
                    break;

            }
            }
        }

        *//*for(int i=20; i<35; i++)
        {
        if(gp.enemy[0][i]==null)
            {
                System.out.println(i);

            gp.enemy[0][i] = new ChombBomb(gp);
            gp.enemy[0][i].is_destroyable=false;
            gp.enemy[0][i].is_locked=true;
            gp.enemy[0][i].lock_high_x=3000;
            gp.enemy[0][i].lock_low_x=870;
            gp.enemy[0][i].lock_low_y=5600;
            gp.enemy[0][i].lock_high_y=7200;

            while (true) {
                Random random1 = new Random();

                int X = random1.nextInt(1776 - 880) + 880;

                Random random2 = new Random();

                int Y = random2.nextInt(6900 - 5832) + 5832;


                gp.enemy[0][i].worldX = X;
                gp.enemy[0][i].worldY = Y;

                gp.enemy[0][i].collisonOn=false;

                gp.cChecker.checkTile(gp.enemy[0][i]);
                gp.cChecker.check_decoraton(gp.enemy[0][i]);

                if(gp.enemy[0][i].collisonOn==false)
                    break;

            }

}


        }*/
        /*

        for(int i=35; i<50; i++)
        {
        if(gp.enemy[0][i]==null)
            {

                System.out.println(i);



            while (true) {


                Random random1 = new Random();

                int X = random1.nextInt( 8300- 3528) + 3528;

                Random random2 = new Random();

                int Y = random2.nextInt(3700 - 660) + 660;


                gp.enemy[0][i].worldX = X;
                gp.enemy[0][i].worldY = Y;

                gp.enemy[0][i].collisonOn=false;

                gp.cChecker.checkTile(gp.enemy[0][i]);
                gp.cChecker.check_decoraton(gp.enemy[0][i]);

                if(gp.enemy[0][i].collisonOn==false)
                    break;

            }
            }
        }
        */
    /*    gp.enemy[0][40]= new Bull(gp);
        gp.enemy[0][40].worldX=1000;
        gp.enemy[0][40].worldY=7500;

        gp.enemy[0][41]= new Bull(gp);
        gp.enemy[0][41].worldX=1360;
        gp.enemy[0][41].worldY=8080;

        gp.enemy[0][42]= new Bull(gp);
        gp.enemy[0][42].worldX=1856;
        gp.enemy[0][42].worldY=7680;

        gp.enemy[0][43]= new Bull(gp);
        gp.enemy[0][43].worldX=1728;
        gp.enemy[0][43].worldY=7376;

        //island
        gp.enemy[0][44]= new Bull(gp);
        gp.enemy[0][44].worldX=2808;
        gp.enemy[0][44].worldY=8312;
        //island
        gp.enemy[0][45]= new Bull(gp);
        gp.enemy[0][45].worldX=3284;
        gp.enemy[0][45].worldY=8064;

        gp.enemy[0][46]= new Bull(gp);
        gp.enemy[0][46].worldX=3652;
        gp.enemy[0][46].worldY=7376;

        gp.enemy[0][47]= new Bull(gp);
        gp.enemy[0][47].worldX=3838;
        gp.enemy[0][47].worldY=7928;

        gp.enemy[0][48]= new Bull(gp);
        gp.enemy[0][48].worldX=4468;
        gp.enemy[0][48].worldY=7312;

        gp.enemy[0][49]= new Bull(gp);
        gp.enemy[0][49].worldX=5036;
        gp.enemy[0][49].worldY=7128;

        gp.enemy[0][50]= new Bull(gp);
        gp.enemy[0][50].worldX=1640;
        gp.enemy[0][50].worldY=7848;

        //island
        gp.enemy[0][51]= new Bull(gp);
        gp.enemy[0][51].worldX=2676;
        gp.enemy[0][51].worldY=8316;


        for(int i=52; i<80; i++)
        {
         if(gp.enemy[0][i]==null)
            {


                gp.enemy[0][i] = new Pumpkin(gp);

            while (true) {
                Random random1 = new Random();

                int X = random1.nextInt( 7110- 6100) + 6100;

                Random random2 = new Random();

                int Y = random2.nextInt(4790 - 3260) + 3260;


                gp.enemy[0][i].worldX = X;
                gp.enemy[0][i].worldY = Y;

                gp.enemy[0][i].collisonOn=false;

                gp.cChecker.checkTile(gp.enemy[0][i]);
                gp.cChecker.check_decoraton(gp.enemy[0][i]);

                if(gp.enemy[0][i].collisonOn==false)
                    break;

            }
            }
        }

         for(int i=80; i<90; i++) {

            if (gp.enemy[0][i] == null) {

                System.out.println(i);
                gp.enemy[0][i] = new RhinoBettle(gp);

                while (true) {
                    Random random1 = new Random();

                    int X = random1.nextInt(3336 - 1780) + 1780;

                    Random random2 = new Random();

                    int Y = random2.nextInt(2720 - 2160) + 2160;


                    gp.enemy[0][i].worldX = X;
                    gp.enemy[0][i].worldY = Y;

                    gp.enemy[0][i].lock_low_x = 1700;
                    gp.enemy[0][i].lock_high_x = 3350;
                    gp.enemy[0][i].lock_low_y = 2000;
                    gp.enemy[0][i].lock_high_y = 2720;

                    gp.enemy[0][i].collisonOn = false;

                    gp.cChecker.checkTile(gp.enemy[0][i]);
                    gp.cChecker.check_decoraton(gp.enemy[0][i]);

                    if (gp.enemy[0][i].collisonOn == false)
                        break;

                }
            }
        }




        gp.enemy[0][105]= new Plant(gp);
        gp.enemy[0][105].worldX=6264;
        gp.enemy[0][105].worldY=2616;

        gp.enemy[0][106]= new Plant(gp);
        gp.enemy[0][106].worldX=5908;
        gp.enemy[0][106].worldY=2100;

        gp.enemy[0][107]= new Plant(gp);
        gp.enemy[0][107].worldX=7440;
        gp.enemy[0][107].worldY=5756;

        gp.enemy[0][108]= new Plant(gp);
        gp.enemy[0][108].worldX=7416;
        gp.enemy[0][108].worldY=5456;


        gp.enemy[0][109]= new Plant(gp);
        gp.enemy[0][109].worldX=6044;
        gp.enemy[0][109].worldY=1380;


        gp.enemy[0][110]= new Plant(gp);
        gp.enemy[0][110].worldX=7740;
        gp.enemy[0][110].worldY=2672;


        gp.enemy[0][111]= new Plant(gp);
        gp.enemy[0][111].worldX=5480;
        gp.enemy[0][111].worldY=2224;

        gp.enemy[0][112]= new Plant(gp);
        gp.enemy[0][112].worldX=5584;
        gp.enemy[0][112].worldY=2924;


        gp.enemy[0][113]= new Plant(gp);
        gp.enemy[0][113].worldX=7428;
        gp.enemy[0][113].worldY=4640;


        gp.enemy[0][114]= new Plant(gp);
        gp.enemy[0][114].worldX=7788;
        gp.enemy[0][114].worldY=3368;


        gp.enemy[0][115]= new Plant(gp);
        gp.enemy[0][115].worldX=6360;
        gp.enemy[0][115].worldY=2720;

        gp.enemy[0][116]= new Plant(gp);
        gp.enemy[0][116].worldX=7480;
        gp.enemy[0][116].worldY=1988;

        gp.enemy[0][117]= new Plant(gp);
        gp.enemy[0][117].worldX=5716;
        gp.enemy[0][117].worldY=552;

        gp.enemy[0][118]= new Plant(gp);
        gp.enemy[0][118].worldX=6636;
        gp.enemy[0][118].worldY=528;

        gp.enemy[0][119]= new Plant(gp);
        gp.enemy[0][119].worldX=5644;
        gp.enemy[0][119].worldY=1816;*/

        for(int i=0; i<120; i++)
        {
            if(gp.enemy[0][i]!=null)
            gp.enemy[0][i].map=0;
        }


        for(int i=1; i<8; i++)
        gp.enemy[1][i]=new Devil(gp);

        gp.enemy[1][1].worldX=1604;
        gp.enemy[1][1].worldY=2920;

        gp.enemy[1][2].worldX=1604;
        gp.enemy[1][2].worldY=2900;

        gp.enemy[1][3].worldX=1800;
        gp.enemy[1][3].worldY=2920;


        for(int i=8; i<18; i++)
            gp.enemy[1][i]=new Skeleton(gp);

        gp.enemy[1][8].worldX=2100;
        gp.enemy[1][8].worldY=1100;

        gp.enemy[1][9].worldX=1600;
        gp.enemy[1][9].worldY=3000;

        gp.enemy[1][10].worldX=1900;
        gp.enemy[1][10].worldY=2900;


        for(int i=18; i<25; i++)
            gp.enemy[1][i]=new GreenSlime(gp);

        gp.enemy[1][18].worldX=1804;
        gp.enemy[1][18].worldY=2960;
        gp.enemy[1][19].worldX=1904;
        gp.enemy[1][19].worldY=2960;

        gp.enemy[1][20].worldX=2100;
        gp.enemy[1][20].worldY=2960;

        for(int i=0; i<40; i++)
        {
            if(gp.enemy[1][i]!=null)
                gp.enemy[1][i].map=1;
        }

        gp.enemy[1][0]=new Dungeon(gp);

        gp.enemy[2][0]=new Wizard(gp);
        gp.enemy[2][0].worldX=1704;
        gp.enemy[2][0].worldY=1192;
        gp.enemy[2][0].direction="up";
        gp.enemy[2][0].current_state="enemy";

        gp.enemy[3][0]=new FinalBoss(gp);
        gp.enemy[3][0].worldX=1620;
        gp.enemy[3][0].worldY=580;

    }


    public void setNPC()
    {
        gp.npc[0]=new Mayor(gp);
        gp.npc[1]=new DeputyMayor(gp);


    }
}

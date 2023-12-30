package Tile;

import MainPackage.GamePanel;
import MainPackage.UtilityTool;
import entity.Player;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.Buffer;

public class DecorationManager {

    GamePanel gp;

    int decoration_count=800;

    int decoration_varity_count=151;

    public int current_dec=0;

    int water_variety_count=4;
    public Decoration[][] dec;

    public Rectangle[] decSolidArea= new Rectangle[decoration_varity_count];

    public Rectangle teleporterSolidArea=new Rectangle(54,80,128-54, 128-80);
    Decoration [][] water= new Decoration[water_variety_count][30];

    int [] water_count={4,15, 8, 25};

    int [] water_animation_count={12,6, 6, 6};

    BufferedImage [][] water_animation= new BufferedImage[water_variety_count][15];

    Decoration moving_tree= new Decoration();

    Decoration teleporter[]=new Decoration[7];

    BufferedImage [] moving_tree_image= new BufferedImage[6];


    BufferedImage[] dec_image= new BufferedImage[decoration_varity_count];

    BufferedImage [] teleporter_image=new BufferedImage[6];

    public DecorationManager(GamePanel gp)
    {
        this.gp=gp;
        this.dec= new Decoration[gp.maxMap][decoration_count];
        /*this.water[0]= new Decoration[water_count[0]];
        this.water[1]= new Decoration[water_count[1]];
        this.water[2]= new Decoration[water_count[2]];*/

        getDecorationImage();
        setDecorationValues();
        getWaterAnimationImage();
        setWater();
        setDecorationSolidArea();
        set_teleporter();

    }

    public void  getDecorationImage()
    {



        try{
            for(int i=0; i<decoration_varity_count; i++)
            dec_image[i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Decoration/Dec"+i+".png"));

            for(int i=0; i<6; i++)
                moving_tree_image[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Decoration/Moving tree/frame ("+i+").png"));

            for(int i=0; i<6; i++)
                teleporter_image[i]=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Decoration/Teleporter/"+i+".png"));


        }catch (IOException e)
        {
            e.printStackTrace();
        }

    }

    public void getWaterAnimationImage()
    {
        try{
            for(int i=0; i<water_animation_count[0]; i++)
                water_animation[0][i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Water/Type1/frame ("+i+").gif"));

            for(int i=0; i<water_animation_count[1]; i++)
                water_animation[1][i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Water/Type2/frame("+i+").gif"));

            for(int i=0; i<water_animation_count[2]; i++)
                water_animation[2][i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Water/Type3/frame("+i+").gif"));

            for(int i=0; i<water_animation_count[3]; i++)
                water_animation[3][i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Water/Type4/frame ("+i+").gif"));
        }catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public void updateAnimation()
    {
        update_water1();

        update_moving_tree();

        update_teleporter();
    }


    public void set_teleporter()
    {
        for(int i=0; i<teleporter.length; i++)
        {

            teleporter[i]=new Decoration();
        }

        teleporter[0].worldX=11796;
        teleporter[0].worldY=1588;
        teleporter[0].image_no=1;

        teleporter[1].worldX=11656;
        teleporter[1].worldY=1757;
        teleporter[1].image_no=4;

        teleporter[2].worldX=11988;
        teleporter[2].worldY=1860;
        teleporter[2].image_no=3;

        teleporter[3].worldX=12220;
        teleporter[3].worldY=1656;
        teleporter[3].image_no=5;

        teleporter[4].worldX=12300;
        teleporter[4].worldY=1792;
        teleporter[4].image_no=2;

        teleporter[5].worldX=12020;
        teleporter[5].worldY=1436;
        teleporter[5].image_no=0;

        teleporter[6].worldX=12020;
        teleporter[6].worldY=1070;
        teleporter[6].image_no=0;


    }
    public void setWater()
    {
        for(int i=0; i<water_count[0]; i++)
            water[0][i]= new Decoration();

        water_setter(0, 0, 304, 80, 1050, 1000, 0);
        water_setter(0,1, 304, 80, 1200, 1150, 4);
        water_setter(0, 2, 304, 80, 1110, 1300, 3);
        water_setter(0, 3, 304, 80, 1050, 1600, 10);

        for(int i=0; i<water_count[1]; i++)
            water[1][i]= new Decoration();

        water_setter(1, 0, 128, 144, 8576,2592, 3);
        water_setter(1, 1, 136, 144, 9344,2592, 0);
        water_setter(1, 2, 136, 144, 9480,2592, 0);
        water_setter(1,3, 100, 144, 9726,2592, 0);
        water_setter(1,4, 100, 144, 9804,2592, 0);
        water_setter(1,5, 85, 96, 9868,2024, 0);
        water_setter(1,6, 84, 96, 9870,2241, 2);
        water_setter(1,7, 126, 144, 10013,1632, 2);

        water_setter(1,8, 140, 144, 9870,1060, 2);
        water_setter(1,9, 140, 144, 10010,1060, 2);

        water_setter(1,10, 80, 220, 9460,740, 2);
        water_setter(1,11, 80, 220, 9436,740, 2);
        water_setter(1,12, 80, 220, 9516,740, 2);
        water_setter(1,13, 80, 220, 9587,740, 2);
        water_setter(1,14, 80, 135, 9055,965, 2);


        for(int i=0; i<water_count[2]; i++)
            water[2][i]= new Decoration();

        water_setter(2, 0, 35, 144, 8863,2592, 0);
        water_setter(2, 1, 35, 144, 9055,2592, 0);
        water_setter(2, 2, 35, 144, 9199,2592, 0);
        water_setter(2, 3, 35, 144, 10063,2592, 0);

        for(int i=0; i<water_count[3]; i++)
            water[3][i]= new Decoration();

        water_setter(3, 0, 50, 45, 9436,2114, 0);
        water_setter(3, 1, 50, 45, 9486,2114, 0);
        water_setter(3, 2, 50, 45, 9536,2114, 0);
        water_setter(3, 3, 50, 45, 9586,2114, 0);
        water_setter(3, 4, 50, 45, 9636,2114, 0);
        water_setter(3, 5, 50, 45, 9686,2114, 0);
        water_setter(3, 6, 50, 45, 9710,2114, 0);
        water_setter(3, 7, 50, 45, 9436,1735, 2);
        water_setter(3, 8, 50, 45, 9486,1735, 2);
        water_setter(3, 9, 50, 45, 9536,1735, 2);
        water_setter(3, 10, 50, 45, 9586,1735, 2);
        water_setter(3, 11, 50, 45, 9613,1735, 2);

        water_setter(3, 12, 50, 45, 9436,1396, 4);
        water_setter(3, 13, 50, 45, 9486,1396, 4);
        water_setter(3, 14, 50, 45, 9536,1396, 4);
        water_setter(3, 15, 50, 45, 9586,1396, 4);
        water_setter(3, 16, 50, 45, 9613,1396, 4);

        water_setter(3, 17, 50, 45, 9436,1196, 3);
        water_setter(3, 18, 50, 45, 9486,1196, 3);
        water_setter(3, 19, 50, 45, 9536,1196, 3);
        water_setter(3, 20, 50, 45, 9586,1196, 3);
        water_setter(3, 21, 50, 45, 9613,1196, 3);
    }





    public void setDecorationValues()
    {
        moving_tree.worldX=11168;
        moving_tree.worldY=2056;
        moving_tree.height=248;
                moving_tree.width=305;

        for(int i=0; i<decoration_count; i++)
            dec[0][i]=new Decoration();

        decoration_setter(current_dec,  1900, 775, 450, 330, 1 );
        decoration_setter(current_dec,  1730, 1690, 225, 306, 2 );
        decoration_setter(current_dec,  1980, 1690, 225, 306, 2 );
        decoration_setter(current_dec,  2240, 1690, 225, 306, 2 );
        decoration_setter(current_dec,  2680, 1065, 260, 320, 6 );
        decoration_setter(current_dec,  2940, 1237, 180, 150, 3 );
        decoration_setter(current_dec,  1730, 1220, 225, 306, 2 );
        decoration_setter(current_dec,  1980, 1220, 225, 306, 2 );
        decoration_setter(current_dec,  2240, 1220, 225, 306, 2 );
        decoration_setter(current_dec,  2640, 1685, 260, 320, 7 );
        decoration_setter(current_dec,  2875, 1847, 180, 150, 3 );
        decoration_setter(current_dec,  3055, 1847, 180, 150, 3 );
        decoration_setter(current_dec,  1170, 1850, 240, 306, 2 );
        decoration_setter(current_dec,  1900, 2050, 150, 150, 0 );
        decoration_setter(current_dec  ,2400,2120,  250, 220, 17 );
        decoration_setter(current_dec,  2600, 2280, 150, 265, 8 );
        decoration_setter(current_dec,  2365, 2300, 150, 265, 8 );
        decoration_setter(current_dec,  1970, 2300, 150, 265, 8 );
        decoration_setter(current_dec,  2080, 2280, 150, 265, 8 );
        decoration_setter(current_dec,  2180, 2310, 150, 265, 8 );
        decoration_setter(current_dec,  2480, 2310, 150, 265, 8 );
        decoration_setter(current_dec,  2290, 2380, 150, 265, 8 );
        decoration_setter(current_dec,  1780, 2350, 150, 265, 8 );
        decoration_setter(current_dec,  2500, 2400, 150, 265, 8 );
        decoration_setter(current_dec,  954, 760, 18, 200, 11 );
        decoration_setter(current_dec,  954, 960, 18, 200, 11 );
        decoration_setter(current_dec,  954, 1160, 18, 200, 11 );
        decoration_setter(current_dec,  954, 1360, 18, 200, 11 );
        decoration_setter(current_dec,  954, 1560, 18, 200, 11 );
        decoration_setter(current_dec,  954, 1760, 18, 200, 11 );
        decoration_setter(current_dec,  954, 1960, 18, 200, 11 );
        decoration_setter(current_dec,  954, 570, 18, 200, 11 );
        decoration_setter(current_dec,  954, 2160, 18, 200, 11 );
        decoration_setter(current_dec,  954, 2360, 18, 200, 11 );
        decoration_setter(current_dec,  954, 2560, 18, 300, 11 );
        decoration_setter(current_dec,  3438, 760, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 960, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 1160, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 1360, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 1560, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 1760, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 1960, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 570, 18, 200, 12);
        decoration_setter(current_dec,  3438, 2160, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 2360, 18, 200, 12 );
        decoration_setter(current_dec,  3438, 2560, 18, 300, 12 );
        decoration_setter(current_dec,  954, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  1208, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  1330, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  1685, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  1540, 2755, 185, 130, 21 );
        decoration_setter(current_dec,  1938, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  2192, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  2446, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  2700, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  2954, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  3200, 2755, 254, 128, 10 );
        decoration_setter(current_dec,  972, 570, 254, 128, 13 );
        decoration_setter(current_dec,  1208, 570, 254, 128, 13 );
        decoration_setter(current_dec,  1461, 570, 254, 128, 13 );
        decoration_setter(current_dec,  1684, 570, 254, 128, 13 );
        decoration_setter(current_dec,  1938, 570, 254, 128, 13 );
        decoration_setter(current_dec,  2192, 570, 254, 128, 13 );
        decoration_setter(current_dec,  2446, 570, 254, 128, 13 );
        decoration_setter(current_dec,  2700, 570, 254, 128, 13 );
        decoration_setter(current_dec,  2954, 570, 254, 128, 13 );
        decoration_setter(current_dec,  3185, 570, 254, 128, 13 );
        decoration_setter(current_dec,  2860, 2280, 150, 265, 8 );
        decoration_setter(current_dec,  2670, 2330, 150, 265, 8 );
        decoration_setter(current_dec,  3100, 2350, 150, 265, 8 );
        decoration_setter(current_dec,  1850, 2390, 150, 265, 8 );
        decoration_setter(current_dec,  3010, 2400, 150, 265, 8 );
        decoration_setter(current_dec,  2070, 2430, 150, 265, 8 );
        decoration_setter(current_dec,  2190, 2420, 150, 265, 8 );
        decoration_setter(current_dec,  2790, 2420, 150, 265, 8 );
        decoration_setter(current_dec,  2960, 2490, 150, 265, 8 );
        decoration_setter(current_dec,  3200, 2360, 150, 265, 8 );
        decoration_setter(current_dec,  2580, 2480, 150, 265, 8 );
        decoration_setter(current_dec,  2340, 2470, 150, 265, 8 );
        decoration_setter(current_dec ,1050,2300,  200, 110, 16 );
        decoration_setter(current_dec,1350,2370,  110, 110, 15 );
        decoration_setter(current_dec  ,1120,2450,  110, 110, 15 );
        decoration_setter(current_dec,1290,2490,  110, 110, 15 );
        decoration_setter(current_dec,1390,2280,  110, 100, 18 );
        decoration_setter(current_dec,2300,2180,  68, 69, 19 );
        decoration_setter(current_dec,2290,2280,  68, 69, 19 );
        decoration_setter(current_dec,2700,2200,  68, 69, 19 );
        decoration_setter(current_dec,2850,2120,  68, 69, 19 );
        decoration_setter(current_dec,  1670, 2400, 150, 265, 8 );
        decoration_setter(current_dec,  2720, 2470, 150, 265, 8 );
        decoration_setter(current_dec,  1800, 2480, 150, 265, 8 );
        decoration_setter(current_dec,  1945, 2460, 150, 265, 8 );
        decoration_setter(current_dec,  2460, 2470, 150, 265, 8 );
        decoration_setter(current_dec,  2030, 2490, 150, 265, 8 );
        decoration_setter(current_dec,  2390, 600, 170, 265, 14 );
        decoration_setter(current_dec,  2560, 600, 170, 265, 14 );
        decoration_setter(current_dec,  2730, 600, 170, 265, 14 );
        decoration_setter(current_dec,  2900, 600, 170, 265, 14 );
        decoration_setter(current_dec,  3070, 600, 170, 265, 14 );
        decoration_setter(current_dec,  3240, 600, 170, 265, 14 );
        decoration_setter(current_dec,  2330, 800, 170, 265, 14 );
        decoration_setter(current_dec,  2490, 800, 170, 265, 14 );
        decoration_setter(current_dec,  2650, 800, 170, 265, 14 );
        decoration_setter(current_dec,  2810, 800, 170, 265, 14 );
        decoration_setter(current_dec,  2970, 800, 170, 265, 14 );
        decoration_setter(current_dec,  3140, 800, 170, 265, 14 );
        decoration_setter(current_dec,  3290, 800, 170, 265, 14 );
        decoration_setter(current_dec ,2880,1560,  110, 110, 15 );
        decoration_setter(current_dec ,3000,1560,  110, 110, 15 );
        decoration_setter(current_dec ,3120,1560,  110, 110, 15 );
        decoration_setter(current_dec ,2980,1660,  110, 110, 15 );
        decoration_setter(current_dec ,3100,1660,  110, 110, 15 );
        decoration_setter(current_dec ,2980,1130,  110, 110, 18 );
        decoration_setter(current_dec ,3100,1130,  110, 110, 15 );
        decoration_setter(current_dec ,1660,900,  110, 110, 15 );
        decoration_setter(current_dec ,1790,900,  110, 110, 18 );  //grassland decoration
        decoration_setter(current_dec ,1790,3100,  190, 200, 29 );
        decoration_setter(current_dec ,3190,3400,  190, 200, 29 );
        decoration_setter(current_dec ,2090,3850,  190, 200, 29 );
        decoration_setter(current_dec ,2590,4500,  190, 200, 29 );
        decoration_setter(current_dec ,1290,5800,  190, 200, 29 );
        decoration_setter(current_dec ,3990,1050,  190, 200, 29 );
        decoration_setter(current_dec ,2880,4700,  190, 200, 29 );
        decoration_setter(current_dec ,1190,3600,  190, 200, 29 );
        decoration_setter(current_dec ,3390,5600,  150, 150, 27 );
        decoration_setter(current_dec ,2290,4650,  150, 150, 27 );
        decoration_setter(current_dec ,3890,6600,  150, 150, 27 );
        decoration_setter(current_dec ,2900,3600,  150, 150, 27 );
        decoration_setter(current_dec ,3390,5600,  150, 150, 27 );
        decoration_setter(current_dec ,3890,2400,  150, 150, 27 );
        decoration_setter(current_dec ,3990,6500,  150, 150, 27 );
        decoration_setter(current_dec, 2590, 5820, 90, 90, 37);
        decoration_setter(current_dec, 1780, 4444, 90, 90, 37);
        decoration_setter(current_dec, 3050, 3910, 90, 90, 37);
        decoration_setter(current_dec, 3470, 6220, 90, 90, 37);
        decoration_setter(current_dec, 2160, 4900, 90, 90, 37);
        decoration_setter(current_dec, 3980, 5650, 90, 90, 37);
        decoration_setter(current_dec, 1390, 4020, 90, 90, 37);
        decoration_setter(current_dec, 2640, 6170, 90, 90, 37);
        decoration_setter(current_dec, 3540, 5230, 90, 90, 37);
        decoration_setter(current_dec, 1890, 3820, 90, 90, 37);
        decoration_setter(current_dec, 2760, 4320, 90, 90, 37);
        decoration_setter(current_dec, 3280, 5910, 90, 90, 37);
        decoration_setter(current_dec, 1340, 4980, 90, 90, 37);
        decoration_setter(current_dec, 3820, 4730, 90, 90, 37);
        decoration_setter(current_dec, 3890, 1870, 90, 90, 37);
        decoration_setter(current_dec, 2870, 4880, 90, 80, 31);
        decoration_setter(current_dec, 2190, 2970, 90, 80, 31);
        decoration_setter(current_dec, 3620, 4170, 90, 80, 31);
        decoration_setter(current_dec, 1580, 4360, 90, 80, 31);
        decoration_setter(current_dec, 3890, 5120, 90, 80, 31);
        decoration_setter(current_dec, 1330, 3860, 90, 80, 31);
        decoration_setter(current_dec, 3090, 6560, 90, 80, 31);
        decoration_setter(current_dec, 2490, 3980, 90, 80, 31);
        decoration_setter(current_dec, 1960, 4320, 90, 80, 31);
        decoration_setter(current_dec, 3550, 6240, 90, 80, 31);
        decoration_setter(current_dec, 1760, 4620, 90, 80, 31);
        decoration_setter(current_dec, 2970, 5050, 90, 80, 31);
        decoration_setter(current_dec, 3280, 5460, 90, 80, 31);
        decoration_setter(current_dec, 1170, 3520, 90, 80, 31);
        decoration_setter(current_dec, 2460, 5640, 90, 80, 31);
        decoration_setter(current_dec, 3980, 4660, 90, 80, 31);
        decoration_setter(current_dec, 1790, 3870, 90, 80, 31);
        decoration_setter(current_dec, 2650, 6330, 90, 80, 31);
        decoration_setter(current_dec, 3400, 4770, 90, 80, 31);
        decoration_setter(current_dec, 2610, 3960, 105, 88, 30);
        decoration_setter(current_dec, 1450, 3200, 105, 88, 30);
        decoration_setter(current_dec, 3120, 4490, 105, 88, 30);
        decoration_setter(current_dec, 1390, 2970, 105, 88, 30);
        decoration_setter(current_dec, 3980, 5430, 105, 88, 30);
        decoration_setter(current_dec, 2260, 3620, 105, 88, 30);
        decoration_setter(current_dec, 1660, 6470, 190, 200, 26);
        decoration_setter(current_dec, 1260, 6220, 300, 300, 22);
        decoration_setter(current_dec, 1060, 6020, 150, 140, 23);
        decoration_setter(current_dec, 1360, 6020, 150, 140, 23);
        decoration_setter(current_dec, 960, 6220, 88, 95, 43);
        decoration_setter(current_dec, 970, 6420, 88, 95, 43);
        decoration_setter(current_dec, 1160, 6675, 120, 130, 35);
        decoration_setter(current_dec, 1460, 6670, 120, 130, 35);
        decoration_setter(current_dec, 1740, 6680, 120, 130, 35);
        decoration_setter(current_dec ,990,5600,  160, 200, 39 );
        decoration_setter(current_dec ,2200,4370,  160, 200, 39 );
        decoration_setter(current_dec ,2910,5750,  160, 200, 39 );
        decoration_setter(current_dec ,2090,5170,  160, 200, 39 );
        decoration_setter(current_dec ,1190,4360,  160, 200, 39 );
        decoration_setter(current_dec ,2350,3200,  160, 200, 39 );
        decoration_setter(current_dec ,3530,2170,  160, 200, 39 );
        decoration_setter(current_dec ,3890,3930,  160, 200, 39 );
        decoration_setter(current_dec ,960,3000,  160, 200, 39 );
        decoration_setter(current_dec ,3830,3424,  160, 200, 39 );
        decoration_setter(current_dec ,3550,4400,  160, 200, 39 );
        decoration_setter(current_dec, 1576, 4623, 110, 90, 25);
        decoration_setter(current_dec, 2758, 5392, 110, 90, 25);
        decoration_setter(current_dec, 2156, 4178, 110, 90, 25);
        decoration_setter(current_dec, 3987, 5897, 110, 90, 25);
        decoration_setter(current_dec, 3324, 2990, 110, 90, 25);
        decoration_setter(current_dec, 3412, 3935, 110, 90, 25);
        decoration_setter(current_dec, 1876, 4089, 110, 90, 25);
        decoration_setter(current_dec, 3199, 5767, 110, 90, 25);
        decoration_setter(current_dec, 3845, 1098, 110, 90, 25);
        decoration_setter(current_dec, 983, 3331, 110, 90, 25);
        decoration_setter(current_dec, 3987, 6676, 110, 90, 25);
        decoration_setter(current_dec, 3612, 5023, 110, 90, 25);
        decoration_setter(current_dec, 1499, 4687, 110, 90, 25);
        decoration_setter(current_dec, 2998, 5256, 110, 90, 25);
        decoration_setter(current_dec, 1776, 4198, 110, 90, 25);
        decoration_setter(current_dec, 3887, 5637, 110, 90, 25);
        decoration_setter(current_dec, 1432, 4123, 110, 90, 25);
        decoration_setter(current_dec, 3721, 5189, 110, 90, 25);
        decoration_setter(current_dec, 2134, 4629, 110, 100, 38);
        decoration_setter(current_dec, 3446, 5012, 110, 100, 38);
        decoration_setter(current_dec, 2665, 5890, 110, 100, 38);
        decoration_setter(current_dec, 1579, 4111, 110, 100, 38);
        decoration_setter(current_dec, 3980, 5332, 110, 100, 38);
        decoration_setter(current_dec, 2266, 4267, 110, 100, 38);
        decoration_setter(current_dec, 3691, 5599, 110, 100, 38);
        decoration_setter(current_dec, 2812, 4810, 110, 100, 38);
        decoration_setter(current_dec, 1723, 3978, 110, 100, 38);
        decoration_setter(current_dec, 3275, 5486, 110, 100, 38);
        decoration_setter(current_dec, 2398, 4610, 110, 100, 38);
        decoration_setter(current_dec, 3111, 5823, 110, 100, 38);
        decoration_setter(current_dec, 3861, 2983, 110, 100, 38);
        decoration_setter(current_dec, 3231, 4203, 110, 100, 38);
        decoration_setter(current_dec, 1752, 5243, 110, 100, 38);
        decoration_setter(current_dec, 2096, 6520, 110, 100, 38);
        decoration_setter(current_dec, 2560, 3568, 88, 98, 28);
        decoration_setter(current_dec, 3230, 4000, 88, 98, 28);
        decoration_setter(current_dec, 3888, 4472, 88, 98, 28);
        decoration_setter(current_dec, 3680, 6058, 88, 98, 28);
        decoration_setter(current_dec, 2480, 5064, 88, 98, 28);
        decoration_setter(current_dec, 1432, 4336, 88, 98, 28); //mud
        decoration_setter(current_dec ,1500,7400,  150, 150, 48 );
        decoration_setter(current_dec ,1100,7300,  150, 150, 48 );
        decoration_setter(current_dec ,1730,8000,  150, 150, 48 );
        decoration_setter(current_dec ,2260,7560,  150, 150, 48 );
        decoration_setter(current_dec ,3832,7400,  150, 150, 48 );
        decoration_setter(current_dec ,3968,7710,  150, 150, 45 );
        decoration_setter(current_dec ,1938,7240,  150, 150, 45 );
        decoration_setter(current_dec ,1200,7840,  150, 150, 45 );
        decoration_setter(current_dec ,3750,7020,  150, 150, 50 );
        decoration_setter(current_dec ,1680,7488,  150, 150, 50 );
        decoration_setter(current_dec ,1020,7640,  150, 150, 44 );
        decoration_setter(current_dec ,4340,7484,  120, 120, 49 );
        decoration_setter(current_dec ,1480,7200,  120, 120, 49 );
        decoration_setter(current_dec ,1120,7985,  120, 120, 49 );//Forest
        decoration_setter(current_dec ,6488,3976,  298, 319, 59 );
        decoration_setter(current_dec ,6744,4160,  197, 187, 65 );
        decoration_setter(current_dec ,6352,3686,  197, 187, 65 );
        decoration_setter(current_dec ,6320,3946,  144, 137, 66 );
        decoration_setter(current_dec ,6688,3776,  144, 137, 66 );
        decoration_setter(current_dec ,6112,3666,  144, 137, 66 );
        decoration_setter(current_dec ,6616,3636,  144, 137, 66 );
        decoration_setter(current_dec ,6392,4264,  144, 137, 66 );
        decoration_setter(current_dec ,6608,4432,  280, 280, 71 );
        decoration_setter(current_dec ,6880,4590,  280, 280, 68 );
        decoration_setter(current_dec ,6350,4430,  260, 260, 73 );
        decoration_setter(current_dec ,6870,4400,  260, 260, 73 );
        decoration_setter(current_dec ,6840,4440,  260, 260, 73 );
        decoration_setter(current_dec ,6400,4536,  280, 280, 72 );
        decoration_setter(current_dec ,6260,3214,  240, 240, 74 );
        decoration_setter(current_dec ,6400,3304,  200, 200, 78 );
        decoration_setter(current_dec ,6870,3310,  240, 240, 74 );
        decoration_setter(current_dec ,6680,3324,  240, 240, 74 );
        decoration_setter(current_dec ,5950,3416,  200, 200, 78 );
        decoration_setter(current_dec ,6240,3480,  200, 200, 78 );
        decoration_setter(current_dec ,6870,3632,  140, 140, 76 );
        decoration_setter(current_dec ,6560,3512,  140, 140, 76 );
        decoration_setter(current_dec ,6024,3896,  140, 140, 76 );
        decoration_setter(current_dec ,5920,3752,  140, 140, 76 );
        decoration_setter(current_dec ,6580,3784,  140, 140, 76 );
        decoration_setter(current_dec ,6512,4400,  140, 140, 76 );
        decoration_setter(current_dec ,6944,4104,  140, 140, 76 );
        decoration_setter(current_dec ,6776,3952,  140, 140, 76 );
        decoration_setter(current_dec ,6688,4704,  140, 140, 76 );
        decoration_setter(current_dec ,5656,3520,  137, 154, 56 );
        decoration_setter(current_dec ,5928,3272,  137, 154, 56 );
        decoration_setter(current_dec ,6200,4184,  137, 154, 56 );
        decoration_setter(current_dec ,6472,3536,  90, 92, 67 );
        decoration_setter(current_dec ,6776,3576,  90, 92, 67 );
        decoration_setter(current_dec ,6464,3936,  90, 92, 67 );
        decoration_setter(current_dec ,6848,4384,  90, 92, 67 );
        decoration_setter(current_dec ,5616,5444,  320, 320, 69 );
        decoration_setter(current_dec ,5112,5444,  320, 320, 69 );
        decoration_setter(current_dec ,5090,5148,  360, 360, 70 );
        decoration_setter(current_dec ,5340,5148,  360, 360, 70 );
        decoration_setter(current_dec ,5580,5148,  360, 360, 70 ); //house
        decoration_setter(current_dec ,5360,5380,  280, 350, 51 );  //476-190=286
        decoration_setter(current_dec, 5512, 4098, 252, 126, 60);
        decoration_setter(current_dec, 4887, 6721, 252, 126, 60);
        decoration_setter(current_dec, 6328,5960, 252, 126, 60);
        decoration_setter(current_dec, 6424,5112, 252, 126, 60);
        decoration_setter(current_dec, 4376, 3673, 252, 126, 60);
        decoration_setter(current_dec, 4678, 5149, 252, 126, 60);
        decoration_setter(current_dec, 5279, 4356, 252, 126, 60);
        decoration_setter(current_dec, 4392, 4821, 252, 126, 60);
        decoration_setter(current_dec, 5464,3360, 136, 121, 62);
        decoration_setter(current_dec, 4784,3456, 136, 121, 62);
        decoration_setter(current_dec, 5065, 6476, 136, 121, 62);
        decoration_setter(current_dec, 5973, 6712, 136, 121, 62);
        decoration_setter(current_dec, 5648,6168, 136, 121, 62);
        decoration_setter(current_dec, 4800,4968, 136, 121, 62);
        decoration_setter(current_dec, 5947, 4529, 136, 121, 62);
        decoration_setter(current_dec, 5786, 6613, 136, 121, 62);
        decoration_setter(current_dec, 6616,5800, 136, 121, 62);
        decoration_setter(current_dec, 6656,5488, 136, 121, 62);
        decoration_setter(current_dec, 4767, 6748, 136, 121, 62);
        decoration_setter(current_dec, 4778, 5867, 136, 121, 62);
        decoration_setter(current_dec, 5512, 4495, 136, 121, 62);
        decoration_setter(current_dec, 4847, 5679, 136, 121, 62);
        decoration_setter(current_dec, 4896,3360, 253, 270, 52);
        decoration_setter(current_dec, 4296,3376, 253, 270, 52);
        decoration_setter(current_dec, 4512,3448, 253, 270, 52);
        decoration_setter(current_dec, 4984,3512, 253, 270, 52);
        decoration_setter(current_dec, 4648,3558, 253, 270, 52);
        decoration_setter(current_dec, 4847, 3679, 253, 270, 52);
        decoration_setter(current_dec, 5336,3752, 253, 270, 52);
        decoration_setter(current_dec, 5128,3776, 253, 270, 52);
        decoration_setter(current_dec, 4440,3808, 253, 270, 52);
        decoration_setter(current_dec, 4654,3840, 253, 270, 52);
        decoration_setter(current_dec, 4936,3920, 253, 270, 52);
        decoration_setter(current_dec, 5288,3976, 253, 270, 52);
        decoration_setter(current_dec, 5150,4084, 253, 270, 52);
        decoration_setter(current_dec, 4376,4080, 253, 270, 52);
        decoration_setter(current_dec, 4736,4104, 253, 270, 52);
        decoration_setter(current_dec, 5728,4144, 253, 270, 52);
        decoration_setter(current_dec, 4960,4192, 253, 270, 52);
        decoration_setter(current_dec, 5464,4193, 253, 270, 52);
        decoration_setter(current_dec, 4584,4248, 253, 270, 52);
        decoration_setter(current_dec, 4688,3352, 114, 108, 64);
        decoration_setter(current_dec, 5236,3632, 114, 108, 64);
        decoration_setter(current_dec, 5584,3960, 114, 108, 64);
        decoration_setter(current_dec, 5704,4392, 114, 108, 64);
        decoration_setter(current_dec, 4408,4408, 114, 108, 64);
        decoration_setter(current_dec, 5000,4456, 114, 108, 64);
        decoration_setter(current_dec, 5832,4504, 114, 108, 64);
        decoration_setter(current_dec, 5128,4840, 114, 108, 64);
        decoration_setter(current_dec, 6576,4944, 114, 108, 64);
        decoration_setter(current_dec, 5784,5080, 114, 108, 64);
        decoration_setter(current_dec, 6832,5088, 114, 108, 64);
        decoration_setter(current_dec, 6884,5232, 114, 108, 64);
        decoration_setter(current_dec, 6484,5296, 114, 108, 64);
        decoration_setter(current_dec, 6684,5672, 114, 108, 64);
        decoration_setter(current_dec, 6116,5768, 114, 108, 64);
        decoration_setter(current_dec, 5176,4544, 236, 236, 54);
        decoration_setter(current_dec, 4392,4560, 236, 236, 54);
        decoration_setter(current_dec, 4912,4576, 236, 236, 54);
        decoration_setter(current_dec, 4654,4578, 236, 236, 54);
        decoration_setter(current_dec, 5408,4592, 236, 236, 54);
        decoration_setter(current_dec, 5408,4592, 236, 236, 54);
        decoration_setter(current_dec, 5664,4616, 236, 236, 54);
        decoration_setter(current_dec, 5920,4704, 236, 236, 54);
        decoration_setter(current_dec, 5344,4728, 236, 236, 54);
        decoration_setter(current_dec, 4816,4792, 236, 236, 54);
        decoration_setter(current_dec, 5576,4840, 236, 236, 54);
        decoration_setter(current_dec, 5216,4856, 236, 236, 54);
        decoration_setter(current_dec, 4568,4864, 236, 236, 54);
        decoration_setter(current_dec, 5856,4880, 236, 236, 54);
        decoration_setter(current_dec, 4936,4920, 236, 236, 54);
        decoration_setter(current_dec, 4416,4952, 236, 236, 54);
        decoration_setter(current_dec, 6120,4953, 236, 236, 54);
        decoration_setter(current_dec, 5440,4968, 236, 236, 54);
        decoration_setter(current_dec, 6302,5048, 236, 236, 54);
        decoration_setter(current_dec, 5976,5092, 236, 236, 54);
        decoration_setter(current_dec, 4930,5250, 214, 230, 53);
        decoration_setter(current_dec, 4484,5248, 214, 230, 53);
        decoration_setter(current_dec, 4680,5296, 214, 230, 53);
        decoration_setter(current_dec, 6620,5280, 214, 230, 53);
        decoration_setter(current_dec, 6156,5352, 214, 230, 53);
        decoration_setter(current_dec, 6324,5392, 214, 230, 53);
        decoration_setter(current_dec, 4892,5464, 214, 230, 53);
        decoration_setter(current_dec, 4716,5510, 214, 230, 53);
        decoration_setter(current_dec, 4468,5576, 214, 230, 53);
        decoration_setter(current_dec, 6812,5402, 214, 230, 53);
        decoration_setter(current_dec, 5988,5448, 214, 230, 53);
        decoration_setter(current_dec, 6116,5504, 214, 230, 53);
        decoration_setter(current_dec, 6524,5480, 214, 230, 53);
        decoration_setter(current_dec, 6258,5600, 214, 230, 53);
        decoration_setter(current_dec, 6356,5680, 214, 230, 53);
        decoration_setter(current_dec, 6764,5704, 214, 230, 53);
        decoration_setter(current_dec, 4720,5976, 336, 336, 75);
        decoration_setter(current_dec, 4548,6000, 336, 336, 75);
        decoration_setter(current_dec, 5020,6032, 336, 336, 75);
        decoration_setter(current_dec, 4336,6048, 336, 336, 75);
        decoration_setter(current_dec, 4780,6240, 336, 336, 75);
        decoration_setter(current_dec, 4596,6280, 336, 336, 75);
        decoration_setter(current_dec, 4276,6288, 336, 336, 75);
        decoration_setter(current_dec, 4932,6208, 336, 336, 75);
        decoration_setter(current_dec, 4452,6880, 336, 336, 75);
        decoration_setter(current_dec, 5196,6344, 336, 336, 75);
        decoration_setter(current_dec, 4802,6468, 336, 336, 75);
        decoration_setter(current_dec, 5052,6608, 336, 336, 75);
        decoration_setter(current_dec, 4274,6638, 336, 336, 75);
        decoration_setter(current_dec, 4516,6638, 336, 336, 75);
        decoration_setter(current_dec, 4452,6880, 336, 336, 75);
        decoration_setter(current_dec, 5452, 6064, 194, 241, 55);
        decoration_setter(current_dec, 5804, 6072, 194, 241, 55);
        decoration_setter(current_dec, 5788, 6192, 194, 241, 55);
        decoration_setter(current_dec, 5940, 6240, 194, 241, 55);
        decoration_setter(current_dec, 5548, 6304, 194, 241, 55);
        decoration_setter(current_dec, 5700, 6397, 194, 241, 55);
        decoration_setter(current_dec, 6044, 6400, 194, 241, 55);
        decoration_setter(current_dec, 5900, 6500, 194, 241, 55);
        decoration_setter(current_dec, 5612, 6640, 194, 241, 55);
        decoration_setter(current_dec, 6092, 6696, 194, 241, 55);
        decoration_setter(current_dec, 5772, 6840, 194, 241, 55);
        decoration_setter(current_dec, 5940, 6952, 194, 241, 55);
        decoration_setter(current_dec, 6076,5944, 200, 200, 77);
        decoration_setter(current_dec, 6304,6068, 200, 200, 77);
        decoration_setter(current_dec, 6525,6136, 200, 200, 77);
        decoration_setter(current_dec, 6324,6248, 200, 200, 77);
        decoration_setter(current_dec, 6538,6336, 200, 200, 77);
        decoration_setter(current_dec, 4532,6552, 121, 110, 61);
        decoration_setter(current_dec, 5420,6712, 121, 110, 61);
        decoration_setter(current_dec, 5348,6224, 121, 110, 61);
        decoration_setter(current_dec, 5140,5944, 121, 110, 61);
        decoration_setter(current_dec, 6236,6560, 121, 110, 61);
        decoration_setter(current_dec, 6588,6008, 121, 110, 61);
        decoration_setter(current_dec, 5908,5928, 121, 110, 61);
        decoration_setter(current_dec, 4988,6024, 121, 110, 61);
        decoration_setter(current_dec, 5636,6016, 121, 110, 61);
        decoration_setter(current_dec, 6172,6288, 121, 110, 61);//swamp
        decoration_setter(current_dec, 6709,1820, 300, 280, 104);
        decoration_setter(current_dec, 7420,508, 450, 300, 83);
        decoration_setter(current_dec, 7644,745, 350, 420, 95);//house 613-190=423
        decoration_setter(current_dec, 7935,928, 250, 250, 86);
        decoration_setter(current_dec, 7502,1220, 210, 155, 85);
        decoration_setter(current_dec, 7732,1220, 210, 155, 85);
        decoration_setter(current_dec, 7940,1184, 145, 160, 88);
        decoration_setter(current_dec, 7400,802, 145, 160, 88);
        decoration_setter(current_dec, 7924,720, 160, 175, 87);
        decoration_setter(current_dec, 7412,904, 282, 214, 94);
        decoration_setter(current_dec, 6276,1200, 374, 412, 84);
        decoration_setter(current_dec, 6348,2760, 262, 350, 91);
        decoration_setter(current_dec, 6660,2968, 180, 212, 103);
        decoration_setter(current_dec, 7660,1992, 180, 212, 103);
        decoration_setter(current_dec, 7812,3048, 180, 212, 103);
        decoration_setter(current_dec, 7204,4000, 180, 212, 103);
        decoration_setter(current_dec, 5908,2352, 180, 212, 103);
        decoration_setter(current_dec, 5844,616, 180, 212, 103);
        decoration_setter(current_dec, 6836,936, 160, 110, 96);
        decoration_setter(current_dec, 7140,1616, 160, 110, 96);
        decoration_setter(current_dec, 5412,1824, 160, 110, 96);
        decoration_setter(current_dec, 5612,2608, 160, 110, 96);
        decoration_setter(current_dec, 6332,896, 160, 110, 96);
        decoration_setter(current_dec, 7460,2984, 160, 110, 96);
        decoration_setter(current_dec, 7356,3856, 160, 110, 96);
        decoration_setter(current_dec, 7540,5128, 160, 110, 96);
        decoration_setter(current_dec, 7540,5128, 160, 110, 96);
        decoration_setter(current_dec, 5708,2864, 160, 110, 96);
        decoration_setter(current_dec, 5660,1312, 130, 105, 99);
        decoration_setter(current_dec, 6996,1248, 130, 105, 99);
        decoration_setter(current_dec, 5972,1968, 130, 105, 99);
        decoration_setter(current_dec, 4716,2496, 130, 105, 99);
        decoration_setter(current_dec, 6932,3016, 130, 105, 99);
        decoration_setter(current_dec, 7524,4736, 130, 105, 99);
        decoration_setter(current_dec, 7476,5264, 130, 105, 99);
        decoration_setter(current_dec, 7436,5864, 130, 105, 99);
        decoration_setter(current_dec, 7124,3144, 130, 105, 99);
        decoration_setter(current_dec, 5892,2224, 130, 105, 99);
        decoration_setter(current_dec, 4956,3128, 130, 105, 99);
        decoration_setter(current_dec, 4524,1488, 130, 105, 99);
        decoration_setter(current_dec, 6796,528, 130, 105, 99);
        decoration_setter(current_dec, 5580,672, 130, 105, 99);
        decoration_setter(current_dec, 6804,2400, 150, 170, 101);
        decoration_setter(current_dec, 7940,2520, 150, 170, 101);
        decoration_setter(current_dec, 5308,2576, 150, 170, 101);
        decoration_setter(current_dec, 6492,1616, 150, 170, 101);
        decoration_setter(current_dec, 7524,2088, 150, 170, 101);
        decoration_setter(current_dec, 7572,2720, 150, 170, 101);
        decoration_setter(current_dec, 6036,2512, 150, 170, 101);
        decoration_setter(current_dec, 7268,3632, 150, 170, 101);
        decoration_setter(current_dec, 7564,4272, 150, 170, 101);
        decoration_setter(current_dec, 7444,4976, 150, 170, 101);
        decoration_setter(current_dec, 7204,2328, 150, 170, 101);
        decoration_setter(current_dec, 6140,576, 150, 170, 101);
        decoration_setter(current_dec, 5860,904, 270, 310, 79);
        decoration_setter(current_dec, 7036,616, 270, 310, 79);
        decoration_setter(current_dec, 7996,1880, 270, 310, 79);
        decoration_setter(current_dec, 4556,2896, 270, 310, 79);
        decoration_setter(current_dec, 6164,2728, 180, 190, 80);
        decoration_setter(current_dec, 7604,1608, 180, 190, 80);
        decoration_setter(current_dec, 7652,2408, 180, 190, 80);
        decoration_setter(current_dec, 7716,3552, 180, 190, 80);
        decoration_setter(current_dec, 7252,4440, 180, 190, 80);
        decoration_setter(current_dec, 5676,824, 180, 190, 80);
        decoration_setter(current_dec, 6572,632, 170, 170, 92);
        decoration_setter(current_dec, 6420,2096, 170, 170, 92);
        decoration_setter(current_dec, 6420,2352, 170, 170, 92);
        decoration_setter(current_dec, 5436,2336, 170, 170, 92);
        decoration_setter(current_dec, 7820,1856, 170, 170, 92);
        decoration_setter(current_dec, 7388,4096, 170, 170, 92);
        decoration_setter(current_dec, 7452,5584, 170, 170, 92);
        decoration_setter(current_dec, 7412,1520, 156, 228, 90);
        decoration_setter(current_dec, 5708,2382, 156, 228, 90);
        decoration_setter(current_dec, 6140,2272, 156, 228, 90);
        decoration_setter(current_dec, 5484,1248, 156, 228, 90);
        decoration_setter(current_dec, 4452,1896, 156, 228, 90);
        decoration_setter(current_dec, 4484,2704, 156, 228, 90);
        decoration_setter(current_dec, 6468,1000, 150, 130, 100);
        decoration_setter(current_dec, 5644,2280, 150, 130, 100);
        decoration_setter(current_dec, 5572,1544, 150, 130, 100);
        decoration_setter(current_dec, 4484,880, 150, 130, 100);
        decoration_setter(current_dec, 4652,2256, 150, 130, 100);
        decoration_setter(current_dec, 5380,2840, 150, 130, 100);
        decoration_setter(current_dec, 7308,2600, 150, 130, 100);
        decoration_setter(current_dec, 7316,5128, 150, 130, 100);
        decoration_setter(current_dec, 7252,5704, 150, 130, 100);
        decoration_setter(current_dec, 7844,2400, 150, 130, 100);
        decoration_setter(current_dec, 7916,1536, 150, 130, 100);
        decoration_setter(current_dec, 6676,898, 68, 116, 81);
        decoration_setter(current_dec, 5420,952, 68, 116, 81);
        decoration_setter(current_dec, 5380,1528, 68, 116, 81);
        decoration_setter(current_dec, 5860,2456, 68, 116, 81);
        decoration_setter(current_dec, 5484,2504, 68, 116, 81);
        decoration_setter(current_dec, 6916,2768, 68, 116, 81);
        decoration_setter(current_dec, 7400,1800, 68, 116, 81);
        decoration_setter(current_dec, 7268,1952, 68, 116, 81);
        decoration_setter(current_dec, 7532,4032, 68, 116, 81);
        decoration_setter(current_dec, 7150,2840, 68, 116, 81);
        decoration_setter(current_dec, 5876,1616, 68, 116, 81);
        decoration_setter(current_dec, 6028,584, 68, 116, 81);
        decoration_setter(current_dec, 6244,936, 130, 138, 97);
        decoration_setter(current_dec, 6676,1208, 130, 138, 97);
        decoration_setter(current_dec, 6828,1208, 130, 138, 97);
        decoration_setter(current_dec, 6004,1456, 130, 138, 97);
        decoration_setter(current_dec, 5572,904, 130, 138, 97);
        decoration_setter(current_dec, 5508,2592, 130, 138, 97);
        decoration_setter(current_dec, 4700,2064, 130, 138, 97);
        decoration_setter(current_dec, 6636,2496, 130, 138, 97);
        decoration_setter(current_dec, 7596,3784, 130, 138, 97);
        decoration_setter(current_dec, 7684,1808, 130, 138, 97);
        decoration_setter(current_dec, 5884,1350, 130, 138, 97);
        decoration_setter(current_dec, 4868,2704, 130, 138, 97);
        decoration_setter(current_dec, 6356,632, 100, 130, 98);
        decoration_setter(current_dec, 5836,1208, 100, 130, 98);
        decoration_setter(current_dec, 6724,928, 100, 130, 98);
        decoration_setter(current_dec, 7212,1224, 100, 130, 98);
        decoration_setter(current_dec, 7364,2048, 100, 130, 98);
        decoration_setter(current_dec, 7108,2448, 100, 130, 98);
        decoration_setter(current_dec, 7436,3584, 100, 130, 98);
        decoration_setter(current_dec, 7436,5312, 100, 130, 98);
        decoration_setter(current_dec, 6156,1080, 130, 145, 82);
        decoration_setter(current_dec, 5556,2032, 130, 145, 82);
        decoration_setter(current_dec, 6084,2152, 130, 145, 82);
        decoration_setter(current_dec, 6132,2976, 130, 145, 82);
        decoration_setter(current_dec, 5844,3080, 130, 145, 82);
        decoration_setter(current_dec, 8036,2360, 130, 145, 82);
        decoration_setter(current_dec, 7612,3392, 130, 145, 82);
        decoration_setter(current_dec, 7100,3928, 130, 145, 82);
        decoration_setter(current_dec, 7652,1472, 130, 145, 82);
        decoration_setter(current_dec, 5404,1924, 210, 278, 89);
        decoration_setter(current_dec, 7644,2872, 210, 278, 89);
        decoration_setter(current_dec, 5964,2766, 210, 278, 89);//stone
        decoration_setter(current_dec, 9268,2152, 500, 300, 105);
        decoration_setter(current_dec, 9778,2365, 270, 200, 106);
        decoration_setter(current_dec, 9444,1864, 300, 120, 113);
        decoration_setter(current_dec, 9448,560, 170, 193, 112);
        decoration_setter(current_dec, 9608,490, 230, 246, 111);
        decoration_setter(current_dec, 9848,512, 130, 100, 110);
        decoration_setter(current_dec, 9854,600, 130, 100, 110);
        decoration_setter(current_dec, 9952,680, 130, 100, 110);
        decoration_setter(current_dec, 9968,520, 154, 151, 108);
        decoration_setter(current_dec, 9904,2800, 200, 241, 109);
        decoration_setter(current_dec, 8732,664, 300, 278, 121);
        decoration_setter(current_dec, 8172,560, 300, 278, 121);
        decoration_setter(current_dec, 8390,1112, 300, 278, 121);
        decoration_setter(current_dec, 8330,784, 300, 278, 121);
        decoration_setter(current_dec, 8176,2344, 240, 285, 120);
        decoration_setter(current_dec, 8368,2284, 240, 285, 120);
        decoration_setter(current_dec, 8680,2326, 240, 285, 120);
        decoration_setter(current_dec, 8160,1400, 240, 285, 120);
        decoration_setter(current_dec, 8656,952, 240, 285, 120);
        decoration_setter(current_dec, 9976,2384, 440, 380, 107);
        decoration_setter(current_dec, 8912,1880, 120, 140, 116);
        decoration_setter(current_dec, 9120,736, 120, 140, 116);
        decoration_setter(current_dec, 8492,1832, 120, 140, 116);
        decoration_setter(current_dec, 10144,568, 120, 140, 116);
        decoration_setter(current_dec, 8688,520, 120, 140, 116);
        decoration_setter(current_dec, 9776,1680, 120, 140, 116);
        decoration_setter(current_dec, 9664,1296, 75, 74, 118);
        decoration_setter(current_dec, 9792,744, 75, 74, 118);
        decoration_setter(current_dec, 9208,1376, 75, 74, 118);
        decoration_setter(current_dec, 8952,1216, 75, 74, 118);
        decoration_setter(current_dec, 9944,2136, 75, 74, 118);
        decoration_setter(current_dec, 9078,1440, 120, 200, 114);
        decoration_setter(current_dec, 9608,2420, 120, 200, 114);
        decoration_setter(current_dec, 9920,1280, 120, 200, 114);
        decoration_setter(current_dec, 8440,1552, 120, 200, 114);
        decoration_setter(current_dec, 9320,600, 120, 200, 114);
        decoration_setter(current_dec, 9624,1552, 120, 200, 114);
        decoration_setter(current_dec, 9656,808, 105, 160, 122);
        decoration_setter(current_dec, 9784,1504, 105, 160, 122);
        decoration_setter(current_dec, 8760,1368, 105, 160, 122);
        decoration_setter(current_dec, 9104,2344, 105, 160, 122);
        decoration_setter(current_dec, 8840,1240, 105, 160, 122);
        decoration_setter(current_dec, 8896,1648, 66, 60, 123);
        decoration_setter(current_dec, 8784,2152, 66, 60, 123);
        decoration_setter(current_dec, 9080,2072, 66, 60, 123);
        decoration_setter(current_dec, 9656,1752, 66, 60, 123);
        decoration_setter(current_dec, 9896,2528, 66, 60, 123);
        decoration_setter(current_dec, 9800,2144, 66, 60, 123);
        decoration_setter(current_dec, 8872,1728, 66, 60, 123);
        decoration_setter(current_dec, 9224,864, 66, 60, 123);
        decoration_setter(current_dec, 9944,1544, 80, 69, 119);
        decoration_setter(current_dec, 8272,1272, 80, 69, 119);
        decoration_setter(current_dec, 8744,1552, 80, 69, 119);
        decoration_setter(current_dec, 9088,2504, 80, 69, 119);
        decoration_setter(current_dec, 9264,2368, 80, 69, 119);
        decoration_setter(current_dec, 8376,2072, 80, 69, 119);
        decoration_setter(current_dec, 10184,752, 80, 69, 119);
        decoration_setter(current_dec, 9168,1184, 105, 60, 117);
        decoration_setter(current_dec, 8960,2232, 105, 60, 117);
        decoration_setter(current_dec, 8400,1456, 105, 60, 117);
        decoration_setter(current_dec, 9328,976, 105, 60, 117);
        decoration_setter(current_dec, 8400,2160, 105, 60, 117);
        decoration_setter(current_dec, 8904,2392, 143, 115, 115);
        decoration_setter(current_dec, 10288,1464, 143, 115, 115);
        decoration_setter(current_dec, 10384,2120, 143, 115, 115);
        decoration_setter(current_dec, 8224,1064, 143, 115, 115);
        decoration_setter(current_dec, 9168,584, 143, 115, 115);//Desert
        decoration_setter(current_dec, 12192,720, 140, 120, 125);
        decoration_setter(current_dec, 11835,760, 150, 155, 124);
        decoration_setter(current_dec, 11968,656, 271, 320, 150);  //861-190=671
        decoration_setter(current_dec, 12208,832, 130, 133, 128);
        decoration_setter(current_dec, 11944,2104, 193, 180, 132);
        decoration_setter(current_dec, 12248,2102, 157, 170, 131);
        decoration_setter(current_dec, 12064,2224, 254, 228, 141);
        decoration_setter(current_dec, 12288,2400, 180, 169, 144);
        decoration_setter(current_dec, 11952,2424, 106, 93, 133);
        decoration_setter(current_dec, 12128,2464, 106, 93, 133);
        decoration_setter(current_dec, 11504,1088, 169, 120, 145);
        decoration_setter(current_dec, 10920,2000, 169, 120, 145);
        decoration_setter(current_dec, 12344,2568, 169, 120, 145);
        decoration_setter(current_dec, 10456,624, 169, 120, 145);
        decoration_setter(current_dec, 11112,1024, 169, 120, 145);

        decoration_setter(current_dec, 10744,480, 197, 231, 142);
        decoration_setter(current_dec, 11544,552, 197, 231, 142);
        decoration_setter(current_dec, 10656,544, 197, 231, 142);
        decoration_setter(current_dec, 10408,832, 197, 231, 142);
        decoration_setter(current_dec, 10960,1128, 197, 231, 142);
        decoration_setter(current_dec, 11472,728, 197, 231, 142);


        decoration_setter(current_dec, 10880,584, 135, 260, 129);
        decoration_setter(current_dec, 11216,720, 130, 215, 130);
        decoration_setter(current_dec, 11088,544, 126, 193, 146);
        decoration_setter(current_dec, 11024,800, 100, 155, 138);
        decoration_setter(current_dec, 10856,776, 120, 120, 139);
        decoration_setter(current_dec, 11024,704, 120, 120, 139);
        decoration_setter(current_dec, 11296,576, 120, 120, 139);
        decoration_setter(current_dec, 11288,888, 70, 98, 147);
        decoration_setter(current_dec, 10928,928, 70, 98, 147);
        decoration_setter(current_dec, 11144,864, 70, 98, 147);


        decoration_setter(current_dec, 11304,1296, 300, 240, 134);
        decoration_setter(current_dec, 10624,1040, 236, 242, 135);
        decoration_setter(current_dec, 10920,1504, 270, 320, 126);



        decoration_setter(current_dec, 10616,2376, 199, 213, 143);
        decoration_setter(current_dec, 10480,2488, 199, 213, 143);
        decoration_setter(current_dec, 10880,2328, 199, 213, 143);
        decoration_setter(current_dec, 11120,2480, 199, 213, 143);
        decoration_setter(current_dec, 10728,2176, 199, 213, 143);
        decoration_setter(current_dec, 11536,2248, 199, 213, 143);
        decoration_setter(current_dec, 11592,2392, 199, 213, 143);
        decoration_setter(current_dec, 11832,2392, 199, 213, 143);
        decoration_setter(current_dec, 11360,2432, 199, 213, 143);
        decoration_setter(current_dec, 10840,2495, 199, 213, 143);
        decoration_setter(current_dec, 11800,2184, 199, 213, 143);

        decoration_setter(current_dec, 10624,1400, 202, 237, 140);
        decoration_setter(current_dec, 10544,1976, 202, 237, 140);
        decoration_setter(current_dec, 11240,1064, 202, 237, 140);
        decoration_setter(current_dec, 11312,1800, 202, 237, 140);

        decoration_setter(current_dec, 10552,1728, 280, 220, 127);



        decoration_setter(current_dec, 12040,2552, 133, 142, 148);
        decoration_setter(current_dec, 11256,2368, 133, 142, 148);
        decoration_setter(current_dec, 10496,2344, 133, 142, 148);
        decoration_setter(current_dec, 11000,2168, 133, 142, 148);
        decoration_setter(current_dec, 11784,2560, 133, 142, 148);
        decoration_setter(current_dec, 12384,2264, 133, 142, 148);
        decoration_setter(current_dec, 11680,2088, 133, 142, 148);

        decoration_setter(current_dec, 11552,952, 100, 114, 136);
        decoration_setter(current_dec, 11616,960, 100, 114, 136);
        decoration_setter(current_dec, 10576,752, 100, 114, 136);
        decoration_setter(current_dec, 10488,1144, 100, 114, 136);
        decoration_setter(current_dec, 10776,1976, 100, 114, 136);
        decoration_setter(current_dec, 11128,1928, 100, 114, 136);
        decoration_setter(current_dec, 11672,1392, 100, 114, 136);
        decoration_setter(current_dec, 12400,2072, 100, 114, 136);
        decoration_setter(current_dec, 11436,2080, 100, 114, 136);
        decoration_setter(current_dec, 11160,1264, 100, 114, 136);
        decoration_setter(current_dec, 12128,2072, 100, 114, 136);

        decoration_setter(current_dec, 11304,1592, 105, 103, 149);
        decoration_setter(current_dec, 10584,2240, 105, 103, 149);
        decoration_setter(current_dec, 10576,1304, 105, 103, 149);
        decoration_setter(current_dec, 11240,1712, 105, 103, 149);
        decoration_setter(current_dec, 10448,1296, 105, 103, 149);
        decoration_setter(current_dec, 11576,1976, 105, 103, 149);


    }

    public void setDecorationSolidArea() {
        for (int i = 0; i < decoration_varity_count; i++)
            decSolidArea[i] = new Rectangle();

        decSolidArea[0] = new Rectangle(23, 67, 100, 75);
        decSolidArea[1]= new Rectangle(19, 91, 412, 180);
        decSolidArea[2]=new Rectangle(14,95, 186, 192);
        decSolidArea[3]=new Rectangle(4,37, 168-4, 142-37);
        decSolidArea[4]=new Rectangle();
        decSolidArea[5]=new Rectangle();
        decSolidArea[6]=new Rectangle(29, 118, 236-29, 309-118);
        decSolidArea[7]=new Rectangle(24, 102, 204-24, 274-102);
        decSolidArea[8]=new Rectangle(41, 217, 96-41, 264-217);
        decSolidArea[9]=new Rectangle();
        decSolidArea[10]=new Rectangle(0,80,254, 140-80);
        decSolidArea[11]=new Rectangle(0,0, 17, 199);
        decSolidArea[12]=new Rectangle(0,0, 17,199);
        decSolidArea[13]=new Rectangle(0,85, 253, 140-85);
        decSolidArea[14]=new Rectangle(34, 206, 123-34,262-206);
        decSolidArea[15]=new Rectangle(7,24, 97-7,120-24);
        decSolidArea[16]=new Rectangle(10,30, 193-10, 109-30);
        decSolidArea[17]= new Rectangle(12, 28, 238-12, 217-28);
        decSolidArea[18]= new Rectangle(6,14,98-6,100-14);
        decSolidArea[19]=new Rectangle(4, 24, 62-4, 64-24);
        decSolidArea[20]=new Rectangle(27,123, 83-27, 168-123);
        decSolidArea[21]= new Rectangle(0,0,0,0); //used but no solid area
        decSolidArea[22]= new Rectangle(15,111,276-15,300-111);
        decSolidArea[23]=new Rectangle(2,52, 140-2,134-52);
        decSolidArea[24]= new Rectangle();
        decSolidArea[25]= new Rectangle(10,44, 120-10, 127-44);
        decSolidArea[26]= new Rectangle(6,76,174-6,200-76);
        decSolidArea[27]= new Rectangle(1,38, 131, 148-38);
        decSolidArea[28]= new Rectangle(10,35, 81-10, 86-35);
        decSolidArea[29]= new Rectangle(42, 154, 126-42, 197-154);
        decSolidArea[30]= new Rectangle(9, 34, 87-9, 82-34);
        decSolidArea[31]= new Rectangle(4,35,71-4,79-35);
        decSolidArea[32]= new Rectangle();
        decSolidArea[33]= new Rectangle();
        decSolidArea[34]=new Rectangle();
        decSolidArea[35]=new Rectangle(7, 55, 133-7, 126-55);
        decSolidArea[36]= new Rectangle(4,32, 82-4, 64-32);
        decSolidArea[37]= new Rectangle(8, 32, 81-8, 86-32);
        decSolidArea[38]= new Rectangle(24,31, 92-24, 89-31);
        decSolidArea[39]=new Rectangle(47, 155, 120-47, 196-155);
        decSolidArea[40]=new Rectangle();
        decSolidArea[41]=new Rectangle();
        decSolidArea[42]=new Rectangle();
        decSolidArea[43]= new Rectangle(7,25,78-7, 81-25);
        decSolidArea[44]= new Rectangle(17, 45, 135-17, 141-45);
        decSolidArea[45]= new Rectangle(17,40, 134-17, 150-40);
        decSolidArea[46]= new Rectangle();
        decSolidArea[47]=new Rectangle();
        decSolidArea[48]=new Rectangle(17, 40, 132-17, 146-40);
        decSolidArea[49]=new Rectangle(26,36, 99-26, 101-36);
        decSolidArea[50]=new Rectangle(17, 43, 133-17, 141-43);

        decSolidArea[51]= new Rectangle(23, 80, 255-23, 360-80);
        decSolidArea[52]=new Rectangle(65, 200, 172-65, 280-200);
        decSolidArea[53]=new Rectangle(64, 168, 153-64, 235-168);
        decSolidArea[54]= new Rectangle(71, 185, 173-71, 242-185);
        decSolidArea[55]= new Rectangle(57, 183, 142-57, 240-183);
        decSolidArea[56]= new Rectangle(21,54,121-21,165-54);
        decSolidArea[57]=new Rectangle();
        decSolidArea[58]=new Rectangle();
        decSolidArea[59]=new Rectangle(11, 121, 265-11, 330-121);
        decSolidArea[60]=new Rectangle(4,44, 230-4, 107-44);
        decSolidArea[61]=new Rectangle(10, 35, 107-10, 120-35);
        decSolidArea[62]=new Rectangle(11,41, 113-11, 120-41);
        decSolidArea[63]=new Rectangle();
        decSolidArea[64]=new Rectangle(7, 28, 102-7, 115-28);
        decSolidArea[65]= new Rectangle(16, 81, 177-16, 195-81);
        decSolidArea[66]=new Rectangle(20, 92, 105-20, 145-92);
        decSolidArea[67]=new Rectangle(14, 33, 79-14, 98-33);
        decSolidArea[68]= new Rectangle(58, 200, 221-58, 270-200);
        decSolidArea[69]=new Rectangle(100, 228, 195-100, 290-228);
        decSolidArea[70]=new Rectangle(116, 285, 203-116, 347-285);
        decSolidArea[71]=new Rectangle(92, 199, 201-92, 250-199);
        decSolidArea[72]=new Rectangle(35, 139, 230-35, 273-139);
        decSolidArea[73]= new Rectangle(89, 169, 174-89, 217-169);
        decSolidArea[74]= new Rectangle(98, 167, 149-98, 207-167);
        decSolidArea[75]=new Rectangle(104, 223, 213-104, 302-223);
        decSolidArea[76]=new Rectangle(60, 107, 94-60, 134-107);
        decSolidArea[77]=new Rectangle(78, 149, 143-78, 200-149);
        decSolidArea[78]=new Rectangle(58, 142, 138-58, 178-142);
        decSolidArea[79]=new Rectangle(23, 136, 249-23, 315-136);
        decSolidArea[80]= new Rectangle(11, 113,164-11, 190-113);
        decSolidArea[81]=new Rectangle(15,93, 29-15, 101-93);
        decSolidArea[82]=new Rectangle(12, 50, 107-12, 145-50);
        decSolidArea[83]=new Rectangle(30, 184, 206-30, 300-184);
        decSolidArea[84]=new Rectangle(37, 123, 244-37, 400-123);
        decSolidArea[85]=new Rectangle(47, 155, 185-47, 155-146);
        decSolidArea[86]= new Rectangle(25, 190, 97-25, 246-190);
        decSolidArea[87]=new Rectangle(21, 116, 123-21, 180-116);
        decSolidArea[88]=new Rectangle(26, 103, 112-26, 169-103);
        decSolidArea[89]=new Rectangle(22, 196, 130-22, 272-196);
        decSolidArea[90]=new Rectangle(27, 175, 116-27, 230-175);
        decSolidArea[91]=new Rectangle(63, 239, 183-63, 355-239);
        decSolidArea[92]=new Rectangle(68, 139, 99-68, 165-139);
        decSolidArea[93]=new Rectangle();
        decSolidArea[94]=new Rectangle(149, 170, 239-149, 220-170);
        decSolidArea[95]=new Rectangle(39, 242, 293-39, 410-242);
        decSolidArea[96]=new Rectangle(23, 38, 125-23, 110-38);
        decSolidArea[97]=new Rectangle(34, 108, 92-34, 137-108);
        decSolidArea[98]=new Rectangle(15, 99, 74-15, 138-99);
        decSolidArea[99]=new Rectangle(19, 50, 110-19, 110-50);
        decSolidArea[100]=new Rectangle(8, 23, 68-8,70-23);
        decSolidArea[101]=new Rectangle(43, 114, 110-43, 175-114);
        decSolidArea[102]=new Rectangle();
        decSolidArea[103]=new Rectangle(28, 152, 140-28, 220-152);
        decSolidArea[104]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[105]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[106]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[107]=new Rectangle(161, 191, 271-161, 225-191);
        decSolidArea[108]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[109]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[110]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[111]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[112]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[113]=new Rectangle(); //used but player cant reach..might todo later
        decSolidArea[114]=new Rectangle(41, 176, 91-41, 210-176);
        decSolidArea[115]=new Rectangle(16, 55, 125-16, 113-55);
        decSolidArea[116]=new Rectangle(29, 102, 87-29, 140-102);
        decSolidArea[117]=new Rectangle(9, 26, 80-9, 60-26);
        decSolidArea[118]= new Rectangle(12, 45, 54-12, 69-45);
        decSolidArea[119]= new Rectangle(8, 36, 66-8, 69-36);
        decSolidArea[120]= new Rectangle(62, 217, 169-62, 282-217);
        decSolidArea[121]= new Rectangle(91, 213, 166-91, 273-213);
        decSolidArea[122]= new Rectangle(48, 118, 67-48, 165-118);
        decSolidArea[123]= new Rectangle(3,22,57-3, 65-22);



    }

    public void decoration_setter(int i, int x, int y, int height, int width, int image)
    {
        dec[0][i].worldX=x;
        dec[0][i].worldY=y;
        dec[0][i].height=height;
        dec[0][i].width=width;
        dec[0][i].image_no=image;

        current_dec++;


    }

    public void draw(Graphics2D g2)
    {

        if(gp.currentMap==0)
        {
            for(int i=0; i<decoration_count; i++)
            {

                int screenX= dec[gp.currentMap][i].worldX-gp.player.worldX+gp.player.screenX;
                int screenY= dec[gp.currentMap][i].worldY-gp.player.worldY+gp.player.screenY;

                if(dec[gp.currentMap][i].worldX +gp.screenWidth>gp.player.worldX-gp.player.screenX &&
                        dec[gp.currentMap][i].worldX-gp.screenWidth<gp.player.worldX+gp.player.screenX &&
                        dec[gp.currentMap][i].worldY+gp.screenHeight>gp.player.worldY-gp.player.screenY &&
                        dec[gp.currentMap][i].worldY -gp.screenHeight<gp.player.worldY+gp.player.screenY)
                {
                    g2.drawImage(dec_image[dec[gp.currentMap][i].image_no], screenX, screenY, dec[gp.currentMap][i].height, dec[gp.currentMap][i].width, null);
                }
            }
        }

        int screenX= moving_tree.worldX-gp.player.worldX+gp.player.screenX;
        int screenY= moving_tree.worldY-gp.player.worldY+gp.player.screenY;

        if(moving_tree.worldX +gp.screenWidth>gp.player.worldX-gp.player.screenX &&
                moving_tree.worldX-gp.screenWidth<gp.player.worldX+gp.player.screenX &&
                moving_tree.worldY+gp.screenHeight>gp.player.worldY-gp.player.screenY &&
                moving_tree.worldY -gp.screenHeight<gp.player.worldY+gp.player.screenY)
        {
            g2.drawImage(moving_tree_image[moving_tree.image_no], screenX, screenY, moving_tree.height, moving_tree.width, null);
        }


        for(int i=0; i<teleporter.length; i++)
        {
             screenX= teleporter[i].worldX-gp.player.worldX+gp.player.screenX;
             screenY= teleporter[i].worldY-gp.player.worldY+gp.player.screenY;

            if(teleporter[i].worldX +gp.screenWidth>gp.player.worldX-gp.player.screenX &&
                    teleporter[i].worldX-gp.screenWidth<gp.player.worldX+gp.player.screenX &&
                    teleporter[i].worldY+gp.screenHeight>gp.player.worldY-gp.player.screenY &&
                    teleporter[i].worldY -gp.screenHeight<gp.player.worldY+gp.player.screenY)
            {
                g2.drawImage(teleporter_image[teleporter[i].image_no], screenX, screenY, 180, 170, null);
            }
        }



    }

    public void draw_water(Graphics2D g2)
    {

        for(int j=0; j<water_variety_count; j++)
        {
            for(int i=0; i<water_count[j]; i++)
            {

                int screenX= water[j][i].worldX-gp.player.worldX+gp.player.screenX;
                int screenY= water[j][i].worldY-gp.player.worldY+gp.player.screenY;

                if(water[j][i].worldX +gp.screenWidth>gp.player.worldX-gp.player.screenX &&
                        water[j][i].worldX-gp.screenWidth<gp.player.worldX+gp.player.screenX &&
                        water[j][i].worldY+gp.screenHeight>gp.player.worldY-gp.player.screenY &&
                        water[j][i].worldY -gp.screenHeight<gp.player.worldY+gp.player.screenY)
                {
                    g2.drawImage(water_animation[j][water[j][i].image_no], screenX, screenY, water[j][i].height, water[j][i].width, null);
                }
            }
        }





    }

    public void update_water1()
    {

        for(int j=0; j<water_variety_count; j++)
        {
            for(int i=0; i<water_count[j]; i++)
            {
                water[j][i].spriteCounter++;

                if (water[j][i].spriteCounter > 9) {
                    water[j][i].image_no = (++water[j][i].image_no) % water_animation_count[j];
                    water[j][i].spriteCounter= 0;
                }
            }
        }



    }

    public void update_moving_tree()
    {

        moving_tree.spriteCounter++;

                if (moving_tree.spriteCounter > 9) {
                    moving_tree.image_no = (++moving_tree.image_no) % 6;
                    moving_tree.spriteCounter= 0;
                }





    }

    public void water_setter(int k, int i, int height, int width, int x, int y, int image)
    {
        water[k][i].worldX=x;
        water[k][i].worldY=y;
        water[k][i].height=height;
        water[k][i].width=width;
        water[k][i].image_no=image;
    }

    boolean boy_collison=true;

    public int next_teleporter=1;

    public void update_teleporter()
    {
        int teleporter_collison=check_teleporter_collison();



        if(teleporter_collison!=-1) {
            if (teleporter_collison == next_teleporter)
                next_teleporter++;
            else
                next_teleporter = 1;


            if (next_teleporter == 6) {
                if (boy_collison == true) {
                    gp.player.BoyWorldX = 12076;
                    gp.player.BoyWorldY = 1228;
                    gp.player.direction = "down";
                    next_teleporter = 0;
                }
            } else {
                if (boy_collison == true) {
                    gp.player.BoyWorldX = 12076;
                    gp.player.BoyWorldY = 1588;
                    gp.player.direction = "down";
                }
            }
        }
    }



    public int check_teleporter_collison()
    {
        Player e= gp.player;

        for(int k=0; k<2; k++) {
            Rectangle entity1 = new Rectangle();

            if (k==0) {
                entity1.x = e.GirlWorldX + e.solidArea.x;
                entity1.y = e.GirlWOrldY + e.solidArea.y;
            } else {
                entity1.x = e.BoyWorldX + e.solidArea.x;
                entity1.y = e.BoyWorldY + e.solidArea.y;
            }
            entity1.height = e.solidArea.height;
            entity1.width = e.solidArea.width;


            if (gp.currentMap == 0)
                for (int i = 0; i < teleporter.length; i++) {
                    Decoration d = teleporter[i];


                    Rectangle entity2 = new Rectangle();

                    entity2.x = d.worldX + teleporterSolidArea.x;
                    entity2.y = d.worldY + teleporterSolidArea.y;
                    entity2.height = teleporterSolidArea.height;
                    entity2.width = teleporterSolidArea.width;


                    if (entity1.intersects(entity2)) {

                        if (k==1)
                            boy_collison=true;
                        else
                            boy_collison=false;

                        return teleporter[i].image_no;



                    }


                }
        }

        return -1;
    }


}

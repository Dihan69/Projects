package Hud;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class HudManager {

    GamePanel gp;
    Graphics2D g2;

    Hud [] girl_health_mid;
    Hud girl_health_start;
    Hud girl_health_end[];

    Hud [] boy_health_mid;
    Hud boy_health_start;
    Hud boy_health_end[];

    int charIndex=0;

    String combined_text="";

    BufferedImage  game_over, restart, exit;



    public Font purisaB, arneson, arnesonBold;

    int current_slot=0;

    int press_delay=50;



    public HudManager(GamePanel gp)
    {
        this.gp=gp;

        girl_health_mid = new Hud[12];
        girl_health_end = new Hud[2];
        girl_health_start = new Hud();
        boy_health_mid = new Hud[12];
        boy_health_end = new Hud[2];
        boy_health_start = new Hud();

        load_hud_image();
        load_font();



    }

    public void load_font()
    {
        try{
            File is = new File("res/Font/Purisa Bold.ttf");
            purisaB= Font.createFont(Font.TRUETYPE_FONT, is);

            is = new File("res/Font/Arneson.ttf");
            arneson= Font.createFont(Font.TRUETYPE_FONT, is);

            is = new File("res/Font/Arneson Bold.ttf");
            arnesonBold= Font.createFont(Font.TRUETYPE_FONT, is);


        }
        catch (IOException e)
        {
            e.printStackTrace();
        } catch (FontFormatException e) {
            throw new RuntimeException(e);
        }
    }

    public void load_hud_image()
    {
        for(int i=0; i<12; i++)
            girl_health_mid[i]=new Hud();

        girl_health_end[0]=new Hud();
        girl_health_end[1]=new Hud();

        for(int i=0; i<12; i++)
            boy_health_mid[i]=new Hud();

        boy_health_end[0]=new Hud();
        boy_health_end[1]=new Hud();

        try{
            girl_health_mid[0].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid0.png"));
            girl_health_mid[1].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid1.png"));
            girl_health_mid[2].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid2.png"));
            girl_health_mid[3].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid3.png"));
            girl_health_mid[4].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid4.png"));
            girl_health_mid[5].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid5.png"));
            girl_health_mid[6].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid6.png"));
            girl_health_mid[7].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid7.png"));
            girl_health_mid[8].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid8.png"));
            girl_health_mid[9].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid9.png"));
            girl_health_mid[10].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid10.png"));
            girl_health_mid[11].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/mid11.png"));

            girl_health_end[0].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/end0.png"));
            girl_health_end[1].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/end1.png"));

            girl_health_start.image =   ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/start.png"));

            boy_health_mid[0].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid0.png"));
            boy_health_mid[1].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid1.png"));
            boy_health_mid[2].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid2.png"));
            boy_health_mid[3].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid3.png"));
            boy_health_mid[4].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid4.png"));
            boy_health_mid[5].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid5.png"));
            boy_health_mid[6].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid6.png"));
            boy_health_mid[7].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid7.png"));
            boy_health_mid[8].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid8.png"));
            boy_health_mid[9].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid9.png"));
            boy_health_mid[10].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid10.png"));
            boy_health_mid[11].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/mid11.png"));

            boy_health_end[0].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/end0.png"));
            boy_health_end[1].image= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/end1.png"));

            boy_health_start.image =   ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Blue/start.png"));



            game_over= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/Game Over.png"));
            restart= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/restart.png"));
            exit= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Hud/exit.png"));





        }
        catch (IOException e)
        {

        }

    }



    public void draw_hud(Graphics2D g2) {


        int x, y, mid, i;

        //Draw health hud
        x= 10;
        y=gp.tileSize;
        g2.drawImage(girl_health_start.image, x, y, gp.tileSize, gp.tileSize, null);

        i=1;



        while(true)
        {




            if(gp.player.girl_current_health <i*10 && gp.player.girl_current_health >=(i-1)*10)
            {
                mid=gp.player.girl_current_health %10;

                if(gp.player.girl_current_health <=0)
                    mid=11;
            }
            else if(gp.player.girl_current_health >=i*10)
                mid=10;
            else
                mid=11;







            g2.drawImage(girl_health_mid[mid].image, x+gp.tileSize*i, y, gp.tileSize, gp.tileSize, null);

            i++;

            if(i*10>gp.player.girl_max_health)
                break;
        }


        if(gp.player.girl_current_health ==gp.player.girl_max_health)
            g2.drawImage(girl_health_end[1].image, x+gp.tileSize*i, y, gp.tileSize, gp.tileSize, null);
        else
            g2.drawImage(girl_health_end[0].image, x+gp.tileSize*i, y, gp.tileSize, gp.tileSize, null);

        //Draw transformation hud


        x= 10;
        y=gp.tileSize*2+2;
        g2.drawImage(boy_health_start.image, x, y, gp.tileSize, gp.tileSize, null);

        i=1;



        while(true)
        {




            if(gp.player.current_health <i*10 && gp.player.current_health >=(i-1)*10)
            {
                mid=gp.player.current_health %10;

                if(gp.player.current_health <=0)
                    mid=11;
            }
            else if(gp.player.current_health >=i*10)
                mid=10;
            else
                mid=11;







            g2.drawImage(boy_health_mid[mid].image, x+gp.tileSize*i, y, gp.tileSize, gp.tileSize, null);

            i++;

            if(i*10>gp.player.max_health)
                break;
        }


        if(gp.player.current_health ==gp.player.max_health)
            g2.drawImage(boy_health_end[1].image, x+gp.tileSize*i, y, gp.tileSize, gp.tileSize, null);
        else
            g2.drawImage(boy_health_end[0].image, x+gp.tileSize*i, y, gp.tileSize, gp.tileSize, null);







    }
}

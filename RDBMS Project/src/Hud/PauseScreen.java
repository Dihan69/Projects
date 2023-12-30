package Hud;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.sql.SQLException;

public class PauseScreen {
    BufferedImage pause, continue_button, exit, idle, select, main_background, control, control_title, saving;

    int current_slot=0;

    int press_delay=50;

    int current_state=0;

    GamePanel gp;

    public PauseScreen(GamePanel gp)
    {
        this.gp=gp;

        load_image();
    }

    public void load_image()
    {
        try {
            main_background= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/pause_background.png"));

            exit=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/exit2.png"));
            continue_button=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/continue2.png"));
            pause=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Paused.png"));
            idle=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/button-idle2.png"));
            select=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/button-select2.png"));
            control = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/controls2.png"));
            saving=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/load2.png"));
            control_title = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Controls_title.png"));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void update()
    {
        if(gp.keyH.upPressed==true && press_delay==0)
        {
            if(current_slot==1)
                current_slot=0;
            else if(current_slot==2)
                current_slot=1;
            else if(current_slot==3)
                current_slot=2;
            else if(current_slot==0)
                current_slot=3;

            press_delay=10;
        }
        else if(gp.keyH.downPressed==true && press_delay==0)
        {
            if(current_slot==1)
                current_slot=2;
            else if(current_slot==2)
                current_slot=3;
            else if(current_slot==3)
                current_slot=0;
            else if(current_slot==0)
                current_slot=1;

            press_delay=10;
        }
        else if(gp.keyH.enterPressed==true && press_delay==0)
        {
            if(current_slot==0)
                gp.gameState=gp.playState;
            else if(current_slot==3)
            {
                gp.gameState=gp.titleState;


            }
            else if(current_slot==1)
            {

                    gp.gameState=gp.savingState;


            }
            else if(current_slot==2)
            {
                current_state=1;
            }

            press_delay=40;
        }
        else if(gp.keyH.escapePressed==true && press_delay==0)
        {
            current_state=0;
        }

        if(press_delay>0)
            press_delay--;
    }

    public void draw(Graphics2D g2) {


        g2.drawImage(main_background, 0, 0, gp.screenWidth, gp.screenHeight, null);

        int factor=70;

        if(current_state==0) {
            g2.drawImage(pause, 550+factor, 150, 444, 118, null);


            if (current_slot == 0)
                g2.drawImage(select, 570+factor, 370, 384, 97, null);
            else
                g2.drawImage(idle, 570+factor, 370, 384, 97, null);
            g2.drawImage(continue_button, 570+factor, 370, 384, 97, null);

            if (current_slot == 1)
                g2.drawImage(select, 570+factor, 520, 384, 97, null);
            else
                g2.drawImage(idle, 570+factor, 520, 384, 97, null);

            g2.drawImage(saving, 570+factor+15, 520+15, 350, 70, null);

            if (current_slot == 2)
                g2.drawImage(select, 570+factor, 670, 384, 97, null);
            else
                g2.drawImage(idle, 570+factor, 670, 384, 97, null);

            g2.drawImage(control, 570+factor, 670, 384, 97, null);

            if (current_slot == 3)
                g2.drawImage(select, 570+factor, 820, 384, 97, null);
            else
                g2.drawImage(idle, 570+factor, 820, 384, 97, null);

            g2.drawImage(exit, 570+factor, 820, 384, 97, null);
        }

        else
        {

            g2.drawImage(control_title, 560+factor, 100, 400, 100, null);

            g2.setColor(Color.white);
            g2.setFont(gp.hud.purisaB);
            g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
            g2.drawString("LEFT-ARROW: Girl Move left ", 550+factor, 250);
            g2.drawString("RIGHT-ARROW: Girl Move right", 550+factor, 300);
            g2.drawString("UP-ARROW: Girl Move up", 550+factor, 350);
            g2.drawString("DOWN-ARROW: Girl Move down", 550+factor, 400);
            g2.drawString("A BUTTON: Girl Move left", 550+factor, 450);
            g2.drawString("D BUTTON: Girl Move right", 550+factor, 500);
            g2.drawString("W BUTTON: Girl Move up", 550+factor, 550);
            g2.drawString("S BUTTON: Girl Move down", 550+factor, 600);
            g2.drawString("LEFT CTRL: Boy Attack", 550+factor, 650);
            g2.drawString("RIGHT CTRL: Girl Attack", 550+factor, 700);
            g2.drawString("ENTER BUTTON: Interact", 550+factor, 750);
            g2.drawString("ESCAPE BUTTON: Pause/resume game", 550+factor, 800);
        }
    }
}

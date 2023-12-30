package Hud;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class TitleScreen {

    public BufferedImage main_background, loading, loading_title;
    public BufferedImage castle_background, forest_background, winter_background, cave_background;
    public BufferedImage play, exit, continue_button, load, idle, select, title, control, control_title;

    public BufferedImage map[]= new BufferedImage[11];

    public int press_delay=50;

    String current_selected="play";

    boolean is_control_state=false;



    GamePanel gp;
    public TitleScreen(GamePanel gp)
    {
        this.gp=gp;
        load_image();

        if(gp.currentMap>0)
            current_selected="continue";


    }

    public void load_image(){
        try {
            loading_title= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/loading_title.png"));

            main_background= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/red_background.jpg"));


            play=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/play.png"));
            exit=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/exit.png"));
            continue_button=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/continue.png"));
            load=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/load.png"));
            idle=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/button-idle.png"));
            select=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/button-select.png"));
            title=  ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/title.png"));
            control = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/controls.png"));
            control_title = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Controls_title.png"));

            for(int i=0; i<=10; i++)
                map[i]= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/map ("+i+").png"));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void update()
    {
        if(gp.keyH.downPressed==true && press_delay==0)
        {
            press_delay=10;
            downlogic();
        }
        else if(gp.keyH.upPressed==true && press_delay==0)
        {
            press_delay=10;
            uplogic();
        }
        else if(gp.keyH.enterPressed==true && press_delay==0)
        {
            press_delay=10;
            enterlogic();
        }
        else if(gp.keyH.escapePressed==true && press_delay==0)
        {
            press_delay=10;

            is_control_state=false;

        }

        if(press_delay>0)
            press_delay--;


    }

    public void enterlogic()
    {
        if(current_selected=="continue")
        {
            gp.next_selected="continue";
            gp.gameState=gp.playState;

        }
        else if(current_selected=="play")
        {

            gp.next_selected="play";
            gp.gameState=gp.playState;



        }
        else if(current_selected=="exit")
        {
            System.exit(0);
        }
        else if(current_selected=="load")
        {
            gp.gameState=gp.saveLoadingState;
        }
        else if(current_selected=="controls")
        {
            is_control_state=true;
        }
    }

    public void uplogic()
    {
        if(current_selected=="play")
        {
            if(gp.currentMap>0)
                current_selected="continue";
            else
                current_selected="exit";
        }
        else if(current_selected=="load")
            current_selected="play";
        else if(current_selected=="exit")
            current_selected="controls";
        else if(current_selected=="continue")
            current_selected="exit";
        else if(current_selected=="controls")
            current_selected="load";

    }

    public void downlogic()
    {
        if(current_selected=="play")
            current_selected="load";

        else if(current_selected=="exit")
        {
            if(gp.currentMap>0)
                current_selected="continue";
            else
                current_selected="play";

        }
        else if(current_selected=="continue")
            current_selected="play";
        else if(current_selected=="load")
            current_selected="controls";
        else if(current_selected=="controls")
            current_selected="exit";


    }



    public void draw(Graphics2D g2) {


        g2.drawImage(main_background, 0, 0, gp.screenWidth, gp.screenHeight, null);


        if (is_control_state == false) {
            g2.drawImage(title, 400, 30, 800, 290, null);

            int factor = 0;

            if (gp.quest.current_active_quest_id > 0) {
                if (current_selected == "continue")
                    g2.drawImage(select, 640, 350, 288, 72, null);
                else
                    g2.drawImage(idle, 640, 350, 288, 72, null);
                g2.drawImage(continue_button, 640, 357, 288, 60, null);
            } else
                factor = 50;


            if (current_selected == "play")
                g2.drawImage(select, 640, 450 - factor, 288, 72, null);
            else
                g2.drawImage(idle, 640, 450 - factor, 288, 72, null);
            g2.drawImage(play, 640, 457 - factor, 288, 60, null);

            if (current_selected == "load")
                g2.drawImage(select, 640, 550 - factor, 288, 72, null);
            else
                g2.drawImage(idle, 640, 550 - factor, 288, 72, null);
            g2.drawImage(load, 640, 557 - factor, 288, 60, null);

            if (current_selected == "controls")
                g2.drawImage(select, 640, 650 - factor, 288, 72, null);
            else
                g2.drawImage(idle, 640, 650 - factor, 288, 72, null);
            g2.drawImage(control, 640, 657 - factor, 288, 60, null);

            if (current_selected == "exit")
                g2.drawImage(select, 640, 750 - factor, 288, 72, null);
            else
                g2.drawImage(idle, 640, 750 - factor, 288, 72, null);
            g2.drawImage(exit, 640, 757 - factor, 288, 60, null);
        }
        else
        {

            int factor=70;
            
            g2.drawImage(control_title, 560+factor, 100, 400, 100, null);

            g2.setColor(new Color(0,0,0, 150));
            g2.fillRect(540, 220, 800, 600);

            g2.setColor(Color.white);
            g2.setFont(gp.hud.purisaB);
            g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
            g2.drawString("ARROW Keys: Girl Moving all directions ", 550+factor, 250);
            g2.drawString("WASD: Boy moving all direction", 550+factor, 300);
            g2.drawString("LEFT CTRL: Boy Attack", 550+factor, 350);
            g2.drawString("RIGHT CTRL: Girl Attack", 550+factor, 400);
            g2.drawString("M BUTTON: Open or close Current Map", 550+factor, 450);
            g2.drawString("U BUTTON: Open Upgrade Screen", 550+factor, 500);
            g2.drawString("B BUTTON: Ride or get down from boat", 550+factor, 550);
            g2.drawString("SPACE: Switch current active player", 550+factor, 600);
            g2.drawString("I BUTTON: Open Inventory", 550+factor, 650);
            g2.drawString("Q BUTTON: Open Quest page", 550+factor, 700);
            g2.drawString("ENTER BUTTON: Interact", 550+factor, 750);
            g2.drawString("ESCAPE BUTTON: Pause/resume game", 550+factor, 800);
        }

    }




}

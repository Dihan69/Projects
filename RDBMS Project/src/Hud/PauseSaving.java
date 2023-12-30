package Hud;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.sql.SQLException;

public class PauseSaving {

    BufferedImage main_background, save_frame, save_frame_selected, save_text,  save_warning, new_save, new_save_selected, scroll_bar, scroll_thumb;

    int current_slot=0;

    int f_pressed_time=0, x_pressed_time=0;

    int press_delay=50;

    int start_slot=0;



    int current_state=0;

    public Save save[]= new Save[100];

    GamePanel gp;

    public PauseSaving(GamePanel gp)
    {
        this.gp=gp;

        for(int i=0; i<100; i++)
            save[i]=new Save();



        load_image();
    }

    public void load_image()
    {
        try {
            main_background= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/save_background.jpg"));
            save_frame=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/save_frame.png"));
            save_frame_selected=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/save_frame_selected.png"));
            save_text=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/save_game_text.png"));

            save_warning=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/save_load_warning.png"));
            new_save=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/new_save.png"));
            new_save_selected=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/new_save_selected.png"));

            scroll_bar=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/scroll_bar.png"));
            scroll_thumb=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/scroll_thumb.png"));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void update()
    {
        this.save=gp.saveLoading.save;

        System.out.println(start_slot+","+current_slot);

        if(gp.keyH.upPressed==true && press_delay==0)
        {
            if(current_slot>0)
            {

                current_slot--;

                if(start_slot>current_slot )
                    start_slot--;
            }
            else
            {
                start_slot=gp.total_save_game-3;
                current_slot=gp.total_save_game;
            }

            press_delay=10;
        }
        else if(gp.keyH.downPressed==true && press_delay==0)
        {
            if(current_slot<gp.total_save_game)
            {

                current_slot++;

                if(current_slot>3 && start_slot<gp.total_save_game-3)
                    start_slot++;
            }
            else
            {
                start_slot=0;
                current_slot=0;
            }



            press_delay=10;
        }
        else if(gp.keyH.enterPressed==true && press_delay==0)
        {

            press_delay=40;
        }
        else if(gp.keyH.escapePressed==true && press_delay==0)
        {
            gp.gameState=gp.pauseState;
        }
        else if(gp.keyH.f_pressed==true)
        {
            f_pressed_time++;

        }
        else if(gp.keyH.x_pressed==true)
        {
            x_pressed_time++;
        }
        else
        {
            x_pressed_time=0;
            f_pressed_time=0;

        }

        if(press_delay>0)
            press_delay--;


        if(f_pressed_time>200)
        {
            if(current_slot==gp.total_save_game)
            {
                 try
            {

                gp.save_game_id=gp.total_save_game;

                gp.db.createNewGames();
                gp.db.getSaveGames();



             gp.db.setDatabaseValues();





            }
            catch (SQLException e) {
                throw new RuntimeException(e);
            }
            }
            else if(current_slot!=0)
            {
                try
                {

                    gp.save_game_id=current_slot;



                    gp.db.overwriteSaveGames();

                 gp.db.setDatabaseValues();

                    gp.db.updateSaveGames();





                }
                catch (SQLException e) {
                    throw new RuntimeException(e);
                }
            }

            f_pressed_time=0;
        }
        else if(x_pressed_time>200)
        {
            x_pressed_time=0;

            if(current_slot!=0 && current_slot!=gp.total_save_game)
            {
                try
                {

                    gp.db.deleteGame(current_slot);
                    gp.db.updateSaveGames();

                    if(start_slot>0)
                        start_slot--;



                }
                catch (SQLException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }

    public void draw(Graphics2D g2) {


        g2.drawImage(main_background, 0, 0, gp.screenWidth, gp.screenHeight, null);

        int factor = 130;

        g2.drawImage(save_text, 160, 170, 719, 75, null);

        int num = 0;

        for (int i = start_slot; i < Math.min(start_slot + gp.total_save_game+1, start_slot + 4); i++) {

            if (i != gp.total_save_game) {
                if (current_slot == i) {
                    g2.drawImage(save_frame_selected, 160, 280 + factor * num, 716, 115, null);
                } else
                    g2.drawImage(save_frame, 160, 280 + factor * num, 716, 115, null);

                int left_x = 175;

                g2.setColor(Color.black);
                g2.setFont(gp.hud.arnesonBold);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 30F));
                g2.drawString(save[i].save_name, left_x, 310 + factor * num);
                g2.setFont(gp.hud.arneson);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
                g2.drawString(save[i].location, left_x, 355 + factor * num);
                g2.drawString(save[i].progress + " % complete", left_x, 380 + factor * num);

                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 25F));

                if (i == 0)
                    g2.drawString("Autosave", 700, 315 + factor * num);
                else
                    g2.drawString("Manual Save " + i, 650, 320 + factor * num);

                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));

                g2.drawString(save[i].last_saved, 580, 355 + factor * num);
                g2.drawString(convertSecondsToHMS(save[i].save_time), 650, 380 + factor * num);

                num++;
            } else {
                if (current_slot == i) {
                    g2.drawImage(new_save_selected, 160, 280 + factor * num, 716, 115, null);
                } else
                    g2.drawImage(new_save, 160, 280 + factor * num, 716, 115, null);

                g2.setColor(Color.black);
                g2.setFont(gp.hud.arneson);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 35F));
                g2.drawString("CREATE A NEW SAVE GAME", 300, 315 + factor * num);


            }
        }


        int y=240+factor*(current_slot-start_slot);

        g2.drawImage(save_warning, 940, y-10, 350, 170, null);
        g2.setColor(Color.black);
        g2.setFont(gp.hud.arnesonBold);
        g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 20F));

        if (current_slot == gp.total_save_game)
            g2.drawString("Do you want to create a new slot?", 958, y + 20);
        else if (current_slot == 0)
            g2.drawString("You cannot save in this slot!!!", 958, y + 20);
        else
        g2.drawString("Do you want to overwrite this slot?", 958, y + 20);

        g2.setFont(gp.hud.arneson);
        g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));

        if (current_slot == gp.total_save_game) {
            g2.drawString("This will create a new slot and save ", 958, y + 48);
            g2.drawString("your current progress in that slot. If ", 958, y + 68);
            g2.drawString("don't want to do this, you can overwrite", 958, y + 88);
            g2.drawString("a slot or rely on autosave.", 958, y + 108);
        } else if (current_slot == 0) {
            g2.drawString("This save game was automatically saved ", 958, y + 48);
            g2.drawString("when you completed any action in your ", 958, y + 68);
            g2.drawString("last playthrough. You can not overwrite", 958, y + 88);
            g2.drawString("or delete the game in this slot. Please", 958, y + 108);
            g2.drawString("choose a valid slot", 958, y + 128);
        } else {
            g2.drawString("This action will overwrite current game ", 958, y + 48);
            g2.drawString("saved in autosave. If you have want to ", 958, y + 68);
            g2.drawString("save progress of autosave and haven't", 958, y + 88);
            g2.drawString("already, please save it in a separate slot", 958, y + 108);
        }


        g2.setFont(gp.hud.arnesonBold);
        g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 20F));

        if (current_slot == gp.total_save_game) {

            g2.drawString("F   Create new Save game", 980, y + 139);

            g2.setColor(Color.white);
            g2.setStroke(new BasicStroke(3));
            g2.drawArc(971, y + 117, 28, 28, 0, 360);



            g2.setColor(Color.red);
            g2.setStroke(new BasicStroke(3));
            g2.drawArc(971, y + 117, 28, 28, 90, -(Math.min((int) (((float) f_pressed_time / 200) * 360.0), 360)));


        } else if(current_slot!=0) {
            g2.drawString("F   Overwrite    X   Delete", 980, y + 139);

            g2.setColor(Color.black);
            g2.setStroke(new BasicStroke(3));
            g2.drawArc(971, y + 117, 28, 28, 0, 360);
            g2.drawArc(1130, y + 117, 28, 28, 0, 360);


            g2.setColor(Color.red);
            g2.setStroke(new BasicStroke(3));
            g2.drawArc(971, y + 117, 28, 28, 90, -(Math.min((int) (((float) f_pressed_time / 200) * 360.0), 360)));
            g2.drawArc(1130, y + 117, 28, 28, 90, -(Math.min((int) (((float) x_pressed_time / 200) * 360.0), 360)));
        }

        draw_scroll_thumb(g2);
    }

    public void draw_scroll_thumb(Graphics2D g2)
    {
        int max_height= 505;
        int max_width=14;
        int x=900,y=280;

        g2.drawImage(scroll_bar, x, y, max_width, max_height, null);

        int thumb_height;

        if(gp.total_save_game>4)
            thumb_height=(int)(((float)Math.max(4,gp.total_save_game+1-4)/(float)(gp.total_save_game+1))*(float)max_height);
        else
            thumb_height=max_height;

        int start_y;

        if(gp.total_save_game<=4)
            start_y=y;
        else
            start_y= y+ start_slot*(int)((float)max_height/(gp.total_save_game+1)-1);

        g2.drawImage(scroll_thumb, x, start_y, max_width, thumb_height, null);
    }



    public String convertSecondsToHMS(int seconds) {
        if (seconds < 0) {
            throw new IllegalArgumentException("Input must be a non-negative integer");
        }

        int hours = seconds / 3600;
        int minutes = (seconds % 3600) / 60;
        int remainingSeconds = seconds % 60;

        return String.format("%d H %d M %d S", hours, minutes, remainingSeconds);
    }
}

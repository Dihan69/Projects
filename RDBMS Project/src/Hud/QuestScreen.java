package Hud;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class QuestScreen {

    BufferedImage background, body, body_selected, completed, active, description;

    boolean is_quest_body=true;

    int available_quest=0;

    int current_slot=0;

    int press_delay=0;


    int current_type=0;

    int start_slot=0;

    int max_board_per_screen=7;


    GamePanel gp;

    public QuestScreen(GamePanel gp)
    {
        this.gp=gp;

        load_image();
    }

    public void load_image()
    {
        try {
            background= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/quest_background.jpg"));
            body=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Quest_body.png"));
            body_selected=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Quest_body_selected.png"));
            description=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Quest_description.png"));
            completed=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Quest_body_completed.png"));
            active=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Quest_body_general.png"));


        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void update()
    {


        available_quest=0;

        if(current_type==0)
        for(int i=0; i<gp.quest.max_quest; i++)
        {
            if(gp.quest.quest[i]!=null && !(gp.quest.quest[i].status.equals("not offered")))
                available_quest++;
        }

        if(current_type==1)
            for(int i=0; i<gp.quest.total_main_quest; i++)
            {
                if(gp.quest.quest[i]!=null && !(gp.quest.quest[i].status.equals("not offered")))
                    available_quest++;
            }

        if(current_type==2)
            for(int i=gp.quest.total_main_quest; i<gp.quest.total_main_quest+gp.quest.total_side_quest; i++)
            {
                if(gp.quest.quest[i]!=null && !(gp.quest.quest[i].status.equals("not offered")))
                    available_quest++;
            }



        if(gp.keyH.upPressed==true && press_delay==0)
        {
            if(current_slot>0)
            {

                current_slot--;

                if(start_slot>current_slot)
                    start_slot--;
            }
            else
            {
                start_slot=available_quest-max_board_per_screen;
                current_slot=available_quest-1;
            }

            press_delay=10;
        }
        else if(gp.keyH.downPressed==true && press_delay==0)
        {
            if(current_slot<available_quest-1)
            {

                current_slot++;

                if(current_slot>3 && start_slot<available_quest-4)
                    start_slot++;
            }
            else
            {
                start_slot=0;
                current_slot=0;
            }



            press_delay=10;
        }


        if(press_delay>0)
            press_delay--;
    }

    public void draw(Graphics2D g2)
    {

        g2.drawImage(background, 0, 0, gp.screenWidth, gp.screenHeight, null);


            drawAllQuests(g2);

    }

    public void drawAllQuests(Graphics2D g2)
    {
        int factor=95;

        int num=0;


        g2.setColor(Color.black);


        int i=0, count=0;

        boolean available_done=false;


        while(count<available_quest)
        {
            if(available_done==false && gp.quest.quest[i]!=null && gp.quest.quest[i].status.equals("available"))
            {
                if(count>=start_slot && count<=Math.min(start_slot+available_quest, start_slot+max_board_per_screen))
                {
                    if(current_slot==num)
                        g2.drawImage(body_selected, 180, 195+factor*num, 587, 80, null);

                    if(gp.quest.current_active_quest_id==num)
                        g2.drawImage(active, 245, 200+factor*num, 515, 75, null);

                    else
                        g2.drawImage(body, 245, 200+factor*num, 515, 75, null);

                    g2.setFont(gp.hud.arnesonBold);
                    g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 28F));
                    g2.drawString(gp.quest.quest[i].name, 252, 225 + factor *num);


                    g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 22F));

                    String type;
                    if(i<=16)
                         type="Main Quest";
                    else
                        type="Side Quest";

                    g2.drawString(type, 252, 245 + factor *num);

                    num++;


                }

                count++;
            }
            else if(available_done==true && gp.quest.quest[i]!=null && gp.quest.quest[i].status.equals("completed"))
            {
                if(count>=start_slot && count<=Math.min(start_slot+available_quest, start_slot+max_board_per_screen))
                {
                    if(current_slot==num)
                        g2.drawImage(body_selected, 180, 195+factor*num, 587, 80, null);


                        g2.drawImage(completed, 245, 200+factor*num, 515, 75, null);


                    g2.setFont(gp.hud.arnesonBold);
                    g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 28F));
                    g2.drawString(gp.quest.quest[i].name, 252, 225 + factor *num);

                    g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 22F));

                    String type;

                    if(i<=16)
                        type="Main Quest";
                    else
                        type="Side Quest";

                    g2.drawString(type, 252, 245 + factor *num);

                    num++;


                }

                count++;
            }



            i++;

            if(i==gp.quest.max_quest)
            {
                i=0;
                available_done=true;

            }
        }



    }


}

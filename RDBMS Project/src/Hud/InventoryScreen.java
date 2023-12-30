package Hud;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.sql.SQLException;

public class InventoryScreen {

    BufferedImage main_background, slot, slot_selected, description;

    int current_slot_x=0;
    int current_slot_y=0;



    int press_delay=50;





    int current_state=0;

    public int inventory[]=new int[50];

    GamePanel gp;

    public InventoryScreen(GamePanel gp)
    {
        this.gp=gp;



        load_image();
    }

    public void load_image()
    {
        try {
            main_background= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/black_background.jpg"));
            slot=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/inventory_slot_selected.png"));
            slot_selected=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/inventory_slot.png"));
            description=ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/inventory_description.png"));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void update()
    {

        this.inventory=gp.player.inventory;


        if(gp.keyH.upPressed==true && press_delay==0)
        {

            if(current_slot_x>=5 && current_slot_x<9)
            {
                current_slot_y=(--current_slot_y)%3;

                if(current_slot_y<0)
                    current_slot_y=3;

            }
            else
            {
                current_slot_y=(--current_slot_y)%6;

                if(current_slot_y<0)
                    current_slot_y=5;
            }



            press_delay=10;
        }
        else if(gp.keyH.downPressed==true && press_delay==0)
        {

        if(current_slot_x>=5 && current_slot_x<9)
        current_slot_y=(++current_slot_y)%3;
        else
            current_slot_y=(++current_slot_y)%6;


            press_delay=10;
        }
        else if(gp.keyH.rightPressed==true && press_delay==0)
        {

            if(current_slot_y>=3 && current_slot_x==4)
                current_slot_x=9;
            else
            current_slot_x=(++current_slot_x)%13;



            press_delay=10;
        }
        else if(gp.keyH.leftPressed==true && press_delay==0)
        {

            if(current_slot_y>=3 && current_slot_x==9)
                current_slot_x=4;
            else
            current_slot_x=(--current_slot_x)%13;

            if(current_slot_x<0)
                current_slot_x=12;



            press_delay=10;
        }
        else if(gp.keyH.enterPressed==true && press_delay==0)
        {

            press_delay=40;
        }




        if(press_delay>0)
            press_delay--;




    }

    public void draw(Graphics2D g2) {


        g2.drawImage(main_background, 0, 0, gp.screenWidth, gp.screenHeight, null);

        int this_slot_x=0;

        g2.setColor(Color.white);
        g2.setFont(gp.hud.arnesonBold);
        g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 30F));
        g2.drawString("Valuable Resources", 173, 240);
        g2.drawString("Enhancements", 173+580, 240);
        g2.drawString("Quest Items", 173+580+500, 240);

        g2.fillRect(171, 260, 4*100+80, 3);
        g2.fillRect(171+580, 260, 3*100+80, 3);
        g2.fillRect(171+1080, 260, 3*100+80, 3);

        for(int i=0; i< 5; i++)
            for(int j=0; j<6; j++)
            {
                this_slot_x=i;

                if(current_slot_x==this_slot_x && j==current_slot_y)
                    g2.drawImage(slot_selected, 170+i*100, 285+j*100, 80, 80, null);
                else

                g2.drawImage(slot, 170+i*100, 285+j*100, 80, 80, null);
            }

        for(int i=0; i< 4; i++)
            for(int j=0; j<3; j++)
            {
                this_slot_x=5+i;

                if(current_slot_x==this_slot_x && j==current_slot_y)
                    g2.drawImage(slot_selected, 170+580+i*100, 285+j*100, 80, 80, null);

                else
                    g2.drawImage(slot, 170+580+i*100, 285+j*100, 80, 80, null);
            }

        g2.drawImage(description, 170+580, 285+320, 380, 270, null);


        for(int i=0; i< 4; i++)
            for(int j=0; j<6; j++)
            {
                this_slot_x=9+i;

                if(current_slot_x==this_slot_x && j==current_slot_y)
                    g2.drawImage(slot_selected, 170+580+500+i*100, 285+j*100, 80, 80, null);
            else
                    g2.drawImage(slot, 170+580+500+i*100, 285+j*100, 80, 80, null);
            }

        g2.setColor(Color.black);
        g2.setFont(gp.hud.arneson);
        g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));

        int field_y=0, field_x=0;

        for(int i=0; i<gp.objM.object_varity_count; i++)
        {

            if(inventory[i]!=0 && gp.objM.solo_obj[i].type=="resource")
            {
                g2.drawImage(gp.objM.solo_obj[i].image[0], 170+field_x*100, 285+field_y*100, 70, 70, null);
                g2.drawString("x"+inventory[i],170+50+field_x*100, 285+70+field_y*100 );


                if(field_x<4)
                    field_x++;
                else
                {
                    field_x=0;
                    field_y++;
                }
            }

        }


         field_y=0;
         field_x=0;

        for(int i=0; i<gp.objM.object_varity_count; i++)
        {

            if(inventory[i]!=0 && gp.objM.solo_obj[i].type=="consumable")
            {
                g2.drawImage(gp.objM.solo_obj[i].image[0], 170+580+field_x*100, 285+field_y*100, 70, 70, null);
                g2.drawString("x"+inventory[i],170+580+50+field_x*100, 285+70+field_y*100 );


                if(field_x<3)
                    field_x++;
                else
                {
                    field_x=0;
                    field_y++;
                }
            }

        }

        field_y=0;
        field_x=0;

        for(int i=0; i<gp.objM.object_varity_count; i++)
        {

            if(inventory[i]!=0 && gp.objM.solo_obj[i].type=="quest")
            {
                g2.drawImage(gp.objM.solo_obj[i].image[0], 170+580+500+field_x*100, 285+field_y*100, 70, 70, null);
                g2.drawString("x"+inventory[i],170+580+500+50+field_x*100, 285+70+field_y*100 );


                if(field_x<3)
                    field_x++;
                else
                {
                    field_x=0;
                    field_y++;
                }
            }

        }


    }


}

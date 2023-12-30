package Hud;

import MainPackage.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class ShopScreen {

    BufferedImage main_background, slot, slot_selected, description;

    int current_slot_x = 0;
    int current_slot_y = 0;


    int press_delay = 50;


    int current_state = 0;

    public int inventory[] = new int[50];

    GamePanel gp;

    public ShopScreen(GamePanel gp) {
        this.gp = gp;


        load_image();
    }

    public void load_image() {
        try {
            main_background = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/shop1.png"));
            slot = ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/shop2.png"));


        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void update() {

        this.inventory = gp.player.inventory;


        if (gp.keyH.upPressed == true && press_delay == 0) {

            current_slot_y = (++current_slot_y) % 2;


            press_delay = 10;
        } else if (gp.keyH.downPressed == true && press_delay == 0) {

            current_slot_y = (++current_slot_y) % 2;


            press_delay = 10;
        }


        if (press_delay > 0)
            press_delay--;


    }

    public void draw(Graphics2D g2) {


        if (current_slot_y == 0)
            g2.drawImage(main_background, 0, 0, gp.screenWidth, gp.screenHeight, null);
        else
            g2.drawImage(slot, 0, 0, gp.screenWidth, gp.screenHeight, null);

    }

}

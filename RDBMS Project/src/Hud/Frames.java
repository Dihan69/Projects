package Hud;

import MainPackage.GamePanel;

import java.awt.*;

public class Frames {

    public static String speaker="";
    public static void frame1(Graphics2D g2, int x, int y, int height, int width)
    {
        Color c= new Color(255, 255, 255, 150);
        g2.setColor(c);
        g2.fillRect(x,y, width, height);



        /*int border_width=2;
        c= new Color (255, 255, 255);
        g2.setColor(c);
        g2.setStroke(new BasicStroke(border_width));
        g2.drawRoundRect(x+border_width, y+border_width, width-border_width*2, height-border_width*2, 25, 25);*/
    }

    public static void dialogueframe(Graphics2D g2, GamePanel gp)
    {
        Color c1= new Color(0, 0, 0, 150);
        Color c2= new Color(255, 255, 255);






        int x=gp.tileSize*6-5;
        int y=gp.tileSize*4;
        int width= gp.screenWidth-(gp.tileSize*12)+16;
        int height= gp.tileSize*4;



        frame2(g2, x,y, width, height, c1, c2, 5);
    }

    public static void frame3(Graphics2D g2, int x, int y, int width, int height, Color c1, Color c2, int border)
    {
        g2.setColor(new Color(204, 204, 204, 150));

        g2.fillRect(x, y, width, height);

        // Set border color and width
        int border_width = border;

        g2.setColor( new Color(96, 26, 62));
        g2.setStroke(new BasicStroke(border_width));
        g2.drawRect(x + border_width, y + border_width, width - border_width * 2, height - border_width * 2);


    }


    public  static void frame2(Graphics2D g2, int x, int y, int width, int height, Color c1, Color c2, int border)
    {
        GradientPaint gradient = new GradientPaint(x, y, new Color(96, 26, 62,   150), x + width, y + height, new Color(44, 4, 29, 150));
        g2.setPaint(gradient);
        g2.fillRect(x, y, width, height);

        // Set border color and width
        int border_width = border;
        g2.setColor(new Color(204, 204, 204));
        g2.setStroke(new BasicStroke(border_width));
        g2.drawRect(x + border_width, y + border_width, width - border_width * 2, height - border_width * 2);


    }
}

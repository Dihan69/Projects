package entity;

import MainPackage.GamePanel;

import java.awt.*;
import java.awt.image.BufferedImage;

public  class Entity {

    public GamePanel gp;
    public Entity(GamePanel gp)
    {
        this.gp=gp;
    }
    public int speed;

    public int current_health=10, max_health=10, last_hit_time=0;
    public boolean got_hit=false;

    public boolean visibility=false;

    public int hit_damage=0;

    public int screenX, screenY;

    public boolean is_locked=false;

    public boolean is_destroyable=true;
    public int lock_high_x, lock_low_x, lock_high_y, lock_low_y;

    public int height, width;

    public int map;

    public int worldY, worldX;

    public String current_state="not quest";


    public String action ="walk";

    public String direction ="left";

    public BufferedImage up[]= new BufferedImage[4];
    public BufferedImage right[]= new BufferedImage[4];
    public BufferedImage left[]= new BufferedImage[4];
    public BufferedImage down[]= new BufferedImage[4];

    public boolean collisonOn = false;

    public  void update()
    {

    }
    public  void draw(Graphics2D g2)
    {

    }

    public int spriteNum=0, spriteCounter=0;




    public Rectangle solidArea, damageSolidArea;

    public String move_direction;
    public boolean can_shoot, destroyable;

    public int power, shoot_delay, lifetime;




}

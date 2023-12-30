package Quest;

import MainPackage.GamePanel;

import java.awt.*;

public class Quest {

    public String name;
    public int id;
    public int max_phase;

    public int current_phase =0;

    public String current_dialogue="";

    public int dialogue_index=0;

    public int remaining_time=0, quest_max_finish_time=0;
    long start_time=0, current_time=0;

    public String []phase_command;

    public String [] description=new String[3];

    public String type;

    public String status="not offered";

    public boolean is_printed;

    GamePanel gp;

    public Quest(GamePanel gp)
    {
        this.gp=gp;
    }

    public void draw(Graphics2D g2)
    {

    }

    public void update()
    {

    }


}

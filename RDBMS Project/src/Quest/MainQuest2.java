package Quest;

import Hud.Frames;
import MainPackage.GamePanel;

import java.awt.*;

public class MainQuest2 extends  Quest{

    boolean mayor_close=false;

    String dialogues1[]=new String[20];
    String dialogues2[]= new String[20];

    int press_delay=0;

    int dialogue1_phase=0, dialogue2_phase=11;
    int beetles_killed =0;

    int charIndex=0;
    String combinedString="";
    public MainQuest2(GamePanel gp) {
        super(gp);

        name="The Beetles";

        max_phase=13;
        phase_command=new String[max_phase];

        set_phase_command();


        current_phase=dialogue2_phase;

        setDialogue();



    }

    public void setDialogue()
    {
        dialogues1[0]="Glad you came back so fast.";
        dialogues1[1]="There is a problem in the south side forest of the village";
        dialogues1[2]="A number of beetles are residing there. They can invade the \nvillage anytime. Children cannot play by the side of village.";
        dialogues1[3]="I need you to kill of them";
        dialogues1[4]="Ok, Chief. It won't be a problem. I will be right back.";

        dialogues2[0]="Hope you were not hurt. Here is your reward.";
    }

    public void set_phase_command()
    {
        phase_command[0]="Meet the Village Chief";
        phase_command[1]="Kill the Beetles [0/10]";
        phase_command[2]="Kill the Beetles [1/10]";
        phase_command[3]="Kill the Beetles [2/10]";
        phase_command[4]="Kill the Beetles [3/10]";
        phase_command[5]="Kill the Beetles [4/10]";
        phase_command[6]="Kill the Beetles [5/10]";
        phase_command[7]="Kill the Beetles [6/10]";
        phase_command[8]="Kill the Beetles [7/10]";
        phase_command[9]="Kill the Beetles [8/10]";
        phase_command[10]="Kill the Beetles [9/10]";
        phase_command[11]="Talk to the Village Chief";
        phase_command[12]="[[COMPLETED]]";
    }

    public void update()
    {
        status="completed";
        if(gp.gameState==gp.playState) {
            beetles_killed = 0;

            if (current_phase == 1) {
                for (int i = 80; i < 90; i++)
                    if (gp.enemy[0][i] == null)
                        beetles_killed++;

                if (beetles_killed == 10)
                    current_phase = dialogue2_phase;
            }

            if (current_phase == dialogue1_phase || current_phase == dialogue2_phase)
            {
                if ((Math.abs(gp.player.BoyWorldX - gp.npc[0].worldX) <= 50 && Math.abs(gp.player.BoyWorldY - gp.npc[0].worldY) <= 50) )
                {
                    mayor_close=true;
                    gp.player.currentDialogue="boy";
                }
                else if(Math.abs(gp.player.GirlWorldX - gp.npc[0].worldX) <= 50 && Math.abs(gp.player.GirlWOrldY - gp.npc[0].worldY) <= 50) {

                    mayor_close = true;
                    gp.player.currentDialogue="girl";
                }
                else
                    mayor_close=false;
            }
            else
                mayor_close = false;

            if (mayor_close == true && gp.keyH.f_pressed == true && (current_phase==0 || current_phase==11)) {
                gp.gameState = gp.dialogueState;
                gp.npc[0].current_state = "dialogue start";
            }
        }
        else if(gp.gameState==gp.dialogueState)
        {
            speak();
        }

        if(current_phase==max_phase-1 && status!="complete")
        {
            gp.quest.next_main_quest=3;
            gp.quest.current_main_quest++;

            gp.quest.quest_complete_phase=true;
            gp.quest.quest_complete_display_time=100;




            status="completed";
        }

    }

    public void speak()
    {
        if(current_phase==dialogue1_phase && dialogues1[dialogue_index]!=null)
            current_dialogue=dialogues1[dialogue_index];
        else if(current_phase==dialogue2_phase && dialogues2[dialogue_index]!=null)
            current_dialogue=dialogues2[dialogue_index];
        else
        {
            gp.gameState=gp.playState;
            gp.npc[0].current_state="dialogue end";
            current_phase++;
            dialogue_index=0;
            combinedString="";
            charIndex=0;
        }

        if(gp.keyH.enterPressed==true && press_delay==0)
        {
            press_delay=10;
            dialogue_index++;
            charIndex=0;
            combinedString="";
        }

        if(press_delay>0)
            press_delay--;
    }

    public void draw_dialogue_text(Graphics2D g2)
    {
        int x=gp.tileSize*6-5;
        int y=gp.tileSize*4;


        x+= gp.tileSize-19;
        y+= gp.tileSize;
        g2.setFont(gp.hud.arneson);
        g2.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
        g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 40F));
        g2.setColor(Color.white);

        char characters[]=new char[150];

        if(current_phase==dialogue1_phase && dialogues1[dialogue_index]!=null)
            characters= dialogues1[dialogue_index].toCharArray();
        else if(current_phase==dialogue2_phase && dialogues2[dialogue_index]!=null)
            characters=dialogues2[dialogue_index].toCharArray();

        if(charIndex<characters.length)
        {
            String s=String.valueOf(characters[charIndex]);
            combinedString=combinedString+s;
            current_dialogue=combinedString;
            charIndex++;
        }

        for(String line: current_dialogue.split("\n"))
        {
            g2.drawString(line, x, y);
            y+=40;
        }
    }


    public void draw(Graphics2D g2) {
        if (gp.gameState == gp.playState) {
            g2.setColor(Color.white);
            g2.setFont(gp.hud.arnesonBold);
            g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 30F));
            g2.drawString(name, 1370, 120);

            g2.fillRect(1370, 127, 250, 3);

            g2.setFont(gp.hud.arneson);
            g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 20F));

            if (current_phase == dialogue1_phase || current_phase >= dialogue2_phase)
                g2.drawString(phase_command[current_phase], 1370, 150);
            else
                g2.drawString(phase_command[current_phase + beetles_killed], 1370, 150);

            if (mayor_close == true) {
                Frames.frame1(g2, gp.npc[0].screenX - 10, gp.npc[0].screenY - 35, 30, 80);
                g2.setColor(Color.BLACK);
                g2.setFont(gp.hud.arneson);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
                g2.drawString("F Interact", gp.npc[0].screenX - 8, gp.npc[0].screenY - 20);
            }
        }
        else if(gp.gameState==gp.dialogueState)
        {
            Frames.dialogueframe(g2, gp);
            draw_dialogue_text(g2);
        }
    }
}

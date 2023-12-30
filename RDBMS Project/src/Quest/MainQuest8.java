package Quest;

import Hud.Frames;
import MainPackage.GamePanel;
import entity.Wizard;

import java.awt.*;

public class MainQuest8 extends Quest{
    boolean santa_close =false;

    String dialogues1[]=new String[20];
    String dialogues2[]= new String[20];

    int press_delay=0;

    int plant_killed =0;

    int charIndex=0;

    public boolean house_close=false, house_knocked=false;
    int dialogue1_phase=0, dialogue2_phase=16;

    int speaker1[]=new int [20];
    int speaker2[]= new int [20];
    String combinedString="";
    public MainQuest8(GamePanel gp) {
        super(gp);

        name="Plants & Zombies";

        max_phase=18;
        phase_command=new String[max_phase];

        set_phase_command();





        setDialogue();



    }

    public void setDialogue()
    {
        dialogues1[0]="How do you dare to come to my house?";
        dialogues1[1]="The mayor of the village send me to you.";
        dialogues1[2]="Huh! To get the key? You need to defeat me to get it.";
        dialogues1[3]="First, prove me you are worth wasting my time on.";
        dialogues1[4]="Over-confidence is never good. You need to prove your worth \nto me";
        dialogues1[5]="We are ready to face any challenge.";
        dialogues1[6]="I have hidden some rare gems accross the forest in this side of \nthe river. Find me all of those.";
        dialogues1[7]="We will be right back , sir once we are done.";

        dialogues2[0]="Hmmm, good job. Even though it took a while more than I \nexpected.";
        dialogues2[1]="Here is your reward. You can keep the gems to sell." ;
        dialogues2[2]="Come back later when you are ready for next challenge.";
    }

    public void set_phase_command()
    {
        phase_command[0]="Find the Wizard in swamp";
        phase_command[1]="Kill the Man-eater plants [0/15]";
        phase_command[2]="Kill the Man-eater plants [1/15]";
        phase_command[3]="Kill the Man-eater plants [2/15]";
        phase_command[4]="Kill the Man-eater plants [3/15]";
        phase_command[5]="Kill the Man-eater plants [4/15]";
        phase_command[6]="Kill the Man-eater plants [5/15]";
        phase_command[7]="Kill the Man-eater plants [6/15]";
        phase_command[8]="Kill the Man-eater plants [7/15]";
        phase_command[9]="Kill the Man-eater plants [8/15]";
        phase_command[10]="Kill the Man-eater plants [9/15]";
        phase_command[11]="Kill the Man-eater plants [10/15]";
        phase_command[12]="Kill the Man-eater plants [11/15]";
        phase_command[13]="Kill the Man-eater plants [12/15]";
        phase_command[14]="Kill the Man-eater plants [13/15]";
        phase_command[15]="Kill the Man-eater plants [14/15]";
        phase_command[16]="Talk to Wizard in his house";
        phase_command[17]="[[COMPLETED]]";
    }

    public void update()
    {


        status="completed";

        if(gp.gameState==gp.playState) {

            if(current_phase>=1 && gp.npc[3]==null)
                gp.npc[3]=new Wizard(gp);


            if (current_phase == 1) {
                for (int i = 105; i < 120; i++)
                    if (gp.enemy[0][i] == null)
                        plant_killed++;

                if (plant_killed == 15)
                    current_phase = dialogue2_phase;
            }





            if(current_phase==dialogue1_phase )
            {
                if(gp.player.BoyWorldX>=7680 && gp.player.BoyWorldX<=7880 && gp.player.BoyWorldY>=1100 && gp.player.BoyWorldY<=1200)
                    house_close=true;
                else  if(gp.player.GirlWorldX>=7680 && gp.player.GirlWorldX<=7880 && gp.player.GirlWOrldY>=1100 && gp.player.GirlWOrldY<=1200)
                    house_close=true;
                else
                    house_close=false;
            }
            else
                house_close=false;

            if(house_close==true && gp.keyH.f_pressed==true)
            {
                gp.gameState= gp.transitionState;
                gp.quest.wizard_house_knocked=true;


            }

            if (current_phase == dialogue2_phase)
            {
                if ((Math.abs(gp.player.BoyWorldX - gp.npc[3].worldX) <= 50 && Math.abs(gp.player.BoyWorldY - gp.npc[3].worldY) <= 50) )
                {
                    santa_close =true;
                    gp.player.currentDialogue="boy";
                }
                else if(Math.abs(gp.player.GirlWorldX - gp.npc[3].worldX) <= 50 && Math.abs(gp.player.GirlWOrldY - gp.npc[3].worldY) <= 50) {

                    santa_close = true;
                    gp.player.currentDialogue="girl";
                }
                else
                    santa_close =false;
            }
            else
                santa_close = false;

            if (santa_close == true && gp.keyH.f_pressed == true &&  current_phase==dialogue2_phase) {
                gp.gameState = gp.dialogueState;
                gp.npc[3].current_state = "dialogue start";
            }

        }
        else if(gp.gameState==gp.dialogueState)
        {
            speak();
        }



        if(current_phase==max_phase-1)
        {

            gp.quest.next_main_quest=5;
            gp.quest.current_main_quest++;

            gp.quest.quest_complete_display_time=100;

            gp.quest.quest_complete_phase=true;
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
            gp.npc[3].current_state="dialogue end";
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
                g2.drawString(phase_command[current_phase + plant_killed], 1370, 150);

            if (santa_close == true) {
                Frames.frame1(g2, gp.npc[0].screenX - 10, gp.npc[0].screenY - 35, 30, 80);
                g2.setColor(Color.BLACK);
                g2.setFont(gp.hud.arneson);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
                g2.drawString("F Interact", gp.npc[0].screenX - 8, gp.npc[0].screenY - 20);
            }

            if(house_close==true)
            {


                int screenX= gp.decM.dec[gp.currentMap][423].worldX-gp.player.worldX+gp.player.screenX+125;
                int screenY= gp.decM.dec[gp.currentMap][423].worldY-gp.player.worldY+gp.player.screenY+200;

                Frames.frame1(g2, screenX, screenY, 30, 80);
                g2.setColor(Color.BLACK);
                g2.setFont(gp.hud.arneson);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
                g2.drawString("F Interact", screenX+2, screenY+15);
            }

            if (santa_close == true) {
                Frames.frame1(g2, gp.npc[3].screenX - 10, gp.npc[3].screenY - 35, 30, 80);
                g2.setColor(Color.BLACK);
                g2.setFont(gp.hud.arneson);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
                g2.drawString("F Interact", gp.npc[3].screenX - 8, gp.npc[3].screenY - 20);
            }
        }
        else if(gp.gameState==gp.dialogueState)
        {
            Frames.dialogueframe(g2, gp);
            draw_dialogue_text(g2);
        }
    }
}

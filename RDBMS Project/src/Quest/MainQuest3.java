package Quest;

import Enemy.ChombBomb;
import Enemy.RhinoBettle;
import Hud.Frames;
import MainPackage.GamePanel;
import NPC.DeputyMayor;
import NPC.Mayor;

import java.awt.*;
import java.util.Random;

public class MainQuest3 extends Quest{
    boolean mayor_close=false;

    String dialogues1[]=new String[20];
    String dialogues2[]= new String[20];

    int press_delay=0;

    int chombBomb_killed =0;

    int charIndex=0;

    boolean start_time_taken=false;

    int dialogue1_phase=0, dialogue2_phase=16;

    int speaker1[]=new int [20];
    int speaker2[]= new int [20];
    String combinedString="";

    public int chombBomb_start=90;

    public boolean house_knocked=false;

    boolean chombBomb_created=false;

    public boolean house_close=false;
    public MainQuest3(GamePanel gp) {
        super(gp);

        name="Unwanted Guests";

        max_phase=18;
        phase_command=new String[max_phase];

        quest_max_finish_time=300;
        remaining_time=300;



        set_phase_command();



        setDialogue();



    }

    public void setDialogue()
    {
        dialogues1[0]="Chief!!! Chief!! We are in trouble.";
        dialogues1[1]="What happened???";
        dialogues1[2]="These bomb monsters are invading our village. They have \ncrossed the barrier already.";
        dialogues1[3]="How did this happen? The barrier was working fine last time I\nchecked.";
        dialogues1[4]="There are more than 10 of them. I am too old to beat them in \ntime before they destroy everything in the village.";
        dialogues1[5]="Don't worry, chief. We can fight them. It is time to put those\n hard years of training into work.";
        dialogues1[6]="But these are not those simple beetles. These are much swift\nmonsters. You only have 5 minutes to do this.";
        dialogues1[7]="Trust on us for this time, Chief. We know we can.";
        dialogues1[8]="Okay, my kid. I am sorry I have to put you through this.";
        dialogues1[9]="You will attract their attention once you get close. Try to \nkill one at a time and stay away from its explosion.";
        dialogues1[10]="Ok, chief. You and deputy stay in home.";

        dialogues2[0]="Wow! I cannot believe you guys managed to save our village \n in time. It is such a big achievement for someone who just \n finished his training.";
        dialogues2[1]="It was a hard job but we managed to do this.";
        dialogues2[2]="I am giving you the permission to find your way to defeat \nthe demon king.";
        dialogues2[3]="Really? It would be such a honor to fight to save our village,\n even if it cost my life";
        dialogues2[4]="It won't, you are the first one in years I believe will make it\n out alive.";
        dialogues2[5]="Listen to me, carefully. At first, 3 of the people who lives \noutside the village. They are the only one who knows how \n to inflirate the base of demon king.";
        dialogues2[6]="You will find them in the forest, swamp and desert. Remember \n that they will test your worth first before giving you the\n information.";
        dialogues2[7]="We will pass the test and return to the village as hero.";
        dialogues2[8]="Good luck, my kids. May you succeed in your path.";
    }

    public void set_phase_command()
    {
        phase_command[0]="Hear from Deputy Chief";
        phase_command[1]="Kill the ChombBombs in time [0/15]";
        phase_command[2]="Kill the ChombBombs in time [1/15]";
        phase_command[3]="Kill the ChombBombs in time [2/15]";
        phase_command[4]="Kill the ChombBombs in time [3/15]";
        phase_command[5]="Kill the ChombBombs in time [4/15]";
        phase_command[6]="Kill the ChombBombs in time [5/15]";
        phase_command[7]="Kill the ChombBombs in time [6/15]";
        phase_command[8]="Kill the ChombBombs in time [7/15]";
        phase_command[9]="Kill the ChombBombs in time [8/15]";
        phase_command[10]="Kill the ChombBombs in time [9/15]";
        phase_command[11]="Kill the ChombBombs in time [10/15]";
        phase_command[12]="Kill the ChombBombs in time [11/15]";
        phase_command[13]="Kill the ChombBombs in time [12/15]";
        phase_command[14]="Kill the ChombBombs in time [13/15]";
        phase_command[15]="Kill the ChombBombs in time [14/15]";
        phase_command[16]="Find the village Chief in his house.";
        phase_command[17]="[[COMPLETED]]";
    }



    public void update()
    {
        status="completed";

        if(gp.gameState==gp.playState) {


            if(start_time_taken==false && current_phase==1)
            {
                start_time_taken=true;
                start_time=  System.currentTimeMillis();
            }

            for(int i=90; i<=104; i++)
                if(gp.destroyed_enemy[i]==1)
                    gp.enemy[0][i]=null;



            if (current_phase == 1 && gp.quest.chombCreated==true) {

                chombBomb_killed=0;

                for (int i = chombBomb_start; i <chombBomb_start+15; i++)
                    if (gp.enemy[0][i] == null)
                        chombBomb_killed++;


                if (chombBomb_killed == 15)
                    current_phase = dialogue2_phase;
            }

            if (current_phase == dialogue1_phase || current_phase == dialogue2_phase)
            {
                if(gp.npc[0]!=null)
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

            if (mayor_close == true && gp.keyH.f_pressed == true && (current_phase==dialogue1_phase || current_phase==dialogue2_phase)) {
                gp.gameState = gp.dialogueState;
                gp.npc[0].current_state = "dialogue start";
            }

            current_time= System.currentTimeMillis();
            int elapsed_time=   (int)((current_time - start_time) / 1000);

            if(elapsed_time==1)
            {
                remaining_time--;
                start_time=System.currentTimeMillis();
            }
            else if(elapsed_time>1)
            {
                start_time=System.currentTimeMillis();
            }


            if(current_phase==dialogue2_phase )
            {
                if(gp.player.BoyWorldX>=2164 && gp.player.BoyWorldX<=2252 && gp.player.BoyWorldY>=1020 && gp.player.BoyWorldY<=1064)
                    house_close=true;
                else  if(gp.player.GirlWorldX>=2164 && gp.player.GirlWorldX<=2252 && gp.player.GirlWOrldY>=1020 && gp.player.GirlWOrldY<=1064)
                    house_close=true;
                else
                    house_close=false;
            }
           else
               house_close=false;

            if(house_close==true && gp.keyH.f_pressed==true)
            {
                gp.gameState= gp.transitionState;
                house_knocked=true;


            }


        }
        else if(gp.gameState==gp.dialogueState)
        {
            speak();
        }



        if(current_phase==max_phase-1)
        {
            gp.quest.next_main_quest=4;
            gp.quest.current_main_quest++;

            gp.gameState=gp.transitionState;

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
            gp.npc[0].current_state="dialogue end";


            if(current_phase==0 && chombBomb_created==false)
            {
                chombBomb_created=true;
                gp.gameState=gp.transitionState;
            }

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
                g2.drawString(phase_command[current_phase + chombBomb_killed], 1370, 150);

            if(current_phase==1)
            g2.drawString(formatRemainingTime(remaining_time), 1370, 170);

            if (mayor_close == true) {
                Frames.frame1(g2, gp.npc[0].screenX - 10, gp.npc[0].screenY - 35, 30, 80);
                g2.setColor(Color.BLACK);
                g2.setFont(gp.hud.arneson);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
                g2.drawString("F Interact", gp.npc[0].screenX - 8, gp.npc[0].screenY - 20);
            }

            if(house_close==true)
            {


                int screenX= gp.decM.dec[gp.currentMap][0].worldX-gp.player.worldX+gp.player.screenX+325;
                int screenY= gp.decM.dec[gp.currentMap][0].worldY-gp.player.worldY+gp.player.screenY+200;

                Frames.frame1(g2, screenX, screenY, 30, 80);
                g2.setColor(Color.BLACK);
                g2.setFont(gp.hud.arneson);
                g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 18F));
                g2.drawString("F Interact", screenX+2, screenY+15);
            }
        }
        else if(gp.gameState==gp.dialogueState)
        {
            Frames.dialogueframe(g2, gp);
            draw_dialogue_text(g2);
        }
    }


    public  String formatRemainingTime(int remainingTime) {

        int minutes = (remainingTime % 3600) / 60;
        int seconds = remainingTime % 60;

        // Format the time in "hh:mm:ss" format
        String formattedTime = String.format("%02d:%02d",  minutes, seconds);

        return formattedTime;
    }

}

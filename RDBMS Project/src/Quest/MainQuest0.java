package Quest;

import Hud.Frames;
import MainPackage.GamePanel;

import java.awt.*;

public class MainQuest0 extends Quest{

    String dialogues[]=new String[20];


    int press_delay=0;

    String combinedString="";

    int charIndex=0;

    public MainQuest0(GamePanel gp) {
        super(gp);

        name="Introduction";

        max_phase=2;

        setDialogue();

    }

    public void setDialogue()
    {
        dialogues[0]="The village of Thaelon was once a prosperous village on the \noutskirt of the capital city. ";
        dialogues[1]="But it was not for long as soon the demon king decided to take \nshelter in the island just outside the city";
        dialogues[2]="He isolated the area from outside by creating a barrier so that \nno one can attack him in his base.";
        dialogues[3]="The village also found itself inside the barrier and so no one \nfrom the village can go outside.";
        dialogues[4]="The only hope for the village people is to someone from them \ndefeat the demon king. ";
        dialogues[5]="But countless warrior from the village has failed to defeat the\ndemon king and the villagers have almost lost hope.";
        dialogues[6]="The final hope of the village is two siblings who have showed \nimmense potential in training.";
        dialogues[7]="The story unfolds the journey of these two siblings as they \nfight their way to reach the demon king.";



    }

    public void update()
    {
    if(gp.gameState!=gp.dialogueState)
    {
        press_delay=30;
        gp.gameState=gp.dialogueState;
    }

        if(gp.gameState==gp.dialogueState)
        {
            speak();
        }

        if(current_phase==max_phase-1)
        {

            gp.quest.next_main_quest=1;
            gp.quest.current_main_quest++;

            gp.quest.quest_complete_display_time=0;

            gp.quest.quest_complete_phase=true;
            status="completed";

            gp.gameState=gp.transitionState;
            gp.transitionScreen.counter=100;


        }
    }

    public void speak()
    {
        if(dialogues[dialogue_index]!=null)
            current_dialogue=dialogues[dialogue_index];

        else
        {
            gp.gameState=gp.playState;
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
        int y=gp.tileSize*6;


        x+= gp.tileSize-19;
        y+= gp.tileSize;
        g2.setFont(gp.hud.arneson);
        g2.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
        g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 40F));
        g2.setColor(Color.white);

        char characters[]=new char[150];


            characters= dialogues[dialogue_index].toCharArray();


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


        g2.setColor(Color.black);

        g2.fillRect(0, 0, gp.screenWidth, gp.screenHeight);


            draw_dialogue_text(g2);

    }
}

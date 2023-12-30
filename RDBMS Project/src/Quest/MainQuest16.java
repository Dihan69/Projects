package Quest;

import MainPackage.GamePanel;

import java.awt.*;

public class MainQuest16 extends Quest{
    String dialogues[]=new String[20];

    String dialogues2[]=new String[20];


    int press_delay=0;

    String combinedString="";

    int charIndex=0;

    public MainQuest16(GamePanel gp) {
        super(gp);

        name="Introduction";

        max_phase=3;

        setDialogue();

    }

    public void setDialogue()
    {
        dialogues[0]="Finally, the fierce battle with demon king ends. The siblings has\n" +
                     "succeeded to free their village from the grasp of the demon king.\n"+
                     "This is not the end of the story of siblings, it is just the start\n"+
                     "as they have earned their freedom to extend their adventure to the \n" +
                     "the outside filled with more monstors and evil people.";

        dialogues2[0]="                    A RDBMS PROJECT                    \n"+
                      "                     For CSE 4508                      \n"+
                      " \n"+
                      " \n"+
                      " \n"+
                      "                   A special Thanks\n"+
                      "            to our honorable Course Teachers\n"+
                      " \n"+
                      "                   Md. Shihab Shahriar    \n"+
                      "                    Lecturer, IUT CSE    \n"+
                      " \n"+
                      "                     MD Atiqur Rahman   \n"+
                      "                    Lecturer, IUT CSE    \n"+
                      " \n"+
                      " \n"+
                      "                 Code, Story & Design By\n"+
                      "\n"+
                "                Mubtasim Kamal Dihan    \n"+
                "                    ID-200041138    \n"+
                "                    CSE 20, IUT    \n"+
                "\n"+
                "                      Abdullah    \n"+
                "                    ID-200041126    \n"+
                "                    CSE 20, IUT    \n"+
                "\n"+
                "                        Amina    \n"+
                "                    ID-200041155    \n"+
                "                    CSE 20, IUT    \n"+
                " \n"+
                " \n"+
                "             Arts, Images & Sprite Credit\n"+
                "\n"+
                "                       Abdullah    \n"+
                "                    Craftpix website    \n"+
                "                     itch.io website    \n"
        ;



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


        if(current_phase==0)
        draw_dialogue_text(g2);
        else if(current_phase==1)
            draw_credit_text(g2);

    }

    public int scrollup=0;
    public void draw_credit_text(Graphics2D g2)
    {
        int x=gp.tileSize*6-5;
        int y=400-scrollup;

        g2.drawImage(gp.titleScreen.title, 400, 30-scrollup, 800, 290, null);


        x+= gp.tileSize-19;
        y+= gp.tileSize;
        g2.setFont(gp.hud.arneson);
        g2.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
        g2.setFont(g2.getFont().deriveFont(Font.PLAIN, 40F));
        g2.setColor(Color.white);

        current_dialogue=dialogues2[0];

        for(String line: current_dialogue.split("\n"))
        {
            g2.drawString(line, x, y);
            y+=40;
        }

        scrollup++;
    }
}

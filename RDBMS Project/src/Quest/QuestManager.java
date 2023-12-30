package Quest;

import Enemy.ChombBomb;
import Hud.QuestScreen;
import MainPackage.GamePanel;
import NPC.DeputyMayor;
import NPC.Mayor;
import NPC.OlderMan;
import NPC.SantaOldMan;
import entity.Wizard;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.sql.SQLException;
import java.util.Random;

public class QuestManager {

    public int total_main_quest=17;
    public int total_side_quest=1;

    public int current_side_quest=1;

    public int current_main_quest=2;

    public int next_main_quest=1;
    public int next_side_quest=-1;

    public int current_active_quest_id=16;

    public boolean santa_house_knocked=false;

    public boolean wizard_house_knocked=false;

    boolean chombCreated=false;

    public int quest_complete_display_time=0;

    public boolean quest_complete_phase=false;

    public int max_quest=total_main_quest+total_side_quest;

    public Quest [] quest=new Quest[max_quest];

    public BufferedImage quest_complete;


    GamePanel gp;
    public QuestManager(GamePanel gp)
    {
        this.gp=gp;

        quest[0]=new MainQuest0(gp);
        quest[1]=new MainQuest1(gp);
        quest[2]=new MainQuest2(gp);
        quest[3]=new MainQuest3(gp);
        quest[4]=new MainQuest4(gp);
        quest[5]=new MainQuest5(gp);
        quest[6]=new MainQuest6(gp);
        quest[7]=new MainQuest7(gp);
        quest[8]=new MainQuest8(gp);
        quest[9]=new MainQuest9(gp);
        quest[10]=new MainQuest10(gp);
        quest[11]=new MainQuest11(gp);
        quest[12]=new MainQuest12(gp);
        quest[13]=new MainQuest13(gp);
        quest[14]=new MainQuest14(gp);
        quest[15]=new MainQuest15(gp);
        quest[16]=new MainQuest16(gp);
        quest[17]=new SideQuest0_17(gp);







        try {
            quest_complete= ImageIO.read(getClass().getClassLoader().getResourceAsStream("Title/Quest Complete.png"));

        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    int auto_save_delay=1000;

    public void update()
    {
        for(int i=0; i<12; i++)
            quest[i].status="completed";

        quest[13].status="available";

        if(auto_save_delay>0)
            auto_save_delay--;
        else
        {
            auto_save_delay=1000;

            try
            {

                gp.save_game_id=0;



                gp.db.overwriteSaveGames();

                gp.db.setDatabaseValues();

                gp.db.updateSaveGames();





            }
            catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }


        if((gp.quest.quest[4].status.equals("completed") || gp.quest.current_active_quest_id>4) && gp.npc[2]==null)
            gp.npc[2]=new SantaOldMan(gp);

        if((gp.quest.quest[8].status.equals("completed") || gp.quest.current_active_quest_id>8) && gp.npc[3]==null)
            gp.npc[3]=new Wizard(gp);

            if (current_active_quest_id >= 0 && quest_complete_phase == false)
                quest[current_active_quest_id].update();

            if (quest_complete_phase == true) {
                if (quest_complete_display_time <= 0)
                    quest_complete_logic();
            }


            if (quest_complete_display_time > 0)
                quest_complete_display_time--;


        quest_start_logic();


    }

    public void quest_complete_logic()
    {
        if(current_active_quest_id==0)
        {
            current_active_quest_id=1;
            quest[1].status="available";
        }
        else if(current_active_quest_id==1)
        {
            current_active_quest_id=2;
            quest[2].status="available";
        }
        else if(current_active_quest_id==2)
        {
            current_active_quest_id=3;
            gp.gameState=gp.transitionState;
            quest[3].status="available";
        }
        else if(current_active_quest_id==3)
        {
            current_active_quest_id=4;
            gp.aSetter.setNPC();
            quest[4].status="available";
            quest[8].status="available";

        }
        else if(current_active_quest_id==4)
        {
            current_active_quest_id=5;
            quest[5].status="available";

        }

        else if(current_active_quest_id==5)
        {
            current_active_quest_id=6;
            quest[6].status="available";

        }
        else if(current_active_quest_id==6)
        {
            current_active_quest_id=7;
            quest[7].status="available";

        }
        else if(current_active_quest_id==7)
        {
            for(int i=8; i<15; i++)
                if(quest[i].status!="complete")
                {
                    current_active_quest_id=i;
                    break;
                }
        }

        quest_complete_phase=false;
    }

    public void quest_start_logic()
    {
        if(gp.gameState==gp.playState && current_active_quest_id==3 && quest[3].current_phase==0)
            gp.gameState= gp.dialogueState;






        if(gp.gameState==gp.playState && current_active_quest_id==3 && quest[3].current_phase==16 && gp.npc[0]!=null)
            gp.gameState=gp.dialogueState;

        if(gp.gameState==gp.playState && current_active_quest_id==4 && quest[4].current_phase==0 && gp.npc[2]!=null)
            gp.gameState=gp.dialogueState;

        if(gp.gameState==gp.playState && current_active_quest_id==8 && quest[8].current_phase==0 && gp.npc[3]!=null)
            gp.gameState=gp.dialogueState;

        if(gp.gameState==gp.playState && current_active_quest_id==12 && quest[12].current_phase==0 && santa_house_knocked)
            gp.gameState=gp.dialogueState;



        if(gp.npc[1]!=null)
        {
            if(gp.gameState==gp.transitionState  && current_active_quest_id==3 && gp.npc[1].current_state=="not quest" && quest[current_active_quest_id].current_phase==0 && gp.transitionScreen.counter==gp.transitionScreen.max_counter-5 &&gp.transitionScreen.state=="increasing")
            {


                gp.npc[1].worldX=1592;
                gp.npc[1].worldY=1720;
                gp.npc[1].current_state="quest 3 start";
                gp.npc[1].direction="up";
                gp.npc[1].speed=3;
                gp.npc[0].current_state="dialogue start";

                gp.player.direction="left";
                gp.player.girlDirection="left";
            }
        }



        if(gp.gameState==gp.transitionState  && current_active_quest_id==3 && quest[current_active_quest_id].current_phase==1 && gp.transitionScreen.counter==gp.transitionScreen.max_counter-5 && gp.transitionScreen.state=="increasing")
        {
            create_chombBomb();

            for(int i=0; i<gp.npc_count; i++)
                gp.npc[i]=null;

            chombCreated=true;

        }

        if(gp.gameState==gp.playState && current_active_quest_id==3 && quest[current_active_quest_id].current_phase==1 && chombCreated==false)
        {
            create_chombBomb();

            for(int i=90; i<105; i++)
                if(gp.destroyed_enemy[i]==1)
                    gp.enemy[i]=null;
            for(int i=0; i<gp.npc_count; i++)
                gp.npc[i]=null;

            chombCreated=true;
        }

        if(gp.gameState==gp.transitionState  && current_active_quest_id==3 && quest[current_active_quest_id].current_phase==16 && gp.transitionScreen.counter==gp.transitionScreen.max_counter-5 && gp.transitionScreen.state=="increasing")
        {

            gp.npc[0]=new Mayor(gp);
            gp.npc[1]=new DeputyMayor(gp);
            gp.npc[0].current_state="dialogue going";
            gp.npc[1].current_state="dialogue going";
            gp.npc[0].direction="left";
            gp.npc[1].direction="left";
            gp.npc[0].worldX=2220;
            gp.npc[0].worldY=1028;
            gp.npc[1].worldX=2220;
            gp.npc[1].worldY=1090;
            gp.player.BoyWorldX=2150;
            gp.player.BoyWorldY=1028;
            gp.player.GirlWorldX=2150;
            gp.player.GirlWOrldY=1090;
            gp.player.direction="right";
            gp.player.girlDirection="right";



        }

        if(gp.gameState==gp.transitionState  && current_active_quest_id==8 && wizard_house_knocked==true && quest[current_active_quest_id].current_phase==0 && gp.transitionScreen.counter==gp.transitionScreen.max_counter-5 && gp.transitionScreen.state=="increasing")
        {

            gp.npc[3]=new Wizard(gp);
            gp.npc[3].current_state="dialogue going";
            gp.npc[3].direction="left";
            gp.npc[3].worldX=7800;
            gp.npc[3].worldY=1150;
            gp.player.BoyWorldX=7720;
            gp.player.BoyWorldY=1140;
            gp.player.GirlWorldX=7720;
            gp.player.GirlWOrldY=1200;
            gp.player.direction="right";
            gp.player.girlDirection="right";



        }

        if(gp.gameState==gp.transitionState  && current_active_quest_id==4 && santa_house_knocked==true && quest[current_active_quest_id].current_phase==0 && gp.transitionScreen.counter==gp.transitionScreen.max_counter-5 && gp.transitionScreen.state=="increasing")
        {

            gp.npc[2]=new SantaOldMan(gp);
            gp.npc[2].current_state="dialogue going";
            gp.npc[2].direction="left";
            gp.npc[2].worldX=5490;
            gp.npc[2].worldY=5730;
            gp.player.BoyWorldX=5410;
            gp.player.BoyWorldY=5720;
            gp.player.GirlWorldX=5410;
            gp.player.GirlWOrldY=5760;
            gp.player.direction="right";
            gp.player.girlDirection="right";



        }


        if(gp.gameState==gp.transitionState  && current_active_quest_id==12 && santa_house_knocked==true && quest[current_active_quest_id].current_phase==0 && gp.transitionScreen.counter==gp.transitionScreen.max_counter-5 && gp.transitionScreen.state=="increasing")
        {

            gp.npc[2]=new OlderMan(gp);
            gp.npc[2].current_state="dialogue going";
            gp.npc[2].direction="left";
            gp.npc[2].worldX=12050;
            gp.npc[2].worldY=960;
            gp.player.BoyWorldX=12000;
            gp.player.BoyWorldY=960;

            gp.player.direction="right";
            gp.player.girlDirection="right";



        }
    }

    public void draw(Graphics2D g2)
    {
        if(current_active_quest_id>=0 && quest_complete_display_time<=0)
            quest[current_active_quest_id].draw(g2);

        if(quest_complete_phase==true)
            g2.drawImage(quest_complete, 500, 300, 800, 90, null);

        if(gp.gameState==gp.playState && current_active_quest_id==3 && quest[current_active_quest_id].current_phase==1 && chombCreated==false)
            gp.tileM.draw_loading_screen(g2);
    }


    public void create_chombBomb()
    {
        gp.enemy[0][90]=new ChombBomb(gp);
        gp.enemy[0][90].worldX=1956;
        gp.enemy[0][90].worldY=728;

        gp.enemy[0][91]=new ChombBomb(gp);
        gp.enemy[0][91].worldX=1536;
        gp.enemy[0][91].worldY=808;


        gp.enemy[0][92]=new ChombBomb(gp);
        gp.enemy[0][92].worldX=2508;
        gp.enemy[0][92].worldY=880;


        gp.enemy[0][93]=new ChombBomb(gp);
        gp.enemy[0][93].worldX=3084;
        gp.enemy[0][93].worldY=1052;

        gp.enemy[0][94]=new ChombBomb(gp);
        gp.enemy[0][94].worldX=2704;
        gp.enemy[0][94].worldY=1492;

        gp.enemy[0][95]=new ChombBomb(gp);
        gp.enemy[0][95].worldX=1632;
        gp.enemy[0][95].worldY=1380;

        gp.enemy[0][96]=new ChombBomb(gp);
        gp.enemy[0][96].worldX=1096;
        gp.enemy[0][96].worldY=1808;


        gp.enemy[0][97]=new ChombBomb(gp);
        gp.enemy[0][97].worldX=1224;
        gp.enemy[0][97].worldY=2216;


        gp.enemy[0][98]=new ChombBomb(gp);
        gp.enemy[0][98].worldX=1436;
        gp.enemy[0][98].worldY=2548;


        gp.enemy[0][99]=new ChombBomb(gp);
        gp.enemy[0][99].worldX=1804;
        gp.enemy[0][99].worldY=2184;

        gp.enemy[0][100]=new ChombBomb(gp);
        gp.enemy[0][100].worldX=2348;
        gp.enemy[0][100].worldY=2028;

        gp.enemy[0][101]=new ChombBomb(gp);
        gp.enemy[0][101].worldX=3052;
        gp.enemy[0][101].worldY=2204;

        gp.enemy[0][102]=new ChombBomb(gp);
        gp.enemy[0][102].worldX=2864;
        gp.enemy[0][102].worldY=2548;

        gp.enemy[0][103]=new ChombBomb(gp);
        gp.enemy[0][103].worldX=2188;
        gp.enemy[0][103].worldY=2704;

        gp.enemy[0][104]=new ChombBomb(gp);
        gp.enemy[0][104].worldX=1940;
        gp.enemy[0][104].worldY=2344;


        for(int i=90; i<105; i++)
            gp.enemy[0][i].map=0;
    }
}

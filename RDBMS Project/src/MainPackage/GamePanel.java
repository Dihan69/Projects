package MainPackage;

import Hud.*;
import Quest.QuestManager;
import Tile.DecorationManager;
import Tile.ObjectManager;
import Tile.TileManager;
import entity.Boat;
import entity.Entity;
import entity.Player;
import Tile.Map;

import javax.swing.*;
import java.awt.*;
import java.sql.SQLException;

public class GamePanel extends JPanel implements  Runnable{
    //

    final int originalTileSize=16; //individual block..may hold a whole player
    final int scale=3; //16 is too small..so we need to scale it

    public final int tileSize = originalTileSize * scale; //original tile that would be displayed
    public final int MaxScreenCol= 36; //no of tiles in a column
    public final int MaxScreenRow= 20;// no of tiles in row

    public final int maxMap=4;
    public int currentMap=3;
    public final int screenWidth= tileSize * MaxScreenCol; //sets total screen column
    public final int screenHeight= tileSize * MaxScreenRow; //sets total screen row

    //World Settings
    public final int [] maxWorldCol= {279, 96, 70, 73};
    public final int [] maxWorldRow= {223, 70, 41, 41};
    public int shopState=14;

    public ShopScreen shopScreen= new ShopScreen(this);
    //public final int worldWidth=tileSize*maxWorldCol;
    //public final int worldHeight= tileSize* maxWorldRow;


    Thread gameThread;
    int FPS=60;

    public KeyHandler keyH= new KeyHandler(this);
    public Player player = new Player(this, keyH);
    public TileManager tileM= new TileManager(this);
    public ObjectManager objM= new ObjectManager(this);

    public AssetSetter aSetter = new AssetSetter(this);
    public TitleScreen titleScreen= new TitleScreen(this);

    public int save_game_id=0;

    int enemy_count=120;
    public Entity enemy[][]=new Entity[maxMap][enemy_count];


    public int destroyed_enemy[]=new int[enemy_count];

    public int npc_count=10;

    public Entity npc[]=new Entity[npc_count];

    public Boat boat=new Boat(this);

    Map map= new Map(this);

    public boolean start_time_taken=false;
    public long start_time, current_time;

    public int passed_time=0;



    public DecorationManager decM= new DecorationManager(this);

    public CollisionChecker cChecker= new CollisionChecker(this);

    public HudManager hud=new HudManager(this);

    public QuestManager quest= new QuestManager(this);
    public PauseScreen pauseScreen= new PauseScreen(this);
    public SaveLoading saveLoading= new SaveLoading(this);

    public PauseSaving pauseSaving=new PauseSaving(this);

    public InventoryScreen inventoryScreen = new InventoryScreen(this);

    public QuestScreen questScreen= new QuestScreen(this);

    public TransitionScreen transitionScreen=new TransitionScreen(this);


    public Database db=new Database(this);
    public boolean playerGameCollisonOn =true;

    public String next_selected= "";

    public int gameState;
    public final int playState=0;
    public final int mapState=1;

    public final int gameLoadingState=2;

    public final int pauseState=3;
    public final int savingState=4;

    public final int saveLoadingState=5;

    public final int titleState=6;

    public final int inventoryState=7;

    public final int questState=8;

    public final int dialogueState=9;

    public final int transitionState=10;

    public final int boatState=11;

    public int total_save_game=0;





    public GamePanel()
    {
        this.setPreferredSize(new Dimension(screenWidth, screenHeight));
        this.setBackground(Color.black);
        this.setDoubleBuffered(true);
        this.addKeyListener(keyH);
        this.setFocusable(true);

        this.gameState=gameLoadingState;

       // ]setupGame();
    }

    public void resetGame()
    {
        aSetter.setEnemy();
        aSetter.setNPC();

        objM= new ObjectManager(this);
        quest= new QuestManager(this);
    }


    public void setupGame()
    {
        aSetter.setEnemy();
        aSetter.setNPC();
        this.gameState=titleState;

        try
        {

            db.getSaveGames();

            db.getPlayer();
            db.getObject();



        }
        catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }


    public void startGameThread()
    {
        gameThread= new Thread(this);
        gameThread.start(); //automatically calls run method
    }


    @Override
    public void run() {

        double drawInterval = 1000000000/ (double) FPS;
        double nextDrawTime= System.nanoTime() + drawInterval;
        //our gameloop

        while(gameThread != null) {


            update();

            repaint(); //we are calling paintComponent option

            try
            {
                double remainingTime = nextDrawTime - System.nanoTime();

                remainingTime= remainingTime/1000000; //the sleep function only takes mili, so we convert to it

                if(remainingTime<0)
                    remainingTime=0;

                Thread.sleep((long) remainingTime);

                nextDrawTime+= drawInterval; //set next interval
            }
            catch(InterruptedException e)
            {
                //convention
            }
        }

    }

    public void update()
    {


        if(gameState==playState || gameState==dialogueState || gameState==boatState) {


            if(start_time_taken==false )
            {
                start_time_taken=true;
                start_time=  System.currentTimeMillis();
            }

            if(gameState!=dialogueState)
            {


                    player.update();
                if(gameState==boatState)
                boat.update();
            }

            if(currentMap==0) {
                decM.updateAnimation();
                objM.update();
            }

            for(int i=0; i<enemy[currentMap].length; i++)
            {

                if(enemy[currentMap][i]!=null)
                {
                    enemy[currentMap][i].update();

                    if(enemy[currentMap][i].current_health<=0)
                    {
                        if(currentMap==0)
                        if(enemy[0][i].is_destroyable==true)
                            destroyed_enemy[i]=1;

                        enemy[currentMap][i]=null;
                    }
                }

            }

            if(currentMap==0)
            for(int i=0; i<npc.length; i++)
            {
                if(npc[i]!=null)
                {
                    npc[i].update();
                }
            }

            quest.update();


            current_time= System.currentTimeMillis();
            int elapsed_time=   (int)((current_time - start_time) / 1000);

            if(elapsed_time==1)
            {
                passed_time++;
                start_time=System.currentTimeMillis();
            }
            else if(elapsed_time>1)
            {

                start_time=System.currentTimeMillis();
            }


        }
        else if(gameState==pauseState)
            pauseScreen.update();
        else if(gameState==titleState)
            titleScreen.update();
        else if (gameState==saveLoadingState)
            saveLoading.update();
        else if(gameState==savingState)
            pauseSaving.update();
        else if(gameState==inventoryState)
            inventoryScreen.update();
        else if(gameState==questState)
            questScreen.update();
        else if(gameState==transitionState)
        {
            quest.update();
            transitionScreen.update();
        }
        else if(gameState==shopState)
            shopScreen.update();
    }



    public void paintComponent(Graphics g) {
        super.paintComponent(g);



        Graphics2D g2 = (Graphics2D) g;

        if(gameState==gameLoadingState )
            tileM.draw_loading_screen(g2);
        else if (gameState == playState || gameState==dialogueState || gameState==transitionState || gameState==boatState) {
            tileM.draw(g2);

            if(currentMap==0)
            decM.draw_water(g2);

            if(gameState==boatState)
                boat.draw(g2);
            else
            player.draw(g2);

            for(int i=0; i<enemy[currentMap].length; i++)
                if(enemy[currentMap][i]!=null)
                    enemy[currentMap][i].draw(g2);

            if(currentMap==0)
            for(int i=0; i<npc.length; i++)
                if(npc[i]!=null)
                    npc[i].draw(g2);

            if(currentMap==0) {
                objM.draw_later(g2);
                decM.draw(g2);
                objM.draw(g2);
            }
            if(gameState==playState || gameState==boatState)
            hud.draw_hud(g2);

            if(gameState!=transitionState)
            quest.draw(g2);

            if(gameState==transitionState)
                transitionScreen.draw(g2);


        }
        else if(gameState== mapState)
            map.drawFullMapScreen(g2);
        else if(gameState==pauseState)
            pauseScreen.draw(g2);
        else if(gameState==savingState)
            pauseSaving.draw(g2);
        else if(gameState==titleState)
            titleScreen.draw(g2);
        else if(gameState==saveLoadingState)
            saveLoading.draw(g2);
        else if(gameState==inventoryState)
            inventoryScreen.draw(g2);
        else if(gameState==questState)
            questScreen.draw(g2);
        else if(gameState==shopState)
            shopScreen.draw(g2);

    }

}

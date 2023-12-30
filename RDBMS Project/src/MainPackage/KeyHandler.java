package MainPackage;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyHandler implements KeyListener {

    public boolean w_pressed,a_pressed,s_pressed,d_pressed, b_pressed;
    public boolean upPressed, downPressed, leftPressed, rightPressed;

    public boolean LctrlPressed, RctrlPressed, enterPressed, escapePressed;

    public boolean one_pressed,two_pressed,three_pressed;
    public boolean f_pressed, x_pressed;
    public boolean spacePressed;

    GamePanel gp;

    public KeyHandler(GamePanel gp)
    {
        this.gp=gp;
    }
    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

        int code= e.getKeyCode();

        if(code==KeyEvent.VK_W)
            w_pressed=true;
        if(code==KeyEvent.VK_S)
            s_pressed=true;
        if(code==KeyEvent.VK_A)
            a_pressed=true;
        if(code==KeyEvent.VK_D)
            d_pressed=true;
        if (code == KeyEvent.VK_UP)
            upPressed = true;
        if (code == KeyEvent.VK_DOWN)
            downPressed = true;
        if (code == KeyEvent.VK_LEFT)
            leftPressed = true;
        if (code == KeyEvent.VK_RIGHT)
            rightPressed = true;
        if (code == KeyEvent.VK_SPACE)
            spacePressed = true;
        if (code == KeyEvent.VK_X)
            x_pressed = true;
        if (code == KeyEvent.VK_F)
            f_pressed = true;
        if(code==KeyEvent.VK_1)
            one_pressed=true;
        if(code==KeyEvent.VK_2)
            two_pressed=true;
        if(code==KeyEvent.VK_3)
            three_pressed=true;
        if(code==KeyEvent.VK_B)
            b_pressed=true;
        if (code == KeyEvent.VK_CONTROL) {
            if (e.getKeyLocation() == KeyEvent.KEY_LOCATION_LEFT) {

                LctrlPressed=true;
            } else if (e.getKeyLocation() == KeyEvent.KEY_LOCATION_RIGHT) {

                RctrlPressed=true;
            }
        }
        if(code==KeyEvent.VK_ENTER)
            enterPressed=true;
        else if(code==KeyEvent.VK_ESCAPE)
            escapePressed=true;

        if(code==KeyEvent.VK_I && gp.gameState==gp.playState)
            gp.gameState=gp.inventoryState;

        if(code==KeyEvent.VK_Q && gp.gameState==gp.playState)
            gp.gameState=gp.questState;
        if(code==KeyEvent.VK_M && gp.gameState==gp.playState)
            gp.gameState=gp.mapState;
        else if(code==KeyEvent.VK_M && gp.gameState==gp.mapState)
            gp.gameState=gp.playState;
        else if(code==KeyEvent.VK_L && gp.gameState==gp.playState)
            gp.gameState=gp.shopState;

        else if(escapePressed==true)
        {
            if(gp.gameState==gp.playState)
                gp.gameState=gp.pauseState;
            else if(gp.gameState==gp.pauseState)
                gp.gameState=gp.playState;
            else if(gp.gameState==gp.inventoryState)
                gp.gameState=gp.playState;
            else if(gp.gameState==gp.questState)
                gp.gameState=gp.playState;
            else if(gp.gameState==gp.shopState)
                gp.gameState=gp.playState;
        }



    }

    @Override
    public void keyReleased(KeyEvent e) {

        int code= e.getKeyCode();

        if(code==KeyEvent.VK_W)
            w_pressed=false;
        if(code==KeyEvent.VK_S)
            s_pressed=false;
        if(code==KeyEvent.VK_A)
            a_pressed=false;
        if(code==KeyEvent.VK_D)
            d_pressed=false;
        if (code == KeyEvent.VK_UP)
            upPressed = false;
        if (code == KeyEvent.VK_DOWN)
            downPressed = false;
        if (code == KeyEvent.VK_LEFT)
            leftPressed = false;
        if (code == KeyEvent.VK_RIGHT)
            rightPressed = false;
        if (code == KeyEvent.VK_SPACE)
            spacePressed = false;
        if (code == KeyEvent.VK_X)
            x_pressed = false;
        if (code == KeyEvent.VK_F)
            f_pressed = false;
        if(code==KeyEvent.VK_1)
            one_pressed=false;
        if(code==KeyEvent.VK_2)
            two_pressed=false;
        if(code==KeyEvent.VK_3)
            three_pressed=false;

        if(code==KeyEvent.VK_ENTER)
            enterPressed=false;
        else if(code==KeyEvent.VK_ESCAPE)
            escapePressed=false;

        if (code == KeyEvent.VK_CONTROL) {
            if (e.getKeyLocation() == KeyEvent.KEY_LOCATION_LEFT) {

               LctrlPressed=false;
            } else if (e.getKeyLocation() == KeyEvent.KEY_LOCATION_RIGHT) {

                RctrlPressed=false;
            }
        }

        if(code==KeyEvent.VK_B)
            b_pressed=false;

    }
}

package Wyswietlanie;

import Swiat.Swiat;
import Swiat.Ruch;

import javax.swing.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class ZczytajKlawisz implements KeyListener {
    private Ruch key;
    private Swiat world;
    private JFrame frame;

    public ZczytajKlawisz(Ruch key, Swiat swiat){
        this.key = key;
        this.world = swiat;
    }

    public void attachToFrame(JFrame frame) {
        this.frame = frame;
        frame.addKeyListener(this);
        frame.setFocusable(true);
        frame.requestFocusInWindow();
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()){
            case KeyEvent.VK_UP : {
                key = Ruch.UP;
                System.out.println(key);
                break;
            }
            case KeyEvent.VK_DOWN : {
                key = Ruch.DOWN;
                break;
            }
            case KeyEvent.VK_LEFT : {
                key = Ruch.LEFT;
                break;
            }
            case KeyEvent.VK_RIGHT : {
                key = Ruch.RIGHT;
                break;
            }
            case KeyEvent.VK_S : {
                key = Ruch.SKIP;
                break;
            }
            case KeyEvent.VK_U : {
                key = Ruch.SKILL;
                break;
            }
            default : {
                key = Ruch.UNDEFINED;
                break;
            }
        }
        if(key != Ruch.UNDEFINED)
            world.wykonajTure(key);
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}

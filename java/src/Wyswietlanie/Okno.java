package Wyswietlanie;

import Swiat.Swiat;
import Swiat.Ruch;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.List;

public class Okno extends JFrame {
    private Swiat world;
    private Menu menu = new Menu(this);
    private JTextArea console = new JTextArea();
    private Mapa map = new Mapa();
    private ZczytajKlawisz keyListener;
    private Ruch key = Ruch.UNDEFINED;

    public Okno(){
        setTitle("Oliwier Komorowski 197808");
        setSize(800,800);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        menu.setSize(getWidth(),100);
        console.setSize(300,getHeight());
        creatSwiat();
//        keyListener = new ZczytajKlawisz(key, world);
//        addKeyListener(keyListener);
//        keyListener.attachToFrame(this);
        add(menu, BorderLayout.NORTH);
//        game.add(console);
//        game.add(map);
//        add(game);
        add(map, BorderLayout.CENTER);
        JFrame logWindow = new JFrame("Logi");
        logWindow.setSize(300,300);
        logWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        logWindow.add(console);
        logWindow.setVisible(true);
        setVisible(true);
        setFocusable(true);
        requestFocus(true);
    }

    public void creatSwiat(){
        JPanel panel = new JPanel();
        JToggleButton option = new JToggleButton("Nowy świat");
        option.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (option.isSelected())
                {
                    option.setText("Wczytaj świat");
                }
                else
                {
                    option.setText("Nowy świat");
                }
            }
        });
        panel.add(option);
        while (true)
        {
            int result = JOptionPane.showConfirmDialog(null, panel, "Wybierz świat", JOptionPane.OK_OPTION, JOptionPane.PLAIN_MESSAGE);
            if (result == JOptionPane.OK_OPTION) {
                if (option.isSelected())
                {
                    if (loadWorld())
                    {
                        menu.setWorld(world);
                        map.setWorld(world);
                        break;
                    }
                }
                else
                {
                    if (newWorld())
                    {
                        menu.setWorld(world);
                        map.setWorld(world);
                        break;
                    }
                }
            }
            else
                break;
        }

        keyListener = new ZczytajKlawisz(key, world);
        addKeyListener(keyListener);
        keyListener.attachToFrame(this);
    }

    private boolean newWorld(){
        JPanel panel = new JPanel(new GridLayout(2,3));
        panel.add(new Label("Wysokość: "));
        JSlider height = new JSlider(5,99,15);
        final Integer[] h = new Integer[1];
        h[0] = height.getValue();
        JLabel lh = new JLabel(h[0].toString());
        height.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                h[0] = height.getValue();
                lh.setText(h[0].toString());
            }
        });
        panel.add(lh);
        panel.add(height);
        panel.add(new Label("Szerokość: "));
        JSlider width = new JSlider(5,99,15);
        final Integer[] w = new Integer[1];
        w[0] = width.getValue();
        JLabel lw = new JLabel(w[0].toString());
        width.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                w[0] = width.getValue();
                lw.setText(w[0].toString());
            }
        });
        panel.add(lw);
        panel.add(width);

        int result = JOptionPane.showConfirmDialog(null, panel, "Wybierz wymiary", JOptionPane.OK_OPTION, JOptionPane.PLAIN_MESSAGE);
        if (result == JOptionPane.OK_OPTION)
        {
            world = new Swiat(height.getValue(), width.getValue(), this);
            return true;
        }
        else
            return false;
    }

    private boolean loadWorld(){
        JPanel panel = new JPanel(new GridLayout(2,1));
        panel.add(new Label("Nazwa pliku: "));
        JTextField fileName = new JTextField();
        panel.add(fileName);

        int result = JOptionPane.showConfirmDialog(null, panel, "Wczytaj zapis", JOptionPane.OK_OPTION, JOptionPane.PLAIN_MESSAGE);
        if (result == JOptionPane.OK_OPTION)
        {
            try {
                List<String> allLines = Files.readAllLines(Paths.get(fileName.getText()+".txt"));
                System.out.println(fileName.getText());
                world = new Swiat(allLines, this);
                return true;
            } catch (IOException e) {
                JOptionPane.showMessageDialog(null, "Błąd odczytu pliku.", "Error", JOptionPane.ERROR_MESSAGE);
                return false;
            }
        }
        else
            return false;
    }


    public String getText(){
        return JOptionPane.showInputDialog("Podaj nazwę");
    }

//    public Ruch getKey() {
//        this.setFocusable(true);
////        switch (buff){
////            case KeyEvent.VK_UP : {
////                key = Ruch.UP;
////                setTitle("UP");
////                break;
////            }
////            case KeyEvent.VK_DOWN : {
////                key = Ruch.DOWN;
////                setTitle("DOWN");
////                break;
////            }
////            case KeyEvent.VK_LEFT : {
////                key = Ruch.LEFT;
////                break;
////            }
////            case KeyEvent.VK_RIGHT : {
////                key = Ruch.RIGHT;
////                break;
////            }
////            case KeyEvent.VK_S : {
////                key = Ruch.SKIP;
////                break;
////            }
////            case KeyEvent.VK_U : {
////                key = Ruch.SKILL;
////                break;
////            }
////            default : {
////                break;
////            }
////        }
//
//        buff = KeyEvent.VK_UNDEFINED;
//        return key;
//    }

    public void updateConsole(String s){
        console.setText(s);
    }

    public void updateField(int x, int y){
        map.updatePole(x,y);
    }

//    @Override
//    public void keyTyped(KeyEvent e) {
//        buff = e.getKeyCode();
//        switch (buff){
//            case KeyEvent.VK_UP : {
//                key = Ruch.UP;
//                setTitle("UP");
//                break;
//            }
//            case KeyEvent.VK_DOWN : {
//                key = Ruch.DOWN;
//                setTitle("DOWN");
//                break;
//            }
//            case KeyEvent.VK_LEFT : {
//                key = Ruch.LEFT;
//                break;
//            }
//            case KeyEvent.VK_RIGHT : {
//                key = Ruch.RIGHT;
//                break;
//            }
//            case KeyEvent.VK_S : {
//                key = Ruch.SKILL;
//                break;
//            }
//            case KeyEvent.VK_U : {
//                key = Ruch.SKILL;
//                break;
//            }
//            default : {
//                key = Ruch.UNDEFINED;
//                break;
//            }
//        }
//        System.out.println(buff);
//        notifyAll();
//    }
//
//    @Override
//    public void keyPressed(KeyEvent e) {
//        buff = e.getKeyCode();
//        System.out.println(buff);
//    }
//
//    @Override
//    public void keyReleased(KeyEvent e) {
//
//    }

    public void printBoard(){
        map.printBoard();
    }

//    @Override
//    public void keyTyped(KeyEvent e) {
//
//    }
//
//    @Override
//    public void keyPressed(KeyEvent e) {
//        buff = e.getKeyCode();
//        switch (buff){
//            case KeyEvent.VK_UP : {
//                key = Ruch.UP;
//                System.out.println(buff);
//                setTitle("UP");
//                break;
//            }
//            case KeyEvent.VK_DOWN : {
//                key = Ruch.DOWN;
//                setTitle("DOWN");
//                break;
//            }
//            case KeyEvent.VK_LEFT : {
//                key = Ruch.LEFT;
//                break;
//            }
//            case KeyEvent.VK_RIGHT : {
//                key = Ruch.RIGHT;
//                break;
//            }
//            case KeyEvent.VK_S : {
//                key = Ruch.SKIP;
//                break;
//            }
//            case KeyEvent.VK_U : {
//                key = Ruch.SKILL;
//                break;
//            }
//            default : {
//                key = Ruch.UNDEFINED;
//                break;
//            }
//        }
//        if(key != Ruch.UNDEFINED)
//            world.wykonajTure(key);
//    }
//
//    @Override
//    public void keyReleased(KeyEvent e) {
//
//    }
}

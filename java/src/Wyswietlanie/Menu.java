package Wyswietlanie;

import Swiat.Swiat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

public class Menu extends JPanel {
    private Swiat world;
    private final JFrame f;

    public Menu(JFrame frame){
        f = frame;
        setLayout(new GridLayout(3,1));
        setBackground(Color.LIGHT_GRAY);
        JButton saveWorld = new JButton("Zapisz");
        saveWorld.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.zapisz();
                f.requestFocus();
            }
        });
        JButton newWorld = new JButton("Nowy świat");
        newWorld.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.nowySwiat();
                f.requestFocus();
            }
        });
        JButton nextTurn = new JButton("Kolejna tura");
        nextTurn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                f.requestFocus();
            }
        });
        add(nextTurn);
        add(saveWorld);
        add(newWorld);
        setVisible(true);
    }
    public void setWidth(int width){
        setPreferredSize(new Dimension(width,50));
    }
    public void setWorld(Swiat world) {
        this.world=world;
    }
}

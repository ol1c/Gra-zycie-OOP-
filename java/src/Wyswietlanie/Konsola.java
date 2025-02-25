package Wyswietlanie;

import Swiat.Swiat;

import javax.swing.*;
import java.awt.*;

public class Konsola extends JScrollPane {
    private JPanel container = new JPanel();
    private JTextArea text = new JTextArea();
    private Swiat world;

    public Konsola(){
        text.setText("");
        container.add(text);
        container.setLayout(new BoxLayout(container, BoxLayout.Y_AXIS));
        container.setVisible(true);
        add(container);
        setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        setVisible(true);
    }

    public void setWorld(Swiat world) {
        this.world=world;
    }

    public void update(String s){
        this.text.setText(s);
        container.setVisible(true);
        setVisible(true);
    }
}

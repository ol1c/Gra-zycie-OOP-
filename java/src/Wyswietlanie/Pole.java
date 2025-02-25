package Wyswietlanie;

import Swiat.Organizm;
import Swiat.Swiat;
import Swiat.Gatunek;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Pole extends JButton {
    private int x;
    private int y;
    private Swiat world;
    public Pole(int x, int y, Swiat world){
        this.x=x;
        this.y=y;
        this.world=world;
        setSize(20,20);
        addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(world.ktoStoi(x,y) == null)
                    dodajOrganizmMenu();
                else
                    pokazOrganizm();
            }
        });
    }

    public void update(){
        Organizm o = world.ktoStoi(x,y);
        if(o == null)
        {
            setText("");
        }
        else
        {
            setText(o.rysowanie());
        }
        repaint();
    }

    private void dodajOrganizmMenu(){
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(3,4));
        JButton b = new JButton("Barszcz Sosnowskiego");
        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.BARSZCZ_SOSNOWSKIEGO,x,y);
                update();
            }
        });
        JButton g = new JButton("Guarana");
        g.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.GUARANA,x,y);
                update();
            }
        });
        JButton m = new JButton("Mlecz");
        m.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.MLECZ,x,y);
                update();
            }
        });
        JButton t = new JButton("Trawa");
        t.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.TRAWA,x,y);
                update();
            }
        });
        JButton j = new JButton("Wilcze Jagody");
        j.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.WILCZE_JAGODY,x,y);
                update();
            }
        });
        JButton a = new JButton("Antylopa");
        a.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.ANTYLOPA,x,y);
                update();
            }
        });
        JButton c = new JButton("Człowiek");
        c.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.CZLOWIEK,x,y);
                update();
            }
        });
        JButton l = new JButton("Lis");
        l.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.LIS,x,y);
                update();
            }
        });
        JButton o = new JButton("Owca");
        o.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.OWCA,x,y);
                update();
            }
        });
        JButton w = new JButton("Wilk");
        w.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.WILK,x,y);
                update();
            }
        });
        JButton z = new JButton("Zółw");
        z.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.dodajOrganizm(Gatunek.ZOLW,x,y);
                update();
            }
        });
        panel.add(b);
        panel.add(g);
        panel.add(m);
        panel.add(t);
        panel.add(j);
        panel.add(a);
        panel.add(l);
        panel.add(o);
        panel.add(w);
        panel.add(z);
        panel.add(c);

        JOptionPane.showMessageDialog(null,panel,"Dodaj organizm",JOptionPane.PLAIN_MESSAGE);
    }

    private void pokazOrganizm() {
        JOptionPane.showMessageDialog(null,world.ktoStoi(x,y).toString(),"Zawartość pola",JOptionPane.PLAIN_MESSAGE);
    }

}

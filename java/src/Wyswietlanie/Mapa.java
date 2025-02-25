package Wyswietlanie;

import Swiat.Swiat;
import Swiat.Organizm;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class Mapa extends JPanel {
    private Swiat world;
    private Pole[][] board;

    public Mapa(){
    }

    public void setWorld(Swiat world){
        int height;
        int width;
        if (this.world != null)
        {
            height = this.world.getHeight();
            width = this.world.getWidth();
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    remove(board[i][j]);
                }
            }
        }
        this.world=world;
        height = world.getHeight();
        width = world.getWidth();
        board = new Pole[height][width];
        setLayout(new GridLayout(height,width));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                board[i][j] = new Pole(i,j,world);
                add(board[i][j]);
                updatePole(i,j);
            }
        }
    }

    public void updatePole(int x, int y){
        if(world != null)
        {
            board[x][y].update();
        }
    }

    public void printBoard(){
        int height = world.getHeight();
        int width = world.getWidth();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                updatePole(i,j);
            }
        }
    }
}

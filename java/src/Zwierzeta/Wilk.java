package Zwierzeta;
import Swiat.*;

public class Wilk extends Zwierze{
    public Wilk(int x, int y , Swiat swiat){
        super(Gatunek.WILK, 9,5, x, y, swiat);
    }
    public Wilk(int x, int y, int sila, Swiat swiat){
        super(Gatunek.WILK, sila,5, x, y, swiat);
    }

    @Override
    public String rysowanie(){return "W";}
}

package Rosliny;
import Swiat.*;

public class Trawa extends Roslina{
    public Trawa(int x, int y, Swiat swiat){super(Gatunek.TRAWA, 0, 0, x, y, swiat);}
    public Trawa(int x, int y, int sila, Swiat swiat){super(Gatunek.TRAWA, sila, 0, x, y, swiat);}

    @Override
    public String rysowanie(){return "T";}
}

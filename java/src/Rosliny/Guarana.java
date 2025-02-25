package Rosliny;
import Swiat.*;

public class Guarana extends Roslina{
    public Guarana(int x, int y, Swiat swiat){
        super(Gatunek.GUARANA, 0, 0, x, y, swiat);
    }
    public Guarana(int x, int y, int sila, Swiat swiat){
        super(Gatunek.GUARANA, sila, 0, x, y, swiat);
    }

    @Override
    public void kolizja(Organizm organizm){
        this.walka(organizm);
        organizm.zwiekszSila(3);
    }

    @Override
    public String rysowanie(){return "G";}
}
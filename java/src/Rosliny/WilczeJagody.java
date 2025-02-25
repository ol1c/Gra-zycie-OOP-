package Rosliny;
import Swiat.*;

public class WilczeJagody extends Roslina{
    public WilczeJagody(int x, int y, Swiat swiat){
        super(Gatunek.WILCZE_JAGODY, 99, 0, x, y, swiat);
    }
    public WilczeJagody(int x, int y, int sila, Swiat swiat){
        super(Gatunek.WILCZE_JAGODY, sila, 0, x, y, swiat);
    }

    @Override
    public void kolizja(Organizm organizm){
        this.swiat.dodajLog(organizm.toString() + " je " + this.toString());
        this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
        this.zabij();
        organizm.zabij();
//        swiat.zwolnijPole(polozenie.x,polozenie.y);
    }

    @Override
    public String rysowanie(){return "J";}
}
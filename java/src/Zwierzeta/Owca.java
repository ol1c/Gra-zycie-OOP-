package Zwierzeta;
import Swiat.*;

public class Owca extends Zwierze{
    public Owca(int x, int y , Swiat swiat){
        super(Gatunek.OWCA, 4,4, x, y, swiat);
    }
    public Owca(int x, int y, int sila, Swiat swiat){
        super(Gatunek.OWCA, sila,4, x, y, swiat);
    }

    @Override
    public String rysowanie(){return "O";}
}

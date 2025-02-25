package Rosliny;
import Swiat.*;

public class Mlecz extends Roslina{
    public Mlecz(int x, int y, Swiat swiat){
        super(Gatunek.MLECZ, 0, 0, x, y, swiat);
    }
    public Mlecz(int x, int y, int sila, Swiat swiat){
        super(Gatunek.MLECZ, sila, 0, x, y, swiat);
    }

    @Override
    public Polozenie akcja(){
        int czyRozmnozy;
        for(int i = 0; i < 3 ; i++)
        {
            czyRozmnozy = this.swiat.getLosowaLiczba(0, this.szansaNaRozmnozenie);
            if (czyRozmnozy == 0)
                this.swiat.dodajOrganizm(this.gatunek, this.polozenie.x, this.polozenie.y);
        }
        return this.polozenie;
    }

    @Override
    public String rysowanie(){return "M";}
}

package Zwierzeta;
import Swiat.*;

public class Zolw extends Zwierze{
    public Zolw(int x, int y , Swiat swiat){
        super(Gatunek.ZOLW, 2,1, x, y, swiat);
    }
    public Zolw(int x, int y, int sila, Swiat swiat){
        super(Gatunek.ZOLW, sila,1, x, y, swiat);
    }

    @Override
    public Polozenie akcja(){
//        swiat.zwolnijPole(polozenie.x,polozenie.y);
        int czyRuszy = this.swiat.getLosowaLiczba(0,3);
        if (czyRuszy == 0)
            return this.swiat.getLosowyRuch(this.polozenie);
        return this.polozenie;
    }

    @Override
    public void kolizja(Organizm organizm)
    {
        if(organizm instanceof Zolw)
            this.swiat.dodajOrganizm(Gatunek.ZOLW, this.polozenie.x, this.polozenie.y);
        else
        {
            if(organizm.getSila() < 5)
                this.swiat.losowePrzesuniecie(organizm,this.polozenie);
            else
                this.walka(organizm);
        }
    }

    @Override
    public String rysowanie(){return "Z";}
}

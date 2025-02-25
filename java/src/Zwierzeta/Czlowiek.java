package Zwierzeta;
import Swiat.*;

public class Czlowiek extends Zwierze {
    private Umiejetnosc umiejetnosc = new Umiejetnosc();

    public Czlowiek(int x, int y, Swiat swiat){
        super(Gatunek.CZLOWIEK, 5, 4, x, y, swiat);
    }
    public Czlowiek(int x, int y, int sila, int um, Swiat swiat){
        super(Gatunek.CZLOWIEK, sila, 4, x, y, swiat);
        umiejetnosc.setTrwanie(um);
    }

    @Override
    public Polozenie akcja(){
//        swiat.zwolnijPole(polozenie.x,polozenie.y);
        this.umiejetnosc.aktualizuj();
        Polozenie p = new Polozenie();
        p.x = this.polozenie.x;
        p.y = this.polozenie.y;
        Ruch ruch = swiat.getRuch();
        if (ruch == Ruch.SKILL)
        {
            if (umiejetnosc.czyMoznaUzyc())
                umiejetnosc.uzyj();
            else
            {
                swiat.dodajLog("Umiejętność niedostępna.");
            }
        }
        switch (ruch)
        {
            case Ruch.UP:
            {
                p.x--;
                break;
            }
            case Ruch.DOWN:
            {
                p.x++;
                break;
            }
            case Ruch.LEFT:
            {
                p.y--;
                break;
            }
            case Ruch.RIGHT:
            {
                p.y++;
                break;
            }
            default:
                break;
        }
        if(!this.swiat.czyNaMapie(p.x,p.y))
        {
            p.x = this.polozenie.x;
            p.y = this.polozenie.y;
        }

        return p;
    }

    @Override
    public void kolizja(Organizm organizm){
        if(organizm instanceof Czlowiek)
            this.swiat.dodajOrganizm(Gatunek.CZLOWIEK, this.polozenie.x, this.polozenie.y);
        else
        {
            if(this.umiejetnosc.czyAktywna())
            {
                this.swiat.losowePrzesuniecie(organizm, this.polozenie);
                this.swiat.dodajLog(this.toString() + " przesunał " + organizm.toString());
            }
            else
            {
                this.walka(organizm);
            }
        }
    }

    @Override
    public String toZapis(){
        return this.gatunek.toString() + "\n" + this.polozenie.x + "\n" + this.polozenie.y + "\n" + this.sila + "\n" + this.umiejetnosc.getTrwanie();
    }

    @Override
    public String rysowanie(){
        if (umiejetnosc.czyAktywna())
            return  "^o^";
        else
            return "-_-";
    }
}

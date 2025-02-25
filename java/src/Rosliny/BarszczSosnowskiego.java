package Rosliny;
import Swiat.*;

public class BarszczSosnowskiego extends Roslina{
    public BarszczSosnowskiego(int x, int y, Swiat swiat){
        super(Gatunek.BARSZCZ_SOSNOWSKIEGO, 10, 0, x, y, swiat);
    }
    public BarszczSosnowskiego(int x, int y, int sila, Swiat swiat){
        super(Gatunek.BARSZCZ_SOSNOWSKIEGO, sila, 0, x, y, swiat);
    }


    @Override
    public Polozenie akcja(){
        Organizm organizm = this.swiat.ktoStoi(this.polozenie.x - 1, this.polozenie.y + 1);
        if (organizm != null) {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);
        }
        organizm = this.swiat.ktoStoi(this.polozenie.x - 1, this.polozenie.y);
        if (organizm != null) {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);
        }
        organizm = this.swiat.ktoStoi(this.polozenie.x - 1, this.polozenie.y - 1);
        if (organizm != null) {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);
        }
        organizm = this.swiat.ktoStoi(this.polozenie.x + 1, this.polozenie.y + 1);
        if (organizm != null) {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);
        }
        organizm = this.swiat.ktoStoi(this.polozenie.x + 1, this.polozenie.y);
        if (organizm != null) {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);
        }
        organizm = this.swiat.ktoStoi(this.polozenie.x + 1, this.polozenie.y - 1);
        if (organizm != null) {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);
        }
        organizm = this.swiat.ktoStoi(this.polozenie.x, this.polozenie.y + 1);
        if (organizm != null) {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);
        }
        organizm = this.swiat.ktoStoi(this.polozenie.x, this.polozenie.y - 1);
        if (organizm != null) {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);
        }

        int czyRozmnozy = this.swiat.getLosowaLiczba(0, this.szansaNaRozmnozenie);
        if (czyRozmnozy == 0)
            this.swiat.dodajOrganizm(this.gatunek, this.polozenie.x, this.polozenie.y);

        return this.polozenie;
    }

    @Override
    public void kolizja(Organizm organizm){
        this.swiat.dodajLog(organizm.toString() + " je " + this.toString());
        this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
        this.zabij();
        organizm.zabij();
    }

    @Override
    public String rysowanie(){return "B";}
}

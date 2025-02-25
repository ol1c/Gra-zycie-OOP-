package Rosliny;
import Swiat.*;

public abstract class Roslina implements Organizm {
    protected final Gatunek gatunek;
    protected int sila;
    protected final int inicjatywa;
    protected Polozenie polozenie = new Polozenie();
    protected final Swiat swiat;
    protected boolean zyje = true;
    protected static int szansaNaRozmnozenie = 50;

    public Roslina(Gatunek gatunek, int sila, int inicjatywa, int x, int y, Swiat swiat){
        this.gatunek = gatunek;
        this.sila = sila;
        this.inicjatywa = inicjatywa;
        this.polozenie.x = x;
        this.polozenie.y = y;
        this.swiat = swiat;
    }

    @Override
    public Polozenie akcja(){
        int czyRozmnozy = this.swiat.getLosowaLiczba(0,this.szansaNaRozmnozenie);
        if (czyRozmnozy == 0)
        {
            this.swiat.dodajOrganizm(this.gatunek, this.polozenie.x, this.polozenie.y);
        }
        return this.polozenie;
    }

    @Override
    public void kolizja(Organizm organizm){
        this.walka(organizm);
    }

    protected void walka(Organizm organizm){
        if (this.sila > organizm.getSila())
        {
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            organizm.zabij();

        }
        else
        {
            this.swiat.dodajLog(organizm.toString() + " je " + this.toString());
            organizm.setPolozenie(this.polozenie);
            this.zabij();
        }
    }

    @Override
    final public boolean getZyje() {
        return zyje;
    }

    @Override
    final public Gatunek getGatunek() {
        return gatunek;
    }

    @Override
    final public int getInicjatywa() {
        return inicjatywa;
    }

    @Override
    final public int getSila() {
        return sila;
    }

    @Override
    public void zwiekszSila(int sila){
        this.sila += sila;
    }

    @Override
    final public Polozenie getPolozenie() {
        return polozenie;
    }

    @Override
    final public void setPolozenie(Polozenie polozenie) {
        this.polozenie.x = polozenie.x;
        this.polozenie.y = polozenie.y;
    }

    @Override
    final public String toZapis() {
        return this.gatunek.toString() + "\n" + this.polozenie.x + "\n" + this.polozenie.y + "\n" + this.sila;
    }

    @Override
    final public void zabij(){
        this.zyje = false;
    }

    @Override
    public String toString(){
        return this.gatunek.toString() + "[" + this.polozenie.x + "][" + this.polozenie.y + "]";
    }

    @Override
    public String rysowanie(){return gatunek.toString();}
}

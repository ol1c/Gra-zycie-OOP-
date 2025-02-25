package Zwierzeta;
import Swiat.*;

public abstract class Zwierze implements Organizm {
    protected final Gatunek gatunek;
    protected int sila;
    protected final int inicjatywa;
    protected Polozenie polozenie = new Polozenie();
    protected final Swiat swiat;
    protected boolean zyje = true;

    public Zwierze(Gatunek gatunek, int sila, int inicjatywa, int x, int y, Swiat swiat){
        this.gatunek = gatunek;
        this.sila = sila;
        this.inicjatywa = inicjatywa;
        this.polozenie.x = x;
        this.polozenie.y = y;
        this.swiat = swiat;
    }

    @Override
    public Polozenie akcja(){
//        swiat.zwolnijPole(polozenie.x,polozenie.y);
        return this.swiat.getLosowyRuch(this.polozenie);
    }

    @Override
    public void kolizja(Organizm organizm){
        /**
         * jeśli dojdzie do kolizji dwóch tych samych gatunków
         * powstanie nowy organizm tego samego gatunku
         */
        if (this.gatunek == organizm.getGatunek())
            this.swiat.dodajOrganizm(this.gatunek, this.polozenie.x, this.polozenie.y);
        /**
         * w innym przypadku dojdzie do walki
         */
        else
            this.walka(organizm);
    }

    protected void walka(Organizm organizm){
        if (this.sila > organizm.getSila())
        {
            organizm.zabij();
            this.swiat.dodajLog(this.toString() + " zabił/a " + organizm.toString());
            Polozenie p = organizm.getPolozenie();
//            swiat.zwolnijPole(p.x,p.y);

        }
        else
        {
            organizm.setPolozenie(this.polozenie);
            this.zabij();
            this.swiat.dodajLog(organizm.toString() + " zabił/a " + this.toString());
//            swiat.zwolnijPole(polozenie.x,polozenie.y);
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
    public String toZapis() {
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

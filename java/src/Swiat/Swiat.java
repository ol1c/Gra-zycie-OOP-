package Swiat;
import Rosliny.*;
import Zwierzeta.*;
import Wyswietlanie.Okno;

import java.io.FileWriter;
import java.io.IOException;
import java.io.InterruptedIOException;
import java.util.ConcurrentModificationException;
import java.util.LinkedList;
import java.util.List;

public class Swiat {
    private List<Organizm> organizmy = new LinkedList<>();
    private String logi = "";
    private int height = 15;
    private int width = 15;
    private Okno widok;
    private Ruch ruch;

    public Swiat(Okno widok) {
        this.widok = widok;
        poczatkowaPopulacja();
    }

    public Swiat(int rozmiarX, int rozmiarY, Okno widok){
        height = rozmiarX;
        width = rozmiarY;
        this.widok = widok;
        wyczyscSwiat();
        poczatkowaPopulacja();
    }

    public Swiat(List<String> zapis, Okno widok){
        wyczyscSwiat();

        this.widok = widok;
        String gatunek = new String();
        int x;
        int y;
        int sila;
        int um;


        setHeight(Integer.parseInt(zapis.getFirst()));
        zapis.removeFirst();
        setWidth(Integer.parseInt(zapis.getFirst()));
        zapis.removeFirst();

        while(!zapis.isEmpty())
        {
            gatunek = zapis.getFirst();
            zapis.removeFirst();
            x = Integer.parseInt(zapis.getFirst());
            zapis.removeFirst();
            y = Integer.parseInt(zapis.getFirst());
            zapis.removeFirst();
            sila = Integer.parseInt(zapis.getFirst());
            zapis.removeFirst();

            if (gatunek.equals("CZLOWIEK"))
            {
                um = Integer.parseInt(zapis.getFirst());
                zapis.removeFirst();
                dodajOrganizm(Gatunek.CZLOWIEK,x,y,sila,um);
            }
            else
                dodajOrganizm(jakiGatunek(gatunek),x,y,sila);

        }
    }

    public void nowySwiat(){
        widok.creatSwiat();
    }

    public Organizm ktoStoi(int x, int y){
        Polozenie p = new Polozenie();
        p.x = x;
        p.y = y;
        try{
            for (Organizm organizm : organizmy) {
                if (p.equals(organizm.getPolozenie()))
                    if (organizm.getZyje())
                        return organizm;
            }
        }catch (ConcurrentModificationException e){
            System.out.println("kto stoi error\n");
        }
        return null;
    }

    public void wykonajTure(Ruch r) {
        this.ruch = r;
        logi="";
        Polozenie p;
        Organizm o2;
        try {
            for (Organizm o : organizmy) {
                if (o.getZyje()) {
                    p = o.akcja();
                    o2 = ktoStoi(p.x, p.y);
                    if (o2 == null || o2.equals(o)) {
                        o.setPolozenie(p);
                    } else {
                        o2.kolizja(o);
                    }

                    widok.printBoard();
                }
            }
        } catch (ConcurrentModificationException e){
            System.out.println("foreach error");
        }
        System.out.println("\nkoniec tury");
        widok.printBoard();
        widok.updateConsole(logi);
        oczyscOrganizmy();
    }

//    public void aktualizujPole(int x, int y){
//        widok.updateField(x,y);
//    }

//    public void zwolnijPole(int x, int y) {
//        widok.updateField(x,y);
//    }

    public boolean zapisz() {
        String fileName = widok.getText();
        while (fileName.equals("\0"))
        {
            fileName = widok.getText();
        }
        fileName += ".txt";
        try (FileWriter zapis = new FileWriter(fileName)) {
            zapis.write(height+"\n");
            zapis.write(width+"\n");
            for(Organizm o : organizmy) {
                zapis.write(o.toZapis()+"\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "Świat wysokość " + this.height + ", szerokość " + this.width + "\n" + organizmy.toString();
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getLosowaLiczba(int min, int max) {
        return (int) ((Math.random() * (max - min)) + min);
    }

    public void dodajLog(String log){
        this.logi += (log + "\n");
    }

    public void dodajOrganizm(Gatunek gatunek, int x, int y){
        int nowyX = x;
        int nowyY = y;
        if (this.czyNaMapie(x,y) && this.ktoStoi(x,y) == null);
        else if (this.czyNaMapie(x + 1,y + 1) && this.ktoStoi(x + 1,y + 1) == null)
        {
            nowyX++;
            nowyY++;
        }
        else if (this.czyNaMapie(x + 1,y - 1) && this.ktoStoi(x + 1,y - 1) == null)
        {
            nowyX++;
            nowyY--;
        }
        else if (this.czyNaMapie(x + 1,y) && this.ktoStoi(x + 1,y) == null)
        {
            nowyX++;
        }
        else if (this.czyNaMapie(x,y - 1) && this.ktoStoi(x,y - 1) == null)
        {
            nowyY--;
        }
        else if (this.czyNaMapie(x,y + 1) && this.ktoStoi(x,y + 1) == null)
        {
            nowyY++;
        }
        else if (this.czyNaMapie(x - 1,y + 1) && this.ktoStoi(x - 1,y + 1) == null)
        {
            nowyX--;
            nowyY++;
        }
        else if (this.czyNaMapie(x - 1,y) && this.ktoStoi(x - 1,y) == null)
        {
            nowyX--;
        }
        else if (this.czyNaMapie(x - 1,y - 1) && this.ktoStoi(x - 1,y - 1) == null)
        {
            nowyX--;
            nowyY--;
        }
        else
        {
            nowyX = -1;
            nowyY = -1;
        }

        if(nowyX != -1 && nowyY != -1)
        {
            switch (gatunek)
            {
                case Gatunek.CZLOWIEK:
                {
                    this.dodajDoListy(new Czlowiek(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.WILK:
                {
                    this.dodajDoListy(new Wilk(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.OWCA:
                {
                    this.dodajDoListy(new Owca(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.LIS:
                {
                    this.dodajDoListy(new Lis(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.ZOLW:
                {
                    this.dodajDoListy(new Zolw(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.ANTYLOPA:
                {
                    this.dodajDoListy(new Antylopa(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.TRAWA:
                {
                    this.dodajDoListy(new Trawa(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.MLECZ:
                {
                    this.dodajDoListy(new Mlecz(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.GUARANA:
                {
                    this.dodajDoListy(new Guarana(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.WILCZE_JAGODY:
                {
                    this.dodajDoListy(new WilczeJagody(nowyX, nowyY, this));
                    break;
                }
                case Gatunek.BARSZCZ_SOSNOWSKIEGO:
                {
                    this.dodajDoListy(new BarszczSosnowskiego(nowyX, nowyY, this));
                    break;
                }
            }

//            widok.updateField(nowyX,nowyY);
        }
    }

    public boolean czyNaMapie (int x, int y){
        return x >= 0 && y >= 0 && x < this.height && y < this.width;
    }

    public void losowePrzesuniecie(Organizm organizm, Polozenie polozenie)
    {
        Polozenie p = new Polozenie();
        p.x = polozenie.x;
        p.y = polozenie.y;
        int kierunek = this.getLosowaLiczba(0, 7);

        switch (kierunek)
        {
            case 0:
            {
                p.x++;
                p.y++;
                break;
            }
            case 1:
            {
                p.x++;
                break;
            }
            case 2: {
                p.x++;
                p.y--;
                break;
            }
            case 3:
            {
                p.x--;
                p.y++;
                break;
            }
            case 4:
            {
                p.x--;
                break;
            }
            case 5:
            {
                p.x--;
                p.y--;
                break;
            }
            case 6:
            {
                p.y--;
                break;
            }
            case 7:
            {
                p.y++;
                break;
            }
        }
        if(!this.czyNaMapie(p.x,p.y) || this.ktoStoi(p.x,p.y) != null)
            p = organizm.getPolozenie();
        organizm.setPolozenie(p);
    }

    public Polozenie getLosowyRuch(Polozenie start) {
        Polozenie p = new Polozenie();
        p.x = start.x;
        p.y = start.y;
        int kierunek = this.getLosowaLiczba(0,3);

        for(int i = 0; i < 4 ; i++)
        {
            switch (kierunek)
            {
                case 0:
                {
                    p.x++;
                    break;
                }
                case 1:
                {
                    p.x--;
                    break;
                }
                case 2:
                {
                    p.y++;
                    break;
                }
                case 3:
                {
                    p.y--;
                    break;
                }
                default:
                    break;
            }

            if (!this.czyNaMapie(p.x, p.y))
            {
                p.x = start.x;
                p.y = start.y;
                kierunek = (kierunek + 1) % 4;
            }
            else
                break;
        }
        return p;
    }

    public Ruch getRuch(){return ruch;}

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    private void poczatkowaPopulacja(){
        /**
         * Dodaje organizm (gatunek, losowa pozycja x, losowa pozycja y)
         */
        this.dodajOrganizm(Gatunek.CZLOWIEK, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.WILK, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.WILK, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.ZOLW, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.ZOLW, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.OWCA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.OWCA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.OWCA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.LIS, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.LIS, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.ANTYLOPA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.ANTYLOPA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.ANTYLOPA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.TRAWA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.TRAWA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.MLECZ, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.MLECZ, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.GUARANA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.GUARANA, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.WILCZE_JAGODY, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.WILCZE_JAGODY, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
        this.dodajOrganizm(Gatunek.BARSZCZ_SOSNOWSKIEGO, this.getLosowaLiczba(0, this.height), this.getLosowaLiczba(0, this.width));
    }

    private void dodajOrganizm(Gatunek gatunek, int x, int y, int sila){
        switch (gatunek)
        {
            case Gatunek.WILK:
            {
                this.dodajDoListy(new Wilk(x, y, this));
                break;
            }
            case Gatunek.OWCA:
            {
                this.dodajDoListy(new Owca(x, y, this));
                break;
            }
            case Gatunek.LIS:
            {
                this.dodajDoListy(new Lis(x, y, this));
                break;
            }
            case Gatunek.ZOLW:
            {
                this.dodajDoListy(new Zolw(x, y, this));
                break;
            }
            case Gatunek.ANTYLOPA:
            {
                this.dodajDoListy(new Antylopa(x, y, this));
                break;
            }
            case Gatunek.TRAWA:
            {
                this.dodajDoListy(new Trawa(x, y, this));
                break;
            }
            case Gatunek.MLECZ:
            {
                this.dodajDoListy(new Mlecz(x, y, this));
                break;
            }
            case Gatunek.GUARANA:
            {
                this.dodajDoListy(new Guarana(x, y, this));
                break;
            }
            case Gatunek.WILCZE_JAGODY:
            {
                this.dodajDoListy(new WilczeJagody(x, y, this));
                break;
            }
            case Gatunek.BARSZCZ_SOSNOWSKIEGO:
            {
                this.dodajDoListy(new BarszczSosnowskiego(x, y, sila, this));
                break;
            }
        }
        widok.updateField(x,y);
    }

    private Gatunek jakiGatunek(String nazwa){
        Gatunek gatunek;
        switch (nazwa)
        {
            case "CZLOWIEK": {
                gatunek = Gatunek.CZLOWIEK;
                break;
            }
            case "OWCA": {
                gatunek = Gatunek.OWCA;
                break;
            }
            case "WILK": {
                gatunek = Gatunek.WILK;
                break;
            }
            case "ZOLW": {
                gatunek = Gatunek.ZOLW;
                break;
            }
            case "LIS": {
                gatunek = Gatunek.LIS;
                break;
            }
            case "ANTYLOPA": {
                gatunek = Gatunek.ANTYLOPA;
                break;
            }
            case "TRAWA": {
                gatunek = Gatunek.TRAWA;
                break;
            }
            case "MLECZ": {
                gatunek = Gatunek.MLECZ;
                break;
            }
            case "GUARANA": {
                gatunek = Gatunek.GUARANA;
                break;
            }
            case "WILCZE_JAGODY": {
                gatunek = Gatunek.WILCZE_JAGODY;
                break;
            }
            case "BARSZCZ_SOSNOWSKIEGO": {
                gatunek = Gatunek.BARSZCZ_SOSNOWSKIEGO;
                break;
            }
            default: {
                gatunek = Gatunek.TRAWA;
                break;
            }
        }

        return gatunek;
    }


    private void dodajDoListy(Organizm organizm){
        this.dodajLog("Nowy organizm: " + organizm.toString());
        int id = organizmy.size();
        for(Organizm o : this.organizmy)
        {
            if(organizm.getInicjatywa() > o.getInicjatywa())
            {
                id = this.organizmy.indexOf(o);
                break;
            }
        }
        this.organizmy.add(id, organizm);
    }

    private void wyczyscSwiat() {
        logi = "";
        organizmy.clear();
    }

    private void dodajOrganizm(Gatunek gatunek, int x, int y, int sila, int umiejetnosc){
        dodajDoListy(new Czlowiek(x, y, sila, umiejetnosc,this));
        widok.updateField(x,y);
    }

    private void oczyscOrganizmy() {
        try{
            organizmy.removeIf(o -> !o.getZyje());
        }catch (ConcurrentModificationException e){
            e.printStackTrace();
        }
    }
}

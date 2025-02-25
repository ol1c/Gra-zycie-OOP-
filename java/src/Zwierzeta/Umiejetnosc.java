package Zwierzeta;

public class Umiejetnosc {
    private static int czas = 5;
    private int trwanie;

    public Umiejetnosc(){this.trwanie = 0;}

    public void aktualizuj(){
        if(trwanie>0)
            trwanie--;
    }

    public void uzyj(){trwanie = 2 * czas;}

    public boolean czyAktywna(){
        if(trwanie>czas)
            return true;
        return false;
    }

    public boolean czyMoznaUzyc(){
        if(trwanie == 0)
            return true;
        return false;
    }

    public int getTrwanie(){return this.trwanie;}

    public void setTrwanie(int t){this.trwanie=t;}
}

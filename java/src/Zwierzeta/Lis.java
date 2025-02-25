package Zwierzeta;
import Swiat.*;

public class Lis extends Zwierze{
    public Lis(int x, int y , Swiat swiat){
        super(Gatunek.LIS, 3,7, x, y, swiat);
    }
    public Lis(int x, int y, int sila, Swiat swiat){
        super(Gatunek.LIS, sila,7, x, y, swiat);
    }

    private boolean czyMocniejszy(Polozenie p)
    {
        Organizm o = this.swiat.ktoStoi(p.x,p.y);
        return o == null || o.getSila() <= this.sila;
    }

    @Override
    public Polozenie akcja(){
//        swiat.zwolnijPole(polozenie.x,polozenie.y);
        Polozenie p = new Polozenie();
        p.x = this.polozenie.x;
        p.y = this.polozenie.y;
        int kierunek = this.swiat.getLosowaLiczba(0,3);
        for(int i = 0; i < 4; i++)
        {
            switch (kierunek)
            {
                case 0:
                {
                    p.x++;
                    break;
                }
                case 1: {
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
            }
            if(!this.swiat.czyNaMapie(p.x,p.y))
            {
                p.x = this.polozenie.x;
                p.y = this.polozenie.y;
            }
            else if(this.czyMocniejszy(p))
                break;

            kierunek = (kierunek + 1) % 4;
        }
        return p;
    }

    @Override
    public String rysowanie(){return "L";}

}

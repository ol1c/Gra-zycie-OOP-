package Zwierzeta;
import Swiat.*;

public class Antylopa extends Zwierze{
    public Antylopa(int x, int y , Swiat swiat){
        super(Gatunek.ANTYLOPA, 2,1, x, y, swiat);
    }
    public Antylopa(int x, int y, int sila, Swiat swiat){
        super(Gatunek.ANTYLOPA, sila,1, x, y, swiat);
    }

    @Override
    public Polozenie akcja(){
//        swiat.zwolnijPole(polozenie.x,polozenie.y);
        Polozenie p = new Polozenie();
        p.x = this.polozenie.x;
        p.y = this.polozenie.y;
        int kierunek = this.swiat.getLosowaLiczba(0,3);

        for(int i = 0; i < 8 ; i++)
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
                case 4:
                {
                    p.x += 2;
                    break;
                }
                case 5:
                {
                    p.x -= 2;
                    break;
                }
                case 6:
                {
                    p.y += 2;
                    break;
                }
                case 7:
                {
                    p.y -= 2;
                    break;
                }
                default:
                    break;
            }

            if (!this.swiat.czyNaMapie(p.x, p.y))
            {
                p.x = this.polozenie.x;
                p.y = this.polozenie.y;
                kierunek = (kierunek + 1) % 4;
            }
            else
                break;
        }
        return p;
    }

    @Override
    public void kolizja(Organizm organizm)
    {
        if(organizm instanceof Antylopa)
            this.swiat.dodajOrganizm(Gatunek.ANTYLOPA, this.polozenie.x, this.polozenie.y);
        else
        {
            int ucieczka = this.swiat.getLosowaLiczba(0,1);
            if(ucieczka == 0)
                this.walka(organizm);
        }
    }

    @Override
    public String rysowanie(){return "A";}
}

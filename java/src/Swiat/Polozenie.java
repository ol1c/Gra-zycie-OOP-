package Swiat;

public class Polozenie {
    public int x;
    public int y;

    public Polozenie(){
    }

    @Override
    public boolean equals(Object obj){
        if (obj instanceof Polozenie)
        {
            Polozenie p = (Polozenie) obj;
            return this.x == p.x && this.y == p.y;
        }
        return false;
    }
}

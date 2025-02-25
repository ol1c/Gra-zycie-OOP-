package Swiat;


public interface Organizm {
    /**
     * Wykonuje akcje organizmu.
     * @return Nowa pozycja, którą organizm chce zająć.
     */
    Polozenie akcja();

    /**
     * Obsługuje kolizje z @param.
     * @param organizm - organizm, który stanął na pozycje tego organizmu.
     */
    void kolizja(Organizm organizm);

    /**
     * Rysuje organizm na mapie.
     */
    String rysowanie();

    /**
     * @return Siła organizmu.
     */
    int getSila();

    /**
     * Zwiększa siłę organimzu o
     * @param sila
     */
    void zwiekszSila(int sila);

    /**
     * @return Inicjatywa organizmu.
     */
    int getInicjatywa();

    /**
     * @return Położenie organizmu.
     */
    Polozenie getPolozenie();

    /**
     * Zmienia położenie organizmu.
     * @param polozenie
     */
    void setPolozenie(Polozenie polozenie);

    /**
     * @return string z danymi do zapisu sanu organizmu.
     */
    String toZapis();

    /**
     * @return Czy organizm żyje.
     */
    boolean getZyje();

    /**
     * @return Gatuenk organizmu.
     */
    Gatunek getGatunek();

    /**
     * Zmienia pole boolean zyje na false.
     */
    void zabij();
}

from plants.roslina import Roslina


class Mlecz(Roslina):

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def __init__(self, x, y, world, sila=0):
        Roslina.__init__(self, "mlecz", sila, 0, x, y, world)

    def akcja(self):
        for x in range(3):
            Roslina.akcja(self)
    def rysowanie(self):
        return "M"

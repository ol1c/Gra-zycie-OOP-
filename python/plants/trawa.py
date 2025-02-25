from plants.roslina import Roslina


class Trawa(Roslina):

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def __init__(self, x, y, world, sila=0):
        Roslina.__init__(self, "trawa", sila, 0, x, y, world)

    def rysowanie(self):
        return "T"

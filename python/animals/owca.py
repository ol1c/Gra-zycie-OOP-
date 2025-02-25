from animals.zwierze import Zwierze


class Owca(Zwierze):

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def __init__(self, x, y, world, sila=4):
        Zwierze.__init__(self, "owca", sila, 4, x, y, world)

    def rysowanie(self):
        return "O"

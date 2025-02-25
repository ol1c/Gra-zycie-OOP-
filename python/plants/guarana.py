from plants.roslina import Roslina


class Guarana(Roslina):

    def __init__(self, x, y, world, sila=0):
        Roslina.__init__(self, "guarana", sila, 0, x, y, world)

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def kolizja(self, o):
        self._world.addLog(o.__str__() + " je " + self.__str__())
        self.kill()
        o.setPolozenie(self._x, self._y)
        o.addSila(3)

    def rysowanie(self):
        return "G"

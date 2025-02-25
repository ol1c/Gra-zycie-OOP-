from animals.zwierze import Zwierze


class Cyberowca(Zwierze):

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def __init__(self, x, y, world, sila=11):
        Zwierze.__init__(self, "cyberowca", sila, 4, x, y, world)

    def akcja(self):
        newX, newY = self._world.getNearestBarszcz(self._x, self._y)
        o = self._world.getOrganism(newX, newY)
        if o is None or o is self:
            self.setPolozenie(newX, newY)
        # elif o.getSpecies() == "barszcz sosnowskiego":
        #     self._world.addLog(self.__str__() + " je " + o.__str__())
        #     o.kill()
        else:
            o.kolizja(self)

    def rysowanie(self):
        return "C"

    def isResistantToBarszcz(self):
        return True

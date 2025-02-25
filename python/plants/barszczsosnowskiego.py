from plants.roslina import Roslina


class BarszczSosnowskiego(Roslina):

    def __init__(self, x, y, world, sila=10):
        Roslina.__init__(self, "barszcz sosnowskiego", sila, 0, x, y, world)

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def akcja(self):
        o = self._world.getOrganism(self._x - 1, self._y + 1)
        if o is not None and o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()
        o = self._world.getOrganism(self._x - 1, self._y)
        if o is not None and o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()
        o = self._world.getOrganism(self._x - 1, self._y - 1)
        if o is not None and o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()
        o = self._world.getOrganism(self._x + 1, self._y + 1)
        if o is not None and o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()
        o = self._world.getOrganism(self._x + 1, self._y)
        if o is not None and o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()
        o = self._world.getOrganism(self._x + 1, self._y - 1)
        if o is not None and o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()
        o = self._world.getOrganism(self._x, self._y + 1)
        if o is not None and o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()
        o = self._world.getOrganism(self._x, self._y - 1)
        if o is not None and o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()

        Roslina.akcja(self)

    def kolizja(self, o):
        self._world.addLog(o.__str__() + " je " + self.__str__())
        self.kill()
        o.setPolozenie(self._x, self._y)
        if o.isResistantToBarszcz() is False:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()

    def rysowanie(self):
        return "B"

    def isResistantToBarszcz(self):
        return True

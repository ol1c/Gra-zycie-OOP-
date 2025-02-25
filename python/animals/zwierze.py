from organizm import Organizm


class Zwierze(Organizm):

    def __init__(self, species, sila, inicjatywa, x, y, world):
        Organizm.__init__(self, species, sila, inicjatywa, x, y, world)

    def akcja(self):
        newX, newY = self._world.getRandomMove(self._x,self._y)
        o = self._world.getOrganism(newX, newY)
        if o is None or o is self:
            self.setPolozenie(newX, newY)
        else:
            o.kolizja(self)

    def kolizja(self, o):
        if self._species == o.getSpecies():
            self._world.addOrganism(self.getSpecies(), self._x, self._y)
        else:
            self._fight(o)

    def _fight(self, o):
        if self._sila > o.getSila():
            o.kill()
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
        else:
            self.kill()
            self._world.addLog(o.__str__() + " zabił/a " + self.__str__())
            o.setPolozenie(self._x, self._y)


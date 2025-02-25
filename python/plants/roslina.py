import random

from organizm import Organizm


class Roslina(Organizm):

    def __init__(self, species, sila, inicjatywa, x, y, world):
        Organizm.__init__(self, species, sila, inicjatywa, x, y, world)
        self._multiply = 50

    def akcja(self):
        doesItMupltiply = random.randint(0, self._multiply)
        if doesItMupltiply == 0:
            self._world.addOrganism(self._species, self._x, self._y)

    def kolizja(self, o):
        self._fight(o)

    def _fight(self, o):
        if self._sila > o.getSila():
            o.kill()
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
        else:
            self.kill()
            self._world.addLog(o.__str__() + " je " + self.__str__())
            o.setPolozenie(self._x, self._y)


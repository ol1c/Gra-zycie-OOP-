import random

from animals.zwierze import Zwierze


class Zolw(Zwierze):

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def __init__(self, x, y, world, sila=2):
        Zwierze.__init__(self, "zolw", sila, 4, x, y, world)

    def akcja(self):
        canMove = random.randint(0,3)
        if canMove == 0:
            Zwierze.akcja(self)

    def kolizja(self, o):
        if o.getSpecies() == "zolw":
            self._world.addOrganism("owca", self._x, self._y)
        else:
            if o.getSila() < 5:
                self._world.randomMove(o, self._x, self._y)
                self._world.addLog(self.__str__() + " przesunął " + o.__str__())
            else:
                self._fight(o)

    def rysowanie(self):
        return "Z"
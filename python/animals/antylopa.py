import random

from animals.zwierze import Zwierze


class Antylopa(Zwierze):

    def __init__(self, x, y, world, sila=2):
        Zwierze.__init__(self, "antylopa", sila, 4, x, y, world)

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def akcja(self):
        newX = 0
        newY = 0
        direction = random.randint(0, 7)
        for x in range(8):
            match direction:
                case 0:
                    newX = 1
                case 1:
                    newX = -1
                case 2:
                    newY = 1
                case 3:
                    newY = -1
                case 4:
                    newX = 2
                case 5:
                    newX = -2
                case 6:
                    newY = 2
                case 7:
                    newY = -2

            if not self._world.isOnMap(self._x + newX, self._y + newY):
                newX = 0
                newY = 0
                direction = (direction + 1) % 8
            else:
                break

        o = self._world.getOrganism(self._x + newX, self._y + newY)
        if o is None or o is self:
            self.setPolozenie(self._x + newX, self._y + newY)
        else:
            o.kolizja(self)

    def kolizja(self, o):
        if o.getSpecies() == "antylopa":
            self._world.addOrganism("antylopa", self._x, self._y)
        else:
            escape = random.randint(0,1)
            if escape == 0:
                self._fight(o)

    def rysowanie(self):
        return "A"

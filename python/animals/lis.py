from animals.zwierze import Zwierze
import random


class Lis(Zwierze):

    def __init__(self, x, y, world, sila=3):
        Zwierze.__init__(self, "lis", sila, 4, x, y, world)

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def __isStronger(self, x, y):
        o = self._world.getOrganism(x, y)
        return o is None or o.getSila() <= self._sila

    def akcja(self):
        newX = 0
        newY = 0
        direction = random.randint(0, 3)
        for x in range(4):
            match direction:
                case 0:
                    newX = 1
                case 1:
                    newX = -1
                case 2:
                    newY = 1
                case 3:
                    newY = -1

            if not self._world.isOnMap(self._x + newX, self._y + newY):
                newX = 0
                newY = 0
            elif self.__isStronger(self._x + newX, self._y + newY):
                break
            direction = (direction + 1) % 4

        o = self._world.getOrganism(self._x + newX, self._y + newY)
        if o is None or o is self:
            self.setPolozenie(self._x + newX, self._y + newY)
        else:
            o.kolizja(self)

    def rysowanie(self):
        return "L"

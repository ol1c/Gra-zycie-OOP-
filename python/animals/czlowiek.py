from animals.skill import Skill
from animals.zwierze import Zwierze


class Czlowiek(Zwierze):

    def __init__(self, x, y, world, sila=5, skill=0):
        Zwierze.__init__(self, "czlowiek", sila, 4, x, y, world)
        self.__skill = Skill()
        self.__skill.setDuration(skill)


    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def toSave(self):
        return self._species + "\n" + str(self._x) + "\n" + str(self._y) + "\n" + str(self._sila) + "\n" + str(self.__skill.getDuration())

    def akcja(self):
        self.__skill.update()
        newX = 0
        newY = 0
        key = self._world.getKey()
        if key == "skill":
            if self.__skill.canUse():
                self.__skill.use()
            # else:
            #     while key == "skill":
            #         key = self._world.getKey()
        match key:
            case "down":
                newX = 1
            case "up":
                newX = -1
            case "right":
                newY = 1
            case "left":
                newY = -1
            case "skip":
                return

        if not self._world.isOnMap(self._x + newX, self._y + newY):
            newX = 0
            newY = 0

        o = self._world.getOrganism(self._x + newX, self._y + newY)
        if o is None or o is self:
            self.setPolozenie(self._x + newX, self._y + newY)
        else:
            o.kolizja(self)

    def kolizja(self, o):
        if o.getSpecies() == "czlowiek":
            self._world.addOrganism("czlowiek", self._x, self._y)
        else:
            if self.__skill.isActive():
                self._world.randomMove(o, self._x, self._y)
                self._world.addLog(self.__str__() + " przesunął " + o.__str__())
            else:
                self._fight(o)

    def rysowanie(self):
        if self.__skill.isActive():
            return "$"
        else:
            return "@"

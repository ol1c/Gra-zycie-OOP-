from abc import ABC, abstractmethod
class Organizm(ABC):

    def __init__(self, species, sila, inicjatywa, x, y, world):
        self._species = species
        self._sila = sila
        self._inicjatywa = inicjatywa
        self._x = x
        self._y = y
        self._world = world
        self._alive = True


    @abstractmethod
    def akcja(self):
        pass

    @abstractmethod
    def kolizja(self, o):
        pass

    @abstractmethod
    def rysowanie(self):
        pass

    def getSila(self):
        return self._sila

    def getInicjatywa(self):
        return self._inicjatywa

    def getPolozenie(self):
        return self._x, self._y

    def getAlive(self):
        return self._alive

    def getSpecies(self):
        return self._species

    def setPolozenie(self, x, y):
        self._x = x
        self._y = y

    def addSila(self, add):
        self._sila += add

    def kill(self):
        self._alive = False

    # def isSameClass(self, o):
    #     return isinstance(o, self.__class__)

    def isResistantToBarszcz(self):
        return False

    def toSave(self):
        return self._species + "\n" + str(self._x) + "\n" + str(self._y) + "\n" + str(self._sila)

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

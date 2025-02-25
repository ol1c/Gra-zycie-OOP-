from plants.roslina import Roslina


class WilczeJagody(Roslina):

    def __str__(self):
        return self._species + "[" + str(self._x) + "][" + str(self._y) + "]"

    def __init__(self, x, y, world, sila=99):
        Roslina.__init__(self, "wilcze jagody", sila, 0, x, y, world)

    def kolizja(self, o):
        self._world.addLog(o.__str__() + " je " + self.__str__())
        self.kill()
        o.setPolozenie(self._x, self._y)
        if o.getSila() < self._sila:
            self._world.addLog(self.__str__() + " zabił/a " + o.__str__())
            o.kill()

    def rysowanie(self):
        return "J"

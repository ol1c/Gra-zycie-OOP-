import math
import random

from animals.antylopa import Antylopa
from animals.cyberowca import Cyberowca
from animals.czlowiek import Czlowiek
from animals.lis import Lis
from animals.owca import Owca
from animals.wilk import Wilk
from animals.zolw import Zolw
from plants.barszczsosnowskiego import BarszczSosnowskiego
from plants.guarana import Guarana
from plants.mlecz import Mlecz
from plants.trawa import Trawa
from plants.wilczejagody import WilczeJagody


class Swiat:

    def __init__(self, window, height=15, width=15):
        self.__organisms = []
        self.__logs = "Nowy świat"
        self.__height = height
        self.__width = width
        self.__window = window
        self.__startSettings()

    def __startSettings(self):
        self.addOrganism("czlowiek", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("wilk", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("wilk", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("zolw", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("zolw", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("owca", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("owca", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("owca", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("lis", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("lis", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("antylopa", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("antylopa", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("antylopa", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("trawa", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("trawa", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("mlecz", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("mlecz", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("guarana", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("guarana", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("wilcze jagody", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("wilcze jagody", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("barszcz sosnowskiego", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))
        # self.addOrganism("cyberowca", random.randint(0, self.__height - 1), random.randint(0, self.__width - 1))

    def nextTurn(self):
        self.__clearLogs()
        for o in self.__organisms:
            if o.getAlive():
                o.akcja()
                self.__window.print()
        self.__clearOrganisms()

    def __clearLogs(self):
        self.__logs = ""

    def getKey(self):
        return self.__window.getKey()

    def loadSwiat(self, file):
        self.__organisms = []
        self.__height = int(file.pop(0))
        self.__width = int(file.pop(0))
        while file:
            species = file.pop(0)
            x = int(file.pop(0))
            y = int(file.pop(0))
            sila = int(file.pop(0))
            match species:
                case "czlowiek":
                    cd = int(file.pop(0))
                    self.__addToOrganisms(Czlowiek(x, y, self, sila, cd))
                case "wilk":
                    self.__addToOrganisms(Wilk(x, y, self, sila))
                case "owca":
                    self.__addToOrganisms(Owca(x, y, self, sila))
                case "lis":
                    self.__addToOrganisms(Lis(x, y, self, sila))
                case "zolw":
                    self.__addToOrganisms(Zolw(x, y, self, sila))
                case "antylopa":
                    self.__addToOrganisms(Antylopa(x, y, self, sila))
                case "cyberowca":
                    self.__addToOrganisms(Cyberowca(x, y, self, sila))
                case "trawa":
                    self.__addToOrganisms(Trawa(x, y, self, sila))
                case "mlecz":
                    self.__addToOrganisms(Mlecz(x, y, self, sila))
                case "guarana":
                    self.__addToOrganisms(Guarana(x, y, self, sila))
                case "wilcze jagody":
                    self.__addToOrganisms(WilczeJagody(x, y, self, sila))
                case "barszcz sosnowskiego":
                    self.__addToOrganisms(BarszczSosnowskiego(x, y, self, sila))

    def save(self, fileName):
        try:
            with open(fileName, 'w') as file:
                file.write(f"{self.__height}\n")
                file.write(f"{self.__width}\n")
                for organism in self.__organisms:
                    file.write(f"{organism.toZapis()}\n")
            return True
        except IOError as e:
            print(e)
            return False

    def getOrganism(self, x, y):
        for o in self.__organisms:
            ox, oy = o.getPolozenie()
            if x == ox and y == oy:
                if o.getAlive():
                    return o
        return None

    def getRandomMove(self, x, y):
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

            if not self.isOnMap(x + newX, y + newY):
                newX = 0
                newY = 0
                direction = (direction + 1) % 4
            else:
                break

        return x + newX, y + newY

    def addOrganism(self, species, x, y):
        newX = 0
        newY = 0
        if self.isOnMap(x, y) and self.getOrganism(x, y) is None:
            pass
        elif self.isOnMap(x + 1, y + 1) and self.getOrganism(x + 1, y + 1) is None:
            newX = 1
            newY = 1
        elif self.isOnMap(x + 1, y) and self.getOrganism(x + 1, y) is None:
            newX = 1
        elif self.isOnMap(x + 1, y - 1) and self.getOrganism(x + 1, y - 1) is None:
            newX = 1
            newY = -1
        elif self.isOnMap(x, y + 1) and self.getOrganism(x, y + 1) is None:
            newY = 1
        elif self.isOnMap(x, y - 1) and self.getOrganism(x, y - 1) is None:
            newY = -1
        elif self.isOnMap(x - 1, y + 1) and self.getOrganism(x - 1, y + 1) is None:
            newX = -1
            newY = 1
        elif self.isOnMap(x - 1, y) and self.getOrganism(x - 1, y) is None:
            newX = -1
        elif self.isOnMap(x - 1, y - 1) and self.getOrganism(x - 1, y - 1) is None:
            newX = -1
            newY = -1

        if self.isOnMap(x + newX, y + newY):
            match species:
                case "czlowiek":
                    self.__addToOrganisms(Czlowiek(x + newX, y + newY, self))
                case "wilk":
                    self.__addToOrganisms(Wilk(x + newX, y + newY, self))
                case "owca":
                    self.__addToOrganisms(Owca(x + newX, y + newY, self))
                case "lis":
                    self.__addToOrganisms(Lis(x + newX, y + newY, self))
                case "zolw":
                    self.__addToOrganisms(Zolw(x + newX, y + newY, self))
                case "antylopa":
                    self.__addToOrganisms(Antylopa(x + newX, y + newY, self))
                case "cyberowca":
                    self.__addToOrganisms(Cyberowca(x + newX, y + newY, self))
                case "trawa":
                    self.__addToOrganisms(Trawa(x + newX, y + newY, self))
                case "mlecz":
                    self.__addToOrganisms(Mlecz(x + newX, y + newY, self))
                case "guarana":
                    self.__addToOrganisms(Guarana(x + newX, y + newY, self))
                case "wilcze jagody":
                    self.__addToOrganisms(WilczeJagody(x + newX, y + newY, self))
                case "barszcz sosnowskiego":
                    self.__addToOrganisms(BarszczSosnowskiego(x + newX, y + newY, self))


    def isOnMap(self, x , y):
        return x >= 0 and y >= 0 and x < self.__height and y < self.__width

    def __addToOrganisms(self, add):
        self.addLog("nowy organizm: " + add.__str__())
        index = 0
        for o in self.__organisms:
            if add.getInicjatywa() > o.getInicjatywa():
                break
            index += 1
        self.__organisms.insert(index, add)

    def addLog(self, log):
        self.__logs += (log + "\n")

    def getLogs(self):
        return self.__logs

    def __clearOrganisms(self):
        self.__organisms[:] = [o for o in self.__organisms if o.getAlive() is True]

    def randomMove(self, o, x, y):
        newX = 0
        newY = 0
        direction = random.randint(0, 7)
        for x in range(8):
            match direction:
                case 0:
                    newX = 1
                    newY = 1
                case 1:
                    newX = 1
                case 2:
                    newX = 1
                    newY = -1
                case 3:
                    newX = -1
                    newY = 1
                case 4:
                    newX = -1
                case 5:
                    newX = -1
                    newY = -1
                case 6:
                    newY = 1
                case 7:
                    newY = -1

            if not self.isOnMap(x + newX, y + newY) or self.getOrganism(x + newX, y + newY) is not None:
                newX = 0
                newY = 0
                direction = (direction + 1) % 8
            else:
                break

        o.setPolozenie(x + newX, y + newY)

    def getNearestBarszcz(self, x, y):
        nearestBarsz = None
        minDistance = math.sqrt((self.__height * self.__height) + (self.__width * self.__width))
        for o in self.__organisms:
            if o.getSpecies() == "barszcz sosnowskiego" and o.getAlive():
                ox, oy = o.getPolozenie()
                distance = math.sqrt((abs(x - ox) * abs(x - ox)) + (abs(y - oy) * abs(y - oy)))
                if minDistance > distance:
                    minDistance = distance
                    nearestBarsz = o

        if nearestBarsz is None:
            return self.getRandomMove(x, y)

        bx, by = nearestBarsz.getPolozenie()
        if x > bx:
            return x - 1, y
        elif x < bx:
            return x + 1, y
        elif y > by:
            return x, y - 1
        else:
            return x, y + 1

    def getSize(self):
        return self.__height, self.__width

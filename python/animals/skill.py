class Skill:
    def __init__(self):
        self.__cooldown = 5
        self.__duration = 0

    def update(self):
        if self.__duration > 0:
            self.__duration -= 1

    def use(self):
        self.__duration = 2 * self.__cooldown

    def isActive(self):
        if self.__duration > self.__cooldown:
            return True
        return False

    def canUse(self):
        if self.__duration == 0:
            return True
        return False

    def getDuration(self):
        return self.__duration

    def setDuration(self, x):
        self.__duration = x

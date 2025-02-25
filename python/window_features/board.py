from tkinter import Frame

from window_features.field import Field


class Board(Frame):
    def __init__(self, window):
        Frame.__init__(self, window, bg="lightblue")
        self.grid(column=0, row=1, columnspan=3, rowspan=3)
        self.__height = 0
        self.__width = 0
        self.__fields = []
        self.__world = None
        self.__window = window

    def setWorld(self, w):
        self.__world = w
        height, width = self.__world.getSize()
        self.__setSize(height, width)

    def __setSize(self, h, w):
        for f in self.__fields:
            f.destroy()
        self.__height = h
        self.__width = w
        for x in range(h):
            for y in range(w):
                if self.__world is not None:
                    self.__fields.append(Field(x, y, self))
        self.print()

    def print(self):
        for f in self.__fields:
            f.print()

    def getWorld(self):
        return self.__world

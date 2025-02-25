from tkinter import *


class Field(Button):
    def __init__(self, x, y, f):
        Button.__init__(self, f, command=self.__function, text=" ", width=2)
        self.__x = x
        self.__y = y
        self.__frame = f
        self.grid(column=y, row=x)

    def __function(self):
        o = self.__frame.getWorld().getOrganism(self.__x, self.__y)
        if o is None:
            self.__addOrganism()
        else:
            self.__showOrganism(o)

    def __showOrganism(self, organism):
        win = Tk()
        win.title("Organizm")

        label = Label(win, text=organism.__str__())
        label.pack()


    def __addOrganism(self):
        def addW():
            self.__frame.getWorld().addOrganism("wilk", self.__x, self.__y)
            self.print()
            win.destroy()

        def addO():
            self.__frame.getWorld().addOrganism("owca", self.__x, self.__y)
            self.print()
            win.destroy()

        def addL():
            self.__frame.getWorld().addOrganism("lis", self.__x, self.__y)
            self.print()
            win.destroy()

        def addZ():
            self.__frame.getWorld().addOrganism("zolw", self.__x, self.__y)
            self.print()
            win.destroy()

        def addA():
            self.__frame.getWorld().addOrganism("antylopa", self.__x, self.__y)
            self.print()
            win.destroy()

        def addC():
            self.__frame.getWorld().addOrganism("cyberowca", self.__x, self.__y)
            self.print()
            win.destroy()

        def addT():
            self.__frame.getWorld().addOrganism("trawa", self.__x, self.__y)
            self.print()
            win.destroy()

        def addM():
            self.__frame.getWorld().addOrganism("mlecz", self.__x, self.__y)
            self.print()
            win.destroy()

        def addG():
            self.__frame.getWorld().addOrganism("guarana", self.__x, self.__y)
            self.print()
            win.destroy()

        def addWJ():
            self.__frame.getWorld().addOrganism("wilcze jagody", self.__x, self.__y)
            self.print()
            win.destroy()

        def addBS():
            self.__frame.getWorld().addOrganism("barszcz sosnowskiego", self.__x, self.__y)
            self.print()
            win.destroy()

        win = Tk()
        win.title("Dodaj organizm")

        w = Button(win, text="Wilk", command=addW)
        w.pack()
        o = Button(win, text="Owca", command=addO)
        o.pack()
        l = Button(win, text="Lis", command=addL)
        l.pack()
        z = Button(win, text="Zółw", command=addZ)
        z.pack()
        a = Button(win, text="Antylopa", command=addA)
        a.pack()
        c = Button(win, text="Cyberowca", command=addC)
        c.pack()
        t = Button(win, text="Trawa", command=addT)
        t.pack()
        m = Button(win, text="Mlecz", command=addM)
        m.pack()
        g = Button(win, text="Guarana", command=addG)
        g.pack()
        wj = Button(win, text="Wilcze Jagody", command=addWJ)
        wj.pack()
        b = Button(win, text="Barszcz Sosnowskiego", command=addBS)
        b.pack()

        win.mainloop()

    def print(self):
        o = self.__frame.getWorld().getOrganism(self.__x, self.__y)
        if o is not None:
            self.config(text=o.rysowanie())
        else:
            self.config(text=" ")

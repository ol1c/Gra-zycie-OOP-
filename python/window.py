from tkinter import *
from tkinter import messagebox

from swiat import Swiat
from window_features.board import Board
from window_features.console import Console


class MainWin(Tk):
    def __init__(self):
        Tk.__init__(self)
        self.__world = None
        self.title("Oliwier Komorowski 197808")
        self.geometry('800x800')
        self.bind('<KeyPress>', self.__keyPress)
        self.__key = "skip"

        self.__newBtn = Button(self, text="Nowy świat", command=self.__creatWorld)
        self.__newBtn.grid(column=0, row=0)
        self.__saveBtn = Button(self, text="Zapisz", command=self.__saveWorld)
        self.__saveBtn.grid(column=1, row=0)
        self.__nextBtn = Button(self, text="Następna tura", command=self.__nextTurn)
        self.__nextBtn.grid(column=2, row=0)
        self.__board = Board(self)
        self.__console = Console(self)

        self.__creatWorld()

    def __creatWorld(self):
        def toggle_option():
            if option.config('text')[-1] == 'Nowy świat':
                option.config(text='Wczytaj świat')
            else:
                option.config(text='Nowy świat')

        def ok_option():
            win.withdraw()
            if option.config('text')[-1] == 'Wczytaj świat':
                if self.__loadWorld():
                    win.destroy()
                else:
                    win.deiconify()
            else:
                if self.__newWorld():
                    win.destroy()
                else:
                    win.deiconify()

        #self.withdraw()

        win = Tk()
        win.title("Wybierz świat")
        win.tk.call('tk', 'scaling', 3.0)

        option = Button(win, text="Nowy świat", command=toggle_option)
        option.pack()

        ok = Button(win, text="OK", command=ok_option)
        ok.pack()

        win.mainloop()

        self.deiconify()

    def __newWorld(self):
        def ok_option():
            try:
                self.__world = Swiat(self, height.get(), width.get())
                self.__attachWorld()
                win.destroy()
                return True
            except IOError:
                messagebox.showerror("Error", "Błąd odczytu pliku.")
                return False

        win = Tk()
        win.title("Stwórz Świat")
        win.tk.call('tk', 'scaling', 3.0)

        labelH = Label(win, text="Wysokość:")
        labelH.pack()
        height = Scale(win, from_=10, to=30, orient=HORIZONTAL)
        height.pack()

        labelW = Label(win, text="Szerokość:")
        labelW.pack()

        width = Scale(win, from_=10, to=30, orient=HORIZONTAL)
        width.pack()

        ok = Button(win, text="OK", command=ok_option)
        ok.pack()
        win.mainloop()

    def __loadWorld(self):
        def load():
            try:
                fileName = text.get()
                with open(fileName + ".txt", "r") as file:
                    allLines = file.readlines()
                print(fileName)
                self.__world = Swiat(self)
                self.__world.loadSwiat(allLines)
                self.__attachWorld()
                win.destroy()
                return True
            except IOError:
                messagebox.showerror("Error", "Błąd odczytu pliku.")
                return False

        win = Tk()
        win.title("Wczytaj Świat")
        win.tk.call('tk', 'scaling', 3.0)

        label = Label(win, text="Podaj nazwę pliku:")
        label.pack()

        text = Entry(win)
        text.pack()

        ok = Button(win, text="OK", command=load)
        ok.pack()
        win.mainloop()

    def __saveWorld(self):
        def load():
            try:
                fileName = text.get()
                self.__world.save(fileName + ".txt")
                win.destroy()
                return True
            except IOError:
                messagebox.showerror("Error", "Błąd odczytu pliku.")
                return False

        win = Tk()
        win.title("Wczytaj Świat")
        win.tk.call('tk', 'scaling', 3.0)

        label = Label(win, text="Podaj nazwę pliku:")
        label.pack()

        text = Entry(win)
        text.pack()

        ok = Button(win, text="OK", command=load)
        ok.pack()
        win.mainloop()

    def __keyPress(self, event):
        print(event.char)
        match event.keysym:
            case "Up":
                self.__key = "up"
            case "Down":
                self.__key = "down"
            case "Left":
                self.__key = "left"
            case "Right":
                self.__key = "right"
            case "u":
                self.__key = "skill"
            case "space":
                self.__key = "skip"
            case _:
                self.__key = None

    def __attachWorld(self):
        self.__board.destroy()
        self.__board = Board(self)
        self.__board.setWorld(self.__world)

    def __nextTurn(self):
        if self.__world is not None:
            self.__world.nextTurn()
            self.__key = "skip"

    def print(self):
        if self.__world is not None:
            self.__board.print()
            self.__console.setText(self.__world.getLogs())

    def getKey(self):
        if self.__key is not None:
            return self.__key


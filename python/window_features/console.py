from tkinter import Label


class Console(Label):
    def __init__(self, win):
        Label.__init__(self, win, bg="lightgrey", text="")
        self.grid(column=3, row=1)


    def setText(self, string):
        self.config(text=string)

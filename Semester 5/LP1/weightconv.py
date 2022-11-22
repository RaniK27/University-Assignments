from tkinter import *

window = Tk()

window.title("Weight Converter")


def kg_conv():
    gram = float(user_value.get()) * 1000
    pounds = float(user_value.get()) * 2.20462
    ounce = float(user_value.get()) * 35.274

    t1.insert(END, gram)
    t2.insert(END, pounds)
    t3.insert(END, ounce)


user_value = StringVar()
e1 = Entry(window, textvariable=user_value)

l1 = Label(window, text="Weight(in kg): ")
l2 = Label(window, text = "Gram")
l3 = Label(window, text = "Pounds")
l4 = Label(window, text = "Ounce")

t1 = Text(window, height=1, width = 10)
t2 = Text(window, height=1, width = 10)
t3 = Text(window, height=1, width = 10)

b1 = Button(window, text="Convert", command=kg_conv)

l1.grid(row=1, column=0)
e1.grid(row=1, column=1)
l2.grid(row=2, column=0)
l3.grid(row=2, column=1)
l4.grid(row=2, column=2)
t1.grid(row=3, column=0)
t2.grid(row=3, column=1)
t3.grid(row=3, column=2)
b1.grid(row=1, column=2)

window.mainloop()
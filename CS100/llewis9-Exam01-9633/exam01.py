__author__ = 'Donald J. Hake II'

import turtle
from math import *

def drawSquareFromCenter(turtle,x):
    turtle.penup()
    turtle.forward(-x/2)
    turtle.right(90)
    turtle.forward(x/2)
    turtle.left(90)
    turtle.pendown( )
    turtle.forward(x)
    turtle.left(90)
    turtle.forward(x)
    turtle.left(90)
    turtle.forward(x)
    turtle.left(90)
    turtle.forward(x)
    turtle.left(90)
    turtle.penup( )
    turtle.forward(x/2)
    turtle.left(90)
    turtle.forward(x/2)
    turtle.right(90)


def main():
    # create turtle
    bob = turtle.Turtle()

    # get user input
    size = int(input("Enter size of square: "))

    # TASK 0: create and initialize all variables
    # TODO 0: create and initialize variables using the variable names supplied
    # TODO 0: replace 0's with actual calculations
    # CALC 1: calculate diagonals of diamonds from size of squares
    diagDiamond1 = (size * .35) * sqrt(2)
    diagDiamond2 = (size * .35) * sqrt(2)
    diagDiamond3 = (size * .35) * sqrt(2)
    diagDiamond4 = (size * .35) * sqrt(2)

    # CALC 2: calculate sizes of diamonds from their diagonals
    sizeDiamond1 = size
    sizeDiamond2 = size * .75
    sizeDiamond3 = size * .5
    sizeDiamond4 = size * .25

    # CALC 3: calculate diagonal of squares
    diagSquare = 0

    # TASK 1: draw the 4 diamonds first, from smallest to largest
    # TODO 1: position cursor to draw diamonds around origin
    bob.lt(45)
    # TODO 2: draw 1st diamond, centered around origin
    drawSquareFromCenter(bob, sizeDiamond1)

    # TODO 3: draw 2nd diamond, centered around origin
    drawSquareFromCenter(bob, sizeDiamond2)

    # TODO 4: draw 3rd diamond, centered around origin
    drawSquareFromCenter(bob, sizeDiamond3)

    # TODO 5: draw 4th diamond, centered around origin
    drawSquareFromCenter(bob, sizeDiamond4)


    # TASK 2: draw squares, clockwise, starting with top square, moving directly between square centers
    # TODO 6: position cursor to center of top square
    bob.lt(45)
    bob.fd(diagDiamond1 / sqrt(2))
    bob.rt(90)
    # TODO 7: draw top square
    drawSquareFromCenter(bob, diagDiamond1 / sqrt(2))


    # TODO 8: move directly to center of right square (center to center)
    bob.rt(45)
    bob.fd(diagDiamond2)
    bob.rt(45)


    # TODO 9: draw right square
    drawSquareFromCenter(bob, diagDiamond2 / sqrt(2))

    # TODO 10: move directly to center of bottom square (center to center)
    bob.rt(45)
    bob.fd(diagDiamond3)
    bob.rt(45)


    # TODO 11: draw bottom square
    drawSquareFromCenter(bob, diagDiamond3 / sqrt(2))

    # TODO 12: move directly to center of left square (center to center)
    bob.rt(45)
    bob.fd(diagDiamond4)
    bob.rt(45)


    # TODO 13: draw left square
    drawSquareFromCenter(bob, diagDiamond4 / sqrt(2))

    # TASK 3: leave cursor at top of diagram
    # TODO 14: move cursor to top of diagram, facing right
    bob.rt(45)
    bob.fd(diagDiamond4)
    bob.lt(45)
    bob.fd(diagDiamond4 / sqrt(2))
    bob.rt(90)


    # wait for user input before exiting
    input("Press any key to exit")

main()

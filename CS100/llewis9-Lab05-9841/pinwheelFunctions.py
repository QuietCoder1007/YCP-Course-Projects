# Import turtle graphics library
import turtle

# Import math functions
from math import *


# Function to draw a square about the current position
def drawSquareFromCenter(turtle, x):
    turtle.penup()
    turtle.forward(-x / 2)
    turtle.right(90)
    turtle.forward(x / 2)
    turtle.left(90)
    turtle.pendown()
    turtle.forward(x)
    turtle.left(90)
    turtle.forward(x)
    turtle.left(90)
    turtle.forward(x)
    turtle.left(90)
    turtle.forward(x)
    turtle.left(90)
    turtle.penup()
    turtle.forward(x / 2)
    turtle.left(90)
    turtle.forward(x / 2)
    turtle.right(90)


# TODO: Right turn movement function
def moveToCenterRightTurn(turtle, distX, distY):
    turtle.penup()
    turtle.fd(distX)
    turtle.lt(90)
    turtle.fd(distY)
    turtle.lt(90)


# TODO: Diagonal movement function
def moveToCenterDiagonal(turtle, distX, distY):
    turtle.penup()
    turtle.rt(degrees(atan2(distY, distX)))
    turtle.fd(hypot(distX, distY))
    turtle.lt(degrees(atan2(distY, distX)))


# TODO: Complete program to call functions

#       to draw pinwheel

def main():
    # Create turtle
    bob = turtle.Turtle()

    # Get user input
    size1 = 250
    size2 = int(input('Enter size for first square: '))
    size3 = int(input('Enter size for first square: '))
    size4 = int(input('Enter size for first square: '))

    # half side lengths of squares
    halfsize1 = size1 / 2
    halfsize2 = size2 / 2
    halfsize3 = size3 / 2
    halfsize4 = size4 / 2

    # Movement from Center of square2 to center of square3
    dist1 = halfsize2 + halfsize3
    dist2 = halfsize2 - halfsize3

    # Movement from Center of square3 to center of square4
    dist11 = halfsize3 + halfsize4
    dist22 = halfsize3 - halfsize4

    # Draw first square
    moveToCenterRightTurn(bob, halfsize1, halfsize1)
    drawSquareFromCenter(bob, size1)
    moveToCenterRightTurn(bob, halfsize1, halfsize1)

    # Orient self for square2
    bob.rt(90)

    # Draw second square
    moveToCenterRightTurn(bob, halfsize2, halfsize2)
    drawSquareFromCenter(bob, size2)

    # Draw third square
    bob.lt(90)
    moveToCenterDiagonal(bob, dist1, dist2)
    drawSquareFromCenter(bob, size3)

    # Orient self for square4
    bob.rt(90)

    # Draw fourth square
    moveToCenterDiagonal(bob, dist11, dist22)
    drawSquareFromCenter(bob, size4)

    # Return to origin
    bob.rt(90)
    moveToCenterDiagonal(bob, halfsize4, halfsize4)
    # Press any key to exit
    input()


main()

import math
import turtle


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


def main():
   # Create turtle
   bob = turtle.Turtle()

   # Get user input
   size1 = int(input("Enter size fore top square: "))

   # Square lengths in relation to size1 square
   size2 = size1 * 2
   size3 = size1 * 3
   size4 = size1 * 4

   # Half-lengths of each square
   halfSize1 = size1 / 2
   halfSize2 = size2 / 2
   halfSize3 = size3 / 2
   halfSize4 = size4 / 2

   height = size2 + size3 + size4
   hypotenuse = ((size4)**2) + ((size4)**2)

   # Draw graphics

   # Move towards center of size4 square
   bob.penup()
   bob.left(45)
   bob.forward(math.sqrt(hypotenuse))
   bob.left(45)

   # Move upward towards center of size1 square
   bob.forward(height + halfSize1)

   # Draw size1 square from center
   drawSquareFromCenter(bob, size1)

   # Move total of length two squares divided by two
   bob.forward(-halfSize1 + -halfSize2)

   # Draw size2 square from center
   drawSquareFromCenter(bob, size2)

   # Move total length of two sqaures divided by two
   bob.forward(-halfSize2 + -halfSize3)

   # Draw size3 square from center
   drawSquareFromCenter(bob, size3)

   # Move total length of two squares divided by two towards center of next square
   bob.forward(-halfSize3 + -halfSize4)

   # Draw size4 square from center
   drawSquareFromCenter(bob, size4)

   # Move to point of origin from size4 square
   bob.right(45)
   bob.forward(-hypotenuse)
   bob.right(45)

   # Press any key to exit

   input()


main()
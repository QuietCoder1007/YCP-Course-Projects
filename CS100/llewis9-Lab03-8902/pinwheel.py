import turtle

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

 # Create turtle
 drawSquareFromCenter(turtle, 40)
 turtle.forward(100)
 turtle.left(90)
 turtle.forward(60)
 turtle.right(90)

 drawSquareFromCenter(turtle, 160)
 turtle.right(90)
 turtle.forward(140)
 turtle.left(90)
 turtle.forward(-20)

 drawSquareFromCenter(turtle, 120)
 turtle.right(180)
 turtle.forward(100)
 turtle.left(90)
 turtle.forward(-20)

 drawSquareFromCenter(turtle, 80)
 turtle.right(180)
 turtle.forward(60)
 turtle.left(90)
 turtle.forward(20)

 bob = turtle.Turtle()
 # Draw graphics
 drawSquareFromCenter(bob,0)
 # Press any key to exit
 input()

main()


# Newton

## Introduction

You should write ONLY ONE FUNCTION to solve this question.

It's not easy to find exact solution of equations containing x^n(where n is not less than 5). Generally, we can plot the graph of the function and study the intersection between the curve and x-axis. But how do we approximate the zero point? Here we introduce a method called Newton's method of approximation.

Given a curve y=x^5-4x^4+x^3-2x^2+x+1:

We first take an arbitrary point on the curve. Draw L1 which is the curve's tangent line at the point. Take the intersection between L1 and x axis. Assume the intersection is (x',0). Then take the point (x',y') on the curve and draw a tangent line L2. We can see the intersection between L2 and x axis is much closer to the zero point. This process will loop until the difference of two adjacent solutions is less than a given number, which is the requested accuracy. Your first task is to approximate a zero point of the functiongiven. 

Then you need to display the corresponding English words of the given function, for example, if I input y= 4*x^4+2*x^3-x^2+8(you can input in the data type you want), the output should be ‘y equals to four times x to the 4th power plus two times x cubed minus x squared plus eight.’

What’s more, your function should keep asking for user’s input and display the answer, unless user input “I LOVE LAB” to exit the program. An example run of the program is shown below:

```
Input function:x.^3+x+1
Input accuracy:0.0001
a approximate zero point of y equals to x cubed plus x plus one is -0.6823.
Input function:x.^3-x+1
Input accuracy:0.0001
a approximate zero point of y equals to x cubed minus x plus one is -1.3.
Input function:x.^2-x-1
Input accuracy:0.00001
a approximate zero point of y equals to x squared minus x minus one is -1.61803.
```

You only need to consider polynomial function with the max power less than 10, and the parameters are natural number which are less than 100. We assume the correct variable should be ‘x’ and the given function is named ‘y’.

Hint: These functions, ‘syms’, ‘subs’ may be useful, and you need to find a function on the Internet to get the derivative of a function.

## Work cited
Question 1, Lab2, VG101, Jigang Wu, FA2015 & FA2016
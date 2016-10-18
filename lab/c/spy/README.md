# Spy

## Introduction

I think you will have a lot of fun with this lab and you will learn how to use a library.

Since you have just started with C and you have already practiced the things you have learned in your homework, you may feel boring if I ask you to write a program to judge whether a number is a palindrome. So I'm going to give you an exciting problem and help you know how to use *.lib files.

Implementation of function can be put in a *.lib file. Before you start, I want to remind you of the usage of lib file. First create an empty project, add a source file named lab3.cpp (must be cpp here because the lib file is written in C++. This doesn't mean you need to use C++).

Copy spy.h and spy.lib into the same folder where your newly-add source file is located.

Then open lab3.cpp, add the following codes:

```
#include "spy.h"
#pragma comment(lib, "spy.lib")
int main()
{
    int a = encode(514370900000,1234);
    printf("%d\n",a);
    system("pause"); // This is command is used to prevent the command window from disappearing, making it convenient for you to see the output
}
```
## Work cited
Question 1, Lab3, VG101, Jigang Wu, FA2015
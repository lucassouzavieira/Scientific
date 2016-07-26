#!/usr/bin/env python
# !-*- coding: utf-8 -*-


def Collatz(x):
    print(x)
    if(x == 1):
        return
    elif (x % 2 == 0):
        Collatz(x/2)
    else:
        Collatz(3*x + 1)

Collatz(7)


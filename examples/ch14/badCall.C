/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
void triple(const int&) {}
/*

void triple(int& i) {
    i *= 3;
}
*/

void f() {
int a = 1;
int b = 2;
triple(a + b); // WRONG: conversion to non-const int& requires temporary

}

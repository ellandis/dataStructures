#include<stdio.h>
#include<stdlib.h>
#include "dstack.h"

int main(int argc, char *argv[])
{
    DStack *Brick = Create_DStack();
    //Display_Stack(Brick);
    Push(Brick,100);
    Push(Brick,99);
    Push(Brick,98);
    Push(Brick,97);
    //Display_Stack(Brick);
    //Pop(Brick);
    //Pop(Brick);
    //Pop(Brick);
    //Pop(Brick);
    //Pop(Brick);
    Display_Stack(Brick);
    Display_Stack(Brick);
    return 0;
}

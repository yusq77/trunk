/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-10-31 14:59:48
 *================================================*/

#include <stdio.h> 
#include <setjmp.h>

jmp_buf buf;


/* 
 * int setjmp(jmp_buf envbuf);
 * setjmp函数用缓冲区envbuf保存系统堆栈的内容，以便后续的longjmp函数使用。setjmp函数初次启用时返回0值
 *
 * void longjmp(jmp_buf envbuf, int val);
 * longjmp函数中的参数envbuf是由setjmp函数所保存的堆栈环境，参数val设置setjmp函数的返回值。
 * longjmp函数本身是没有返回值的，它执行后跳转到保存envbuf参数的setjmp函数调用，并由setjmp函数调用返回，
 * 此时setjmp函数的返回值就是val。
 *
 *
 * 先调用setjmp，用变量envbuf记录当前的位置，然后调用longjmp，返回envbuf所记录的位置，并使setjmp的返回值为val。
 * 当时用longjmp时，envbuf的内容被销毁了。其实这里的“位置”一词真正的含义是栈定指针。
 *
 * setjmp/longjmp的最大用处是错误恢复，类似try ...catch...
 * 他们的功能比goto强多了，goto只能在函数体内跳来跳去，而setjmp/longjmp可以在到过的所有位置间。
 *
 * */
banana(){ 
    char *p = 0x80;
    printf("*p = ");

    printf("in banana() \n"); 
    longjmp(buf,1);

    printf("you'll never see this,because i longjmp'd");

}

main() 
{ 
    if(setjmp(buf)) 
        printf("back in main\n"); 
    else{ 
        printf("first time through\n"); 
        banana(); 
    }
#if 0
    first time through
    in banana() 
    back in main
#endif

}

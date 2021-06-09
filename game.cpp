#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <process.h>
#include <time.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <bios.h>

///////////////////////////////MAIN////////////////////////////////

void main()
{
    clrscr();
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
    errorcode = graphresult();
    if (errorcode != grOk)
    {
        cout << "Graphics error:\n"
             << grapherrormsg(errorcode);
        cout << "Press any key to halt";
        getch();
        exit(1);
    }
    void draw();
    draw();
    getch();
    cleardevice();
    closegraph();
}

int q, x, color, y;

//////////////////////////LOAD SCREEN////////////////////////////

void load()
{
    int maxcolor;
    char msg[80];
    maxcolor = getmaxcolor();
    //settextjustify(CENTER_TEXT, CENTER_TEXT);
    x = getmaxx() / 2;
    y = getmaxy() / 2;
    int a = x, q = x - 200;
    int b = y;
    char S[] = "TIC TAC TOE ";
    for (color = 1; color <= 12; color++)
    { //cleardevice();
        {
            setcolor(color);
            settextstyle(0, 0, 5);
            if (color == 1)
                outtextxy(q, y, "T");
            if (color == 2)
                outtextxy(q, y, "I");
            if (color == 3)
                outtextxy(q, y, "C");
            if (color == 4)
                outtextxy(q, y, " ");
            if (color == 5)
                outtextxy(q, y, "T");
            if (color == 6)
                outtextxy(q, y, "A");
            if (color == 7)
                outtextxy(q, y, "C");
            if (color == 8)
                outtextxy(q, y, " ");
            if (color == 9)
                outtextxy(q, y, "T");
            if (color == 10)
                outtextxy(q, y, "O");
            if (color == 11)
                outtextxy(q, y, "E");
            if (color == 12)
                outtextxy(q, y, " ");
        }
        settextstyle(0, 0, 1);
        outtextxy(x - 28, y + 107, "LOADING");
        int z = b;
        for (int i = 1; i <= 10; i++)
        {
            rectangle(a - 50, z + 100, a + i * 10 - 50, b + 120);
            setcolor(color);
            delay(70);
        }
        q += 40;
    }
    void home();
    home();
}
////////////////////////////////HOME//////////////////////////////////

void home()
{
    void play();
    void instructions();
    void credits();

    x = getmaxx() / 2;
    y = getmaxy() / 2;
    int a = x, q = x - 200;
    int b = y;
    cleardevice();
    for (int i = 0; i < 9; i++)
    { //cleardevice();
        q = x - 200;
        settextstyle(0, 0, 5);
        color = 1;
        setcolor(color);
        outtextxy(q, y, "T");
        q += 40;
        color = 2;
        setcolor(color);
        outtextxy(q, y, "I");
        q += 40;
        color = 3;
        setcolor(color);
        outtextxy(q, y, "C");
        q += 40;
        color = 4;
        setcolor(color);
        outtextxy(q, y, " ");
        q += 40;
        color = 5;
        setcolor(color);
        outtextxy(q, y, "T");
        q += 40;
        color = 6;
        setcolor(color);
        outtextxy(q, y, "A");
        q += 40;
        color = 7;
        setcolor(color);
        outtextxy(q, y, "C");
        q += 40;
        color = 8;
        setcolor(color);
        outtextxy(q, y, " ");
        q += 40;
        color = 9;
        setcolor(color);
        outtextxy(q, y, "T");
        q += 40;
        color = 10;
        setcolor(color);
        outtextxy(q, y, "O");
        q += 40;
        color = 11;
        setcolor(color);
        outtextxy(q, y, "E");
        q += 40;
        color = 12;
        setcolor(color);
        outtextxy(q, y, " ");
        q += 40;
        y -= 20;
        delay(100);
        if (i == 8)
            break;
        cleardevice();
    }
    settextstyle(10, 0, 3);
    outtextxy(x - 180, y + 140, "1. PLAY");
    outtextxy(x - 178, y + 142, "1. PLAY");
    outtextxy(x - 180, y + 200, "2. INSTRUCTIONS");
    outtextxy(x - 178, y + 202, "2. INSTRUCTIONS");
    outtextxy(x - 180, y + 260, "3. CREDITS");
    outtextxy(x - 178, y + 262, "3. CREDITS");
    setcolor(WHITE);
    int u = getmaxx(), v = getmaxy();
    settextstyle(1, 0, 1);
    outtextxy(u - 200, v - 50, "PRESS ESC TO EXIT");
    int key;
    while (bioskey(1) == 0)
        ;
    key = bioskey(0);
    if (key == 283)
        exit(1);
    else if (key == 561)
        play();
    else if (key == 818)
        instructions();
    else if (key == 1075)
        credits();
    else
        home();
}
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int checkwin();
void board();

int player = 1;

//////////////////////////////PLAY/////////////////////////////////

void play()
{
    int i, choice, o = 0;
    char mark;
    cleardevice();
    do
    {
        cleardevice();
        if (o == 0)
            setcolor(BLUE);
        o++;
        board();
        if (player % 2 == 1)
        {
            setcolor(RED);
            outtextxy(0, 0, "Player 1 Enter any number");
        }
        else if (player % 2 == 0)
        {
            setcolor(BLUE);
            outtextxy(0, 0, "Player 2 Enter any number");
        }
        else
        {
            setcolor(YELLOW);
        }
        //cin >> choice;
        player = (player % 2) ? 1 : 2;
        gotoxy(0, 0);
        //cout<<"Player "<<player<<",enter a number:  ";
        while (bioskey(1) == 0)
            ;
        choice = bioskey(0);
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 561 && square[1] == '1')
            square[1] = mark;
        else if (choice == 818 && square[2] == '2')
            square[2] = mark;
        else if (choice == 1075 && square[3] == '3')
            square[3] = mark;
        else if (choice == 1332 && square[4] == '4')
            square[4] = mark;
        else if (choice == 1589 && square[5] == '5')
            square[5] = mark;
        else if (choice == 1846 && square[6] == '6')
            square[6] = mark;
        else if (choice == 2103 && square[7] == '7')
            square[7] = mark;
        else if (choice == 2360 && square[8] == '8')
            square[8] = mark;
        else if (choice == 2617 && square[9] == '9')
            square[9] = mark;
        else
        {
            cout << "Invalid move ";
            player--;
            getch();
        }
        i = checkwin();
        player++;

    } while (i == -1);
    board();

    void win1();
    void win2();
    void draw();

    if (i == 1)
    {
        --player;
        if (player == 1)
        {
            /*	setcolor(RED);
		outtextxy(0,0,"Player 1 Wins!!!");  */
            win1();
        }
        else if (player == 2)
        {
            /*setcolor(BLUE);
		outtextxy(0,0,"Player 2 Wins!!!"); */
            win2();
        }
    }
    else
    {
        draw();
    }
    //cout<<endl<<"Press ESC to exit";
    square[0] = '0';
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
    int key;
    while (bioskey(1) == 0)
        ;
    key = bioskey(0);
    if (key == 283)
        home();
    getch();
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
///////////////////////////////BOARD//////////////////////////////

void board()
{

    cleardevice();
    line(270, 100, 270, 325);
    line(345, 100, 345, 325);
    line(205, 175, 420, 175);
    line(205, 250, 420, 250);
    settextstyle(0, 0, 3);
    int l = 225 - 75, m = 130, n = 1, p = 130;
    for (int o = 1; o < 10; o++)
    {
        l = 225 - 75;
        if (square[o] == 'X')
            outtextxy(l += (75 * n), p, "X");
        else if (square[o] == 'O')
            outtextxy(l += (75 * n), p, "O");
        n++;
        if (o == 3 || o == 6)
        {
            n = 1;
            l = 225 - 75;
            p = m + (75 * (o / 3));
        }
    }
    l = 225;
    m = 130;
}
/////////////////////////INSTRUCTIONS/////////////////////////

void instructions()
{
    void home();
    cleardevice();
    setcolor(LIGHTGREEN);
    settextstyle(3, 0, 5);
    outtextxy((getmaxx() / 2) - 132, 30, "HOW TO PLAY");
    line((getmaxx() / 2) - 135, 75, (getmaxx() / 2) + 147, 75);
    int u = getmaxx(), v = getmaxy();
    settextstyle(2, 0, 6);
    setcolor(YELLOW);
    outtextxy(70, 100, "Welcome to the Game. The instructions are as simple as 2+2.");
    outtextxy(70, 130, "1. The Tic Tac Toe grid follows the pattern given below.");
    setcolor(WHITE);
    line(getmaxx() / 2 - 100, 250, getmaxx() / 2 - 100, 420); //v1
    line(getmaxx() / 2 + 20, 250, getmaxx() / 2 + 20, 420);   //v2
    line(getmaxx() / 2 - 170, 300, getmaxx() / 2 + 90, 300);  //h1
    line(getmaxx() / 2 - 170, 370, getmaxx() / 2 + 90, 370);  //h2

    settextstyle(3, 0, 4);
    outtextxy(getmaxx() / 2 - 140, 250, "1");
    outtextxy(getmaxx() / 2 - 45, 250, "2");
    outtextxy(getmaxx() / 2 + 50, 250, "3");
    outtextxy(getmaxx() / 2 - 140, 310, "4");
    outtextxy(getmaxx() / 2 - 45, 310, "5");
    outtextxy(getmaxx() / 2 + 50, 310, "6");
    outtextxy(getmaxx() / 2 - 140, 375, "7");
    outtextxy(getmaxx() / 2 - 45, 375, "8");
    outtextxy(getmaxx() / 2 + 50, 375, "9");

    settextstyle(2, 0, 6);
    setcolor(YELLOW);
    outtextxy(70, 150, "2. To mark your square, press the no.  ");
    outtextxy(70, 170, "   corresponding to its square and hit Enter key.");
    outtextxy(70, 190, "3. Now the most important step....ENJOY THE GAME.");
    setcolor(WHITE);
    settextstyle(1, 0, 1);
    outtextxy(u - 210, v - 50, "PRESS ESC TO GO BACK");
    int key;
    while (bioskey(1) == 0)
        ;
    {
        key = bioskey(0);
        if (key == 283)
            home();
        else
            instructions();
    }
}

////////////////////////////CREDITS//////////////////////////////

void credits()
{
    x = getmaxx() / 2;
    y = getmaxy() / 2;
    cleardevice();
    settextstyle(10, 0, 3);
    for (int i = 0; i < 60; i++)
    {
        cleardevice();
        setcolor(CYAN);
        outtextxy(x - 70, y + 130, "CREDITS");
        line(x - 67, y + 183, x + 73, y + 183);
        setcolor(LIGHTGREEN);
        outtextxy(x - 120, y + 200, "Parth N. Shah");
        outtextxy(x - 170, y + 240, "Prakhar T. Tibrewal");
        outtextxy(x - 120, y + 280, "Ankit K. Das");
        setcolor(RED);
        outtextxy(x - 150, y + 360, "Special thanks to");
        setcolor(LIGHTGREEN);
        outtextxy(x - 120, y + 400, "Smriti Ma'am");
        outtextxy(x - 140, y + 440, "And our Friends");
        y -= 10;
        delay(120);
    }

    home();
}

void win1()
{
    setcolor(WHITE);
    for (int i = 1; i <= 10; i++)
    {
        pieslice(getmaxx() / 2, getmaxy() / 2, 0, 36 * i, 190);
        delay(50);
    }

    for (int j = 1; j <= 25; j++)
    {
        circle(getmaxx() / 2, getmaxy() / 2, 190 + j * 10);
        delay(50);
    }
    for (int k = 1; k <= 1000; k++)
    {
        setcolor(k);
        settextstyle(7, 0, 4);
        outtextxy(getmaxx() / 2 - 150, getmaxy() / 2 - 25, "PLAYER 1 WINS!!!");
    }
    cleardevice();
    setcolor(WHITE);
    settextstyle(9, 0, 5);
    for (int t = 1; t <= 30; t++)
    {
        outtextxy(getmaxx() - 50 * t, getmaxy() / 2 - 75, "Press ESC to exit");
        delay(200);
        cleardevice();
    }
    square[0] = '0';
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
    int key;
    while (bioskey(1) == 0)
        ;
    key = bioskey(0);
    if (key == 283)
        home();
    getch();
}

void win2()
{
    setcolor(WHITE);
    for (int i = 1; i <= 10; i++)
    {
        pieslice(getmaxx() / 2, getmaxy() / 2, 0, 36 * i, 190);
        delay(50);
    }

    for (int j = 1; j <= 25; j++)
    {
        circle(getmaxx() / 2, getmaxy() / 2, 190 + j * 10);
        delay(50);
    }
    for (int k = 1; k <= 1000; k++)
    {
        setcolor(k);
        settextstyle(7, 0, 4);
        outtextxy(getmaxx() / 2 - 150, getmaxy() / 2 - 25, "PLAYER 2 WINS!!!");
    }
    cleardevice();
    setcolor(WHITE);
    settextstyle(9, 0, 5);
    for (int t = 1; t <= 30; t++)
    {
        outtextxy(getmaxx() - 50 * t, getmaxy() / 2 - 75, "Press ESC to exit");
        delay(200);
        cleardevice();
    }
    square[0] = '0';
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
    int key;
    while (bioskey(1) == 0)
        ;
    key = bioskey(0);
    if (key == 283)

        getch();
    home();
}

void draw()
{
    cleardevice();
    setcolor(WHITE);
    /* for(int i=1; i<=10; i++)
 {
  pieslice(getmaxx()/2,getmaxy()/2,0,36*i,190);
  delay(50);
 } */

    for (int j = 1; j <= 25; j++)
    {
        circle(getmaxx() / 2, getmaxy() / 2, 190 + j * 10);
        delay(50);
    }
    setcolor(RED);
    settextstyle(7, 0, 4);
    outtextxy(getmaxx() / 2 - 70, getmaxy() / 2 - 25, "DRAW!!!");
    setcolor(WHITE);
    settextstyle(1, 0, 1);
    outtextxy(getmaxx() - 200, getmaxy() - 50, "PRESS ESC TO EXIT");

    square[0] = '0';
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
    int key;
    while (bioskey(1) == 0)
        ;
    key = bioskey(0);
    if (key == 283)
        home();
}

//THE END

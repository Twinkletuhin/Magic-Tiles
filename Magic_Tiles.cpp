#include <bits/stdc++.h>
#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#define screenWidth 650
#define screenHight 750
int pageTrack = 0;
void position1();
void position2();
void position3();
void position4();
void position5();
void TakeScore();
int level = 1;
int life = 5;
int dy;
int tap = 0;
bool takeScore = true; // for resume till at leat one tiles is clicked
// clock_t start, end;
int score = 0;
char sscore[80] = {0};
char bc[7][60] = {"img\\bc_2.bmp", "img\\name.bmp", "img\\start.bmp", "img\\option.bmp", "img\\music.bmp", "img\\menubc.bmp", "img\\about.bmp"};
char Main[10][60] = {"img\\ai-01.bmp", "img\\ai-02.bmp", "img\\ai-03.bmp", "img\\ai-04.bmp", "img\\ai-05.bmp", "img\\ai-06.bmp", "img\\ai-07.bmp", "img\\ai-08.bmp", "img\\ai-09.bmp", "img\\ai-10.bmp"};
bool musicOn = true;
bool musicTrack = false;
bool click = false;
char quit[80] = {0};
char slife[15] = {0};
char slevel[15] = {0};
char PlayerName[80] = "{TUHIN}";
char Tplayername[80];
void leaderBoard();
void ChangeMainBc();
int easy = 1, medium = 0, hard = 0;
int t = 0;
typedef struct
{
    char name[100];
    int score;
} player;
player p[6];
typedef struct
{ // to control the color of the tiles
    int r;
    int g;
    int b;
} paint;
paint color[5];
typedef struct
{ // to handle the coordinate of tiles
    double x;
    double y;

} axis;
axis tiles[5];
void coordinate()
{ // srand(time(0));
    tiles[0].x = 2.5;
    tiles[0].y = rand() % 750;
    tiles[1].x = 135;
    tiles[1].y = rand() % 750;
    tiles[2].x = 267.5;
    tiles[2].y = rand() % 750;
    tiles[3].x = 400;
    tiles[3].y = rand() % 750;
    tiles[4].x = 532.5;
    tiles[4].y = rand() % 750;
    // printf("1-%d 2-%d 3-%d 4-%d 5-%d\n", tiles[0].y, tiles[1].y, tiles[2].y, tiles[3].y, tiles[4].y);
}
typedef struct
{ // to control the buttons
    int x;
    int y;
} Button;
Button name[5];
typedef struct
{
    // to end game
    int x;
} CLICK;
CLICK Life[5];
void homePage()
{
    PlaySound(0, 0, 0);
    iShowBMP(0, 0, bc[5]);
    iShowBMP(name[0].x, name[0].y, bc[1]); // name
    iShowBMP(name[1].x, name[1].y, bc[2]); // start
    iShowBMP(name[2].x, name[2].y, bc[3]); // option
    iShowBMP(name[3].x, name[3].y, bc[4]); // music
    iShowBMP(name[4].x, name[4].y, bc[6]); // about
}
typedef struct
{
    int x;
    int y;
} area;
area Tiles[5];
void TakeName()
{
    iFilledRectangle(200, 400, 200, 50);
    iShowBMP(0, 0, "img\\nameIn.bmp");
    iShowBMP(2, 701, "img\\back.bmp");
    iSetColor(0, 0, 0);
    iText(240, 320, Tplayername, GLUT_BITMAP_TIMES_ROMAN_24);
}
void mainPage()
{
    if (musicOn)
    {
        PlaySound(TEXT("music\\beleiver.wav"), NULL, SND_LOOP | SND_ASYNC);
        musicOn = false;
    }

    iShowBMP(0, 0, Main[t]);
    iSetColor(255, 228, 255);
    iLine(126.25, 0, 126.25, 750);
    iLine(258.75, 0, 258.75, 750);
    iLine(391.25, 0, 391.25, 750);
    iLine(523.75, 0, 523.75, 750);
    iSetColor(color[0].r, color[0].g, color[0].b);
    iFilledRectangle(tiles[0].x, tiles[0].y, Tiles[0].x, Tiles[0].y);
    iSetColor(color[1].r, color[1].g, color[1].b);
    iFilledRectangle(tiles[1].x, tiles[1].y, Tiles[1].x, Tiles[1].y);
    iSetColor(color[2].r, color[2].g, color[2].b);
    iFilledRectangle(tiles[2].x, tiles[2].y, Tiles[2].x, Tiles[2].y);
    iSetColor(color[3].r, color[3].g, color[3].b);
    iFilledRectangle(tiles[3].x, tiles[3].y, Tiles[3].x, Tiles[3].y);
    iSetColor(color[4].r, color[4].g, color[4].b);
    iFilledRectangle(tiles[4].x, tiles[4].y, Tiles[4].x, Tiles[4].y);
    // end = clock();
    // double timeDiff = (start - end) / CLOCKS_PER_SEC;
    //  sprintf(quit, "%.2lf", timeDiff);
    iSetColor(233, 234, 236);
    iFilledRectangle(175, 703, 279, 38);
    iSetColor(255, 0, 0);
    sprintf(slevel, "LEVEL : %d", level);
    iText(180, 715, slevel, GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255, 0, 0);
    // iText(310, 710, "LIFE LEFT: ", GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(slife, "LIFE LEFT: %d", life);
    iText(310, 715, slife, GLUT_BITMAP_TIMES_ROMAN_24);
    //   iText(570,700,"\033[1;31mScore:\033[0m",GLUT_BITMAP_HELVETICA_18);
    // iShowBMP2(484, 705, "img\\score.bmp", 0);
    iSetColor(233, 234, 236);
    iFilledRectangle(490, 703, 155, 38);
    iSetColor(0, 0, 0);
    iText(505, 715, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(sscore, "%d", score);
    p[5].score = score;
    iText(590, 715, sscore, GLUT_BITMAP_TIMES_ROMAN_24);
    iShowBMP(0, 705, "img\\back.bmp");
    int a;
    if (easy == 1)
    {
        a = 1;
    }
    if (medium == 1)
    {
        a = 2;
    }
    if (hard == 1)
    {
        a = 3;
    }
    if (score == 120)
    {
        level = 2;
    }
    if (score == 180)
    {
        level = 3;
    }
    if (level == 1)
    {
        if (easy == 1)
            dy = 10;
        else
            dy = 8 * a;
    }
    else if (level == 2)
    {
        dy = 10 * a;
    }
    else if (level == 3)
    {
        dy = 15 * a;
    }

    // if (timeDiff < 1)
    //     exit(0);
}
void showLeaderBoard()
{
    iShowBMP(0, 0, "img\\leaderBc.bmp");
    leaderBoard();
    iShowBMP(150, 160, "img\\leader.bmp");
    iShowBMP(240, 48, "img\\back.bmp");
    int dx = 250, dy = 490, wid = 33, len = 200;
    char show[5][80];
    sprintf(show[0], "%s : %d", p[0].name, p[0].score);
    sprintf(show[1], "%s : %d", p[1].name, p[1].score);
    sprintf(show[2], "%s : %d", p[2].name, p[2].score);
    sprintf(show[3], "%s : %d", p[3].name, p[3].score);
    sprintf(show[4], "%s : %d", p[4].name, p[4].score);
    iSetColor(255, 255, 255);
    iFilledRectangle(dx, dy, len, wid);
    iFilledRectangle(dx, dy - 60, len, wid);
    iFilledRectangle(dx, dy - 120, len, wid);
    iFilledRectangle(dx, dy - 180, len, wid);
    iFilledRectangle(dx, dy - 240, len, wid);
    iSetColor(0, 0, 0);
    iText(dx + 10, dy + 10, show[0], GLUT_BITMAP_TIMES_ROMAN_24);
    iText(dx + 10, dy + 10 - 60, show[1], GLUT_BITMAP_TIMES_ROMAN_24);
    iText(dx + 10, dy + 10 - 120, show[2], GLUT_BITMAP_TIMES_ROMAN_24);
    iText(dx + 10, dy + 10 - 180, show[3], GLUT_BITMAP_TIMES_ROMAN_24);
    iText(dx + 10, dy + 10 - 240, show[4], GLUT_BITMAP_TIMES_ROMAN_24);
}
void optionPage()
{
    iShowBMP(0, 0, "img\\optionBc.bmp");
    iShowBMP(279 - 37, 110, "img\\back.bmp");
    // iSetColor(255, 255, 255);
    // iText(300, 300, "Leaderboard", GLUT_BITMAP_TIMES_ROMAN_24);
}
void aboutPage()
{
    iShowBMP(0, 0, "img\\aboutBC.bmp");
    iShowBMP(2, 705, "img\\back.bmp");
}

void musicPage()
{
    iShowBMP(0, 0, "img\\musicBc.bmp");
    if (musicOn == false)
    {
        iShowBMP(252, 337, "img\\musicOff.bmp");
    }
    else
    {
        iShowBMP(252, 337, "img\\musicOn.bmp");
    }
    iShowBMP(246, 69, "img\\back.bmp");
}
void endPage()
{
    PlaySound(0, 0, 0);
    iShowBMP(0, 0, "img\\over.bmp");
    iSetColor(255, 255, 255);
    iFilledRectangle(238, 332, 182, 32);
    iSetColor(0, 0, 0);
    iText(270, 338, PlayerName, GLUT_BITMAP_TIMES_ROMAN_24);
    // printf("p[5].name in end page call:%s", p[5].name);
    iText(291, 240, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255, 255, 255);
    iFilledRectangle(230, 209, 170, 16);
    iSetColor(0, 0, 0);
    iText(305, 208, sscore, GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255, 255, 255);
    iFilledRectangle(260, 156, 129, 24);
    iSetColor(0, 0, 0);
    iText(265, 160, "Game Over", GLUT_BITMAP_TIMES_ROMAN_24);
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    if (takeScore)
        leaderBoard();
}
void iDraw()
{
    // place your drawing codes here

    if (pageTrack != 1)
    {
        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        iPauseTimer(3);
        iPauseTimer(4);
        iPauseTimer(5);
    }
    if (life == 0)
    {
        pageTrack = 6;
    }
    iClear();
    switch (pageTrack)
    {
    case 0:
    {
        homePage();
        tap = 0;
        break;
    }
    case 1:
    {
        mainPage();
        // musicOn=true;
        if (tap == 1)
        {
            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);
            iResumeTimer(5);
        }

        break;
    }
    case 54:
    {
        tap = 0;
        TakeName();
        break;
    }
    case 2:
        optionPage();
        break;
    case 4:
        aboutPage();
        break;
    case 5:
        musicPage();
        break;
    case 6:
        endPage();
        break;
    case 76:
        showLeaderBoard();
    }
}
void leaderBoard()
{
    takeScore = false;
    char mark[10];
    FILE *fp;
    if ((fp = fopen("leaderboard.txt", "r")) == NULL)
    {
        printf("Error opening leaderboard file\n");
        return;
    }
    int i = 0;
    while (i < 5)
    {
        fscanf(fp, "%s %d", p[i].name, &p[i].score);
        i++;
    }
    fclose(fp);
    int temp;
    char tempName[80];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 5; j > i; j--)
        {
            if (p[j].score > p[i].score)
            {
                temp = p[j].score;
                p[j].score = p[i].score;
                p[i].score = temp;
                strcpy(tempName, p[j].name);
                strcpy(p[j].name, p[i].name);
                strcpy(p[i].name, tempName);
            }
        }
    }
    fp = fopen("leaderboard.txt", "w");
    for (int i = 0; i < 5; i++)
    {
        fprintf(fp, "%s %d\n", p[i].name, p[i].score);
    }
    fclose(fp);
}
// void TakeScore(){
//     takeScore=false;
//     FILE *fp;
//     if ((fp = fopen("leaderboard.txt", "a"))==NULL){
//         printf("Error opening leaderboard file\n");
//         return;
//     }

//     if((fprintf(fp, "%s %d\n", p[5].name, score))<0){
//         printf("Error writing to leaderboard file\n");
//         return;
//     }
//     fclose(fp);

// }

// void musicControl()
// {
//     if (pageTrack == 1)
//         PlaySound(TEXT("music\\beleiver.wav"), NULL, SND_ASYNC);
//     if (pageTrack == 0)
//         PlaySound(0, 0, 0);
// }
/*
    function iMouseMove() is called when the user presses and drags the mouse.
    (mx, my) is the position where the mouse pointer is.
    */
void iMouseMove(int mx, int my)
{
    // printf("x = %d, y= %d\n",mx,my);
    // place your codes here
}

/*
    function iMouse() is called when the user presses/releases the mouse.
    (mx, my) is the position where the mouse pointer is.

    */
void gan()
{
    click = true;
    if (click)
    {
        PlaySound(TEXT("music\\click.wav"), NULL, NULL);
        click = false;
    }
}
void iMouse(int button, int state, int mx, int my)
{
    // if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    // {
    //     printf("x = %d, y= %d\n", mx, my);
    // }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (pageTrack == 1)
        {
            if (mx >= tiles[0].x && mx <= (tiles[1].x - 17.5) && my >= tiles[0].y && my <= (tiles[0].y + 250))
            {
                Life[0].x = 1;
                Tiles[0] = {0, 0};
                tap++;
                // color[0] = {0, 0, 255};
                score += 2;
            }
            if (mx >= tiles[1].x && mx <= (tiles[2].x - 17.5) && my >= tiles[1].y && my <= (tiles[1].y + 250))
            {
                Life[1].x = 1;
                Tiles[1] = {0, 0};
                tap++;
                // color[1] = {0, 0, 255};
                score += 2;
            }
            if (mx >= tiles[2].x && mx <= (tiles[3].x - 17.5) && my >= tiles[2].y && my <= (tiles[2].y + 250))
            {
                Life[2].x = 1;
                Tiles[2] = {0, 0};
                tap++;
                //  color[2] = {0, 0, 255};
                score += 2;
            }
            if (mx >= tiles[3].x && mx <= (tiles[4].x - 17.5) && my >= tiles[3].y && my <= (tiles[3].y + 250))
            {
                Life[3].x = 1;
                Tiles[3] = {0, 0};
                tap++;
                // color[3] = {0, 0, 255};
                score += 2;
            }
            if (mx >= tiles[4].x && mx <= (632.5) && my >= tiles[4].y && my <= (tiles[4].y + 250))
            {
                Life[4].x = 1;
                Tiles[4] = {0, 0};
                tap++;
                // color[4] = {0, 0, 255};
                score += 2;
            }
            if ((mx >= 0 && mx <= 160) && my >= 705 && my < 750)
            {
                pageTrack = 0;
                if (musicTrack)
                {
                    musicOn = true;
                }

                gan();
            }
        }

        // name[0] = {140, 530}; // for name
        // name[1] = {220, 470}; // for start
        // name[2] = {195, 395}; // for options
        // name[3] = {217, 250}; // for music
        // name[4] = {220, 320}; // for about
        if (pageTrack == 4)
        {
            if (mx >= 2 && mx <= 162 && my >= 701 && my <= 750)
            {
                pageTrack = 0;
                gan();
            }
        }
        if (!pageTrack)
        {
            // for start button
            if (mx >= name[1].x && mx <= (name[1].x + 168) && my >= name[1].y && my <= (name[1].y + 48))
            {
                pageTrack = 54;
                //  start = clock() + 61000;
                //  printf("start x=%d,y=%d\n", mx, my);
                gan();
            }

            // for option
            if ((mx >= name[2].x && mx <= name[2].x + 216) && (my >= name[2].y && my <= name[2].y + 47))
            {
                gan();
                // printf("option x=%d,y=%d\n", mx, my);
                pageTrack = 2;
            }

            // for music
            if ((mx >= name[3].x && mx <= name[3].x + 171) && (my >= name[3].y && my <= name[3].y + 48))
            {
                gan();
                //  printf("music x=%d,y=%d\n", mx, my);

                pageTrack = 5;
            }

            // for about
            if ((mx >= name[4].x && mx <= name[4].x + 165) && (my >= name[4].y && my <= name[4].y + 46))
            {
                gan();
                // printf("about x=%d,y=%d\n", mx, my);
                pageTrack = 4;
            }
        }
        if (pageTrack == 2)
        { // option page
            if ((mx >= 207 && mx <= 296) && (my >= 660 && my <= 683))
            {
                pageTrack = 76;
                gan();
            }
            if (mx >= 49 && mx <= 85 && my >= 318 && my <= 342)
            {
                easy = 1;
                // printf("%d\n", easy);
                gan();
            }
            if (mx >= 346 && mx <= 407 && my >= 318 && my <= 338)
            {
                medium = 1;
                //  printf("medium:%d\n", medium);
                gan();
            }
            if (mx >= 552 && mx <= 596 && my >= 319 && my <= 342)
            {
                hard = 1;
                // printf("hard:%d\n", hard);
                gan();
            }
            if (mx >= 279 - 37 && mx <= 439 - 37 && my >= 110 && my <= 160)
            {
                pageTrack = 0;
                gan();
            }
        }
        if (pageTrack == 6)
        { // end page
            if (mx >= 309 && mx <= 344 && my >= 77 && my <= 99)
            {
                // pageTrack=0;
                gan();
                exit(0);
            }
        }
        if (pageTrack == 76)
        {
            // leader board page
            if (mx >= 465 && mx <= 491 && my >= 569 && my < 586)
            {
                pageTrack = 0;
                gan();
            }
            if (mx >= 243 && mx <= 410 && my >= 171 && my <= 203)
            {
                pageTrack = 54;
                gan();
            }
            if (mx >= 240 && mx <= 390 && my >= 54 && my <= 104)
            {
                pageTrack = 2;
                gan();
            }
        }
        if (pageTrack == 5)
        {
            if (mx >= 252 && mx <= 352 && my >= 337 && my <= 457)
            {
                gan();
                musicOn = !musicOn;
                if (musicOn)
                {
                    musicTrack = true;
                }
                else
                {
                    musicTrack = false;
                }
            }
            if (mx >= 246 && mx <= 406 && my >= 69 && my <= 119)
            {
                pageTrack = 0;
                gan();
            }
        }
        if (pageTrack == 54)
        {
            if (mx >= 2 && mx <= 162 && my >= 701 && my <= 750)
            {
                gan();
                pageTrack = 0;
            }
        }
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    }
}

/*
    function iKeyboard() is called whenever the user hits a key in keyboard.
    key- holds the ASCII value of the key pressed.
    */
int len = 0;
void iKeyboard(unsigned char key)

{
    int i;

    if (pageTrack == 54)
    {
        if (key != '\b' && key != '\r')
        {
            Tplayername[len] = key;
            len++;
        }
        if (key == '\b' && len >= 0)
        {
            Tplayername[len - 1] = '\0';
            len--;
        }
        if (key == '\r')
        {
            strcpy(p[5].name, Tplayername);
            strcpy(PlayerName, Tplayername);
            // printf("player name in return time:%s",p[5].name);
            for (int i = 0; i < len; i++)
            {
                Tplayername[i] = 0;
            }
            len = 0;
            pageTrack = 1;
            //  printf("%s ",PlayerName);
            //  printf("Hi");
        }
    }

    // if (key == 'p' && pageTrack == 1)
    // {
    //     if (musicOn)
    //     {
    //         musicOn = false;
    //         PlaySound(0, 0, 0);
    //     }
    //     else
    //     {
    //         musicOn = true;
    //         PlaySound(TEXT("music\\beleiver.wav"), NULL, SND_ASYNC);
    //     }
    // }
    // if(pageTrack==1){
    //     if(key=='b'){
    //         t++;
    //         if(t==7)
    //             t=0;
    //     }
    // }
    if (key == 'x')
    {
        exit(0);
    }
    // place your codes for other keys here
}

/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
    */
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    // place your codes for other keys here
}
void ChangeMainBc()
{
    t++;
    if (t == 8)
        t = 0;
}
void colorChange()
{
    srand(time(0));
    // color[0] = {220, 20, 60};
    // color[1] = {255, 215, 0};
    // color[2] = {60, 179, 133};
    // color[3] = {75, 0, 130};
    // color[4] = {47, 79, 79};
    color[0] = {rand() % 255, rand() % 255, rand() % 255};
    color[1] = {rand() % 255, rand() % 255, rand() % 255};
    color[2] = {rand() % 255, rand() % 255, rand() % 255};
    color[3] = {rand() % 255, rand() % 255, rand() % 255};
    color[4] = {rand() % 255, rand() % 255, rand() % 255};
}

void position1()
{
    //  printf("I was called\n");
    srand(time(0));
    tiles[0].y -= dy;
    if (tiles[0].y <= -250)
    {
        if (Life[0].x == 0)
        {
            if (pageTrack == 1)
                life--;
        }
        Life[0].x = 0;
        tiles[0].y = 700;
        // color[0]={rand()%255,rand()%255,rand()%255};
        // color[0] = {220, 20, 60};
        Tiles[0] = {115, 250};
    }
}
void position2()
{

    srand(time(0));
    tiles[1].y -= dy;
    if (tiles[1].y <= -250)
    {
        if (Life[1].x == 0)
        {
            if (pageTrack == 1)
                life--;
        }
        Life[1].x = 0;
        tiles[1].y = 700;
        // color[1]={rand()%255,rand()%255,rand()%255};
        // color[1] = {255, 215, 0};
        Tiles[1] = {115, 250};
    }
}

void position3()
{

    srand(time(0));
    tiles[2].y -= dy;
    if (tiles[2].y <= -250)
    {
        if (Life[2].x == 0)
        {
            if (pageTrack == 1)
                life--;
        }
        Life[2].x = 0;
        tiles[2].y = 700;
        // color[2]={rand()%255,rand()%255,rand()%255};
        // color[2] = {60, 179, 133};
        Tiles[2] = {115, 250};
    }
}
void position4()
{

    srand(time(0));
    tiles[3].y -= dy;
    if (tiles[3].y <= -250)
    {
        if (Life[3].x == 0)
        {
            if (pageTrack == 1)
                life--;
        }
        Life[3].x = 0;
        tiles[3].y = 700;
        // color[3]={rand()%255,rand()%255,rand()%255};
        //  color[3] = {75, 0, 130};
        Tiles[3] = {115, 250};
    }
}
void position5()
{

    srand(time(NULL));
    tiles[4].y -= dy;
    if (tiles[4].y <= -250)
    {
        if (Life[4].x == 0)
        {
            if (pageTrack == 1)
                life--;
        }
        Life[4].x = 0;
        tiles[4].y = 700;
        // color[4]={rand()%255,rand()%255,rand()%255};
        // color[4] = {47, 79, 79};
        Tiles[4] = {115, 250};
    }
}
int main()
{
    name[0] = {140, 530}; // for name
    name[1] = {220, 470}; // for start
    name[2] = {195, 395}; // for options
    name[3] = {217, 250}; // for music
    name[4] = {220, 320}; // for about
    // for the length and bredth of the tiles
    Tiles[0] = {115, 250};
    Tiles[1] = {115, 250};
    Tiles[2] = {115, 250};
    Tiles[3] = {115, 250};
    Tiles[4] = {115, 250};
    coordinate();
    iSetTimer(5, position1);
    iSetTimer(10 - 10, position2);
    iSetTimer(13 - 10, position3);
    iSetTimer(15 - 10, position4);
    iSetTimer(17 - 10, position5);
    iSetTimer(3000, ChangeMainBc);
    iSetTimer(1, colorChange);
    // if (pageTrack == 1)
    //     PlaySound(TEXT("music\\beleiver.wav"), NULL, SND_ASYNC);
    // if (pageTrack == 0)
    //     PlaySound(0, 0, 0);

    iInitialize(screenWidth, screenHight, "MAGIC TILES");

    return 0;
}

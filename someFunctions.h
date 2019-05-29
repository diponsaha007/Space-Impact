//Full power 10 dhore kora.. jodi baras ba komas taile dx * full power e 10 ta chng kore dis...
void lifebar(int power)
{
    iSetColor(255,255,255);
    iFilledRectangle(350,550,70,18);
    float dx= power*70.0/100;
    iSetColor(255,0,0);
    iFilledRectangle(350,550,dx*10,18);
    iSetColor(255,255,255);
}
void draw_enemy(float xx,float yy)
{
    iSetColor(255,218,185);
    iFilledEllipse(xx+20,yy+15,12,15);
    iSetColor(210,105,30);
    iFilledEllipse(xx+20,yy+5,20,5);
    iSetColor(0,255,0);
    iFilledCircle(xx+20,yy+5,2);
    iFilledCircle(xx+30,yy+5,2);
    iFilledCircle(xx+10,yy+5,2);
    iSetColor(0,0,128);
    iFilledCircle(xx+20,yy+20,5);
    iFilledRectangle(xx+15,yy+10,10,6);
    iSetColor(255,0,0);
    iLine(xx+15,yy+13,xx+10,yy+20);
    iSetColor(255,255,255);
}
void draw_enemy1(float xx,float yy)
{
    iSetColor(250,38,38);
    iFilledEllipse(xx+20,yy+15,12,15);
    iSetColor(92,49,49);
    iFilledEllipse(xx+20,yy+5,20,5);
    iSetColor(0,255,0);
    iFilledCircle(xx+20,yy+5,2);
    iFilledCircle(xx+30,yy+5,2);
    iFilledCircle(xx+10,yy+5,2);
    iSetColor(92,49,49);
    iFilledCircle(xx+20,yy+20,5);
    iFilledRectangle(xx+15,yy+10,10,6);
    iSetColor(255,0,0);
    iLine(xx+15,yy+13,xx+10,yy+20);
    iSetColor(255,255,255);
}
void draw_enemy2(float xx,float yy)
{
    iSetColor(255,255,255);
    iFilledEllipse(xx+20,yy+15,12,15);
    iSetColor(255,255,255);
    iFilledEllipse(xx+20,yy+5,20,5);
    iSetColor(246,38,38);
    iLine(xx+20,yy+10,xx+20,yy+27);
    iLine(xx+21,yy+10,xx+21,yy+27);
    iLine(xx+10,yy+17,xx+31,yy+17);
    iLine(xx+10,yy+16,xx+31,yy+16);
    iSetColor(255,255,255);
}
void main_image()
{
    iShowBMP(0,0,"main_image.bmp");
}
void draw_menu()
{
    //iSetColor(107,257,215);
    main_image();
    //iFilledRectangle(0,0,800,580);
    iSetColor(255,255,255);
    //iFilledRectangle(300,400,200,40);
    //iFilledRectangle(300,340,200,40);
    //iFilledRectangle(300,280,200,40);
    //iFilledRectangle(300,220,200,40);
    //iFilledRectangle(300,160,200,40);
    //iFilledRectangle(300,100,200,40);
    //iFilledRectangle(300,40,200,40);
    //iSetColor(0,0,0);
    iText(362,410,"START",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(331,350,"LOAD GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(362,290,"LEVEL",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(320,230,"HIGH SCORES",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(347,170,"CREDITS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(340,110,"SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(369,50,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

}
void draw_space(int x, int y)
{
    iSetColor(0,0,255);
    iFilledRectangle(x,y,15,10);
    iFilledRectangle(x,y+20,15,10);
    iFilledRectangle(x+15,y,7,30);
    iSetColor(127,0,255);
    iFilledRectangle(x+22,y+5,15,18);
    iSetColor(0,204,0);
    iFilledRectangle(x+37,y+11,13,6.35);
    iFilledRectangle(x,y,22,5);
    iFilledRectangle(x,y+25,22,5);
    iFilledRectangle(x+22,y+5,15,4);
    iFilledRectangle(x+22,y+19,15,4);
    iSetColor(255,255,255);
}
void credits()
{
    iShowBMP(0,0,"Credits.bmp-Backup.bmp");
    iSetColor(255,255,255);
    iFilledRectangle(300,40,200,40);
    iSetColor(0,0,0);
    iText(362,50,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
}
void pause_menu()
{
    //iSetColor(107,257,215);
    //iFilledRectangle(0,0,800,580);
    main_image();
    iSetColor(255,255,255);
    //iFilledRectangle(300,400,200,40);
    //iFilledRectangle(300,340,200,40);
    //iFilledRectangle(300,280,200,40);
    //iFilledRectangle(300,220,200,40);
    //iFilledRectangle(300,160,200,40);
    //iSetColor(0,0,0);
    iText(352,410,"RESUME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(320,350,"HIGH SCORES",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(331,290," MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(369,230,"SAVE",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(369,170,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
}

void seven_segment(int A,int B,int C,int D,int E,int F,int G,int ini_x,int ini_y)
{
    if(A)
        iFilledRectangle(ini_x,ini_y,35,5);
    if(B)
        iFilledRectangle(ini_x,ini_y-40,35,5);
    if(C)
        iFilledRectangle(ini_x,ini_y-80,35,5);
    if(D)
        iFilledRectangle(ini_x-5,ini_y-170+130,5,45);
    if(E)
        iFilledRectangle(ini_x-5,ini_y-170+90,5,45);
    if(F)
        iFilledRectangle(ini_x+35,ini_y-170+130,5,45);
    if(G)
        iFilledRectangle(ini_x+35,ini_y-170+90,5,45);
}
void print_name()//prints space impact
{
    iSetColor(255,255,255);
    seven_segment(1,1,1,1,0,0,1,76-20,563);
    seven_segment(1,1,0,1,1,1,0,76+60-20,563);
    seven_segment(1,1,0,1,1,1,1,76+120-20,563);
    seven_segment(1,0,1,1,1,0,0,76+180-20,563);
    seven_segment(1,1,1,1,1,0,0,76+240-20,563);

    seven_segment(0,0,0,0,0,1,1,400-20,563);
    seven_segment(1,0,0,1,1,1,1,460-20,563);
    seven_segment(1,0,0,0,0,1,1,460+40-20,563);
    seven_segment(1,1,0,1,1,1,0,500+60-20,563);
    seven_segment(1,1,0,1,1,1,1,500+120-20,563);
    seven_segment(1,0,1,1,1,0,0,500+180-20,563);
    seven_segment(1,0,0,0,0,1,1,500+230-20,563);
    seven_segment(1,0,0,0,0,0,0,500+230+40-20,563);
}
int check(int x,int y,int m,int o)
{
    int n=m+40;
    int p=o+30;
    if(x>=m&&x<=n&&y>=o&&y<=p)
    {
        return 1;
    }
    return 0;
}

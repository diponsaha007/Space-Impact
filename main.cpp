#include "iGraphics.h"
#include "someFunctions.h"
struct highscore
{
    char name[30];
    int score;
} scores[1000];
//#########################################################################//
//.......variables for pausing timer.........//
int t,tc,md=1,flag[1000],flag_for_bullet[1000],mode_for_enter_name=0,namelength=0,highscoretoresume=0,tm,tmp,tmc,type[1000],bullets=100;
//.................Finished..................//
//.......variables for moving spaceship......//
int x=50,y=30;
//.................Finished..................//
FILE *fp;
float x_bonus_power,y_bonus_power,r_bonus_power=10;
//.......variables for moving enemy..........//
float intervalfornewenemy=3000,intervalforenemymove=50,intervalforenemybulletcreate=2100;
float x_enemy[1000],y_enemy[1000];
int i=0,p=0,score=0,enemy_bullet_number=0;
char str[6],Powerstring[3],sss[100]="Enter your name",bulletstring[4];
//.................Finished..................//
float bullet_x_point[1000],bullet_y_point[1000];
float x_enemy_bullet[1000],y_enemy_bullet[1000];
int Power=10,flag_for_enemy_bullet[1000];
float circle_for_level_x=335,circle_for_level_y=300;
int mode=0,sound=1,sound_manual=1,circle_for_settings_x=268, circle_for_settings_y=348 ;
int beep_mode=1,circle_for_beep_x=268,circle_for_beep_y=210;
//#########################################################################//
void playsound()
{
    if(sound_manual==1)
    {
        PlaySound("videoplaybackTrim.wav", NULL,SND_ASYNC);
        sound=1;
    }
}
void playbeep()
{
    if(beep_mode==1)
        PlaySound("Space Impact - Nokia 1100 GamesTrim.wav", NULL,SND_ASYNC);
}
void stopsound()
{
    PlaySound(NULL, NULL,SND_ASYNC);
    sound=0;
}
void settings()
{
    main_image();
    iText(362,50,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(279,377,"SOUND (TURN ON / OFF)",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(279,238,"BEEP (TURN ON / OFF)",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(279,340,"1. ON",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(279,307,"2. OFF",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(279,200,"1. ON",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(279,162,"2. OFF",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,0,0);
    iFilledCircle(circle_for_settings_x,circle_for_settings_y,5);
    iFilledCircle(circle_for_beep_x,circle_for_beep_y,5);
}
void savegame()
{
    FILE *fp2;
    fp2=fopen("not array.txt","w");
    fprintf(fp2,"%f %f %f %d %d %d\n",intervalfornewenemy,intervalforenemymove,intervalforenemybulletcreate,i,p,enemy_bullet_number);
    fclose(fp2);
    fp2=fopen("last score.txt","w");
    fprintf(fp2,"%d",score);
    fclose(fp2);
    fp2=fopen("last power.txt","w");
    fprintf(fp2,"%d",Power);
    fclose(fp2);
    fp2=fopen("x_enemy.txt","w");
    for(int w=0; w<i; w++)
    {
        fprintf(fp2,"%f ",x_enemy[w]);
    }
    fclose(fp2);
    fp2=fopen("bullets.txt","w");
    fprintf(fp2,"%d",bullets);
    fclose(fp2);
    fp2=fopen("y_enemy.txt","w");
    for(int w=0; w<i; w++)
    {
        fprintf(fp2,"%f ",y_enemy[w]);
    }
    fclose(fp2);
    fp2=fopen("bullet_x_point.txt","w");
    for(int w=0; w<p; w++)
    {
        fprintf(fp2,"%f ",bullet_x_point[w]);
    }
    fclose(fp2);
    fp2=fopen("bullet_y_point.txt","w");
    for(int w=0; w<p; w++)
    {
        fprintf(fp2,"%f ",bullet_y_point[w]);
    }
    fclose(fp2);
    fp2=fopen("x_enemy_bullet.txt","w");
    for(int w=0; w<enemy_bullet_number; w++)
    {
        fprintf(fp2,"%f ",x_enemy_bullet[w]);
    }
    fclose(fp2);
    fp2=fopen("y_enemy_bullet.txt","w");
    for(int w=0; w<enemy_bullet_number; w++)
    {
        fprintf(fp2,"%f ",y_enemy_bullet[w]);
    }
    fclose(fp2);
    fp2=fopen("flag_for_enemy_bullet.txt","w");
    for(int w=0; w<enemy_bullet_number; w++)
    {
        fprintf(fp2,"%d ",flag_for_enemy_bullet[w]);
    }
    fclose(fp2);
    fp2=fopen("flag.txt","w");
    for(int w=0; w<1000; w++)
    {
        fprintf(fp2,"%d ",flag[w]);
    }
    fclose(fp2);
    fp2=fopen("flag_for_bullet.txt","w");
    for(int w=0; w<1000; w++)
    {
        fprintf(fp2,"%d ",flag_for_bullet[w]);
    }
    fclose(fp2);
    fp2=fopen("types.txt","w");
    for(int w=0;w<i;w++)
    {
        fprintf(fp2,"%d ",type[w]);
    }
    fclose(fp2);

}

void loadgame()
{
    mode_for_enter_name=0;
    FILE *fp2;
    fp2=fopen("not array","r");
    fscanf(fp2,"%f %f %f %d %d %d",&intervalfornewenemy,&intervalforenemymove,&intervalforenemybulletcreate,&i,&p,&enemy_bullet_number);
    fclose(fp2);
    fp2=fopen("last score.txt","r");
    fscanf(fp2,"%d",&score);
    fclose(fp2);
    fp2=fopen("bullets.txt","r");
    fscanf(fp2,"%d",&bullets);
    fclose(fp2);
    fp2=fopen("last power.txt","r");
    fscanf(fp2,"%d",&Power);
    fclose(fp2);

    fp2=fopen("x_enemy.txt","r");
    for(int w=0; w<i; w++)
    {
        fscanf(fp2,"%f ",&x_enemy[w]);
    }
    fclose(fp2);
    fp2=fopen("y_enemy.txt","r");
    for(int w=0; w<i; w++)
    {
        fscanf(fp2,"%f ",&y_enemy[w]);
    }
    fclose(fp2);
    fp2=fopen("bullet_x_point.txt","r");
    for(int w=0; w<p; w++)
    {
        fscanf(fp2,"%f ",&bullet_x_point[w]);
    }
    fclose(fp2);
    fp2=fopen("bullet_y_point.txt","r");
    for(int w=0; w<p; w++)
    {
        fscanf(fp2,"%f ",&bullet_y_point[w]);
    }
    fclose(fp2);
    fp2=fopen("x_enemy_bullet.txt","r");
    for(int w=0; w<enemy_bullet_number; w++)
    {
        fscanf(fp2,"%f ",&x_enemy_bullet[w]);
    }
    fclose(fp2);
    fp2=fopen("y_enemy_bullet.txt","r");
    for(int w=0; w<enemy_bullet_number; w++)
    {
        fscanf(fp2,"%f ",&y_enemy_bullet[w]);
    }
    fclose(fp2);
    fp2=fopen("flag_for_enemy_bullet.txt","r");
    for(int w=0; w<enemy_bullet_number; w++)
    {
        fscanf(fp2,"%d ",&flag_for_enemy_bullet[w]);
    }
    fclose(fp2);
    fp2=fopen("flag.txt","r");
    for(int w=0; w<1000; w++)
    {
        fscanf(fp2,"%d ",&flag[w]);
    }
    fclose(fp2);
    fp2=fopen("flag_for_bullet.txt","r");
    for(int w=0; w<1000; w++)
    {
        fscanf(fp2,"%d ",&flag_for_bullet[w]);
    }
    fclose(fp2);
    fp2=fopen("types.txt","r");
    for(int w=0;w<1000;w++)
    {
        fscanf(fp2,"%d ",&type[w]);
    }
    fclose(fp2);

}

void highscore()
{
    int pnumber=0;//playernumber
    FILE *fp1;
    fp1=fopen("scores.txt","r");
    while(fscanf(fp1,"%s %d",&scores[pnumber].name,&scores[pnumber].score)!=EOF)
    {
        pnumber++;
    }
    fscanf(fp1,"%s %d",&scores[pnumber].name,&scores[pnumber].score);
    pnumber++;
    fclose(fp1);
    for(int q=0; q<pnumber-1; q++)
    {
        for(int w=0; w<pnumber; w++)
        {
            if(scores[w].score<scores[q].score)
            {
                char temp[100];
                int tempnumber;
                tempnumber=scores[w].score;
                scores[w].score=scores[q].score;
                scores[q].score=tempnumber;
                strcpy(temp,scores[w].name);
                strcpy(scores[w].name,scores[q].name);
                strcpy(scores[q].name,temp);
            }
        }
    }
    //iSetColor(107,257,215);
    //iFilledRectangle(0,0,800,580);
    main_image();
    iSetColor(255,255,255);
    //iFilledRectangle(150,150,500,380);
    //iSetColor(0,0,0);
    int yyy=480;
    for(int q=0; q<5; q++)
    {
        char temp[1000];
        itoa(q+1,temp,10);
        strcat(temp,".");
        strcat(temp,scores[q].name);
        iText(175,yyy,temp,GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(scores[q].score,temp,10);
        iText(350,yyy,temp,GLUT_BITMAP_TIMES_ROMAN_24);
        yyy-=75;

    }
    iSetColor(255,255,255);
    //iFilledRectangle(300,40,200,40);
    //iSetColor(0,0,0);
    iText(362,50,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
}


void iDraw()
{
    iClear();
    if(mode==0)
    {
        draw_menu();
        print_name();
    }

    if(mode==1)
    {
        iShowBMP(0,0,"galaxy-wallpaper-31.bmp");
        iSetColor(255,255,255);
        iLine(0,510,800,510);
        draw_space(x,y);
        itoa(score,str,10);
        iText(5,550,"Score : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(80,550,str,GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(bullets,bulletstring,10);
        iText(5,490,"Bullets:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(89,490,bulletstring,GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(Power,Powerstring,10);
        iText(190,550,"Power:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(280,550,Powerstring,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(600,550,"Press P to pause",GLUT_BITMAP_TIMES_ROMAN_24);
        lifebar(Power);
        for(int j=0; j<i; j++)
        {
            if(flag[j]==1)
            {
                if(type[j]==0)
                    draw_enemy(x_enemy[j],y_enemy[j]);
                if(type[j]==1)
                    draw_enemy1(x_enemy[j],y_enemy[j]);
                if(type[j]==2)
                    draw_enemy2(x_enemy[j],y_enemy[j]);
            }
        }
        for(int j=0;j<i;j++)
        {
            if(type[j]!=2&&flag[j]==1)
            {
                int c=check(x,y,x_enemy[j],y_enemy[j])||check(x+50,y,x_enemy[j],y_enemy[j])||check(x,y+30,x_enemy[j],y_enemy[j])||check(x+50,y+30,x_enemy[j],y_enemy[j]);
                if(c)
                {
                    Power--;
                    flag[j]=0;
                }
            }
        }
        for(int j=0; j<1000; j++)
        {
            if(flag_for_bullet[j]==1)
            {
                iPoint(bullet_x_point[j],bullet_y_point[j],2);
                for(int k=0; k<i; k++)
                {
                    if(flag[k]==1)
                    {
                        if(bullet_x_point[j]>=x_enemy[k]  &&  bullet_x_point[j]<=x_enemy[k]+40  &&bullet_y_point[j]>=y_enemy[k]&&  bullet_y_point[j]<=y_enemy[k]+30)
                        {
                            if(type[k]==0)
                            {flag[k]=0;
                            flag_for_bullet[j]=0;
                            score+=10;
                            }
                            if(type[k]==1)
                            {   flag[k]=0;
                                flag_for_bullet[j]=0;
                                score+=10;
                                bullets+=50;
                            }
                            if(type[k]==2)
                            {

                                flag[k]=0;
                                flag_for_bullet[j]=0;
                                Power=min(10,Power+1);

                            }


                        }
                    }
                }
            }
        }
        for(int j=0; j<1000; j++)
        {
            if(flag_for_enemy_bullet[j]==1)
            {
                iSetColor(255,0,0);
                iPoint(x_enemy_bullet[j],y_enemy_bullet[j],2);
                if(x_enemy_bullet[j]>=x&&x_enemy_bullet[j]<=x+37&&y_enemy_bullet[j]>=y&&y_enemy_bullet[j]<=y+25)
                {
                    Power--;
                    flag_for_enemy_bullet[j]=0;
                }
            }
        }

    }
    if(mode==12)//Pause menu
    {
        pause_menu();
        print_name();
    }
    if(Power==0||bullets==0)
    {
        mode=10;
        //iSetColor(107,257,215);
        main_image();
        //iFilledRectangle(0,0,800,580);
        print_name();
        iSetColor(255,255,255);
        iText(300,380,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(320,330,"Score : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(395,330,str,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iFilledRectangle(270,280,200,40);
        iSetColor(0,0,0);
        iText(290,290,sss,GLUT_BITMAP_TIMES_ROMAN_24);

    }
    if(mode==5)//Credits
    {
        credits();

    }
    if(mode==2)
    {
        //iSetColor(107,257,215);
        //iFilledRectangle(0,0,800,580);
        main_image();
        print_name();
        iSetColor(255,255,255);
        //iFilledRectangle(300,280,200,40);
        //iFilledRectangle(300,220,200,40);
       // iFilledRectangle(300,160,200,40);
       // iFilledRectangle(300,40,200,40);
        //iSetColor(0,0,0);
        iText(367,290,"EASY",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(350,230,"MEDIUM",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(357,170,"HARD",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(362,50,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
        iFilledCircle(circle_for_level_x,circle_for_level_y,8);
    }
    if(mode==4)
    {
        highscore();
    }
    if(mode==56)
    {
        settings();
        print_name();
    }
}
void enemy_move()
{
    for(int j=0; j<i; j++)
    {
        x_enemy[j]-=2;
    }
}
void new_enemy()
{
    x_enemy[i]=800;
    y_enemy[i]=(rand()%16)*30;
    type[i]=0;
    flag[i]=1;
    int c=rand()%5;
    //printf("%d",c);
    if(c==1)
    {
        type[i]=1;
    }
    int d=rand()%15;
    if(d==7)
    {
        type[i]=2;
    }
    i++;

}
void proceed_bullet()
{
    for(int j=0; j<1000; j++)
    {
        bullet_x_point[j]+=20;
    }
    for(int j=0; j<1000; j++)
    {
        x_enemy_bullet[j]-=5;
    }
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    //printf("%d %d\n",mx,my);
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //printf("%d %d\n",mx,my);
        if(mode==1)
        {
            if(bullets-1>=0)
            {
            //place your codes here
            playbeep();
            bullets--;
            bullet_x_point[p]=x+50;
            bullet_y_point[p]=y+13.5;
            flag_for_bullet[p]=1;
            p++;
            if(p>10)
            {
                p=0;
            }
            }
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        if(mode==0)//menu
        {
            if(mx<=500&&mx>=300&&my<=440&&my>=400)
            {
                mode=1;
                stopsound();
                namelength=0;highscoretoresume=0;bullets=100;x=50;y=30;p=0;score=0;enemy_bullet_number=0;i=0;Power=10;
                memset(flag,0,1000*sizeof(int));
                memset(flag_for_bullet,0,1000*sizeof(int));
                memset(flag_for_enemy_bullet,0,1000*sizeof(int));
            }
            if(mx<=500&&mx>=300&&my<=380&&my>=340)
            {
                loadgame();
                mode=1;
                stopsound();
            }
            if(mx<=500&&mx>=300&&my<=320&&my>=280)
            {
                mode=2;
                if(sound==0)
                {
                    playsound();
                }
            }
            if(mx<=500&&mx>=300&&my<=200&&my>=160)
            {
                mode=5;
                if(sound==0)
                {
                    playsound();
                }
            }
            if(mx<=500&&mx>=300&&my<=260&&my>=220)
            {
                highscoretoresume=0;
                mode=4;
                if(sound==0)
                {
                    playsound();
                }
            }
            if(mx<=500&&mx>=300&&my<=140&&my>=100)
            {
                mode=56;//mode for settings
                if(sound==0)
                {
                    playsound();
                }
            }
            if(mx<=424&&mx>=368&&my<=73&&my>=48)
            {
                exit(0);
            }


        }
        else if(mode==12)//resume
        {
            if(mx<=500&&mx>=300&&my<=440&&my>=400)
            {
                mode=1;
                iResumeTimer(t);
                iResumeTimer(tc);
                iResumeTimer(tm);
                iResumeTimer(tmp);
                iResumeTimer(tmc);
                md=1;
                stopsound();
            }
            if(mx<=500&&mx>=300&&my<=380&&my>=340)
            {
                mode=4;
                highscoretoresume=1;//add
                if(sound==0)
                {
                    playsound();
                }
            }
            if(mx<=500&&mx>=300&&my<=320&&my>=280)
            {
                mode=0;
                iResumeTimer(t);
                iResumeTimer(tc);
                iResumeTimer(tm);
                iResumeTimer(tmp);
                iResumeTimer(tmc);
                md=1;
            }
            if(mx<=500&&mx>=300&&my<=260&&my>=220)
            {
                savegame();
            }
            if(mx<=500&&mx>=300&&my<=200&&my>=160)
            {
                exit(0);
            }

        }

        else if(mode==2)//level
        {
            if(mx<=500&&mx>=300&&my<=320&&my>=280)
            {
                circle_for_level_y=300;
                intervalfornewenemy=3000;
                intervalforenemymove=50;
                intervalforenemybulletcreate=2100;   //add;
            }
            if(mx<=500&&mx>=300&&my<=260&&my>=220)
            {
                circle_for_level_y=240;
                intervalfornewenemy=2000;
                intervalforenemymove=40;
                intervalforenemybulletcreate=1500;     //add
            }
            if(mx<=500&&mx>=300&&my<=200&&my>=160)
            {
                circle_for_level_y=180;
                intervalfornewenemy=1000;
                intervalforenemymove=20;
                intervalforenemybulletcreate=1000;      //add
            }
            if(mx<=500&&mx>=300&&my<=80&&my>=40)
            {
                mode=0;
            }
            if(sound==0)
            {
                playsound();
            }

        }
        else if(mode==4)
        {
            if(mx<=500&&mx>=300&&my<=80&&my>=40&&highscoretoresume==0)
            {
                mode=0;
            }
            if(mx<=500&&mx>=300&&my<=80&&my>=40&&highscoretoresume==1)
            {
                mode=12;
            }

        }
        else if(mode==5)//credit
        {
            if(mx>=300&&mx<=500&&my<=100&&my>=40)
            {
                mode=0;
            }
        }
        else if(mode==10)//game over
        {
            if(mx<=470&&mx>=270&&my>=280&&my<=320)
            {
                int l=strlen(sss);
                while(--l>=0)
                {
                    sss[l]=0;
                }
                mode_for_enter_name=1;
            }
        }
        else if(mode == 56)
        {
            if(mx>=300&&mx<=500&&my<=100&&my>=40)
            {
                mode=0;
            }
            if(mx>=278&&mx<=347&&my<=325&&my>=309)
            {
                sound_manual=0;
                stopsound();
                if(circle_for_settings_y!=313)
                    circle_for_settings_y-=35;
            }
            if(mx>=279&&mx<=336&&my<=358&&my>=341)
            {
                sound_manual=1;
                playsound();
                if(circle_for_settings_y!=348)
                    circle_for_settings_y+=35;
            }
            if(mx>=278&&mx<=347&&my<=218&&my>=202)
            {
                if(circle_for_beep_y==170)
                {
                    beep_mode=1;
                    circle_for_beep_y+=40;
                }
            }
            if(mx>=279&&mx<=336&&my<=185&&my>=169)
            {
                if(circle_for_beep_y==210)
                {
                    beep_mode=0;
                    circle_for_beep_y-=40;
                }
            }

        }
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
    if(mode_for_enter_name==1)
    {
        if(key=='\r')
        {
            FILE *fp;
            fp=fopen("scores.txt","a");
            fprintf(fp,"%s %d \n",sss,score);
            fclose(fp);
            strcpy(sss,"Enter your name");
            mode_for_enter_name=0;
            Power=10;
            bullets=100;
            mode=0;
        }
        else
        {
            if(namelength<=14)
            {
                sss[namelength++]=key;
            }
        }

    }

    if (key == 'q')
    {
        exit(0);
    }
    if((key=='p'||key=='P')&&mode==1)//game pause
    {
        iPauseTimer(t);
        iPauseTimer(tc);
        iPauseTimer(tm);
        iPauseTimer(tmp);
        iPauseTimer(tmc);
        md=0;
        mode=12;//pause bar
        if(sound==0)
        {
            playsound();
        }//pause bar
    }

    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, , GLUT_KEY_RIGHT, , GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_UP)
    {
        if(y+30<=500 &&md==1)
            y+=12;
    }
    if(key==GLUT_KEY_DOWN)
    {
        if(y-10>=0 &&md==1)
        {
            y-=12;
        }
    }
    if(key==GLUT_KEY_RIGHT)
    {
        if(x+50<=750 &&md==1)
        {
            x+=50;
        }
    }
    if(key==GLUT_KEY_LEFT)
    {
        if(x-50>=0 &&md==1)
        {
            x-=50;
        }
    }
    //place your codes for other keys here
}
void y_move()
{

    for(int j=0; j<i; j++)
    {
        int mode=rand()%2;
        if(mode==1)
        {
            if(y_enemy[j]+75<=500)//recheck
                y_enemy[j]+=15;
        }
        else
        {
            if(y_enemy[j]-15>=0)//recheck
                y_enemy[j]-=15;
        }
    }
}
void enemy_bullet_create()
{
    for(int j=0; j<i; j++)
    {
        if(type[j]==1||type[j]==0){
        if(flag[j]==1)
        {
            x_enemy_bullet[enemy_bullet_number]=x_enemy[j];
            y_enemy_bullet[enemy_bullet_number]=y_enemy[j];
            //bullet_parents[enemy_bullet_number]=j;
            flag_for_enemy_bullet[enemy_bullet_number]=1;
            enemy_bullet_number++;
            if(enemy_bullet_number>900)
            {
                enemy_bullet_number=0;
            }
        }
        }
    }
}


int main()
{
    //place your own initialization codes here.
    t=iSetTimer(intervalforenemymove,enemy_move);
    tc=iSetTimer(intervalfornewenemy,new_enemy);
    tm=iSetTimer(500,y_move);
    tmp=iSetTimer(10,proceed_bullet);
    tmc=iSetTimer(intervalforenemybulletcreate,enemy_bullet_create);
    playsound();
    iInitialize(800,580, "Space Impact");
    return 0;
}


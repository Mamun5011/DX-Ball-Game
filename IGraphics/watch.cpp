#include"iGraphics.h"
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include<algorithm>
using namespace std;

//LATEST GAME...... VERSION 2
int F1=1,S1=0,W1=0,L1=0,I1=0,G1=0,H1=0;
int radius;
int flag=0,flag1=0,P1=0,Q=0,K=0,M;
int score=0,stop_var=1,st=0;
int ball_x=390, ball_y=23;
float image_x1,image_x2,image_y1,image_y2,image_x3,image_y3;
float image_dy =.2;
int dx, dy,dis;
int image_array[3];
int level1=1,level2=0,p=0,life,q=0,z=0,counter=0;
int image_x,image_dx,x,y;

//int array_b[9][25] = {{0,0,0,0,1,1,1,1,2,2,2,2,3,2,2,2,2,1,1,1,1,0,0,0,0},{0,0,0,1,1,1,1,2,2,2,2,3,3,3,2,2,2,2,1,1,1,1,0,0,0},{0,0,1,1,1,1,2,2,2,2,3,3,3,3,3,2,2,2,2,1,1,1,1,0,0},{0,1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,2,2,2,2,1,1,1,1,0},{1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,3,3,2,2,2,2,1,1,1,1},{0,1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,2,2,2,2,1,1,1,1,0},{0,0,1,1,1,1,2,2,2,2,3,3,3,3,3,2,2,2,2,1,1,1,1,0,0},{0,0,0,1,1,1,1,2,2,2,2,3,3,3,2,2,2,2,1,1,1,1,0,0,0},{0,0,0,0,1,1,1,1,2,2,2,2,3,2,2,2,2,1,1,1,1,0,0,0,0}};

int array_b[9][25];
int drect = 20;
int stick_x = 365,stick_y = 0;
int rand_2d[3][2] = {{0,10},{2,19},{5,8}};
int rand_array[4] = {0,0,0,0};
int ordinate_array[10] = {360,(360+1*20),(360+2*20),(360+3*20),(360+4*20),(360+5*20),(360+6*20),(360+7*20),(360+8*20),(360+9*20)};
int abscissa_array[26] = {105,(105+1*30),(105+2*30),(105+3*30),(105+4*30),(105+5*30),(105+6*30),(105+7*30),(105+8*30),(105+9*30),(105+10*30),(105+11*30),(105+12*30),(105+13*30),(105+14*30),(105+15*30),(105+16*30),(105+17*30),(105+18*30),(105+19*30),(105+20*30),(105+21*30),(105+22*30),(105+23*30),(105+24*30),(105+25*30)};
int var = 0,value =0;



void load_game()
{

		    int i,j;
    FILE *fp;
     fp=fopen("install.txt","r");
      for(i=0;i<9;i++){
    for(j=0;j<25;j++){
           fscanf(fp,"%d",&array_b[i][j]);
           }}
          fscanf(fp,"%d",&life);
		  fscanf(fp,"%d",&dis);
		  fscanf(fp,"%d",&radius);
		    fscanf(fp,"%d",&score);
    fclose(fp);

	ball_x=390; ball_y=23;
	q=0;
}

void save_game()
{
	if(M==1){
		 int i,j;

    FILE *fp;
     fp=fopen("install.txt","w");
      for(i=0;i<9;i++){
    for(j=0;j<25;j++){
           fprintf(fp,"%d",array_b[i][j]);
	        fprintf(fp,"\n");}}
               fprintf(fp,"%d",life);
			    fprintf(fp,"\n");
				 fprintf(fp,"%d",dis);
				 fprintf(fp,"\n");
				  fprintf(fp,"%d",radius);
				  fprintf(fp,"\n");
				   fprintf(fp,"%d",score);
				    fprintf(fp,"\n");
				    fprintf(fp,"%d",image_array[0]);
					 fprintf(fp,"\n");
					  fprintf(fp,"%d", image_array[1]);
					  fprintf(fp,"\n");
					   fprintf(fp,"%d",image_array[2]);
			   fclose(fp);
   }
	 
	 M=0;
}

void installation()
{

	    int i,j;
    FILE *fp;
     fp=fopen("initial.txt","r");
      for(i=0;i<9;i++){
    for(j=0;j<25;j++){
           fscanf(fp,"%d",&array_b[i][j]);
           }}
          fscanf(fp,"%d",&life);
		  fscanf(fp,"%d",&dis);
		  fscanf(fp,"%d",&radius);
		   fscanf(fp,"%d",& image_array[0]);
		    fscanf(fp,"%d",& image_array[1]);
			 fscanf(fp,"%d",& image_array[2]);
		  
    fclose(fp);
	st=0;

}


void mainmenu()
{
	
	iShowBMP(0,0, "image1.bmp");
	iShowBMP(295,605, "Capture.bmp");
	iSetColor(0,255,0);
	iRectangle(360, 400, 220, 40);//PLAY GAME
	iSetColor(255,0,0);
	iText(397, 410,"PLAY GAME",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(0,255,0);
	iRectangle(360, 340, 220, 40);//resume game
	iSetColor(255,0,0);
	iText(380, 350,"RESUME GAME",GLUT_BITMAP_TIMES_ROMAN_24);


	iSetColor(0,255,0);
	iRectangle(360,280, 220, 40);// instructions
	iSetColor(255,0,0);
	iText(380, 295,"INSTRUCTION",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0,255,0);
	iRectangle(360,220, 220, 40);
	iSetColor(255,0,0);
	iText(388, 235,"HIGHSCORE",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0,255,0);
	iRectangle(360,160, 220, 40);//Exit
	iSetColor(255,0,0);
	iText(425, 175,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

}


void instructions()
{

	
	iShowBMP(0,0, "ins.bmp");
	iShowBMP(185,585, "icon1.bmp");
	iSetColor(255,0,0);
	iRectangle(170,145,680,370);
	iSetColor(0,0,0);
	iText(180,460,"This is just a simple breakout-style game.  Do your best to break all the bricks on",GLUT_BITMAP_HELVETICA_18);
	iText(172,435," the screen without dropping the ball.If you break all the bricks, then you will move",GLUT_BITMAP_HELVETICA_18);
	iText(180,410,"on to the next board.  If you are really good, you'll be able to beat the board pack",GLUT_BITMAP_HELVETICA_18);
	iText(180,385,"and hopefully have the new high score.To play, pick a board pack and click the",GLUT_BITMAP_HELVETICA_18);
	iText(180,360,"Play button.Don't forget to grab the power-ups during the game... they will make",GLUT_BITMAP_HELVETICA_18);
	iText(180,335,"the game a lot more fun.  Blue power-ups are usually good.....",GLUT_BITMAP_HELVETICA_18);
	iText(180,310,"keyboard instructions:",GLUT_BITMAP_HELVETICA_18);

	iText(315,285,"Turn right- F ",GLUT_BITMAP_HELVETICA_18);
	iText(315,263,"Turn left - A ",GLUT_BITMAP_HELVETICA_18);
	iText(315,241,"Pause    - p ",GLUT_BITMAP_HELVETICA_18);
	iText(315,219,"Resume  - r ",GLUT_BITMAP_HELVETICA_18);

	iText(250,200,"That'd be all !",GLUT_BITMAP_HELVETICA_18);
	iText(380,165,"HAVE FUN!",GLUT_BITMAP_HELVETICA_18);
	iSetColor(255,0,0);
	iRectangle(360,15,200,50);//Back
	iSetColor(255,0,0);
	iText(415,30,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
}
void icon()
{


	iShowBMP(320,615, "icon.bmp");
	iShowBMP(170,430, "speedball.bmp");
	iSetColor(0,255,0);
	iText(210,440,"SPEEDBALL",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(170,390, "bigball.bmp");
	iText(210,405,"BIG BALL",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(170,360, "killpaddle.bmp");
	iText(210,370,"KILL PADDLE",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(170,325, "expandpaddle.bmp");
	iText(210,335,"EXPAND PADDLE",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,0,0);
	iRectangle(360,15,200,50);//Back
	iSetColor(255,255,0);
	iText(415,30,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,255,0);
	iRectangle(385,225,200,50);//Back
	iSetColor(0,255,0);
	iText(400,240,"START GAME",GLUT_BITMAP_TIMES_ROMAN_24);


}

void drawing_lives()
{
	int i;
	for (i = 0; i < life; i++)
	{


		iSetColor(255,255,255);
		iFilledCircle(500+i*20,650,8);
		iSetColor(255,0,0);
		iFilledCircle(500+i*20,650,5);


	}
	st++;

	if(st==1){
		ball_x=390;
		ball_y=25;
		array_b[0][8]=2;
		array_b[0][9]=2;
		Sleep(100);
		iPauseTimer(0);}
}

void rand_image(int x,int y)
{
	int i,j;

	for (i = 0; i<3; i++)
	{    
		for (j = 0; j<2; j++)
		{
			if(x == rand_2d[i][j] && y == rand_2d[i][j+1])
			{
				
				
				image_array[i] = 1;
				if(i == 0)
				{
					image_x1 = abscissa_array[y];
					image_y1 = ordinate_array[x];

				}
				else if(i == 1)
				{
					image_x2 = abscissa_array[y];
					image_y2 = ordinate_array[x];


				}
				else if(i == 2){
					image_x3 = abscissa_array[y];
					image_y3 = ordinate_array[x];

				}
				

			}


		}

	}




}

void image_position()
{
	if(image_array[0] == 1)
	{
		image_y1 -= image_dy;

	}
	else if(image_array[1] == 1)
	{
		image_y2 -= image_dy;

	}
	else if(image_array[2] == 1){
	    image_y3 -= image_dy;
	}

}
void oppo_eating()
{
	int i;

	if(image_y1 < 15 )
	{
		image_array[0] = 0;

	}
	if(image_y2 < 15)
	{
		image_array[1] = 0;

	}
	if(image_y3 < 15){
		image_array[2] = 0;
	}

	if(image_array[0] || image_array[1]||image_array[2])
	{
		if( image_y1 <= 20 && (image_x1 >= stick_x - 8 && image_x1 <= stick_x + dis+8))
		{
			dis = 100;
			

		}
		else if(image_y2 <= 20 && (image_x2 >= stick_x - 8) && (image_x2 <= stick_x + dis +8))
		{
			radius = 8;
		}
		else if(image_y3 <= 20 && (image_x3 >= stick_x - 8) && (image_x3 <= stick_x + dis +8))
		{
			
			life -= 1;
			

		}
	}
			
}
void show_image()
{
	image_position(); 
	oppo_eating();


	if(image_array[0] == 1)
	{
		iShowBMP(image_x1,image_y1, "expandpaddle.bmp");


	}
	else if(image_array[1] == 1)
	{
		iShowBMP(image_x2,image_y2, "bigball.bmp");
	}
	else if(image_array[2] == 1)
	{
		iShowBMP(image_x3,image_y3,"killpaddle.bmp");
	}


}


void levelcheck()
{
	int i,j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 25; j++)
		{ if(array_b[i][j] == 0)
		{
			z++;
		}
		}
	}


	if(z==135){level2=1;
	level1=0;
	counter++;
	if(counter==2){
		W1=1;}
	}
	else{
		z=0;}
}





void vanish_bricks(int x,int y)
{

	if(array_b[x][y] == 1 || array_b[x][y] == 2|| array_b[x][y] == 3)
	{

		array_b[x][y] *= 0;
		dx = -dx;
		dy = -dy;
		rand_image(x,y);

	}
}
void is_there()
{
	int i;
	for( i = 0; i < 10; i++)
	{
		if(ball_y >= (ordinate_array[i]-6)&&(ball_y<=ordinate_array[i+1]+6))
		{
			x = i;

			break;
		}
	}
	for( i = 0; i < 25; i++)
	{
		if(ball_x >= abscissa_array[i]-6 && ball_x <= abscissa_array[i+1]+6)
		{
			y = i;

			break;
		}

	}
	if (array_b[x][y] != 0)
	{

		vanish_bricks(x,y);
		score+=20;
	}

}


void score_save()
{
	using namespace std;
	int a[5],i;
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	fclose(fp);
	sort(a,a+5);
	if(score>a[0]){
		a[0]=score;
		sort(a,a+5);
		fp=fopen("input.txt","w");
		for(i=4;i>=0;i--){
			fprintf(fp,"%d\n",a[i]);}
		fclose(fp);}


}


int score_card()
{

	int m,n,p,v,w;
	char str[5];



	n=(score/1000)+48;
	p=(score/100)%10+48;
	v=(score/10)%10+48;
	w=(score%10)+48;

	str[0]=(char)n;
	str[1]=(char)p;
	str[2]=(char)v;
	str[3]=(char)w;
	str[4]='\0';
	iSetColor(255,255,0);
	iText(700,630,&str[0],GLUT_BITMAP_TIMES_ROMAN_24);
	return 0;
}

int score_card2()
{
	int m,n,p,v,w;
	char str[5];
    n=(score/1000)+48;
	p=(score/100)%10+48;
	v=(score/10)%10+48;
	w=(score%10)+48;

	str[0]=(char)n;
	str[1]=(char)p;
	str[2]=(char)v;
	str[3]=(char)w;
	str[4]='\0';
	iSetColor(255,255,0);
	//iText(310,370,"YOUR SCORE IS",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(410,330,"YOUR SCORE IS",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(455,290,&str[0],GLUT_BITMAP_TIMES_ROMAN_24);
	return 0;


}




void score_open()
{

	int m,n,p,v,w,c;
	char str[5];
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&c);
	fclose(fp);

	n=(c/1000)+48;
	p=(c/100)%10+48;
	v=(c/10)%10+48;
	w=(c%10)+48;

	str[0]=(char)n;
	str[1]=(char)p;
	str[2]=(char)v;
	str[3]=(char)w;
	str[4]='\0';
	iSetColor(255,255,0);
	iSetColor(255,0,0);
	iRectangle(360,15,200,50);//Back
	iSetColor(255,255,0);
	iText(415,30,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);

	iText(310,370,"YOUR HIGH SCORE IS",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(410,330,&str[0],GLUT_BITMAP_TIMES_ROMAN_24);


}
void finding_position()
{




	// if(ball_y <=21 && ball_x >= (stick_x - 140) && ball_x <= (stick_x + 75+8))
	if(ball_y<=21 && ball_x+12-stick_x-8>=0 && stick_x +dis+8-ball_x>=0)
	{

		value=1;

	}

	else if(ball_y <=10 && !(ball_x+7-stick_x-5>=0 && stick_x + dis+10-ball_x>=0))
	{
		q=1;


	}
	else if(ball_y >= 340 && ball_y <= 570)
	{

		p=1;


	}


}



void iDraw()
{
	//place your drawing codes here	

	iClear();
	if(F1 == 1){
		mainmenu();
		flag=0;
		flag1=0;
		save_game();
		}

	else if(K==1){
		     
		   load_game();
			G1=1;
			 K=0;

	}
	else if(W1==1){
			
		iShowBMP(295,605, "Capture.bmp");
		  iShowBMP(0,0, "congra.bmp");
		iShowBMP(150,400, "congras.bmp");
		iSetColor(255,255,0);
		iText(340, 410,"CONGRATULATION",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(388, 370,"YOU WON",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,0,0);
	iRectangle(360,15,200,50);//Back
	iSetColor(255,255,0);
	iText(415,30,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);

		score_save();
		P1=1;
		//life=5;
		score=0;
	}
	else if(L1==1){
	
		//iSetColor(255,255,0);
	iShowBMP(295,605, "Capture.bmp");
	iShowBMP(0,0, "over.bmp");
	//iText(405, 400,"SORRY",GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(388, 360,"YOU LOSE",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,0,0);
	iRectangle(360,15,200,50);//Back
	iSetColor(255,255,0);
	iText(415,30,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	   score_card2();
		score_save();
		P1=1;
		//score=0;
	
	}
	else if(I1){
		instructions();
		flag=1;                
		flag1=0;
		
	}
	else if(S1){
	   

	iShowBMP(0,0, "a2EJP.bmp");
		icon();
		flag1=1;
		flag=1;
		installation();
	score=0;
		



			score=0;
		K=0;
	//life=5;
	}
	else if(H1){
		iShowBMP(0,0, "scene1.bmp");
		
	
		score_open();
		flag=1;
		flag1=0;
		
	}

	else if(G1==1){


		iClear();
		score_card();
		if(q==1){


			image_array[0] == 0;
			image_array[1] == 0;
			image_array[2] == 0;
			

			
			iFilledRectangle(stick_x,0,dis,15);
			iFilledCircle(stick_x,7.5,7.5);
			iFilledCircle(stick_x+dis,7.5,7.5);
			stick_x = 365;
			ball_x = 390;
			ball_y = 23;
			ball_y=(ball_y) >0?(ball_y):-(ball_y);
			dy =(dy)>0?(dy):(-dy);
			life-=1;
			iPauseTimer(0);
			Sleep(100);
			q=0;
		}
		if(p==1){
			is_there();
			p=0;}

		if(value==1){


			dy =(dy)>0?(dy):(-dy);
			ball_y=23;

			value=0;}

		    Q=1;
			iSetColor(255,0,0);
	        iRectangle(20,630,150,40);//Back
	        iSetColor(255,255,0);
	        iText(35,646,"save game",GLUT_BITMAP_TIMES_ROMAN_24);
			

		int i,j;
		for(i = 0; i < 9; i++)
		{
			for(j = 0; j < 25; j++)
			{

				if(level1){

					if(array_b[i][j] == 3)
					{
						iSetColor(0, 0, 0);
						iFilledRectangle(105+(30*j),200+(8+i)*20,30,20);
						iSetColor(255, 255, 0);
						iFilledRectangle(108+(30*j),204+(8+i)*20,24,13);

					}

					else if(array_b[i][j] == 2)
					{

						iSetColor(380, 190, 168);
						iFilledRectangle(105+(30*j),200+(8+i)*20,28,18);
						iSetColor(255, 0, 0);

						iFilledRectangle(108+(30*j),204+(8+i)*20,24,13);

					}
					else if(array_b[i][j] == 1)
					{
						iSetColor(0,0,255);
						iFilledRectangle(105+(30*j),200+(8+i)*20,28,18);
						// iSetColor(380, 190, 168);
						iSetColor(0,255,0);
						iFilledRectangle(108+(30*j),204+(8+i)*20,24,13);
					}
				}
				if(level2){



					if(array_b[i][j] == 2)
					{

						iSetColor(380, 190, 168);
						iFilledRectangle(105+(30*j),200+(8+i)*20,28,18);
						iSetColor(255, 0, 0);

						iFilledRectangle(108+(30*j),204+(8+i)*20,24,13);

					}

					else if(array_b[i][j] == 3)
					{
						array_b[i][j]*=0;
					}

					else if(array_b[i][j] == 1)
					{
						iSetColor(0,0,255);
						iFilledRectangle(105+(30*j),200+(8+i)*20,28,18);
						// iSetColor(380, 190, 168);
						iSetColor(0,255,0);
						iFilledRectangle(108+(30*j),204+(8+i)*20,24,13);
					}




				}




			}

		}

		ball_y=(ball_y)>0?(ball_y):-(ball_y);

		iSetColor(380, 190, 168);
		iFilledCircle(ball_x,ball_y,radius);
		iSetColor(192,67,255);
		iFilledRectangle(stick_x,0,dis,15);
		iFilledCircle(stick_x,7.5,7.5);
		iFilledCircle(stick_x+dis,7.5,7.5);
		drawing_lives();
		finding_position();
		show_image();

			if(life==0){

			F1=0;
			I1=0;
			S1=0;
			W1=0;
			L1=1;
			H1=0;
			G1=0;
		    image_array[0]=0;
			image_array[1]=0;
			image_array[2]=0;


	}


	}





	//iText(560, 10, "Use cursors to move the picture.");
}

void iMouseMove(int mx,int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		if(flag==0 && mx>=360 && mx<=580 && my>=400 && my<=440){  //play game
			S1=1;
			F1=0;
			I1=0;
			L1=0;
			W1=0;
			H1=0;
			G1=0;
			K=0;
		}
		         


		else if(flag==0 && mx>=360 && mx<=580 && my>=340 && my<=380){   //resume game
			                                                                       
			K=1;   
			F1=0;
			I1=0;
			S1=0;
			W1=0;
			L1=0;
			H1=0;

		}
                                 

		else if(flag==0 && mx>=360 && mx<=580 && my>=280 && my<=320){  //instruction

			I1=1;
			F1=0;
			S1=0;
			W1=0;
			L1=0;
			H1=0;
			G1=0;
			K=0;
		}

		else if(flag==1 && mx>=360 && mx<=560 && my>=15 && my<=65){   //back
			F1=1;
			I1=0;
			S1=0;
			W1=0;
			L1=0;
			H1=0;
			G1=0;
			K=0;

		}

		
		else if(P1==1 && mx>=360 && mx<=560 && my>=15 && my<=65){   //back
			F1=1;
			I1=0;
			S1=0;
			W1=0;
			L1=0;
			H1=0;
			G1=0;                             // iRectangle(20,630,150,40); save game
			P1=0;
			K=0;

		}
		 else if(Q==1 && mx>=20 && mx<=170 && my>=630 && my<=670){                               

			 Q=0;
			 S1=0;
			F1=1;
			I1=0;
			L1=0;
			W1=0;
			H1=0;
			G1=0;
			K=0;
		 M=1;}


		else if(flag==0 && flag1!=1 && mx>=360 && mx<=580 && my>=220 && my<=260){  //highscore  iRectangle(360,220, 220, 40);
			H1=1;
			F1=0;
			I1=0;
			S1=0;
			W1=0;
			L1=0;
			G1=0;
			K=0;
		}
		else if( mx>=360 && mx<=560 && my>=160 && my<=200){
			exit(0);
		}                                  // iRectangle(385,225,200,50);
		else if(flag==1 && flag1==1 && mx>=385 && mx<=585 && my>=225 && my<=275){    //start game

			G1=1;
			flag=0;
			ball_x = 390;
			ball_y = 23;
			S1=0;
			F1=0;
			I1=0;
			L1=0;
			W1=0;
			K=0;

		}

	}


	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}


void iKeyboard(unsigned char key)
{

	if((key == 'a' || key == 'A') && stick_x >18)
	{
		stick_x -= 10;
		//if(ball_y<30)ball_x -= 10;

	}
	else if((key == 'f' || key == 'F') && stick_x < 895)

	{
		stick_x += 10;
		if(ball_x==stick_x+15)ball_x+=10;

	}
	else if(key == 'p')
	{
		iPauseTimer(0);
	}
	else if(key == 'r')
	{
		iResumeTimer(0);
	}
	/*if((key == 'f' || key == 'F') || (key == 'a' || key == 'A'))
	{
		//printf("Pressing A before");
		iResumeTimer(0);
		//printf("Pressing A after");
	}
	*/
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{

		exit(0);

	}


}
void ballChange()
{
	ball_x += dx;
	ball_y += dy;

	if(ball_x > 979 || ball_x < 0)dx = -dx;
	if(ball_y >= 700 )dy = -dy;
}
int main()
{

	iSetTimer(10,ballChange);
	iSetTimer(10,levelcheck);
	//iSetTimer(5,finding_position);	
	//iSetTimer(10,lose);
	dx = 12;
	dy = 5;
	iInitialize(980,700,"DX-BALL");
}

//============================================================================
// PROJECT FALL'19 
// MADE BY     : FARAYA BAIG 19I-2162 CS-H 
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...

//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include <fstream>
#include<sstream>
#include <string>
#include<cstdlib>

using namespace std;
float x = 25;    //declaring my car x-axis
float y = 750;   //declaring my car y-axis
int c=0;      
bool f=true,game_pause=true;  //bools
float xopp = 25;  //opponent car x-axis
float yopp = 50; //opponent car y-axis
int lives=3; //declaring lives
int menu=0;  //initialining menu
int score=0, fs=0;  //initialize and declare
int move1; 
float bx_rect[8];  //x-cordinates of gift boxes
float y_rect[8]; //y-cordinates of gift boxes
int level=1; //initialize level 1
bool check[5][8][8]; //bool check
string line2[10]; //array forhigh scores
string line;	
int MyCarSpeed=5;  //my car speed initialized
int OppoCarSpeed=5; //opponent car speed initialized
int speed2x=0; //initializing double speed
bool lost=false; //bool for losing

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity(); 
}



/*
 * Main Canvas drawing function.
 * */
//Board *b;


void GameDisplay()/**/{
	
	 
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	
	glClearColor(0.6/*Red Component*/, 0.6,	//148.0/255/*Green Component*/,
			0.706/*Blue Component*/, 0.5 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	

	//DrawCircle(seeds[1][2],seeds[1][3],3,colors[GREEN]);





	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
    
	if(menu == 0){  //Main Menu
		DrawCircle(700,770,500,colors[DARK_MAGENTA]);

		if(lost==true) //When lost display :-
		{ 
		DrawString(300,700,"GAME OVER",colors[MAROON]);
		DrawString(300,650,"YOUR SCORE: "+to_string(score),colors[BLACK]);
		}
		if(lost==false) //When program opens ,Display Main menu :-
		{
		DrawString(200,700,"Welcome to MENU of DODGE_EM ",colors[MAROON]);
		}

		DrawString(250,600,"(S)-Start a new game",colors[BLACK]);
		DrawString(250,500,"(H)-Help",colors[PINK]);
		DrawString(250,400,"(Esc)-Exit",colors[LAVENDER]);
		DrawString(250,300,"(T)-High Scores",colors[BLACK]);
		}
	

	// Drawing my car
	/*float x = 100; 
	float y = 100; 
	float width = 20; 
	float height = 15;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 5.0;*/
	string str="0";
	
	if(menu==1)     // ARENA,CARS,MOVEMENTS ARE ALL IN MENU 1(GameDisplay)
	                          
{ DrawString(350,900,"SCORE="+to_string(score),colors[BLACK]);   //Displaying scores on top of gameplay.Converting num to string
  DrawString(500,900,"LIVES="+to_string(lives),colors[HOT_PINK]); //Displaying lives on top of gameplay.Converting num to string
  DrawString(200,900,"LEVEL="+to_string(level),colors[HOT_PINK]); //Displaying levels on top of gameplay.Converting num to string
bx_rect[0]=40;  // x cordinates of the gift boxes
bx_rect[1]=110;
bx_rect[2]=190;
bx_rect[3]=260;
bx_rect[4]=540;
bx_rect[5]=615;
bx_rect[6]=690;
bx_rect[7]=760;
y_rect[0]=760;  //y cordinates of the gift boxes
y_rect[1]=690;
y_rect[2]=600;
y_rect[3]=515;
y_rect[4]=310;
y_rect[5]=200;
y_rect[6]=125;
y_rect[7]=40;
	
	for(int i=0; i<8; i++)
	{
	
		for(int j=0;j<8;j++){               
		if(check[level][i][j]==false){ 
		if( x-30>bx_rect[i] || x+30<bx_rect[i] || y-30>y_rect[j] || y+30<y_rect[j] ) //based on how far is my car from the gift boxes
		{
		
			DrawSquare(bx_rect[i],y_rect[j],15,colors[NAVY]);    //printing gift boxes and detecting them
		}
		else{
				check[level][i][j]=true;       //if car collides with gift boxes,bool check becomes true and score increses
				score++; fs++;	 	
		}
		}
	}
	}
	
	// My car
        float width = 10;   //declare and initialzie
	float height = 10;  //declare and initialize
	float* color = colors[BLUE_VIOLET]; 
	float radius = 3.0; //declare and initialize
	DrawRoundRect(x+move1,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect((x+width*3)+move1,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect((x+width*3)+move1,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x+move1,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x+move1, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width+move1, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect((x+width*3)+move1, y+height*2, width, height, color, radius/2); // body right rect
		
	// Drawing 2nd car(opponent)
	
		 
        color = colors[ORANGE];  
	DrawRoundRect(xopp,yopp,width,height,color,radius); // bottom left tyre
	DrawRoundRect((xopp+width*3),yopp,width,height,color,radius); // bottom right tyre
	DrawRoundRect((xopp+width*3),yopp+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(xopp,yopp+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(xopp, yopp+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(xopp+width, yopp+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect((xopp+width*3), yopp+height*2, width, height, color, radius/2); // body right rect
	
    	if(game_pause){ 
 	//My car movement
	if(x<740 && y==750)
	{
	 x=x+MyCarSpeed;  //right
	
	}
	else if(x==740 && y>40)
	{
	y=y-MyCarSpeed;  //right down
	
	}
	else if(y==40&& x>25)  //left
	{
 	  x=x-MyCarSpeed;

	}
	else if(x==25 && y<750)  //left up
	{
	y=y+MyCarSpeed;

	}                      // complete
	
	if(y==670 && x>=95 && x<670)       //loop for 2nd round
	
	{
	  x=x+MyCarSpeed;                       //right

	}
	else if(x==670 && y<=670 && y>110)
	{                                //right down
	y=y-MyCarSpeed;
	
	}
	else if(y==110 && x<=670 && x>95)        //left down
	{
 	  x=x-MyCarSpeed;
	
	}
	else if (x==95 && y>=110  && y<670)    //left up
	{ 
	y= y+MyCarSpeed;                      
	
	}	 //complete

	
	if ( y==600 && x>=165 && x<600)  //3rd round
	{
	 x=x+MyCarSpeed;            //right 
	
	}
	else if( x==600 && y<=600 && y>180)
	{
	 y=y-MyCarSpeed; //right down
	
	}
	else if( y==180 && x<=600 && x>165)	
	{
	 x=x-MyCarSpeed; //left
	
	}
	else if( x==165 && y>=180 && y<600)	//complete
	{ 
	y= y+MyCarSpeed; //left up
	
	} 
		
	if  (y==530 && x>=235 && x<530)  //4th round
	  {
	 x=x+MyCarSpeed; //right
	
	}
	else if( x==530 && y<=530 && y>250)
	{
	 y=y-MyCarSpeed;  //right down

	}
	else if( y==250 && x<=530 && x>235)	
	{
	 x=x-MyCarSpeed;  //left
	
	}
	else if(x==235 && y>=250 && y<530)	//complete
	{ 
	y= y+MyCarSpeed; //left up
	
	} 

	//For collision of Cars
	if((x>=xopp-30 && x<=xopp+30 && y>=yopp-30 && y<=yopp+30))
	{
 	 xopp=25, yopp=40;
	 x=25; y=750;
	lives--;
	fs=0;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
			check[level][i][j]=false;
			}
		}

	}

	if (fs==64)   //fs refers to score or 64 gift boxes collected.
	{ 
	 fs=0;
	 level++;  //when 64 boxes collected,level up
	 xopp=25; yopp=40;
	 x=740; y=40;
	 MyCarSpeed=5;    //definingg speeds of car
	 OppoCarSpeed=5;	 
	}




	
	// 2nd Car movement
      
	if(xopp<740 && yopp==40)
	{
	 xopp=xopp+OppoCarSpeed;  //right
	
	}
	else if(xopp==25 && yopp>40)
	{
	yopp=yopp-OppoCarSpeed;  //right down
	
	}
	else if(yopp==750&& xopp>25)  //left
	{
 	  xopp=xopp-OppoCarSpeed;

	}
	else if(xopp==740 && yopp<750)  //left up
	{
	yopp=yopp+OppoCarSpeed;

	}                      // complete
	
	if(yopp==110 && xopp>=95 && xopp<670)       //loop for 2nd round
	
	{
	  xopp=xopp+OppoCarSpeed;                       //right

	}
	else if(xopp==95 && yopp<=670 && yopp>110)
	{                                //right down
	yopp=yopp-OppoCarSpeed;
	
	}
	else if(yopp==670 && xopp<=670 && xopp>95)        //left down
	{
 	  xopp=xopp-OppoCarSpeed;
	
	}
	else if (xopp==670 && yopp>=110  && yopp<670)    //left up
	{ 
	yopp= yopp+OppoCarSpeed;                      
	
	}	 //complete

	
	if ( yopp==180 && xopp>=165 && xopp<600)  //3rd round
	{
	 xopp=xopp+OppoCarSpeed;            //right 
	
	}
	else if( xopp==165 && yopp<=600 && yopp>180)
	{
	 yopp=yopp-OppoCarSpeed; //right down
	
	}
	else if( yopp==600 && xopp<=600 && xopp>165)	
	{
	 xopp=xopp-OppoCarSpeed; //left
	
	}
	else if( xopp==600 && yopp>=180 && yopp<600)	//complete
	{ 
	yopp= yopp+OppoCarSpeed; //left up
	
	} 
		
	if  (yopp==250 && xopp>=235 && xopp<530)  //4th round
	  {
	 xopp=xopp+OppoCarSpeed; //right
	
	}
	else if( xopp==235 && yopp<=530 && yopp>250)
	{
	 yopp=yopp-OppoCarSpeed;  //right down

	}
	else if( yopp==530 && xopp<=530 && xopp>235)	
	{
	 xopp=xopp-OppoCarSpeed;  //left
	
	}
	else if(xopp==530 && yopp>=250 && yopp<530)	//complete
	{ 
	yopp= yopp+OppoCarSpeed; //left up
	
	} 

	
     }  
	

	// Drawing Arena
	int gap_turn = 60; //declare and initialize
	int sx = 20; //declare and initialize
	int sy = 10; //declare and initialize
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10; //declare and initialize
	float *scolor = colors[BROWN];
	//BOTTOM LEFT
	DrawRectangle(sx, sy, swidth-20, sheight, scolor); // bottom left
	DrawRectangle(sx + 60, sy + 90, swidth - 80, sheight , scolor); // second bottom left 2 (x,y)
	DrawRectangle(sx + 130, sy + 160, swidth - 150, sheight , scolor);// third bottom left
	DrawRectangle(sx + 208, sy + 230, swidth - 230, sheight , scolor); //fourth bottom left
	DrawRectangle(sx + 302, sy + 315, swidth - 205, sheight , scolor); //horiz mid line from bottom
	//BOTTOM RIGHT
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
        DrawRectangle(sx +swidth + gap_turn, sy + 90, swidth - 90, sheight,scolor); //sec bottom right
	DrawRectangle(sx +swidth + gap_turn, sy + 160, swidth - 170, sheight,scolor); //third bottom right
	DrawRectangle(sx +swidth + gap_turn, sy + 230, swidth - 240, sheight,scolor); //fourth bottom right
	//RIGHT DOWN
	DrawRectangle(sx +swidth*2+gap_turn, sy+sheight, sheight*2, swidth-18, scolor); // right down	
	DrawRectangle(sx-100 +swidth*2+gap_turn, sy+sheight+80, sheight*2-10, swidth-105, scolor); //parallel to right down(1)/
	DrawRectangle(sx-172 +swidth*2+gap_turn, sy+sheight+150, sheight*2-10, swidth-175, scolor);//parallel to right down (2)
	DrawRectangle(sx-250 +swidth*2+gap_turn, sy+sheight+222, sheight*2-10, swidth-248, scolor); //parallel to right down (3)
	//RIGHT UP
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up	
	DrawRectangle(sx-100+swidth*2+gap_turn, sy+sheight+6+swidth+gap_turn, sheight*2-10, swidth-80, scolor);//parallel to right up
	DrawRectangle(sx-170+swidth*2+gap_turn, sy+6+sheight+swidth+gap_turn, sheight*2-10, swidth-155, scolor);//parallel to up vertright
	DrawRectangle(sx-250+swidth*2+gap_turn, sy+6+sheight+swidth+gap_turn, sheight*2-10, swidth-235, scolor); //parallel to up right(5)
	DrawRectangle(sx-332+swidth*2+gap_turn, sy-14+sheight+swidth+gap_turn, sheight*2-10, swidth-300, scolor);// || TO UP RIGHT mid
	DrawRectangle(sx-500+swidth*2+gap_turn, sy-14+sheight+swidth+gap_turn, sheight*2-10, swidth-300, scolor);  // || to up left mid
	//TOP RIGHT
	DrawRectangle(sx+10 + swidth + gap_turn, sy+810, swidth-10, sheight, scolor); // top right	
	DrawRectangle(sx +10+ swidth + gap_turn, sy+651, swidth-170, sheight, scolor); //third top right
	DrawRectangle(sx +10+ swidth + gap_turn, sy+580, swidth-250, sheight, scolor); //fourth top right
	DrawRectangle(sx+10+ swidth + gap_turn, sy+730, swidth-100, sheight, scolor); //second top right
	//TOP LEFT	
	DrawRectangle(sx, sy+810, swidth-10, sheight, scolor); // top left
	DrawRectangle(sx+60, sy+726, swidth-70, sheight, scolor); // top left (2)
	DrawRectangle(sx+135, sy+647, swidth-147, sheight, scolor); //top left (3)
	DrawRectangle(sx+200, sy+576, swidth-212, sheight, scolor); //top left(4)
	DrawRectangle(sx+300, sy+486, swidth-200, sheight, scolor);
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	//LEFT DOWN
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth-15, scolor); // left down
	DrawRectangle(sx-740 +swidth*2+gap_turn, sy+sheight+80, sheight*2-10, swidth-95, scolor); // parallel to left down(1)
	DrawRectangle(sx-670 +swidth*2+gap_turn, sy+sheight+154, sheight*2-10, swidth-170, scolor); // parallel to left down(2)
	DrawRectangle(sx-600 +swidth*2+gap_turn, sy+sheight+220, sheight*2-10, swidth-235, scolor); // parallel to left down(3)
	//LEFT UP
	DrawRectangle(sx-740 +swidth*2+gap_turn, sy+sheight+427, sheight*2-10, swidth-80, scolor); // parallel to left up(2)
	DrawRectangle(sx-670 +swidth*2+gap_turn, sy+sheight+427, sheight*2-10, swidth-150, scolor); //parallel to left up(3)
	DrawRectangle(sx-600 +swidth*2+gap_turn, sy+sheight+427, sheight*2-10, swidth-230, scolor); //parallel to left up(4)
	DrawRectangle(sx-498 +swidth*2+gap_turn, sy+sheight+312, sheight*2-10, swidth-300, scolor);//  left mid vert line up
	DrawRectangle(sx-334 +swidth*2+gap_turn, sy+sheight+305, sheight*2-10, swidth-288, scolor); //right mid vertical line up 
	
	
}
if(menu==2) // Help Menu
{ DrawCircle(700,770,500,colors[PEACH_PUFF]);

DrawString(150,750,"----------Welcome To Game Guide-----------",colors[BLACK]);

DrawString(20,650,"Game Starts with two Cars.Purple Car is Player's car While yellow Car is Opponent's.",colors[DARK_RED]);
DrawString(20,600,"Player car moves clockwise while Enemy car moves Anti clockwise.",colors[DARK_RED]);
DrawString(100,550,"1-Press 'S' to start game",colors[GREEN]);
DrawString(100,500,"2-Press 'T' to view high scores",colors[BLUE]);
DrawString(100,450,"3-Use Up Down Left Right key to take Turns",colors[DARK_VIOLET]);
DrawString(100,400,"4-Press 'P' to Pause the game",colors[GREEN]);
DrawString(100,350,"5-Press 'C' to Continue the game",colors[BLUE]);
DrawString(100,300,"6-Press 'B' to go back to Main Menu",colors[DARK_VIOLET]);
DrawString(100,250,"7-Use Spacebar to double your speed",colors[GREEN]);

float width = 10;   //declare and initialzie
	float height = 10;  //declare and initialize
	float* color = colors[BLUE_VIOLET]; 
	float radius = 3.0; //declare and initialize
	DrawRoundRect(x+move1,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect((x+width*3)+move1,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect((x+width*3)+move1,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x+move1,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x+move1, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width+move1, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect((x+width*3)+move1, y+height*2, width, height, color, radius/2); // body right rect
        color = colors[ORANGE];  
	DrawRoundRect(xopp,yopp,width,height,color,radius); // bottom left tyre
	DrawRoundRect((xopp+width*3),yopp,width,height,color,radius); // bottom right tyre
	DrawRoundRect((xopp+width*3),yopp+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(xopp,yopp+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(xopp, yopp+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(xopp+width, yopp+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect((xopp+width*3), yopp+height*2, width, height, color, radius/2); // body right rect

}

if(lives<=0){  //When player loses,go to menu 0 i.e Main Menu 
	menu=0;
	lost=true;

 	}
if(menu==3)
{ 

//When T is pressed
	int position=700;
	int high_Scores[10] = { 1000, 280, 170, 160,150,100,50,20,10,0}; //scores array

//Comparing scores with high scores	
for(int j=0;j<10;j++)
{
	if(score>high_Scores[j])
	{
		high_Scores[j]=score;
		break;
	}

}
	//writing to a file
int i=1;

	DrawCircle(700,770,500,colors[DARK_MAGENTA]);
	DrawString(250,800,"--------High Scores--------",colors[BLACK]);
	ofstream fout;
	fout.open ("high_score.txt"); //this function takes the name of the file that you are writing to
	
	for (int i = 0; i < 10; i++){
		fout << high_Scores[i] << endl;
	}
		
	fout.close();
	
	//reading from a file
	string h_score;
	ifstream fin ("high_score.txt"); //name of the file it is supposed to read
	if (fin.is_open())
	{
		while ( getline (fin, h_score) ) //this loop will run depending on the number of lines in the file
		{
		DrawString(350,position,Num2Str(i)+") "+h_score,colors[AQUA_MARINE]);
		position-=50;
		i++;
		  
		  
		  
		}
		fin.close();
	}
	
	else 
	DrawString(350,500,"Unable to open file",colors[AQUA_MARINE]); 

}


	if(menu==10){
		exit(1);

}
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int a, int b) {
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
	if(y>=360&&y<=400&&x==235){             //conditions to turn my car with left key
	x-=70;
	}else if(y>=360&&y<=400&&x==95){
	x-=70;
	}else if(y>=360&&y<=400&&x==165){
	x-=70;
	}else if(y>=360&&y<=400&&x==740){
	x-=70;
	}else if(y>=360&&y<=400&&x==600){
	x-=70;
	}else if(y>=360&&y<=400&&x==670){
	x-=70;
	}
	//x = x - 5;
	//cout<<"l"<<x<<","<<y<<endl;

	} 
	else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
	{
	if(y>=360&&y<=400&&x==25){   //conditions to turn my car with right key
	x+=70;
	}else if(y>=360&&y<=400&&x==95){
	x+=70;
	}else if(y>=360&&y<=400&&x==165){
	x+=70;
	}else if(y>=360&&y<=400&&x==530){
	x+=70;
	}else if(y>=360&&y<=400&&x==600){
	x+=70;
	}else if(y>=360&&y<=400&&x==670){
	x+=70;
	} 
	//x+=5;
	//cout<<"R"<<x<<","<<y<<endl;
	} 
	else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/){
	if(x>=360&&x<=400&&y==670){      ////conditions to turn my car with up key
	y+=80;
	}else if(x>=360&&x<=400&&y==600){  //moving up step by step
	y+=70;
	}else if(x>=360&&x<=400&&y==530){
	y+=70;
	}else if(x>=360&&x<=400&&y==180){
	y += 70;
	}else if(x>=360&&x<=400&&y==110){
	y += 70;
	}else if(x>=360&&x<=400&&y==40){
	y += 70;
	}

	//y = y + 5;
	//cout<<"U"<<y<<endl;
	
	}
	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) 
	{
	if(x>=360&&x<=400&&y==670){  //conditions to turn my car with down key
	y-=70;
	if(x>=360&&x<=400&&y==750){      ////conditions to turn my car with up key
	y-=80;}
	}else if(x>=360&&x<=400&&y==600){
	y-=70;
	}else if(x>=360&&x<=400&&y==750){
	y-=80;
	}else if(x>=360&&x<=400&&y==180){
	y -= 70;
	}else if(x>=360&&x<=400&&y==110){
	y -= 70;
	}else if(x>=360&&x<=400&&y==250){
	y -= 70;
	}

	//y = y  - 5;
	//cout<<"D"<<x<<","<<y<<endl;	
	
	}
	glutPostRedisplay();


	}
		
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/




/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
 void PrintableKeys(unsigned char key, int x, int y) 
	{ 
	if (key == 27/* Escape key ASCII*/)                 //To exit the program
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'e' || key == 'E')   //to exit 
			
	{
		menu=10;
	}
	
 if(key == 's' || key == 'S'){  // TO start a new game
		score=0;
		menu=1;  // gameplay is in menu 1 
		lost=false; // bool check lost not true
		lives=3;
		}
	  if(key == 'H' || key == 'h'){  // To display Help

		menu=2; //Help is in menu 2
		lost=false; // When bool check lost is not true 
		lives=3; 
		}
	 if(key == 'T' || key == 't'){  // To display High Scores

		menu=3; //High scores are in menu 3
		lost=false;
		lives=3;
		}
	if(key == 'P' || key == 'p'){  //to pause the game

	game_pause = false; //stops movement 

	}
	if(key == 'C' || key == 'c'){ //To Continue

	game_pause = true;  //Bool check true and movements begin

	}
	
	if(key == 'B' || key == 'b'){  //To go back to Main menu of Dodge' Em

	menu=0;
	score=0;
	}

	/*if (key == 32) {  //Space bar ASCII 
	MyCarSpeed=10; //when presses speed of my car doubles
	speed2x++; 
		if (speed2x%2==0) //if pressed again , back to 5 speed
		{ MyCarSpeed=5; }
	}	*/

	glutPostRedisplay(); 
} 

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
//auto turns of opponent car
if (xopp>=360 && xopp<=400 && yopp==40)
{ yopp=110; }
if (xopp>=360 && xopp<=400 && yopp==670)
{ yopp=600; }
if (xopp>=360 && xopp<=400 && yopp==180)
{ yopp=250; }
if (xopp>=360 && xopp<=400 && yopp==530)
{ yopp=600; }

//switching from level 1 to 2
if (level==2 || level==3)
{
	if (level==3)
	{OppoCarSpeed=10;}
	if (yopp>=360 && yopp<=400 && xopp==740)
	{ xopp=670; }
	if (yopp>=360 && yopp<=400 && xopp==95)
	{ xopp=165; }
	if (yopp>=360 && yopp<=400 && xopp==600)
	{ xopp=670; }

}
        glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(500.0/FPS, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x6, int y6) {
cout<<x6<<"  "<<y6<<endl;
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
//string line;
std::ofstream myfile;
//myfile.open("score.txt", std::ios::app);
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 940; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge em by Faraya"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...


	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(500.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	//myfile<<score<<endl;
	return 1;
}

#endif /* AsteroidS_CPP_ */

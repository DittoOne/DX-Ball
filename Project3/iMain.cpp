#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int box_x = 10;
int box_y = 10;
int box2_x = 200;
int box2_y = 380;
int ball_x = 70 + rand() % 200  ;
int ball_y = 80 + rand() % 150;
int dx = 5 ;
int dy = 5 ;

int balltimer = 0;

struct bar{
	int bar_x;
	int bar_y;
	int bar_w;
	int bar_h;
	int bar_hp;
	bool bar_spawn;
};
int i = 0;
struct bar b[20];

int distance_x = 0;
int distance_y = 0;

int count = 0;

void iDraw()
{
	iClear();
	iSetColor(255, 0, 0);
	iFilledRectangle(box_x, box_y, 100, 10);

	/*iSetColor(255, 0, 255);
	iFilledRectangle(box2_x, box2_y, 100, 10);*/

	iSetColor(0, 255, 0);
	iFilledCircle(ball_x, ball_y, 10, 100);




	for (int i = 0; i < 20; i++){
		if (i % 2 == 0 && b[i].bar_spawn){
			iSetColor(0, 255, 255);
			iFilledRectangle(b[i].bar_x,b[i].bar_y,b[i].bar_w,b[i].bar_h);
		}
		else if(i%2 != 0 && b[i].bar_spawn){
			iSetColor(0, 0, 255);
			iFilledRectangle(b[i].bar_x, b[i].bar_y, b[i].bar_w, b[i].bar_h);
		}
	}
	
	if (count >= 20){
		iSetColor(0, 255, 0);
		iText(250, 200, " YOU WIN", GLUT_BITMAP_TIMES_ROMAN_24);
		iPauseTimer(balltimer);
	}

	if (ball_y+5 < 0 && count < 20){
		iSetColor(255, 0, 0);
		iText(250, 200, "YOU LOSE", GLUT_BITMAP_TIMES_ROMAN_24);
		iPauseTimer(balltimer);

	}
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	box_x = mx;
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'd')
	{
		box2_x += 20;
	}
	if (key == 'a')
	{
		box2_x -= 20;
	}
	
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

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}
void ballchange(){
	ball_x += dx;
	ball_y += dy;

	if ( ((ball_x <= box_x + 100 && ball_x >= box_x) && (ball_y <= box_y + 30)))
	{
		dx = (dx + rand() % 2);
		
		dy = -dy;
	}
	if (((ball_x >= box_x - 50 && ball_x <= box_x) && (ball_y <= box_y + 30)))
	{
		dx = -(dx + rand() % 2);

		dy = -dy;
	}
	
	
	for (int i = 0; i <= 19; i++){
		if (((ball_x <= b[i].bar_x + 120 && ball_x >= b[i].bar_x) && (ball_y >= b[i].bar_y)) && b[i].bar_spawn)
		{
			dx = -dx;

			dy = -(dy + rand() % 2);

			b[i].bar_hp--;
			if (b[i].bar_hp <= 0){
				b[i].bar_spawn = false;
				count++;
			}
		}

		if (((ball_x >= b[i].bar_x - 50 && ball_x <= b[i].bar_x) && (ball_y >= b[i].bar_y)) && b[i].bar_spawn)
		{
			dx = dx;

			dy = -(dy + rand() % 2);

			b[i].bar_hp--;
			if (b[i].bar_hp <= 0){
				b[i].bar_spawn = false;
				count++;
			}
		}
		
	}
	if ((ball_x >= 600 || ball_x <= 0) && ball_y >= 0)
		dx = -dx;
	if (ball_y >= 400){
		dy = -dy;
	}
	
}
void setVariable(){
	for (int i = 0; i < 20; i++){
		b[i].bar_x = 0 + distance_x;
		b[i].bar_y = 300 + distance_y;
		b[i].bar_w = 120;
		b[i].bar_h = 20;
		b[i].bar_hp = 1;
		b[i].bar_spawn = true;

		if (i % 5 != 0){
			distance_x = distance_x + b[i].bar_w;
		}
		if (i > 0 && i % 5 == 0){
			distance_y = distance_y + b[i].bar_h;
			distance_x = 0;
		}
	}
}
int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(600, 400, "Project Title");

	 balltimer = iSetTimer(30, ballchange);

	setVariable();

	///updated see the documentations
	iStart();
	return 0;
}
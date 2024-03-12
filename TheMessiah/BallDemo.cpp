# include "iGraphics.h"

int ball1_x = 100, ball1_y = 100,ball2_x = 200,ball2_y = 200;
int dx, dy;
int balltimer_1,balltimer_2;

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();

    iSetColor(255, 100, 10);
	iFilledCircle(ball1_x, ball1_y, 7);
    iFilledCircle(ball2_x, ball2_y, 7);
	iSetColor(255, 255, 255);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(balltimer_1);
       	iResumeTimer(balltimer_2);

	}
	if(key == 'r')
	{
		iResumeTimer(balltimer_1);
        iPauseTimer(balltimer_2);

	}
	//place your codes for other keys here
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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

void ballChange1(){
	ball1_x += dx;
	ball1_y += dy;

	if(ball1_x > 400 || ball1_x < 0)dx = -dx;
	if(ball1_y > 400 || ball1_y < 0)dy = -dy;
}

void ballChange2(){
	ball2_x += dx;
	ball2_y += dy;

	if(ball2_x > 400 || ball2_x < 0)dx = -dx;
	if(ball2_y > 400 || ball2_y < 0)dy = -dy;
}


int main()
{
	//place your own initialization codes here.
	balltimer_1 = iSetTimer(5, ballChange1);
	balltimer_2 = iSetTimer(5, ballChange2);

	dx = 5;
	dy = 7;
	iInitialize(400, 400, "Ball Demo");
    iStart();
	return 0;
}


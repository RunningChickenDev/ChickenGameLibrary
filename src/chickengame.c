/*
 * chickengame.c
 *
 *  Created on: 7 mrt. 2017
 *      Author: MisterCavespider
 */

#define TIMER_ID 0

#include "fxlib.h"
#include "timer.h"
#include <stdio.h>

int frame = 0;
float fps = 30;
float tpf = 0;

int running = 0;
int idle = 0;

void calcTpf();

//Called at the end of a timer
void onFrame() {
	frame ++;
	idle = 1;
}

void calcTpf() {
	tpf = (float)(1.0/fps);
}

void run() {
	running = 1;
	idle = 1;

	start();

	while (running)
	{
		if(idle)
		{
			idle = 0;
			calcTpf();
			loop(tpf);
			SetTimer(ID_USER_TIMER1, (int)(1000/fps), &onFrame);
		}
	}

	clean();
}

void kill()
{
	running = 0;
}

void getFrameCount(unsigned int *p)
{
	*p = frame;
}

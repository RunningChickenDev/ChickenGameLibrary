/*
 * chickengame.c
 *
 *  Created on: 7 mrt. 2017
 *      Author: MisterCavespider
 */

#define TIMER_ID 0

#include "fxlib.h"

int frame = 0;
float fps = 60;
float tpf = 0;

int running = 1;
int idle = 0;

void calcTpf();

//Called at the end of a timer
void onFrame() {
	idle = 1;
	frame ++;
}

void calcTpf() {
	tpf = (float)(1.0/fps);
}

void run() {

	start();

	while (running)
	{
		if(idle)
		{
			SetTimer(TIMER_ID, (int)(1000/60), &onFrame);
			calcTpf();
			loop(tpf);
		}
	}

	clean();
}

void kill()
{
	running = 0;
}

/*
 * chickengame.h
 *
 *  Created on: 7 mrt. 2017
 *      Author: MisterCavespider
 */

#ifndef CHICKENGAME_H_
#define CHICKENGAME_H_

#include "chickenpoints.h"
#include "chickengraphics.h"

extern int frame;
extern float fps;

void onFrame();

void run();
void start();
void loop(float tpf);
void clean();
void kill();

#endif /* CHICKENGAME_H_ */

/*
 * chickenpoints.c
 *
 *  Created on: 7 mrt. 2017
 *      Author: MisterCavespider
 */

#include <math.h>
#include "chickenpoints.h"

/*C (LANG)*/
Point Point_Create(int x, int y) {
	struct point n = {0,0};
	n.x = x;
	n.y = y;
	return n;
}

/*MATH*/
/**+**/
Point Point_add(Point *a, Point *b) {
	int xtot = a->x + b->x;
	int ytot = a->y + b->y;
	return Point_Create(xtot, ytot);
}

void Point_add_local(Point *a, Point *b) {
	a->x += b->x;
	a->y += b->y;
}

/**-**/
Point Point_sub(Point *a, Point *b) {
	int xtot = a->x - b->x;
	int ytot = a->y - b->y;
	return Point_Create(xtot, ytot);
}

void Point_sub_local(Point *a, Point *b) {
	a->x -= b->x;
	a->y -= b->y;
}

/*SPACE*/
double Point_distance(Point *a, Point *b) {
	double dist;
	int deltaX = a->x - b->x;
	int deltaY = a->y - b->y;

	dist = sqrt( pow((double) deltaX,2) + pow((double) deltaY,2) );
	return dist;
}

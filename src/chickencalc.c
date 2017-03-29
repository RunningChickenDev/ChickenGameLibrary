/*
 * chickenVectors.c
 *
 *  Created on: 7 mrt. 2017
 *      Author: MisterCavespider
 */

#include <stdlib.h>
#include <math.h>
#include "chickencalc.h"

/*C (LANG)*/
void Vector_create(vector_t *store, float x, float y) {
	struct vector v = {0,0};
	v.x = x;
	v.y = y;
	*store = v;
}

vector_t Vector_creater(float x, float y)
{
	vector_t v;
	Vector_create(&v,x,y);
	return v;
}

int Vector_compare_y(const void * a, const void * b)
{
	return ( ((vector_t*)a)->y - ((vector_t*)b)->y );
}

void Vector_sort_by_y(void* base, int num)
{
	//qsort(base, num, sizeof(Vector), Vector_Create);
}

//Math
//+
vector_t Vector_add(vector_t a, vector_t b)
{
	return Vector_creater(a.x + b.x, a.y + b.y);
}

void Vector_addLoc(vector_t a, vector_t b) {
	a.x += b.x;
	a.y += b.y;
}

//-
vector_t Vector_sub(vector_t a, vector_t b) {
	return Vector_creater(a.x - b.x, a.y - b.y);
}

void Vector_subLoc(vector_t a, vector_t b)
{
	a.x -= b.x;
	a.y -= b.y;
}

//SPACE
void Vector_distance(float *store, vector_t a, vector_t b) {
	float deltaX = a.x - b.x;
	float deltaY = a.y - b.y;

	*store = sqrt( pow((double) deltaX,2) + pow((double) deltaY,2) );
}

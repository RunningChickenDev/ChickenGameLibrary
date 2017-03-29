/*
 * chickenpoints.h
 *
 *  Created on: 7 mrt. 2017
 *      Author: MisterCavespider
 */

#ifndef CHICKENCALC_H_
#define CHICKENCALC_H_

/*CREATES THE STRUCT*/
struct vector {
	float x;
	float y;
};
/*LET'S "vector_t" BE THE TYPE OF THE STRUCT*/
typedef struct vector vector_t;

/*C (LANG)*/
void Vector_create(vector_t *v, int x, int y);
vector_t Vector_creater(int x, int y);
int Vector_compare_y(const void * a, const void * b);

//MATH
vector_t Vector_add(vector_t a, vector_t b);
void Vector_addLoc(vector_t a, vector_t b);
vector_t Vector_sub(vector_t a, vector_t b);
void Vector_subLoc(vector_t a, vector_t b);

//SPACE
void Vector_distance(float *store, vector_t a, vector_t b);

#endif

/*
 * chickenpoints.h
 *
 *  Created on: 7 mrt. 2017
 *      Author: MisterCavespider
 */

#ifndef CHICKENPOINTS_H_
#define CHICKENPOINTS_H_

/*CREATES THE STRUCT*/
struct point {
	int x;
	int y;
};
/*LET'S "Point" BE THE TYPE OF THE STRUCT*/
typedef struct point Point;

/*C (LANG)*/
Point Point_Create(int x, int y);
int Point_compare_y(const void * a, const void * b);

/*MATH*/
/**+**/
Point Point_add(Point *a, Point *b);
void Point_add_local(Point *a, Point *b);
/**-**/
Point Point_sub(Point *a, Point *b);
void Point_sub_local(Point *a, Point *b);

/*SPACE*/
double Point_distance(Point *a, Point *b);
void Point_distance_store(double *store, Point *a, Point *b);

#endif

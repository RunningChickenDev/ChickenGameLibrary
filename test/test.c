/*
 * test.c
 *
 *  Created on: 7 mrt. 2017
 *      Author: MisterCavespider
 */

#include <stdio.h>
#include "chickengame.h"

void print_point(Point p);

void graphics_test();
void point_test();

int main(int argc, char **argv) {

	graphics_test();

	return 0;
}

void graphics_test() {
	printf("%d", SQUARE_AREA);

	DrawH_flatbottom_triangle(Point_Create(10,20), Point_Create(1,1), Point_Create(30, 1));
}

void point_test() {
	Point a = Point_Create(1,2);
	Point b = Point_Create(2,1);
	Point c;
	print_point(a);
	print_point(b);

	c = Point_add(&a,&b);
	print_point(c);

	Point_add_local(&a, &b);
	print_point(a);

	double distance = Point_distance(&a,&b);
	printf("d: %f\n", distance);
}

void print_point(Point p) {
	printf("%d, %d\n", p.x, p.y);
}

/*
 * chickengraphics.h
 *
 *  Created on: 8 mrt. 2017
 *      Author: MisterCavespider
 */

#ifndef CHIKCENGRAPHICS_H_
#define CHIKCENGRAPHICS_H_

#define SQUARE_AREA		0
#define SQUARE_POLYGON	1

/*
 * "Draw" is used for general draw functions.
 * "DrawH" is used not meant for external use,
 * but are helper functions.
 */

void Draw_line(Point a, Point b);
void Draw_point(Point p);
void Draw_triangle(Point a, Point b, Point c);
void Draw_square(Point a, Point b, int type);
void Draw_area(Point a, Point b);
void Draw_polygon(Point* p_arr);

/* Sorted */
void DrawH_flattop_triangle(Point v1, Point v2, Point v3);
void DrawH_flatbottom_triangle(Point v1, Point v2, Point v3);

void Grphcs_update_DD();

#endif

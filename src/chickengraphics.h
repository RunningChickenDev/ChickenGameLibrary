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

void Draw_line(vector_t a, vector_t b);
void Draw_point(vector_t p);
void Draw_valpoint(vector_t p, int val);
void Draw_triangle(vector_t a, vector_t b, vector_t c);
void Draw_square(vector_t a, vector_t b, int type);
void Draw_area(vector_t a, vector_t b);
void Draw_polygon(vector_t* p_arr);

/*
 * More complicated draws.
 * Sprites may be structs one day.
 */

void Draw_sprite(vector_t a, unsigned int *sprite, int xl, int yl);

/* Sorted */
void DrawH_flattop_triangle(vector_t v1, vector_t v2, vector_t v3);
void DrawH_flatbottom_triangle(vector_t v1, vector_t v2, vector_t v3);

void Grphcs_update();
void Grphcs_clr();

#endif

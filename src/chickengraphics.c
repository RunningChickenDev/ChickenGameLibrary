/*
 * chickengraphics.c
 *
 *  Created on: 8 mrt. 2017
 *      Author: MisterCavespider
 */

#include "fxlib.h"
#include "chickenpoints.h"
#include "chickengraphics.h"

void Draw_line(vector_t a, vector_t b)
{
	Bdisp_DrawLineVRAM(a.x, a.y, b.x, b.y);
}

void Draw_point(vector_t p)
{
	if(p.x < 0 || p.x > 127 || p.y < 0 || p.y > 63) {
		return;
	}

	Bdisp_SetPoint_VRAM(p.x, p.y, 1);
}

void Draw_valpoint(vector_t p, int val) {
	if(Bdisp_GetPoint_VRAM != 0 && val != 0) {
		Draw_point(p);
	}
}

void Draw_triangle(vector_t a, vector_t b, vector_t c)
{

}

void Draw_square(vector_t a, vector_t b, int type)
{
	switch(type) {
	case SQUARE_AREA:
		break;
	case SQUARE_POLYGON:
		if(a.y > b.y) {
			DrawH_flattop_triangle(a,b,Vector_creater(a.x, b.y));
			DrawH_flatbottom_triangle(b,a,Vector_creater(b.x, a.y));
		} else {
			DrawH_flattop_triangle(b,a,Vector_creater(b.x,a.y));
			DrawH_flatbottom_triangle(a,b,Vector_creater(a.x, b.y));
		}
		break;
	}
}

void Draw_area(vector_t a, vector_t b)
{

}

void Draw_polygon(vector_t* p_arr)
{

}

void DrawH_flattop_triangle(vector_t v1, vector_t v2, vector_t v3)
{
	int scanLine = 0;

	float slope1 = (float) ((float) (v1.x - v2.x)) / ((float) (v1.y - v2.y));	/*Delta x , Delta y*/
	float slope2 = (float) ((float) (v1.x - v3.x)) / ((float) (v1.y - v3.y));	/*Delta x , Delta y*/

	float curx1 = (float) v2.x;
	float curx2 = (float) v3.x;

	for(scanLine = (int)v2.y; scanLine < (int)v1.y; scanLine++)
	{
		Bdisp_DrawLineVRAM((int) curx1, scanLine, (int) curx2, scanLine);
		curx1 += slope1;
		curx2 += slope2;
	}

	Bdisp_SetPoint_DD(v1.x, v1.y, 1);
}

void DrawH_flatbottom_triangle(vector_t v1, vector_t v2, vector_t v3)
{
	int scanLine = 0;

	float slope1 = (float) ((float) (v1.x - v2.x)) / ((float) (v1.y - v2.y));	/*Delta x , Delta y*/
	float slope2 = (float) ((float) (v1.x - v3.x)) / ((float) (v1.y - v3.y));	/*Delta x , Delta y*/

	float curx1 = (float) v2.x;
	float curx2 = (float) v3.x;

	for(scanLine = v2.y; scanLine > v1.y; scanLine--)
	{
		Bdisp_DrawLineVRAM((int) curx1, scanLine, (int) curx2, scanLine);
		curx1 -= slope1;
		curx2 -= slope2;
	}

	Bdisp_SetPoint_DD(v1.x, v1.y, 1);
}

void Draw_sprite(vector_t a, unsigned int *sprite, int xl, int yl) {
	int val = 0;
	int i = 0;
	int xoff;
	int yoff;
	vector_t d = Vector_creater(0,0);

	for(yoff = 0; yoff < yl; yoff++)
	{
		for(xoff = 0; xoff < xl; xoff++)
		{
			d.x = a.x + xoff;
			d.y = a.y + yoff;

			i = xoff + xl * yoff;
			val = (sprite[i / 16] >> i % 16) & 1;

			Draw_valpoint(d, val);
		}
	}
}

void Grphcs_update()
{
	Bdisp_PutDisp_DD();
}

void Grphcs_clr()
{
	Bdisp_AllClr_VRAM();
}

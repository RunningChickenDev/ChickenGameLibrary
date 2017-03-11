/*
 * chickengraphics.c
 *
 *  Created on: 8 mrt. 2017
 *      Author: MisterCavespider
 */

#include "fxlib.h"
#include "chickenpoints.h"
#include "chickengraphics.h"

void Draw_line(Point a, Point b)
{
	Bdisp_DrawLineVRAM(a.x, a.y, b.x, b.y);
}

void Draw_point(Point p)
{
	Bdisp_SetPoint_VRAM(p.x, p.y, 1);
}

void Draw_triangle(Point a, Point b, Point c)
{
	if(b.y == c.y)
	{
		/* Trivial cases */
		if(a.y > b.y)
		{
			DrawH_flattop_triangle(a, b, c);
		} else if(a.y < b.y)
		{
			DrawH_flatbottom_triangle(a, b, c);
		}
	} else {

	}
}

void Draw_square(Point a, Point b, int type)
{
	switch(type) {
	case SQUARE_AREA:
		break;
	case SQUARE_POLYGON:
		if(a.y > b.y) {
			DrawH_flattop_triangle(a,b,Point_Create(a.x, b.y));
			DrawH_flatbottom_triangle(b,a,Point_Create(b.x, a.y));
		} else {
			DrawH_flattop_triangle(b,a,Point_Create(b.x,a.y));
			DrawH_flatbottom_triangle(a,b,Point_Create(a.x, b.y));
		}
		break;
	}
}

void Draw_area(Point a, Point b)
{

}

void Draw_polygon(Point* p_arr)
{

}

void DrawH_flattop_triangle(Point v1, Point v2, Point v3)
{
	int scanLine = 0;

	float slope1 = (float) ((float) (v1.x - v2.x)) / ((float) (v1.y - v2.y));	/*Delta x , Delta y*/
	float slope2 = (float) ((float) (v1.x - v3.x)) / ((float) (v1.y - v3.y));	/*Delta x , Delta y*/

	float curx1 = (float) v2.x;
	float curx2 = (float) v3.x;

	for(scanLine = v2.y; scanLine < v1.y; scanLine++)
	{
		Bdisp_DrawLineVRAM((int) curx1, scanLine, (int) curx2, scanLine);
		curx1 += slope1;
		curx2 += slope2;
	}

	Bdisp_SetPoint_DD(v1.x, v1.y, 1);
}

void DrawH_flatbottom_triangle(Point v1, Point v2, Point v3)
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

void Grphcs_update_DD()
{
	Bdisp_PutDisp_DD();
}

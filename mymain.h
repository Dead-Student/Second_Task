#pragma once

#pragma warning(disable : 4996)
#include "framework.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "Resource.h"
#include "targetver.h"

#define MAX_LOADSTRING 100
#define IDT_TIMER1 101

typedef struct {
	short x, y;
}MyPoint;

void DrawLine(HDC hdc, MyPoint a, MyPoint b);
void prc(HDC hhdc, MyPoint a, MyPoint b, int curlvl, int targetlvl);

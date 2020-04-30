#include "mymain.h"


void DrawLine(HDC hdc, MyPoint a, MyPoint b)
{
    if ((a.x || a.y) && (b.y || b.x))
    {
        MoveToEx(hdc, a.x, a.y, NULL);
        LineTo(hdc, b.x, b.y);
    }
}


void prc(HDC hhdc, MyPoint a, MyPoint b, int curlvl, int targetlvl)
{
    MyPoint N1, N2, N3, N4, K1, K2, K3, K4;
    if (targetlvl - curlvl) {

        K1.x = (short)((b.x - a.x) / 3) + a.x;
        K1.y = (short)((b.y - a.y) / 3) + a.y;

        N2.x = (short)((b.x - a.x) / 3) + a.x;
        N2.y = (short)((b.y - a.y) / 3) + a.y;

        K3.x = (short)(((b.x - a.x) / 3) * 2 + a.x);
        K3.y = (short)(((b.y - a.y) / 3) * 2 + a.y);

        N4.x = (short)((b.x - a.x) / 3) * 2 + a.x;
        N4.y = (short)((b.y - a.y) / 3) * 2 + a.y;

        K2.x = (short)((N4.x - K1.x) * 0.5 - (N4.y - K1.y) * (-0.866) + K1.x);
        K2.y = (short)((N4.x - K1.x) * (-0.866) + (N4.y - K1.y) * 0.5 + K1.y);

        N3.x = (short)(((N4.x - K1.x) * 0.5) - ((N4.y - K1.y) * (-0.866)) + K1.x);
        N3.y = (short)(((N4.x - K1.x) * (-0.866)) + ((N4.y - K1.y) * 0.5) + K1.y);

        prc(hhdc, a, K1, curlvl + 1, targetlvl);
        prc(hhdc, N2, K2, curlvl + 1, targetlvl);
        prc(hhdc, N3, K3, curlvl + 1, targetlvl);
        prc(hhdc, N4, b, curlvl + 1, targetlvl);
    }
    else {
        DrawLine(hhdc, a, b);
        Ellipse(hhdc, a.x + 3, a.y + 3, a.x - 3, a.y - 3);
        Ellipse(hhdc, b.x + 3, b.y + 3, b.x - 3, b.y - 3);
    }
}

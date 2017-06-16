#include <windows.h>

#include <time.h>

//http://www.winprog.org/tutorial/simple_window.html

const wchar_t g_szClassName[] = L"myWindowClass";



void Circle(HDC hDC, double cx, double cy, double r)

{

	Ellipse(hDC, (int)(cx - r), (int)(cy - r), (int)(cx + r), (int)(cy + r));

}



void rCircle(HDC hDC, double cx, double cy, double r)

{

	Circle(hDC, cx, cy, r);

	if (r<5.0)

	{

		return;

	}

	double nuR = r / 2.0;

	double nuX, nuY;

	nuX = cx;

	nuY = cy - nuR;

	rCircle(hDC, nuX, nuY, nuR);

	nuX = cx;

	nuY = cy + nuR;

	rCircle(hDC, nuX, nuY, nuR);

	nuX = cx - nuR;

	nuY = cy;

	rCircle(hDC, nuX, nuY, nuR);

	nuX = cx + nuR;

	nuY = cy;

	rCircle(hDC, nuX, nuY, nuR);

}

void DrawDie(HDC hdc, int x, int y, double size, int value, int dieRed, int dieGreen, int dieBlue, int spotRed, int spotGreen, int SpotBlue)

{
	HPEN hThinRedPen;

	HBRUSH hBlueBrush,hOtherBrush;
	hBlueBrush = CreateSolidBrush(RGB(spotRed, spotGreen, SpotBlue));
	hOtherBrush = CreateSolidBrush(RGB((dieRed ), (dieGreen ), (dieBlue)));

	hThinRedPen = CreatePen(PS_SOLID, 1, RGB(dieRed, dieGreen, dieBlue));
	SelectObject(hdc, hBlueBrush);
	SelectObject(hdc, hThinRedPen);


	Rectangle(hdc, (int)(x - (size / 2)), (int)(y - (size / 2)), (int)(x + (size / 2)), (int)(y + (size / 2)));
	SelectObject(hdc,hOtherBrush);
	double cx = x;

	double cy = y;

	double r = size / 10.0;

	if (value == 1)

	{

		Circle(hdc, cx, cy, r);

	}

	else if (value == 2)

	{

		Circle(hdc, (cx - size / 4), (cy - size / 4), r);

		Circle(hdc, (cx + size / 4), (cy + size / 4), r);

	}

	else if (value == 3)

	{

		Circle(hdc, (cx - size / 4), (cy - size / 4), r);

		Circle(hdc, (cx + size / 4), (cy + size / 4), r);

		Circle(hdc, cx, cy, r);

	}

	else if (value == 4)

	{

		Circle(hdc, (cx + size / 4), (cy + size / 4), r);

		Circle(hdc, (cx - size / 4), (cy - size / 4), r);

		Circle(hdc, (cx - size / 4), (cy + size / 4), r);

		Circle(hdc, (cx + size / 4), (cy - size / 4), r);

	}

	else if (value == 5)

	{

		Circle(hdc, (cx + size / 4), (cy + size / 4), r);

		Circle(hdc, (cx - size / 4), (cy - size / 4), r);

		Circle(hdc, (cx - size / 4), (cy + size / 4), r);

		Circle(hdc, (cx + size / 4), (cy - size / 4), r);

		Circle(hdc, cx, cy, r);

	}

	else if (value == 6)

	{

		Circle(hdc, (cx - size / 4), cy, r);

		Circle(hdc, (cx - size / 4), (cy - size / 4), r);

		Circle(hdc, (cx - size / 4), (cy + size / 4), r);

		Circle(hdc, (cx + size / 4), cy, r);

		Circle(hdc, (cx + size / 4), (cy - size / 4), r);

		Circle(hdc, (cx + size / 4), (cy + size / 4), r);



	}



}

// Step 4: the Window Procedure

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)

{

	srand((unsigned int)time(NULL));

	static int x = 150;

	static int y = 150;

	static double size = 100;

	static int value = 1;
	static int value2 = 2;
	static int value3 = 3;
	static int value4 = 4;
	static int value5 = 5;
	
	static int evenNum = 0;

	static bool drawEllipse = false;

	static int red1 = 155;
	static int green1 = 10;
	static int blue1 = 18;

	static int redCircle = 5;
	static int greenCircle = 40;
	static int blueCircle = 180;

	static int redDie1 = 3;
	static int greenDie1 = 196;
	static int blueDie1 = 200;

	static int redCircle1 =15 ;
	static int greenCircle1 = 89;
	static int blueCircle1 = 123;

	static int redDie2 = 18;
	static int greenDie2 = 120;
	static int blueDie2 = 59;

	static int redCircle2 = 115;
	static int greenCircle2 = 79;
	static int blueCircle2 = 93;

	static int redDie3 = 181;
	static int greenDie3 = 10;
	static int blueDie3 = 229;

	static int redCircle3 = 57;
	static int greenCircle3 = 39;
	static int blueCircle3 = 193;

	static int redDie4 = 11;
	static int greenDie4 = 110;
	static int blueDie4 = 29;

	static int redCircle4 = 27;
	static int greenCircle4 = 139;
	static int blueCircle4 = 113;

	static int redDie5 = 151;
	static int greenDie5 = 30;
	static int blueDie5 = 219;

	PAINTSTRUCT ps;

	HDC hdc;

	HFONT hFont;

	switch (msg)

	{

	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);

		hFont = CreateFont(60, 0, 0, 0, 0, FALSE, 1, 0, 0, 0, 0, 0, 0, L"Arial");

		SelectObject(hdc, hFont);

		DrawDie(hdc, x, y, size, value,redDie1, greenDie1,blueDie1,redCircle,greenCircle,blueCircle);
		DrawDie(hdc, x + 150, y, size, value2, redDie2, greenDie2, blueDie2, redCircle1, greenCircle1, blueCircle1);
		DrawDie(hdc, x + 300, y, size, value3, redDie3, greenDie3, blueDie3, redCircle2, greenCircle2, blueCircle2);
		DrawDie(hdc, x + 450, y, size, value4, redDie4, greenDie4, blueDie4, redCircle3, greenCircle3, blueCircle3);
		DrawDie(hdc, x + 600, y, size, value5, redDie5, greenDie5, blueDie5, redCircle4, greenCircle4, blueCircle4);

		evenNum = 0;

		if (value == 2 || value == 4 || value == 6)
		{
			evenNum += 1;
		}
		if (value2 == 2 || value2 == 4 || value2 == 6)
		{
			evenNum += 1;
		}
		if (value3 == 2 || value3 == 4 || value3 == 6)
		{
			evenNum += 1;
		}
		if (value4 == 2 || value4 == 4 || value4 == 6)
		{
			evenNum += 1;
		}
		if (value5 == 2 || value5 == 4 || value5 == 6)
		{
			evenNum += 1;
		}



		if (drawEllipse)

		{

			Ellipse(hdc, (int)(x - (size / 2)), (int)(y - (size / 2)), (int)(x + (size / 2)), (int)(y + (size / 2)));

		}

		else

		{

				/*Rectangle(hdc, (int)(x - (size / 2)), (int)(y - (size / 2)), (int)(x + (size / 2)), (int)(y + (size / 2)));

			double cx = x;

			double cy = y - (size / 4.0);

			double r = size / 4.0;

			SelectObject(hdc, hOtherBrush);

			Circle(hdc, cx, cy, r);*/
		}

		RECT rect;

		rect.left = 100;

		rect.top = 300;

		rect.right = 400;

		rect.bottom = 500;

		if (evenNum == 0)
		{
			DrawText(hdc, L"there are no even die", -1, &rect, DT_WORDBREAK | DT_CENTER);
		}
		if (evenNum == 1)
		{
			DrawText(hdc, L"there is one even die", -1, &rect, DT_WORDBREAK | DT_CENTER);
		}
		if (evenNum == 2)
		{
			DrawText(hdc, L"there are two even dice", -1, &rect, DT_WORDBREAK | DT_CENTER);
		}
		if (evenNum == 3)
		{
			DrawText(hdc, L"there are three even dice", -1, &rect, DT_WORDBREAK | DT_CENTER);
		}
		if (evenNum == 4)
		{
			DrawText(hdc, L"there are four even dice", -1, &rect, DT_WORDBREAK | DT_CENTER);
		}
		if (evenNum == 5)
		{
			DrawText(hdc, L"there are five even dice", -1, &rect, DT_WORDBREAK | DT_CENTER);
		}

		//Uncomment the next line to see an example of graphic recursion

		//rCircle(hdc, 400.0, 275.0, 275.0);

		DeleteObject(hFont);

		EndPaint(hwnd, &ps);

		break;

	case WM_CHAR:

		if (wParam == 'e')

		{

			drawEllipse = true;

		}

		else if (wParam == 'r')

		{

			drawEllipse = false;

		}

		else if (wParam == 'c')

		{

			redCircle = rand() % 256;
			greenCircle = rand() % 256;
			blueCircle = rand() % 256;

			redDie1 = rand() % 256;
			greenDie1 = rand() % 256;
			blueDie1 = rand() % 256;

			redCircle1 = rand() % 256;
			greenCircle1 = rand() % 256;
			blueCircle1 = rand() % 256;

			redDie2 = rand() % 256;
			greenDie2 = rand() % 256;
			blueDie2 = rand() % 256;

			redCircle2 = rand() % 256;
			greenCircle2 = rand() % 256;
			blueCircle2 = rand() % 256;

			redDie3 = rand() % 256;
			greenDie3 = rand() % 256;
			blueDie3 = rand() % 256;

			redCircle3 = rand() % 256;
			greenCircle3 = rand() % 256;
			blueCircle3 = rand() % 256;

			redDie4 = rand() % 256;
			greenDie4 = rand() % 256;
			blueDie4 = rand() % 256;

			redCircle4 = rand() % 256;
			greenCircle4 = rand() % 256;
			blueCircle4 = rand() % 256;

			redDie5 = rand() % 256;
			greenDie5 = rand() % 256;
			blueDie5 = rand() % 256;

		}

		InvalidateRect(hwnd, NULL, true);

		break;

	case WM_KEYDOWN:

		if (wParam == VK_RIGHT)

		{

			x += 3;


		}

		else if (wParam == VK_LEFT)

		{

			x -= 3;


		}

		else if (wParam == VK_UP)

		{

			y -= 3;


		}

		else if (wParam == VK_DOWN)

		{

			y += 3;

			
		}

		else if (wParam == VK_SPACE)

		{

			value = rand() % 6 + 1;
			value2 = rand() % 6 + 1;
			value3 = rand() % 6 + 1;
			value4 = rand() % 6 + 1;
			value5 = rand() % 6 + 1;


		}

		else if (wParam == VK_PRIOR)

		{

			size *= 1.05;


		}

		else if (wParam == VK_NEXT)

		{

			size /= 1.05;

		}

		InvalidateRect(hwnd, NULL, true);

		break;

	case WM_CLOSE:

		DestroyWindow(hwnd);

		break;

	case WM_DESTROY:

		PostQuitMessage(0);

		break;

	default:

		return DefWindowProc(hwnd, msg, wParam, lParam);

	}

	return 0;

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,

	LPSTR lpCmdLine, int nCmdShow)

{

	WNDCLASSEX wc;

	HWND hwnd;

	MSG Msg;

	//Step 1: Registering the Window Class

	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = 0;

	wc.lpfnWndProc = WndProc;

	wc.cbClsExtra = 0;

	wc.cbWndExtra = 0;

	wc.hInstance = hInstance;

	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	wc.lpszMenuName = NULL;

	wc.lpszClassName = g_szClassName;

	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))

	{

		MessageBox(NULL, L"Window Registration Failed!", L"Error!",

			MB_ICONEXCLAMATION | MB_OK);

		return 0;

	}

	// Step 2: Creating the Window

	hwnd = CreateWindowEx(

		WS_EX_CLIENTEDGE,

		g_szClassName,

		L"David Dorneau",

		WS_OVERLAPPEDWINDOW,

		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,

		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)

	{

		MessageBox(NULL, L"Window Creation Failed!", L"Error!",

			MB_ICONEXCLAMATION | MB_OK);

		return 0;

	}

	ShowWindow(hwnd, nCmdShow);

	UpdateWindow(hwnd);

	// Step 3: The Message Loop

	while (GetMessage(&Msg, NULL, 0, 0) > 0)

	{

		TranslateMessage(&Msg);

		DispatchMessage(&Msg);

	}

	return Msg.wParam;

}



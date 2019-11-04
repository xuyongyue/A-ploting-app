#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include<locale.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include <process.h>

void paixu(float* a, int n, int*b)
{
	int g = 0, l = 0;
	float v[100] = { 0 };
	for (g = 0; g<n; g++)
		v[g] = a[g];
	int x = 0, y = 0;
	float a1 = 0, b1 = 0;
	for (x = 0; x<n - 1; x++)
	{
		for (y = 0; y<n - 1; y++)
		{
			if (v[y]>v[y + 1])
			{
				a1 = v[y];
				v[y] = v[y + 1];
				v[y + 1] = a1;

			}
		}
	}
	for (x = 0; x<n; x++)
		for (y = 0; y<n; y++)
		{
			if (v[x] == a[y])
				b[x] = y;
		}
	for (x = 0; x<n; x++)
		printf("%f  ", a[b[x]]);

}
float qmin (float* a,int n)
{
	int x = 0, y = 0,z=0;
	float k= a[0];
	for (x = 0; x < n; x++)
		if (a[x] < k)
			k = a[x];
	return k;
}
float qmax(float* a, int n)
{
	int x = 0, y = 0, z = 0;
	float k = a[0];
	for (x = 0; x < n; x++)
		if (a[x] > k)
			k = a[x];
	return k;
}
float pingjun(float* a,int b)
{
	int x = 0;
	float y = 0;
	for (x = 0; x < b; x++)
		y = y + a[x];
	y = y / b;
	return y;
}
float var(float* a, int b)
{
	if (b == 1)
		return 0;
	int m = 0, n = 0;
	float x = pingjun(a, b),y=0;
	for (m = 0; m < b; m++)
		y = y + pow((a[m] - x), 2);
	y = y / (b - 1);
	return y;

}
int stow(float a, char* b)
{
	int m = 0, n = 0, z = 0, k = 0, p = 0, u = 0;
	if (a < 0)
	{
		a = -a;
		m = 1;
	}
	if (a == 0)
	{
		b[0] = '0';
		return 0;
	}
	float a1 = 0;
	a1 = a;
	int x = 0, y = 0;
	if (a >= 1)
		while (a1 >= 1)
		{
			a1 = a1 / 10;
			x++;

		}
	if (a<1)
		while (a1 <1)
		{
			a1 = a1 * 10;
			y++;
		}
	int j = 0;
	if (a - (int)a == 0)
		j = 1;
	while ((a - (int)a))
	{
		a = a * 10;
		n++;

	}
	if (x > 0)
		z = n + x;

	else z = n;
	//printf("%d\n", z);
	if (m > 0)
	{
		b[p] = '-';
		p++;
	}
	if (y > 0)
	{
		b[p] = '0';
		p++;
		b[p] = '.';
		p++;
	}
	k = (int)a;
	int e = 1, r = 0;
	while (z>0)
	{
	//	outtextxy(0,  5,"o");
		printf("%d\n", k);
		for (r = 0; r<z - 1; r++)
			e = e * 10;
		b[p] = k / e + '0';
		k = k%e;
		p++;
		z--;
		u++;
		if (u == x&&j==0)
		{
			b[p] = '.';
			p++;
		}
		e = 1;
	}
}
float wtos(char*a)
{
	float x = 0;
	int y = 0,z=0,m=0,n=strlen(a)-1;
	if (a[0] == '-')
		m = 1;
	for (y = 0;( a[y] < 58 && a[y]>47)||a[y]=='.'||a[y]=='-'; y++)
	{
		if(a[y]!='.'&&a[y]!='-')
		x = x * 10 + a[y] - '0';
		else n = y;
	}
	for (y = 0; y < strlen(a) - 1 - n; y++)
		x = x / 10;
	if (m)
		x = -x;
	return x;
}
int wtos1(char*a,float *b)
{
	char a1[500][ 200] = { '\0' };
	int x = 0, y = 0,m=0,n=0,k=0;
	for (x = 0; x < strlen(a); x++)
	{
		if ((a[x] > 47 && a[x] < 58) || a[x] == '.' || a[x] == '-')
		{
			a1[m][n] = a[x];
			k = 1;
			n++;
		}
		else
			if (k == 1)
			{
				m++;
				n = 0;
				k = 0;
			}		
	}
	for (x = 0; a1[x][0] != '\0'; x++)
	{
		b[x] = wtos(a1[x]);
	}
	return x;
}
void alpha(float level, float mean, int shu,float var, float* qujian)
{
	FILE*fp = fopen("nn.txt", "r");
	char a[30000] = { '\0' };
	char b = ' ';
	int g = 0, o = 0;
	while (b != EOF)
	{
		b = getc(fp);
		if (b == '\n')
			b = ',';
		a[g] = b;
		g++;
	}
	float x[400] = { 0 };
	wtos1(a, x);
	g = 0;
	for (g = 0; g < 300; g++)
		if (level /2 +0.5<= x[g])
			break;
	g = g / 100;
	qujian[0] = mean + g* sqrt(var) / sqrt(shu);
	qujian[1] = mean -g* sqrt(var) / sqrt(shu);
}
float xiefang(float* a,float *b, int n)
{
	float c[2000] = { 0 };
	int x = 0;
	float x1 = 0, y = 0, z = 0;
	for (x = 0; x < n; x++)
		c[x] = a[x] * b[x];
	y = pingjun(c, n) - pingjun(a, n)*pingjun(b, n);
	z = y / sqrt(var(a, n)*(n - 1) / n*var(b, n)*(n - 1) / n);
	return z;
}
float qkmao(float* x, float* y, int n)
{
	int m = 0;
	float z = 0, k = 0,i=0;
	float xb = pingjun(x, n), yb = pingjun(y, n);
	for (m = 0; m < n; m++)
	{
		z = z + (x[m] - xb)*(y[m] - yb);
		k = k + (x[m] - xb)*(x[m] - xb);
	}
	i = z / k;
	return i;
}
float qbmao(float* x, float* y, int n)
{
	float a = 0, b = 0, c = 0, d = 0;
	a = pingjun(x, n);
	b = qkmao(x, y, n);
	c = pingjun(y, n);
	d = c - b*a;
	return d;
}
void charubeijing(IMAGE img)
{
	loadimage(&img, "首页.jpg", 900, 500, true);
	putimage(0, 0, &img);
}
void charubeijing4(IMAGE img)
{
	loadimage(&img, "04.jpg", 900, 500, true);
	putimage(0, 0, &img);
}
void xianshi(void)
{
	outtextxy(600, 50,  "1   2   3 ");
	outtextxy(600, 130, "4   5   6 ");
	outtextxy(600, 210, "7   8   9");
	outtextxy(600, 290, "0   .   -");
	outtextxy(600, 370, "<       ok");
	outtextxy(600, 450, ">");
	outtextxy(700, 420, "返回");
}
int anniu(int x1, int x2, int y1, int y2, MOUSEMSG m)
{
	if (m.uMsg == WM_LBUTTONUP&&m.x > x1 && m.x < x2 && m.y>y1 && m.y < y2)
		return 1;
	else return 0;
}
int fanhui(MOUSEMSG m)
{

	if (anniu(700, 740, 420, 460, m))
		return 1;
	else return 0;
}
void charubeijing2(IMAGE img)
{
	loadimage(&img, "03.jpg", 900, 500, true);
	putimage(0, 0, &img);
}
void shuzi(char yzf[20][200], float bianliang[20][200], char bianliangming[20][20], MOUSEMSG m, int x, int y)
{
	char xx;
	int shu5 = 0;
	settextstyle(40, 0, "宋体");
	outtextxy(40, 20, "1    2    3 ");
	outtextxy(40, 80, "4    5    6 ");
	outtextxy(40, 140, "7    8    9");
	outtextxy(40, 200, "0    .    -");
	outtextxy(40, 260, "<          ");
	outtextxy(40, 320, ">         next");
	outtextxy(700, 420, "返回");
	outtextxy(700, 350, "finish");
	settextstyle(25, 0, "微软雅黑");
	outtextxy(400, 20, "变量1");
	outtextxy(500, 20, "变量2");
	outtextxy(600, 20, "变量3");
	while (1)
	{
		m = GetMouseMsg();
		int shu1 = 0, shu2 = 0, shu3 = 0, shu4 = 10,shu6=0;///提前设好x=0,y=0;
		if (anniu(680,940,300,400,m))
		{
			y++;
			yzf[y][0] = 'o';
			yzf[y][1] = 'v';
			yzf[y][2] = 'e';
			yzf[y][3] = 'r';
			y++;
			break;
		 }
		settextstyle(25, 0, "微软雅黑");
		
		if (m.uMsg == WM_LBUTTONUP)
		{
			shu1 = m.x / 100;
			shu2 = m.y / 60;
			shu3 = shu2 * 3 + shu1 + 1;
			if (shu1 < 3 && shu2 < 7)
			{
				if (shu3 == 10)
					yzf[y][x++] = '0';
				if (shu3 <= 9)
					yzf[y][x++] = shu3 + 48;
			if (shu3 == 13)
				{
					yzf[y][x - 1] = '\0';
					x--;
					IMAGE img;
					charubeijing2(img);
					settextstyle(40, 0, "宋体");
					outtextxy(40, 20, "1    2    3 ");
					outtextxy(40, 80, "4    5    6 ");
					outtextxy(40, 140, "7    8    9");
					outtextxy(40, 200, "0    .    -");
					outtextxy(40, 260, "<          ");
					outtextxy(40, 320, ">         next");
					outtextxy(700, 420, "返回");
					outtextxy(700, 350, "finish");

					settextstyle(25, 0, "微软雅黑");
					outtextxy(420, 20, "变量1");
					outtextxy(520, 20, "变量2");
					outtextxy(620, 20, "变量3");
					

				}
			if (shu3 == 18)
			{
				y++;
				yzf[y][0] = 'o';
				yzf[y][1] = 'v';
				yzf[y][2] = 'e';
				yzf[y][3] = 'r';
				y++;
				x = 0;
			}
				if (shu3 == 16)
				{
				x = 0;
				y++;
				}
				if (shu3 == 11)
					yzf[y][x++] = '.';
				if (shu3 == 12)
					yzf[y][x++] = '-';
		//	if (shu3 == 18)
		//			break;
				settextstyle(25, 0, "微软雅黑");
				shu5 = 0, shu6 = 0;
				for (shu4 = 0; shu4 <=y; shu4++)
				{
					shu6++;
					outtextxy(420 + shu5 * 100, 20 + shu6 * 30, yzf[shu4]);
					if (strcmp(yzf[shu4], "over") == 0)
						shu5++, shu6 = 0;
				}
			}
		}
	}
}



int main(void)
{
	float level = 0.95;
chushi:int x = 0, xuanze = 0, renyi = 0;
	char le[10] = { '\0' };
	stow(level, le);
	FILE* fp2;
	char yzf[200][200] = { '\0' }, yzf2[200][200] = { '\0' }, bianliangming[20][20] = { '\0' };
	float bianliang[200][200] = { 0 };
	time_t t;
	t = time(NULL);
	char *time;//定义一个字符串用来保存获取到的日期和时间
	time = ctime(&t);//赋值
	int xx1 = 0, yy1 = 0;
	FILE * fp1;
	fp1 = fopen("历史.txt", "a");
	fp2 = fopen("see.txt", "w+");
	MOUSEMSG m;
	initgraph(900, 500);
	IMAGE img;
	charubeijing(img);
	//setlocale(LC_ALL, "chs");//解决中文乱码，在头文件locale.h中
	settextstyle(40, 0, "微软雅黑");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);/*处理文字后面的黑色，使文字后的背景为图片*/
	outtextxy(650, 100, "新建向量");
	outtextxy(650, 200, "历史向量");
	outtextxy(650, 300, "联系作者");
	outtextxy(650, 400, "说明（必读）");
	settextstyle(30, 0, "微软雅黑");
	outtextxy(50, 400, "许永跃 161140064 TEL：15720613859");
	char tupian[200][200] = { '\0' };
	int tu = 0;
	for (tu = 0; tu < 200; tu++)
		strcat(tupian[tu], "D:\\\\o");
	
	while (1)
	{
		m = GetMouseMsg();
		if (anniu(640, 820, 390, 450, m))
			xuanze = 4;
		if (anniu(640, 820, 290, 350, m))
			xuanze = 3;
		if (anniu(640, 820, 190, 250, m))
			xuanze = 2;
		if (anniu(640, 820, 90, 150, m))
			xuanze = 1;
		if (xuanze != 0)
			break;
	}
	x = 0;
	int y = 0;
	settextstyle(40, 0, "宋体");
	settextcolor(BLUE);
	if (xuanze == 2)
		system("notepad 历史.txt");
	if (xuanze == 4)
	{
		int g333 = 0;
		settextstyle(20, 0, "宋体");
		charubeijing2(img);
		outtextxy(50, 50, "新建变量可以通过鼠标和输入框，当变量较多或单个变量很长时");
		outtextxy(50, 80, "建议使用输入框输入，注意输入时变量名称与元素及元素与元素");
		outtextxy(50, 110, "之间用逗号或空格分开。由于显示窗口太小的问题，出现位数过");
		outtextxy(50, 140, "长的数字可能导致屏幕混乱，此时可通过记事本查看计算结果。");
		outtextxy(50, 170, "每次启动程序置信水平默认为0.95，点击下方可对其进行修改：");

		char le2[10] = { '\0' };
		settextstyle(40, 0, "宋体");
		outtextxy(700, 420, "返回");
		outtextxy(50, 260, "置信水平：");
		outtextxy(50, 330, "点击此处修改");
		while (1)
		{

			stow(level, le2);
			outtextxy(560, 260 + g333 * 40, le2);
			m = GetMouseMsg();
			if (anniu(45, 290, 320, 370, m))
			{
				InputBox(le2, 30, "修改置信水平", "输入", "0.95", 300, 200, false);
				level = wtos(le2);
				g333++;
			}
			if (fanhui(m))
				goto chushi;

		}
	}
	if (xuanze == 3)
	{
		charubeijing2(img);
		outtextxy(50, 100, "许永跃");
		outtextxy(50, 160, "16 生科 应用");
		outtextxy(50, 220, "161140064");
		outtextxy(50, 260, "xyywd123@163.com TEL：15720613859");
		outtextxy(700, 420, "返回");
		while (1)
		{
			m = GetMouseMsg();
			if (fanhui(m))
				goto chushi;
		}

	}
	if (xuanze == 1)
	{
		charubeijing2(img);
		settextstyle(40, 0, "宋体");
		outtextxy(50, 100, "请选择输入方式：");
		outtextxy(50, 160, "1、输入框输入");
		outtextxy(50, 220, "2、鼠标输入");
		outtextxy(700, 420, "返回");
		while (1)
		{
			m = GetMouseMsg();
			if (anniu(40, 220, 200, 250, m))
			{
				xuanze = 12;
				break;
			}
			if (anniu(40, 220, 150, 200, m))
			{
				xuanze = 11;
				break;
			}
			if (fanhui(m))
				goto chushi;
		}
		charubeijing2(img);
		settextstyle(40, 0, "宋体");
		if (xuanze == 11)
		{
			outtextxy(40, 60, "点击此处添加新向量");
			outtextxy(700, 420, "返回");
			outtextxy(20, 420, "完成");
			while (1)
			{
				m = GetMouseMsg();
				if (anniu(0, 400, 40, 120, m))
				{
					InputBox(yzf2[renyi], 400, "向量名 元素1，元素2，.... 示例：x 1,2,3,4", "输入向量", "x 1,2,3", 500, 400, false);
					renyi++;
					settextstyle(30, 0, "宋体");
					outtextxy(100, 100 + 40 * renyi, yzf2[renyi - 1]);
					settextstyle(40, 0, "宋体");
				}
				if (fanhui(m))
					goto chushi;
				if (anniu(10, 110, 410, 480, m))
					break;

			}
		}
		int renyi2 = 0, renyi3 = 0;
		int bianliangshu[20];
		if (xuanze == 12)
			shuzi(yzf, bianliang, bianliangming, m, x, y);

		if (xuanze == 11)
		{
			for (renyi = 0; yzf2[renyi][0] != '\0'; renyi++)
			{
				for (renyi2 = 0; yzf2[renyi][renyi2] > 47 && yzf2[renyi][renyi2] < 123; renyi2++)
				{
					bianliangming[renyi][renyi2] = yzf2[renyi][renyi2];
					xx1++;
				}
				yy1++;
				xx1 = 0;
				bianliangshu[renyi] = wtos1(yzf2[renyi], bianliang[renyi]);
			}
			yy1 = 0;
		}
		xx1 = 0;
		if (xuanze == 12)
		{

			char m1 = '0';
			for (renyi = 0; yzf[renyi][0] != '\0'; renyi++)
			{
				bianliangming[xx1][0] = 'x';
				bianliangming[xx1][1] = m1 + 1;
				if (strcmp(yzf[renyi], "over") != 0)
				{
					bianliang[xx1][yy1] = wtos(yzf[renyi]);
					yy1++;
				}
				if (strcmp(yzf[renyi], "over") == 0)
				{
					m1++;
					bianliangshu[xx1] = yy1;
					xx1++;
					yy1 = 0;
					//		renyi++;
				}
			}

		}
		xx1 = 0;
		charubeijing4(img);
		float junzhi[20] = { 0 };
		float fangcha[20] = { 0 };
		float qujian[10] = { 0 };
		char qujianz[10][20] = { '\0' };
		float shi = qbmao(bianliang[0], bianliang[1], bianliangshu[0]);
		settextstyle(40, 0, "宋体");
		outtextxy(700, 420, "返回");
		settextstyle(20, 0, "宋体");
		outtextxy(50, 300, "线性");
		outtextxy(50, 400, "用记事本查看");
		outtextxy(460, 5, "平均值");
		outtextxy(550, 5, "方差");
		outtextxy(640, 5, "mu置信上限");
		outtextxy(750, 5, "下限");
		setlinecolor(BLACK);
		line(450, -100, 450, 1000);
		char bianliangzi[200][20] = { '\0' };
		yy1 = 0;
		char biaohao[20][30] = { '\0' };
		biaohao[0][0] = '1';
		for (yy1 = 0; yy1 < 5; yy1++) {
			outtextxy(90 + yy1 * 60, 5, biaohao[0]);
			biaohao[0][0]++;

		}
		yy1 = 0;
		while (bianliangming[xx1][0] != '\0')
		{
			line(540, 0, 540, 55 + xx1 * 30);
			line(630, 0, 630, 55 + xx1 * 30);
			if (xx1 < 8)
			{
				outtextxy(50, 30 + xx1 * 30, bianliangming[xx1]);
				line(40, 25 + xx1 * 30, 900, 25 + xx1 * 30);
			}
			if (xx1 == 8)
				outtextxy(50, 30 + xx1 * 40, "...");
			//	if(xx1<=5)
			//	outtextxy(70 + xx1 * 80, 300, bianliangming[xx1]);
			//	if (xx1 > 5)
			//		outtextxy(70 + (xx1-5 )* 80, 340, bianliangming[xx1]);
			for (yy1 = 0; yy1 < bianliangshu[xx1]; yy1++)
				stow(bianliang[xx1][yy1], bianliangzi[yy1]);
			fputs(bianliangming[xx1], fp1);
			fputs(": ", fp1);
			fputs(bianliangming[xx1], fp2);
			fputs(": ", fp2);
			for (yy1 = 0; yy1 < bianliangshu[xx1]; yy1++)
			{
				if (yy1 < 5)
					outtextxy(90 + yy1 * 60, 30 + xx1 * 30, bianliangzi[yy1]);
				if (yy1 == 5)
					outtextxy(90 + yy1 * 60, 30 + xx1 * 30, "...");
				if (yy1 <= 5)
					line(85 + yy1 * 60, 0, 85 + yy1 * 60, 55 + xx1 * 30);
				fputs(bianliangzi[yy1], fp1);
				fputs("  ", fp1);
				fputs(bianliangzi[yy1], fp2);
				fputs("  ", fp2);
			}
			fputs(time, fp1);
			fputs("\n", fp1);

			junzhi[xx1] = pingjun(bianliang[xx1], bianliangshu[xx1]);
			fangcha[xx1] = var(bianliang[xx1], bianliangshu[xx1]);
			alpha(level, junzhi[xx1], bianliangshu[xx1], fangcha[xx1], qujian);
			stow(qujian[0], qujianz[0]);
			stow(qujian[1], qujianz[1]);
			stow(junzhi[xx1], biaohao[0]);
			stow(fangcha[xx1], biaohao[1]);
			fputs(" 均值 ：", fp2);
			fputs(biaohao[0], fp2);
			fputs("   方差：", fp2);
			fputs(biaohao[1], fp2);
			fputs("   mu置信上限： ", fp2);
			fputs(qujianz[0], fp2);
			fputs("   mu置信下限： ", fp2);
			fputs(qujianz[1], fp2);
			fputs("   置信水平：", fp2);
			fputs(le, fp2);
			fputs("\n", fp2);
			outtextxy(455, 30 + xx1 * 30, biaohao[0]);
			outtextxy(545, 30 + xx1 * 30, biaohao[1]);
			outtextxy(640, 30 + xx1 * 30, qujianz[0]);
			outtextxy(750, 30 + xx1 * 30, qujianz[1]);
			for (renyi3 = 0; renyi3 < 600; renyi3++)
				biaohao[0][renyi3] = '\0';
			renyi3 = 0;
			xx1++;
		}
		yy1 = 0;
		while (1)
		{
			m = GetMouseMsg();
			if (anniu(40, 160, 390, 450, m))
			{
				fclose(fp2);
				renyi = 56;
				system("notepad see.txt");
			}
			if (anniu(40, 100, 290, 350, m))
			{
				xuanze = 13;
				break;
			}

			if (fanhui(m))
				goto chushi;
		}
		fclose(fp1);
		fclose(fp2);
		if (xuanze == 13)
		{
			float tu1 = 0;
		bian:		charubeijing4(img);
			settextstyle(40, 0, "宋体");
			outtextxy(700, 420, "返回");/////////////////////////////////////////////////接下来可以画图了
			if (renyi == 56)
				fp2 = fopen("see.txt", "r+");
			xx1 = 0;
			yy1 = 0;
			renyi = 0;
			float xief = 0;
			char xiefangchaz[200][40] = { '\0' };
			char bmaoz[20][40] = { '\0' };
			char bmaoz2[20][40] = { '\0' };
			float bmao[20][40] = { 0 };
			char kmaoz[20][40] = { '\0' };
			float kmao[20][40] = { 0 };
			float bianlianggeshu = 0;
			settextstyle(20, 0, "宋体");
			while (bianliangming[xx1][0] != '\0')
			{
				bianlianggeshu++;
				outtextxy(50, 30, "自变量");
				outtextxy(10, 50, "因变量");
				line(10, 90 + xx1 * 90, 700, 90 + xx1 * 90);
				line(120 + xx1 * 140, 0, 120 + xx1 * 140, 400);

				outtextxy(180 + xx1 * 140, 30, bianliangming[xx1]);
				outtextxy(30, 130 + xx1 * 90, bianliangming[xx1]);
				for (yy1 = 0; bianliangming[yy1][0] != '\0'; yy1++)
				{
					if (bianliangshu[xx1] == bianliangshu[yy1])
					{
						xief = xiefang(bianliang[xx1], bianliang[yy1], bianliangshu[xx1]);
						stow(xief, xiefangchaz[renyi]);
						outtextxy(140 + xx1 * 140, 95 + yy1 * 90, xiefangchaz[renyi]);
						outtextxy(120 + xx1 * 140, 95 + yy1 * 90, "c:");

						bmao[xx1][yy1] = qbmao(bianliang[xx1], bianliang[yy1], bianliangshu[0]);
						stow(bmao[xx1][yy1], bmaoz2[renyi]);
						outtextxy(140 + xx1 * 140, 120 + yy1 * 90, bmaoz2[renyi]);
						outtextxy(120 + xx1 * 140, 120 + yy1 * 90, "b:");

						kmao[xx1][yy1] = qkmao(bianliang[xx1], bianliang[yy1], bianliangshu[xx1]);
						stow(kmao[xx1][yy1], kmaoz[renyi]);
						outtextxy(140 + xx1 * 140, 145 + yy1 * 90, kmaoz[renyi]);
						outtextxy(120 + xx1 * 140, 145 + yy1 * 90, "k:");
						renyi++;

					}

					else outtextxy(125 + xx1 * 140, 95 + yy1 * 90, "不对等");
				}
				xx1++;
			}
			settextstyle(40, 0, "宋体");
			outtextxy(700, 420, "返回");
			settextstyle(30, 0, "宋体");
			outtextxy(700, 300, ">直方图");
			outtextxy(700, 100, ">折线");
			settextstyle(20, 0, "宋体");
			while (1)
			{
				m = GetMouseMsg();
				if (anniu(700, 840, 290, 340, m))
				{
					xuanze = 131;
					outtextxy(700, 350, "请点击表格自变量栏对");
					outtextxy(700, 375, "应方格添加变量");
					break;
				}
				if (anniu(700, 840, 90, 140, m))
				{
					xuanze = 132;
					outtextxy(700, 150, "点此加自变量");
					outtextxy(700, 180, "点此加因变量");
					outtextxy(650, 210, "点击表格直接确定变量");
					outtextxy(700, 240, "输完点击此处");
					break;
				}

				if (fanhui(m))
					goto chushi;
			}
			char zibianliang[30] = { '\0' };
			char yinbianliang[30][30] = { '\0' };
			char luan[10];
			int zib = 0;
			int yinb[50] = { 0 };
			int yinbshu = 0;
			int fang = 0;
			int zg = 0, zg2 = 0;
			int flag = 0;
			xx1 = 0, yy1 = 0;
			int fang2=0,fang3=0;
			int zz1 = 0, kk1 = 0;
			while (1)
			{
				m = GetMouseMsg();
				if (xuanze == 131)
					if (m.uMsg == WM_LBUTTONUP&&m.y > 0 && m.y < 90 && m.x>120)
					{
						fang = (m.x - 120) / 140;
						xuanze = 1311;
						break;
					}
				if (xuanze == 132)
				{
					if (anniu(690, 820, 140, 170, m) && zg == 0)
					{
						InputBox(zibianliang, 40, "自变量名字 不要有空格 例：x1", "自变量", "x1", 300, 500, false);
						if (zibianliang[0] != '\0')
						{
							for (xx1 = 0; bianliangming[xx1][0] != '\0'; xx1++)
								if (strcmp(zibianliang, bianliangming[xx1]) == 0)
								{
									zg = 1;
									break;
									zib = xx1;
								}

							if (zg == 0)
							{
								InputBox(luan, 4, "输入错误！请关掉此窗口重新输入", "错误", "", 400, 400, true);
								for (zz1 = 0; zz1 < 30; zz1++)
									zibianliang[zz1] = '\0';
								zz1 = 0;
							}

						}
					}
					if (anniu(640, 890, 205, 250,m))
					{
						while (1)
						{

							m = GetMouseMsg();
							if (m.uMsg == WM_LBUTTONUP&&m.y > 90 && m.y < 90 + 90 * bianlianggeshu && m.x>120 && m.x < 120 + bianlianggeshu * 140)
							{
								fang2 = (m.x - 120) / 140;
								zib = fang2;
								fang3 = (m.y - 90) / 90;
								yinb[0] = fang3;
								yinbshu = 1;
								xuanze = 1321;
								break;
							}
							
							if (fanhui(m))
								goto bian;
							
						}
						if (yinbshu)
							break;
					}
				
					if (anniu(690, 820, 175, 200, m))
					{
						InputBox(yinbianliang[yy1], 40, "因变量名字 不要有空格 例：x2", "因变量", "x2", 300, 500, false);
						for (xx1 = 0; bianliangming[xx1] != '\0'; xx1++)
							if (strcmp(yinbianliang[yy1], bianliangming[xx1]) == 0)
							{
								yinb[kk1] = xx1;
								kk1++;
								yinbshu++;
								zg2 = 1;
								break;
							}

						if (zg2 == 0)
						{
							InputBox(luan, 4, "输入错误！请关掉此窗口重新输入", "错误", "", 400, 400, true);
							for (zz1 = 0; zz1 < 30; zz1++)
								zibianliang[zz1] = '\0';
							yinbshu--;
							zib = 0;
							zz1 = 0;
						}
						zg2 = 0;
						yy1++;
					}
					if (anniu(690, 900, 230, 280, m))
					{
						xuanze = 1321;
						break;
					}
				}



				if (fanhui(m))
					goto chushi;

			}
			charubeijing4(img);
			settextstyle(30, 0, "宋体");
			outtextxy(720, 430, "返回");
			xx1 = 0, yy1 = 0, zz1 = 0, kk1 = 0;
			int kk2 = 0, kk3 = 0;
			float pinshu[200] = { 0 };////要把之前的数组都扩大一些才好
			char zujuz[30] = { '\0' };
			float zuju = 0, maxm = 0, minm = 0, kuai = 0, biao = 0;
			char biaoz[400][40] = { '\0' };
			float jued = 0, zuixiao = 0, zuida = 0, jued2 = 0;
			if (xuanze == 1311)
			{
				settextstyle(30, 0, "宋体");
				outtextxy(250, 30, bianliangming[fang]);
				outtextxy(350, 30, "的频率分布直方图");
				line(115, 400, 115, 396);
				line(100, 100, 100, 400);
				line(100, 400, 700, 400);
				line(700, 400, 700, 396);
				line(100, 100, 98, 100);
				InputBox(zujuz, 4, "请输入组距", "组距", "", 400, 400, true);
				zuju = wtos(zujuz);
				maxm = qmax(bianliang[fang], bianliangshu[fang]);
				minm = qmin(bianliang[fang], bianliangshu[fang]);
				if (minm < 0)
				{
					jued = -minm;
					kk1 = 1;
				}
				else jued = minm;
				if (maxm < 0)
				{
					jued2 = -maxm;
					kk2 = 1;
				}
				else jued2 = maxm;
				while (xx1*zuju < jued)
					xx1++;
				if (kk1 == 1)
					zuixiao = -xx1*zuju;
				else zuixiao = (xx1 - 1)*zuju;
				xx1 = 0;
				while (xx1*zuju < jued2)
					xx1++;
				if (kk2 == 1)
					zuida = -(xx1 - 1)*zuju + zuju;
				else zuida = xx1*zuju + zuju;
				xx1 = zuixiao;
				kuai = ((zuida - zuixiao) / zuju);
				float kuai2 = 585 / kuai;
				settextstyle(15, 0, "宋体");
				biao = zuixiao;
				while (xx1 <= zuida + zuju)
				{
					for (kk3 = 0; kk3 < bianliangshu[fang]; kk3++)
						if ((bianliang[fang][kk3] - xx1) / zuju < 1 && (bianliang[fang][kk3] - xx1) / zuju >= 0)
							pinshu[zz1]++;
					line(115 + zz1*kuai2, 400, 115 + zz1*kuai2, 396);
					stow(xx1, biaoz[zz1]);
					if (xx1 <= zuida)
						outtextxy(110 + zz1*kuai2, 405, biaoz[zz1]);
					xx1 += zuju;
					zz1++;
				}
				setfillcolor(BLUE);
				float zuidas = qmax(pinshu, kuai);
				float gao = 0;
				char biaoz2[200][200] = { '\0' };
				zz1 = 0;
				setlinecolor(BLACK);
				while (zz1 < kuai)
				{
					gao = 300 * pinshu[zz1] / zuidas;
					setlinestyle(PS_DASH);
					if (gao != 400)
						line(100, 400 - gao, 115 + (zz1 + 1)*kuai2, 400 - gao);
					stow(pinshu[zz1], biaoz2[zz1]);
					outtextxy(70, 400 - gao, biaoz2[zz1]);
					fillrectangle(115 + zz1*kuai2, 400 - gao, 115 + (zz1 + 1)*kuai2, 400);
					zz1++;
				}
				setlinestyle(PS_SOLID);


			}
			if (xuanze == 1321)
			{
				line(115, 400, 115, 396);
				line(100, 100, 100, 400);
				line(100, 400, 700, 400);
				line(700, 400, 700, 396);
				line(100, 100, 98, 100);
		//		
				settextstyle(15, 0, "宋体");
				float xxiao = qmin(bianliang[zib], bianliangshu[zib]), xda = qmax(bianliang[zib], bianliangshu[zib]), yxiao = qmin(bianliang[yinb[0]], bianliangshu[yinb[0]]), yda = qmax(bianliang[yinb[0]], bianliangshu[yinb[0]]), linshi = 0;
				for (xx1 = 0; xx1 < yinbshu; xx1++)
				{
					if (bianliangshu[zib] != bianliangshu[yinb[xx1]])
					{
						InputBox(luan, 4, "错误！元素个数不一致", "错误", "", 400, 400, true);
						goto bian;
					}
					linshi = qmin(bianliang[yinb[xx1]], bianliangshu[yinb[xx1]]);
					if (yxiao > linshi)
						yxiao = linshi;
					linshi = qmax(bianliang[yinb[xx1]], bianliangshu[yinb[xx1]]);
					if (yda < linshi)
						yda = linshi;
					
				}
				float xzuobiao[100] = { 0 };
				float yzuobiao[100][100] = { 0 };
				char biaoz1[200][200] = { '\0' };
				char biaoz2[200][200] = { '\0' };

				int uu = 0, uu1 = 0, uu3 = 0,uu4=0 ,pai[100] = {0};
				paixu(bianliang[zib], bianliangshu[zib], pai);
				for (uu3 = 0; uu3 < bianliangshu[zib]; uu3++)
				{
					xx1 = pai[uu3];
					if (uu3 > 0)
						uu4 = pai[uu3 - 1];
					xzuobiao[xx1] = 115 + 585 * (bianliang[zib][xx1] - xxiao) / (xda - xxiao);
					for (yy1 = 0; yy1 < yinbshu; yy1++)
					{
						yzuobiao[yy1][xx1] = 385 - 285* (bianliang[yinb[yy1]][xx1] - yxiao) / (yda - yxiao);
						stow(bianliang[yinb[yy1]][xx1], biaoz1[uu]);
						
						if (yy1 == 0)
						{
							setlinecolor(RED);
							setfillcolor(RED);
						}
							
						if (yy1 == 1)
						{
							setlinecolor(BLUE);
							setfillcolor(BLUE);
						}
						if (yy1 == 2)
						{
							setlinecolor(GREEN);
							setfillcolor(GREEN);
						}
						outtextxy(40, yzuobiao[yy1][0],bianliangming[yinb[yy1]]);
						outtextxy(70, yzuobiao[yy1][xx1], biaoz1[uu]);
						fillcircle(xzuobiao[xx1], yzuobiao[yy1][xx1],3);
						setlinestyle(PS_DASH);
						line(115, 385 - 285 * (qbmao(bianliang[zib],bianliang[yinb[yy1]], bianliangshu[zib])+ xxiao*qkmao(bianliang[zib], bianliang[yinb[yy1]], bianliangshu[zib]) -yxiao )/ (yda - yxiao), 700, 385 - 285 * (qkmao(bianliang[zib], bianliang[yinb[yy1]], bianliangshu[zib])*(xda) + bmao[zib][yinb[yy1]] - yxiao)/(yda-yxiao));
						setlinestyle(PS_SOLID);
						line(100, yzuobiao[yy1][xx1], 96, yzuobiao[yy1][xx1]);
						uu++;
						if (uu3 > 0)
							line(xzuobiao[uu4], yzuobiao[yy1][uu4], xzuobiao[xx1], yzuobiao[yy1][xx1]);
					}
					line(xzuobiao[xx1],400, xzuobiao[xx1], 396 );
					stow(bianliang[zib][xx1], biaoz2[uu1]);
					outtextxy( xzuobiao[xx1], 415,biaoz2[uu1]);
					uu1++;
				}



			}
			while (1)
			{
				m = GetMouseMsg();
				if (fanhui(m))
				{
					tu1++;
					int tu3 = (int)tu1;
					char tu2[100] = { '\0' };
					stow(tu1, tu2);
					strcat(tupian[tu3], tu2);
					
					strcat(tupian[tu3], ".bmp");
				//	outtextxy(200, 420, tupian[tu3]);
					saveimage(tupian[tu3]);
				//	getchar();
					goto bian;
				}
			}
		}

	}

	getch();
	closegraph();
	return 0;
}
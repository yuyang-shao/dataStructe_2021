#undef UNICODE
#undef _UNICODE
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)//防止vs2019报错，使程序顺利运行
//#pragma comment(lib,"Winmm.lib")
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <mmsystem.h>
//#include<string.h>
#include<windows.h>
#include <string>
#include <ctime>

#define width 800
#define height 799//游戏画面尺寸
#define width1 200  //景点图片尺寸
#define height1 200
#define Infinity 20000//约定【2000】代表无穷大，即不连通
#define MaxVertexNum 20//约定最多设置20个顶点（景点）
#define MAX 40 
#define key 13//默认顶点数为13
#define lock 20//默认边数为20
#define MaxMidNum 5//约定最多设置5个中间点（景点）
#define MaxRow 120 //约定全排列行数最多为120（即5！）

IMAGE map, BenedictionTemple, dinosaur, Geopark, hualuogeng, white,
joyland, maoshan, museum, NewFourthArmy, SilverNoodles, TianmuLake, tianningTemple, yancheng, NanshanBambooSea;

typedef struct vexsinfo//顶点（景点）结构体
{
	char name[32];//名称 
	int position;//代号
	char introduction[256];//简介---功能菜单5 
	char super_introduction[512];//详细介绍---功能菜单6 
	int x;  //景点坐标
	int y;
}vexsinfo;

typedef struct arcell//边（路径）结构体
{
	int adj;//权值  
}arcell, adjmatrix[MaxVertexNum][MaxVertexNum];//邻接矩阵

typedef struct mgraph//图结构体
{
	vexsinfo vexs[MaxVertexNum];//顶点数组 
	adjmatrix arcs;//邻接矩阵 
	int vexnum, arcnum;//顶点（vertex）数和边（arc）数 
}mgraph;

void dfs(mgraph* c, int a, int b);
void allroad(mgraph c);
void swap(int* a, int* b);
void allRange(int* a, int k, int len);      //实现全排列
int shortestpath_dij(mgraph c, int v0, int Vend, int isdraw);
int PathMidNode(mgraph c, int i, int n, int isdraw);
void finalShortest(mgraph c);
void floyd(mgraph c);
void display(mgraph c, int i, int j);
void DrawPath();
void DrawPath();
int locatevex(mgraph c, int v);
void creatgraph(mgraph* c);
int delvex(mgraph* c);
int delarc(mgraph* c);
void printmatrix(mgraph c);
void Changegraph();
void Query(mgraph c);
void Outputtext();
void drawCircle(mgraph c);
void MOUSE_Picture();
int shortestpath_dij(mgraph c, int v0, int Vend, int isdraw);
int envex(mgraph* c);
int enarc(mgraph* c);

//全局变量

int shortest[MaxVertexNum][MaxVertexNum];//最短路径 
int pathh[MaxVertexNum][MaxVertexNum];
int rangeArray[MaxRow][MaxMidNum];
int visited[MaxVertexNum] = { 0 };
int road[MaxVertexNum];
int m = 1;
mgraph changzhou; //常州图
//初始化图形系统

mgraph initgraph()
{
	int i = 0, j = 0;
	mgraph c;
	c.vexnum = key;  //顶点数
	c.arcnum = lock;  //边数

	//设置景点代号
	for (i = 1; i <= key; i++)
		c.vexs[i].position = i;

	//string copy顶点信息 ，景点的名称，详细介绍，简介
	strcpy(c.vexs[1].name, "茅山风景区");
	strcpy(c.vexs[1].super_introduction, "\n茅山风景区：茅山形胜独特，风景秀丽，2001年被列为国家AAAA级旅游区\n");
	strcpy(c.vexs[1].introduction, "金陵地肺名山");

	strcpy(c.vexs[2].name, "银丝面");
	strcpy(c.vexs[2].super_introduction, "\n银丝面：面细如丝，色白似银，柔软滑爽，富有韧性，下锅不糊\n");
	strcpy(c.vexs[2].introduction, "地方传统面食小吃");

	strcpy(c.vexs[3].name, "华罗庚纪念馆");
	strcpy(c.vexs[3].super_introduction, "\n河苑：套餐，盖浇饭，汉堡可乐，蛋炒饭，粥，包子，馒头，应有尽有，满足你的胃。\n");
	strcpy(c.vexs[3].introduction, "美食中心");

	strcpy(c.vexs[4].name, "中华曙猿地质公园");
	strcpy(c.vexs[4].super_introduction, "\n中华曙猿地质公园：规划区域包括长荡湖湿地及水母山遗址，是中华曙猿化石的发现地\n");
	strcpy(c.vexs[4].introduction, "省级湿地公园");

	strcpy(c.vexs[5].name, "报恩禅寺");
	strcpy(c.vexs[5].super_introduction, "\n报恩禅寺：报恩禅寺毗邻传奇色彩的“水漫金山”的“金山寺”，长寿福地的“南山”\n");
	strcpy(c.vexs[5].introduction, "佛门圣地");

	strcpy(c.vexs[6].name, "天目湖度假区");
	strcpy(c.vexs[6].super_introduction, "\n天目湖：位于常州溧阳市南八公里处，因属天目山余脉，故名“天目湖”。\n");
	strcpy(c.vexs[6].introduction, "“江南明珠”、“绿色仙境”");

	strcpy(c.vexs[7].name, "南山竹海");
	strcpy(c.vexs[7].super_introduction, "\n南山竹海：景区以竹文化和寿文化为主题，坐拥3.5万亩翠竹。\n");
	strcpy(c.vexs[7].introduction, "天堂南山，梦幻竹海");

	strcpy(c.vexs[8].name, "中国春秋淹城旅游区");
	strcpy(c.vexs[8].super_introduction, "\n中国春秋淹城旅游区：是中国最为古老也最为完整的地面城池遗址\n");
	strcpy(c.vexs[8].introduction, "地面城池遗址");

	strcpy(c.vexs[9].name, "环球动漫嬉戏谷");
	strcpy(c.vexs[9].super_introduction, "\n环球动漫嬉戏谷：从未有过的、神秘未知的、超越现实的“奇幻世界”带入现实的主题乐园\n");
	strcpy(c.vexs[9].introduction, "动漫艺术、游戏文化");

	strcpy(c.vexs[10].name, "常州博物馆");
	strcpy(c.vexs[10].super_introduction, "\n常州博物馆：是集收藏、研究、陈列展览于一体的地方综合性博物馆\n");
	strcpy(c.vexs[10].introduction, "国家一级博物馆");

	strcpy(c.vexs[11].name, "环球恐龙城");
	strcpy(c.vexs[11].super_introduction, "\n环球恐龙城：一家融展示、科普、娱乐、休闲及参与性表演于一体的恐龙为主题的一站式旅游度假区.\n");
	strcpy(c.vexs[11].introduction, "旅游度假区");

	strcpy(c.vexs[12].name, "天宁禅寺");
	strcpy(c.vexs[12].super_introduction, "\n天宁禅寺：是常州现存规模最大，保存最完整的千年古刹\n");
	strcpy(c.vexs[12].introduction, "中国禅宗四大丛林");

	strcpy(c.vexs[13].name, "新四军江南指挥部纪念馆");
	strcpy(c.vexs[13].super_introduction, "\n新四军江南指挥部纪念馆：是一个在中国革命史和军事史上都有重要地位的地方\n");
	strcpy(c.vexs[13].introduction, "指挥部旧址");

	//确定景点的坐标
	c.vexs[1].x = 145;
	c.vexs[1].y = 238;//茅山

	c.vexs[2].x = 200;
	c.vexs[2].y = 330;//银丝面

	c.vexs[3].x = 330;
	c.vexs[3].y = 285;//华罗庚纪念馆

	c.vexs[4].x = 320;
	c.vexs[4].y = 445;//中华曙猿地质公园

	c.vexs[5].x = 170;
	c.vexs[5].y = 640;//报恩禅寺

	c.vexs[6].x = 250;
	c.vexs[6].y = 640;//天目湖度假区

	c.vexs[7].x = 260;
	c.vexs[7].y = 750;//南山竹海

	c.vexs[8].x = 470;
	c.vexs[8].y = 320;//中国春秋淹城旅游区

	c.vexs[9].x = 650;
	c.vexs[9].y = 470;//环球动漫嬉戏谷

	c.vexs[10].x = 550;
	c.vexs[10].y = 230;//常州博物馆

	c.vexs[11].x = 630;
	c.vexs[11].y = 210;//环球恐龙城

	c.vexs[12].x = 620;
	c.vexs[12].y = 250;//天宁禅寺

	c.vexs[13].x = 160;
	c.vexs[13].y = 490; //新四军


	//初始化邻接矩阵，权值均为无穷大，即所有顶点互不相连
	for (i = 1; i <= key; i++)
		for (j = 1; j <= key; j++)
			c.arcs[i][j].adj = Infinity; //邻接矩阵权值无限大（2000）

	//规定顶点的连通情况并赋予边对应的权值，（点1，点2，边权）G[点1][点2] = weight 
	//联通两个景点，确定两景点间距离
	c.arcs[1][2].adj = 60;
	c.arcs[1][3].adj = 70;

	c.arcs[2][3].adj = 40;
	c.arcs[2][4].adj = 80;
	c.arcs[2][13].adj = 120;

	c.arcs[3][8].adj = 130;

	c.arcs[4][13].adj = 130;
	c.arcs[4][9].adj = 420;

	c.arcs[5][6].adj = 20;
	//c.arcs[5][7].adj = 60;


	c.arcs[6][7].adj = 70;

	//c.arcs[7][8].adj = 30;

	c.arcs[8][9].adj = 210;
	c.arcs[8][10].adj = 40;

	//c.arcs[9][10].adj = 35;
	//c.arcs[9][11].adj = 10;

	c.arcs[10][11].adj = 10;

	c.arcs[11][12].adj = 10;

	c.arcs[5][13].adj = 200;
	c.arcs[6][13].adj = 210;

	//无向图对称赋值
	for (i = 1; i <= key; i++)
	{
		for (j = 1; j <= key; j++)
		{
			c.arcs[j][i].adj = c.arcs[i][j].adj;
		}
		c.arcs[i][i].adj = 0;
	}
	return c;
}
//递归深度遍历所有A点到B点所有路径
//参考：https://www.ixueshu.com/document/b182fab31af30eb123354954e9327cd8318947a18e7f9386.html
void dfs(mgraph* c, int a, int b)            //递归遍历A点到B点所有路径
{
	visited[a] = 1;                //标记该点已经被访问
	int i, j, k = b;
	for (i = 1; i <= c->vexnum; i++)
	{
		if (c->arcs[a][i].adj < Infinity && visited[i] == 0)
		{
			if (i == b)
			{
				//				srand((unsigned)time( NULL ) );
				setlinestyle(0, 2);
				int x, y, z;                      //随机产生3个随机数
				x = int(rand() % 255);
				while (1)
				{
					y = int(rand() % 255);
					if (y != x)break;
				}
				while (1)
				{
					z = int(rand() % 255);
					if ((z != y) && (z != x))break;
				}
				setlinecolor(RGB(x, y, z));    //用不同颜色画出路径
				for (j = 0; j < m - 1; j++)
				{
					setlinestyle(0, 2);
					line(c->vexs[road[j]].x, c->vexs[road[j]].y, c->vexs[road[j + 1]].x, c->vexs[road[j + 1]].y);
				}
				line(c->vexs[road[m - 1]].x, c->vexs[road[m - 1]].y, c->vexs[b].x, c->vexs[b].y);
			}
			else
			{
				road[m] = i;             //road保存路径
				m++;
				dfs(c, i, k);                //递归
				visited[i] = 0;
				m--;
			}
		}
	}
}

//画两点之间所有路径
void allroad(mgraph c)
{
	putimage(0, 0, &white);
	drawCircle(changzhou);
	int i, j;
	char s1[10], s2[10];
	outtextxy(300, 100, _T("请输入要查询的两个景点的代号"));
	InputBox(s1, 10, _T("请输入起点"));
	// 将用户输入转换为数字
	sscanf(s1, "%d", &i);
	InputBox(s2, 10, _T("请输入终点"));
	// 将用户输入转换为数字
	sscanf(s2, "%d", &j);
	road[0] = i;
	dfs(&c, i, j);
}

//贪心+dij算法求经过指定中点的最短路径
//参考：https://wenku.baidu.com/view/034f89ad1eb91a37f1115cca.html
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void allRange(int* a, int k, int len)     //指针a表示中间点数组,len表示经过中间点个数
{

	int i;
	if (k == len)
	{
		static int s_i = 0;
		for (int j = 0; j <= len; j++)
		{
			rangeArray[s_i][j] = a[j];
		}
		s_i++;
	}
	else
	{
		for (i = k; i <= len; i++)
		{
			swap(a + i, a + k);
			allRange(a, k + 1, len);
			swap(a + i, a + k);
		}
	}

}  
//求两点之间最短路径
int shortestpath_dij(mgraph c, int v0, int Vend, int isdraw)
{
	int v, w, k = 1, min, t, p;
	int final[MaxVertexNum];//final[w]=1表示已经求得顶点V0到W的最短路径
	int Patharc[MaxVertexNum];//存放直接前驱
	int ShortPathtable[MaxVertexNum];//存储权值和

	//初始化
	for (v = 1; v <= c.vexnum; v++)
	{
		final[v] = 0;
		ShortPathtable[v] = c.arcs[v0][v].adj;
		Patharc[v] = v0;
	}

	ShortPathtable[v0] = 0;
	final[v0] = 1;

	//dij算法
	for (v = 2; v <= c.vexnum; v++)    //v从2开始而不是从1开始，每次循环求得v0与一个顶点的最短路径
	{

		min = Infinity;
		for (w = 1; w <= c.vexnum; w++)
		{
			if (!final[w] && ShortPathtable[w] < min)
			{
				k = w;
				min = ShortPathtable[w];
			}
		}
		final[k] = 1;

		//修正最短路径 
		for (w = 1; w <= c.vexnum; w++)
		{
			if (!final[w] && (min + c.arcs[k][w].adj < ShortPathtable[w]))
			{
				ShortPathtable[w] = min + c.arcs[k][w].adj;//修正路径长度
				Patharc[w] = k;//存放直接前驱

			}
		}
	}
	if (isdraw == 1)     //画出最短路径
	{
		t = Patharc[Vend];
		setlinecolor(RED);
		setlinestyle(0, 2);
	
		line(c.vexs[t].x, c.vexs[t].y, c.vexs[Vend].x, c.vexs[Vend].y);

		while (t != v0)
		{

			p = t;
			t = Patharc[t];
			
		 line(c.vexs[t].x, c.vexs[t].y, c.vexs[p].x, c.vexs[p].y);
		 
			
			
		}
//		line(c.vexs[v0].x, c.vexs[v0].y, c.vexs[t].x, c.vexs[t].y);

	}
	return ShortPathtable[Vend];
}

//求经过中间点集所有点的最短路径
int PathMidNode(mgraph c, int i, int n, int isdraw)   //i表示全排列矩阵的行数，n代表全排列矩阵的列数,n表示中间点的个数
{
	int dist = 0;    //dist代表经过中间点集所有点所要经过的距离
	int dis = 0;    //dis为将中点点集中每两点间的距离
	for (int j = 0; j < n - 1; j++)              //之所以小于n-1是因为j+1<=n-1
	{
		if (isdraw == 0)
		{
			dis = shortestpath_dij(changzhou, rangeArray[i][j], rangeArray[i][j + 1], 0);
		}
		if (isdraw == 1)
		{
			dis = shortestpath_dij(changzhou, rangeArray[i][j], rangeArray[i][j + 1], 1);
		}
		dist += dis;
	}
	return dist;
}

//求最终最短(经过指定中间点)
void finalShortest(mgraph c)
{

	putimage(0, 0, &white);
	drawCircle(changzhou);
	outtextxy(300, 100, _T("请输入要查询的两个景点的代号"));
	int i, j; //要查询的两个景点的代号
	int n, row = 1;    //n表示要经过的中间点数量(全排列矩阵列数）,row代表全排列行数
	int* a;
	//	int a[5];
	int path = Infinity, temp, road = -1, midPath;  //road 代表中点集的路线
	char s1[10], s2[10], s3[10];
	InputBox(s1, 10, _T("请输入起点"));
	// 将用户输入转换为数字
	sscanf(s1, "%d", &i);
	InputBox(s2, 10, _T("请输入终点"));
	// 将用户输入转换为数字
	sscanf(s2, "%d", &j);
	InputBox(s3, 10, _T("请输入需要经过的点数"));
	// 将用户输入转换为数字
	sscanf(s3, "%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (int d = 0; d < n; d++)
	{
		char s[10];
		InputBox(s, 10, _T("请输入中间点"));
		// 将用户输入转换为数字
		sscanf(s, "%d", &a[d]);
	}

	allRange(a, 0, n - 1);    //进行全排列

	for (int b = n; b > 0; b--)
	{
		row *= b;
	}
	for (int m = 0; m < row; m++)
	{
		midPath = PathMidNode(changzhou, m, n, 0);
		temp = shortestpath_dij(changzhou, i, rangeArray[m][0], 0) + midPath + shortestpath_dij(changzhou, rangeArray[m][n - 1], j, 0);   //0表示不划线
		if (temp < path)
		{
			path = temp;
			road = m;     //m代表全排列矩阵的第m行,第m种全排列

		}
	}
	shortestpath_dij(changzhou, i, rangeArray[road][0], 1);

	shortestpath_dij(changzhou, rangeArray[road][n - 1], j, 1);
	PathMidNode(changzhou, road, n, 1);
	char str[150];
	sprintf(str, "%s到%s的最短路径是:%dm", c.vexs[i].name, c.vexs[j].name, path);
	outtextxy(50, 50, str);
}

//33弗洛伊德算法
void floyd(mgraph c)
{
	int i, j, k;
	for (i = 1; i <= c.vexnum; i++)
	{
		for (j = 1; j <= c.vexnum; j++)
		{
			shortest[i][j] = c.arcs[i][j].adj;
			pathh[i][j] = j;//顶点i到顶点j的最短路径是经过j 
		}
	}

	printf("\n\n\n");

	//核心操作；算法参考网址：https://www.cnblogs.com/skywang12345/p/3711523.html 
	for (k = 1; k <= c.vexnum; k++)
	{
		for (i = 1; i <= c.vexnum; i++)
		{
			for (j = 1; j <= c.vexnum; j++)
			{
				if (shortest[i][j] > shortest[i][k] + shortest[k][j])
				{
					shortest[i][j] = shortest[i][k] + shortest[k][j];
					pathh[i][j] = pathh[i][k];
					//顶点i到顶点j的最短路径是经过k 
				}
			}
		}
	}
}
//33打印最短路径 
void display(mgraph c, int i, int j)
{
	int a, b, k;
	a = i;
	b = j;
	setlinecolor(RED);
	setlinestyle(0, 2);
	k = pathh[i][j];
	line(c.vexs[a].x, c.vexs[a].y, c.vexs[k].x, c.vexs[k].y);
	while (k != b)
	{
		//递归
		line(c.vexs[k].x, c.vexs[k].y, c.vexs[pathh[k][j]].x, c.vexs[pathh[k][j]].y);
		k = pathh[k][j];
	}
	//	line(c.vexs[pathh[i][j]].x, c.vexs[pathh[i][j]].y, c.vexs[b].x, c.vexs[b].y);
	//printf("%s-->%s的最短路径是：%d 米。\n\n", c.vexs[a].name, c.vexs[b].name, shortest[a][b]);
	char str[150];
	sprintf(str, "%s到%s的最短路径是:%dm", c.vexs[a].name, c.vexs[b].name, shortest[a][b]);
	outtextxy(0, 155, str);
}
//画最短路线
void DrawPath() {

	putimage(0, 0, &white);
	drawCircle(changzhou);
	Outputtext();
	outtextxy(0, 180, _T("请输入要查询的两个景点的代号"));
	int i, j; //要查询的两个景点的代号

	char s1[10];
	InputBox(s1, 10, _T("请输入起点"));
	// 将用户输入转换为数字
	sscanf(s1, "%d", &i);
	char s2[10];
	InputBox(s2, 10, _T("请输入终点"));
	// 将用户输入转换为数字
	sscanf(s2, "%d", &j);
	floyd(changzhou);
	display(changzhou, i, j);


}





//7判断顶点是否在图中
int locatevex(mgraph c, int v)
{
	int i;
	for (i = 1; i <= c.vexnum; i++)
		if (v == c.vexs[i].position)
			return i;//已找到
	return -1;//未找到
}
//重新建图
void creatgraph(mgraph* c)
{
	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(40, 0, _T("黑体"));//字体的宽+字体的高+字体的风格

	// 在屏幕中央输出字符串
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("重新建图"), &r, DT_CENTER | DT_WORDBREAK);

	//设置文本颜色
	settextcolor(BLUE);

	//设置文本样式
	settextstyle(30, 0, _T("黑体"));//字体的宽+字体的高+字体的风格
	outtextxy(200, 100, _T("顶点数:"));
	outtextxy(200, 145, _T("边数:"));
	int i, j, m, n, v0, v1, distance;

	//顶点数
	char s1[10];
	InputBox(s1, 10, _T("请输入顶点数"));
	outtextxy(300, 100, s1);

	//边数
	char s2[10];
	InputBox(s2, 10, _T("请输入边数"));
	outtextxy(300, 145, s2);

	// 将用户输入转换为数字
	sscanf(s1, "%d", &c->vexnum);
	sscanf(s2, "%d", &c->arcnum);

	//设置文本样式
	settextstyle(20, 0, "黑体");//字体的宽+字体的高+字体的风格
	settextcolor(CYAN);
	char s3[10];
	char s4[20];
	char s5[256];
	char s6[512];
	char s11[10];
	char s10[10];
	for (i = 1; i <= c->vexnum; i++)
	{


		outtextxy(0, 145 + 30 * i, _T("景点代号:"));
		outtextxy(100, 145 + 30 * i, _T("景点名称:"));
		outtextxy(250, 145 + 30 * i, _T("景点简介:"));
		outtextxy(400, 145 + 30 * i, _T("景点详细介绍:"));
		outtextxy(590, 145 + 30 * i, _T("x轴坐标:"));
		outtextxy(695, 145 + 30 * i, _T("y轴坐标:"));

	}
	settextcolor(BLUE);
	for (i = 1; i <= c->vexnum; i++)
	{
		c->vexs[i].position = i;
		//		InputBox(s3, 10, _T("请输入景点的代号:"));
		sprintf(s3, "%d", c->vexs[i].position);
		outtextxy(80, 145 + 30 * i, s3);

		InputBox(s4, 10, _T("请输入景点的名称:"));
		sscanf(s4, "%s", &c->vexs[i].name);
		outtextxy(190, 145 + 30 * i, s4);

		InputBox(s5, 10, _T("请输入景点的简介:"));
		sscanf(s5, "%s", &c->vexs[i].introduction);
		outtextxy(340, 145 + 30 * i, s5);

		InputBox(s6, 10, _T("请输入景点的详细介绍:"));
		sscanf(s6, "%s", &c->vexs[i].super_introduction);
		outtextxy(550, 145 + 30 * i, s6);

		InputBox(s11, 10, _T("请输入景点x轴坐标:"));
		sscanf(s11, "%d", &c->vexs[i].x);
		outtextxy(680, 145 + 30 * i, s11);

		InputBox(s10, 10, _T("请输入景点的y轴坐标:"));
		sscanf(s10, "%d", &c->vexs[i].y);
		outtextxy(780, 145 + 30 * i, s10);

	}
	//初始化权值为无穷大（不连通）
	for (i = 1; i <= c->vexnum; i++)
	{
		for (j = 1; j <= c->vexnum; j++)
		{
			c->arcs[i][j].adj = Infinity;
		}
		c->arcs[i][i].adj = 0;
	}


	//printf("请键入边的信息：\n");

	//设置文本颜色
	settextcolor(RED);
	//设置文本样式
	settextstyle(20, 0, "黑体");//字体的宽+字体的高+字体的风格
	outtextxy(300, 145 + 50 * (c->vexnum + 1), _T("请键入边的信息"));

	for (i = 1; i <= c->arcnum; i++)
	{

		outtextxy(0, 145 + 50 * (c->vexnum + 1 + i), _T("起点"));
		outtextxy(150, 145 + 50 * (c->vexnum + 1 + i), _T("终点"));
		outtextxy(300, 145 + 50 * (c->vexnum + 1 + i), _T("长度"));

	}
	char s7[10];
	char s8[10];
	char s9[10];
	for (i = 1; i <= c->arcnum; i++)
	{
		InputBox(s7, 10, _T("起点"));
		outtextxy(100, 145 + 50 * (c->vexnum + 1 + i), s7);
		InputBox(s8, 10, _T("终点"));
		outtextxy(250, 145 + 50 * (c->vexnum + 1 + i), s8);
		InputBox(s9, 10, _T("长度"));
		outtextxy(400, 145 + 50 * (c->vexnum + 1 + i), s9);
		sscanf(s7, "%d", &v0);
		sscanf(s8, "%d", &v1);
		sscanf(s9, "%d", &distance);

		m = locatevex(changzhou, v0);
		n = locatevex(changzhou, v1);
		if (m > 0 && n > 0)
		{
			//无向图对称赋值
			c->arcs[m][n].adj = distance;
			c->arcs[n][m].adj = c->arcs[m][n].adj;
		}
	}

}
//7删除顶点
int delvex(mgraph* c)
{
	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(40, 0, _T("黑体"));//字体的宽+字体的高+字体的风格

	// 在屏幕中央输出字符串
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("删除顶点"), &r, DT_CENTER | DT_WORDBREAK);

	int i = 0, j;
	int  v;
	//设置文本样式
	settextstyle(60, 0, "黑体");//字体的宽+字体的高+字体的风格
	if (c->vexnum <= 0)
	{
		outtextxy(300, 100, _T("图中已无顶点,不能再删除"));
		return 1;
	}

	//设置文本样式
	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
	//设置文本颜色
	settextcolor(RED);
	outtextxy(20, 180, _T("请键入需删除的景点代号："));
	char s1[10];
	InputBox(s1, 10, _T("请键入需删除的景点代号"));
	outtextxy(500, 180, s1);
	// 将用户输入转换为数字
	sscanf(s1, "%d", &v);

	while (v <= 0 || v > c->vexnum)
	{
		outtextxy(300, 100, _T("代号错误"));
		return 1;
	}


	//删除邻接矩阵的第v行
	for (i = v; i <= c->vexnum - 1; i++)
		for (j = 1; j <= c->vexnum; j++)
			c->arcs[i][j] = c->arcs[i + 1][j];

	//删除邻接矩阵的第v列
	for (i = v; i <= c->vexnum - 1; i++)
		for (j = 1; j <= c->vexnum - 1; j++)
			c->arcs[j][i] = c->arcs[j][i + 1];

	//删除顶点数组中第v列
	for (int k = v; k <= c->vexnum - 1; k++)
	{
		c->vexs[k] = c->vexs[k + 1];
		c->vexs[k].position = c->vexs[k].position - 1;
	}
	c->vexnum--;



	outtextxy(300, 350, _T("顶点删除成功"));
	return 1;
}
//7删除边
int delarc(mgraph* c)
{
	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格

	// 在屏幕中央输出字符串
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("删除边"), &r, DT_CENTER | DT_WORDBREAK);

	int  v0, v1;

	//设置文本样式
	settextstyle(60, 0, _T("黑体"));//字体的宽+字体的高+字体的风格
	if (c->vexnum <= 0)
	{
		outtextxy(300, 100, _T("图中已无边,不能再删除"));
		return 1;
	}
	//设置文本样式
	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
	//设置文本颜色
	settextcolor(RED);
	outtextxy(20, 180, _T("请键入需删除的起点代号："));
	outtextxy(20, 230, _T("请键入需删除的终点代号："));
	char s1[10];
	InputBox(s1, 10, _T("请键入需删除的起点代号"));
	outtextxy(500, 180, s1);
	char s2[10];
	InputBox(s2, 10, _T("请键入需删除的终点代号"));
	outtextxy(500, 230, s2);
	// 将用户输入转换为数字
	sscanf(s1, "%d", &v0);
	sscanf(s2, "%d", &v1);

	while (v0 <= 0 || v0 > c->vexnum || v1 <= 0 || v1 > c->vexnum)
	{
		outtextxy(300, 100, _T(" 代号错误"));
		return 1;
	}
	//无向图对称赋值
	c->arcs[v0][v1].adj = Infinity;
	c->arcs[v1][v0].adj = Infinity;
	c->arcnum--;

	outtextxy(300, 100, _T("边删除成功!"));
	return 1;
}
//7增加顶点
int envex(mgraph* c)
{
	int i = c->vexnum + 1;
	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(40, 0, _T("黑体"));//字体的宽+字体的高+字体的风格

	// 在屏幕中央输出字符串
	RECT r = { 0, 0, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("增加顶点"), &r, DT_CENTER | DT_WORDBREAK);


	//设置文本样式
	settextstyle(40, 0, _T("黑体"));//字体的高+字体的宽+字体的风格
	//设置文本颜色
	settextcolor(RED);
	c->vexs[i].position = i;
	outtextxy(20, 230, _T("请键入需新增的景点名称："));
	outtextxy(20, 280, _T("请键入需新增的景点简介："));
	outtextxy(20, 330, _T("请键入需新增的景点详细介绍："));
	outtextxy(20, 380, _T("请键入需新增的景点x轴坐标："));
	outtextxy(20, 430, _T("请键入需新增的景点y轴坐标："));
	char s4[20], s5[256], s6[512], s11[10], s10[10];

	InputBox(s4, 20, _T("请输入景点的名称:"));
	sscanf(s4, "%s", &c->vexs[i].name);
	outtextxy(590, 230, s4);

	InputBox(s5, 256, _T("请输入景点的简介:"));
	sscanf(s5, "%s", &c->vexs[i].introduction);
	outtextxy(590, 280, s5);

	InputBox(s6, 512, _T("请输入景点的详细介绍:"));
	sscanf(s6, "%s", &c->vexs[i].super_introduction);
	outtextxy(590, 330, s6);

	InputBox(s11, 10, _T("请输入景点x轴坐标:"));
	sscanf(s11, "%d", &c->vexs[i].x);
	outtextxy(590, 380, s11);

	InputBox(s10, 10, _T("请输入景点的y轴坐标:"));
	sscanf(s10, "%d", &c->vexs[i].y);
	outtextxy(590, 430, s10);
	c->vexnum++;
	//	无向图对称赋值
	for (i = 1; i <= c->vexnum; i++)
	{
		c->arcs[c->vexnum][i].adj = Infinity;
		c->arcs[i][c->vexnum].adj = Infinity;
	}
	c->arcs[c->vexnum][c->vexnum].adj = 0;


	outtextxy(300, 480, _T("顶点添加成功"));
	return 1;
}
//7增加边
int enarc(mgraph* c)
{

	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格

	// 在屏幕中央输出字符串
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("增加边"), &r, DT_CENTER | DT_WORDBREAK);
	int  v0, v1, distance;

	//设置文本样式
	settextstyle(60, 0, _T("黑体"));//字体的宽+字体的高+字体的风格
	//设置文本样式
	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
	//设置文本颜色
	settextcolor(RED);
	outtextxy(20, 180, _T("请键入需新增的边的起点代号："));
	outtextxy(20, 230, _T("请键入需新增的边的终点代号："));
	outtextxy(20, 280, _T("请键入需新增的边的长度(权值)："));
	char s1[10];
	InputBox(s1, 10, _T("请键入需新增的边的起点代号"));
	outtextxy(590, 180, s1);
	char s2[10];
	InputBox(s2, 10, _T("请键入需新增的边的终点代号"));
	outtextxy(590, 230, s2);
	char s3[10];
	InputBox(s3, 10, _T("请键入需新增的边的长度"));
	outtextxy(590, 280, s3);
	// 将用户输入转换为数字
	sscanf(s1, "%d", &v0);
	sscanf(s2, "%d", &v1);
	sscanf(s3, "%d", &distance);
	if (c->arcs[v0][v1].adj < Infinity)
	{
		outtextxy(300, 100, _T("图中已有边,不能再新增"));
		return 1;
	}


	//无向图对称赋值
	c->arcs[v0][v1].adj = distance;
	c->arcs[v1][v0].adj = c->arcs[v0][v1].adj;
	c->arcnum++;
	outtextxy(300, 100, _T("边新增成功!"));

	return 1;
}

//7输出邻接矩阵
void printmatrix(mgraph c)
{
	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格

	// 在屏幕中央输出字符串
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("输出邻接矩阵\n约定【2000】代表无穷大，即不连通"), &r, DT_CENTER | DT_WORDBREAK);
	int i, j, k = 0, t = 0;
	settextstyle(11, 0, "宋体");
	char s[10];
	//sprintf(s, "%d", c.arcs[1][2].adj);//将整形a转换成字符串
	//outtextxy(20  , 120  , s);

	settextcolor(BLUE);
	settextstyle(15, 0, "宋体");

	for (i = 1; i <= c.vexnum; i++)
	{
		sprintf(s, "%d", i);//将整形a转换成字符串
		outtextxy(i * 50 - 30, 80, i);
	}

	settextcolor(RED);
	settextstyle(11, 0, "宋体");
	for (i = 1; i <= c.vexnum; i++)
	{
		for (j = 1; j <= c.vexnum; j++)
		{
			sprintf(s, "%d", c.arcs[i][j].adj);//将整形a转换成字符串
			outtextxy(20 + k * 50, 120 + t * 40, s);
			//printf("%-6d", c.arcs[i][j].adj);
			k++;
			//判断换行时机
			if (k % c.vexnum == 0)
			{
				printf("\n");
				k = 0;
				t++;//行数
			}
		}
	}


}
//77修改图信息
void Changegraph()
{
	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(20, 0, "黑体");//字体的宽+字体的高+字体的风格

	// 在屏幕中央输出字符串
	RECT r = { 0, 0, width - 1, height - 1 };
	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("重新编辑图的信息,请选择你要进行的操作"), &r, DT_CENTER | DT_WORDBREAK);

	//设置文本颜色
	settextcolor(BLUE);
	//设置文本样式
	settextstyle(30, 0, "黑体");//字体的宽+字体的高+字体的风格 
	RECT r1 = { 0,50,width - 1 ,height - 1 };
	drawtext(_T("1.重新建图\n2.删除顶点\n3.删除边\n4.增加顶点\n5.增加边\n 6.输出邻接矩阵"), &r1, DT_CENTER | DT_WORDBREAK);
	switch (getch())
	{

	case 49://重新建图1
		creatgraph(&changzhou);
		break;
	case 50://删除顶点2
		delvex(&changzhou);
		break;
	case 51://删除边3
		delarc(&changzhou);
		break;
	case 52://增加顶点4
		envex(&changzhou);
		break;
	case 53://增加边5
		enarc(&changzhou);
		break;
	case 54://输出邻接矩阵
		printmatrix(changzhou);
		break;
	
	default://处理异常

		break;
	}
}
//*查询景点页面
void Query(mgraph c) {
	//	TCHAR st1[] = _T("茅山风景区");
	//	TCHAR st2[] = _T("银丝面");
	//	TCHAR st3[] = _T("华罗庚纪念馆");
	//	TCHAR st4[] = _T("中华曙猿地质公园");
	//	TCHAR st5[] = _T("报恩禅寺");
	//	TCHAR st6[] = _T("天目湖度假区");
	//	TCHAR st7[] = _T("南山竹海");
	//	TCHAR st8[] = _T("中国春秋淹城旅游区");
	//	TCHAR st9[] = _T("环球动漫嬉戏谷");
	//	///*TCHAR st10[] = _T("常州博物馆");
	//	//TCHAR st11[] = _T("环球恐龙城");
	//	//TCHAR st12[] = _T("天宁禅寺");
	//	//TCHAR st13[] = _T("新四军江南指挥部纪念馆");*/
	//	TCHAR st10[] = _T("常州博物馆");
	//	TCHAR st11[] = _T("环球恐龙城");
	//	TCHAR st12[] = _T("天宁禅寺");
	//	TCHAR st13[] = _T("新四军江南指挥部纪念馆");
	TCHAR st14[] = _T("景点代号：");
	TCHAR st15[] = _T("景点名称：");
	TCHAR st16[] = _T("详细介绍：");
	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(20, 0, "黑体");//字体的宽+字体的高+字体的风格

	// 在屏幕中央输出字符串
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("查询景点信息，请输入你要查询的景点代号"), &r, DT_CENTER | DT_WORDBREAK);

	//设置文本颜色
	settextcolor(BLUE);
	//设置文本样式
	settextstyle(30, 0, _T("黑体"));//字体的宽+字体的高+字体的风格 
	RECT r1 = { 0,50,width - 1 ,height - 1 };
	//		 drawtext(_T("1.茅山风景区\n2.银丝面\n3.华罗庚纪念馆\n4.中华曙猿地质公园\n5.报恩禅寺\n6.天目湖度假区\n 7.南山竹海\n8.中国春秋淹城旅游区\n9.环球动漫嬉戏谷\n10.常州博物馆\n11.环球恐龙城\n12.天宁禅寺\n13.新四军江南指挥部纪念馆\n"), &r1, DT_CENTER | DT_WORDBREAK);
	for (int i = 1; i <= c.vexnum; i++)
	{
		char str[80];
		sprintf(str, "%d、%s", c.vexs[i].position, c.vexs[i].name);
		outtextxy(80, 145 + 30 * i, str);
	}
	int a = getch();
	putimage(0, 0, &white);
	outtextxy(50, 20, st14);
	outtextxy(50, 60, st15);
	outtextxy(50, 100, st16);
	char s[10], str[80], str1[512];
	if (a >= 49 && a <= 57)
	{

		sprintf(s, "%d", c.vexs[a - 48].position);
		sprintf(str, "%s", c.vexs[a - 48].name);
		sprintf(str1, "%s", c.vexs[a - 48].introduction);
	}
	else if (a >= 97 && a <= 102)
	{
		sprintf(s, "%d", c.vexs[a - 87].position);
		sprintf(str, "%s", c.vexs[a - 87].name);
		sprintf(str1, "%s", c.vexs[a - 87].introduction);
	}

	outtextxy(250, 20, s);
	outtextxy(250, 60, str);
	outtextxy(250, 100, str1);
	//			//用户输入景点代号,查询景点信息 
	//			 switch (a)
	//			 {
	//				 
	//			 case 49: 
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//				 char str[80];
	//				 sprintf(str, "%s",c.vexs[a].name);
	//				char str1[512];
	//				sprintf(str1, "%s",c.vexs[a].introduction);
	//
	//				 outtextxy(250, 20,_T("1"));
	////				 outtextxy(250, 60, _T("茅山风景区"));
	////				 drawtext(_T("茅山形胜独特，风景秀丽，2001年被列为国家AAAA级旅游区"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300, 300, &maoshan);
	//				 break;
	//			 case 50:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("2"));
	//				 outtextxy(250, 60, _T("银丝面"));
	//				 drawtext(_T("面细如丝，色白似银，柔软滑爽，富有韧性，下锅不糊"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300, 300, &SilverNoodles);
	//				 break;
	//			 case 51:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("3"));
	//				 outtextxy(250, 60, _T("华罗庚纪念馆"));
	//				 drawtext(_T("作为江苏省爱国主义教育基地，纪念馆每年接待中外参观者5万多人。多年来，华罗庚不仅没有被人们淡忘，反而越来越受到人们的尊敬和怀念"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300, 300, &hualuogeng);
	//				 break;
	//			 case 52:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("4"));
	//				 outtextxy(250, 60, _T("中华曙猿地质公园"));
	//				 drawtext(_T("规划区域包括长荡湖湿地及水母山遗址，是中华曙猿化石的发现地"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300, 300,&Geopark);
	//				 break;
	//			 case 53:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("5"));
	//				 outtextxy(250, 60, _T("报恩禅寺"));
	//				 putimage(300, 300, &BenedictionTemple);
	//				 drawtext(_T("报恩禅寺毗邻传奇色彩的“水漫金山”的“金山寺”，长寿福地的“南山”"), &r0, DT_LEFT | DT_WORDBREAK);
	//
	//				 break;
	//
	//			 case 54:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("6"));
	//				 outtextxy(250, 60, _T("天目湖度假区"));
	//				 drawtext(_T("位于常州溧阳市南八公里处，因属天目山余脉，故名“天目湖”。"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &TianmuLake);
	//				 break;
	//			 case 55:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("7"));
	//				 outtextxy(250, 60, _T("南山竹海"));
	//				 drawtext(_T("景区以竹文化和寿文化为主题，坐拥3.5万亩翠竹"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &NanshanBambooSea);
	//				 break;
	//			 case 56:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("8"));
	//				 outtextxy(250, 60, _T("中国春秋淹城旅游区"));
	//				 drawtext(_T("是中国最为古老也最为完整的地面城池遗址"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &yancheng);
	//				 break;
	//			 case 57:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("9"));
	//				 outtextxy(250, 60, _T("环球动漫嬉戏谷"));
	//				 drawtext(_T("从未有过的、神秘未知的、超越现实的“奇幻世界”带入现实的主题乐园"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &joyland);
	//				 break;
	//			 case 97:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("10"));
	//				 outtextxy(250, 60, _T("常州博物馆"));
	//				 drawtext(_T("是集收藏、研究、陈列展览于一体的地方综合性博物馆"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &museum);
	//				 break;
	//			 case 98:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("11"));
	//				 outtextxy(250, 60, _T("环球恐龙城"));
	//				 drawtext(_T("一家融展示、科普、娱乐、休闲及参与性表演于一体的恐龙为主题的一站式旅游度假区"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &dinosaur);
	//				 break;
	//			 case 99:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("12"));
	//				 outtextxy(250, 60, _T("天宁禅寺"));
	//				 drawtext(_T("是常州现存规模最大，保存最完整的千年古刹"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &tianningTemple);
	//				 break;
	//
	//			 case 100:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("13"));
	//				 outtextxy(250, 60, _T("新四军江南指挥部纪念馆"));
	//				 drawtext(_T("是一个在中国革命史和军事史上都有重要地位的地方"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &NewFourthArmy);
	//				 break;
	//			
	//			 default://处理异常
	//				
	//				 break;
	//			 }	

}
//输出景点及其代号
void Outputtext() {
	TCHAR s14[] = _T("A.景点信息查询");
	TCHAR s15[] = _T("B.查询两景点最短路线");
	//TCHAR s16[] = _T("景点及其代号");
	TCHAR s17[] = _T("可选服务");
	TCHAR s18[] = _T("C.重新编辑图的信息");
	TCHAR s19[] = _T("D.查询经过中间顶点的最短路径");
	TCHAR s20[] = _T("E.查询两点间所有路径");


	//设置文字背景模式-->透明
	//TRANSPARENT：代表透明，或着直接写【0】，也表示透明
	setbkmode(TRANSPARENT);
	//设置文本颜色
	settextcolor(RED);

	//设置文本样式
	settextstyle(10, 0, "黑体");//字体的宽+字体的高+字体的风格

	//outtextxy(20, 5, s16);
	outtextxy(250, 5, s17);




	//设置文本颜色
	settextcolor(LIGHTBLUE);

	//设置文本样式
	settextstyle(20, 0, _T("宋体"));//字体的宽+字体的高+字体的风格


	outtextxy(250, 20, s14);
	outtextxy(250, 45, s15);
	outtextxy(250, 70, s18);
	outtextxy(250, 95, s19);
	outtextxy(250, 120, s20);
}

//画出景点标记及连线
void drawCircle(mgraph c)
{
	char str[80];

	for (int i = 1; i <= c.vexnum; i++)
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(c.vexs[i].x, c.vexs[i].y, 10);
		sprintf(str, "%d、%s", c.vexs[i].position, c.vexs[i].name);
		setbkmode(TRANSPARENT);
		settextcolor(BLUE);
		settextstyle(15, 0, _T("宋体"));//字体的高+字体的宽+字体的风格
		outtextxy(c.vexs[i].x - 40, c.vexs[i].y - 25, str);
	}


	for (int i = 0; i <= c.vexnum; i++)
		for (int j = i; j <= c.vexnum; j++)
		{
			if (c.arcs[i][j].adj > 0 && c.arcs[i][j].adj != Infinity)
			{
				setlinecolor(BLUE);
				setlinestyle(2, 2);
				line(c.vexs[i].x, c.vexs[i].y, c.vexs[j].x, c.vexs[j].y);
			}
		}
}
void MOUSE_Picture() {
	if (MouseHit()) {
		MOUSEMSG m = GetMouseMsg();//获取鼠标信息
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (m.x <= 220 && m.x >= 140 && m.y <= 250 && m.y >= 220)
			{
				putimage(m.x, m.y, &maoshan);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);

				//				Outputtext();
			}
			else if (m.x <= 270 && m.x >= 190 && m.y <= 370 && m.y >= 315)
			{
				putimage(m.x, m.y, &SilverNoodles);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 340 && m.x >= 255 && m.y <= 300 && m.y >= 275)
			{
				putimage(m.x, m.y, &hualuogeng);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 210 && m.x >= 80 && m.y <= 505 && m.y >= 470)
			{
				putimage(m.x, m.y, &NewFourthArmy);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 220 && m.x >= 150 && m.y <= 650 && m.y >= 620)
			{
				putimage(m.x, m.y, &BenedictionTemple);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 340 && m.x >= 245 && m.y <= 470 && m.y >= 430)
			{
				putimage(m.x, m.y, &Geopark);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 315 && m.x >= 230 && m.y <= 655 && m.y >= 625)
			{
				putimage(m.x, m.y, &TianmuLake);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 300 && m.x >= 240 && m.y <= 760 && m.y >= 730)
			{
				putimage(m.x, (m.y - 200), &NanshanBambooSea);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 580 && m.x >= 455 && m.y <= 320 && m.y >= 265)
			{
				putimage(m.x, m.y, &yancheng);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 600 && m.x >= 530 && m.y <= 205 && m.y >= 180)
			{
				putimage(m.x, m.y, &museum);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 690 && m.x >= 630 && m.y <= 225 && m.y >= 200)
			{
				putimage(m.x, m.y, &dinosaur);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 600 && m.x >= 665 && m.y <= 260 && m.y >= 235)
			{
				putimage(m.x, m.y, &tianningTemple);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}
			else if (m.x <= 720 && m.x >= 630 && m.y <= 490 && m.y >= 400)
			{
				putimage((m.x - 200), m.y, &joyland);
				Sleep(1000);
				putimage(0, 0, &white);
				drawCircle(changzhou);
				//				Outputtext();
			}


		}

		//刷新地图页面
		if (m.uMsg == WM_RBUTTONDOWN) {
			//			putimage(0, 0, &map);
			//			Outputtext();
			putimage(0, 0, &white);
			drawCircle(changzhou);
			Outputtext();

		}
	}

}
// 主函数
int main()
{

	initgraph(width, height);
	//全局资源导入
	loadimage(&map, _T("D:\\IMAGE\\map.jpg"), width, height);
	loadimage(&white, _T("D:\\IMAGE\\white.jpg"), width, height);
	loadimage(&BenedictionTemple, _T("D:\\IMAGE\\BenedictionTemple.jpg"), width1, height1);
	loadimage(&dinosaur,  _T("D:\\IMAGE\\dinosaur.jpg"), width1, height1);
	loadimage(&Geopark, _T("D:\\IMAGE\\Geopark.jpg"), width1, height1);
	loadimage(&hualuogeng, _T("D:\\IMAGE\\hualuogeng.jpg"), width1, height1);
	loadimage(&joyland, _T("ED:\\IMAGE\\joyland.jpg"), width1, height1);
	loadimage(&maoshan,_T("D:\\IMAGE\\maoshan.jpg"), width1, height1);
	loadimage(&NewFourthArmy, _T("D:\\IMAGE\\NewFourthArmy.jpg"), width1, height1);
	loadimage(&SilverNoodles, _T("D:\\IMAGE\\SilverNoodles.jpg"), width1, height1);
	loadimage(&TianmuLake, _T("D:\\IMAGE\\TianmuLake.jpg"), width1, height1);
	loadimage(&tianningTemple, _T("D:\\IMAGE\\tianningTemple.jpg"), width1, height1);
	loadimage(&yancheng,_T("D:\\IMAGE\\yancheng.jpg"), width1, height1);
	loadimage(&NanshanBambooSea,_T("D:\\IMAGE\\NanshanBambooSea.jpg"), width1, height1);
	loadimage(&museum, _T("D:\\IMAGE\\museum.jpg"), width1, height1);

	putimage(0, 0, &white);

	changzhou = initgraph();
	drawCircle(changzhou);
		Outputtext();

		//c = initgraph();
	while (1) {

		MOUSE_Picture();


		char input;
		//选择服务
		if (_kbhit()) {

			input = getch();
			if (input == 'a') {
				Query(changzhou); //查询景点信息

			}
			else if (input == 'b') {
				DrawPath(); //最短路线

			}
			else if (input == 'c') {
				Changegraph(); //编辑图信息
			}
			else if (input == 'd')
			{
				finalShortest(changzhou);     //不仅经过初始点和终点，还经过其他点
			}
			else if (input == 'e')
			{
				allroad(changzhou);     //不仅经过初始点和终点，还经过其他点
			}
		}

	}
	system("pause");
	closegraph;//关闭画布
	return 0;

}

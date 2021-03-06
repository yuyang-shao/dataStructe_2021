//#undef UNICODE
//#undef _UNICODE
//#define _CRT_SECURE_NO_DEPRECATE
//#pragma warning(disable:4996)//防止vs2019报错，使程序顺利运行
////#pragma comment(lib,"Winmm.lib")
//#include <stdio.h>
//#include <graphics.h>
//#include <conio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <mmsystem.h>
//#include<string.h>
//#include<windows.h>
//#include <string>
//
//#define width 800
//#define height 799//游戏画面尺寸
//#define width1 200  //景点图片尺寸
//#define height1 200
//#define Infinity 20000//约定【2000】代表无穷大，即不连通
//#define MaxVertexNum 20//约定最多设置20个顶点（景点）
//#define MAX 40 
//#define key 13//默认顶点数为13
//#define lock 20//默认边数为20
//
//IMAGE map, BenedictionTemple, dinosaur, Geopark, hualuogeng,white,
//		joyland, maoshan, museum, NewFourthArmy, SilverNoodles, TianmuLake, tianningTemple, yancheng, NanshanBambooSea;
//
//
//
//typedef struct vexsinfo//顶点（景点）结构体
//{
//	char name[32];//名称 
//	int position;//代号
//	char introduction[256];//简介---功能菜单5 
//	char super_introduction[512];//详细介绍---功能菜单6 
//	int x;  //景点坐标
//	int y;
//}vexsinfo;
//
//typedef struct arcell//边（路径）结构体
//{
//	int adj;//权值  
//}arcell, adjmatrix[MaxVertexNum][MaxVertexNum];//邻接矩阵
//
//typedef struct mgraph//图结构体
//{
//	vexsinfo vexs[MaxVertexNum];//顶点数组 
//	adjmatrix arcs;//邻接矩阵 
//	int vexnum, arcnum;//顶点（vertex）数和边（arc）数 
//}mgraph;
//
////全局变量
//
//int shortest[MaxVertexNum][MaxVertexNum];//最短路径 
//int pathh[MaxVertexNum][MaxVertexNum];
//mgraph changzhou; //常州图
////c.vexnum = key;  //顶点数
////c.arcnum = lock;  //边数
//
////初始化图形系统
//mgraph initgraph()
//{
//	int i = 0, j = 0;
//	mgraph c;
//	c.vexnum = key;  //顶点数
//	c.arcnum = lock;  //边数
//
//	//设置景点代号
//	for (i = 1; i <= key; i++)
//		c.vexs[i].position = i;
//
//	//string copy顶点信息 ，景点的名称，详细介绍，简介
//	strcpy(c.vexs[1].name, "茅山风景区");
//	strcpy(c.vexs[1].super_introduction, "\n茅山风景区：茅山形胜独特，风景秀丽，2001年被列为国家AAAA级旅游区\n");
//	strcpy(c.vexs[1].introduction, "金陵地肺名山");
//
//	strcpy(c.vexs[2].name, "银丝面");
//	strcpy(c.vexs[2].super_introduction, "\n银丝面：面细如丝，色白似银，柔软滑爽，富有韧性，下锅不糊\n");
//	strcpy(c.vexs[2].introduction, "地方传统面食小吃");
//
//	strcpy(c.vexs[3].name, "华罗庚纪念馆");
//	strcpy(c.vexs[3].super_introduction, "\n河苑：套餐，盖浇饭，汉堡可乐，蛋炒饭，粥，包子，馒头，应有尽有，满足你的胃。\n");
//	strcpy(c.vexs[3].introduction, "美食中心");
//
//	strcpy(c.vexs[4].name, "中华曙猿地质公园");
//	strcpy(c.vexs[4].super_introduction, "\n中华曙猿地质公园：规划区域包括长荡湖湿地及水母山遗址，是中华曙猿化石的发现地\n");
//	strcpy(c.vexs[4].introduction, "省级湿地公园");
//
//	strcpy(c.vexs[5].name, "报恩禅寺");
//	strcpy(c.vexs[5].super_introduction, "\n报恩禅寺：报恩禅寺毗邻传奇色彩的“水漫金山”的“金山寺”，长寿福地的“南山”\n");
//	strcpy(c.vexs[5].introduction, "佛门圣地");
//
//	strcpy(c.vexs[6].name, "天目湖度假区");
//	strcpy(c.vexs[6].super_introduction, "\n天目湖：位于常州溧阳市南八公里处，因属天目山余脉，故名“天目湖”。\n");
//	strcpy(c.vexs[6].introduction, "“江南明珠”、“绿色仙境”");
//
//	strcpy(c.vexs[7].name, "南山竹海");
//	strcpy(c.vexs[7].super_introduction, "\n南山竹海：景区以竹文化和寿文化为主题，坐拥3.5万亩翠竹。\n");
//	strcpy(c.vexs[7].introduction, "天堂南山，梦幻竹海");
//
//	strcpy(c.vexs[8].name, "中国春秋淹城旅游区");
//	strcpy(c.vexs[8].super_introduction, "\n中国春秋淹城旅游区：是中国最为古老也最为完整的地面城池遗址\n");
//	strcpy(c.vexs[8].introduction, "地面城池遗址");
//
//	strcpy(c.vexs[9].name, "环球动漫嬉戏谷");
//	strcpy(c.vexs[9].super_introduction, "\n环球动漫嬉戏谷：从未有过的、神秘未知的、超越现实的“奇幻世界”带入现实的主题乐园\n");
//	strcpy(c.vexs[9].introduction, "动漫艺术、游戏文化");
//
//	strcpy(c.vexs[10].name, "常州博物馆");
//	strcpy(c.vexs[10].super_introduction, "\n常州博物馆：是集收藏、研究、陈列展览于一体的地方综合性博物馆\n");
//	strcpy(c.vexs[10].introduction, "国家一级博物馆");
//
//	strcpy(c.vexs[11].name, "环球恐龙城");
//	strcpy(c.vexs[11].super_introduction, "\n环球恐龙城：一家融展示、科普、娱乐、休闲及参与性表演于一体的恐龙为主题的一站式旅游度假区.\n");
//	strcpy(c.vexs[11].introduction, "旅游度假区");
//
//	strcpy(c.vexs[12].name, "天宁禅寺");
//	strcpy(c.vexs[12].super_introduction, "\n天宁禅寺：是常州现存规模最大，保存最完整的千年古刹\n");
//	strcpy(c.vexs[12].introduction, "中国禅宗四大丛林");
//
//	strcpy(c.vexs[13].name, "新四军江南指挥部纪念馆");
//	strcpy(c.vexs[13].super_introduction, "\n新四军江南指挥部纪念馆：是一个在中国革命史和军事史上都有重要地位的地方\n");
//	strcpy(c.vexs[13].introduction, "指挥部旧址");
//
//	//确定景点的坐标
//	c.vexs[1].x = 145;
//	c.vexs[1].y = 238;//茅山
//
//	c.vexs[2].x = 200;
//	c.vexs[2].y = 330;//银丝面
//
//	c.vexs[3].x = 330;
//	c.vexs[3].y = 285;//华罗庚纪念馆
//
//	c.vexs[4].x = 320;
//	c.vexs[4].y = 445;//中华曙猿地质公园
//
//	c.vexs[5].x = 170;
//	c.vexs[5].y = 640;//报恩禅寺
//
//	c.vexs[6].x = 250;
//	c.vexs[6].y = 640;//天目湖度假区
//
//	c.vexs[7].x = 260;
//	c.vexs[7].y = 750;//南山竹海
//
//	c.vexs[8].x = 470;
//	c.vexs[8].y = 320;//中国春秋淹城旅游区
//
//	c.vexs[9].x = 650;
//	c.vexs[9].y = 470;//环球动漫嬉戏谷
//
//	c.vexs[10].x = 550;
//	c.vexs[10].y = 230;//常州博物馆
//
//	c.vexs[11].x = 630;
//	c.vexs[11].y = 210;//环球恐龙城
//
//	c.vexs[12].x = 620;
//	c.vexs[12].y = 250;//天宁禅寺
//
//	c.vexs[13].x = 160;
//	c.vexs[13].y = 490; //新四军
//
//
//	//初始化邻接矩阵，权值均为无穷大，即所有顶点互不相连
//	for (i = 1; i <= key; i++)
//		for (j = 1; j <= key; j++)
//			c.arcs[i][j].adj = Infinity; //邻接矩阵权值无限大（2000）
//
//	//规定顶点的连通情况并赋予边对应的权值，（点1，点2，边权）G[点1][点2] = weight 
//	//联通两个景点，确定两景点间距离
//	c.arcs[1][2].adj = 60;
//	c.arcs[1][3].adj = 70;
//
//	c.arcs[2][3].adj = 40;
//	c.arcs[2][4].adj = 80;
//	c.arcs[2][13].adj = 120;
//
//	c.arcs[3][8].adj = 130;
//	
//	c.arcs[4][13].adj = 130;
//	c.arcs[4][9].adj = 20;
//
//	c.arcs[5][6].adj = 20;
//	//c.arcs[5][7].adj = 60;
//	
//
//	c.arcs[6][7].adj = 70;
//
//	//c.arcs[7][8].adj = 30;
//
//	c.arcs[8][9].adj = 210;
//	c.arcs[8][10].adj = 40;
//
//	//c.arcs[9][10].adj = 35;
//	//c.arcs[9][11].adj = 10;
//
//	c.arcs[10][11].adj = 10;
//
//	c.arcs[11][12].adj = 10;
//
//	c.arcs[5][13].adj = 200;
//	c.arcs[5][13].adj = 210;
//
//	//无向图对称赋值
//	for (i = 1; i <= key; i++)
//		for (j = 1; j <= key; j++)
//			c.arcs[j][i].adj = c.arcs[i][j].adj;
//
//	return c;
//}
//
//
//
////33弗洛伊德算法
//void floyd(mgraph c)
//{
//	int i, j, k;
//	for (i = 1; i <= c.vexnum; i++)
//	{
//		for (j = 1; j <= c.vexnum; j++)
//		{
//			shortest[i][j] = c.arcs[i][j].adj;
//			pathh[i][j] = j;//顶点i到顶点j的最短路径是经过j 
//		}
//	}
//
//	printf("\n\n\n");
//
//	//核心操作；算法参考网址：https://www.cnblogs.com/skywang12345/p/3711523.html 
//	for (k = 1; k <= c.vexnum; k++)
//	{
//		for (i = 1; i <= c.vexnum; i++)
//		{
//			for (j = 1; j <= c.vexnum; j++)
//			{
//				if (shortest[i][j] > shortest[i][k] + shortest[k][j])
//				{
//					shortest[i][j] = shortest[i][k] + shortest[k][j];
//					pathh[i][j] = pathh[i][k];
//					//顶点i到顶点j的最短路径是经过k 
//				}
//			}
//		}
//	}
//}
//
////33打印最短路径 
//void display(mgraph c, int i, int j)
//{
//	int a, b,k;
//	a = i;
//	b = j;
//	setlinecolor(RED);
//	setlinestyle(PS_DASHDOT,2);
//	k = pathh[i][j];
//	line(c.vexs[a].x, c.vexs[a].y, c.vexs[k].x, c.vexs[k].y);
//	while (k != b)
//	{
//		//递归
//		line( c.vexs[k].x, c.vexs[k].y,c.vexs[pathh[k][j]].x, c.vexs[pathh[k][j]].y);
//		k = pathh[k][j];
//	}
////	line(c.vexs[pathh[i][j]].x, c.vexs[pathh[i][j]].y, c.vexs[b].x, c.vexs[b].y);
//	//printf("%s-->%s的最短路径是：%d 米。\n\n", c.vexs[a].name, c.vexs[b].name, shortest[a][b]);
//	
//	outtextxy(50, 100, shortest[a][b]);
//}
// //画最短路线
//void DrawPath() {
//
//	outtextxy(300, 100,_T("请输入要查询的两个景点的代号"));
//	int i, j; //要查询的两个景点的代号
//	 
//	char s1[10];
//	InputBox(s1, 10, _T("请输入起点"));
//	// 将用户输入转换为数字
//	sscanf(s1, "%d", &i);
//	char s2[10];
//	InputBox(s2, 10, _T("请输入终点"));
//	// 将用户输入转换为数字
//	sscanf(s2, "%d", &j);
//	floyd(changzhou);
//	display(changzhou, i, j);
//
//
//}
////7判断顶点是否在图中
//int locatevex(mgraph c, int v)
//{
//	int i;
//	for (i = 1; i <= c.vexnum; i++)
//		if (v == c.vexs[i].position)
//			return i;//已找到
//	return -1;//未找到
//}
//
////重新建图
//void creatgraph(mgraph* c)
//{
//	//设置文本颜色
//	settextcolor(RED);
//
//	//设置文本样式
//	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
//
//	// 在屏幕中央输出字符串
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("重新建图"), &r, DT_CENTER | DT_WORDBREAK);
//
//	//设置文本颜色
//	settextcolor(BLUE);
//
//	//设置文本样式
//	settextstyle(30, 0, "黑体");//字体的宽+字体的高+字体的风格
//	outtextxy(200, 100,_T("顶点数:"));
//	outtextxy(200, 145, _T("边数:"));
//	int i, j, m, n, v0, v1, distance;
//
//	//printf("请键入图的顶点数和边数：\n");
//
//
//		// 定义字符串缓冲区，并接收用户输入
//	//顶点数
//	char s1[10];
//	InputBox(s1, 10, _T("请输入顶点数"));
//	outtextxy(300, 100, s1);
//
//	//边数
//	char s2[10];
//	InputBox(s2, 10, _T("请输入边数"));
//	outtextxy(300, 145, s2);
//
//	// 将用户输入转换为数字
//	sscanf(s1, "%d", &c->vexnum);
//	sscanf(s2, "%d", &c->arcnum);
//
//	//设置文本样式
//	settextstyle(20, 0, "黑体");//字体的宽+字体的高+字体的风格
//	settextcolor(CYAN);
//	char s3[10];
//	char s4[10];
//	char s5[10];
//	char s6[10];
//	for (i = 1; i <= c->vexnum; i++)
//	{
//	
//	 
//		outtextxy(0, 145 + 50 * i, _T("景点代号:"));
//		outtextxy(150, 145 + 50 * i, _T("景点名称:"));
//		outtextxy(300, 145 + 50 * i, _T("景点简介:"));
//		outtextxy(450, 145 + 50 * i, _T("景点详细介绍:"));
//
//	}
//	settextcolor(BLUE);
//	for (i = 1; i <= c->vexnum; i++)
//	{
//		
//		InputBox(s3, 10, _T("请输入景点的代号:"));
//		sscanf(s3, "%d", &c->vexs[i].position);
//		outtextxy(100, 145+50*i, s3);
//
//		InputBox(s4, 10, _T("请输入景点的名称:"));
//		sscanf(s4, "%d", &c->vexs[i].name);
//		outtextxy(250, 145 + 50 * i, s4);
//
//		InputBox(s5, 10, _T("请输入景点的简介:"));
//		sscanf(s5, "%d", &c->vexs[i].introduction);
//		outtextxy(400, 145 + 50 * i, s5);
//
//		InputBox(s6, 10, _T("请输入景点的详细介绍:"));
//		sscanf(s6, "%d", &c->vexs[i].introduction);
//		outtextxy(600, 145 + 50 * i, s6);
//
//	}
//	//初始化权值为无穷大（不连通）
//	for (i = 1; i <= c->vexnum; i++)
//		for (j = 1; j <= c->vexnum; j++)
//			c->arcs[i][j].adj = Infinity;
//
//	//printf("请键入边的信息：\n");
//
//	//设置文本颜色
//	settextcolor(RED);
//	//设置文本样式
//	settextstyle(20, 0, "黑体");//字体的宽+字体的高+字体的风格
//	outtextxy(300, 145 + 50 * (c->vexnum+1), _T("请键入边的信息"));
//
//	for (i = 1; i <= c->arcnum; i++)
//	{
//
//		outtextxy(0, 145 + 50 * (c->vexnum + 1+i), _T("起点"));
//		outtextxy(150, 145 + 50 * (c->vexnum + 1+i), _T("终点"));
//		outtextxy(300, 145 + 50 * (c->vexnum + 1+i), _T("长度"));
//		 
//	}
//	char s7[10];
//	char s8[10];
//	char s9[10];
//	for (i = 1; i <= c->arcnum; i++)
//	{
//		/*printf("\n第%d条边的起点、终点、长度为：", i);
//		scanf("%d %d %d", &v0, &v1, &distance);*/
//		//判断输入的起点和终点是否存在于图中，若存在，则返回代号
//		InputBox(s7, 10, _T("起点"));
//		outtextxy(100, 145 + 50 * (c->vexnum + 1 + i), s7);
//		InputBox(s8, 10, _T("终点") );
//		outtextxy(250, 145 + 50 * (c->vexnum + 1 + i),s8);
//		InputBox(s9, 10, _T("长度"));
//		outtextxy(400, 145 + 50 * (c->vexnum + 1 + i),s9);
//		sscanf(s7, "%d", &v0);
//		sscanf(s8, "%d", &v1);
//		sscanf(s9, "%d", &distance);
//	
//		m = locatevex(changzhou, v0);
//		n = locatevex(changzhou, v1);
//		if (m > 0 && n > 0)
//		{
//			//无向图对称赋值
//			c->arcs[m][n].adj = distance;
//			c->arcs[n][m].adj = c->arcs[m][n].adj;
//		}
//	}
//	
//}
////7删除顶点
//int delvex(mgraph* c)
//{
//	//设置文本颜色
//	settextcolor(RED);
//
//	//设置文本样式
//	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
//
//	// 在屏幕中央输出字符串
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("删除顶点"), &r, DT_CENTER | DT_WORDBREAK);
//
//	int i = 0, j;
//	int m, v;
//	//设置文本样式
//	settextstyle(60, 0, "黑体");//字体的宽+字体的高+字体的风格
//	if (c->vexnum <= 0)
//	{
//		outtextxy(300, 100, _T("图中已无顶点,不能再删除"));
//		return 1;
//	}
//
//	//设置文本样式
//	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
//	//设置文本颜色
//	settextcolor(RED);
//	outtextxy(20, 180, _T("请键入需删除的景点代号："));
//	char s1[10];
//	InputBox(s1, 10, _T("请键入需删除的景点代号"));
//	outtextxy(500, 180, s1);
//	// 将用户输入转换为数字
//	sscanf(s1, "%d", &v);
//	
//	while (v <= 0 || v > key)
//	{
//		outtextxy(300, 100, _T("代号错误"));
//		return 1;
//	}
//	m = locatevex(changzhou, v);
//	if (m < 0)
//	{
//		//printf("顶点%d已删除\n", v);
//		outtextxy(300, 350, _T("该顶点已被删除"));
//		return 1;
//	}
//
//	//删除邻接矩阵的第m行
//	for (i = m-1; i < c->vexnum - 1; i++)
//		for (j = 0; j < c->vexnum; j++)
//			c->arcs[i][j] = c->arcs[i + 1][j];
//
//	//删除邻接矩阵的第m列
//	for (i = m-1; i < c->vexnum - 1; i++)
//		for (j = 0; j < c->vexnum; j++)
//			c->arcs[j][i] = c->arcs[j][i + 1];
//
//	c->vexs[v].position = -1;//表示该顶点已删除
//	c->vexnum--;
//	outtextxy(300, 350, _T("顶点删除成功"));
//	return 1;
//}
////7删除边
//int delarc(mgraph* c)
//{
//	//设置文本颜色
//	settextcolor(RED);
//
//	//设置文本样式
//	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
//
//	// 在屏幕中央输出字符串
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("删除边"), &r, DT_CENTER | DT_WORDBREAK);
//
//	int m, n, v0, v1;
//	
//	//设置文本样式
//	settextstyle(60, 0, "黑体");//字体的宽+字体的高+字体的风格
//	if (c->vexnum <= 0)
//	{
//		outtextxy(300, 100, _T("图中已边,不能再删除"));
//		return 1;
//	}
//	//设置文本样式
//	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
//	//设置文本颜色
//	settextcolor(RED);
//	outtextxy(20, 180, _T("请键入需删除的起点代号："));
//	outtextxy(20, 230, _T("请键入需删除的终点代号："));
//	char s1[10];
//	InputBox(s1, 10, _T("请键入需删除的起点代号"));
//	outtextxy(500, 180, s1);
//	char s2[10];
//	InputBox(s2, 10, _T("请键入需删除的终点代号"));
//	outtextxy(500, 230, s2);
//	// 将用户输入转换为数字
//	sscanf(s1, "%d", &v0);
//	sscanf(s1, "%d", &v1);
//
//	while (v0 <= 0 || v0 > key || v1 <= 0 || v1 > key)
//	{
//		outtextxy(300, 100, _T(" 代号错误"));
//		return 1;
//	}
//	m = locatevex(changzhou, v0);
//	if (m < 0)
//	{
//		 
//		outtextxy(300, 100, _T("起点已删除"));
//		return 1;
//	}
//	n = locatevex(changzhou, v1);
//	if (n < 0)
//	{
//		 
//		outtextxy(300, 100, _T(" 终点已删除"));
//		return 1;
//	}
//
//	//无向图对称赋值
//	c->arcs[m][n].adj = Infinity;
//	c->arcs[n][m].adj = Infinity;
//	c->arcnum--;
//
//	outtextxy(300, 100, _T("边删除成功!"));
//	return 1;
//}
////7输出邻接矩阵
//void printmatrix(mgraph c)
//{
//	//设置文本颜色
//	settextcolor(RED);
//
//	//设置文本样式
//	settextstyle(40, 0, "黑体");//字体的宽+字体的高+字体的风格
//
//	// 在屏幕中央输出字符串
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("输出邻接矩阵\n约定【2000】代表无穷大，即不连通"), &r, DT_CENTER | DT_WORDBREAK);
//	int i, j, k = 0,t=0;
//	settextstyle(11, 0, "宋体");
//	char s[10];
//	//sprintf(s, "%d", c.arcs[1][2].adj);//将整形a转换成字符串
//	//outtextxy(20  , 120  , s);
//
//	settextcolor(BLUE);
//	settextstyle(15, 0, "宋体");
//
//	for (i = 1; i <= c.vexnum; i++)
//	{
//		sprintf(s, "%d", i);//将整形a转换成字符串
//		outtextxy(i * 50 - 30, 80, i);
//	}
//
//	settextcolor(RED);
//	settextstyle(11, 0, "宋体");
//	for (i = 1; i <=c.vexnum; i++)
//	{
//		for (j = 1; j <= c.vexnum; j++)
//		{
//			sprintf(s, "%d", c.arcs[i][j].adj);//将整形a转换成字符串
//			outtextxy(20+k*50,120+t*40, s);
//			//printf("%-6d", c.arcs[i][j].adj);
//			k++;
//			//判断换行时机
//			if (k % c.vexnum == 0)
//			{
//				printf("\n");
//				k = 0;
//				t++;//行数
//			}
//		}
//	}
//	
//	
//}
////77修改图信息
//void Changegraph()
//{
//	//设置文本颜色
//	settextcolor(RED);
//
//	//设置文本样式
//	settextstyle(20, 0, "黑体");//字体的宽+字体的高+字体的风格
//
//	// 在屏幕中央输出字符串
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("重新编辑图的信息,请选择你要进行的操作"), &r, DT_CENTER | DT_WORDBREAK);
//
//	//设置文本颜色
//	settextcolor(BLUE);
//	//设置文本样式
//	settextstyle(30, 0, "黑体");//字体的宽+字体的高+字体的风格 
//	RECT r1 = { 0,50,width - 1 ,height - 1 };
//	drawtext(_T("1.重新建图\n2.删除顶点\n3.删除边\n4.增加顶点\n5.增加边\n6.更新信息\n 7.输出邻接矩阵"), &r1, DT_CENTER | DT_WORDBREAK);
//	switch (getch())
//	{
//
//	case 49://重新建图1
//		creatgraph(&changzhou);
//		break;
//	case 50://删除顶点2
//		delvex(&changzhou);
//		break;
//	case 51://删除边3
//		delarc(&changzhou);
//		break;
//	case 52://增加顶点4
//		//envex(mgraph * c);
//		break;
//	case 53://增加边5
//		//enarc(mgraph * c);
//		break;
//	case 54://更新信息6
//		//newgraph(mgraph * c);
//		break;
//	case 55://输出邻接矩阵7
//		printmatrix(changzhou);
//		break;
//	default://处理异常
//
//		break;
//	}
//}
// 
//
////*查询景点页面
//void Query() {
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
//	TCHAR st14[] = _T("景点代号：");
//	TCHAR st15[] = _T("景点名称：");
//	TCHAR st16[] = _T("详细介绍：");
//	//设置文本颜色
//	settextcolor(RED);
//
//	//设置文本样式
//	settextstyle(20, 0, "黑体");//字体的宽+字体的高+字体的风格
//
//	// 在屏幕中央输出字符串
//	RECT r = { 0, 0, width-1, height-1};
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//		 putimage(0, 0, &white);
//		 drawtext(_T("查询景点信息，请输入你要查询的景点代号"), &r, DT_CENTER | DT_WORDBREAK) ;
//
//		 //设置文本颜色
//		 settextcolor(BLUE);
//		 //设置文本样式
//		 settextstyle(30, 0, "黑体");//字体的宽+字体的高+字体的风格 
//		 RECT r1 = {0,50,width - 1 ,height - 1 };
//		 drawtext(_T("1.茅山风景区\n2.银丝面\n3.华罗庚纪念馆\n4.中华曙猿地质公园\n5.报恩禅寺\n6.天目湖度假区\n 7.南山竹海\n8.中国春秋淹城旅游区\n9.环球动漫嬉戏谷\n10.常州博物馆\n11.环球恐龙城\n12.天宁禅寺\n13.新四军江南指挥部纪念馆\n"), &r1, DT_CENTER | DT_WORDBREAK);
//		 
//		 
//	
//			
//			//用户输入景点代号,查询景点信息 
//			 switch (getch())
//			 {
//				 
//			 case 49: 
//				 putimage(0, 0, &white);
//				 outtextxy(50, 20, st14);
//				 outtextxy(50, 60, st15);
//				 outtextxy(50, 100, st16);
//				 
//				 outtextxy(250, 20,_T("1"));
//				 outtextxy(250, 60, _T("茅山风景区"));
//				 drawtext(_T("茅山形胜独特，风景秀丽，2001年被列为国家AAAA级旅游区"), &r0, DT_LEFT | DT_WORDBREAK);
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
//	
//}
//
//
//
//
////输出景点及其代号
//void Outputtext() {
//	TCHAR s1[] = _T("1.茅山风景区");
//	TCHAR s2[] = _T("2.银丝面");
//	TCHAR s3[] = _T("3.华罗庚纪念馆");
//	TCHAR s4[] = _T("4.中华曙猿地质公园");
//	TCHAR s5[] = _T("5.报恩禅寺");
//	TCHAR s6[] = _T("6.天目湖度假区");
//	TCHAR s7[] = _T("7.南山竹海");
//	TCHAR s8[] = _T("8.中国春秋淹城旅游区");
//	TCHAR s9[] = _T("9.环球动漫嬉戏谷");
//	TCHAR s10[] = _T("10.常州博物馆");
//	TCHAR s11[] = _T("11.环球恐龙城");
//	TCHAR s12[] = _T("12.天宁禅寺");
//	TCHAR s13[] = _T("13.新四军江南指挥部纪念馆");
//	TCHAR s14[] = _T("A.景点信息查询");
//	TCHAR s15[] = _T("B.查询两景点最短路线");
//	TCHAR s16[] = _T("景点及其代号");
//	TCHAR s17[] = _T("可选服务");
//	TCHAR s18[] = _T("C.重新编辑图的信息");
//
//
//	//设置文字背景模式-->透明
//		//TRANSPARENT：代表透明，或着直接写【0】，也表示透明
//		setbkmode(TRANSPARENT);
//	//设置文本颜色
//	settextcolor(RED);
//
//	//设置文本样式
//	settextstyle(10, 0, "黑体");//字体的宽+字体的高+字体的风格
//
//	outtextxy(20, 5, s16);
//	outtextxy(250, 5, s17);
//
//
//	
//
//	//设置文本颜色
//	settextcolor(LIGHTBLUE);
//
//	//设置文本样式
//	settextstyle(20, 0, "宋体");//字体的宽+字体的高+字体的风格
//
//	outtextxy(20, 20, s1);
//	outtextxy(20, 45, s2);
//	outtextxy(20, 70, s3);
//	outtextxy(20, 95, s4);
//	outtextxy(20, 120, s5);
//	outtextxy(20, 145, s6);
//	outtextxy(20, 170, s7);
//	outtextxy(20, 195, s8);
//	outtextxy(20, 220, s9);
//	outtextxy(20, 245, s10);
//	outtextxy(20, 270, s11);
//	outtextxy(20, 295, s12);
//	outtextxy(20, 320, s13);
//
//	
//	outtextxy(250, 20, s14);
//	outtextxy(250, 45, s15);
//	outtextxy(250, 70, s18);
//}
//
//void MOUSE_Picture() {
//	if (MouseHit()) {
//		MOUSEMSG m = GetMouseMsg();//获取鼠标信息
//		if (m.uMsg == WM_LBUTTONDOWN) {
//			if (m.x <= 220 && m.x >= 140 && m.y <= 250 && m.y >= 220)
//			{
//				putimage(m.x, m.y, &maoshan);
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 270 && m.x >= 190 && m.y <= 370 && m.y >= 315)
//			{
//				putimage(m.x, m.y, &SilverNoodles); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 340 && m.x >= 255 && m.y <= 300 && m.y >= 275)
//			{
//				putimage(m.x, m.y, &hualuogeng); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 210 && m.x >= 80 && m.y <= 505 && m.y >= 470)
//			{
//				putimage(m.x, m.y, &NewFourthArmy); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 220 && m.x >= 150 && m.y <= 650 && m.y >= 620)
//			{
//				putimage(m.x, m.y, &BenedictionTemple);
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 340 && m.x >= 245 && m.y <= 470 && m.y >= 430)
//			{
//				putimage(m.x, m.y, &Geopark); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 315 && m.x >= 230 && m.y <= 655 && m.y >= 625)
//			{
//				putimage(m.x, m.y, &TianmuLake); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 300 && m.x >= 240 && m.y <= 760 && m.y >= 730)
//			{
//				putimage(m.x, (m.y - 200), &NanshanBambooSea); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 580 && m.x >= 455 && m.y <= 320 && m.y >= 265)
//			{
//				putimage(m.x, m.y, &yancheng); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 600 && m.x >= 530 && m.y <= 205 && m.y >= 180)
//			{
//				putimage(m.x, m.y, &museum); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 690 && m.x >= 630 && m.y <= 225 && m.y >= 200)
//			{
//				putimage(m.x, m.y, &dinosaur); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 600 && m.x >= 665 && m.y <= 260 && m.y >= 235)
//			{
//				putimage(m.x, m.y, &tianningTemple); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//			else if (m.x <= 720 && m.x >= 630 && m.y <= 490 && m.y >= 400)
//			{
//				putimage((m.x - 200), m.y, &joyland); 
//				Sleep(1000);
//				putimage(0, 0, &map);
//				Outputtext();
//			}
//
//
//		}
//
//		//刷新地图页面
//		if (m.uMsg == WM_RBUTTONDOWN) {
//			putimage(0, 0, &map);
//			Outputtext();
//			
//		}
//	}
//
//}
//
//
//
//// 主函数
//int main()
//{
//	initgraph(width, height);
//	//全局资源导入
//	loadimage(&map, _T("D:\\IMAGE\\map.jpg"), width, height);
//	loadimage(&white, _T("D:\\IMAGE\\white.jpg"), width, height);
//	loadimage(&BenedictionTemple, _T("D:\\IMAGE\\BenedictionTemple.jpg"), width1, height1);
//	loadimage(&dinosaur,  _T("D:\\IMAGE\\dinosaur.jpg"), width1, height1);
//	loadimage(&Geopark, _T("D:\\IMAGE\\Geopark.jpg"), width1, height1);
//	loadimage(&hualuogeng, _T("D:\\IMAGE\\hualuogeng.jpg"), width1, height1);
//	loadimage(&joyland, _T("ED:\\IMAGE\\joyland.jpg"), width1, height1);
//	loadimage(&maoshan,_T("D:\\IMAGE\\maoshan.jpg"), width1, height1);
//	loadimage(&NewFourthArmy, _T("D:\\IMAGE\\NewFourthArmy.jpg"), width1, height1);
//	loadimage(&SilverNoodles, _T("D:\\IMAGE\\SilverNoodles.jpg"), width1, height1);
//	loadimage(&TianmuLake, _T("D:\\IMAGE\\TianmuLake.jpg"), width1, height1);
//	loadimage(&tianningTemple, _T("D:\\IMAGE\\tianningTemple.jpg"), width1, height1);
//	loadimage(&yancheng,_T("D:\\IMAGE\\yancheng.jpg"), width1, height1);
//	loadimage(&NanshanBambooSea,_T("D:\\IMAGE\\NanshanBambooSea.jpg"), width1, height1);
//	loadimage(&museum, _T("D:\\IMAGE\\museum.jpg"), width1, height1);
//
//	putimage(0, 0, &map);
//	Outputtext();
//	changzhou = initgraph();
//
//
//	//c = initgraph();
//	while (1) {
//
//		MOUSE_Picture();
//		
//
//		char input;
//		//选择服务
//		if (_kbhit()) {
//			
//			input = getch();
//				if (input=='a') {
//								Query(); //查询景点信息
//
//							}
//				else if (input == 'b') {
//							DrawPath(); //最短路线
//
//						}	
//				else if (input == 'c'){
//					Changegraph(); //编辑图信息
//				}
//		
//	}
//			
//	}
//	system("pause");
//	closegraph;//关闭画布
//	return 0;
//
//}
//
//
//

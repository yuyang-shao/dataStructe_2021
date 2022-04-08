#undef UNICODE
#undef _UNICODE
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)//��ֹvs2019����ʹ����˳������
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
#define height 799//��Ϸ����ߴ�
#define width1 200  //����ͼƬ�ߴ�
#define height1 200
#define Infinity 20000//Լ����2000����������󣬼�����ͨ
#define MaxVertexNum 20//Լ���������20�����㣨���㣩
#define MAX 40 
#define key 13//Ĭ�϶�����Ϊ13
#define lock 20//Ĭ�ϱ���Ϊ20
#define MaxMidNum 5//Լ���������5���м�㣨���㣩
#define MaxRow 120 //Լ��ȫ�����������Ϊ120����5����

IMAGE map, BenedictionTemple, dinosaur, Geopark, hualuogeng, white,
joyland, maoshan, museum, NewFourthArmy, SilverNoodles, TianmuLake, tianningTemple, yancheng, NanshanBambooSea;

typedef struct vexsinfo//���㣨���㣩�ṹ��
{
	char name[32];//���� 
	int position;//����
	char introduction[256];//���---���ܲ˵�5 
	char super_introduction[512];//��ϸ����---���ܲ˵�6 
	int x;  //��������
	int y;
}vexsinfo;

typedef struct arcell//�ߣ�·�����ṹ��
{
	int adj;//Ȩֵ  
}arcell, adjmatrix[MaxVertexNum][MaxVertexNum];//�ڽӾ���

typedef struct mgraph//ͼ�ṹ��
{
	vexsinfo vexs[MaxVertexNum];//�������� 
	adjmatrix arcs;//�ڽӾ��� 
	int vexnum, arcnum;//���㣨vertex�����ͱߣ�arc���� 
}mgraph;

void dfs(mgraph* c, int a, int b);
void allroad(mgraph c);
void swap(int* a, int* b);
void allRange(int* a, int k, int len);      //ʵ��ȫ����
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

//ȫ�ֱ���

int shortest[MaxVertexNum][MaxVertexNum];//���·�� 
int pathh[MaxVertexNum][MaxVertexNum];
int rangeArray[MaxRow][MaxMidNum];
int visited[MaxVertexNum] = { 0 };
int road[MaxVertexNum];
int m = 1;
mgraph changzhou; //����ͼ
//��ʼ��ͼ��ϵͳ

mgraph initgraph()
{
	int i = 0, j = 0;
	mgraph c;
	c.vexnum = key;  //������
	c.arcnum = lock;  //����

	//���þ������
	for (i = 1; i <= key; i++)
		c.vexs[i].position = i;

	//string copy������Ϣ ����������ƣ���ϸ���ܣ����
	strcpy(c.vexs[1].name, "éɽ�羰��");
	strcpy(c.vexs[1].super_introduction, "\néɽ�羰����éɽ��ʤ���أ��羰������2001�걻��Ϊ����AAAA��������\n");
	strcpy(c.vexs[1].introduction, "����ط���ɽ");

	strcpy(c.vexs[2].name, "��˿��");
	strcpy(c.vexs[2].super_introduction, "\n��˿�棺��ϸ��˿��ɫ������������ˬ���������ԣ��¹�����\n");
	strcpy(c.vexs[2].introduction, "�ط���ͳ��ʳС��");

	strcpy(c.vexs[3].name, "���޸������");
	strcpy(c.vexs[3].super_introduction, "\n��Է���ײͣ��ǽ������������֣����������࣬���ӣ���ͷ��Ӧ�о��У��������θ��\n");
	strcpy(c.vexs[3].introduction, "��ʳ����");

	strcpy(c.vexs[4].name, "�л���Գ���ʹ�԰");
	strcpy(c.vexs[4].super_introduction, "\n�л���Գ���ʹ�԰���滮�������������ʪ�ؼ�ˮĸɽ��ַ�����л���Գ��ʯ�ķ��ֵ�\n");
	strcpy(c.vexs[4].introduction, "ʡ��ʪ�ع�԰");

	strcpy(c.vexs[5].name, "��������");
	strcpy(c.vexs[5].super_introduction, "\n�������£������������ڴ���ɫ�ʵġ�ˮ����ɽ���ġ���ɽ�¡������ٸ��صġ���ɽ��\n");
	strcpy(c.vexs[5].introduction, "����ʥ��");

	strcpy(c.vexs[6].name, "��Ŀ���ȼ���");
	strcpy(c.vexs[6].super_introduction, "\n��Ŀ����λ�ڳ����������ϰ˹��ﴦ��������Ŀɽ��������������Ŀ������\n");
	strcpy(c.vexs[6].introduction, "���������顱������ɫ�ɾ���");

	strcpy(c.vexs[7].name, "��ɽ��");
	strcpy(c.vexs[7].super_introduction, "\n��ɽ�񺣣����������Ļ������Ļ�Ϊ���⣬��ӵ3.5��Ķ����\n");
	strcpy(c.vexs[7].introduction, "������ɽ���λ���");

	strcpy(c.vexs[8].name, "�й������ͳ�������");
	strcpy(c.vexs[8].super_introduction, "\n�й������ͳ������������й���Ϊ����Ҳ��Ϊ�����ĵ���ǳ���ַ\n");
	strcpy(c.vexs[8].introduction, "����ǳ���ַ");

	strcpy(c.vexs[9].name, "��������Ϸ��");
	strcpy(c.vexs[9].super_introduction, "\n��������Ϸ�ȣ���δ�й��ġ�����δ֪�ġ���Խ��ʵ�ġ�������硱������ʵ��������԰\n");
	strcpy(c.vexs[9].introduction, "������������Ϸ�Ļ�");

	strcpy(c.vexs[10].name, "���ݲ����");
	strcpy(c.vexs[10].super_introduction, "\n���ݲ���ݣ��Ǽ��ղء��о�������չ����һ��ĵط��ۺ��Բ����\n");
	strcpy(c.vexs[10].introduction, "����һ�������");

	strcpy(c.vexs[11].name, "���������");
	strcpy(c.vexs[11].super_introduction, "\n��������ǣ�һ����չʾ�����ա����֡����м������Ա�����һ��Ŀ���Ϊ�����һվʽ���ζȼ���.\n");
	strcpy(c.vexs[11].introduction, "���ζȼ���");

	strcpy(c.vexs[12].name, "��������");
	strcpy(c.vexs[12].super_introduction, "\n�������£��ǳ����ִ��ģ��󣬱�����������ǧ���ɲ\n");
	strcpy(c.vexs[12].introduction, "�й������Ĵ����");

	strcpy(c.vexs[13].name, "���ľ�����ָ�Ӳ������");
	strcpy(c.vexs[13].super_introduction, "\n���ľ�����ָ�Ӳ�����ݣ���һ�����й�����ʷ�;���ʷ�϶�����Ҫ��λ�ĵط�\n");
	strcpy(c.vexs[13].introduction, "ָ�Ӳ���ַ");

	//ȷ�����������
	c.vexs[1].x = 145;
	c.vexs[1].y = 238;//éɽ

	c.vexs[2].x = 200;
	c.vexs[2].y = 330;//��˿��

	c.vexs[3].x = 330;
	c.vexs[3].y = 285;//���޸������

	c.vexs[4].x = 320;
	c.vexs[4].y = 445;//�л���Գ���ʹ�԰

	c.vexs[5].x = 170;
	c.vexs[5].y = 640;//��������

	c.vexs[6].x = 250;
	c.vexs[6].y = 640;//��Ŀ���ȼ���

	c.vexs[7].x = 260;
	c.vexs[7].y = 750;//��ɽ��

	c.vexs[8].x = 470;
	c.vexs[8].y = 320;//�й������ͳ�������

	c.vexs[9].x = 650;
	c.vexs[9].y = 470;//��������Ϸ��

	c.vexs[10].x = 550;
	c.vexs[10].y = 230;//���ݲ����

	c.vexs[11].x = 630;
	c.vexs[11].y = 210;//���������

	c.vexs[12].x = 620;
	c.vexs[12].y = 250;//��������

	c.vexs[13].x = 160;
	c.vexs[13].y = 490; //���ľ�


	//��ʼ���ڽӾ���Ȩֵ��Ϊ����󣬼����ж��㻥������
	for (i = 1; i <= key; i++)
		for (j = 1; j <= key; j++)
			c.arcs[i][j].adj = Infinity; //�ڽӾ���Ȩֵ���޴�2000��

	//�涨�������ͨ���������߶�Ӧ��Ȩֵ������1����2����Ȩ��G[��1][��2] = weight 
	//��ͨ�������㣬ȷ������������
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

	//����ͼ�ԳƸ�ֵ
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
//�ݹ���ȱ�������A�㵽B������·��
//�ο���https://www.ixueshu.com/document/b182fab31af30eb123354954e9327cd8318947a18e7f9386.html
void dfs(mgraph* c, int a, int b)            //�ݹ����A�㵽B������·��
{
	visited[a] = 1;                //��Ǹõ��Ѿ�������
	int i, j, k = b;
	for (i = 1; i <= c->vexnum; i++)
	{
		if (c->arcs[a][i].adj < Infinity && visited[i] == 0)
		{
			if (i == b)
			{
				//				srand((unsigned)time( NULL ) );
				setlinestyle(0, 2);
				int x, y, z;                      //�������3�������
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
				setlinecolor(RGB(x, y, z));    //�ò�ͬ��ɫ����·��
				for (j = 0; j < m - 1; j++)
				{
					setlinestyle(0, 2);
					line(c->vexs[road[j]].x, c->vexs[road[j]].y, c->vexs[road[j + 1]].x, c->vexs[road[j + 1]].y);
				}
				line(c->vexs[road[m - 1]].x, c->vexs[road[m - 1]].y, c->vexs[b].x, c->vexs[b].y);
			}
			else
			{
				road[m] = i;             //road����·��
				m++;
				dfs(c, i, k);                //�ݹ�
				visited[i] = 0;
				m--;
			}
		}
	}
}

//������֮������·��
void allroad(mgraph c)
{
	putimage(0, 0, &white);
	drawCircle(changzhou);
	int i, j;
	char s1[10], s2[10];
	outtextxy(300, 100, _T("������Ҫ��ѯ����������Ĵ���"));
	InputBox(s1, 10, _T("���������"));
	// ���û�����ת��Ϊ����
	sscanf(s1, "%d", &i);
	InputBox(s2, 10, _T("�������յ�"));
	// ���û�����ת��Ϊ����
	sscanf(s2, "%d", &j);
	road[0] = i;
	dfs(&c, i, j);
}

//̰��+dij�㷨�󾭹�ָ���е�����·��
//�ο���https://wenku.baidu.com/view/034f89ad1eb91a37f1115cca.html
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void allRange(int* a, int k, int len)     //ָ��a��ʾ�м������,len��ʾ�����м�����
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
//������֮�����·��
int shortestpath_dij(mgraph c, int v0, int Vend, int isdraw)
{
	int v, w, k = 1, min, t, p;
	int final[MaxVertexNum];//final[w]=1��ʾ�Ѿ���ö���V0��W�����·��
	int Patharc[MaxVertexNum];//���ֱ��ǰ��
	int ShortPathtable[MaxVertexNum];//�洢Ȩֵ��

	//��ʼ��
	for (v = 1; v <= c.vexnum; v++)
	{
		final[v] = 0;
		ShortPathtable[v] = c.arcs[v0][v].adj;
		Patharc[v] = v0;
	}

	ShortPathtable[v0] = 0;
	final[v0] = 1;

	//dij�㷨
	for (v = 2; v <= c.vexnum; v++)    //v��2��ʼ�����Ǵ�1��ʼ��ÿ��ѭ�����v0��һ����������·��
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

		//�������·�� 
		for (w = 1; w <= c.vexnum; w++)
		{
			if (!final[w] && (min + c.arcs[k][w].adj < ShortPathtable[w]))
			{
				ShortPathtable[w] = min + c.arcs[k][w].adj;//����·������
				Patharc[w] = k;//���ֱ��ǰ��

			}
		}
	}
	if (isdraw == 1)     //�������·��
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

//�󾭹��м�㼯���е�����·��
int PathMidNode(mgraph c, int i, int n, int isdraw)   //i��ʾȫ���о����������n����ȫ���о��������,n��ʾ�м��ĸ���
{
	int dist = 0;    //dist�������м�㼯���е���Ҫ�����ľ���
	int dis = 0;    //disΪ���е�㼯��ÿ�����ľ���
	for (int j = 0; j < n - 1; j++)              //֮����С��n-1����Ϊj+1<=n-1
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

//���������(����ָ���м��)
void finalShortest(mgraph c)
{

	putimage(0, 0, &white);
	drawCircle(changzhou);
	outtextxy(300, 100, _T("������Ҫ��ѯ����������Ĵ���"));
	int i, j; //Ҫ��ѯ����������Ĵ���
	int n, row = 1;    //n��ʾҪ�������м������(ȫ���о���������,row����ȫ��������
	int* a;
	//	int a[5];
	int path = Infinity, temp, road = -1, midPath;  //road �����е㼯��·��
	char s1[10], s2[10], s3[10];
	InputBox(s1, 10, _T("���������"));
	// ���û�����ת��Ϊ����
	sscanf(s1, "%d", &i);
	InputBox(s2, 10, _T("�������յ�"));
	// ���û�����ת��Ϊ����
	sscanf(s2, "%d", &j);
	InputBox(s3, 10, _T("��������Ҫ�����ĵ���"));
	// ���û�����ת��Ϊ����
	sscanf(s3, "%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (int d = 0; d < n; d++)
	{
		char s[10];
		InputBox(s, 10, _T("�������м��"));
		// ���û�����ת��Ϊ����
		sscanf(s, "%d", &a[d]);
	}

	allRange(a, 0, n - 1);    //����ȫ����

	for (int b = n; b > 0; b--)
	{
		row *= b;
	}
	for (int m = 0; m < row; m++)
	{
		midPath = PathMidNode(changzhou, m, n, 0);
		temp = shortestpath_dij(changzhou, i, rangeArray[m][0], 0) + midPath + shortestpath_dij(changzhou, rangeArray[m][n - 1], j, 0);   //0��ʾ������
		if (temp < path)
		{
			path = temp;
			road = m;     //m����ȫ���о���ĵ�m��,��m��ȫ����

		}
	}
	shortestpath_dij(changzhou, i, rangeArray[road][0], 1);

	shortestpath_dij(changzhou, rangeArray[road][n - 1], j, 1);
	PathMidNode(changzhou, road, n, 1);
	char str[150];
	sprintf(str, "%s��%s�����·����:%dm", c.vexs[i].name, c.vexs[j].name, path);
	outtextxy(50, 50, str);
}

//33���������㷨
void floyd(mgraph c)
{
	int i, j, k;
	for (i = 1; i <= c.vexnum; i++)
	{
		for (j = 1; j <= c.vexnum; j++)
		{
			shortest[i][j] = c.arcs[i][j].adj;
			pathh[i][j] = j;//����i������j�����·���Ǿ���j 
		}
	}

	printf("\n\n\n");

	//���Ĳ������㷨�ο���ַ��https://www.cnblogs.com/skywang12345/p/3711523.html 
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
					//����i������j�����·���Ǿ���k 
				}
			}
		}
	}
}
//33��ӡ���·�� 
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
		//�ݹ�
		line(c.vexs[k].x, c.vexs[k].y, c.vexs[pathh[k][j]].x, c.vexs[pathh[k][j]].y);
		k = pathh[k][j];
	}
	//	line(c.vexs[pathh[i][j]].x, c.vexs[pathh[i][j]].y, c.vexs[b].x, c.vexs[b].y);
	//printf("%s-->%s�����·���ǣ�%d �ס�\n\n", c.vexs[a].name, c.vexs[b].name, shortest[a][b]);
	char str[150];
	sprintf(str, "%s��%s�����·����:%dm", c.vexs[a].name, c.vexs[b].name, shortest[a][b]);
	outtextxy(0, 155, str);
}
//�����·��
void DrawPath() {

	putimage(0, 0, &white);
	drawCircle(changzhou);
	Outputtext();
	outtextxy(0, 180, _T("������Ҫ��ѯ����������Ĵ���"));
	int i, j; //Ҫ��ѯ����������Ĵ���

	char s1[10];
	InputBox(s1, 10, _T("���������"));
	// ���û�����ת��Ϊ����
	sscanf(s1, "%d", &i);
	char s2[10];
	InputBox(s2, 10, _T("�������յ�"));
	// ���û�����ת��Ϊ����
	sscanf(s2, "%d", &j);
	floyd(changzhou);
	display(changzhou, i, j);


}





//7�ж϶����Ƿ���ͼ��
int locatevex(mgraph c, int v)
{
	int i;
	for (i = 1; i <= c.vexnum; i++)
		if (v == c.vexs[i].position)
			return i;//���ҵ�
	return -1;//δ�ҵ�
}
//���½�ͼ
void creatgraph(mgraph* c)
{
	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(40, 0, _T("����"));//����Ŀ�+����ĸ�+����ķ��

	// ����Ļ��������ַ���
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("���½�ͼ"), &r, DT_CENTER | DT_WORDBREAK);

	//�����ı���ɫ
	settextcolor(BLUE);

	//�����ı���ʽ
	settextstyle(30, 0, _T("����"));//����Ŀ�+����ĸ�+����ķ��
	outtextxy(200, 100, _T("������:"));
	outtextxy(200, 145, _T("����:"));
	int i, j, m, n, v0, v1, distance;

	//������
	char s1[10];
	InputBox(s1, 10, _T("�����붥����"));
	outtextxy(300, 100, s1);

	//����
	char s2[10];
	InputBox(s2, 10, _T("���������"));
	outtextxy(300, 145, s2);

	// ���û�����ת��Ϊ����
	sscanf(s1, "%d", &c->vexnum);
	sscanf(s2, "%d", &c->arcnum);

	//�����ı���ʽ
	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��
	settextcolor(CYAN);
	char s3[10];
	char s4[20];
	char s5[256];
	char s6[512];
	char s11[10];
	char s10[10];
	for (i = 1; i <= c->vexnum; i++)
	{


		outtextxy(0, 145 + 30 * i, _T("�������:"));
		outtextxy(100, 145 + 30 * i, _T("��������:"));
		outtextxy(250, 145 + 30 * i, _T("������:"));
		outtextxy(400, 145 + 30 * i, _T("������ϸ����:"));
		outtextxy(590, 145 + 30 * i, _T("x������:"));
		outtextxy(695, 145 + 30 * i, _T("y������:"));

	}
	settextcolor(BLUE);
	for (i = 1; i <= c->vexnum; i++)
	{
		c->vexs[i].position = i;
		//		InputBox(s3, 10, _T("�����뾰��Ĵ���:"));
		sprintf(s3, "%d", c->vexs[i].position);
		outtextxy(80, 145 + 30 * i, s3);

		InputBox(s4, 10, _T("�����뾰�������:"));
		sscanf(s4, "%s", &c->vexs[i].name);
		outtextxy(190, 145 + 30 * i, s4);

		InputBox(s5, 10, _T("�����뾰��ļ��:"));
		sscanf(s5, "%s", &c->vexs[i].introduction);
		outtextxy(340, 145 + 30 * i, s5);

		InputBox(s6, 10, _T("�����뾰�����ϸ����:"));
		sscanf(s6, "%s", &c->vexs[i].super_introduction);
		outtextxy(550, 145 + 30 * i, s6);

		InputBox(s11, 10, _T("�����뾰��x������:"));
		sscanf(s11, "%d", &c->vexs[i].x);
		outtextxy(680, 145 + 30 * i, s11);

		InputBox(s10, 10, _T("�����뾰���y������:"));
		sscanf(s10, "%d", &c->vexs[i].y);
		outtextxy(780, 145 + 30 * i, s10);

	}
	//��ʼ��ȨֵΪ����󣨲���ͨ��
	for (i = 1; i <= c->vexnum; i++)
	{
		for (j = 1; j <= c->vexnum; j++)
		{
			c->arcs[i][j].adj = Infinity;
		}
		c->arcs[i][i].adj = 0;
	}


	//printf("�����ߵ���Ϣ��\n");

	//�����ı���ɫ
	settextcolor(RED);
	//�����ı���ʽ
	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��
	outtextxy(300, 145 + 50 * (c->vexnum + 1), _T("�����ߵ���Ϣ"));

	for (i = 1; i <= c->arcnum; i++)
	{

		outtextxy(0, 145 + 50 * (c->vexnum + 1 + i), _T("���"));
		outtextxy(150, 145 + 50 * (c->vexnum + 1 + i), _T("�յ�"));
		outtextxy(300, 145 + 50 * (c->vexnum + 1 + i), _T("����"));

	}
	char s7[10];
	char s8[10];
	char s9[10];
	for (i = 1; i <= c->arcnum; i++)
	{
		InputBox(s7, 10, _T("���"));
		outtextxy(100, 145 + 50 * (c->vexnum + 1 + i), s7);
		InputBox(s8, 10, _T("�յ�"));
		outtextxy(250, 145 + 50 * (c->vexnum + 1 + i), s8);
		InputBox(s9, 10, _T("����"));
		outtextxy(400, 145 + 50 * (c->vexnum + 1 + i), s9);
		sscanf(s7, "%d", &v0);
		sscanf(s8, "%d", &v1);
		sscanf(s9, "%d", &distance);

		m = locatevex(changzhou, v0);
		n = locatevex(changzhou, v1);
		if (m > 0 && n > 0)
		{
			//����ͼ�ԳƸ�ֵ
			c->arcs[m][n].adj = distance;
			c->arcs[n][m].adj = c->arcs[m][n].adj;
		}
	}

}
//7ɾ������
int delvex(mgraph* c)
{
	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(40, 0, _T("����"));//����Ŀ�+����ĸ�+����ķ��

	// ����Ļ��������ַ���
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("ɾ������"), &r, DT_CENTER | DT_WORDBREAK);

	int i = 0, j;
	int  v;
	//�����ı���ʽ
	settextstyle(60, 0, "����");//����Ŀ�+����ĸ�+����ķ��
	if (c->vexnum <= 0)
	{
		outtextxy(300, 100, _T("ͼ�����޶���,������ɾ��"));
		return 1;
	}

	//�����ı���ʽ
	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
	//�����ı���ɫ
	settextcolor(RED);
	outtextxy(20, 180, _T("�������ɾ���ľ�����ţ�"));
	char s1[10];
	InputBox(s1, 10, _T("�������ɾ���ľ������"));
	outtextxy(500, 180, s1);
	// ���û�����ת��Ϊ����
	sscanf(s1, "%d", &v);

	while (v <= 0 || v > c->vexnum)
	{
		outtextxy(300, 100, _T("���Ŵ���"));
		return 1;
	}


	//ɾ���ڽӾ���ĵ�v��
	for (i = v; i <= c->vexnum - 1; i++)
		for (j = 1; j <= c->vexnum; j++)
			c->arcs[i][j] = c->arcs[i + 1][j];

	//ɾ���ڽӾ���ĵ�v��
	for (i = v; i <= c->vexnum - 1; i++)
		for (j = 1; j <= c->vexnum - 1; j++)
			c->arcs[j][i] = c->arcs[j][i + 1];

	//ɾ�����������е�v��
	for (int k = v; k <= c->vexnum - 1; k++)
	{
		c->vexs[k] = c->vexs[k + 1];
		c->vexs[k].position = c->vexs[k].position - 1;
	}
	c->vexnum--;



	outtextxy(300, 350, _T("����ɾ���ɹ�"));
	return 1;
}
//7ɾ����
int delarc(mgraph* c)
{
	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��

	// ����Ļ��������ַ���
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("ɾ����"), &r, DT_CENTER | DT_WORDBREAK);

	int  v0, v1;

	//�����ı���ʽ
	settextstyle(60, 0, _T("����"));//����Ŀ�+����ĸ�+����ķ��
	if (c->vexnum <= 0)
	{
		outtextxy(300, 100, _T("ͼ�����ޱ�,������ɾ��"));
		return 1;
	}
	//�����ı���ʽ
	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
	//�����ı���ɫ
	settextcolor(RED);
	outtextxy(20, 180, _T("�������ɾ���������ţ�"));
	outtextxy(20, 230, _T("�������ɾ�����յ���ţ�"));
	char s1[10];
	InputBox(s1, 10, _T("�������ɾ����������"));
	outtextxy(500, 180, s1);
	char s2[10];
	InputBox(s2, 10, _T("�������ɾ�����յ����"));
	outtextxy(500, 230, s2);
	// ���û�����ת��Ϊ����
	sscanf(s1, "%d", &v0);
	sscanf(s2, "%d", &v1);

	while (v0 <= 0 || v0 > c->vexnum || v1 <= 0 || v1 > c->vexnum)
	{
		outtextxy(300, 100, _T(" ���Ŵ���"));
		return 1;
	}
	//����ͼ�ԳƸ�ֵ
	c->arcs[v0][v1].adj = Infinity;
	c->arcs[v1][v0].adj = Infinity;
	c->arcnum--;

	outtextxy(300, 100, _T("��ɾ���ɹ�!"));
	return 1;
}
//7���Ӷ���
int envex(mgraph* c)
{
	int i = c->vexnum + 1;
	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(40, 0, _T("����"));//����Ŀ�+����ĸ�+����ķ��

	// ����Ļ��������ַ���
	RECT r = { 0, 0, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("���Ӷ���"), &r, DT_CENTER | DT_WORDBREAK);


	//�����ı���ʽ
	settextstyle(40, 0, _T("����"));//����ĸ�+����Ŀ�+����ķ��
	//�����ı���ɫ
	settextcolor(RED);
	c->vexs[i].position = i;
	outtextxy(20, 230, _T("������������ľ������ƣ�"));
	outtextxy(20, 280, _T("������������ľ����飺"));
	outtextxy(20, 330, _T("������������ľ�����ϸ���ܣ�"));
	outtextxy(20, 380, _T("������������ľ���x�����꣺"));
	outtextxy(20, 430, _T("������������ľ���y�����꣺"));
	char s4[20], s5[256], s6[512], s11[10], s10[10];

	InputBox(s4, 20, _T("�����뾰�������:"));
	sscanf(s4, "%s", &c->vexs[i].name);
	outtextxy(590, 230, s4);

	InputBox(s5, 256, _T("�����뾰��ļ��:"));
	sscanf(s5, "%s", &c->vexs[i].introduction);
	outtextxy(590, 280, s5);

	InputBox(s6, 512, _T("�����뾰�����ϸ����:"));
	sscanf(s6, "%s", &c->vexs[i].super_introduction);
	outtextxy(590, 330, s6);

	InputBox(s11, 10, _T("�����뾰��x������:"));
	sscanf(s11, "%d", &c->vexs[i].x);
	outtextxy(590, 380, s11);

	InputBox(s10, 10, _T("�����뾰���y������:"));
	sscanf(s10, "%d", &c->vexs[i].y);
	outtextxy(590, 430, s10);
	c->vexnum++;
	//	����ͼ�ԳƸ�ֵ
	for (i = 1; i <= c->vexnum; i++)
	{
		c->arcs[c->vexnum][i].adj = Infinity;
		c->arcs[i][c->vexnum].adj = Infinity;
	}
	c->arcs[c->vexnum][c->vexnum].adj = 0;


	outtextxy(300, 480, _T("������ӳɹ�"));
	return 1;
}
//7���ӱ�
int enarc(mgraph* c)
{

	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��

	// ����Ļ��������ַ���
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("���ӱ�"), &r, DT_CENTER | DT_WORDBREAK);
	int  v0, v1, distance;

	//�����ı���ʽ
	settextstyle(60, 0, _T("����"));//����Ŀ�+����ĸ�+����ķ��
	//�����ı���ʽ
	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
	//�����ı���ɫ
	settextcolor(RED);
	outtextxy(20, 180, _T("������������ıߵ������ţ�"));
	outtextxy(20, 230, _T("������������ıߵ��յ���ţ�"));
	outtextxy(20, 280, _T("������������ıߵĳ���(Ȩֵ)��"));
	char s1[10];
	InputBox(s1, 10, _T("������������ıߵ�������"));
	outtextxy(590, 180, s1);
	char s2[10];
	InputBox(s2, 10, _T("������������ıߵ��յ����"));
	outtextxy(590, 230, s2);
	char s3[10];
	InputBox(s3, 10, _T("������������ıߵĳ���"));
	outtextxy(590, 280, s3);
	// ���û�����ת��Ϊ����
	sscanf(s1, "%d", &v0);
	sscanf(s2, "%d", &v1);
	sscanf(s3, "%d", &distance);
	if (c->arcs[v0][v1].adj < Infinity)
	{
		outtextxy(300, 100, _T("ͼ�����б�,����������"));
		return 1;
	}


	//����ͼ�ԳƸ�ֵ
	c->arcs[v0][v1].adj = distance;
	c->arcs[v1][v0].adj = c->arcs[v0][v1].adj;
	c->arcnum++;
	outtextxy(300, 100, _T("�������ɹ�!"));

	return 1;
}

//7����ڽӾ���
void printmatrix(mgraph c)
{
	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��

	// ����Ļ��������ַ���
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("����ڽӾ���\nԼ����2000����������󣬼�����ͨ"), &r, DT_CENTER | DT_WORDBREAK);
	int i, j, k = 0, t = 0;
	settextstyle(11, 0, "����");
	char s[10];
	//sprintf(s, "%d", c.arcs[1][2].adj);//������aת�����ַ���
	//outtextxy(20  , 120  , s);

	settextcolor(BLUE);
	settextstyle(15, 0, "����");

	for (i = 1; i <= c.vexnum; i++)
	{
		sprintf(s, "%d", i);//������aת�����ַ���
		outtextxy(i * 50 - 30, 80, i);
	}

	settextcolor(RED);
	settextstyle(11, 0, "����");
	for (i = 1; i <= c.vexnum; i++)
	{
		for (j = 1; j <= c.vexnum; j++)
		{
			sprintf(s, "%d", c.arcs[i][j].adj);//������aת�����ַ���
			outtextxy(20 + k * 50, 120 + t * 40, s);
			//printf("%-6d", c.arcs[i][j].adj);
			k++;
			//�жϻ���ʱ��
			if (k % c.vexnum == 0)
			{
				printf("\n");
				k = 0;
				t++;//����
			}
		}
	}


}
//77�޸�ͼ��Ϣ
void Changegraph()
{
	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��

	// ����Ļ��������ַ���
	RECT r = { 0, 0, width - 1, height - 1 };
	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("���±༭ͼ����Ϣ,��ѡ����Ҫ���еĲ���"), &r, DT_CENTER | DT_WORDBREAK);

	//�����ı���ɫ
	settextcolor(BLUE);
	//�����ı���ʽ
	settextstyle(30, 0, "����");//����Ŀ�+����ĸ�+����ķ�� 
	RECT r1 = { 0,50,width - 1 ,height - 1 };
	drawtext(_T("1.���½�ͼ\n2.ɾ������\n3.ɾ����\n4.���Ӷ���\n5.���ӱ�\n 6.����ڽӾ���"), &r1, DT_CENTER | DT_WORDBREAK);
	switch (getch())
	{

	case 49://���½�ͼ1
		creatgraph(&changzhou);
		break;
	case 50://ɾ������2
		delvex(&changzhou);
		break;
	case 51://ɾ����3
		delarc(&changzhou);
		break;
	case 52://���Ӷ���4
		envex(&changzhou);
		break;
	case 53://���ӱ�5
		enarc(&changzhou);
		break;
	case 54://����ڽӾ���
		printmatrix(changzhou);
		break;
	
	default://�����쳣

		break;
	}
}
//*��ѯ����ҳ��
void Query(mgraph c) {
	//	TCHAR st1[] = _T("éɽ�羰��");
	//	TCHAR st2[] = _T("��˿��");
	//	TCHAR st3[] = _T("���޸������");
	//	TCHAR st4[] = _T("�л���Գ���ʹ�԰");
	//	TCHAR st5[] = _T("��������");
	//	TCHAR st6[] = _T("��Ŀ���ȼ���");
	//	TCHAR st7[] = _T("��ɽ��");
	//	TCHAR st8[] = _T("�й������ͳ�������");
	//	TCHAR st9[] = _T("��������Ϸ��");
	//	///*TCHAR st10[] = _T("���ݲ����");
	//	//TCHAR st11[] = _T("���������");
	//	//TCHAR st12[] = _T("��������");
	//	//TCHAR st13[] = _T("���ľ�����ָ�Ӳ������");*/
	//	TCHAR st10[] = _T("���ݲ����");
	//	TCHAR st11[] = _T("���������");
	//	TCHAR st12[] = _T("��������");
	//	TCHAR st13[] = _T("���ľ�����ָ�Ӳ������");
	TCHAR st14[] = _T("������ţ�");
	TCHAR st15[] = _T("�������ƣ�");
	TCHAR st16[] = _T("��ϸ���ܣ�");
	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��

	// ����Ļ��������ַ���
	RECT r = { 0, 0, width - 1, height - 1 };
	//	RECT r0 = { 250, 100, width - 1, height - 1 };
	putimage(0, 0, &white);
	drawtext(_T("��ѯ������Ϣ����������Ҫ��ѯ�ľ������"), &r, DT_CENTER | DT_WORDBREAK);

	//�����ı���ɫ
	settextcolor(BLUE);
	//�����ı���ʽ
	settextstyle(30, 0, _T("����"));//����Ŀ�+����ĸ�+����ķ�� 
	RECT r1 = { 0,50,width - 1 ,height - 1 };
	//		 drawtext(_T("1.éɽ�羰��\n2.��˿��\n3.���޸������\n4.�л���Գ���ʹ�԰\n5.��������\n6.��Ŀ���ȼ���\n 7.��ɽ��\n8.�й������ͳ�������\n9.��������Ϸ��\n10.���ݲ����\n11.���������\n12.��������\n13.���ľ�����ָ�Ӳ������\n"), &r1, DT_CENTER | DT_WORDBREAK);
	for (int i = 1; i <= c.vexnum; i++)
	{
		char str[80];
		sprintf(str, "%d��%s", c.vexs[i].position, c.vexs[i].name);
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
	//			//�û����뾰�����,��ѯ������Ϣ 
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
	////				 outtextxy(250, 60, _T("éɽ�羰��"));
	////				 drawtext(_T("éɽ��ʤ���أ��羰������2001�걻��Ϊ����AAAA��������"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300, 300, &maoshan);
	//				 break;
	//			 case 50:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("2"));
	//				 outtextxy(250, 60, _T("��˿��"));
	//				 drawtext(_T("��ϸ��˿��ɫ������������ˬ���������ԣ��¹�����"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300, 300, &SilverNoodles);
	//				 break;
	//			 case 51:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("3"));
	//				 outtextxy(250, 60, _T("���޸������"));
	//				 drawtext(_T("��Ϊ����ʡ��������������أ������ÿ��Ӵ�����ι���5����ˡ������������޸�����û�б����ǵ���������Խ��Խ�ܵ����ǵ��𾴺ͻ���"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300, 300, &hualuogeng);
	//				 break;
	//			 case 52:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("4"));
	//				 outtextxy(250, 60, _T("�л���Գ���ʹ�԰"));
	//				 drawtext(_T("�滮�������������ʪ�ؼ�ˮĸɽ��ַ�����л���Գ��ʯ�ķ��ֵ�"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300, 300,&Geopark);
	//				 break;
	//			 case 53:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("5"));
	//				 outtextxy(250, 60, _T("��������"));
	//				 putimage(300, 300, &BenedictionTemple);
	//				 drawtext(_T("�����������ڴ���ɫ�ʵġ�ˮ����ɽ���ġ���ɽ�¡������ٸ��صġ���ɽ��"), &r0, DT_LEFT | DT_WORDBREAK);
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
	//				 outtextxy(250, 60, _T("��Ŀ���ȼ���"));
	//				 drawtext(_T("λ�ڳ����������ϰ˹��ﴦ��������Ŀɽ��������������Ŀ������"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &TianmuLake);
	//				 break;
	//			 case 55:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("7"));
	//				 outtextxy(250, 60, _T("��ɽ��"));
	//				 drawtext(_T("���������Ļ������Ļ�Ϊ���⣬��ӵ3.5��Ķ����"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &NanshanBambooSea);
	//				 break;
	//			 case 56:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("8"));
	//				 outtextxy(250, 60, _T("�й������ͳ�������"));
	//				 drawtext(_T("���й���Ϊ����Ҳ��Ϊ�����ĵ���ǳ���ַ"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &yancheng);
	//				 break;
	//			 case 57:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("9"));
	//				 outtextxy(250, 60, _T("��������Ϸ��"));
	//				 drawtext(_T("��δ�й��ġ�����δ֪�ġ���Խ��ʵ�ġ�������硱������ʵ��������԰"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &joyland);
	//				 break;
	//			 case 97:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("10"));
	//				 outtextxy(250, 60, _T("���ݲ����"));
	//				 drawtext(_T("�Ǽ��ղء��о�������չ����һ��ĵط��ۺ��Բ����"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &museum);
	//				 break;
	//			 case 98:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("11"));
	//				 outtextxy(250, 60, _T("���������"));
	//				 drawtext(_T("һ����չʾ�����ա����֡����м������Ա�����һ��Ŀ���Ϊ�����һվʽ���ζȼ���"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &dinosaur);
	//				 break;
	//			 case 99:
	//				 putimage(0, 0, &white);
	//				 outtextxy(50, 20, st14);
	//				 outtextxy(50, 60, st15);
	//				 outtextxy(50, 100, st16);
	//
	//				 outtextxy(250, 20, _T("12"));
	//				 outtextxy(250, 60, _T("��������"));
	//				 drawtext(_T("�ǳ����ִ��ģ��󣬱�����������ǧ���ɲ"), &r0, DT_LEFT | DT_WORDBREAK);
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
	//				 outtextxy(250, 60, _T("���ľ�����ָ�Ӳ������"));
	//				 drawtext(_T("��һ�����й�����ʷ�;���ʷ�϶�����Ҫ��λ�ĵط�"), &r0, DT_LEFT | DT_WORDBREAK);
	//				 putimage(300,300, &NewFourthArmy);
	//				 break;
	//			
	//			 default://�����쳣
	//				
	//				 break;
	//			 }	

}
//������㼰�����
void Outputtext() {
	TCHAR s14[] = _T("A.������Ϣ��ѯ");
	TCHAR s15[] = _T("B.��ѯ���������·��");
	//TCHAR s16[] = _T("���㼰�����");
	TCHAR s17[] = _T("��ѡ����");
	TCHAR s18[] = _T("C.���±༭ͼ����Ϣ");
	TCHAR s19[] = _T("D.��ѯ�����м䶥������·��");
	TCHAR s20[] = _T("E.��ѯ���������·��");


	//�������ֱ���ģʽ-->͸��
	//TRANSPARENT������͸��������ֱ��д��0����Ҳ��ʾ͸��
	setbkmode(TRANSPARENT);
	//�����ı���ɫ
	settextcolor(RED);

	//�����ı���ʽ
	settextstyle(10, 0, "����");//����Ŀ�+����ĸ�+����ķ��

	//outtextxy(20, 5, s16);
	outtextxy(250, 5, s17);




	//�����ı���ɫ
	settextcolor(LIGHTBLUE);

	//�����ı���ʽ
	settextstyle(20, 0, _T("����"));//����Ŀ�+����ĸ�+����ķ��


	outtextxy(250, 20, s14);
	outtextxy(250, 45, s15);
	outtextxy(250, 70, s18);
	outtextxy(250, 95, s19);
	outtextxy(250, 120, s20);
}

//���������Ǽ�����
void drawCircle(mgraph c)
{
	char str[80];

	for (int i = 1; i <= c.vexnum; i++)
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(c.vexs[i].x, c.vexs[i].y, 10);
		sprintf(str, "%d��%s", c.vexs[i].position, c.vexs[i].name);
		setbkmode(TRANSPARENT);
		settextcolor(BLUE);
		settextstyle(15, 0, _T("����"));//����ĸ�+����Ŀ�+����ķ��
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
		MOUSEMSG m = GetMouseMsg();//��ȡ�����Ϣ
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

		//ˢ�µ�ͼҳ��
		if (m.uMsg == WM_RBUTTONDOWN) {
			//			putimage(0, 0, &map);
			//			Outputtext();
			putimage(0, 0, &white);
			drawCircle(changzhou);
			Outputtext();

		}
	}

}
// ������
int main()
{

	initgraph(width, height);
	//ȫ����Դ����
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
		//ѡ�����
		if (_kbhit()) {

			input = getch();
			if (input == 'a') {
				Query(changzhou); //��ѯ������Ϣ

			}
			else if (input == 'b') {
				DrawPath(); //���·��

			}
			else if (input == 'c') {
				Changegraph(); //�༭ͼ��Ϣ
			}
			else if (input == 'd')
			{
				finalShortest(changzhou);     //����������ʼ����յ㣬������������
			}
			else if (input == 'e')
			{
				allroad(changzhou);     //����������ʼ����յ㣬������������
			}
		}

	}
	system("pause");
	closegraph;//�رջ���
	return 0;

}

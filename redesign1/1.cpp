//#undef UNICODE
//#undef _UNICODE
//#define _CRT_SECURE_NO_DEPRECATE
//#pragma warning(disable:4996)//��ֹvs2019����ʹ����˳������
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
//#define height 799//��Ϸ����ߴ�
//#define width1 200  //����ͼƬ�ߴ�
//#define height1 200
//#define Infinity 20000//Լ����2000����������󣬼�����ͨ
//#define MaxVertexNum 20//Լ���������20�����㣨���㣩
//#define MAX 40 
//#define key 13//Ĭ�϶�����Ϊ13
//#define lock 20//Ĭ�ϱ���Ϊ20
//
//IMAGE map, BenedictionTemple, dinosaur, Geopark, hualuogeng,white,
//		joyland, maoshan, museum, NewFourthArmy, SilverNoodles, TianmuLake, tianningTemple, yancheng, NanshanBambooSea;
//
//
//
//typedef struct vexsinfo//���㣨���㣩�ṹ��
//{
//	char name[32];//���� 
//	int position;//����
//	char introduction[256];//���---���ܲ˵�5 
//	char super_introduction[512];//��ϸ����---���ܲ˵�6 
//	int x;  //��������
//	int y;
//}vexsinfo;
//
//typedef struct arcell//�ߣ�·�����ṹ��
//{
//	int adj;//Ȩֵ  
//}arcell, adjmatrix[MaxVertexNum][MaxVertexNum];//�ڽӾ���
//
//typedef struct mgraph//ͼ�ṹ��
//{
//	vexsinfo vexs[MaxVertexNum];//�������� 
//	adjmatrix arcs;//�ڽӾ��� 
//	int vexnum, arcnum;//���㣨vertex�����ͱߣ�arc���� 
//}mgraph;
//
////ȫ�ֱ���
//
//int shortest[MaxVertexNum][MaxVertexNum];//���·�� 
//int pathh[MaxVertexNum][MaxVertexNum];
//mgraph changzhou; //����ͼ
////c.vexnum = key;  //������
////c.arcnum = lock;  //����
//
////��ʼ��ͼ��ϵͳ
//mgraph initgraph()
//{
//	int i = 0, j = 0;
//	mgraph c;
//	c.vexnum = key;  //������
//	c.arcnum = lock;  //����
//
//	//���þ������
//	for (i = 1; i <= key; i++)
//		c.vexs[i].position = i;
//
//	//string copy������Ϣ ����������ƣ���ϸ���ܣ����
//	strcpy(c.vexs[1].name, "éɽ�羰��");
//	strcpy(c.vexs[1].super_introduction, "\néɽ�羰����éɽ��ʤ���أ��羰������2001�걻��Ϊ����AAAA��������\n");
//	strcpy(c.vexs[1].introduction, "����ط���ɽ");
//
//	strcpy(c.vexs[2].name, "��˿��");
//	strcpy(c.vexs[2].super_introduction, "\n��˿�棺��ϸ��˿��ɫ������������ˬ���������ԣ��¹�����\n");
//	strcpy(c.vexs[2].introduction, "�ط���ͳ��ʳС��");
//
//	strcpy(c.vexs[3].name, "���޸������");
//	strcpy(c.vexs[3].super_introduction, "\n��Է���ײͣ��ǽ������������֣����������࣬���ӣ���ͷ��Ӧ�о��У��������θ��\n");
//	strcpy(c.vexs[3].introduction, "��ʳ����");
//
//	strcpy(c.vexs[4].name, "�л���Գ���ʹ�԰");
//	strcpy(c.vexs[4].super_introduction, "\n�л���Գ���ʹ�԰���滮�������������ʪ�ؼ�ˮĸɽ��ַ�����л���Գ��ʯ�ķ��ֵ�\n");
//	strcpy(c.vexs[4].introduction, "ʡ��ʪ�ع�԰");
//
//	strcpy(c.vexs[5].name, "��������");
//	strcpy(c.vexs[5].super_introduction, "\n�������£������������ڴ���ɫ�ʵġ�ˮ����ɽ���ġ���ɽ�¡������ٸ��صġ���ɽ��\n");
//	strcpy(c.vexs[5].introduction, "����ʥ��");
//
//	strcpy(c.vexs[6].name, "��Ŀ���ȼ���");
//	strcpy(c.vexs[6].super_introduction, "\n��Ŀ����λ�ڳ����������ϰ˹��ﴦ��������Ŀɽ��������������Ŀ������\n");
//	strcpy(c.vexs[6].introduction, "���������顱������ɫ�ɾ���");
//
//	strcpy(c.vexs[7].name, "��ɽ��");
//	strcpy(c.vexs[7].super_introduction, "\n��ɽ�񺣣����������Ļ������Ļ�Ϊ���⣬��ӵ3.5��Ķ����\n");
//	strcpy(c.vexs[7].introduction, "������ɽ���λ���");
//
//	strcpy(c.vexs[8].name, "�й������ͳ�������");
//	strcpy(c.vexs[8].super_introduction, "\n�й������ͳ������������й���Ϊ����Ҳ��Ϊ�����ĵ���ǳ���ַ\n");
//	strcpy(c.vexs[8].introduction, "����ǳ���ַ");
//
//	strcpy(c.vexs[9].name, "��������Ϸ��");
//	strcpy(c.vexs[9].super_introduction, "\n��������Ϸ�ȣ���δ�й��ġ�����δ֪�ġ���Խ��ʵ�ġ�������硱������ʵ��������԰\n");
//	strcpy(c.vexs[9].introduction, "������������Ϸ�Ļ�");
//
//	strcpy(c.vexs[10].name, "���ݲ����");
//	strcpy(c.vexs[10].super_introduction, "\n���ݲ���ݣ��Ǽ��ղء��о�������չ����һ��ĵط��ۺ��Բ����\n");
//	strcpy(c.vexs[10].introduction, "����һ�������");
//
//	strcpy(c.vexs[11].name, "���������");
//	strcpy(c.vexs[11].super_introduction, "\n��������ǣ�һ����չʾ�����ա����֡����м������Ա�����һ��Ŀ���Ϊ�����һվʽ���ζȼ���.\n");
//	strcpy(c.vexs[11].introduction, "���ζȼ���");
//
//	strcpy(c.vexs[12].name, "��������");
//	strcpy(c.vexs[12].super_introduction, "\n�������£��ǳ����ִ��ģ��󣬱�����������ǧ���ɲ\n");
//	strcpy(c.vexs[12].introduction, "�й������Ĵ����");
//
//	strcpy(c.vexs[13].name, "���ľ�����ָ�Ӳ������");
//	strcpy(c.vexs[13].super_introduction, "\n���ľ�����ָ�Ӳ�����ݣ���һ�����й�����ʷ�;���ʷ�϶�����Ҫ��λ�ĵط�\n");
//	strcpy(c.vexs[13].introduction, "ָ�Ӳ���ַ");
//
//	//ȷ�����������
//	c.vexs[1].x = 145;
//	c.vexs[1].y = 238;//éɽ
//
//	c.vexs[2].x = 200;
//	c.vexs[2].y = 330;//��˿��
//
//	c.vexs[3].x = 330;
//	c.vexs[3].y = 285;//���޸������
//
//	c.vexs[4].x = 320;
//	c.vexs[4].y = 445;//�л���Գ���ʹ�԰
//
//	c.vexs[5].x = 170;
//	c.vexs[5].y = 640;//��������
//
//	c.vexs[6].x = 250;
//	c.vexs[6].y = 640;//��Ŀ���ȼ���
//
//	c.vexs[7].x = 260;
//	c.vexs[7].y = 750;//��ɽ��
//
//	c.vexs[8].x = 470;
//	c.vexs[8].y = 320;//�й������ͳ�������
//
//	c.vexs[9].x = 650;
//	c.vexs[9].y = 470;//��������Ϸ��
//
//	c.vexs[10].x = 550;
//	c.vexs[10].y = 230;//���ݲ����
//
//	c.vexs[11].x = 630;
//	c.vexs[11].y = 210;//���������
//
//	c.vexs[12].x = 620;
//	c.vexs[12].y = 250;//��������
//
//	c.vexs[13].x = 160;
//	c.vexs[13].y = 490; //���ľ�
//
//
//	//��ʼ���ڽӾ���Ȩֵ��Ϊ����󣬼����ж��㻥������
//	for (i = 1; i <= key; i++)
//		for (j = 1; j <= key; j++)
//			c.arcs[i][j].adj = Infinity; //�ڽӾ���Ȩֵ���޴�2000��
//
//	//�涨�������ͨ���������߶�Ӧ��Ȩֵ������1����2����Ȩ��G[��1][��2] = weight 
//	//��ͨ�������㣬ȷ������������
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
//	//����ͼ�ԳƸ�ֵ
//	for (i = 1; i <= key; i++)
//		for (j = 1; j <= key; j++)
//			c.arcs[j][i].adj = c.arcs[i][j].adj;
//
//	return c;
//}
//
//
//
////33���������㷨
//void floyd(mgraph c)
//{
//	int i, j, k;
//	for (i = 1; i <= c.vexnum; i++)
//	{
//		for (j = 1; j <= c.vexnum; j++)
//		{
//			shortest[i][j] = c.arcs[i][j].adj;
//			pathh[i][j] = j;//����i������j�����·���Ǿ���j 
//		}
//	}
//
//	printf("\n\n\n");
//
//	//���Ĳ������㷨�ο���ַ��https://www.cnblogs.com/skywang12345/p/3711523.html 
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
//					//����i������j�����·���Ǿ���k 
//				}
//			}
//		}
//	}
//}
//
////33��ӡ���·�� 
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
//		//�ݹ�
//		line( c.vexs[k].x, c.vexs[k].y,c.vexs[pathh[k][j]].x, c.vexs[pathh[k][j]].y);
//		k = pathh[k][j];
//	}
////	line(c.vexs[pathh[i][j]].x, c.vexs[pathh[i][j]].y, c.vexs[b].x, c.vexs[b].y);
//	//printf("%s-->%s�����·���ǣ�%d �ס�\n\n", c.vexs[a].name, c.vexs[b].name, shortest[a][b]);
//	
//	outtextxy(50, 100, shortest[a][b]);
//}
// //�����·��
//void DrawPath() {
//
//	outtextxy(300, 100,_T("������Ҫ��ѯ����������Ĵ���"));
//	int i, j; //Ҫ��ѯ����������Ĵ���
//	 
//	char s1[10];
//	InputBox(s1, 10, _T("���������"));
//	// ���û�����ת��Ϊ����
//	sscanf(s1, "%d", &i);
//	char s2[10];
//	InputBox(s2, 10, _T("�������յ�"));
//	// ���û�����ת��Ϊ����
//	sscanf(s2, "%d", &j);
//	floyd(changzhou);
//	display(changzhou, i, j);
//
//
//}
////7�ж϶����Ƿ���ͼ��
//int locatevex(mgraph c, int v)
//{
//	int i;
//	for (i = 1; i <= c.vexnum; i++)
//		if (v == c.vexs[i].position)
//			return i;//���ҵ�
//	return -1;//δ�ҵ�
//}
//
////���½�ͼ
//void creatgraph(mgraph* c)
//{
//	//�����ı���ɫ
//	settextcolor(RED);
//
//	//�����ı���ʽ
//	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//
//	// ����Ļ��������ַ���
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("���½�ͼ"), &r, DT_CENTER | DT_WORDBREAK);
//
//	//�����ı���ɫ
//	settextcolor(BLUE);
//
//	//�����ı���ʽ
//	settextstyle(30, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//	outtextxy(200, 100,_T("������:"));
//	outtextxy(200, 145, _T("����:"));
//	int i, j, m, n, v0, v1, distance;
//
//	//printf("�����ͼ�Ķ������ͱ�����\n");
//
//
//		// �����ַ������������������û�����
//	//������
//	char s1[10];
//	InputBox(s1, 10, _T("�����붥����"));
//	outtextxy(300, 100, s1);
//
//	//����
//	char s2[10];
//	InputBox(s2, 10, _T("���������"));
//	outtextxy(300, 145, s2);
//
//	// ���û�����ת��Ϊ����
//	sscanf(s1, "%d", &c->vexnum);
//	sscanf(s2, "%d", &c->arcnum);
//
//	//�����ı���ʽ
//	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//	settextcolor(CYAN);
//	char s3[10];
//	char s4[10];
//	char s5[10];
//	char s6[10];
//	for (i = 1; i <= c->vexnum; i++)
//	{
//	
//	 
//		outtextxy(0, 145 + 50 * i, _T("�������:"));
//		outtextxy(150, 145 + 50 * i, _T("��������:"));
//		outtextxy(300, 145 + 50 * i, _T("������:"));
//		outtextxy(450, 145 + 50 * i, _T("������ϸ����:"));
//
//	}
//	settextcolor(BLUE);
//	for (i = 1; i <= c->vexnum; i++)
//	{
//		
//		InputBox(s3, 10, _T("�����뾰��Ĵ���:"));
//		sscanf(s3, "%d", &c->vexs[i].position);
//		outtextxy(100, 145+50*i, s3);
//
//		InputBox(s4, 10, _T("�����뾰�������:"));
//		sscanf(s4, "%d", &c->vexs[i].name);
//		outtextxy(250, 145 + 50 * i, s4);
//
//		InputBox(s5, 10, _T("�����뾰��ļ��:"));
//		sscanf(s5, "%d", &c->vexs[i].introduction);
//		outtextxy(400, 145 + 50 * i, s5);
//
//		InputBox(s6, 10, _T("�����뾰�����ϸ����:"));
//		sscanf(s6, "%d", &c->vexs[i].introduction);
//		outtextxy(600, 145 + 50 * i, s6);
//
//	}
//	//��ʼ��ȨֵΪ����󣨲���ͨ��
//	for (i = 1; i <= c->vexnum; i++)
//		for (j = 1; j <= c->vexnum; j++)
//			c->arcs[i][j].adj = Infinity;
//
//	//printf("�����ߵ���Ϣ��\n");
//
//	//�����ı���ɫ
//	settextcolor(RED);
//	//�����ı���ʽ
//	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//	outtextxy(300, 145 + 50 * (c->vexnum+1), _T("�����ߵ���Ϣ"));
//
//	for (i = 1; i <= c->arcnum; i++)
//	{
//
//		outtextxy(0, 145 + 50 * (c->vexnum + 1+i), _T("���"));
//		outtextxy(150, 145 + 50 * (c->vexnum + 1+i), _T("�յ�"));
//		outtextxy(300, 145 + 50 * (c->vexnum + 1+i), _T("����"));
//		 
//	}
//	char s7[10];
//	char s8[10];
//	char s9[10];
//	for (i = 1; i <= c->arcnum; i++)
//	{
//		/*printf("\n��%d���ߵ���㡢�յ㡢����Ϊ��", i);
//		scanf("%d %d %d", &v0, &v1, &distance);*/
//		//�ж�����������յ��Ƿ������ͼ�У������ڣ��򷵻ش���
//		InputBox(s7, 10, _T("���"));
//		outtextxy(100, 145 + 50 * (c->vexnum + 1 + i), s7);
//		InputBox(s8, 10, _T("�յ�") );
//		outtextxy(250, 145 + 50 * (c->vexnum + 1 + i),s8);
//		InputBox(s9, 10, _T("����"));
//		outtextxy(400, 145 + 50 * (c->vexnum + 1 + i),s9);
//		sscanf(s7, "%d", &v0);
//		sscanf(s8, "%d", &v1);
//		sscanf(s9, "%d", &distance);
//	
//		m = locatevex(changzhou, v0);
//		n = locatevex(changzhou, v1);
//		if (m > 0 && n > 0)
//		{
//			//����ͼ�ԳƸ�ֵ
//			c->arcs[m][n].adj = distance;
//			c->arcs[n][m].adj = c->arcs[m][n].adj;
//		}
//	}
//	
//}
////7ɾ������
//int delvex(mgraph* c)
//{
//	//�����ı���ɫ
//	settextcolor(RED);
//
//	//�����ı���ʽ
//	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//
//	// ����Ļ��������ַ���
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("ɾ������"), &r, DT_CENTER | DT_WORDBREAK);
//
//	int i = 0, j;
//	int m, v;
//	//�����ı���ʽ
//	settextstyle(60, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//	if (c->vexnum <= 0)
//	{
//		outtextxy(300, 100, _T("ͼ�����޶���,������ɾ��"));
//		return 1;
//	}
//
//	//�����ı���ʽ
//	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//	//�����ı���ɫ
//	settextcolor(RED);
//	outtextxy(20, 180, _T("�������ɾ���ľ�����ţ�"));
//	char s1[10];
//	InputBox(s1, 10, _T("�������ɾ���ľ������"));
//	outtextxy(500, 180, s1);
//	// ���û�����ת��Ϊ����
//	sscanf(s1, "%d", &v);
//	
//	while (v <= 0 || v > key)
//	{
//		outtextxy(300, 100, _T("���Ŵ���"));
//		return 1;
//	}
//	m = locatevex(changzhou, v);
//	if (m < 0)
//	{
//		//printf("����%d��ɾ��\n", v);
//		outtextxy(300, 350, _T("�ö����ѱ�ɾ��"));
//		return 1;
//	}
//
//	//ɾ���ڽӾ���ĵ�m��
//	for (i = m-1; i < c->vexnum - 1; i++)
//		for (j = 0; j < c->vexnum; j++)
//			c->arcs[i][j] = c->arcs[i + 1][j];
//
//	//ɾ���ڽӾ���ĵ�m��
//	for (i = m-1; i < c->vexnum - 1; i++)
//		for (j = 0; j < c->vexnum; j++)
//			c->arcs[j][i] = c->arcs[j][i + 1];
//
//	c->vexs[v].position = -1;//��ʾ�ö�����ɾ��
//	c->vexnum--;
//	outtextxy(300, 350, _T("����ɾ���ɹ�"));
//	return 1;
//}
////7ɾ����
//int delarc(mgraph* c)
//{
//	//�����ı���ɫ
//	settextcolor(RED);
//
//	//�����ı���ʽ
//	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//
//	// ����Ļ��������ַ���
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("ɾ����"), &r, DT_CENTER | DT_WORDBREAK);
//
//	int m, n, v0, v1;
//	
//	//�����ı���ʽ
//	settextstyle(60, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//	if (c->vexnum <= 0)
//	{
//		outtextxy(300, 100, _T("ͼ���ѱ�,������ɾ��"));
//		return 1;
//	}
//	//�����ı���ʽ
//	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//	//�����ı���ɫ
//	settextcolor(RED);
//	outtextxy(20, 180, _T("�������ɾ���������ţ�"));
//	outtextxy(20, 230, _T("�������ɾ�����յ���ţ�"));
//	char s1[10];
//	InputBox(s1, 10, _T("�������ɾ����������"));
//	outtextxy(500, 180, s1);
//	char s2[10];
//	InputBox(s2, 10, _T("�������ɾ�����յ����"));
//	outtextxy(500, 230, s2);
//	// ���û�����ת��Ϊ����
//	sscanf(s1, "%d", &v0);
//	sscanf(s1, "%d", &v1);
//
//	while (v0 <= 0 || v0 > key || v1 <= 0 || v1 > key)
//	{
//		outtextxy(300, 100, _T(" ���Ŵ���"));
//		return 1;
//	}
//	m = locatevex(changzhou, v0);
//	if (m < 0)
//	{
//		 
//		outtextxy(300, 100, _T("�����ɾ��"));
//		return 1;
//	}
//	n = locatevex(changzhou, v1);
//	if (n < 0)
//	{
//		 
//		outtextxy(300, 100, _T(" �յ���ɾ��"));
//		return 1;
//	}
//
//	//����ͼ�ԳƸ�ֵ
//	c->arcs[m][n].adj = Infinity;
//	c->arcs[n][m].adj = Infinity;
//	c->arcnum--;
//
//	outtextxy(300, 100, _T("��ɾ���ɹ�!"));
//	return 1;
//}
////7����ڽӾ���
//void printmatrix(mgraph c)
//{
//	//�����ı���ɫ
//	settextcolor(RED);
//
//	//�����ı���ʽ
//	settextstyle(40, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//
//	// ����Ļ��������ַ���
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("����ڽӾ���\nԼ����2000����������󣬼�����ͨ"), &r, DT_CENTER | DT_WORDBREAK);
//	int i, j, k = 0,t=0;
//	settextstyle(11, 0, "����");
//	char s[10];
//	//sprintf(s, "%d", c.arcs[1][2].adj);//������aת�����ַ���
//	//outtextxy(20  , 120  , s);
//
//	settextcolor(BLUE);
//	settextstyle(15, 0, "����");
//
//	for (i = 1; i <= c.vexnum; i++)
//	{
//		sprintf(s, "%d", i);//������aת�����ַ���
//		outtextxy(i * 50 - 30, 80, i);
//	}
//
//	settextcolor(RED);
//	settextstyle(11, 0, "����");
//	for (i = 1; i <=c.vexnum; i++)
//	{
//		for (j = 1; j <= c.vexnum; j++)
//		{
//			sprintf(s, "%d", c.arcs[i][j].adj);//������aת�����ַ���
//			outtextxy(20+k*50,120+t*40, s);
//			//printf("%-6d", c.arcs[i][j].adj);
//			k++;
//			//�жϻ���ʱ��
//			if (k % c.vexnum == 0)
//			{
//				printf("\n");
//				k = 0;
//				t++;//����
//			}
//		}
//	}
//	
//	
//}
////77�޸�ͼ��Ϣ
//void Changegraph()
//{
//	//�����ı���ɫ
//	settextcolor(RED);
//
//	//�����ı���ʽ
//	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//
//	// ����Ļ��������ַ���
//	RECT r = { 0, 0, width - 1, height - 1 };
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//	putimage(0, 0, &white);
//	drawtext(_T("���±༭ͼ����Ϣ,��ѡ����Ҫ���еĲ���"), &r, DT_CENTER | DT_WORDBREAK);
//
//	//�����ı���ɫ
//	settextcolor(BLUE);
//	//�����ı���ʽ
//	settextstyle(30, 0, "����");//����Ŀ�+����ĸ�+����ķ�� 
//	RECT r1 = { 0,50,width - 1 ,height - 1 };
//	drawtext(_T("1.���½�ͼ\n2.ɾ������\n3.ɾ����\n4.���Ӷ���\n5.���ӱ�\n6.������Ϣ\n 7.����ڽӾ���"), &r1, DT_CENTER | DT_WORDBREAK);
//	switch (getch())
//	{
//
//	case 49://���½�ͼ1
//		creatgraph(&changzhou);
//		break;
//	case 50://ɾ������2
//		delvex(&changzhou);
//		break;
//	case 51://ɾ����3
//		delarc(&changzhou);
//		break;
//	case 52://���Ӷ���4
//		//envex(mgraph * c);
//		break;
//	case 53://���ӱ�5
//		//enarc(mgraph * c);
//		break;
//	case 54://������Ϣ6
//		//newgraph(mgraph * c);
//		break;
//	case 55://����ڽӾ���7
//		printmatrix(changzhou);
//		break;
//	default://�����쳣
//
//		break;
//	}
//}
// 
//
////*��ѯ����ҳ��
//void Query() {
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
//	TCHAR st14[] = _T("������ţ�");
//	TCHAR st15[] = _T("�������ƣ�");
//	TCHAR st16[] = _T("��ϸ���ܣ�");
//	//�����ı���ɫ
//	settextcolor(RED);
//
//	//�����ı���ʽ
//	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//
//	// ����Ļ��������ַ���
//	RECT r = { 0, 0, width-1, height-1};
//	RECT r0 = { 250, 100, width - 1, height - 1 };
//		 putimage(0, 0, &white);
//		 drawtext(_T("��ѯ������Ϣ����������Ҫ��ѯ�ľ������"), &r, DT_CENTER | DT_WORDBREAK) ;
//
//		 //�����ı���ɫ
//		 settextcolor(BLUE);
//		 //�����ı���ʽ
//		 settextstyle(30, 0, "����");//����Ŀ�+����ĸ�+����ķ�� 
//		 RECT r1 = {0,50,width - 1 ,height - 1 };
//		 drawtext(_T("1.éɽ�羰��\n2.��˿��\n3.���޸������\n4.�л���Գ���ʹ�԰\n5.��������\n6.��Ŀ���ȼ���\n 7.��ɽ��\n8.�й������ͳ�������\n9.��������Ϸ��\n10.���ݲ����\n11.���������\n12.��������\n13.���ľ�����ָ�Ӳ������\n"), &r1, DT_CENTER | DT_WORDBREAK);
//		 
//		 
//	
//			
//			//�û����뾰�����,��ѯ������Ϣ 
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
//				 outtextxy(250, 60, _T("éɽ�羰��"));
//				 drawtext(_T("éɽ��ʤ���أ��羰������2001�걻��Ϊ����AAAA��������"), &r0, DT_LEFT | DT_WORDBREAK);
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
//	
//}
//
//
//
//
////������㼰�����
//void Outputtext() {
//	TCHAR s1[] = _T("1.éɽ�羰��");
//	TCHAR s2[] = _T("2.��˿��");
//	TCHAR s3[] = _T("3.���޸������");
//	TCHAR s4[] = _T("4.�л���Գ���ʹ�԰");
//	TCHAR s5[] = _T("5.��������");
//	TCHAR s6[] = _T("6.��Ŀ���ȼ���");
//	TCHAR s7[] = _T("7.��ɽ��");
//	TCHAR s8[] = _T("8.�й������ͳ�������");
//	TCHAR s9[] = _T("9.��������Ϸ��");
//	TCHAR s10[] = _T("10.���ݲ����");
//	TCHAR s11[] = _T("11.���������");
//	TCHAR s12[] = _T("12.��������");
//	TCHAR s13[] = _T("13.���ľ�����ָ�Ӳ������");
//	TCHAR s14[] = _T("A.������Ϣ��ѯ");
//	TCHAR s15[] = _T("B.��ѯ���������·��");
//	TCHAR s16[] = _T("���㼰�����");
//	TCHAR s17[] = _T("��ѡ����");
//	TCHAR s18[] = _T("C.���±༭ͼ����Ϣ");
//
//
//	//�������ֱ���ģʽ-->͸��
//		//TRANSPARENT������͸��������ֱ��д��0����Ҳ��ʾ͸��
//		setbkmode(TRANSPARENT);
//	//�����ı���ɫ
//	settextcolor(RED);
//
//	//�����ı���ʽ
//	settextstyle(10, 0, "����");//����Ŀ�+����ĸ�+����ķ��
//
//	outtextxy(20, 5, s16);
//	outtextxy(250, 5, s17);
//
//
//	
//
//	//�����ı���ɫ
//	settextcolor(LIGHTBLUE);
//
//	//�����ı���ʽ
//	settextstyle(20, 0, "����");//����Ŀ�+����ĸ�+����ķ��
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
//		MOUSEMSG m = GetMouseMsg();//��ȡ�����Ϣ
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
//		//ˢ�µ�ͼҳ��
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
//// ������
//int main()
//{
//	initgraph(width, height);
//	//ȫ����Դ����
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
//		//ѡ�����
//		if (_kbhit()) {
//			
//			input = getch();
//				if (input=='a') {
//								Query(); //��ѯ������Ϣ
//
//							}
//				else if (input == 'b') {
//							DrawPath(); //���·��
//
//						}	
//				else if (input == 'c'){
//					Changegraph(); //�༭ͼ��Ϣ
//				}
//		
//	}
//			
//	}
//	system("pause");
//	closegraph;//�رջ���
//	return 0;
//
//}
//
//
//

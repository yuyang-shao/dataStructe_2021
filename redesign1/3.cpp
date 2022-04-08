//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
///*��ŵ�˼·�ǣ�
//1.�ҵ�һ�����ʵĵ㣨�Ǳ߽磬�Ǳ�ǣ�����ջ������ջ����ֱ����ջ���Ҳ�����һ����ų�ջ��������һ��
//2.��ջʱ��Ҫ���б�ǣ����ҵ��յ�ʱͬ����ջ�������ô�ӡ������������յ��ջ���ָ���Ǽ��ɼ��ɣ���������
//
//��ʵ��Ҫ�������³���
//0 0 0
//0 0 0 
//1 0 0
//·��(0,0)->(0,1)->(1,1)->(1,0)ʱ����ʱ���ջ��(1,0)����4������ı��������������У������Ѿ�����ǣ�����Ҳ����ǣ����²��У�
//
//��ʱ��ջ������û�лָ��ȱ�ǣ���һֱ��ջ��(0,0)��������Ԫ�ر����Ϸ��ĵ�����Ϊ����ǵ��£�0,0��->(1,0)->(1,1)·�߱��¶�,
//
//������Ҫ�������·�ʽ��������һ����ǰ�Ķ��㣬��������ĸ�����û�б����Ļ�*/
//
//#define MAZE_MAX_X 4
//#define MAZE_MAX_Y 4
//
//#define MAX_DIR 4
//#define DIM 2
//
//#define IS_DP_BITN_TRUE(value,bitn) ((value) >> (bitn)) & 0x1 
//
//#define SET_DP_BITN(value,bitn,flag) \
//	if((flag) == 1)\
//	{\
//	(value) = ((value) | (0x1 << bitn));\
//	}\
//	else\
//	(value) = ((value) & (~(0x1<<bitn)))
//
//#define CLEAR_DP_ALL(value) (value) = 0x0
//
//
//
///*�����ģ��,����ԭ�������Ϸ�������Ļ���ʵ���м�1*/
////���ң��ϣ���
//static const int s_dirs[MAX_DIR][DIM] = {{0,-1},{0,1},{-1,0},{1,0}};
//
//
///*ջ��ʼ*/
//typedef struct Stack_
//{
//	int cap;
//	int top;
//	int** data; 
//}STACK_S;
//
//void Stack_Init(STACK_S* stack,int cap,int size)
//{
//	int i = 0;
//	stack->cap = cap;
//	stack->top = -1;
//	stack->data = (int**)malloc(sizeof(int*)*cap);
//	for(i = 0; i <= cap -1 ;i++)
//	{
//		stack->data[i] = (int*)malloc(sizeof(int)*size);
//		memset(stack->data[i],0,sizeof(int)*size);
//	}
//}
//
//int Stack_Is_Full(STACK_S* stack)
//{
//	return (stack->top == stack->cap) ? 1 : 0;
//}
//
//int Stack_Is_Empty(STACK_S* stack)
//{
//	return (stack->top == -1) ? 1 : 0;
//}
//
//void Stack_Pushback(STACK_S* stack,int x,int y)
//{
//	if(Stack_Is_Full(stack) != 1)
//	{
//		stack->top++;
//		stack->data[stack->top][0] = x;
//		stack->data[stack->top][1] = y;
//	}
//}
//int* Stack_GetTop(STACK_S* stack)
//{
//	if(Stack_Is_Empty(stack) != 1)
//	{
//		return stack->data[stack->top];
//	}
//	else
//		return NULL;
//}
//
//void Stack_Pop(STACK_S* stack)
//{
//	if(Stack_Is_Empty(stack) != 1)
//	{
//		stack->top--;
//	}
//}
///******************ջ����***************/
//
//
//int Point_Is_Boundry(int max_x,int max_y,int x,int y)
//{
//	if(x < 0 || x >= max_x || y < 0 || y >= max_y)
//		return 1;
//	return 0;
//}
//
//
///*��ӡջ�е�·��**/
//void printf_stack_path(STACK_S* stack)
//{
//	STACK_S stack_temp = {0};
//	int* data = NULL;
//	Stack_Init(&stack_temp,stack->cap,2);
//	//��ջ���ŵ���һ��ջ
//	while(Stack_Is_Empty(stack) != 1)
//	{
//		data = Stack_GetTop(stack);
//		Stack_Pushback(&stack_temp,data[0],data[1]);
//		Stack_Pop(stack);
//	}
//	while(Stack_Is_Empty(&stack_temp) != 1)
//	{
//		data = Stack_GetTop(&stack_temp);
//		printf("(%d,%d)->",data[0],data[1]);
//		Stack_Pushback(stack,data[0],data[1]);
//		Stack_Pop(&stack_temp);
//	}
//	//�˸�����һ��"->"ȥ��
//	printf("\b\b\t\n");	
//
//}
//
//void Maze_Dfs_All_Path(int** maze,int max_x,int max_y,int* start,int* end,STACK_S* stack,int** dp)
//{
//	int i = 0;
//	int next_x = 0,next_y = 0;
//	int *cur = 0;
//	int pre_x = -1,pre_y = -1;
//	//�����ջ
//	Stack_Pushback(stack,start[0],start[1]);
//	SET_DP_BITN(*(((int*)dp)+max_y*start[0]+start[0]),4,1);
//
//	while(Stack_Is_Empty(stack) != 1)
//	{
//		cur = Stack_GetTop(stack);
//		//printf("cur:(%d,%d)\n",cur[0],cur[1]);
//		for(i =0; i <= MAX_DIR -1;i++ )
//		{
//			next_x = cur[0]+s_dirs[i][0];
//			next_y = cur[1]+s_dirs[i][1];
//			//printf("next:(%d,%d)\n",next_x,next_y);
//			if(Point_Is_Boundry(max_x,max_y,next_x,next_y) == 1)
//			{
//				//printf("Boundry:(%d,%d)\n",next_x,next_y);
//				continue;
//			}
//			if( *(((int*)maze)+max_y*next_x+next_y) == 1)
//			{
//				//printf("maze is 1 (%d,%d)\n",next_x,next_y);
//				continue;
//			}
//			//�����һ���ڵ��Ѿ����,�򲻺Ϸ�����Ѱ����һ������
//			if(IS_DP_BITN_TRUE(*(((int*)dp)+max_y*next_x+next_y),4))
//			{
//				//printf("dp is 1 (%d,%d)\n",next_x,next_y);
//				continue;
//			}
//			//������ڵ㷽���Ѿ��������򲻼���
//			if(IS_DP_BITN_TRUE(*(((int*)dp)+max_y*cur[0]+cur[1]),i))
//			{
//				//printf("(%d,%d) �� %d �����Ѿ�����\n",cur[0],cur[1],i);
//				continue;
//			}
//			//printf("now (%d,%d) push back\n",next_x,next_y);
//			Stack_Pushback(stack,next_x,next_y);
//			//������һ�ڵ�Ϊ�Ѿ�����,�Լ����ڵ�ķ���
//			SET_DP_BITN(*(((int*)dp)+max_y*next_x+next_y),4,1);
//			SET_DP_BITN(*(((int*)dp)+max_y*cur[0]+cur[1]),i,1);
//			if(next_x == end[0] && next_y == end[1])
//			{
//				printf_stack_path(stack);
//				//�յ��ջ��������лָ���ǵĻ�����һ�ξͲ������
//				Stack_Pop(stack);
//				CLEAR_DP_ALL(*(((int*)dp)+max_y*end[0]+end[1]));
//				continue;
//			}
//			else
//				break;	
//		}
//		if(i >= MAX_DIR)
//		{
//			CLEAR_DP_ALL(*(((int*)dp)+max_y*cur[0]+cur[1]));
//			//printf("(%d,%d) pop and clear all dp bit,dp %d\n",cur[0],cur[1],*(((int*)dp)+max_y*cur[0]+cur[1]));
//			Stack_Pop(stack);
//		}
//	}
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
///*��ŵ�˼·�ǣ�
//1.�ҵ�һ�����ʵĵ㣨�Ǳ߽磬�Ǳ�ǣ�����ջ������ջ����ֱ����ջ���Ҳ�����һ����ų�ջ��������һ��
//2.��ջʱ��Ҫ���б�ǣ����ҵ��յ�ʱͬ����ջ�������ô�ӡ������������յ��ջ���ָ���Ǽ��ɼ��ɣ���������
//
//��ʵ��Ҫ�������³���
//0 0 0
//0 0 0 
//1 0 0
//·��(0,0)->(0,1)->(1,1)->(1,0)ʱ����ʱ���ջ��(1,0)����4������ı��������������У������Ѿ�����ǣ�����Ҳ����ǣ����²��У�
//
//��ʱ��ջ������û�лָ��ȱ�ǣ���һֱ��ջ��(0,0)��������Ԫ�ر����Ϸ��ĵ�����Ϊ����ǵ��£�0,0��->(1,0)->(1,1)·�߱��¶�,
//
//������Ҫ�������·�ʽ��������һ����ǰ�Ķ��㣬��������ĸ�����û�б����Ļ�*/
//
//#define MAZE_MAX_X 4
//#define MAZE_MAX_Y 4
//
//#define MAX_DIR 4
//#define DIM 2
//
//#define IS_DP_BITN_TRUE(value,bitn) ((value) >> (bitn)) & 0x1 
//
//#define SET_DP_BITN(value,bitn,flag) \
//	if((flag) == 1)\
//{\
//	(value) = ((value) | (0x1 << bitn));\
//}\
//	else\
//	(value) = ((value) & (~(0x1<<bitn)))
//
//#define CLEAR_DP_ALL(value) (value) = 0x0
//
//
//
///*�����ģ��,����ԭ�������Ϸ�������Ļ���ʵ���м�1*/
////���ң��ϣ���
//static const int s_dirs[MAX_DIR][DIM] = {{0,-1},{0,1},{-1,0},{1,0}};
//
//
///*ջ��ʼ*/
//typedef struct Stack_
//{
//	int cap;
//	int top;
//	int** data; 
//}STACK_S;
//
//void Stack_Init(STACK_S* stack,int cap,int size)
//{
//	int i = 0;
//	stack->cap = cap;
//	stack->top = -1;
//	stack->data = (int**)malloc(sizeof(int*)*cap);
//	for(i = 0; i <= cap -1 ;i++)
//	{
//		stack->data[i] = (int*)malloc(sizeof(int)*size);
//		memset(stack->data[i],0,sizeof(int)*size);
//	}
//}
//
//int Stack_Is_Full(STACK_S* stack)
//{
//	return (stack->top == stack->cap) ? 1 : 0;
//}
//
//int Stack_Is_Empty(STACK_S* stack)
//{
//	return (stack->top == -1) ? 1 : 0;
//}
//
//void Stack_Pushback(STACK_S* stack,int x,int y)
//{
//	if(Stack_Is_Full(stack) != 1)
//	{
//		stack->top++;
//		stack->data[stack->top][0] = x;
//		stack->data[stack->top][1] = y;
//	}
//}
//int* Stack_GetTop(STACK_S* stack)
//{
//	if(Stack_Is_Empty(stack) != 1)
//	{
//		return stack->data[stack->top];
//	}
//	else
//		return NULL;
//}
//
//void Stack_Pop(STACK_S* stack)
//{
//	if(Stack_Is_Empty(stack) != 1)
//	{
//		stack->top--;
//	}
//}
///******************ջ����***************/
//
//
//int Point_Is_Boundry(int max_x,int max_y,int x,int y)
//{
//	if(x < 0 || x >= max_x || y < 0 || y >= max_y)
//		return 1;
//	return 0;
//}
//
//
///*��ӡջ�е�·��**/
//void printf_stack_path(STACK_S* stack)
//{
//	STACK_S stack_temp = {0};
//	int* data = NULL;
//	Stack_Init(&stack_temp,stack->cap,2);
//	//��ջ���ŵ���һ��ջ
//	while(Stack_Is_Empty(stack) != 1)
//	{
//		data = Stack_GetTop(stack);
//		Stack_Pushback(&stack_temp,data[0],data[1]);
//		Stack_Pop(stack);
//	}
//	while(Stack_Is_Empty(&stack_temp) != 1)
//	{
//		data = Stack_GetTop(&stack_temp);
//		printf("(%d,%d)->",data[0],data[1]);
//		Stack_Pushback(stack,data[0],data[1]);
//		Stack_Pop(&stack_temp);
//	}
//	//�˸�����һ��"->"ȥ��
//	printf("\b\b\t\n");	
//
//}
//
//void Maze_Dfs_All_Path(int** maze,int max_x,int max_y,int* start,int* end,STACK_S* stack,int** dp)
//{
//	int i = 0;
//	int next_x = 0,next_y = 0;
//	int *cur = 0;
//	int pre_x = -1,pre_y = -1;
//	//�����ջ
//	Stack_Pushback(stack,start[0],start[1]);
//	SET_DP_BITN(*(((int*)dp)+max_y*start[0]+start[0]),4,1);
//
//	while(Stack_Is_Empty(stack) != 1)
//	{
//		cur = Stack_GetTop(stack);
//		//printf("cur:(%d,%d)\n",cur[0],cur[1]);
//		for(i =0; i <= MAX_DIR -1;i++ )
//		{
//			next_x = cur[0]+s_dirs[i][0];
//			next_y = cur[1]+s_dirs[i][1];
//			//printf("next:(%d,%d)\n",next_x,next_y);
//			if(Point_Is_Boundry(max_x,max_y,next_x,next_y) == 1)
//			{
//				//printf("Boundry:(%d,%d)\n",next_x,next_y);
//				continue;
//			}
//			if( *(((int*)maze)+max_y*next_x+next_y) == 1)
//			{
//				//printf("maze is 1 (%d,%d)\n",next_x,next_y);
//				continue;
//			}
//			//�����һ���ڵ��Ѿ����,�򲻺Ϸ�����Ѱ����һ������
//			if(IS_DP_BITN_TRUE(*(((int*)dp)+max_y*next_x+next_y),4))
//			{
//				//printf("dp is 1 (%d,%d)\n",next_x,next_y);
//				continue;
//			}
//			//������ڵ㷽���Ѿ��������򲻼���
//			if(IS_DP_BITN_TRUE(*(((int*)dp)+max_y*cur[0]+cur[1]),i))
//			{
//				//printf("(%d,%d) �� %d �����Ѿ�����\n",cur[0],cur[1],i);
//				continue;
//			}
//			//printf("now (%d,%d) push back\n",next_x,next_y);
//			Stack_Pushback(stack,next_x,next_y);
//			//������һ�ڵ�Ϊ�Ѿ�����,�Լ����ڵ�ķ���
//			SET_DP_BITN(*(((int*)dp)+max_y*next_x+next_y),4,1);
//			SET_DP_BITN(*(((int*)dp)+max_y*cur[0]+cur[1]),i,1);
//			if(next_x == end[0] && next_y == end[1])
//			{
//				printf_stack_path(stack);
//				//�յ��ջ��������лָ���ǵĻ�����һ�ξͲ������
//				Stack_Pop(stack);
//				CLEAR_DP_ALL(*(((int*)dp)+max_y*end[0]+end[1]));
//				continue;
//			}
//			else
//				break;	
//		}
//		if(i >= MAX_DIR)
//		{
//			CLEAR_DP_ALL(*(((int*)dp)+max_y*cur[0]+cur[1]));
//			//printf("(%d,%d) pop and clear all dp bit,dp %d\n",cur[0],cur[1],*(((int*)dp)+max_y*cur[0]+cur[1]));
//			Stack_Pop(stack);
//		}
//	}
//}
//
//int main()
//{
//	int len = 0, i =0,j = 0;
//	//bit0:1:2:3�ֱ��ʾ����ǰ��ı�־λ��bit4��ʾ�Ƿ��Ǳ�����
//	int dp[MAZE_MAX_X][MAZE_MAX_Y] = {0};
//	int maze[MAZE_MAX_X][MAZE_MAX_Y] = {
//		{0,0,1,0},
//		{0,0,0,0},
//		{1,1,0,0},
//		{0,0,1,0},
//	};
//	//��㡢�յ�
//	int start[2] = {0,0};
//	int end[2] = {2,3};
//	STACK_S stack = {0};
//	Stack_Init(&stack,100,2);
//	memset((int*)dp,0,sizeof(int)*MAZE_MAX_X*MAZE_MAX_Y);
//	Maze_Dfs_All_Path((int**)maze,MAZE_MAX_X,MAZE_MAX_Y,start,end,&stack,(int**)dp);
//	return 0;
//}
//
//int main()
//{
//	int len = 0, i =0,j = 0;
//	//bit0:1:2:3�ֱ��ʾ����ǰ��ı�־λ��bit4��ʾ�Ƿ��Ǳ�����
//	int dp[MAZE_MAX_X][MAZE_MAX_Y] = {0};
//	int maze[MAZE_MAX_X][MAZE_MAX_Y] = {
//		{0,0,1,0},
//		{0,0,0,0},
//		{1,1,0,0},
//		{0,0,1,0},
//	};
//	//��㡢�յ�
//	int start[2] = {0,0};
//	int end[2] = {2,3};
//	STACK_S stack = {0};
//	Stack_Init(&stack,100,2);
//	memset((int*)dp,0,sizeof(int)*MAZE_MAX_X*MAZE_MAX_Y);
//	Maze_Dfs_All_Path((int**)maze,MAZE_MAX_X,MAZE_MAX_Y,start,end,&stack,(int**)dp);
//	return 0;
//}

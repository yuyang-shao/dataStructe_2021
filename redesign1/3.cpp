//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
///*大概的思路是：
//1.找到一个合适的点（非边界，非标记）就入栈，访问栈顶，直到该栈顶找不到下一个点才出栈，返回上一层
//2.入栈时需要进行标记，当找到终点时同样入栈，并调用打印函数，把这个终点出栈并恢复标记即可即可，继续搜索
//
//其实需要考虑如下场景
//0 0 0
//0 0 0 
//1 0 0
//路线(0,0)->(0,1)->(1,1)->(1,0)时，此时会对栈顶(1,0)进行4个方向的遍历，发现往左不行，往右已经被标记，往上也被标记，往下不行，
//
//此时出栈，但是没有恢复比标记，当一直出栈到(0,0)发现往下元素本来合法的但是因为被标记导致（0,0）->(1,0)->(1,1)路线被堵顶,
//
//所以需要增加如下方式：即对于一个当前的顶点，如果他的四个方向都没有遍历的话*/
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
///*方向的模拟,坐标原点在左上方，向左的话其实是列减1*/
////左，右，上，下
//static const int s_dirs[MAX_DIR][DIM] = {{0,-1},{0,1},{-1,0},{1,0}};
//
//
///*栈开始*/
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
///******************栈结束***************/
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
///*打印栈中的路径**/
//void printf_stack_path(STACK_S* stack)
//{
//	STACK_S stack_temp = {0};
//	int* data = NULL;
//	Stack_Init(&stack_temp,stack->cap,2);
//	//把栈给放到另一个栈
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
//	//退格把最后一个"->"去掉
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
//	//起点入栈
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
//			//如果下一个节点已经标记,则不合法继续寻找下一个方向
//			if(IS_DP_BITN_TRUE(*(((int*)dp)+max_y*next_x+next_y),4))
//			{
//				//printf("dp is 1 (%d,%d)\n",next_x,next_y);
//				continue;
//			}
//			//如果本节点方向已经被遍历则不继续
//			if(IS_DP_BITN_TRUE(*(((int*)dp)+max_y*cur[0]+cur[1]),i))
//			{
//				//printf("(%d,%d) 的 %d 方向已经遍历\n",cur[0],cur[1],i);
//				continue;
//			}
//			//printf("now (%d,%d) push back\n",next_x,next_y);
//			Stack_Pushback(stack,next_x,next_y);
//			//设置下一节点为已经访问,以及本节点的方向
//			SET_DP_BITN(*(((int*)dp)+max_y*next_x+next_y),4,1);
//			SET_DP_BITN(*(((int*)dp)+max_y*cur[0]+cur[1]),i,1);
//			if(next_x == end[0] && next_y == end[1])
//			{
//				printf_stack_path(stack);
//				//终点出栈如果不进行恢复标记的话，下一次就不会进了
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
///*大概的思路是：
//1.找到一个合适的点（非边界，非标记）就入栈，访问栈顶，直到该栈顶找不到下一个点才出栈，返回上一层
//2.入栈时需要进行标记，当找到终点时同样入栈，并调用打印函数，把这个终点出栈并恢复标记即可即可，继续搜索
//
//其实需要考虑如下场景
//0 0 0
//0 0 0 
//1 0 0
//路线(0,0)->(0,1)->(1,1)->(1,0)时，此时会对栈顶(1,0)进行4个方向的遍历，发现往左不行，往右已经被标记，往上也被标记，往下不行，
//
//此时出栈，但是没有恢复比标记，当一直出栈到(0,0)发现往下元素本来合法的但是因为被标记导致（0,0）->(1,0)->(1,1)路线被堵顶,
//
//所以需要增加如下方式：即对于一个当前的顶点，如果他的四个方向都没有遍历的话*/
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
///*方向的模拟,坐标原点在左上方，向左的话其实是列减1*/
////左，右，上，下
//static const int s_dirs[MAX_DIR][DIM] = {{0,-1},{0,1},{-1,0},{1,0}};
//
//
///*栈开始*/
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
///******************栈结束***************/
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
///*打印栈中的路径**/
//void printf_stack_path(STACK_S* stack)
//{
//	STACK_S stack_temp = {0};
//	int* data = NULL;
//	Stack_Init(&stack_temp,stack->cap,2);
//	//把栈给放到另一个栈
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
//	//退格把最后一个"->"去掉
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
//	//起点入栈
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
//			//如果下一个节点已经标记,则不合法继续寻找下一个方向
//			if(IS_DP_BITN_TRUE(*(((int*)dp)+max_y*next_x+next_y),4))
//			{
//				//printf("dp is 1 (%d,%d)\n",next_x,next_y);
//				continue;
//			}
//			//如果本节点方向已经被遍历则不继续
//			if(IS_DP_BITN_TRUE(*(((int*)dp)+max_y*cur[0]+cur[1]),i))
//			{
//				//printf("(%d,%d) 的 %d 方向已经遍历\n",cur[0],cur[1],i);
//				continue;
//			}
//			//printf("now (%d,%d) push back\n",next_x,next_y);
//			Stack_Pushback(stack,next_x,next_y);
//			//设置下一节点为已经访问,以及本节点的方向
//			SET_DP_BITN(*(((int*)dp)+max_y*next_x+next_y),4,1);
//			SET_DP_BITN(*(((int*)dp)+max_y*cur[0]+cur[1]),i,1);
//			if(next_x == end[0] && next_y == end[1])
//			{
//				printf_stack_path(stack);
//				//终点出栈如果不进行恢复标记的话，下一次就不会进了
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
//	//bit0:1:2:3分别表示左右前后的标志位，bit4表示是否标记被访问
//	int dp[MAZE_MAX_X][MAZE_MAX_Y] = {0};
//	int maze[MAZE_MAX_X][MAZE_MAX_Y] = {
//		{0,0,1,0},
//		{0,0,0,0},
//		{1,1,0,0},
//		{0,0,1,0},
//	};
//	//起点、终点
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
//	//bit0:1:2:3分别表示左右前后的标志位，bit4表示是否标记被访问
//	int dp[MAZE_MAX_X][MAZE_MAX_Y] = {0};
//	int maze[MAZE_MAX_X][MAZE_MAX_Y] = {
//		{0,0,1,0},
//		{0,0,0,0},
//		{1,1,0,0},
//		{0,0,1,0},
//	};
//	//起点、终点
//	int start[2] = {0,0};
//	int end[2] = {2,3};
//	STACK_S stack = {0};
//	Stack_Init(&stack,100,2);
//	memset((int*)dp,0,sizeof(int)*MAZE_MAX_X*MAZE_MAX_Y);
//	Maze_Dfs_All_Path((int**)maze,MAZE_MAX_X,MAZE_MAX_Y,start,end,&stack,(int**)dp);
//	return 0;
//}

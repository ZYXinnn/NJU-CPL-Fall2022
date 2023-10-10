#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define SIZE 8//边长 超过100会显示错误
#define NUM 10//雷数量 都可修改 最好不要让雷数量接近格子总数 否则会初始化很长时间乃至死循环
//难度可参考：初级 8*8 10雷 中级 16*16 40雷 高级 16*30 99雷 
int a[SIZE+2][SIZE+2];//雷区-1，否则是周围雷区个数
int b[SIZE+2][SIZE+2];//是否可显示
void textcolor(int color) // 更改字体颜色（这确实是用的别人代码）
{
	//在文本模式中选择新的字符颜色
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // 得到标准输出的句柄
	SetConsoleTextAttribute(hOutput, color);//Attribute:属性
}
void out(int p){//主要输出 p=1为正常，0为调试
	for(int i=0;i<=SIZE+1;i++)
	{
		for(int j=0;j<=SIZE+1;j++)
		{
			if(i==0)
			{
				if(j>=9&&j%2==0)//两位数上面显示奇数，下面偶数，方便读坐标
				{
					printf("  ");
					continue;
				}
				textcolor(15);
				if(j==SIZE+1)
					printf(" 0");
				else
					printf("%2d",j);
				continue;
			}
			if(j==0&&i!=0)
			{
				textcolor(15);
				if(i==SIZE+1)
					printf(" 0");
				else
					printf("%2d",i);
				continue;
			}
			if(i==SIZE+1&&j!=SIZE+1)
			{
				if(j>=9&&j%2!=0)
				{
					printf("  ");
					continue;
				}
				textcolor(15);
				printf("%2d",j);
				continue;
			}
			if(j==SIZE+1&&i!=SIZE+1)
			{
				textcolor(15);
				printf("%2d",i);
				continue;
			}
			if(i==SIZE+1&&j==SIZE+1)
			{
				textcolor(15);
				printf(" 0");
				continue;
			}
			if(b[i][j]==0&&p==1)
			{
				textcolor(8);
				printf(" ?");
			}
			else
			{
				if(a[i][j]!=-1)
				{
					textcolor(3);
					printf("%2d",a[i][j]);
				}
				else
				{
					textcolor(4);
					printf(" *");
				}
			}
		}
		printf("\n");
	}
	printf("\n\n\n");
}
void scan(int x,int y){//初始化a[]
	int n=0;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			if(a[x+i][y+j]==-1)
				n++;
	if(a[x][y]!=-1)
		a[x][y]=n;
}
void step(int x,int y){//模拟一次出来一大片的效果，用了递归，边界情况比较麻烦
	if(b[x][y]==1)
		return;
	b[x][y]=1;
	if(a[x][y]==0)
	{
		if(x+1<SIZE+1&&a[x+1][y]!=-1)
			step(x+1,y);
		if(x-1>0&&a[x-1][y]!=-1)
			step(x-1,y);
		if(y+1<SIZE+1&&a[x][y+1]!=-1)
			step(x,y+1);
		if(y-1>0&&a[x][y-1]!=-1)
			step(x,y-1);
		if(x+1<SIZE+1&&y+1<SIZE+1&&a[x+1][y+1]!=-1)
			step(x+1,y+1);
		if(x-1>0&&y-1>0&&a[x-1][y-1]!=-1)
			step(x-1,y-1);
		if(y+1<SIZE+1&&x-1>0&&a[x-1][y+1]!=-1)
			step(x-1,y+1);
		if(y-1>0&&x+1<SIZE+1&&a[x+1][y-1]!=-1)
			step(x+1,y-1);
	}
	else
	{
		if(a[x-1][y]==0&&x-1>0)
			step(x-1,y);
		if(a[x+1][y]==0&&x+1<SIZE+1)
			step(x+1,y);
		if(a[x][y-1]==0&&y-1>0)
			step(x,y-1);
		if(a[x][y+1]==0&&y+1<SIZE+1)
			step(x,y+1);
		if(a[x-1][y-1]==0&&x-1>0&&y-1>0)
			step(x-1,y-1);
		if(a[x+1][y+1]==0&&x+1<SIZE+1&&y+1<SIZE+1)
			step(x+1,y+1);
		if(a[x+1][y-1]==0&&y-1>0&&x+1<SIZE+1)
			step(x+1,y-1);
		if(a[x-1][y+1]==0&&y+1<SIZE+1&&x-1>0)
			step(x-1,y+1);
	}
}
int main(){
	int i,j,r1,r2,x,y,n=NUM,m,t=0,up=0,start,end;
	start=clock();
	textcolor(4);
	printf("扫雷v0.5\n");
	textcolor(6);
	printf("注意：第一行、最后一行和第一列、最后一列是坐标  标记错误也会失败 输入坐标后接着输1为踩0为标记 需要正确标记所有雷游戏才会结束\n");
	srand(time(0));
	for(i=1;i<=NUM;i++)
	{
		r1=rand();
		x=r1%SIZE+1;
		r2=rand();
		y=r2%SIZE+1;
		if(a[x][y]==-1)
			i--;
		else
			a[x][y]=-1;
	}
	for(i=1;i<=SIZE;i++)
	{
		for(j=1;j<=SIZE;j++)
		{
			scan(i,j);
		}
	}
	//out(0);//调试用
	while(n>0)
	{
		Sleep(2000);
		t++;
		out(1);
		textcolor(10);
		printf("输入坐标（行 列 1或0）：");
		scanf("%d %d %d",&x,&y,&m);
		printf("\n\n\n");
		if(m==0&&x>0&&x<SIZE+1&&y>0&&y<SIZE+1)
		{
			if(a[x][y]==-1)
			{
				textcolor(6);
				printf("你将一枚旗子插到了%d %d，土地中似乎传来一声哀鸣\n\n\n\n",x,y);
				b[x][y]=1;
				n--;
			}
			else
			{
				textcolor(6);
				printf("你自信地插下了旗帜，瞳孔却随即猛然收缩\n\"你!你血口喷人！\"\n被你冤枉的格子自爆了 你倒在了%d %d 坚持了%d回合\n\n\n",x,y,t);
				Sleep(5000);
				printf("但倒下的你抽出了残机！迸发出苏生的力量！\n");
				Sleep(2000);
				printf("\"扶我起来！\"\n空中降下一道圣光，你再一次复活了！\n\n\n\n");
				b[x][y]=1;
				up++;
				continue;
			}
		}
		else if(b[x][y]==0&&x>0&&x<SIZE+1&&y>0&&y<SIZE+1&&m==1)
		{
			if(a[x][y]==-1)
			{
				textcolor(6);
				printf("逐渐不耐烦的你选择了——\n竟然是在雷区蹦迪！\n你被炸死了 倒在了%d %d 坚持了%d回合\n\n\n",x,y,t);
				Sleep(5000);
				printf("但倒下的你抽出了残机！迸发出苏生的力量！\n");
				Sleep(2000);
				printf("\"扶我起来！\"\n空中降下一道圣光，你再一次复活了！\n\n\n\n");
				b[x][y]=1;
				n--;
				up++;
				continue;
			}
			else
			{
				textcolor(6);
				printf("你小心翼翼地踩上了%d %d，无事发生\n\n\n\n",x,y);
				step(x,y);
			}
		}
		else
		{
			textcolor(10);
			printf("输入错误\n\n\n");
			t--;
			continue;
		}
	}
	end=clock();
	textcolor(6);
	printf("很遗憾……\n");
	Sleep(3000);
	printf("经过%d回合的苦战\n",t);
	Sleep(1000);
	printf("你逃出生天\n\n\n\n");
	Sleep(3000);
	out(0);
	printf("\n\n\n");
	textcolor(12);
	printf("消耗残机：%d\n",up);
	int score =10000-(end-start)/1000-up*300;
	printf("消耗时间：%.3f秒\n",(end-start)/1000.0);
	printf("分数：%d\n可喜可贺！可喜可贺！\n",score);
	system("pause");
	return 0;
}

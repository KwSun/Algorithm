#include <stdio.h>
#define MAXLINE 1000  //可输入的最大长度

int getlines(char line[],int maxline);   //读取输入的下一行
void copy(char to[],char from[]);//把新行复制到安全位置

int main(int argc, char const *argv[])
{
	int len;   //当前行的长度
	int max;   //已处理行的最大长度
	char line[MAXLINE];	//当前输入行
	char longest[MAXLINE];	//所保存的最长行

	max = 0;
	while ((len = getlines(line,MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(longest,line);
		}
	if (max > 0)
	{
		printf("%s\n", longest);
	}
	return 0;
}
/* getline:将一行读入s，并返回长度 */
int getlines(char s[],int lim)
{
	int c,i;
	for (int i = 0; i < lim-1 && (c=gerchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
/* copy:将from 拷贝进to */
void copy(char to[],char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}

/*	动态规划最重要的就是 1.最优问题都可以转化为 子问题的最优问题  2.子问题可以转化为其他子问题的重叠问题。
 *	递归版本 备忘录动态规划 和  自低而上的动态规划
 *	动态规划入门的一个小实例:  (本实例使用难道是自底而上的备忘录递归方法-_-!!zZZZZ)
 *	现在有这样一个工作 每一份工作的起止时间如下data中 每个工作时段获取的价值如下：
 *	work    time      value	
 *	 1		1,4			5		
 *	 2		3,5			1
 *	 3		0,6			8
 *	 4		4,7			4
 *	 5		3,8			6
 *	 6		5,9			3
 *	 7		6,10		2
 *	 8		8,11		4
 *	一位员工如何工作才能做得最大的价值
 *
 *	分析：需要按照动态规划的思想去完成该算法
 *		  首先将 获取的价值分为已选和未选(未选的可以规定为为已选的前面的时段的工作)  
 *		  然后 opt(i) = Max( opt(i-1) , value[i]+opt(prev(i)) )  //未选的为前一个工作的价值，已选的可以是自身工作的价值加上与前面
 *		  工作不冲突的某个工作的价值。
 * */
#include<iostream>
#include<vector>
#include "stdlib.h"
#include "string.h"
using namespace std;

#define UInt16 unsigned short
#define UInt32 unsigned int
#define Max(a,b) a>b?a:b
struct TimeRange
{
	unsigned int begin;
	unsigned int end;
	TimeRange():begin(0),end(0)
	{}
	bool operator >= (const TimeRange &tr)
	{
		return begin >= tr.end;
	}
};
typedef TimeRange timeRange;

UInt32 Mem[8] = {0};

std::vector<timeRange> timeRangeVec;
UInt32 value[8] = {5,1,8,4,6,3,2,4};

UInt32 optPrev(UInt32 n)  //计算符合规则的最近一个工作的价值
{
	for(size_t i = n;i>1;--i)
	{
		if(timeRangeVec[n-1] >= timeRangeVec[i - 1 - 1])	//数组从零开始计数
			return i-1;
	}
	return 0;
}

UInt32 opt(UInt32 n)		//获得某一个时段的最大的工作价值
{
	if(n == 0)
	{
		return 0;
	}
	//添加Mem 空间换取时间 将已经计算过的数据保存好 不用每次都计算
	if(Mem[n-1] != 0)
		return Mem[n-1];
	UInt32 optp = optPrev(n);
	Mem[n-1] = Max(opt(n-1),( value[n-1]+opt(optp) ) );
	return Mem[n-1];
}

void addData(UInt32 b,UInt32 e)
{
	timeRange trv;
	trv.begin = b;
	trv.end = e;
	timeRangeVec.push_back(trv);
}

int main(void)
{
	memset(Mem,0,sizeof(Mem));
	//UInt32 opt[timeRangeVec.size()];
	addData(1,4);
	addData(3,5);
	addData(0,6);
	addData(4,7);
	addData(3,8);
	addData(5,9);
	addData(6,10);
	addData(8,11);
	for(size_t i = 1;i<9;++i)
	{	
		UInt32 result = opt(i);
		cout<<result<<endl;
	}
	//opt(4);

	return 0;
}

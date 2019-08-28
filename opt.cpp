/*动态规划入门的一个小实例*/
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

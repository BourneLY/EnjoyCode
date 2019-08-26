/*数组指针:(*p)[] 实际含义是指针P指向一个数组的头部 p++ 则是二维数组的第二行开始*/
/*2019年8月27日00:36:56
 *数组指针：重点在于指针，首先就是一个指针，只不过指针的指向不在是变量名的地址，而是一个数组名的地址(数组名就是这个数组的首地址)
 *			其实就是指针按照数组的规则做偏移.那么数组指针的可以理解为先按照指针的方式偏移到对应的地址，找到地址上的数组，在查找
 *			数组上的某一个值。  实际上是按照指针的方式来查找数据的 下面的例子 (*p)[2] = 3 是可以查找到3的(一般在内存够用的情况下
 *			是连续的)
 *			表现形式：int(*p)[];p:第一行。++p:第二行
 *指针数组：重点在于数组，首先是一个数组，数组的每一个元素是由指针组成的。可不可以理解为：先按照数组的方式找到指针然后按照指针地址偏移
 *			的方式找对应的数据。
 *			表现形式：int *q[]
 *
 *
 *
 * 例子在下面
 *
 *
 *
 * */
#include <iostream>
using namespace std;

int main(void)
{
	int a[3][2] = {{1,2},{3,4},{4,5}};
	int b[3][3] = {1,2,3,4,5,6,7,8,9};
	int (*p)[2];
	int *q[3];
	q[0] = b[0];  //数组名就是数组的首地址，二维数组 行首数组就是这一行的首地址。 二维数组的数组名就是二维数组的首地址。
	p = a;		  //二维数组的数组名就是二维数组的首地址。
	//cout<<*(*p)<<endl;
	//cout<<*p<<endl;
	//cout<<*(*(++p))<<endl;
	//cout<<*q<<endl;
	cout<< (*p)[1]<<endl;
	cout<<*(++(q[0])<<endl;
	cout<<b[0]<<endl;
	return 0;
}

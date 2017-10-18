#include <stdio.h>
#include "RefBase.h"
#define LOG_LINE() fprintf(stderr, "[%s:%d]\n", __FUNCTION__, __LINE__)
using namespace android;
class A : public RefBase  {
public:
	A()
	{fprintf(stderr, "class A Ctor\n");}

	virtual ~A()
	{fprintf(stderr, "class A Dtor\n");}
};

int main()
{
	LOG_LINE();
	A* pA = new A;
	LOG_LINE();
	{
		LOG_LINE();
		sp<A> spA(pA);
		LOG_LINE();
		wp<A> wpA(spA);
		LOG_LINE();
		//大括号结束前，先析构wp，再析构sp。
	}
	LOG_LINE();
}
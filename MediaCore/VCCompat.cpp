#include "VCCompat.h"
#include <windows.h>
#include <float.h>
#include <math.h>

double _round(double val)
{
	return (val> 0.0) ? floor(val+ 0.5) : ceil((float)(val- 0.5));
}

int compat_sqrt(int i){
	return (int)sqrt((float)i);
}

double _log(int i){
	double db=(double)i;
	return log(db);
}

AVRational _AVRational(int num, int den) {  
	AVRational r = {num, den};  
	return r;  
}

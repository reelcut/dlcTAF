/* Call Library source file */
#include <math.h>

_declspec(dllexport) void arrayshift(short SaveArray[], short NewArray[], 
		long NChan, long NData,long NNew, long *Index);

_declspec(dllexport) void arrayshift(short SaveArray[], short NewArray[],
		long NChan, long NData,long NNew, long *Index)
	{


	long ii,jj,ind,ind2,nind,nind2;


	ind  = *Index;
	ind2 = 0;
	
	for (ii=0;ii<NNew;ii++){
		if (ind>NData-1){
			/* if the ind goes past the end start from begining*/
			ind = ind - (long)floor(ind/NData)*NData;
		}
		for (jj=0;jj<NChan;jj++){
			nind = ind + jj*NData;
			nind2 = ind2 + jj*NNew;
			SaveArray[nind] = NewArray[nind2];
		}
		ind++;
		ind2++;
	}	
	if (ind>NData-1){
			ind = ind - (long)floor(ind/NData)*NData;	
	}
	*Index = ind;

	return;
	}

/* Call Library source file */
#include <math.h>


_declspec(dllexport) void THcrossing_c(short NewData[], long Nnew, long Nchan, long TH, 
	long MonChan, long *Crossing, double MnSmoothFac, double *mean);

_declspec(dllexport) void THcrossing_c(short NewData[], long Nnew, long Nchan, long TH, 
	long MonChan, long *Crossing, double MnSmoothFac, double *mean)
	
{

	long ii,ind,DIDCROSS,skipit;
	double mn,tmp;
		
	/*mn=0;skipit=MonChan*Ndata;
	for (ii=0;ii<Ndata;ii++){
			mn += (double)InputArray[ii+skipit];
	}
	if (Ndata>0) {
		mn = mn/Ndata;
	} else {
		mn=0.0;
	}
	*mean=mn;*/

	skipit=MonChan*Nnew;
	mn=0;
	for (ii=0;ii<Nnew;ii++) {
		mn += (double)NewData[ii+skipit];
	}
	if (Nnew>0){
		mn = mn/(double)Nnew;
	} else {
		mn = 0;
	}

	/*tmp = (*mean + mn)*0.5;*/
	*mean = *mean*(1.0-MnSmoothFac) + MnSmoothFac*mn;

	ind=0;DIDCROSS=0;tmp=0;
	while ((ind<Nnew)&&(DIDCROSS==0)) {
		tmp=(double)NewData[ind+skipit] - *mean;
		
		if (tmp<0){
			tmp=-tmp;
		}
	
		if (tmp>=TH) {
			DIDCROSS=1;
		}
			
		ind++;
	}
	*Crossing=DIDCROSS;

	return;	
}

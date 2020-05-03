/* Call Library source file */

_declspec(dllexport) void PullOutData(short InputArray[], long Ndat, long WhichInd, short OutVec[]);

_declspec(dllexport) void PullOutData(short InputArray[], long Ndat, long WhichInd, short OutVec[])
	
{	
	long ii,skipit;
		
	skipit=WhichInd*Ndat;
	for (ii=0;ii<Ndat;ii++){
			OutVec[ii] = InputArray[ii+skipit];
	}
}
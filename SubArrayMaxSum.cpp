#include<iostream>
Using namespace std;

Int main()
{
	//consecutive sum of a array
	Int maxendinghere=0;
	Int maxsofar=-INF;
	For (int i=0;i<array.length();i++)
	{	
		//if maxendinghere is a sum which counts till the current element (array[currLoc]) and must contain the current element, otherwise, it cannot gurantee the consecutive. Thus, if the previous maxendinghere is positive, then we use it, if the previous maxendinghere is negtive, then we give up it.
//if maxendinghere>0 && array[i]>0, then maxendinghere+array[i]
//if maxendinghere>0 && array[i]<0, then maxendinghere+array[i]
//if maxendinghere<0 && array[i]>0, then array[i]
//if maxendinghere<0 && array[i]<0, then array[i]
maxendinghere=max(maxendinghere+array[i],array[i]);

//we have to record the max-consecutive-sum so far.
maxsofar=max(maxsofar,maxendinghere);	
	}
Return 0;
}
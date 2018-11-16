#include<iostream>
#include<algorithm>

int main()
{
	//given two strings x and y, we have to compute the longest common substring
	//note, we’d better push back the first character of x and y one character.
//for example, we can use 
scanf(“%s %s”,x+1, y+1);// it automatically push back x and y by one character. 
	//initialization
	For (int i=0;i<x.length()+1;i++)
		lcs[i][0]=0;
	For (int j=0;j<y.length()+1;j++)//because we donot have value on the 0th position
		lcs[0][j]=0;
	For (int i=1;i<x.length();i++)
		For (int j=1;j<y.length();j++)
			If (x[i]==y[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			Else
			{
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
}
	for
Return 0;
}
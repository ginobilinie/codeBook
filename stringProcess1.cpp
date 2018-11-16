#include<iostream>
#include<string>

using namespace std;

#define eps 0.00001
double findSign(string line,string sign);

int main()
{
	string line;
	char str[100];
	int cases;
	//cin>>cases;
	scanf("%d\n",&cases);
	int ind=0;
	while(cases--)
	{
		//cin.getline(str,sizeof(str));
		getline(cin,line);
		double pNum=findSign(line,"P=");
		double uNum=findSign(line,"U=");
		double iNum=findSign(line,"I=");
		ind++;
		printf("Problem #%d\n",ind);
		if (pNum+1<eps)
		{
			pNum=uNum*iNum;
			printf("P=%.2fW\n",pNum);
		}
		else if (uNum+1<eps)
		{
			uNum=pNum/iNum;
			printf("U=%.2fV\n",uNum);
		}
		else if (iNum+1<eps)
		{
			iNum=pNum/uNum;
			printf("I=%.2fA\n",iNum);
		}
		printf("\n");
	}
	return 0;
}

double findSign(string line,string sign)
{
	double res=-1,times=1;
	string num;
	for (int i=0;i<line.length()-1;i++)
	{
		if (line.substr(i,2)==sign)
		{
			i=i+2;

			while(i<line.length())
			{
				if (line[i]>='0'&&line[i]<='9'||line[i]=='.')
				{
					num+=line[i];
				}
				else if (line[i]=='W'||line[i]=='A'||line[i]=='V')
				{
					res=atof(num.c_str());
					break;
				}
				else if (line[i]=='m')
				{
					times=0.001;
				}
				else if (line[i]=='k')
				{
					times=1000;
				}
				else if (line[i]=='M')
				{
					times=1000000;
				}
				i++;
			}
			break;
		}
	}
	res*=times;
	return res;
}
#include<stdio.h>
#include<math.h>
#define MAX 4
int integers[MAX], dpoints[MAX]={0,0,0,0};
double mean=0, sum=0, num=0;

double mean(double mean);
double stddev(double stddev);
int max(int max);
int min(int min);

int main(){

	for(int i=0;i<MAX;i++){
		
		printf("Enter four integer values: ");
		scanf("%i",&integers[i]);
		sum+=integers[i];
	}
	
	mean(integers[MAX]);
	stddev(integers[MAX]);
	max(integers[MAX]);
	min(integers[MAX]);

}

double mean(){
	int sum;
	for(int j=0;j<MAX;j++){
		
		sum+=integers[j];
	}
	
	mean=sum/MAX;
	printf("The mean of your values is %.2lf", mean);
	
	return mean;
}

double stddev(double stddev){
	for(int j=0;j<MAX;j++){
		dpoints[j] = pow(integers[j]-mean,2);
	}

	for(int j=0;j<MAX;j++){
		int num;
		num += (double)dpoints[j];
	}

	stddev=sqrt(num/MAX);
	
	printf("The standard deviation of your values is %.2lf", stddev);

	return stddev;
}

int max(int max){
	for(int j=0;j<MAX;j++){
		if(integers[j]<integers[j+1])
		max=integers[j+1];
	}
	
	printf("The max of your values is %i", max);
	
	return max;
}

int min(int min){
	for(int j=0;j<MAX;j++){
		if(integers[j+1]<integers[j])
		min=integers[j+1];
	}
	
	printf("The min of your values is %i", min);
	
	return min;
}
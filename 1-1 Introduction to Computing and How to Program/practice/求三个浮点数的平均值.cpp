main()
{
	float average(float x,float y,float z);
	float a,b,c,ave;
	scanf("%f,%f,%f",&a,&b,&c);
	ave=average(a,b,c);
	printf("average=%f",ave);
}
float average(float x,float y,float z)
{
	float ave;
	aver=(x+y+z/3);
	return(ave);
}

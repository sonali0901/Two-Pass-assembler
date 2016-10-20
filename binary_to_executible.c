/*coa_project Students-Shubham Sharma Sonali Gupta Somya Shekhar Jain Simran GUpta */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//fuctions to call different operands
void ADD(float* regi3,float* regi1,float* regi2);
void ADi(float *regi1, int constant);
void SUB(float* regi3,float* regi1,float* regi2);
void SUi(float *regi1, int constant);
void MOV(float*regi1,float*regi2);
float MOi(float regi,int x);
int CMi(float* regi1,int);
void MUL(float* regi3,float* regi1,float* regi2);
void MUi(float *regi1, int constant);
void DIV(float* regi3,float* regi1,float* regi2);
void DIi(float *regi1, int constant);
int CMP(float* regi1,float* regi2);
void JLT(int addr);
void JGT(int addr);
void JEQ(int* addr);
void JMP(int* addr);
void HALT();

FILE *fp; //taking file as global

int main()
{
	
	fp= fopen("digits_binary.txt", "r");
	int m[32]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//mask for 27 bit opcode
	float r[16];
	int ginti,jhanda=0;
	int b[32],reslt[32];
	int a[50][32];
   	 char c;
  	  
  	  int j=0,i,k=0,regi1,regi2,regi3,constant,n=0;
  	if (fp == NULL)
        return 0; //could not open file
	
 	else
	{
   	 while ((c = fgetc(fp)) != EOF)
    	{
		while(c!='\n')
		{
		a[j][n] =  c-'0';//converting to int
		//a[j][n] =atoi(c);		
		n++;
		c=fgetc(fp);
		}
		j++;
		n=0;
    	}
		jhanda=0;
		for(i=0;i<j;)//each instruction
		{	
			
			
			ginti=0;
			//for(k=0;k<32;k++)//each bit
			//	b[k]=atoi(a[j][k]);//string to int array
			reslt[0]=0;
			
			for(k=0;k<17;k++)
			{
	

				reslt[k]=a[i][k];//checking opcode of length 17
			
			}
			for(k=0;k<4;k++)
				ginti=ginti+reslt[16-k]*pow(2,k);//4 bits of end
			switch (ginti)
			{
				case 0://ADD of adding so 3 regiisters
					printf("ADD\n");
					regi1=0,regi2=0,regi3=0;
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<4;k++)
						regi2=regi2+a[i][26-k]*pow(2,k);
					for(k=0;k<4;k++)
						regi3=regi3+a[i][31-k]*pow(2,k);
					ADD(&r[regi1],&r[regi2],&r[regi3]);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]); 
					printf("\n");
					i++;
					break;
				case 1://SUB 3 regi
					 regi1=0,regi2=0,regi3=0;
					printf("SUB\n");
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<4;k++)
						regi2=regi2+a[i][26-k]*pow(2,k);
					for(k=0;k<4;k++)
						regi3=regi3+a[i][31-k]*pow(2,k);
					SUB(&r[regi1],&r[regi2],&r[regi3]);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]); 
					printf("\n");
					i++;
					break;
				case 2://mulitply
					printf("MUL\n");
					 regi1=0,regi2=0,regi3=0;
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<4;k++)
						regi2=regi2+a[i][26-k]*pow(2,k);
					for(k=0;k<4;k++)
						regi3=regi3+a[i][31-k]*pow(2,k);
					MUL(&r[regi1],&r[regi2],&r[regi3]);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]); 
					printf("\n");
					i++;
					break;
				case 3://divide
					printf("DIV\n");
					 regi1=0,regi2=0,regi3=0;
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<4;k++)
						regi2=regi2+a[i][26-k]*pow(2,k);
					for(k=0;k<4;k++)
						regi3=regi3+a[i][31-k]*pow(2,k);
					DIV(&r[regi1],&r[regi2],&r[regi3]);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]);   
					printf("\n");
					i++;
					break;
				case 4://adi 1 regi then constant
					printf("ADi\n");
					 regi1=0,constant=0;
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					ADi(&r[regi1],constant);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]); 
					printf("\n");
					i++;
					break;
				case 5://Sui
					 regi1=0,constant=0;
					printf("SUi\n");
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					SUi(&r[regi1],constant);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]);  
					printf("\n");
					i++;
					break;
				case 6:
					 regi1=0,constant=0;
					printf("MUi\n");
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					MUi(&r[regi1],constant);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]);  
					printf("\n");
					i++;
					break;
				case 7:
					 regi1=0,constant=0;
					printf("DIi\n");
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					DIi(&r[regi1],constant);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]);  
					printf("\n");
					i++;
					break;
				case 8:
					printf("MOi\n");
					 regi1=0,constant=0;
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					
					for(k=0;k<10;k++)
						constant=constant+(a[i][31-k]*pow(2,k));
					
					r[regi1]=MOi(r[regi1],constant);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]);  
					printf("\n");
					i++;
					break;
				case 9:
					printf("CMi\n");
					regi1=0,constant=0;
					for(k=0;k<4;k++)
						regi1=regi1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					jhanda=CMi(&r[regi1],constant);
					printf("jhanda %d\n",jhanda);
					for(k=0;k<16;k++)
						printf("R%d=%d ",k,(int)r[k]);  
					printf("\n");
					i++;
					break;
				default:
					ginti=0;
					
					for(k=0;k<22;k++)
						reslt[k]=a[i][k];//checking opcode of length 22
					for(k=0;k<2;k++)
						ginti=ginti+reslt[21-k]*pow(2,k);//2 bits of end
					switch (ginti)
					{
						case 0://MOV
							 regi1=0,regi2=0;
							printf("MOV\n");
							for(k=0;k<4;k++)
								regi1=regi1+a[i][26-k]*pow(2,k);
							for(k=0;k<4;k++)
								regi2=regi2+a[i][31-k]*pow(2,k);
							MOV(&r[regi1],&r[regi2]);
							for(k=0;k<16;k++)
							printf("R%d=%d ",k,(int)r[k]);  
							printf("\n");
							i++;
							break;
						case 1://CMP
							printf("CMP\n");
							 regi1=0,regi2=0;
							for(k=0;k<4;k++)
								regi1=regi1+a[i][26-k]*pow(2,k);
							for(k=0;k<4;k++)
								regi2=regi2+a[i][31-k]*pow(2,k);
							jhanda=CMP(&r[regi1],&r[regi2]);
							i++;
							printf("jhanda %d\n",jhanda);
							for(k=0;k<16;k++)
							printf("R%d=%d ",k,(int)r[k]); 
							printf("\n");
							break;
						default:
							ginti=0;
							
							for(k=0;k<27;k++)
							reslt[k]=a[i][k];//checking opcode of length 27
							for(k=0;k<3;k++)
							ginti=ginti+reslt[26-k]*pow(2,k);//2 bits of end
							switch (ginti)			
							{
								case 0:
									printf("JMP\n");
									 regi1=0;
									for(k=0;k<5;k++)
									regi1=regi1+a[i][31-k]*pow(2,k);
									for(k=0;k<16;k++)
									printf("R%d=%d ",k,(int)r[k]);  
									printf("\n");
									i=regi1-1;
									break;
								case 1:
									if(jhanda==0)
									{
									regi1=0;
									printf("JEQ\n");
									for(k=0;k<5;k++)
									regi1=regi1+a[i][31-k]*pow(2,k);
									i=regi1-1;
									for(k=0;k<16;k++)
									printf("R%d=%d ",k,(int)r[k]); 
									printf("\n");
									}
									else
									{
										i++;
										
									}
									break;
										
								case 2:
									if(jhanda==1)
									{
									 regi1=0;
									printf("JGT\n");
									for(k=0;k<5;k++)
									regi1=regi1+a[i][31-k]*pow(2,k);
									i=regi1-1;
									for(k=0;k<16;k++)
									printf("R%d=%d ",k,(int)r[k]); 
									printf("\n");
									}
									else
									{
										i++;
										
									}
									break;
								case 3:
									if(jhanda<1)
									{
									regi1=0;
									printf("JLT\n");
									for(k=0;k<5;k++)
									{
										
										regi1=regi1+a[i][31-k]*pow(2,k);
									}
									for(k=0;k<16;k++)
									printf("R%d=%d ",k,(int)r[k]); 
									printf("\n");
									i=regi1-1;
									
									}
									else
									{
										i++;
										
									}
									break;
								default:
									ginti=0;
									for(k=0;k<4;k++)
										ginti=ginti+a[i][31-k]*pow(2,k);
									switch (ginti)
									{
										case 0:
											printf("HLT\n");
											HALT();
											break;
										case 1:
										case 2:
										case 3:
										case 4:
											i++;
											for(k=0;k<16;k++)
											printf("R%d=%d ",k,(int)r[k]); 
											printf("\n");
											break;
									}

									break;		
							}//switch 27
					break;
					}//switch 22
			break;
			}//switch 17
			
			
				
		}//for all instruction
	}//else loop
	/*FILE *fptr;
	fptr=fopen("reslt.txt","w");
	if(fptr==NULL)
	{
     	 printf("Error!");
      	exit(1);
   	}
	for(i=0;i<16;i++)
   	fprintf(fptr,"regi %f\n",r[i]);
   	fclose(fptr);*/
	fclose(fp);
	return 0;
}





//functions
void ADD(float* regi3,float* regi1,float* regi2)
{
	*regi3=*regi1+*regi2;
	
}
void ADi(float *regi1, int constant)
{
	*regi1=(*regi1)+constant;
	
}
void SUB(float* regi3,float* regi1,float* regi2)
{
	*regi3=*regi2-*regi1;
	
}
void SUi(float *regi1, int constant)
{
	*regi1=constant-*regi1;
	
}
void MOV(float*regi1,float*regi2)
{
	*regi1=*regi2;
	
}
float MOi(float regi,int x)
{
	 regi=x;
	return regi;
}
void DIV(float* regi3,float* regi1,float* regi2)
{
	*regi3=(*regi2)/(*regi1);
	
}
void DIi(float *regi1, int constant)
{
	*regi1=*regi1/constant;
	printf(" %f\n",*regi1);
}
void MUL(float* regi3,float* regi1,float* regi2)
{
	*regi3=(*regi2)*(*regi1);
	
}
void MUi(float *regi1, int constant)
{
	*regi1=*regi1*constant;
}
int CMP(float* regi1,float* regi2)
{
	if((*regi2)==(*regi1))
		return 0;
	else if((*regi2)<(*regi1))
		return -1;
	else
		return 1;
}
int CMi(float* regi1,int x)
{	
	if((*regi1)==x)
		return 0;
	else if((*regi1)>x)
		return -1;
	else
		return 1;
}
void JMP(int* addr)
{
	fseek(fp,32*(*addr),SEEK_SET);
}
void JEQ(int* addr)
{
	fseek(fp,32*(*addr),SEEK_SET);
}
void JGT(int addr)
{
	fseek(fp,32*(addr),SEEK_SET);
}
void JLT(int addr)
{
	printf("%d",addr);
	fseek(fp,33*(addr-1),SEEK_SET);
}
void HALT()
{
	exit(0);
}


// test-stl-reverse1.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define MaxEditLen  15
class Force:
{
private:

}
class Tri:
{
private:
	float Point1[3],Point2[3],Point3[3];
	float *BaseVector;

public:
	Tri();
	Tri(float *Point1,float *Point2,float *Point3)
	~Tri();
	float pressure(float *Vector,float Gravity = 9.8,float Density = 1000);
	float show();
	float set(float *p1,float *p2,float *p3)
	

}

Tri::Tri(float *p1,float *p2,float *p3)
{
	Point1[0] = p1[0];
	//...
}
Tri::set(float *p1,float *p2,float *p3)
{

}
Tri::pressure(float *Vector,float Gravity,float Density)
{

}













int _tmain(int argc, _TCHAR* argv[])
{

	int sign, sign0, sign1,sign2,sign3,sign4,sign5;//kang 2004-06
	int mat; //kang 2004-06
	int no_ajacent; // the number of elements of the same material

	int i_kp,i_area;
	int s_norm1,s_norm2,s_norm3;
	float x1,y1,z1,x2,y2,z2,x3,y3,z3;
	float dist1, dist2,dist3;
	float min_side;
	int n_kp;
	int s_print1,s_print2,s_print3;
	int ii;
	int s_once;
	float **coor_kp;
	int *s_kp;

	int mat_req,no_node; //kang 2004-06
	int s_location_x,s_location_y,s_location_z, s_tmpfmt;
	int s_switch_ij,s_switch_jk,s_switch_ki;
	int s_direction_x,s_direction_y,s_direction_z;
	int s_ref_x,s_ref_y,s_ref_z;
/*   int min_i, min_j,min_k,max_i,max_j,max_k;
*/   float min_x,min_y,min_z, max_x,max_y,max_z;
	float x_new,y_new,z_new;
	float tmp_x,tmp_y,tmp_z;

	float c,c1,c2,c3;

	char text1[33],text2[33];
	char line[256],line1[256],line2[256],line3[256];
	int no_line,no_line1;
	char cc[20];
	char ccc[20],text4[33],node[5];
//	char c1[20],c2[20],c3[15];
	int sum = 0,e_sum=0;
	int number =0;
	int steps, stepe,stepm,num; 
	int     di,  dj,  dk,  id,  jd,  kd;
	int   ijk,  i,   j,   k,   i_num;
	int    nx,  ny,  nz;
	int    sx,  sy,  sz;
	float delt_x,delt_y,delt_z;
	float new_x,new_y,new_z; 
	float temperat;
	float tmp,  temp;
	float tflag;
	float distence,  distence0;
	float x,y,z,dx,dy,dz;
	float movex, movey, movez;
	float time;

	char head[20],*string3,text5[20];
	char  meidu[MaxEditLen];
	bool  normal = true;
	char *string,*string2;//tlen[8];
/*
   int *ID; // the serial number of nodes
   float **coord;  // the coordinates of the nodes
	float ***tvalue;
	int ***Mat;     //kang 2004-06
   float ***tmp_node;// the temperature of the nodes
*/
   char sign_str[10];

	FILE *fp1,*fp2,*fp3,*fp4;
	FILE * Box_Stl;
///////////////////////////////////////////////////////////
//\u8BA1\u7B97\u90E8\u5206
///////////////////////////////////////////////////////////

	num=0;
	string=".stl";
	string2="_rev";
	string3="_mov";
	printf("The stl file name (no extension name)\n");
	scanf("%s",text1);
	strcpy(text2,text1);
	strcat(text1,string);
	strcat(text2,string2);
	strcat(text2,string);

	fp4=fopen(text2,"w");
	//fprintf(fp4,"solid\n");

	min_x = min_y = min_z = 100000.0;
	max_x = max_y = max_z = -100000.0;

	n_kp=0;
	fp1= fopen(text1,"r");
	if (!fp1) {
	printf("222\n");
	}
	else
	{
		printf("223\n");

    // error
	}
   	while(!feof(fp1))
   	{
			fgets(line,256,fp1);
   		if(((int)strstr(line,"outer loop")))//cc)))
      	{
         	for(i=0;i<3;i++)
         	{
					fscanf(fp1,"%s%f%f%f",sign_str,&x,&y,&z);
               n_kp++;
         	}
      	}
      }
   	fclose(fp1);

 	coor_kp = (float**) malloc((n_kp+2)*sizeof(float));
	for(i=0;i<n_kp+2;i++)
		coor_kp[i] = (float*)malloc(6*sizeof(float));

	for(i=0;i<n_kp+2;i++)
	for(j=0;j<6;j++)
		coor_kp[i][j] = -1.0E10;

 	s_kp = (int*) malloc((n_kp+2)*sizeof(int));

  	for(i=0;i<n_kp+2;i++)
		s_kp[i] = 0;



	i_kp = 0;
	s_norm1 = 0;
	s_norm2 = 0;
	s_norm3 = 0;
	fp1= fopen(text1,"r");
   	while(!feof(fp1))
   	{
		fgets(line,256,fp1);
   		if(((int)strstr(line,"outer loop")))//cc)))
      	{
			fscanf(fp1,"%s%f%f%f",sign_str,&x1,&y1,&z1);
 			fscanf(fp1,"%s%f%f%f",sign_str,&x2,&y2,&z2);
			fscanf(fp1,"%s%f%f%f",sign_str,&x3,&y3,&z3);
			if(x1<=min_x)  min_x= x1;
 			if(x2<=min_x)  min_x= x2;
  			if(x3<=min_x)  min_x= x3;
   			if(y1<=min_y)  min_y= y1;
    		if(y2<=min_y)  min_y= y2;
   			if(y3<=min_y)  min_y= y3;
     		if(z1<=min_z)  min_z= z1;
          	if(z2<=min_z)  min_z= z2;
          	if(z3<=min_z)  min_z= z3;

			if(x1>=max_x)  max_x= x1;
 			if(x2>=max_x)  max_x= x2;
  			if(x3>=max_x)  max_x= x3;
   			if(y1>=max_y)  max_y= y1;
    		if(y2>=max_y)  max_y= y2;
   			if(y3>=max_y)  max_y= y3;
     		if(z1>=max_z)  max_z= z1;
          	if(z2>=max_z)  max_z= z2;
          	if(z3>=max_z)  max_z= z3;

      	}
      }
   	fclose(fp1);

	delt_x=max_x-min_x;
	delt_y=max_y-min_y;
	delt_z=max_z-min_z;

	max_x=max_x+0.1*delt_x;
   	max_y=max_y+0.1*delt_y;
    max_z=max_z+0.1*delt_z;

	min_x=min_x-0.1*delt_x;
   	min_y=min_y-0.1*delt_y;
    min_z=min_z-0.1*delt_z;

	i_kp=0;
	s_norm1 = 0;
	s_norm2 = 0;
	s_norm3 = 0;

	no_line=0;
 	fp1= fopen(text1,"r");
    while(!feof(fp1))
   	{
			fgets(line,256,fp1);
			no_line++;
   		if(((int)strstr(line,"facet normal"))||((int)strstr(line,"Facet Normal"))||((int)strstr(line,"FACET NORMAL")))
			break;
	}
	fclose(fp1);


  	  no_line1=0;
	  i=0;
		fp1= fopen(text1,"r");

	for(i=1;i<no_line;i++)
	{
		fgets(line,256,fp1);
 		fprintf(fp4,"%s",line);
	}

 	while(!feof(fp1))
   	{
		for(i=0;i<n_kp/3;i++)
		{
 			fscanf(fp1,"%s%s%f%f%f\n",sign_str,sign_str,&x1,&y1,&z1); // facet normal 0.0 0.0 1.0
			fprintf(fp4,"   facet normal %17.9E %17.9E %17.9E\n",x1*(-1.0),y1*(-1.0),z1*(-1.0));
			fgets(line,256,fp1); //     outer loop
 			fprintf(fp4,"%s",line);
			fgets(line1,256,fp1);//        vertex
			fgets(line2,256,fp1);//        vertex
			fgets(line3,256,fp1);//        vertex
 			fprintf(fp4,"%s",line3);
 			fprintf(fp4,"%s",line2);
 			fprintf(fp4,"%s",line1);
			fgets(line,256,fp1);//     endloop
 			fprintf(fp4,"%s",line);
			fgets(line,256,fp1);////        endfacet
 			fprintf(fp4,"%s",line);
		}
		if(i==n_kp/3)
			break;

	}


	fprintf(fp4,"endsolid\n");

	fclose(fp1);

   	fclose(fp4);

    free(s_kp);

	for(i=0;i<n_kp+2;i++)
		free(coor_kp[i]);

	printf("\n");
  	printf("******** STEP <%d>  CHANGING SUCCESS ! AT LAST !! ******** \n",num);
	
	
	return 0;
}


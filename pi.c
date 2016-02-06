#include<stdio.h>
#include<time.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
int xx;

/*   32 750->15      16 400->14           */ 

#define cpy(a,b) init(b);\
		for(xx = 0; xx < max; (b[xx]) = (a[xx++]));
			
#define init(a) for(xx = 0; xx < max; a[xx++] = 0)

#define rs(a)\
		for(xx = max-1; xx >= 0; a[xx] = a[xx-- - 1]);\
				a[0] = 0;

#define ls(a)\
		for(xx = 1; xx < max; a[xx-1] = a[xx++]);\
			a[max-1] = 0;

#define op(a)\
		for(xx = 0; xx < max; (xx==9)?printf("%d.",a[xx++]):printf("%d",a[xx++]));
		
#define fop(a,fp)\
		for(xx = 0; xx < max; (xx==9)?fprintf(fp,"%d.",a[xx++]):fprintf(fp,"%d",a[xx++]));


#define max 2100
#define max_itrn 11
/*
  Increase the value of max to compute the value of pi with higher precision.
  Ensure that the number of iterations to be performed which is defined in the macro max_itrn
  must also be set accordingly so as to get the precise value.
  Typically, max = (2 ^ max_itrn)+50
*/
void add(int*, int*, int*);		//	array declr'n  --> ad'*
void sub(int*, int*, int*);		//	array declr'n  -->  ss'*

void apg(int*, int);
int comp(int*, int*);
void pi(void);		// array declr'n --> p'*	
void basic(void);
void sqroot(int*, int*);
//void fop(int*, FILE*);
//void op(int*);

void quo_t(int*, int*, int*);		//	array declr'n	-->   q'*
void pro_tx (int*, int*, int*);		//	array declr'n	-->   pr'*
void ma(void);

//  pi ()
		int *p, *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;

//  add ()
		int *ad;
		
//  sub ()
		int *ss;
		
//	pro_tx ()
		int *pr1, **x, *pr0;
		
//  quo_t ()
		int *qo, *q1, *q2, *q3;


int main()
{
	
		ma();			
		pi();
		getch();
		return 0;
}
/*
void op(int *n)
{
	int i;
	for(i = 0; i < max; i++)
	{
		printf("%d",n[i]);
		if(i == 9)
			printf(".");
	}
	return;
}
*/
void ma()
{
	int i;
	
//	MEMORY ALLOCATION FOR "pi()"

		p = malloc(max*sizeof(int));
		p1 = malloc(max*sizeof(int));
		p2 = malloc(max*sizeof(int));
		p3 = malloc(max*sizeof(int));
		p4 = malloc(max*sizeof(int));
		p5 = malloc(max*sizeof(int));
		p6 = malloc(max*sizeof(int));
		p7 = malloc(max*sizeof(int));
		p8 = malloc(max*sizeof(int));
		
		
		
//	MEMORY ALLOCATION FOR add ()

		ad = malloc(max*sizeof(int));
		
		
//	MEMORY ALLOCATION FOR sub ()
		
		ss = malloc(max*sizeof(int));
		

//	MEMORY ALLOCATION FOR pro_tx ()
		
		pr0 = malloc(max*sizeof(int));
		pr1 = malloc(max*sizeof(int));
		
		x = malloc(11*sizeof(int*));
		for(i = 0; i< 11; i++)
		{
			x[i] = malloc((max*2+10)*sizeof(int));	
		}
		init(pr0);
		
		
//	MEMORY ALLOCATION FOR quo_t ()
		
		qo = malloc(max*sizeof(int));
		q1 = malloc(max*sizeof(int));
		q2 = malloc(max*sizeof(int));
		q3 = malloc(max*sizeof(int));
}

void pi(void)
{
/*
	trns -->
		a-p1	b-p2	c-p3	t-p4	tx-p5
		tt-p6	x-p7	y-p8

	int p1[max], p2[max], p3[max], p5[max];
	int p4[max],  p[max], p6[max], p7[max];
*/
	int i;
	int p8[max];
	double tot;
	time_t t1,t2;
	
	init(p2);
	init(p3);
	init(p5);
	init(p);
	
	p2[9] = 1;
	p3[9] = 2;
	p5[9] = 4;
	
	FILE *fp;
	FILE *f1;
	f1 = fopen("pi_digits.txt","w");
	fp = fopen("pix.txt","w");
	fprintf(fp,"\n\n\t\t\t....PI.....\n");
	fprintf(fp,"\n\nARRAY SIZE = %d\n",max);
	sqroot(p3,p1);
	quo_t(p2,p1,p4);
	cpy(p4,p2);
	init(p1);
	p1[9] = 1;
	quo_t(p1,p5,p4);
	init(p7);
	p7[9] = 1;
	printf("\n\na = ");
	op(p1);
	printf("\nb = ");
	op(p2);
	printf("\nt = ");
	op(p4);

	
	fprintf(fp,"\nINITIALIZING THE VALUES OF A,B,T");
	fprintf(fp,"\n\na = ");
	fop(p1,fp);
	fprintf(fp,"\nb = ");
	fop(p2,fp);
	fprintf(fp,"\nt = ");
	fop(p4,fp);
	
	t1 = time(NULL);

	for(i = 0; i < max_itrn; i++)
	{
			printf("\n\n ITERATION - %d",i+1);
			fprintf(fp,"\n\n\nITERATION COUNT = %d",i+1);
			cpy(p1,p8);
			add(p1,p2,p6);
			quo_t(p6,p3,p1);
			printf("\n\n\na[%d] = ",i);
			op(p1);
			pro_tx(p2,p8,p6);
			sqroot(p6,p2);
			printf("\nb[%d]  = ",i);
			op(p2);

			if(comp(p8,p1) == -1)
					sub(p1,p8,p6);
			else
				sub(p8,p1,p6);
				
			pro_tx(p6,p6,p5);

			pro_tx(p5,p7,p6);
			
			if(comp(p8,p1)==-1)
				add(p4,p6,p5);
			else
				sub(p4,p6,p5);
			cpy(p5,p4);
			printf("\nt[%d] = ",i);
			op(p4);
			pro_tx(p7,p3,p6);
			cpy(p6,p7);
			
			fprintf(fp,"\n\tA = ");
			fop(p1,fp);
			fprintf(fp,"\n\tB = ");
			fop(p2,fp);
			fprintf(fp,"\n\tT = ");
			fop(p4,fp);
	}

	printf("\n\n.....END OF LOOP");
	
	fprintf(fp,"\n\n\nEND OF ITERATIONS......");
	fprintf(fp,"\nPERFORMING FINAL CALCULATIONS WITH A, B AND T");
	printf("\n\n\n\n\na = ");
	op(p1);
	printf("\nb = ");
	op(p2);
	
	printf("\nt = ");
	op(p4);
	
	
	add(p1,p2,p6);
	pro_tx(p6,p6,p5);
	add(p3,p3,p6);
	pro_tx(p6,p4,p7);
	quo_t(p5,p7,p6);
	cpy(p6,p);
	t2 = time(NULL);
	printf("\n\npi = ");
	op(p);
	
	tot = difftime(t2,t1);
	printf("\n\nTOTAL TIME FOR COMPUTATION = %f",tot);
	
	fprintf(fp,"\n\n\nFINAL VALUE OF PI = ");
	fop(p,fp);
	fprintf(fp,"n\ncomputution time = %f",tot);
	fclose(fp);
	for(i = 0; i < max; i++)
	{
		
		if(i==10)
			fprintf(f1,".");
	if(i%10==0)
		fprintf(f1,"  ");
		
	if(i%30==0)
		fprintf(f1,"\n");
		
	fprintf(f1,"%d",p[i]);	
	}
	fclose(f1);
	getch();

}


void pro_tx(int* b, int* a, int* c)
{
/*
		tx-pr1		pr0->0.0

		int pr1[max];	
		int **x;
*/

		long i;		
		init(c);
			
		if(comp(pr0,a) == 0)
			return;	
		if(comp(pr0,b) == 0)
			return;
		
		int j, xx, p, cr;
		for(i = 0; i <= max*2+10; i++)
				x[0][i] = 0;

		for(i = 1; i <= 10; i++)
		{
				for(j = 0; j < max*2+10; j++)
						x[i][j] = 0;		
				
				add(x[i-1]+max, a, x[i]+max);
		}


		for(i = max-1; i >= 0; i--)
		{
				add(c, x[b[i]]+max-1+10-i,pr1);
				cpy(pr1,c);							
		}
		
}


void quo_t(int a[], int b[], int c[])
{
/*
		t-q1	t1-q2	tx-q3	o-qo

	int q1[max], q2[max], q3[max], qo[max];
*/

	int i, x;
	int f, ff;

	init(qo);
	init(c);
	cpy(a,q1);

	i = 9;
	init(q3);
	q3[i] = 1;
	ff = comp(q1,qo);
		
	if(comp(a,qo)==0)
		return;
		
	if(comp(b,qo)==0)
	{
		init(c);
		c[9] = 1;
		return;
	}

	while(ff > 0)
	{


		f = comp(q1,b);
		while(f >= 0)
		{
			sub(q1,b,q2);
			cpy(q2,q1);
			add(c,q3,q2);
			cpy(q2,c);
			f = comp(q1,b);
		}

		i++;
		init(q3);
		q3[i] = 1;
		if(i >= max-2)
				return;
		ls(q1);
		ff = comp(q1,qo);
	}



}

/*
void fop(int a[], FILE *fp)
{
		int i;
		for(i = 0; i < max; i++)
		{
				fprintf(fp,"%d",a[i]);
				if(i == 9)
					fprintf(fp,".");
		}
}
*/

void sqroot(int x[], int s[])
{

		int i[max], a[max], b[max], t[max], k[max], kt[max], tx[max];
		int f = 1, j;
		int c;
		int d[max], q[max];
		init(t);
		
		init(d);
		d[10] = 5;
		init(q);
		q[9] = 1;
		q[10] = 5;
		apg(i,9);
		init(s);
		init(a);
		a[9] = 1;
		
		for(c = 0; c < max_itrn+1; c++)
		{
				pro_tx(a,a,t);
				pro_tx(a,t,b);
				pro_tx(b,x,tx);
				init(t);
				int xx,cr = 0, xy;
				for(xx = max-1; xx>= 0; xx--)
				{
						xy = tx[xx]*5 + cr;
						t[xx] = xy%10;
						cr = xy/10;
				}	
				rs(t);
				
					
				cr = 0;
				init(tx);
				for(xx = max-1; xx>= 0; xx--)
				{
						xy = a[xx]*5 + cr;
						tx[xx] = xy%10;
						cr = xy/10;
				}	
				rs(tx);
				add(tx,a,b);
				sub(b,t,a);
		}
		pro_tx(a,x,s);

		s[max-1] = 0;
		s[max-2] = 0;
}


void basic(void)
{
	int  s[max], x[max], d[max], p[max], q[max], b[max];
//	int a[50] = {0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//	int b[50] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
/*                                      |                   */
	int a[max];
	init(a);
	a[9] = 2;

	sqroot(a,b);
	printf("\n\n -->");
	op(b);
	return;

	double tx;
	time_t t1, t2, t3;
	printf("\na = ");
	op(a);
	printf("\n b = ");
	op(b);	

	pro_tx(a,b,p);
	return;   


	printf("...................");
//	int b[max];
	init(b);
	b[9] = 1;
	printf("\n-->");
	init(s);
	init(d);
	printf("   -->");
	s[9] = 2;
	d[9] = 3;
	printf("   -->");
	int m, n;
/*	printf("\nA = ");
	op(a);

	printf("\nb = ") ;
	op(b);
*/	
	printf("\n  sqrt 2 --> 3 ..");
	sqroot(s,p);
	sqroot(d,q);
	printf("sq end");

	printf("\nmul wit  reciprocal");
	getch();
	t1 = time(NULL);
	quo_t(b,p,s);
	pro_x(s,q,x);
	t2 = time(NULL);
	printf("mul end\n");
	op(x);
	tx = (float)difftime(t2,t1);
	printf("\n\n time = %19f",tx);
	
	printf("\nNORM DIVN");
	getch();
	t1 = time(NULL);
	quo_t(q,p,x);
	t2 = time(NULL);
	printf("   div end\n");
	op(x);
	tx = (float)difftime(t2,t1);
	printf("\n\n TIME   %19f",tx);
	getch();
	exit(0);
/*	printf("ENTER TWO VARIABLES\n");
	scanf("%d%d",&m,&n);
	conv(a,m);
	conv(b,n);
*/

/*	printf("%d   .. %d",getdl(b)-maxl(b), getdl(b));
	getch();
	apg(a,getdl(b));
	printf("\napg...");

	ls(a);
	op(a);
	getch();
	return;
 */
	init(s);
	init(d);
	init(p);
	init(q);

//	add(a,b,s);
//	sub(a,b,d);
//	pro_x(a,b,p);
//	quo_t(a,b,q);

	printf("\n\nSUM IS   \t");
	op(s); 

	printf("\n\nDIFF IS \t");
	op(d);

	printf("\n\nPRODUCT IS\t");
	op(p);

	printf("\n\nQUOTIENT IS\t");
	op(q);

//	m = comp(a,b);
	printf("\ncomp res = %d",m);

	getch();

}





void apg(int a[], int n)
{
	int i;
	init(a);

	for(i = 0; i < max; i++)
	{
		if(n == i)
			a[i] = 1;
		else
			a[i] = 0;
	}
}


int comp(int a[], int b[])
{
	int i;

	for(i = 0; i < max; i++)
	{
		if(a[i] > b[i])
			return 1;
		if(b[i] > a[i])
			return -1;
	}
	return 0;
}


void add(int *a, int *b, int *s)
{
	int i;
	int t;


	init(ad);
	init(s);

	for(i = max-1; i >= 0; i--)
	{
		t = a[i] + b[i] + ad[i];
		if(t/10)
		{
			s[i] = t % 10;
			ad[i-1] = t / 10;
		}
		else
			s[i] = t;

	}


/*		_asm
		{
			mov esi,a
			mov esi,b
			mov ebx,s
			mov eax,max
			shl eax,2
			add esi,eax
			add edi,eax
			add ebx,eax
			mov ecx,max

			lp1:
				push ecx
				mov eax,[esi]
				add eax,[edi]
				mov ecx,10
				div ecx
				mov [ebx],ecx
				sub esi,4
				sub edi,4
				sub ebx,4
				pop ecx
				dec ecx
				mov eax,edx
				jnx lp1
		}
*/
	return;
}

void sub(int *a, int *b, int *d)
{
	int i;
	int t;

	init(ss);
	init(d);

	for(i = max-1; i >= 0; i--)
	{
		if(a[i]+ss[i] < b[i] )
		{
			ss[i-1]--;
			ss[i] += 10;
		}
		d[i] = a[i] + ss[i] - b[i];
	}

	return;
}

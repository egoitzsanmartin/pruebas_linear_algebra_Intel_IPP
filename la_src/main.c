#include <stdio.h>
#include <ipp.h>
#include <math.h>
#include <stdlib.h>

#define PI 	   3.14159265358979323846
#define TWO_PI 6.28318530717958647692

/*
// The functions providing simple output of the result
// for single precision and double precision real data.
// These functions are only for tight data:
// Stride2 = sizeof(dataType)
// Srtide1 = width*sizeof(dataType)
// Stride0 = length*sizeof(dataType) - for vector array
// Stride0 = width*height*sizeof(dataType) - for matrix array
*/
#define genPRINT_m(TYPE) \
void printf_m_Ipp##TYPE(const char* msg, Ipp##TYPE* buf, int width, int height, IppStatus st ) \
{ 	int i, j; \
	if( st < ippStsNoErr ) { \
		printf( "-- error %d, %s\n", st, ippGetStatusString( st )); \
	} else { \
		printf("%s \n", msg ); \
		for( j=0; j < height; j++) { \
			for( i=0; i < width; i++) { \
				printf("%f ", buf[j*width+i]); } \
				printf("\n"); } } \
}
#define genPRINT_ma(TYPE) \
void printf_ma_Ipp##TYPE(const char* msg, Ipp##TYPE *buf, int width, int height, int count, IppStatus st ) \
{ 	int i, j, k; \
	if( st < ippStsNoErr ) { \
		printf( "-- error %d, %s\n", st, ippGetStatusString( st )); \
	} else { \
		printf("%s \n", msg ); \
		for( j=0; j < height; j++) { \
			for( k=0; k < count; k++) { \
				for( i=0; i < width; i++){ \
					printf("%f ", buf[j*width+i+k*width*height]); \
				} printf(" "); } printf("\n");}} \
}

#define genPRINT_m_L(TYPE) \
void printf_ma_Ipp##TYPE##_L(const char* msg, Ipp##TYPE** buf, int width, int height, int count, IppStatus st )\
{	 int i, j, k; \
	Ipp##TYPE *dst; \
	if( st < ippStsNoErr ) { \
		printf( "-- error %d, %s\n", st, ippGetStatusString( st )); \
	} else { \
		printf("%s \n", msg ); \
		for( j=0; j < height; j++) { \
			for( k=0; k < count; k++) { \
				dst = (Ipp##TYPE*)buf[k]; \
				for( i=0; i < width; i++) { \
					printf("%f ", dst[j*width+i]); } \
					printf(" "); } printf("\n"); } } \
}

#define genPRINT_m_P(TYPE) \
void printf_m_Ipp##TYPE##_P(const char* msg, Ipp##TYPE** buf, int width, int height, IppStatus st ) \
{ 	int i, j; \
	if( st < ippStsNoErr ) { \
		printf( "-- error %d, %s\n", st, ippGetStatusString( st )); \
	} else { \
		printf("%s \n", msg ); \
		for( j=0; j < height; j++) { \
			for( i=0; i < width; i++) { \
				printf("%f ", *buf[j*width+i]); } \
				printf("\n"); } } \
}

#define genPRINT_va(TYPE) \
void printf_va_Ipp##TYPE(const char* msg, Ipp##TYPE* buf, int length, int count, IppStatus st ) \
{	 int i, j; \
	if( st < ippStsNoErr ) { \
		printf( "-- error %d, %s\n", st, ippGetStatusString( st )); \
	} else { \
		printf("%s \n", msg ); \
		for( j=0; j < count; j++) { \
			for( i=0; i < length; i++) { \
				printf("%f ", buf[j*length+i]); } \
				printf("\n"); } } \
}

void printf_v_int(const char* msg, int* buf, int length) \
{ 	int i; \
	printf("%s \n", msg ); \
	for( i=0; i < length; i++) \
	printf("%d ", buf[i]); \
	printf("\n"); \
}
genPRINT_va( 32f );
genPRINT_m( 32f );
genPRINT_ma( 32f );
genPRINT_m_P( 32f );
genPRINT_m_L( 32f );
genPRINT_va( 64f );
genPRINT_m( 64f );
genPRINT_ma( 64f );
genPRINT_m_P( 64f );
genPRINT_m_L( 64f );

double Mod(double x, double y)
{

    if (0. == y)
        return x;

    double m= x - y * floor(x/y);


    if (y > 0)
    {
        if (m>=y)
            return 0;

        if (m<0 )
        {
            if (y+m == y)
                return 0;
            else
                return y+m;
        }
    }
    else 
    {
        if (m<=y)
            return 0;

        if (m>0 )
        {
            if (y+m == y)
                return 0;
            else
                return y+m;
        }
    }

    return m;
}

double wrapToPi(double fAng)
{
    return Mod(fAng + PI, TWO_PI) - PI;
}

void printJacobian(float q1, float q2, float q3, float q4, float q5, float q6){
	Ipp32f jacobian[6*6] = {- 50*sin(q1) - sin(q1)*(425*sin(q2) - cos(q2)*(cos(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - sin(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)) + sin(q2)*(sin(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) + cos(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425))) - cos(q1)*((5647*cos(q4)*cos(q6))/100 + (7683*sin(q4)*sin(q5))/25 - (5647*cos(q5)*sin(q4)*sin(q6))/100 + 50), cos(q1)*(425*cos(q2) + cos(q2)*(sin(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) + cos(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)) + sin(q2)*(cos(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - sin(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425))), cos(q1)*cos(q2)*(sin(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) + cos(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)) + cos(q1)*sin(q2)*(cos(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - sin(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)),   sin(q1)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - cos(q2 + q3)*cos(q1)*((5647*cos(q4)*cos(q6))/100 + (7683*sin(q4)*sin(q5))/25 - (5647*cos(q5)*sin(q4)*sin(q6))/100), - ((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100)*(sin(q1)*sin(q4) - cos(q1)*cos(q2)*cos(q3)*cos(q4) + cos(q1)*cos(q4)*sin(q2)*sin(q3)) - sin(q2 + q3)*cos(q1)*((7683*sin(q5))/25 - (5647*cos(q5)*sin(q6))/100), (5647*cos(q6)*(cos(q5)*sin(q1)*sin(q4) + cos(q1)*cos(q2)*sin(q3)*sin(q5) + cos(q1)*cos(q3)*sin(q2)*sin(q5) - cos(q1)*cos(q2)*cos(q3)*cos(q4)*cos(q5) + cos(q1)*cos(q4)*cos(q5)*sin(q2)*sin(q3)))/100 + (5647*sin(q6)*(cos(q4)*sin(q1) + cos(q1)*cos(q2)*cos(q3)*sin(q4) - cos(q1)*sin(q2)*sin(q3)*sin(q4)))/100,
			  50*cos(q1) + cos(q1)*(425*sin(q2) - cos(q2)*(cos(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - sin(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)) + sin(q2)*(sin(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) + cos(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425))) - sin(q1)*((5647*cos(q4)*cos(q6))/100 + (7683*sin(q4)*sin(q5))/25 - (5647*cos(q5)*sin(q4)*sin(q6))/100 + 50), sin(q1)*(425*cos(q2) + cos(q2)*(sin(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) + cos(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)) + sin(q2)*(cos(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - sin(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425))), cos(q2)*sin(q1)*(sin(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) + cos(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)) + sin(q1)*sin(q2)*(cos(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - sin(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)), - cos(q1)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - cos(q2 + q3)*sin(q1)*((5647*cos(q4)*cos(q6))/100 + (7683*sin(q4)*sin(q5))/25 - (5647*cos(q5)*sin(q4)*sin(q6))/100),   ((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100)*(cos(q1)*sin(q4) + cos(q2)*cos(q3)*cos(q4)*sin(q1) - cos(q4)*sin(q1)*sin(q2)*sin(q3)) - sin(q2 + q3)*sin(q1)*((7683*sin(q5))/25 - (5647*cos(q5)*sin(q6))/100), (5647*cos(q6)*(cos(q2)*sin(q1)*sin(q3)*sin(q5) - cos(q1)*cos(q5)*sin(q4) + cos(q3)*sin(q1)*sin(q2)*sin(q5) - cos(q2)*cos(q3)*cos(q4)*cos(q5)*sin(q1) + cos(q4)*cos(q5)*sin(q1)*sin(q2)*sin(q3)))/100 - (5647*sin(q6)*(cos(q1)*cos(q4) - cos(q2)*cos(q3)*sin(q1)*sin(q4) + sin(q1)*sin(q2)*sin(q3)*sin(q4)))/100,
			                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      0,           cos(q2)*(cos(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - sin(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)) - 425*sin(q2) - sin(q2)*(sin(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) + cos(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)),                 cos(q2)*(cos(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) - sin(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)) - sin(q2)*(sin(q3)*((5647*cos(q6)*sin(q4))/100 - (7683*cos(q4)*sin(q5))/25 + (5647*cos(q4)*cos(q5)*sin(q6))/100) + cos(q3)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100 + 425)),                                                                                                                   sin(q2 + q3)*((5647*cos(q4)*cos(q6))/100 + (7683*sin(q4)*sin(q5))/25 - (5647*cos(q5)*sin(q4)*sin(q6))/100),                                                                          - cos(q2 + q3)*((7683*sin(q5))/25 - (5647*cos(q5)*sin(q6))/100) - sin(q2 + q3)*cos(q4)*((7683*cos(q5))/25 + (5647*sin(q5)*sin(q6))/100),                                                                                                                            (5647*cos(q6)*(cos(q2)*cos(q3)*sin(q5) - sin(q2)*sin(q3)*sin(q5) + cos(q2)*cos(q4)*cos(q5)*sin(q3) + cos(q3)*cos(q4)*cos(q5)*sin(q2)))/100 - (5647*sin(q2 + q3)*sin(q4)*sin(q6))/100,
			                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      0,                                                                                                                                                                                                                                                                                                                                                                                    -sin(q1),                                                                                                                                                                                                                                                                                                                                                                            -sin(q1),                                                                                                                                                                                                         sin(q2 + q3)*cos(q1),                                                                                                                              cos(q1)*sin(q2)*sin(q3)*sin(q4) - cos(q1)*cos(q2)*cos(q3)*sin(q4) - cos(q4)*sin(q1),                                                                                                                                 cos(q1)*cos(q2)*cos(q5)*sin(q3) - sin(q1)*sin(q4)*sin(q5) + cos(q1)*cos(q3)*cos(q5)*sin(q2) + cos(q1)*cos(q2)*cos(q3)*cos(q4)*sin(q5) - cos(q1)*cos(q4)*sin(q2)*sin(q3)*sin(q5),
			                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      0,                                                                                                                                                                                                                                                                                                                                                                                     cos(q1),                                                                                                                                                                                                                                                                                                                                                                             cos(q1),                                                                                                                                                                                                         sin(q2 + q3)*sin(q1),                                                                                                                              cos(q1)*cos(q4) - cos(q2)*cos(q3)*sin(q1)*sin(q4) + sin(q1)*sin(q2)*sin(q3)*sin(q4),                                                                                                                                 cos(q1)*sin(q4)*sin(q5) + cos(q2)*cos(q5)*sin(q1)*sin(q3) + cos(q3)*cos(q5)*sin(q1)*sin(q2) + cos(q2)*cos(q3)*cos(q4)*sin(q1)*sin(q5) - cos(q4)*sin(q1)*sin(q2)*sin(q3)*sin(q5),
			                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      1,                                                                                                                                                                                                                                                                                                                                                                                           0,                                                                                                                                                                                                                                                                                                                                                                                   0,                                                                                                                                                                                                                 cos(q2 + q3),                                                                                                                                                                                             sin(q2 + q3)*sin(q4),                                                                                                                                                                                           cos(q2)*cos(q3)*cos(q5) - cos(q5)*sin(q2)*sin(q3) - cos(q2)*cos(q4)*sin(q3)*sin(q5) - cos(q3)*cos(q4)*sin(q2)*sin(q5)};
	int J_Width = 6;
	int J_Height = 6;
	
	printf_m_Ipp32f("Jacobian: ", jacobian, J_Width, J_Height, ippStsNoErr);
}

/*
	ejemplo^2 = ejemplo*ejemplo ---> (\w{1,100})\^2
*/

void forwardKin(float* Q, Ipp32f* A0_flange){
	
	float q1 = Q[0];
	float q2 = Q[1];
	float q3 = Q[2];
	float q4 = Q[3];
	float q5 = Q[4];
	float q6 = Q[5];
	
	Ipp32f DH_MA[4*4*7] = {cos(q1), 0, -sin(q1), 50*cos(q1),
						   sin(q1), 0, cos(q1) , 50*sin(q1),
						   0,      -1, 0,        0,
						   0,       0, 0,        1,
						   
						   cos(q2-PI/2), -sin(q2-PI/2), 0, 425*cos(q2-PI/2),
						   sin(q2-PI/2),  cos(q2-PI/2), 0, 425*sin(q2-PI/2),
						   0,             0,            1, 50,
						   0,             0,            0, 1,
	
						   cos(q3+PI/2), 0, sin(q3+PI/2),  0,
						   sin(q3+PI/2), 0, -cos(q3+PI/2), 0,
						   0,            1, 0,             0,
						   0,            0, 0,             1,

						   cos(q4), 0, -sin(q4), 0,
						   sin(q4), 0, cos(q4),  0,
						   0,      -1, 0,        425,
						   0,       0, 0,        1,
		
						   cos(q5), 0, sin(q5),  0,
						   sin(q5), 0, -cos(q5), 0,
						   0,       1, 0,        0,
						   0,       0, 0,        1,
						   
						   cos(q6), -sin(q6), 0, 0,
						   sin(q6), cos(q6),  0, 0,
						   0,       0,        1, 0,
						   0,       0,        0, 1,
	
						   1, 0, 0, 0,
						   0, 1, 0, 0,
						   0, 0, 1, 100,
						   0, 0, 0, 1};


	
	int DH_Width  = 4;
	int DH_Height = 4;
	int DH_size = (DH_Width * DH_Height);
	int DH_stride2 = sizeof(Ipp32f)*1;
	int DH_stride1 = sizeof(Ipp32f)*4;

	Ipp32f HT_MA[4*4*7];
	
	int HT_Width  = 4;
	int HT_Height = 4;
	int HT_size = (HT_Height * HT_Width);
	int count = 7;
	int HT_stride2 = sizeof(Ipp32f)*1;
	int HT_stride1 = sizeof(Ipp32f)*4;
	
	Ipp32f tmp[4*4] = {1, 0, 0, 0,
					   0, 1, 0, 0,
					   0, 0, 1, 0,
					   0, 0, 0, 1};
	
	Ipp32f result[4*4];

	int i, j;
	for (i = 0; i < count; i++ )
	{
		Ipp32f DH_M[4*4];
		for(j = 0; j < DH_size; j++){
			DH_M[j] = DH_MA[j + i*DH_size];
		}
		
		ippmMul_mm_32f((const Ipp32f*)tmp, HT_stride1, HT_stride2, HT_Width, HT_Height,
					   (const Ipp32f*)DH_M, DH_stride1, DH_stride2, DH_Width, DH_Height, 
					   result, HT_stride1, HT_stride2);
		
		for(j = 0; j < HT_size; j++){
			HT_MA[j + i*HT_size] = result[j];
			tmp[j] = result[j];
		}
	}
	
	for(j = 0; j < HT_size; j++){
		A0_flange[j] = result[j];
	}
	
	
}

void geoInvKin(Ipp32f* pos, Ipp32f* rot, Ipp32f* Q){	
	
	
	int pos_stride2 = sizeof(Ipp32f)*1;
	
	int rot_Width = 3;
	int rot_Height = 3;
	int rot_stride2 = sizeof(Ipp32f)*1;
	int rot_stride1 = sizeof(Ipp32f)*3;
	
	
	Ipp32f zvec[3*1] = {0,
						0,
						1};
	
	int zvec_len = 3;
	int zvec_stride2 = sizeof(Ipp32f)*1;
	
	Ipp32f zrot[3*1];
	int zrot_stride2 = sizeof(Ipp32f)*1;
	
	ippmMul_mv_32f((const Ipp32f*) rot, rot_stride1, rot_stride2, rot_Width, rot_Height,
			   	   (const Ipp32f*) zvec, zvec_stride2, zvec_len,
			   	   zrot, zrot_stride2);
	Ipp32f W_len[3*1];
	int W_len_stride2 = sizeof(Ipp32f)*1;
	int W_len_len = 3;
	
	ippmMul_vc_32f((const Ipp32f*) zrot, zrot_stride2,
				   (Ipp32f) 100,
				   W_len, W_len_stride2, W_len_len);
	
	Ipp32f WC[3*1];
	int WC_stride2 = sizeof(Ipp32f)*1;
	int WC_len = 3;
	
	ippmSub_vv_32f((const Ipp32f*) pos, pos_stride2, (const Ipp32f*) W_len, W_len_stride2, WC, WC_stride2, WC_len);
	
	Ipp32f Xc = WC[0];
	Ipp32f Yc = WC[1];
	Ipp32f Zc = WC[2];
	
	Ipp32f Toc[4*4] = {rot[0], rot[1], rot[2], Xc,
					   rot[3], rot[4], rot[5], Yc,
					   rot[6], rot[7], rot[8], Zc,
					   0,	   0,      0,      1};
	int Toc_stride2 = sizeof(Ipp32f)*1;
	int Toc_stride1 = sizeof(Ipp32f)*4;
	int Toc_widthHeight = 4;
			
	Ipp32f r_q = sqrt(pow(Xc, 2)+ pow(Yc, 2));
	Ipp32f alfaq = atan2(Yc, Xc);
	Ipp32f betaq = atan2(50, sqrt(pow(r_q, 2) - pow(50, 2)));
	
	Ipp32f q1[2], q2[4], q3[4], q4[8], q5[8], q6[8];
	short int q23_ok[4];
	
	q1[0] = wrapToPi(alfaq - betaq);
	
	Ipp32f alfaq1 = atan2(Yc, Xc);
	q1[1] = wrapToPi(alfaq1 + atan2(-50, -sqrt(pow(r_q, 2) - pow(50, 2 ))));
	
	int A01_stride2 = sizeof(Ipp32f)*1;
	int A01_stride1 = sizeof(Ipp32f)*4;
	Ipp32f pBuffer[4*4+4];
	
	Ipp32f c3[2];
	
	int i, j, k;
	
	for(i = 0; i < 2; i++){
		Ipp32f A01[4*4] = { cos(q1[i]),  0, -sin(q1[i]), 50*cos(q1[i]),
							sin(q1[i]),  0, cos(q1[i]),  50*sin(q1[i]),
							0, 		 	-1, 0,           0,
							0,  		 0, 0,           1 };
		Ipp32f T01qi[4*4];
		int T01qi_stride2 = sizeof(Ipp32f)*1;
		int T01qi_stride1 = sizeof(Ipp32f)*4;
		int T01qi_widthHeight = 4;
		
		ippmInvert_m_32f((const Ipp32f*) A01, A01_stride1, A01_stride2, pBuffer,
						 T01qi, T01qi_stride1, T01qi_stride2, T01qi_widthHeight);
		
		Ipp32f T01ci[4*4];
		int T01ci_stride2 = sizeof(Ipp32f)*1;
		int T01ci_stride1 = sizeof(Ipp32f)*4;
		
		ippmMul_mm_32f((const Ipp32f*)T01qi, T01qi_stride1, T01qi_stride2, T01qi_widthHeight, T01qi_widthHeight,
					   (const Ipp32f*)Toc, Toc_stride1, Toc_stride2, Toc_widthHeight, Toc_widthHeight, 
					   T01ci, T01ci_stride1, T01ci_stride2);
		
		c3[i] = ((pow(T01ci[3],2) + pow(T01ci[7], 2)) - 2*pow(425,2)) / (2*pow(425,2));
		if(fabs(c3[i]) > 1){
			q23_ok[i*2] = 0;
			q23_ok[i*2+1] = 0;
		}else{
			q23_ok[i*2] = 1;
			q23_ok[i*2 + 1] = 1;
			
			q3[i*2] = atan2(sqrt(1-pow(c3[i], 2)), c3[i]);
			q3[i*2 + 1] = -q3[i*2];
			
			q2[i*2] = wrapToPi(PI/2+atan2(T01ci[7], T01ci[3])-atan2(425 * sin(q3[i*2]), 425+425*cos(q3[i*2])));
			q2[i*2 + 1] =  wrapToPi(PI/2+atan2(T01ci[7], T01ci[3])-atan2(425 * sin(q3[i*2 + 1]), 425+425*cos(q3[i*2 + 1])));
		}
		
		for(j = 0; j < 2; j++){
			if(q23_ok[i*2+j] == 1){
				Ipp32f A03[4*4] = { cos(q1[i])*cos(q2[i*2+j] - PI/2)*cos(q3[i*2+j] + PI/2) - cos(q1[i])*sin(q2[i*2+j] - PI/2)*sin(q3[i*2+j] + PI/2), -sin(q1[i]), cos(q1[i])*cos(q2[i*2+j] - PI/2)*sin(q3[i*2+j] + PI/2) + cos(q1[i])*cos(q3[i*2+j] + PI/2)*sin(q2[i*2+j] - PI/2), 50*cos(q1[i]) - 50*sin(q1[i]) + 425*cos(q1[i])*cos(q2[i*2+j] - PI/2),
									cos(q2[i*2+j] - PI/2)*cos(q3[i*2+j] + PI/2)*sin(q1[i]) - sin(q1[i])*sin(q2[i*2+j] - PI/2)*sin(q3[i*2+j] + PI/2),  cos(q1[i]), cos(q2[i*2+j] - PI/2)*sin(q1[i])*sin(q3[i*2+j] + PI/2) + cos(q3[i*2+j] + PI/2)*sin(q1[i])*sin(q2[i*2+j] - PI/2), 50*cos(q1[i]) + 50*sin(q1[i]) + 425*cos(q2[i*2+j] - PI/2)*sin(q1[i]),
									-cos(q2[i*2+j] - PI/2)*sin(q3[i*2+j] + PI/2) - cos(q3[i*2+j] + PI/2)*sin(q2[i*2+j] - PI/2),        0,                 cos(q2[i*2+j] - PI/2)*cos(q3[i*2+j] + PI/2) - sin(q2[i*2+j] - PI/2)*sin(q3[i*2+j] + PI/2),                                  -425*sin(q2[i*2+j] - PI/2),
									0,        0,                                                                             0,                                                    1 };
	
				Ipp32f R03_trans[3*3] =  { A03[0], A03[4], A03[8],
										   A03[1], A03[5], A03[9],
										   A03[2], A03[6], A03[10] };
				int R03_trans_Width = 3;
				int R03_trans_Height = 3;
				int R03_trans_stride2 = sizeof(Ipp32f)*1;
				int R03_trans_stride1 = sizeof(Ipp32f)*3;
				
				Ipp32f W_orient[3*3];
				int W_orient_stride2 = sizeof(Ipp32f)*1;
				int W_orient_stride1 = sizeof(Ipp32f)*3;
				
				ippmMul_mm_32f((const Ipp32f*)R03_trans, R03_trans_stride1, R03_trans_stride2, R03_trans_Width, R03_trans_Height,
							   (const Ipp32f*)rot, rot_stride1, rot_stride2, rot_Width, rot_Height, 
							   W_orient, W_orient_stride1, W_orient_stride2);
				
				q5[i*4+j*2] = atan2(sqrt(1-pow(W_orient[8], 2)), W_orient[8]);
				q5[i*4+j*2+1] = atan2(-sqrt(1-pow(W_orient[8], 2)), W_orient[8]);
				
				for(k = 0; k < 2; k++){
					if (W_orient[8] == 1){
						q4[i*4+j*2+k] = 0;
						q6[i*4+j*2+k] = atan2(W_orient[4], W_orient[0]);
					}else
					{
						if(k == 0){
							q4[i*4+j*2+k] = atan2(W_orient[5], W_orient[2]);
							q6[i*4+j*2+k] = atan2(W_orient[7], -W_orient[6]);
						}else{
							q4[i*4+j*2+k] = atan2(W_orient[5], W_orient[2]) - PI;
							q6[i*4+j*2+k] = atan2(W_orient[7], -W_orient[6]) - PI;
						}
					}
					Q[(i*4+j*2+k)*6] = wrapToPi(q1[i]);
					Q[(i*4+j*2+k)*6 + 1] = wrapToPi(q2[i*2+j]);
					Q[(i*4+j*2+k)*6 + 2] = wrapToPi(q3[i*2+j]);
					Q[(i*4+j*2+k)*6 + 3] = wrapToPi(q4[i*4+j*2+k]);
					Q[(i*4+j*2+k)*6 + 4] = wrapToPi(q5[i*4+j*2+k]);
					Q[(i*4+j*2+k)*6 + 5] = wrapToPi(q6[i*4+j*2+k]);
				}
			}else{
				Q[(i*4+j*2)*6] = 1312;
				Q[(i*4+j*2)*6 + 1] = 1312;
				Q[(i*4+j*2)*6 + 2] = 1312;
				Q[(i*4+j*2)*6 + 3] = 1312;
				Q[(i*4+j*2)*6 + 4] = 1312;
				Q[(i*4+j*2)*6 + 5] = 1312;
				
				Q[(i*4+j*2+1)*6] = 1312;
				Q[(i*4+j*2+1)*6 + 1] = 1312;
				Q[(i*4+j*2+1)*6 + 2] = 1312;
				Q[(i*4+j*2+1)*6 + 3] = 1312;
				Q[(i*4+j*2+1)*6 + 4] = 1312;
				Q[(i*4+j*2+1)*6 + 5] = 1312;
			}
		}
	}
}

int main(){
	int countError = 0;
	int QStride0 = sizeof(Ipp32f);
	int i, j;
	
	for(i = 0; i < 100000; i++){
		float Q[6];
		for(j = 0; j < 6; j++){
			Q[j] = (((float) rand() / (float)(RAND_MAX)) - 0.5) * TWO_PI*0.99;
		}
		
		Ipp32f M[4*4];
		Ipp32f Q_res[8*6];
		int Q_resStride2 = sizeof(Ipp32f);
		int Q_resStride0 = sizeof(Ipp32f)*6;
		
		forwardKin(Q, M);
		
		/*printf_m_Ipp32f("Forward Kin: ", M, 4, 4, ippStsNoErr);*/
		
		Ipp32f pos[3*1] = {M[3],
						   M[7],
						   M[11]};
		
		Ipp32f rot[3*3] = {M[0], M[1], M[2],
						   M[4], M[5], M[6],
						   M[8], M[9], M[10]};
		
		geoInvKin(pos, rot, Q_res);
		
		Ipp32f error[8*6];
		int len = 6;
		int count  = 8;
		int errorStride2 = sizeof(Ipp32f);
		int errorStride0 = sizeof(Ipp32f)*6;
		
		ippmSub_vav_32f((const Ipp32f*) Q_res, Q_resStride0, Q_resStride2,
						(const Ipp32f*) Q, QStride0,
						error, errorStride0, errorStride2, len, count);
		
		Ipp32f result[8];
		
		int noError = 0;
		for (j = 0; j < 8; j++){
			result[j] = fabs(error[j*6]) + fabs(error[j*6 + 1]) + fabs(error[j*6 + 2]) + fabs(error[j*6 + 3]) + fabs(error[j*6 + 4]) + fabs(error[j*6 + 5]);
			if(result[j] < 0.1){
				noError = 1;
			}
		}
		if(noError == 0){
			countError++;
			printf("ERROR\n\n");
			
			printf("Input: \n");
			printf("%f %f %f %f %f %f", Q[0], Q[1], Q[2], Q[3], Q[4], Q[5]);
			printf("\n\n");
			
			printf("Output: \n");
			for (j = 0; j < 8; j++){
				printf("%f %f %f %f %f %f", Q_res[j*6],  Q_res[j*6 + 1],  Q_res[j*6 + 2], Q_res[j*6 + 3], Q_res[j*6 + 4],  Q_res[j*6 + 5]);
				printf("\n");
			}
			printf("\n\n");
		}
	}
	
	printf("Error count: %d", countError);
	return 0;
}

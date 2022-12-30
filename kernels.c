/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {
        "TEAM",    /* Team Name */

        "e252130",      /* First student ID */
        "MURAT BOLU",       /* First student name */

        "e244906",             /* Second student ID */
        "UMUT YILMAZ",           /* Second student name */

        "",             /* Third student ID */
        ""            /* Third student Name */
};


/********************
 * CONVOLUTION KERNEL
 ********************/

/***************************************************************
 * Your different versions of the convolution functions  go here
 ***************************************************************/

/*
 * naive_conv - The naive baseline version of convolution
 */
char naive_conv_descr[] = "naive_conv: Naive baseline implementation";
void naive_conv(int dim, pixel *src, pixel *ker, unsigned *dst) {
    int i,j,k,l;

    for(i = 0; i < dim-8+1; i++)
        for(j = 0; j < dim-8+1; j++) {
            dst[RIDX(i, j, dim)] = 0;
            for(k = 0; k < 8; k++)
                for(l = 0; l < 8; l++) {
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
                }

        }
}

/*
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Convolution: Current working version";
void convolution(int dim, pixel *src, pixel *ker, unsigned *dst)
{

    naive_conv(dim,src,ker,dst);

}

/*********************************************************************
 * register_conv_functions - Register all of your different versions
 *     of the convolution functions  with the driver by calling the
 *     add_conv_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_conv_functions() {
    add_conv_function(&naive_conv, naive_conv_descr);
    add_conv_function(&convolution, convolution_descr);
    /* ... Register additional test functions here */
}




/************************
 * AVERAGE POOLING KERNEL
 ************************/

/*********************************************************
 * Your different versions of the average pooling  go here
 *********************************************************/

/*
 * naive_average_pooling - The naive baseline version of average pooling
 */
char naive_average_pooling_descr[] = "Naive Average Pooling: Naive baseline implementation";
void naive_average_pooling(int dim, pixel *src, pixel *dst) {
    int i,j,k,l;

    for(i = 0; i < dim/2; i++)
        for(j = 0; j < dim/2; j++) {
            dst[RIDX(i, j, dim/2)].red = 0;
            dst[RIDX(i, j, dim/2)].green = 0;
            dst[RIDX(i, j, dim/2)].blue = 0;
            for(k = 0; k < 2; k++) {
                for (l = 0; l < 2; l++) {
                    dst[RIDX(i, j, dim/2)].red += src[RIDX(i*2 + k, j*2 + l, dim)].red;
                    dst[RIDX(i, j, dim/2)].green += src[RIDX(i*2 + k, j*2 + l, dim)].green;
                    dst[RIDX(i, j, dim/2)].blue += src[RIDX(i*2 + k, j*2 + l, dim)].blue;
                }
            }
            dst[RIDX(i, j, dim/2)].red /= 4;
            dst[RIDX(i, j, dim/2)].green /= 4;
            dst[RIDX(i, j, dim/2)].blue /= 4;
        }
}


/*
 * average_pooling - Your current working version of average_pooling
 * IMPORTANT: This is the version you will be graded on
 */
char average_pooling_descr[] = "Average Pooling: Current working version";
void average_pooling(int dim, pixel *src, pixel *dst)
{

    int i,j,k,i2,j2, dim_2, index;
    pixel temp = {0,0,0};
    pixel temp_src1, temp_src2;
    dim_2 = dim/2;
    for(i = 0; i < dim_2; i++){
        i2 = i + i;
        for(j = 0; j < dim_2; j++) {
            j2 = j + j;
            temp.red = 0;
            temp.green = 0;
            temp.blue = 0;
            for(k = 0; k < 2; k++) {
                index = RIDX(i2 + k, j2, dim);
                temp_src1 = src[index];
                temp_src2 = src[index+1];
                temp.red += (temp_src1.red + temp_src2.red);
                temp.green += (temp_src1.green + temp_src2.green);
                temp.blue += (temp_src1.blue + temp_src2.blue);
            }
            temp.red /= 4;
            temp.green /= 4;
            temp.blue /= 4;
            dst[RIDX(i, j, dim_2)] = temp;
        }
    }
}
char another_average_pooling_descr[] = "Average Pooling: testing";
void another_average_pooling(int dim, pixel *src, pixel *dst)
{

    int i,j,k,i2 = 0,j2 = 0, dim_2, index;
    unsigned short temp_red = 0, temp_green = 0, temp_blue = 0;
    dim_2 = dim/2;
    for(i = 0; i < dim_2; i++){
        for(j = 0; j < dim_2; j++) {
            j2 = j + j;
            temp_red = 0;
            temp_green = 0;
            temp_blue = 0;
            for(k = 0; k < 2; k++) {
                index = RIDX(i2 + k, j2, dim);
                temp_red += src[index].red + src[index+1].red;
                temp_green += src[index].green + src[index+1].green;
                temp_blue += src[index].blue + src[index+1].blue;
                
            }
            index = RIDX(i, j, dim_2);
            dst[index].red = temp_red/4;
            dst[index].green = temp_green/4;
            dst[index].blue = temp_blue/4;
        }
        i2 += 2;
    }
}
char seq_average_pooling_descr[] = "Average Pooling: reducing sequential dependency";
void seq_average_pooling(int dim, pixel *src, pixel *dst)
{

    int i,j,k,i2 = 0,j2 = 0, dim_2, index;
    unsigned short temp_red = 0, temp_green = 0, temp_blue = 0, temp_red2 = 0, temp_green2 = 0, temp_blue2 = 0;
    dim_2 = dim/2;
    for(i = 0; i < dim_2; i++){
        for(j = 0; j < dim_2; j++) {
            j2 = j + j;
            temp_red = 0, temp_green = 0, temp_blue = 0, temp_red2 = 0, temp_green2 = 0, temp_blue2 = 0;

            for(k = 0; k < 2; k++) {
                index = RIDX(i2 + k, j2, dim);
                
                temp_red += src[index].red;
                temp_green += src[index].green;
                temp_blue += src[index].blue;

                temp_red2 += src[index+1].red;
                temp_green2 += src[index+1].green;
                temp_blue2 += src[index+1].blue;
            }
            index = RIDX(i, j, dim_2);
            dst[index].red = (temp_red + temp_red2)/4;
            dst[index].green = (temp_green + temp_green2)/4;
            dst[index].blue = (temp_blue + temp_blue2)/4;
        }
        i2 += 2;
    }
}



/******************************************************************************
 * register_average_pooling_functions - Register all of your different versions
 *     of the average pooling  with the driver by calling the
 *     add_average_pooling_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 ******************************************************************************/

void register_average_pooling_functions() {
    add_average_pooling_function(&naive_average_pooling, naive_average_pooling_descr);
    add_average_pooling_function(&average_pooling, average_pooling_descr);
    add_average_pooling_function(&another_average_pooling, another_average_pooling_descr);
    add_average_pooling_function(&seq_average_pooling, seq_average_pooling_descr);
    /* ... Register additional test functions here */
}


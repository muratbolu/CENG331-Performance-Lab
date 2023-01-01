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

    int i,j,k,sum,sum_red,sum_green,sum_blue,src_index=0;

    for(i = 0; i < dim-8+1; i++) {
        for(j = 0; j < dim-8+1; j++) {
            sum_red = 0;
            sum_green = 0;
            sum_blue = 0;
            for(k = 0; k < 64; k+=8) {
                sum_red   += src[src_index].red * ker[k].red;
                sum_green += src[src_index].green * ker[k].green;
                sum_blue  += src[src_index].blue * ker[k].blue;

                sum_red   += src[src_index+1].red * ker[k+1].red;
                sum_green += src[src_index+1].green * ker[k+1].green;
                sum_blue  += src[src_index+1].blue * ker[k+1].blue;

                sum_red   += src[src_index+2].red * ker[k+2].red;
                sum_green += src[src_index+2].green * ker[k+2].green;
                sum_blue  += src[src_index+2].blue * ker[k+2].blue;

                sum_red   += src[src_index+3].red * ker[k+3].red;
                sum_green += src[src_index+3].green * ker[k+3].green;
                sum_blue  += src[src_index+3].blue * ker[k+3].blue;

                sum_red   += src[src_index+4].red * ker[k+4].red;
                sum_green += src[src_index+4].green * ker[k+4].green;
                sum_blue  += src[src_index+4].blue * ker[k+4].blue;

                sum_red   += src[src_index+5].red * ker[k+5].red;
                sum_green += src[src_index+5].green * ker[k+5].green;
                sum_blue  += src[src_index+5].blue * ker[k+5].blue;

                sum_red   += src[src_index+6].red * ker[k+6].red;
                sum_green += src[src_index+6].green * ker[k+6].green;
                sum_blue  += src[src_index+6].blue * ker[k+6].blue;

                sum_red   += src[src_index+7].red * ker[k+7].red;
                sum_green += src[src_index+7].green * ker[k+7].green;
                sum_blue  += src[src_index+7].blue * ker[k+7].blue;

                src_index += dim;
            }
            sum = sum_red + sum_green + sum_blue;
            src_index -= (dim << 3);
            dst[src_index++] = sum;
        }
        src_index += 7;
    }
}


void convolution_using_stack(int dim, pixel *src, pixel *ker, unsigned *dst)
{

    int i,j,k,sum,
        sum_red_0, sum_green_0, sum_blue_0,
        sum_red_1, sum_green_1, sum_blue_1,
        sum_red_2, sum_green_2, sum_blue_2,
        sum_red_3, sum_green_3, sum_blue_3,
        sum_red_4, sum_green_4, sum_blue_4,
        sum_red_5, sum_green_5, sum_blue_5,
        sum_red_6, sum_green_6, sum_blue_6,
        sum_red_7, sum_green_7, sum_blue_7,
        src_index=0;

    for(i = 0; i < dim-8+1; i++) {
        for(j = 0; j < dim-8+1; j++) {
            sum_red_0 = 0; sum_green_0 = 0; sum_blue_0 = 0;
            sum_red_1 = 0; sum_green_1 = 0; sum_blue_1 = 0;
            sum_red_2 = 0; sum_green_2 = 0; sum_blue_2 = 0;
            sum_red_3 = 0; sum_green_3 = 0; sum_blue_3 = 0;
            sum_red_4 = 0; sum_green_4 = 0; sum_blue_4 = 0;
            sum_red_5 = 0; sum_green_5 = 0; sum_blue_5 = 0;
            sum_red_6 = 0; sum_green_6 = 0; sum_blue_6 = 0;
            sum_red_7 = 0; sum_green_7 = 0; sum_blue_7 = 0;
            for(k = 0; k < 64; k+=8) {
                sum_red_0   += src[src_index].red * ker[k].red;
                sum_green_0 += src[src_index].green * ker[k].green;
                sum_blue_0  += src[src_index].blue * ker[k].blue;

                sum_red_1   += src[src_index+1].red * ker[k+1].red;
                sum_green_1 += src[src_index+1].green * ker[k+1].green;
                sum_blue_1  += src[src_index+1].blue * ker[k+1].blue;

                sum_red_2   += src[src_index+2].red * ker[k+2].red;
                sum_green_2 += src[src_index+2].green * ker[k+2].green;
                sum_blue_2  += src[src_index+2].blue * ker[k+2].blue;

                sum_red_3   += src[src_index+3].red * ker[k+3].red;
                sum_green_3 += src[src_index+3].green * ker[k+3].green;
                sum_blue_3  += src[src_index+3].blue * ker[k+3].blue;

                sum_red_4   += src[src_index+4].red * ker[k+4].red;
                sum_green_4 += src[src_index+4].green * ker[k+4].green;
                sum_blue_4  += src[src_index+4].blue * ker[k+4].blue;

                sum_red_5   += src[src_index+5].red * ker[k+5].red;
                sum_green_5 += src[src_index+5].green * ker[k+5].green;
                sum_blue_5  += src[src_index+5].blue * ker[k+5].blue;

                sum_red_6   += src[src_index+6].red * ker[k+6].red;
                sum_green_6 += src[src_index+6].green * ker[k+6].green;
                sum_blue_6  += src[src_index+6].blue * ker[k+6].blue;

                sum_red_7   += src[src_index+7].red * ker[k+7].red;
                sum_green_7 += src[src_index+7].green * ker[k+7].green;
                sum_blue_7  += src[src_index+7].blue * ker[k+7].blue;

                src_index += dim;
            }
            sum = sum_red_0 + sum_green_0 + sum_blue_0
                + sum_red_1 + sum_green_1 + sum_blue_1
                + sum_red_2 + sum_green_2 + sum_blue_2
                + sum_red_3 + sum_green_3 + sum_blue_3
                + sum_red_4 + sum_green_4 + sum_blue_4
                + sum_red_5 + sum_green_5 + sum_blue_5
                + sum_red_6 + sum_green_6 + sum_blue_6
                + sum_red_7 + sum_green_7 + sum_blue_7;
            src_index -= (dim << 3);
            dst[src_index++] = sum;
        }
        src_index += 7;
    }
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

    naive_average_pooling(dim,src,dst);

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
    /* ... Register additional test functions here */
}


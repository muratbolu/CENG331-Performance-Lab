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
    "biggest commit ever", /* Team Name */

    "e252130",    /* First student ID */
    "MURAT BOLU", /* First student name */

    "e244906",     /* Second student ID */
    "UMUT YILMAZ", /* Second student name */

    "e244814",      /* Third student ID */
    "BAHADIR AYDIN" /* Third student Name */
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

    int i,j,sum;

    for(i = 0; i < dim-8+1; i++) {
        for(j = 0; j < dim-8+1; j++) {
            sum = 0;
            sum += src[0].red
                 * ker[0].red;
            sum += src[0].green
                 * ker[0].green;
            sum += src[0].blue
                 * ker[0].blue;

            sum += src[1].red
                 * ker[1].red;
            sum += src[1].green
                 * ker[1].green;
            sum += src[1].blue
                 * ker[1].blue;

            sum += src[2].red
                 * ker[2].red;
            sum += src[2].green
                 * ker[2].green;
            sum += src[2].blue
                 * ker[2].blue;

            sum += src[3].red
                 * ker[3].red;
            sum += src[3].green
                 * ker[3].green;
            sum += src[3].blue
                 * ker[3].blue;

            sum += src[4].red
                 * ker[4].red;
            sum += src[4].green
                 * ker[4].green;
            sum += src[4].blue
                 * ker[4].blue;

            sum += src[5].red
                 * ker[5].red;
            sum += src[5].green
                 * ker[5].green;
            sum += src[5].blue
                 * ker[5].blue;

            sum += src[6].red
                 * ker[6].red;
            sum += src[6].green
                 * ker[6].green;
            sum += src[6].blue
                 * ker[6].blue;

            sum += src[7].red
                 * ker[7].red;
            sum += src[7].green
                 * ker[7].green;
            sum += src[7].blue
                 * ker[7].blue;

            src += dim;

            sum += src[0].red
                 * ker[8].red;
            sum += src[0].green
                 * ker[8].green;
            sum += src[0].blue
                 * ker[8].blue;

            sum += src[1].red
                 * ker[9].red;
            sum += src[1].green
                 * ker[9].green;
            sum += src[1].blue
                 * ker[9].blue;

            sum += src[2].red
                 * ker[10].red;
            sum += src[2].green
                 * ker[10].green;
            sum += src[2].blue
                 * ker[10].blue;

            sum += src[3].red
                 * ker[11].red;
            sum += src[3].green
                 * ker[11].green;
            sum += src[3].blue
                 * ker[11].blue;

            sum += src[4].red
                 * ker[12].red;
            sum += src[4].green
                 * ker[12].green;
            sum += src[4].blue
                 * ker[12].blue;

            sum += src[5].red
                 * ker[13].red;
            sum += src[5].green
                 * ker[13].green;
            sum += src[5].blue
                 * ker[13].blue;

            sum += src[6].red
                 * ker[14].red;
            sum += src[6].green
                 * ker[14].green;
            sum += src[6].blue
                 * ker[14].blue;

            sum += src[7].red
                 * ker[15].red;
            sum += src[7].green
                 * ker[15].green;
            sum += src[7].blue
                 * ker[15].blue;

            src += dim;
            sum += src[0].red
                 * ker[16].red;
            sum += src[0].green
                 * ker[16].green;
            sum += src[0].blue
                 * ker[16].blue;

            sum += src[1].red
                 * ker[17].red;
            sum += src[1].green
                 * ker[17].green;
            sum += src[1].blue
                 * ker[17].blue;

            sum += src[2].red
                 * ker[18].red;
            sum += src[2].green
                 * ker[18].green;
            sum += src[2].blue
                 * ker[18].blue;

            sum += src[3].red
                 * ker[19].red;
            sum += src[3].green
                 * ker[19].green;
            sum += src[3].blue
                 * ker[19].blue;

            sum += src[4].red
                 * ker[20].red;
            sum += src[4].green
                 * ker[20].green;
            sum += src[4].blue
                 * ker[20].blue;

            sum += src[5].red
                 * ker[21].red;
            sum += src[5].green
                 * ker[21].green;
            sum += src[5].blue
                 * ker[21].blue;

            sum += src[6].red
                 * ker[22].red;
            sum += src[6].green
                 * ker[22].green;
            sum += src[6].blue
                 * ker[22].blue;

            sum += src[7].red
                 * ker[23].red;
            sum += src[7].green
                 * ker[23].green;
            sum += src[7].blue
                 * ker[23].blue;

            src += dim;
            sum += src[0].red
                 * ker[24].red;
            sum += src[0].green
                 * ker[24].green;
            sum += src[0].blue
                 * ker[24].blue;

            sum += src[1].red
                 * ker[25].red;
            sum += src[1].green
                 * ker[25].green;
            sum += src[1].blue
                 * ker[25].blue;

            sum += src[2].red
                 * ker[26].red;
            sum += src[2].green
                 * ker[26].green;
            sum += src[2].blue
                 * ker[26].blue;

            sum += src[3].red
                 * ker[27].red;
            sum += src[3].green
                 * ker[27].green;
            sum += src[3].blue
                 * ker[27].blue;

            sum += src[4].red
                 * ker[28].red;
            sum += src[4].green
                 * ker[28].green;
            sum += src[4].blue
                 * ker[28].blue;

            sum += src[5].red
                 * ker[29].red;
            sum += src[5].green
                 * ker[29].green;
            sum += src[5].blue
                 * ker[29].blue;

            sum += src[6].red
                 * ker[30].red;
            sum += src[6].green
                 * ker[30].green;
            sum += src[6].blue
                 * ker[30].blue;

            sum += src[7].red
                 * ker[31].red;
            sum += src[7].green
                 * ker[31].green;
            sum += src[7].blue
                 * ker[31].blue;

            src += dim;
            sum += src[0].red
                 * ker[32].red;
            sum += src[0].green
                 * ker[32].green;
            sum += src[0].blue
                 * ker[32].blue;

            sum += src[1].red
                 * ker[33].red;
            sum += src[1].green
                 * ker[33].green;
            sum += src[1].blue
                 * ker[33].blue;

            sum += src[2].red
                 * ker[34].red;
            sum += src[2].green
                 * ker[34].green;
            sum += src[2].blue
                 * ker[34].blue;

            sum += src[3].red
                 * ker[35].red;
            sum += src[3].green
                 * ker[35].green;
            sum += src[3].blue
                 * ker[35].blue;

            sum += src[4].red
                 * ker[36].red;
            sum += src[4].green
                 * ker[36].green;
            sum += src[4].blue
                 * ker[36].blue;

            sum += src[5].red
                 * ker[37].red;
            sum += src[5].green
                 * ker[37].green;
            sum += src[5].blue
                 * ker[37].blue;

            sum += src[6].red
                 * ker[38].red;
            sum += src[6].green
                 * ker[38].green;
            sum += src[6].blue
                 * ker[38].blue;

            sum += src[7].red
                 * ker[39].red;
            sum += src[7].green
                 * ker[39].green;
            sum += src[7].blue
                 * ker[39].blue;

            src += dim;
            sum += src[0].red
                 * ker[40].red;
            sum += src[0].green
                 * ker[40].green;
            sum += src[0].blue
                 * ker[40].blue;

            sum += src[1].red
                 * ker[41].red;
            sum += src[1].green
                 * ker[41].green;
            sum += src[1].blue
                 * ker[41].blue;

            sum += src[2].red
                 * ker[42].red;
            sum += src[2].green
                 * ker[42].green;
            sum += src[2].blue
                 * ker[42].blue;

            sum += src[3].red
                 * ker[43].red;
            sum += src[3].green
                 * ker[43].green;
            sum += src[3].blue
                 * ker[43].blue;

            sum += src[4].red
                 * ker[44].red;
            sum += src[4].green
                 * ker[44].green;
            sum += src[4].blue
                 * ker[44].blue;

            sum += src[5].red
                 * ker[45].red;
            sum += src[5].green
                 * ker[45].green;
            sum += src[5].blue
                 * ker[45].blue;

            sum += src[6].red
                 * ker[46].red;
            sum += src[6].green
                 * ker[46].green;
            sum += src[6].blue
                 * ker[46].blue;

            sum += src[7].red
                 * ker[47].red;
            sum += src[7].green
                 * ker[47].green;
            sum += src[7].blue
                 * ker[47].blue;

            src += dim;
            sum += src[0].red
                 * ker[48].red;
            sum += src[0].green
                 * ker[48].green;
            sum += src[0].blue
                 * ker[48].blue;

            sum += src[1].red
                 * ker[49].red;
            sum += src[1].green
                 * ker[49].green;
            sum += src[1].blue
                 * ker[49].blue;

            sum += src[2].red
                 * ker[50].red;
            sum += src[2].green
                 * ker[50].green;
            sum += src[2].blue
                 * ker[50].blue;

            sum += src[3].red
                 * ker[51].red;
            sum += src[3].green
                 * ker[51].green;
            sum += src[3].blue
                 * ker[51].blue;

            sum += src[4].red
                 * ker[52].red;
            sum += src[4].green
                 * ker[52].green;
            sum += src[4].blue
                 * ker[52].blue;

            sum += src[5].red
                 * ker[53].red;
            sum += src[5].green
                 * ker[53].green;
            sum += src[5].blue
                 * ker[53].blue;

            sum += src[6].red
                 * ker[54].red;
            sum += src[6].green
                 * ker[54].green;
            sum += src[6].blue
                 * ker[54].blue;

            sum += src[7].red
                 * ker[55].red;
            sum += src[7].green
                 * ker[55].green;
            sum += src[7].blue
                 * ker[55].blue;

            src += dim;
            sum += src[0].red
                 * ker[56].red;
            sum += src[0].green
                 * ker[56].green;
            sum += src[0].blue
                 * ker[56].blue;

            sum += src[1].red
                 * ker[57].red;
            sum += src[1].green
                 * ker[57].green;
            sum += src[1].blue
                 * ker[57].blue;

            sum += src[2].red
                 * ker[58].red;
            sum += src[2].green
                 * ker[58].green;
            sum += src[2].blue
                 * ker[58].blue;

            sum += src[3].red
                 * ker[59].red;
            sum += src[3].green
                 * ker[59].green;
            sum += src[3].blue
                 * ker[59].blue;

            sum += src[4].red
                 * ker[60].red;
            sum += src[4].green
                 * ker[60].green;
            sum += src[4].blue
                 * ker[60].blue;

            sum += src[5].red
                 * ker[61].red;
            sum += src[5].green
                 * ker[61].green;
            sum += src[5].blue
                 * ker[61].blue;

            sum += src[6].red
                 * ker[62].red;
            sum += src[6].green
                 * ker[62].green;
            sum += src[6].blue
                 * ker[62].blue;

            sum += src[7].red
                 * ker[63].red;
            sum += src[7].green
                 * ker[63].green;
            sum += src[7].blue
                 * ker[63].blue;

            src += dim;
            src -= (dim << 3);
            dst[i*dim+j] = sum;
            src++;
        }
        src += 7;
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
    int i, j, dim_2;
    int dst_index = 0, index = 0;
    dim_2 = dim >> 1;
    for (i = 0; i < dim_2; i++) {
        for (j = 0; j < dim_2; j++) {
            unsigned short temp_red = 0, temp_green = 0, temp_blue = 0;

            temp_red += (src[index].red + src[index + 1].red);
            temp_green += (src[index].green + src[index + 1].green);
            temp_blue += (src[index].blue + src[index + 1].blue);

            index += dim;

            temp_red += (src[index].red + src[index + 1].red);
            temp_green += (src[index].green + src[index + 1].green);
            temp_blue += (src[index].blue + src[index + 1].blue);

            index -= dim;

            dst[dst_index].red = temp_red >> 2;
            dst[dst_index].green = temp_green >> 2;
            dst[dst_index].blue = temp_blue >> 2;

            index += 2;
            dst_index++;
        }
        index += dim;
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
    /* ... Register additional test functions here */
}


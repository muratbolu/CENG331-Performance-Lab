/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

#define MY_RIDX(i,dim) ((i) * (dim))

/*
 * Please fill in the following team_t struct
 */
team_t team = {
        "TEAM",    /* Team Name */

        "e252130",      /* First student ID */
        "MURAT BOLU",       /* First student name */

        "e244906",             /* Second student ID */
        "UMUT YILMAZ",           /* Second student name */

        "e244814",             /* Third student ID */
        "BAHADIR AYDIN"            /* Third student Name */
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
    const int size = dim-7;
    int m = 0;
    int i,j,s1,s2,s3,s4,s5,s6,s7,s8,zet,n;
    int n1,n2,n3,n4,n5,n6,n7,n8;
    for (i = 0; i < size; i++) {
        n = m;
        n1 = n;
        for (j = 0; j < size; j++) {
            s1 = src[n1].red   * ker[0].red
               + src[n1].green * ker[0].green
               + src[n1].blue  * ker[0].blue

               + src[n1 + 1].red   * ker[1].red
               + src[n1 + 1].green * ker[1].green
               + src[n1 + 1].blue  * ker[1].blue

               + src[n1 + 2].red   * ker[2].red
               + src[n1 + 2].green * ker[2].green
               + src[n1 + 2].blue  * ker[2].blue

               + src[n1 + 3].red   * ker[3].red
               + src[n1 + 3].green * ker[3].green
               + src[n1 + 3].blue  * ker[3].blue

               + src[n1 + 4].red   * ker[4].red
               + src[n1 + 4].green * ker[4].green
               + src[n1 + 4].blue  * ker[4].blue

               + src[n1 + 5].red   * ker[5].red
               + src[n1 + 5].green * ker[5].green
               + src[n1 + 5].blue  * ker[5].blue

               + src[n1 + 6].red   * ker[6].red
               + src[n1 + 6].green * ker[6].green
               + src[n1 + 6].blue  * ker[6].blue

               + src[n1 + 7].red   * ker[7].red
               + src[n1 + 7].green * ker[7].green
               + src[n1 + 7].blue  * ker[7].blue;

            dst[n1++] = s1;
        }
        zet = dim + n;
        n2 = n;
        for(j = 0; j < size; j++){
            s2 = src[zet].red   * ker[8].red
               + src[zet].green * ker[8].green
               + src[zet].blue  * ker[8].blue

               + src[zet + 1].red   * ker[9].red
               + src[zet + 1].green * ker[9].green
               + src[zet + 1].blue  * ker[9].blue

               + src[zet + 2].red   * ker[10].red
               + src[zet + 2].green * ker[10].green
               + src[zet + 2].blue  * ker[10].blue

               + src[zet + 3].red   * ker[11].red
               + src[zet + 3].green * ker[11].green
               + src[zet + 3].blue  * ker[11].blue

               + src[zet + 4].red   * ker[12].red
               + src[zet + 4].green * ker[12].green
               + src[zet + 4].blue  * ker[12].blue

               + src[zet + 5].red   * ker[13].red
               + src[zet + 5].green * ker[13].green
               + src[zet + 5].blue  * ker[13].blue

               + src[zet + 6].red   * ker[14].red
               + src[zet + 6].green * ker[14].green
               + src[zet + 6].blue  * ker[14].blue

               + src[zet + 7].red   * ker[15].red
               + src[zet + 7].green * ker[15].green
               + src[zet + 7].blue  * ker[15].blue;

            dst[n2++] += s2;
            zet++;
        }
        zet = (dim << 1) + n;
        n3 = n;
        for (int j = 0; j < size; j++) {
            s3 = src[zet].red   * ker[16].red
               + src[zet].green * ker[16].green
               + src[zet].blue  * ker[16].blue

               + src[zet + 1].red   * ker[17].red
               + src[zet + 1].green * ker[17].green
               + src[zet + 1].blue  * ker[17].blue

               + src[zet + 2].red   * ker[18].red
               + src[zet + 2].green * ker[18].green
               + src[zet + 2].blue  * ker[18].blue

               + src[zet + 3].red   * ker[19].red
               + src[zet + 3].green * ker[19].green
               + src[zet + 3].blue  * ker[19].blue

               + src[zet + 4].red   * ker[20].red
               + src[zet + 4].green * ker[20].green
               + src[zet + 4].blue  * ker[20].blue

               + src[zet + 5].red   * ker[21].red
               + src[zet + 5].green * ker[21].green
               + src[zet + 5].blue  * ker[21].blue

               + src[zet + 6].red   * ker[22].red
               + src[zet + 6].green * ker[22].green
               + src[zet + 6].blue  * ker[22].blue

               + src[zet + 7].red   * ker[23].red
               + src[zet + 7].green * ker[23].green
               + src[zet + 7].blue  * ker[23].blue;

            dst[n3++] += s3;
            zet++;
        }
        zet = 3 * dim + n;
        n4 = n;
        for(int j = 0; j < size; j++){
            s4 = src[zet].red   * ker[24].red
               + src[zet].green * ker[24].green
               + src[zet].blue  * ker[24].blue

               + src[zet + 1].red   * ker[25].red
               + src[zet + 1].green * ker[25].green
               + src[zet + 1].blue  * ker[25].blue

               + src[zet + 2].red   * ker[26].red
               + src[zet + 2].green * ker[26].green
               + src[zet + 2].blue  * ker[26].blue

               + src[zet + 3].red   * ker[27].red
               + src[zet + 3].green * ker[27].green
               + src[zet + 3].blue  * ker[27].blue

               + src[zet + 4].red   * ker[28].red
               + src[zet + 4].green * ker[28].green
               + src[zet + 4].blue  * ker[28].blue

               + src[zet + 5].red   * ker[29].red
               + src[zet + 5].green * ker[29].green
               + src[zet + 5].blue  * ker[29].blue

               + src[zet + 6].red   * ker[30].red
               + src[zet + 6].green * ker[30].green
               + src[zet + 6].blue  * ker[30].blue

               + src[zet + 7].red   * ker[31].red
               + src[zet + 7].green * ker[31].green
               + src[zet + 7].blue  * ker[31].blue;

            dst[n4++] += s4;
            zet++;
        }
        zet = (dim << 2) + n;
        n5 = n;
        for(int j = 0;j < size; j++){
            s5 = src[zet].red   * ker[32].red
               + src[zet].green * ker[32].green
               + src[zet].blue  * ker[32].blue

               + src[zet + 1].red   * ker[33].red
               + src[zet + 1].green * ker[33].green
               + src[zet + 1].blue  * ker[33].blue

               + src[zet + 2].red   * ker[34].red
               + src[zet + 2].green * ker[34].green
               + src[zet + 2].blue  * ker[34].blue

               + src[zet + 3].red   * ker[35].red
               + src[zet + 3].green * ker[35].green
               + src[zet + 3].blue  * ker[35].blue

               + src[zet + 4].red   * ker[36].red
               + src[zet + 4].green * ker[36].green
               + src[zet + 4].blue  * ker[36].blue

               + src[zet + 5].red   * ker[37].red
               + src[zet + 5].green * ker[37].green
               + src[zet + 5].blue  * ker[37].blue

               + src[zet + 6].red   * ker[38].red
               + src[zet + 6].green * ker[38].green
               + src[zet + 6].blue  * ker[38].blue

               + src[zet + 7].red   * ker[39].red
               + src[zet + 7].green * ker[39].green
               + src[zet + 7].blue  * ker[39].blue;

            dst[n5++] += s5;
            zet++;
        }
        zet = 5 * dim + n;
        n6 = n;
        for(int j = 0;j<size;j++){
            s6 = src[zet].red   * ker[40].red
               + src[zet].green * ker[40].green
               + src[zet].blue  * ker[40].blue

               + src[zet + 1].red   * ker[41].red
               + src[zet + 1].green * ker[41].green
               + src[zet + 1].blue  * ker[41].blue

               + src[zet + 2].red   * ker[42].red
               + src[zet + 2].green * ker[42].green
               + src[zet + 2].blue  * ker[42].blue

               + src[zet + 3].red   * ker[43].red
               + src[zet + 3].green * ker[43].green
               + src[zet + 3].blue  * ker[43].blue

               + src[zet + 4].red   * ker[44].red
               + src[zet + 4].green * ker[44].green
               + src[zet + 4].blue  * ker[44].blue

               + src[zet + 5].red   * ker[45].red
               + src[zet + 5].green * ker[45].green
               + src[zet + 5].blue  * ker[45].blue

               + src[zet + 6].red   * ker[46].red
               + src[zet + 6].green * ker[46].green
               + src[zet + 6].blue  * ker[46].blue

               + src[zet + 7].red   * ker[47].red
               + src[zet + 7].green * ker[47].green
               + src[zet + 7].blue  * ker[47].blue;

            dst[n6++] += s6;
            zet++;
        }
        zet = 6 * dim + n;
        n7 = n;
        for(int j=0 ; j< size;j++){
            s7 = src[zet].red   * ker[48].red
               + src[zet].green * ker[48].green
               + src[zet].blue  * ker[48].blue

               + src[zet + 1].red   * ker[49].red
               + src[zet + 1].green * ker[49].green
               + src[zet + 1].blue  * ker[49].blue

               + src[zet + 2].red   * ker[50].red
               + src[zet + 2].green * ker[50].green
               + src[zet + 2].blue  * ker[50].blue

               + src[zet + 3].red   * ker[51].red
               + src[zet + 3].green * ker[51].green
               + src[zet + 3].blue  * ker[51].blue

               + src[zet + 4].red   * ker[52].red
               + src[zet + 4].green * ker[52].green
               + src[zet + 4].blue  * ker[52].blue

               + src[zet + 5].red   * ker[53].red
               + src[zet + 5].green * ker[53].green
               + src[zet + 5].blue  * ker[53].blue

               + src[zet + 6].red   * ker[54].red
               + src[zet + 6].green * ker[54].green
               + src[zet + 6].blue  * ker[54].blue

               + src[zet + 7].red   * ker[55].red
               + src[zet + 7].green * ker[55].green
               + src[zet + 7].blue  * ker[55].blue;

            dst[n7++] += s7;
            zet++;
        }
        zet = 7 * dim + n;
        n8 = n;
        for(int j=0;j<size;j++){
            s8 = src[zet].red   * ker[56].red
               + src[zet].green * ker[56].green
               + src[zet].blue  * ker[56].blue

               + src[zet + 1].red   * ker[57].red
               + src[zet + 1].green * ker[57].green
               + src[zet + 1].blue  * ker[57].blue

               + src[zet + 2].red   * ker[58].red
               + src[zet + 2].green * ker[58].green
               + src[zet + 2].blue  * ker[58].blue

               + src[zet + 3].red   * ker[59].red
               + src[zet + 3].green * ker[59].green
               + src[zet + 3].blue  * ker[59].blue

               + src[zet + 4].red   * ker[60].red
               + src[zet + 4].green * ker[60].green
               + src[zet + 4].blue  * ker[60].blue

               + src[zet + 5].red   * ker[61].red
               + src[zet + 5].green * ker[61].green
               + src[zet + 5].blue  * ker[61].blue

               + src[zet + 6].red   * ker[62].red
               + src[zet + 6].green * ker[62].green
               + src[zet + 6].blue  * ker[62].blue

               + src[zet + 7].red   * ker[63].red
               + src[zet + 7].green * ker[63].green
               + src[zet + 7].blue  * ker[63].blue;

            dst[n8++] += s8;
            zet++;
        }

        m += dim;
    }
}

// BAHADIR'S VERSION

char bahadir_convolution_descr[] = "Convolution: Bahadır version";
void bahadir_convolution(int dim, pixel *src, pixel *ker, unsigned *dst){
    const int size = dim-7;
    int m = 0;
    int i,j,s1,s2,s3,s4,s5,s6,s7,s8,zet,n;
    int n1,n2,n3,n4,n5,n6,n7,n8;
    for (i = 0; i < size; i++) {
        n = m;
        n1 = n;
        for (j = 0; j < size; j++) { 
            s1 = src[n1].red * ker[0].red + src[n1].green * ker[0].green + src[n1].blue * ker[0].blue +
            src[n1 + 1].red * ker[1].red+ src[n1 + 1].green * ker[1].green+ src[n1 + 1].blue * ker[1].blue +
            src[n1 + 2].red * ker[2].red+ src[n1 + 2].green * ker[2].green+ src[n1 + 2].blue * ker[2].blue+
            src[n1 + 3].red * ker[3].red+ src[n1 + 3].green * ker[3].green+ src[n1 + 3].blue * ker[3].blue+
            src[n1 + 4].red * ker[4].red+ src[n1 + 4].green * ker[4].green+ src[n1 + 4].blue * ker[4].blue+
            src[n1 + 5].red * ker[5].red+ src[n1 + 5].green * ker[5].green+ src[n1 + 5].blue * ker[5].blue+
            src[n1 + 6].red * ker[6].red+ src[n1 + 6].green * ker[6].green+ src[n1 + 6].blue * ker[6].blue+      
            src[n1 + 7].red * ker[7].red+ src[n1 + 7].green * ker[7].green+ src[n1 + 7].blue * ker[7].blue;
            dst[n1++] = s1;
        }
        zet = dim + n;
        n2 = n;
        for(j = 0; j < size; j++){
            s2 = src[zet].red * ker[8].red + src[zet].green * ker[8].green + src[zet].blue * ker[8].blue +
            src[zet + 1].red * ker[9].red + src[zet + 1].green * ker[9].green + src[zet + 1].blue * ker[9].blue +
            src[zet + 2].red * ker[10].red + src[zet + 2].green * ker[10].green + src[zet + 2].blue * ker[10].blue +
            src[zet + 3].red * ker[11].red + src[zet + 3].green * ker[11].green + src[zet + 3].blue * ker[11].blue +
            src[zet + 4].red * ker[12].red + src[zet + 4].green * ker[12].green + src[zet + 4].blue * ker[12].blue +
            src[zet + 5].red * ker[13].red + src[zet + 5].green * ker[13].green + src[zet + 5].blue * ker[13].blue +
            src[zet + 6].red * ker[14].red + src[zet + 6].green * ker[14].green + src[zet + 6].blue * ker[14].blue +
            src[zet + 7].red * ker[15].red + src[zet + 7].green * ker[15].green + src[zet + 7].blue * ker[15].blue;
            dst[n2++] += s2;
            zet++;
        }
        zet = (dim << 1) + n; 
        n3 = n;
        for (int j = 0; j < size; j++) {
            s3 = src[zet].red * ker[16].red + src[zet].green * ker[16].green + src[zet].blue * ker[16].blue +
            src[zet + 1].red * ker[17].red + src[zet + 1].green * ker[17].green + src[zet + 1].blue * ker[17].blue +
            src[zet + 2].red * ker[18].red + src[zet + 2].green * ker[18].green + src[zet + 2].blue * ker[18].blue +
            src[zet + 3].red * ker[19].red + src[zet + 3].green * ker[19].green + src[zet + 3].blue * ker[19].blue +
            src[zet + 4].red * ker[20].red + src[zet + 4].green * ker[20].green + src[zet + 4].blue * ker[20].blue +
            src[zet + 5].red * ker[21].red  + src[zet + 5].green * ker[21].green + src[zet + 5].blue * ker[21].blue +
            src[zet + 6].red * ker[22].red + src[zet + 6].green * ker[22].green + src[zet + 6].blue * ker[22].blue +
            src[zet + 7].red * ker[23].red + src[zet + 7].green * ker[23].green + src[zet + 7].blue * ker[23].blue;
            dst[n3++] += s3;
            zet++;
        }
        zet = 3 * dim + n;
        n4 = n;
        for(int j = 0; j < size; j++){
            s4 = src[zet].red * ker[24].red+ src[zet].green * ker[24].green+ src[zet].blue * ker[24].blue+
            src[zet + 1].red * ker[25].red+ src[zet + 1].green * ker[25].green+ src[zet + 1].blue * ker[25].blue+
            src[zet + 2].red * ker[26].red+ src[zet + 2].green * ker[26].green+ src[zet + 2].blue * ker[26].blue+
            src[zet + 3].red * ker[27].red+ src[zet + 3].green * ker[27].green+ src[zet + 3].blue * ker[27].blue+
            src[zet + 4].red * ker[28].red+ src[zet + 4].green * ker[28].green+ src[zet + 4].blue * ker[28].blue+
            src[zet + 5].red * ker[29].red+ src[zet + 5].green * ker[29].green+ src[zet + 5].blue * ker[29].blue+
            src[zet + 6].red * ker[30].red+ src[zet + 6].green * ker[30].green+ src[zet + 6].blue * ker[30].blue+
            src[zet + 7].red * ker[31].red+ src[zet + 7].green * ker[31].green+ src[zet + 7].blue * ker[31].blue;
            dst[n4++] += s4;
            zet++;
        }
        zet = (dim << 2) + n;
        n5 = n; 
        for(int j = 0;j < size; j++){
            s5 = src[zet].red * ker[32].red+ src[zet].green * ker[32].green+ src[zet].blue * ker[32].blue+
            src[zet + 1].red * ker[33].red+ src[zet + 1].green * ker[33].green+ src[zet + 1].blue * ker[33].blue+
            src[zet + 2].red * ker[34].red+ src[zet + 2].green * ker[34].green+ src[zet + 2].blue * ker[34].blue+
            src[zet + 3].red * ker[35].red+ src[zet + 3].green * ker[35].green+ src[zet + 3].blue * ker[35].blue+
            src[zet + 4].red * ker[36].red+ src[zet + 4].green * ker[36].green+ src[zet + 4].blue * ker[36].blue+
            src[zet + 5].red * ker[37].red+ src[zet + 5].green * ker[37].green+ src[zet + 5].blue * ker[37].blue+
            src[zet + 6].red * ker[38].red+ src[zet + 6].green * ker[38].green+ src[zet + 6].blue * ker[38].blue+
            src[zet + 7].red * ker[39].red+ src[zet + 7].green * ker[39].green+ src[zet + 7].blue * ker[39].blue;
            dst[n5++] += s5;
            zet++;
        }
        zet = 5 * dim + n;
        n6 = n;
        for(int j = 0;j<size;j++){
            s6 = src[zet].red * ker[40].red + src[zet].green * ker[40].green + src[zet].blue * ker[40].blue +
            src[zet + 1].red * ker[41].red + src[zet + 1].green * ker[41].green + src[zet + 1].blue * ker[41].blue +
            src[zet + 2].red * ker[42].red + src[zet + 2].green * ker[42].green + src[zet + 2].blue * ker[42].blue +
            src[zet + 3].red * ker[43].red + src[zet + 3].green * ker[43].green + src[zet + 3].blue * ker[43].blue +
            src[zet + 4].red * ker[44].red + src[zet + 4].green * ker[44].green + src[zet + 4].blue * ker[44].blue +
            src[zet + 5].red * ker[45].red + src[zet + 5].green * ker[45].green + src[zet + 5].blue * ker[45].blue +
            src[zet + 6].red * ker[46].red + src[zet + 6].green * ker[46].green + src[zet + 6].blue * ker[46].blue +
            src[zet + 7].red * ker[47].red + src[zet + 7].green * ker[47].green + src[zet + 7].blue * ker[47].blue;
            dst[n6++] += s6;
            zet++;
        }
        zet = 6 * dim + n; 
        n7 = n;
        for(int j=0 ; j< size;j++){
            s7 = src[zet].red * ker[48].red + src[zet].green * ker[48].green + src[zet].blue * ker[48].blue +
            src[zet + 1].red * ker[49].red + src[zet + 1].green * ker[49].green + src[zet + 1].blue * ker[49].blue +
            src[zet + 2].red * ker[50].red + src[zet + 2].green * ker[50].green + src[zet + 2].blue * ker[50].blue +
            src[zet + 3].red * ker[51].red + src[zet + 3].green * ker[51].green + src[zet + 3].blue * ker[51].blue +
            src[zet + 4].red * ker[52].red + src[zet + 4].green * ker[52].green + src[zet + 4].blue * ker[52].blue +
            src[zet + 5].red * ker[53].red + src[zet + 5].green * ker[53].green + src[zet + 5].blue * ker[53].blue +
            src[zet + 6].red * ker[54].red + src[zet + 6].green * ker[54].green + src[zet + 6].blue * ker[54].blue +
            src[zet + 7].red * ker[55].red + src[zet + 7].green * ker[55].green + src[zet + 7].blue * ker[55].blue;
            dst[n7++] += s7;
            zet++;
        }
        zet = 7 * dim + n;
        n8 = n;
        for(int j=0;j<size;j++){
            s8 = src[zet].red * ker[56].red + src[zet].green * ker[56].green + src[zet].blue * ker[56].blue +
            src[zet + 1].red * ker[57].red + src[zet + 1].green * ker[57].green + src[zet + 1].blue * ker[57].blue +
            src[zet + 2].red * ker[58].red + src[zet + 2].green * ker[58].green + src[zet + 2].blue * ker[58].blue +
            src[zet + 3].red * ker[59].red + src[zet + 3].green * ker[59].green + src[zet + 3].blue * ker[59].blue +
            src[zet + 4].red * ker[60].red + src[zet + 4].green * ker[60].green + src[zet + 4].blue * ker[60].blue +
            src[zet + 5].red * ker[61].red + src[zet + 5].green * ker[61].green + src[zet + 5].blue * ker[61].blue +
            src[zet + 6].red * ker[62].red + src[zet + 6].green * ker[62].green + src[zet + 6].blue * ker[62].blue +
            src[zet + 7].red * ker[63].red + src[zet + 7].green * ker[63].green + src[zet + 7].blue * ker[63].blue;
            dst[n8++] += s8;
            zet++;
        }

        m += dim;
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
    add_conv_function(&bahadir_convolution,bahadir_convolution_descr);
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

char old_average_pooling_descr[] = "Average Pooling: old version";
void old_average_pooling(int dim, pixel *src, pixel *dst)
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
            index = RIDX(i2, j2, dim);
            for(k = 0; k < 2; k++) {

                temp_red += src[index].red + src[index+1].red;
                temp_green += src[index].green + src[index+1].green;
                temp_blue += src[index].blue + src[index+1].blue;
                index += dim;

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
    int i,j,i1,j1, dim_2, B = 16;
    dim_2 = dim >> 1;
    for(i = 0; i < dim_2; i+= B){
        int i_bound = i + B;
        for(j = 0; j < dim_2; j+=B){
            int index = RIDX(i << 1, j << 1, dim);
            int dst_index = RIDX(i, j, dim_2);

            int j_bound = j + B;
            for(i1 = i; i1 < i_bound; i1++){
                for(j1 = j; j1 <j_bound; j1++){
                    unsigned short temp_red = 0, temp_green = 0, temp_blue = 0;


                    temp_red += (src[index].red + src[index+1].red);
                    temp_green += (src[index].green + src[index+1].green);
                    temp_blue += (src[index].blue + src[index+1].blue);

                    index += dim;

                    temp_red += (src[index].red + src[index+1].red);
                    temp_green += (src[index].green + src[index+1].green);
                    temp_blue += (src[index].blue + src[index+1].blue);


                    index -= dim;
                    dst[dst_index].red = temp_red >> 2;
                    dst[dst_index].green = temp_green >> 2;
                    dst[dst_index].blue = temp_blue >> 2;
                    dst_index++;
                    index+= 2;
                }
                dst_index += dim_2 - B;
                index += (dim - B) << 1;

            }

        }
    }
}

/******************************************************************************
 * register_average_pooling_functions - Register all of your different versions
 *     of the average pooling  with the driver by calling the
 *     add_average_pooling_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 ******************************************************************************/

char test_average_pooling_descr[] = "Average Pooling: test version";
void test_average_pooling(int dim, pixel *src, pixel *dst)
{
    int i,j,i1,j1, dim_2, B = 16;
    dim_2 = dim >> 1;
    for(i = 0; i < dim_2; i+= B){
        int i_bound = i + B;
        for(j = 0; j < dim_2; j+=B){
            int index = RIDX(i << 1, j << 1, dim);
            int dst_index = RIDX(i, j, dim_2);

            int j_bound = j + B;
            for(i1 = i; i1 < i_bound; i1++){
                for(j1 = j; j1 <j_bound; j1++){
                    unsigned short temp_red = 0, temp_green = 0, temp_blue = 0;


                    temp_red += (src[index].red + src[index+1].red);
                    temp_green += (src[index].green + src[index+1].green);
                    temp_blue += (src[index].blue + src[index+1].blue);

                    index += dim;

                    temp_red += (src[index].red + src[index+1].red);
                    temp_green += (src[index].green + src[index+1].green);
                    temp_blue += (src[index].blue + src[index+1].blue);

                    index -= dim;

                    dst[dst_index].red = temp_red >> 2;
                    dst[dst_index].green = temp_green >> 2;
                    dst[dst_index].blue = temp_blue >> 2;
                    dst_index++;
                    index+= 2;
                }
                dst_index += dim_2 - B;
                index += (dim - B) << 1;

            }

        }
    }
}

char average_pooling_descr[] = "Average Pooling: Current working version";
void average_pooling(int dim, pixel *src, pixel *dst)
{

    int i,j, dim_2;
    int dst_index = 0, index = 0;
    dim_2 = dim >> 1;
    for(i = 0; i < dim_2; i++){
        for(j = 0; j < dim_2; j++) {
            unsigned short temp_red = 0, temp_green = 0, temp_blue = 0;

            temp_red += (src[index].red + src[index+1].red);
            temp_green += (src[index].green + src[index+1].green);
            temp_blue += (src[index].blue + src[index+1].blue);

            index += dim;

            temp_red += (src[index].red + src[index+1].red);
            temp_green += (src[index].green + src[index+1].green);
            temp_blue += (src[index].blue + src[index+1].blue);

            index -= dim;

            dst[dst_index].red = temp_red >> 2;
            dst[dst_index].green = temp_green >> 2;
            dst[dst_index].blue = temp_blue >> 2;

            index+=2;
            dst_index++;
        }
        index += dim;

    }
}

void register_average_pooling_functions() {
    add_average_pooling_function(&naive_average_pooling, naive_average_pooling_descr);

    add_average_pooling_function(&old_average_pooling, old_average_pooling_descr);
    add_average_pooling_function(&seq_average_pooling, seq_average_pooling_descr);

    add_average_pooling_function(&average_pooling, average_pooling_descr);
    add_average_pooling_function(&test_average_pooling, test_average_pooling_descr);
    /* ... Register additional test functions here */
}

/*void test_average_pooling(int dim, pixel *src, pixel *dst)
{

    int i,j,k,i2 = 0, dim_2;
    dim_2 = dim >> 1;
    for(i = 0; i < dim_2; i++){
        int index = MY_RIDX(i2,dim);
        for(j = 0; j < dim_2; j++) {
            unsigned short temp_red = 0, temp_green = 0, temp_blue = 0;
            int dst_index;
            for(k = 0; k < 2; k++) {
                int index2 = index + 1;
                temp_red += src[index].red + src[index2].red;
                temp_green += src[index].green + src[index2].green;
                temp_blue += src[index].blue + src[index2].blue;
                index += dim;

            }
            index -= 2*dim;
            dst_index = RIDX(i, j, dim_2);
            dst[dst_index].red = temp_red >> 2;
            dst[dst_index].green = temp_green >> 2;
            dst[dst_index].blue = temp_blue >> 2;
            index+=2;
        }
        i2 += 2;
    }
}
*/

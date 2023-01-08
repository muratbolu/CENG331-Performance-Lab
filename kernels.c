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
        for (j = 0; j < size; j++) {
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
        zet = (dim << 1) + dim + n;
        n4 = n;
        for(j = 0; j < size; j++){
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
        for(j = 0;j < size; j++){
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
        zet = (dim << 2) + dim + n;
        n6 = n;
        for(j = 0;j<size;j++){
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
        for(j=0 ; j< size;j++){
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
        zet = (dim << 3) - dim + n;
        n8 = n;
        for(j=0;j<size;j++){
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

char bahadir_convolution_descrV3[] = "Bahadır Version: Store kernel variables in tmp vars.";
void bahadir_convolutionV3(int dim, pixel *src, pixel *ker, unsigned *dst){
    const int size = dim-7;
    int m = 0;
    int i,j,s1,s2,s3,s4,s5,s6,s7,s8,zet,n;
    int n1,n2,n3,n4,n5,n6,n7,n8;
    int k0r,k0g,k0b,k1r,k1g,k1b,k2r,k2g,k2b,k3r,k3g,k3b,k4r,k4g,k4b,k5r,k5g,k5b,k6r,k6g,k6b,k7r,k7g,k7b;
    for (i = 0; i < size; i++) {
        n = m;
        n1 = n;

        k0r = ker[0].red; k0g = ker[0].green;  k0b = ker[0].blue;
        k1r = ker[1].red; k1g = ker[1].green; k1b = ker[1].blue;
        k2r = ker[2].red; k2g = ker[2].green; k2b = ker[2].blue;
        k3r = ker[3].red; k3g = ker[3].green; k3b = ker[3].blue;
        k4r = ker[4].red; k4g = ker[4].green; k4b = ker[4].blue;
        k5r = ker[5].red; k5g = ker[5].green; k5b = ker[5].blue;
        k6r = ker[6].red; k6g = ker[6].green; k6b = ker[6].blue;
        k7r = ker[7].red; k7g = ker[7].green; k7b = ker[7].blue;
        for (j = 0; j < size; j++) { 
            s1 = src[n1].red * k0r + src[n1].green * k0g + src[n1].blue * k0b+
            src[n1 + 1].red * k1r + src[n1 + 1].green * k1g + src[n1 + 1].blue * k1b +
            src[n1 + 2].red * k2r + src[n1 + 2].green * k2g + src[n1 + 2].blue * k2b +
            src[n1 + 3].red * k3r + src[n1 + 3].green * k3g + src[n1 + 3].blue * k3b +
            src[n1 + 4].red * k4r + src[n1 + 4].green * k4g + src[n1 + 4].blue * k4b +
            src[n1 + 5].red * k5r + src[n1 + 5].green * k5g + src[n1 + 5].blue * k5b +
            src[n1 + 6].red * k6r + src[n1 + 6].green * k6g + src[n1 + 6].blue * k6b +
            src[n1 + 7].red * k7r + src[n1 + 7].green * k7g + src[n1 + 7].blue * k7b;
            dst[n1++] = s1;
        }
        zet = dim + n;
        n2 = n;
        
        k0r = ker[8].red; k0g = ker[8].green; k0b = ker[8].blue;
        k1r = ker[9].red;k1g = ker[9].green;k1b = ker[9].blue;
        k2r = ker[10].red;k2g = ker[10].green;k2b = ker[10].blue;
        k3r = ker[11].red;k3g = ker[11].green;k3b = ker[11].blue;
        k4r = ker[12].red;k4g = ker[12].green;k4b = ker[12].blue;
        k5r = ker[13].red;k5g = ker[13].green;k5b = ker[13].blue;
        k6r = ker[14].red;k6g = ker[14].green;k6b = ker[14].blue;
        k7r = ker[15].red;k7g = ker[15].green;k7b = ker[15].blue;
        for(j = 0; j < size; j++){
            s2 = src[zet].red * k0r+ src[zet].green * k0g + src[zet].blue * k0b +
            src[zet + 1].red * k1r+ src[zet + 1].green * k1g + src[zet + 1].blue * k1b+
            src[zet + 2].red * k2r+ src[zet + 2].green * k2g + src[zet + 2].blue * k2b+
            src[zet + 3].red * k3r+ src[zet + 3].green * k3g + src[zet + 3].blue * k3b+
            src[zet + 4].red * k4r+ src[zet + 4].green * k4g + src[zet + 4].blue * k4b+
            src[zet + 5].red * k5r+ src[zet + 5].green * k5g + src[zet + 5].blue * k5b+
            src[zet + 6].red * k6r+ src[zet + 6].green * k6g + src[zet + 6].blue * k6b+
            src[zet + 7].red * k7r+ src[zet + 7].green * k7g + src[zet + 7].blue *k7b;
            dst[n2++] += s2;
            zet++;
        }
        zet = (dim << 1) + n; 
        n3 = n;

        k0r = ker[16].red; k0g = ker[16].green;  k0b = ker[16].blue;
        k1r = ker[17].red; k1g = ker[17].green; k1b = ker[17].blue;
        k2r = ker[18].red; k2g = ker[18].green; k2b = ker[18].blue;
        k3r = ker[19].red; k3g = ker[19].green; k3b = ker[19].blue;
        k4r = ker[20].red; k4g = ker[20].green; k4b = ker[20].blue;
        k5r = ker[21].red; k5g = ker[21].green; k5b = ker[21].blue;
        k6r = ker[22].red; k6g = ker[22].green; k6b = ker[22].blue;
        k7r = ker[23].red; k7g = ker[23].green; k7b = ker[23].blue;
        for (int j = 0; j < size; j++) {
            s3 = src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b +
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b +
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b +
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b +
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b +
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b +
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b +
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue *k7b;
            dst[n3++] += s3;
            zet++;
        }
        zet = (dim << 1) + dim + n;
        n4 = n;

        k0r = ker[24].red; k0g = ker[24].green; k0b = ker[24].blue;
        k1r = ker[25].red; k1g = ker[25].green; k1b = ker[25].blue;
        k2r = ker[26].red; k2g = ker[26].green; k2b = ker[26].blue;
        k3r = ker[27].red; k3g = ker[27].green; k3b = ker[27].blue;
        k4r = ker[28].red; k4g = ker[28].green; k4b = ker[28].blue;
        k5r = ker[29].red; k5g = ker[29].green; k5b = ker[29].blue;
        k6r = ker[30].red; k6g = ker[30].green; k6b = ker[30].blue;
        k7r = ker[31].red; k7g = ker[31].green; k7b = ker[31].blue;
        for(int j = 0; j < size; j++){
            s4 = src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b + 
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b + 
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b + 
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b + 
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b + 
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b + 
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b + 
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue * k7b; 
            dst[n4++] += s4;
            zet++;
        }
        zet = (dim << 2) + n;
        n5 = n; 

        k0r = ker[32].red;k0g = ker[32].green; k0b = ker[32].blue;
        k1r = ker[33].red;k1g = ker[33].green;k1b = ker[33].blue;
        k2r = ker[34].red;k2g = ker[34].green;k2b = ker[34].blue;
        k3r = ker[35].red;k3g = ker[35].green;k3b = ker[35].blue;
        k4r = ker[36].red;k4g = ker[36].green;k4b = ker[36].blue;
        k5r = ker[37].red;k5g = ker[37].green;k5b = ker[37].blue;
        k6r = ker[38].red;k6g = ker[38].green;k6b = ker[38].blue;
        k7r = ker[39].red;k7g = ker[39].green;k7b = ker[39].blue;
        for(j = 0;j < size; j++){
            s5 = src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b + 
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b + 
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b + 
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b + 
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b + 
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b + 
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b + 
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue * k7b; 
            dst[n5++] += s5;
            zet++;
        }
        zet = (dim << 2) + dim + n;
        n6 = n;

        k0r = ker[40].red; k0g = ker[40].green;  k0b = ker[40].blue;
        k1r = ker[41].red; k1g = ker[41].green; k1b = ker[41].blue;
        k2r = ker[42].red; k2g = ker[42].green; k2b = ker[42].blue;
        k3r = ker[43].red; k3g = ker[43].green; k3b = ker[43].blue;
        k4r = ker[44].red; k4g = ker[44].green; k4b = ker[44].blue;
        k5r = ker[45].red; k5g = ker[45].green; k5b = ker[45].blue;
        k6r = ker[46].red; k6g = ker[46].green; k6b = ker[46].blue;
        k7r = ker[47].red; k7g = ker[47].green; k7b = ker[47].blue;
        for(j = 0;j<size;j++){
            s6 = src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b+
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b+
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b+
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b+
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b+
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b+
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b+
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue *k7b;
            dst[n6++] += s6;
            zet++;
        }
        zet = 6 * dim + n; 
        n7 = n;

        k0r = ker[48].red; k0g = ker[48].green;  k0b = ker[48].blue;
        k1r = ker[49].red; k1g = ker[49].green; k1b = ker[49].blue;
        k2r = ker[50].red; k2g = ker[50].green; k2b = ker[50].blue;
        k3r = ker[51].red; k3g = ker[51].green; k3b = ker[51].blue;
        k4r = ker[52].red; k4g = ker[52].green; k4b = ker[52].blue;
        k5r = ker[53].red; k5g = ker[53].green; k5b = ker[53].blue;
        k6r = ker[54].red; k6g = ker[54].green; k6b = ker[54].blue;
        k7r = ker[55].red; k7g = ker[55].green; k7b = ker[55].blue;
        for(j=0 ; j< size;j++){
            s7 = src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b+
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b+
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b+
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b+
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b+
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b+
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b+
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue *k7b;
            dst[n7++] += s7;
            zet++;
        }
        zet = 7 * dim + n;
        n8 = n;

        k0r = ker[56].red; k0g = ker[56].green; k0b = ker[56].blue;
        k1r = ker[57].red; k1g = ker[57].green; k1b = ker[57].blue;
        k2r = ker[58].red; k2g = ker[58].green; k2b = ker[58].blue;
        k3r = ker[59].red; k3g = ker[59].green; k3b = ker[59].blue;
        k4r = ker[60].red; k4g = ker[60].green; k4b = ker[60].blue;
        k5r = ker[61].red; k5g = ker[61].green; k5b = ker[61].blue;
        k6r = ker[62].red; k6g = ker[62].green; k6b = ker[62].blue;
        k7r = ker[63].red; k7g = ker[63].green; k7b = ker[63].blue;
        for(j=0;j<size;j++){
            s8 = src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b +
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b +
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b +
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b +
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b +
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b +
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b +
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue *k7b; 
            dst[n8++] += s8;
            zet++;
        }

        m += dim;
    }
}

char bahadir_convolution_descrV4[] = "Bahadır Version: Minor changes to v3"; 
void bahadir_convolutionV4(int dim, pixel *src, pixel *ker, unsigned *dst){
    const int size = dim-7;
    int m = 0;
    int i,j,zet,n;
    int n1,n2,n3,n4,n5,n6,n7,n8;
    int k0r,k0g,k0b,k1r,k1g,k1b,k2r,k2g,k2b,k3r,k3g,k3b,k4r,k4g,k4b,k5r,k5g,k5b,k6r,k6g,k6b,k7r,k7g,k7b;
    for (i = 0; i < size; i++) {
        n = m;
        n1 = n;

        k0r = ker[0].red; k0g = ker[0].green;  k0b = ker[0].blue;
        k1r = ker[1].red; k1g = ker[1].green; k1b = ker[1].blue;
        k2r = ker[2].red; k2g = ker[2].green; k2b = ker[2].blue;
        k3r = ker[3].red; k3g = ker[3].green; k3b = ker[3].blue;
        k4r = ker[4].red; k4g = ker[4].green; k4b = ker[4].blue;
        k5r = ker[5].red; k5g = ker[5].green; k5b = ker[5].blue;
        k6r = ker[6].red; k6g = ker[6].green; k6b = ker[6].blue;
        k7r = ker[7].red; k7g = ker[7].green; k7b = ker[7].blue;
        for (j = 0; j < size; j++) { 
            dst[n1] += src[n1].red * k0r + src[n1].green * k0g + src[n1].blue * k0b+
            src[n1 + 1].red * k1r + src[n1 + 1].green * k1g + src[n1 + 1].blue * k1b +
            src[n1 + 2].red * k2r + src[n1 + 2].green * k2g + src[n1 + 2].blue * k2b +
            src[n1 + 3].red * k3r + src[n1 + 3].green * k3g + src[n1 + 3].blue * k3b +
            src[n1 + 4].red * k4r + src[n1 + 4].green * k4g + src[n1 + 4].blue * k4b +
            src[n1 + 5].red * k5r + src[n1 + 5].green * k5g + src[n1 + 5].blue * k5b +
            src[n1 + 6].red * k6r + src[n1 + 6].green * k6g + src[n1 + 6].blue * k6b +
            src[n1 + 7].red * k7r + src[n1 + 7].green * k7g + src[n1 + 7].blue * k7b;
            n1++;
        }
        zet = dim + n;
        n2 = n;
        
        k0r = ker[8].red; k0g = ker[8].green; k0b = ker[8].blue;
        k1r = ker[9].red;k1g = ker[9].green;k1b = ker[9].blue;
        k2r = ker[10].red;k2g = ker[10].green;k2b = ker[10].blue;
        k3r = ker[11].red;k3g = ker[11].green;k3b = ker[11].blue;
        k4r = ker[12].red;k4g = ker[12].green;k4b = ker[12].blue;
        k5r = ker[13].red;k5g = ker[13].green;k5b = ker[13].blue;
        k6r = ker[14].red;k6g = ker[14].green;k6b = ker[14].blue;
        k7r = ker[15].red;k7g = ker[15].green;k7b = ker[15].blue;
        for(j = 0; j < size; j++){
            dst[n2] += src[zet].red * k0r+ src[zet].green * k0g + src[zet].blue * k0b +
            src[zet + 1].red * k1r+ src[zet + 1].green * k1g + src[zet + 1].blue * k1b+
            src[zet + 2].red * k2r+ src[zet + 2].green * k2g + src[zet + 2].blue * k2b+
            src[zet + 3].red * k3r+ src[zet + 3].green * k3g + src[zet + 3].blue * k3b+
            src[zet + 4].red * k4r+ src[zet + 4].green * k4g + src[zet + 4].blue * k4b+
            src[zet + 5].red * k5r+ src[zet + 5].green * k5g + src[zet + 5].blue * k5b+
            src[zet + 6].red * k6r+ src[zet + 6].green * k6g + src[zet + 6].blue * k6b+
            src[zet + 7].red * k7r+ src[zet + 7].green * k7g + src[zet + 7].blue *k7b;
            n2++;
            zet++;
        }
        zet = (dim << 1) + n; 
        n3 = n;

        k0r = ker[16].red; k0g = ker[16].green;  k0b = ker[16].blue;
        k1r = ker[17].red; k1g = ker[17].green; k1b = ker[17].blue;
        k2r = ker[18].red; k2g = ker[18].green; k2b = ker[18].blue;
        k3r = ker[19].red; k3g = ker[19].green; k3b = ker[19].blue;
        k4r = ker[20].red; k4g = ker[20].green; k4b = ker[20].blue;
        k5r = ker[21].red; k5g = ker[21].green; k5b = ker[21].blue;
        k6r = ker[22].red; k6g = ker[22].green; k6b = ker[22].blue;
        k7r = ker[23].red; k7g = ker[23].green; k7b = ker[23].blue;
        for (j = 0; j < size; j++) {
            dst[n3] += src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b +
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b +
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b +
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b +
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b +
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b +
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b +
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue *k7b;
            n3++;
            zet++;
        }
        zet = (dim << 1) + dim + n;
        n4 = n;

        k0r = ker[24].red; k0g = ker[24].green; k0b = ker[24].blue;
        k1r = ker[25].red; k1g = ker[25].green; k1b = ker[25].blue;
        k2r = ker[26].red; k2g = ker[26].green; k2b = ker[26].blue;
        k3r = ker[27].red; k3g = ker[27].green; k3b = ker[27].blue;
        k4r = ker[28].red; k4g = ker[28].green; k4b = ker[28].blue;
        k5r = ker[29].red; k5g = ker[29].green; k5b = ker[29].blue;
        k6r = ker[30].red; k6g = ker[30].green; k6b = ker[30].blue;
        k7r = ker[31].red; k7g = ker[31].green; k7b = ker[31].blue;
        for(int j = 0; j < size; j++){
            dst[n4] += src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b + 
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b + 
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b + 
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b + 
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b + 
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b + 
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b + 
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue * k7b; 
            n4++;
            zet++;
        }
        zet = (dim << 2) + n;
        n5 = n; 

        k0r = ker[32].red;k0g = ker[32].green; k0b = ker[32].blue;
        k1r = ker[33].red;k1g = ker[33].green;k1b = ker[33].blue;
        k2r = ker[34].red;k2g = ker[34].green;k2b = ker[34].blue;
        k3r = ker[35].red;k3g = ker[35].green;k3b = ker[35].blue;
        k4r = ker[36].red;k4g = ker[36].green;k4b = ker[36].blue;
        k5r = ker[37].red;k5g = ker[37].green;k5b = ker[37].blue;
        k6r = ker[38].red;k6g = ker[38].green;k6b = ker[38].blue;
        k7r = ker[39].red;k7g = ker[39].green;k7b = ker[39].blue;
        for(j = 0;j < size; j++){
            dst[n5] += src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b + 
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b + 
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b + 
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b + 
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b + 
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b + 
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b + 
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue * k7b; 
            n5++;
            zet++;
        }
        zet = (dim << 2) + dim + n;
        n6 = n;

        k0r = ker[40].red; k0g = ker[40].green;  k0b = ker[40].blue;
        k1r = ker[41].red; k1g = ker[41].green; k1b = ker[41].blue;
        k2r = ker[42].red; k2g = ker[42].green; k2b = ker[42].blue;
        k3r = ker[43].red; k3g = ker[43].green; k3b = ker[43].blue;
        k4r = ker[44].red; k4g = ker[44].green; k4b = ker[44].blue;
        k5r = ker[45].red; k5g = ker[45].green; k5b = ker[45].blue;
        k6r = ker[46].red; k6g = ker[46].green; k6b = ker[46].blue;
        k7r = ker[47].red; k7g = ker[47].green; k7b = ker[47].blue;
        for(j = 0;j<size;j++){
            dst[n6] += src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b+
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b+
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b+
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b+
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b+
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b+
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b+
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue * k7b;
            n6++;
            zet++;
        }
        zet = 6 * dim + n; 
        n7 = n;

        k0r = ker[48].red; k0g = ker[48].green;  k0b = ker[48].blue;
        k1r = ker[49].red; k1g = ker[49].green; k1b = ker[49].blue;
        k2r = ker[50].red; k2g = ker[50].green; k2b = ker[50].blue;
        k3r = ker[51].red; k3g = ker[51].green; k3b = ker[51].blue;
        k4r = ker[52].red; k4g = ker[52].green; k4b = ker[52].blue;
        k5r = ker[53].red; k5g = ker[53].green; k5b = ker[53].blue;
        k6r = ker[54].red; k6g = ker[54].green; k6b = ker[54].blue;
        k7r = ker[55].red; k7g = ker[55].green; k7b = ker[55].blue;
        for(j=0 ; j< size;j++){
            dst[n7] += src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b+
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b+
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b+
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b+
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b+
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b+
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b+
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue *k7b;
            n7++;
            zet++;
        }
        zet = (dim << 3) - dim + n;
        n8 = n;

        k0r = ker[56].red; k0g = ker[56].green; k0b = ker[56].blue;
        k1r = ker[57].red; k1g = ker[57].green; k1b = ker[57].blue;
        k2r = ker[58].red; k2g = ker[58].green; k2b = ker[58].blue;
        k3r = ker[59].red; k3g = ker[59].green; k3b = ker[59].blue;
        k4r = ker[60].red; k4g = ker[60].green; k4b = ker[60].blue;
        k5r = ker[61].red; k5g = ker[61].green; k5b = ker[61].blue;
        k6r = ker[62].red; k6g = ker[62].green; k6b = ker[62].blue;
        k7r = ker[63].red; k7g = ker[63].green; k7b = ker[63].blue;
        for(j=0;j<size;j++){
            dst[n8] += src[zet].red * k0r + src[zet].green * k0g + src[zet].blue * k0b +
            src[zet + 1].red * k1r + src[zet + 1].green * k1g + src[zet + 1].blue * k1b +
            src[zet + 2].red * k2r + src[zet + 2].green * k2g + src[zet + 2].blue * k2b +
            src[zet + 3].red * k3r + src[zet + 3].green * k3g + src[zet + 3].blue * k3b +
            src[zet + 4].red * k4r + src[zet + 4].green * k4g + src[zet + 4].blue * k4b +
            src[zet + 5].red * k5r + src[zet + 5].green * k5g + src[zet + 5].blue * k5b +
            src[zet + 6].red * k6r + src[zet + 6].green * k6g + src[zet + 6].blue * k6b +
            src[zet + 7].red * k7r + src[zet + 7].green * k7g + src[zet + 7].blue * k7b; 
            n8++;
            zet++;
        }

        m += dim;
    }
}

/*
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Convolution: Current working version";
void convolution(int dim, pixel *src, pixel *ker, unsigned *dst)
{

    unsigned i,j,k,sum,src_index=0;

    for(i = 0; i < dim-8+1; i++) {
        for(j = 0; j < dim-8+1; j++) {
            sum = 0;
            for(k = 0; k < 64; k++) {
                sum += src[src_index].red * ker[k].red;
                sum += src[src_index].green * ker[k].green;
                sum += src[src_index].blue * ker[k].blue;
                src_index += ((k & 7) == 7 ? dim-7 : 1);
            }
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
    add_conv_function(&bahadir_convolution,bahadir_convolution_descr);
    add_conv_function(&bahadir_convolutionV3,bahadir_convolution_descrV3);
    add_conv_function(&bahadir_convolutionV4,bahadir_convolution_descrV4);
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

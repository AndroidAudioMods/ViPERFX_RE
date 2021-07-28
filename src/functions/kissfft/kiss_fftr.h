// Replacement for ffts which is not as cross-platform

#pragma once

#include "kiss_fft.h"

/*

 Real optimized version can save about 45% cpu time vs. complex fft of a real seq.

 */

typedef struct kiss_fftr_state *kiss_fftr_cfg;


kiss_fftr_cfg kiss_fftr_alloc(int nfft,int inverse_fft,void * mem = nullptr, size_t * lenmem = nullptr);
/*
 nfft must be even

 If you don't care to allocate space, use mem = lenmem = NULL
*/


void kiss_fftr(kiss_fftr_cfg cfg,const double *timedata,kiss_fft_cpx *freqdata);
/*
 input timedata has nfft scalar points
 output freqdata has nfft/2+1 complex points
*/

void kiss_fftri(kiss_fftr_cfg cfg,const kiss_fft_cpx *freqdata,double *timedata);
/*
 input freqdata has  nfft/2+1 complex points
 output timedata has nfft scalar points
*/

#define kiss_fftr_free free

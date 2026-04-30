//
// Created by mv2-mavhaire on 30/04/2026.
//


#ifndef WAVEFORM_H
#define WAVEFORM_H
/*
 * waveform.h
 */
#include <stddef.h>// gives us size_t
#include <stdint.h> //gives us uint8_t

#define NOMINAL_RMS_VOLTAGE 230.0// expected RMS voltage for each phase

typedef struct{
    double timestamp;
    double phaseA;
    double phaseB;
    double phaseC;
    double current;
    double frequency;
    double powerFactor;
    double thd;
} WaveformSample;


#endif

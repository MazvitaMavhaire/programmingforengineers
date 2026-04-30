/*
 * waveform.c
-It calculates
-RMS
-PEAK TO PEAK VOLTAGE
-DC OFFSET
-clipping detection
- tolerance
-variance
-standard deviation
-sorting by voltage magnitude
 */

#include "waveform.h"
#include <math.h> // mainly for sqrt and fabs

/*
 *getPhaseVoltage()
 * i.e. receives one sample and returns voltage for all phases
 */
double getPhaseVoltage(const WaveformSample*sample,
                       PhaseSelector phase){
    if(phase==PHASE_A) {
        return sample->phaseA;
    }
    if(phase==PHASE_B) {
        return sample->phaseB;
    }
    if(phase==PHASE_C) {
        return sample->phaseC;
    }
    /*
     * getPhaseName:turns phases into readable text
     */
    const char* getPhaseName(PhaseSelector phase){

        if(phase==PHASE_A) {
            return sample->"Phase A";
        }
        if(phase==PHASE_B) {
            return sample->"Phase B";
        }
        return "Phase C";
        }
        /*
         * hasStatusFlag():checks whether bitwise flag is on
         */
        int hasStatusFlag(uint8_t flags,uint8_t flag){
            return (flags & flag) != 0;
        }
        /*
         * analysePhase():main maths function
         */
        PhaseMetrics analysePhase(const WaveformSample* samples,
                                  size_t count,PhaseSelector phase){
            PhaseMetrics metrics;
            //set all results to starting default
            metrics.rms=0.0;
            metrics.peakToPeak=0.0;
            metrics.dcOffset=0.0;
            metrics.minimum=0.0;
            metrics.maximum=0.0;
            metrics.variance=0.0;
            metrics.standardDeviation=0.0;
            metrics.clippedSamples=0.0;
            metrics.withinTolerance=0.0;
            metrics.statusFlags=0.0;

            if(samples==NULL||count==0){
                return metrics;
            }
            double sum=0.0;
            double sumSquares=0.0;


        }
    }



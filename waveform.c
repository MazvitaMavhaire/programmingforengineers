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
#include<stdlib.h>
#include <lmaccess.h>
#include <rpcndr.h>

/*
 *getPhaseVoltage()
 * i.e. receives one sample and returns voltage for all phases
 *
 *
 */ double getPhaseVoltage(const WaveformSample*sample,
                           size_t count,PhaseSelector phase){
    if(phase==PHASE_A) {return sample->phaseA;
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
    const char* getPhaseName(PhaseSelector phase);
{       if(phase==PHASE_A) {
            return sample->phaseA;
        }
        if(phase==PHASE_B) {
            return sample->phaseB;
        }
        return sample->phaseC;
        }
     /*
         * hasStatusFlag():checks whether bitwise flag is on
         */
        int hasStatusFlag(uint8_t flags,uint8_t flag);
{           return (uint8_t flags,uint8_t flag)!=0;
        }
        /*
         * analysePhase():main maths function
         */
        PhaseMetrics analysePhase(const WaveformSample* sample,
                                  size_t count,PhaseSelector phase);
{          PhaseMetrics metrics;
            //set all results to starting default
            metrics.rms = 0.0;
            metrics.peakToPeak = 0.0;
            metrics.dcOffset = 0.0;
            metrics.minimum = 0.0;
            metrics.maximum = 0.0;
            metrics.variance = 0.0;
            metrics.standardDeviation = 0.0;
            metrics.clippedSamples = 0.0;
            metrics.withinTolerance = 0.0;
            metrics.statusFlags = 0.0;

            if (sample == NULL || count == 0) {
                return metrics;
            }
            double sum = 0.0;
            double sumSquares = 0.0;
            //First voltage is starting min and max
            double firstVoltage = getPhaseVoltage(sample, phase, (PhaseSelector) &count);
            double minVoltage = firstVoltage;
            double maxVoltage = firstVoltage;
            /*
             *first pass -calculate sum > calculate sum of square> find min and max>detect clipping
             */
            for (size_t i = 0; i < count; i++) {
                //pointer to sample i
                const WaveformSample *currentSample = sample + i;
                double voltage = getPhaseVoltage(currentSample, phase,&count);

                sum += voltage;
                sumSquares += voltage * voltage;

                if (voltage < minVoltage) {
                    minVoltage = voltage;
                }
                if (voltage > maxVoltage) {
                    maxVoltage = voltage;
                }
                if (fabs(voltage) >= CLIPPING_LIMIT) {
                    metrics.clippedSamples++;
                }

            }
            metrics.dcOffset = sum / count;
            metrics.rms = sqrt(sumSquares / count);
            metrics.minimum = minVoltage;
            metrics.maximum = maxVoltage;
            metrics.peakToPeak = maxVoltage - minVoltage;
            /*
             * second pass: mean
             */
            double varianceSum = 0.0;

            for (size_t i = 0; i < count; i++) {

                const WaveformSample *currentSample = sample + i;
                double voltage = getPhaseVoltage(currentSample,phase,&count);

                double difference = voltage - metrics.dcOffset;
                varianceSum += difference * difference;
            }
            metrics.variance = varianceSum / count;
            metrics.standardDeviation = sqrt(metrics.variance);
            //RMS range
            double lowerLimit=NOMINAL_RMS_VOLTAGE * 0.90;
            double upperLimit = NOMINAL_RMS_VOLTAGE * 1.10;

            if (metrics.rms >= lowerLimit && metrics.rms <= upperLimit) {
                metrics.withinTolerance = 1;
            } else {
                metrics.withinTolerance = 0;
                metrics.statusFlags |= STATUS_OUT_OF_TOLERANCE;
            }
            if (metrics.clippedSamples > 0) {
                metrics.statusFlags |= STATUS_CLIPPING;
            }
            return metrics;
            /*
             * sortSamplesByVoltageMagnitude()
                This sorts samples from largest voltage magnitude to smallest.
                  Magnitude means absolute value.
                  */

                 void sortSamplesByVoltageMagnitude(WaveformSample *samples,
                                               size_t count,PhaseSelector phase){
                if (samples == NULL || count == 0){
                    return;
                }
                for (size_t i = 1; i < count; i++) {
                    WaveformSample key = samples[i];
                    double keyMagnitude = fabs(getPhaseVoltage(&key, phase));
                    size_t j=i;

                    while (j > 0) {
                        double previousMagnitude =fabs(getPhaseVoltage(&samples[j - 1], phase));
                        if (previousMagnitude >= keyMagnitude) {
                            break;
                        }
                        samples[j] = samples[j - 1];
                        j--;
                    }
                    samples[j] = key
}
}
        }




}
#include "pP_config.h"
#include <EEPROM.h>

int GAIN_FACTOR = GAIN_FACTOR_DEFAULT; // Gain adjustment factor. 0=3x, 1=3.5x, 2=4.33x, 3=6x, 4=11x
int followerThrs = FOLLOWER_THRESHOLD_DEFAULT;
int compThrs = COMP_THRESHOLD_DEFAULT;
int LOOP_DUR = LOOP_DUR_DEFAULT; // duration of time between ADC checks and other loop functions
int TRG_DUR = TRG_DUR_DEFAULT;   // duration of the Z-axis pulse sent, in ms
int Hyst = HYST_DEFAULT;         // Hysteresis value for ADC measurements
int Debug = 0;

void resetEEPROM() {
    resetConfig();
    EEPROM.put(GAIN_FACTOR_ADDRESS, GAIN_FACTOR);
    EEPROM.put(FOLLOWER_THRESHOLD_ADDRESS, followerThrs);
    EEPROM.put(COMP_THRESHOLD_ADDRESS, compThrs);
    EEPROM.put(LOOP_DUR_ADDRESS, LOOP_DUR);
    EEPROM.put(TRG_DUR_ADDRESS, TRG_DUR);
    EEPROM.put(HYST_ADDRESS, Hyst);
    EEPROM.put(VM_CONST_ADDRESS, voltMeterConstant);
}

// Restore config from EEPROM, otherwise reset config and write to EEPROM
void restoreConfig() {
    int temp;

    EEPROM.get(GAIN_FACTOR_ADDRESS, temp);
    if (temp < 0 || temp > 4) {
        resetEEPROM();
    } else {
        GAIN_FACTOR = temp;
    }

    EEPROM.get(FOLLOWER_THRESHOLD_ADDRESS, temp);
    if (temp < 0 || temp > 5000) {
        resetEEPROM();
    } else {
        followerThrs = temp;
    }

    EEPROM.get(COMP_THRESHOLD_ADDRESS, temp);
    if (temp < 0 || temp > 5000) {
        resetEEPROM();
    } else {
        compThrs = temp;
    }

    EEPROM.get(LOOP_DUR_ADDRESS, temp);
    if (temp < 0 && temp > 1000) {
        resetEEPROM();
    } else {
        LOOP_DUR = temp;
    }

    EEPROM.get(TRG_DUR_ADDRESS, temp);
    if (temp < 0 || temp > 1000) {
        resetEEPROM();
    } else {
        TRG_DUR = temp;
    }

    EEPROM.get(HYST_ADDRESS, temp);
    if (temp < 0 || temp > 1000) {
        resetEEPROM();
    } else {
        Hyst = temp;
    }
}

void resetConfig() {
    GAIN_FACTOR = GAIN_FACTOR_DEFAULT;
    followerThrs = FOLLOWER_THRESHOLD_DEFAULT;
    compThrs = COMP_THRESHOLD_DEFAULT;
    LOOP_DUR = LOOP_DUR_DEFAULT;
    TRG_DUR = TRG_DUR_DEFAULT;
    Hyst = HYST_DEFAULT;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <chrono>

#include "fmod.hpp"
#include "fmod_errors.h"

#include "AudioEngine.h"

void errorCheck(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        std::exit(-1);
    }
}


int main()
{
    AudioEngine audioEngine;
    audioEngine.init();
    std::string soundpath = "samples/Breakout_Theme.wav";
    std::string boop = "samples/boop_13.wav";
    std::string beep = "samples/beep_06.wav";
    audioEngine.loadSound(soundpath, false, true);
    audioEngine.loadSound(boop);
    audioEngine.loadSound(beep);

    unsigned int ms = 0;
    unsigned int length = audioEngine.getSoundLengthInMS(soundpath);
    bool glassfirst = true;
    bool boopfirst = true;
    bool beepfirst = true;
    while (ms < (length * 2))
    {
        
        static auto start = std::chrono::high_resolution_clock::now();

        if (glassfirst) { audioEngine.playSound(soundpath, audioEngine.volumeTodB(.25f)); glassfirst = false; }

        if (boopfirst && ms >= 2000) { audioEngine.playSound(boop, audioEngine.volumeTodB(1.f)); boopfirst = false; }
                                                    
        if (beepfirst && ms >= 4000) { audioEngine.playSound(beep, audioEngine.volumeTodB(1.f)); beepfirst = false; }


        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
        ms = static_cast<unsigned int>(int_ms.count());
    }
}

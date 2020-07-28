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
    std::string soundpath = "samples/glass_testubes_rattle_02.wav";
    audioEngine.loadSound(soundpath);
    while (true)
    {
        audioEngine.playSound(soundpath, glm::vec3{ 0.f }, audioEngine.volumeTodB(1.f));
    }
}

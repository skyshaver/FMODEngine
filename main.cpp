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
    //FMOD_RESULT result;
    //FMOD::System* system = nullptr;

    //result = FMOD::System_Create(&system);      // Create the main system object.
    //errorCheck(result);

    //result = system->init(512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
    //errorCheck(result);


    //FMOD::Sound* sound;
    //FMOD::Channel* channel = 0;

    //result = system->createSound(
    //    "samples/glass_testubes_rattle_02.wav",
    //    FMOD_DEFAULT,
    //    0,
    //    &sound
    //);
    //errorCheck(result);

    //unsigned int lenms = 0, ms = 0;
    //
    //result = sound->getLength(&lenms, FMOD_TIMEUNIT_MS);
    //errorCheck(result);

    //printf("Length of sound: %d", lenms);
    //
    //
    //while (ms <= lenms) 
    //{
    //    static auto start = std::chrono::high_resolution_clock::now();
    //    result = system->playSound(
    //        sound,
    //        0,
    //        false,
    //        &channel
    //    );
    //    errorCheck(result);
    //    //std::chrono::duration<double> elapsed_seconds = std::chrono::high_resolution_clock::now() - start;
    //    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
    //    ms = static_cast<unsigned int>(int_ms.count());
    //    // result = channel->getPosition(&ms, FMOD_TIMEUNIT_MS);
    //    
    //    // errorCheck(result);
    //    
    //    //channel->isPlaying(&isPlaying);
    //    //std::cout << std::boolalpha << ms << '\n';
    //}

    //sound->release();

    AudioEngine audioEngine;
    audioEngine.init();
    std::string soundpath = "samples/glass_testubes_rattle_02.wav";
    audioEngine.loadSound(soundpath);
    while (true)
    {
        audioEngine.playSound(soundpath, glm::vec3{ 0.f }, audioEngine.volumeTodB(1.f));
    }
}

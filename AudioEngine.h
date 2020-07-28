#pragma once

#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <iostream>
#include <memory>

#include "fmod_studio.hpp"
#include "fmod.hpp"

#include "glm/glm.hpp"


struct Vector3 // replace with glm::vec3?
{
    float x;
    float y;
    float z;
};

struct Implementation 
{
    Implementation();
    ~Implementation();

    void update();

    FMOD::Studio::System* studioSystem;
    FMOD::System* system;

    int nextChannelId = 0;

    using SoundMap = std::map<std::string, FMOD::Sound*>;
    using ChannelMap = std::map<int, FMOD::Channel*>;
    using EventMap = std::map<std::string, FMOD::Studio::EventInstance*>;
    using BankMap = std::map<std::string, FMOD::Studio::Bank*>;

    BankMap banks;
    EventMap events;
    SoundMap sounds;
    ChannelMap channels;
};


class AudioEngine
{
public:
    static void init();
    static void update();
    static void shutdown();
    static int errorCheck(FMOD_RESULT result);

    void loadBank(const std::string& bankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags);
    void loadEvent(const std::string& eventName);
    void loadSound(const std::string& soundName, bool is3D = true, bool isLooping = false, bool isStream = false);
    void unLoadSound(const std::string& strSoundName);

    // void set3dListenerAndOrientation(const Vector3& vPos = Vector3{ 0, 0, 0 }, float fVolumedB = 0.0f);

    int playSound(const std::string& soundName, const glm::vec3 pos = { 0, 0, 0 }, float volumedB = 0.0f);
    void playEvent(const std::string& eventName);
    // void stopChannel(int nChannelId);
    void stopEvent(const std::string& eventName, bool isImmediate = false);
    void geteventParameter(const std::string& eventName, const std::string& eventParameter, float* parameter);
    void setEventParameter(const std::string& eventName, const std::string& parameterName, float value);
    // void stopAllChannels();

    void setChannel3dPosition(int channelId, const glm::vec3& pos);
    void setChannelVolume(int channelId, float volumedB);
    // bool isPlaying(int nChannelId) const;
    bool isEventPlaying(const std::string& eventName) const;
    float dBToVolume(float dB);
    float volumeTodB(float volume);

    FMOD_VECTOR vectorToFmod(const glm::vec3& pos);

    //static std::unique_ptr<Implementation> implementation;

};


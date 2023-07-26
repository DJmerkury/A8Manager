#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

template <typename T>
struct ParameterSpec
{
    T min;
    T max;
    T dflt;
};

using ParameterSpecInt = ParameterSpec<int>;
using ParameterSpecFloat = ParameterSpec<float>;
using ParameterSpecString = ParameterSpec<juce::String>;
using AmountAndCvInput = std::tuple<juce::String, float>;

class Assimil8orZoneProperties : public ValueTreeWrapper
{
public:
    Assimil8orZoneProperties () noexcept : ValueTreeWrapper (ZoneTypeId) {}

    void setLevelOffset (float levelOffset, bool includeSelfCallback);
    void setLoopLength (float loopLength, bool includeSelfCallback);
    void setLoopStart (int loopStart, bool includeSelfCallback);
    void setMinVoltage (float minVoltage, bool includeSelfCallback);
    void setPitchOffset (float pitchOffset, bool includeSelfCallback);
    void setSample (juce::String sampleFileName, bool includeSelfCallback);
    void setSampleStart (int sampleStart, bool includeSelfCallback);
    void setSampleEnd (int sampleEnd, bool includeSelfCallback);
    void setSide (int side, bool includeSelfCallback);

    float getLevelOffset ();
    float getLoopLength ();
    int getLoopStart ();
    float getMinVoltage ();
    float getPitchOffset ();
    juce::String getSample ();
    int getSampleStart ();
    int getSampleEnd ();
    int getSide ();

    std::function<void (float levelOffset)> onLevelOffsetChange;
    std::function<void (float loopLength)> onLoopLengthChange;
    std::function<void (int loopStart)> onLoopStartChange;
    std::function<void (float minVoltage)> onMinVoltageChange;
    std::function<void (float pitchOffset)> onPitchOffsetChange;
    std::function<void (juce::String sampleFileName)> onSampleChange;
    std::function<void (int sampleStart)> onSampleStartChange;
    std::function<void (int sampleEnd)> onSampleEndChange;
    std::function<void (int side)> onSideChange;

    static inline const juce::Identifier ZoneTypeId { "Zone" };
    static inline const juce::Identifier LevelOffsetPropertyId { "levelOffset" };
    static inline const juce::Identifier LoopLengthPropertyId  { "loopLength" };
    static inline const juce::Identifier LoopStartPropertyId   { "loopStart" };
    static inline const juce::Identifier MinVoltagePropertyId  { "minVoltage" };
    static inline const juce::Identifier PitchOffsetPropertyId { "pitchOffset" };
    static inline const juce::Identifier SamplePropertyId      { "sample" };
    static inline const juce::Identifier SampleStartPropertyId { "sampleStart" };
    static inline const juce::Identifier SampleEndPropertyId   { "sampleEnd" };
    static inline const juce::Identifier SidePropertyId        { "side" };

private:
    void initValueTree () override;

    void valueTreePropertyChanged (juce::ValueTree& vt, const juce::Identifier& property) override;
};

class Assimil8orChannelProperties : public ValueTreeWrapper
{
public:
    Assimil8orChannelProperties () noexcept : ValueTreeWrapper (ChannelTypeId) {}

    void setAliasing (int aliasing, bool includeSelfCallback);
    void setAliasingMod (juce::String cvInput, float aliasingMod, bool includeSelfCallback);
    void setAttack (float attack, bool includeSelfCallback);
    void setAttackFromCurrent (int attackFromCurrent, bool includeSelfCallback);
    void setAttackMod (juce::String cvInput, float attackMod, bool includeSelfCallback);
    void setAutoTrigger (bool autoTrigger, bool includeSelfCallback);
    void setBits (float bits, bool includeSelfCallback);
    void setBitsMod (juce::String cvInput, float bitsMod, bool includeSelfCallback);
    void setChannelMode (int channelMode, bool includeSelfCallback);
    void setExpAM (float expAM, bool includeSelfCallback);
    void setExpFM (float expFM, bool includeSelfCallback);
    void setLevel (float level, bool includeSelfCallback);
    void setLinAM (float linAM, bool includeSelfCallback);
    void setLinAMisExtEnv (bool linAMisExtEnv, bool includeSelfCallback);
    void setLinFM (float linFM, bool includeSelfCallback);
    void setLoopLengthMod (juce::String cvInput, float loopLengthMod, bool includeSelfCallback);
    void setLoopMode (int loopMode, bool includeSelfCallback);
    void setLoopStartMod (juce::String cvInput, float loopStartMod, bool includeSelfCallback);
    void setMixLevel (float mixLevel, bool includeSelfCallback);
    void setMixMod (juce::String cvInput, float mixMod, bool includeSelfCallback);
    void setMixModIsFader (bool mixModIsFader, bool includeSelfCallback);
    void setPan (float pan, bool includeSelfCallback);
    void setPanMod (juce::String cvInput, float panMod, bool includeSelfCallback);
    void setPhaseCV (juce::String cvInput, float phaseCV, bool includeSelfCallback);
    void setPitch (float pitch, bool includeSelfCallback);
    void setPitchCV (juce::String cvInput, float pitchCV, bool includeSelfCallback);
    void setPlayMode (int PlayMode, bool includeSelfCallback);
    void setPMIndex (float pMIndex, bool includeSelfCallback);
    void setPMIndexMod (juce::String cvInput, float pMIndexMod, bool includeSelfCallback);
    void setPMSource (int pMSource, bool includeSelfCallback);
    void setRelease (float release, bool includeSelfCallback);
    void setReleaseMod (juce::String cvInput, float releaseMod, bool includeSelfCallback);
    void setReverse (bool reverse, bool includeSelfCallback);
    void setSampleStartMod (juce::String cvInput, float sampleStartMod, bool includeSelfCallback);
    void setSampleEndMod (juce::String cvInput, float sampleEndMod, bool includeSelfCallback);
    void setSpliceSmoothing (bool spliceSmoothing, bool includeSelfCallback);
    void setXfadeGroup (juce::String cvInput, float xfadeGroup, bool includeSelfCallback);
    void setZonesCV (juce::String zonesCV, bool includeSelfCallback);
    void setZonesRT (int zonesRT, bool includeSelfCallback);

    int getAliasing ();
    AmountAndCvInput getAliasingMod ();
    float getAttack ();
    int getAttackFromCurrent ();
    AmountAndCvInput getAttackMod ();
    bool getAutoTrigger ();
    float getBits ();
    AmountAndCvInput getBitsMod ();
    int getChannelMode ();
    float getExpAM ();
    float getExpFM ();
    float getLevel ();
    float getLinAM ();
    bool getLinAMisExtEnv ();
    float getLinFM ();
    AmountAndCvInput getLoopLengthMod ();
    int getLoopMode ();
    AmountAndCvInput getLoopStartMod ();
    float getMixLevel ();
    AmountAndCvInput getMixMod ();
    bool getMixModIsFader ();
    float getPan ();
    AmountAndCvInput getPanMod ();
    AmountAndCvInput getPhaseCV ();
    float getPitch ();
    AmountAndCvInput getPitchCV ();
    int getPlayMode ();
    float getPMIndex ();
    AmountAndCvInput getPMIndexMod ();
    int getPMSource ();
    float getRelease ();
    AmountAndCvInput getReleaseMod ();
    bool getReverse ();
    AmountAndCvInput getSampleStartMod ();
    AmountAndCvInput getSampleEndMod ();
    bool getSpliceSmoothing ();
    AmountAndCvInput getXfadeGroup ();
    juce::String getZonesCV ();
    int getZonesRT ();

    std::function<void (int aliasing)> onAliasingChange;
    std::function<void (juce::String cvInput, float aliasingMod)> onAliasingModChange;
    std::function<void (float attack)> onAttackChange;
    std::function<void (int attackFromCurrent)> onAttackFromCurrentChange;
    std::function<void (juce::String cvInput, float attackMod)> onAttackModChange;
    std::function<void (bool autoTrigger)> onAutoTriggerChange;
    std::function<void (float bits)> onBitsChange;
    std::function<void (juce::String cvInput, float bitsMod)> onBitsModChange;
    std::function<void (int channelMode)> onChannelModeChange;
    std::function<void (float expAM)> onExpAMChange;
    std::function<void (float expFM)> onExpFMChange;
    std::function<void (float level)> onLevelChange;
    std::function<void (float linAM)> onLinAMChange;
    std::function<void (bool linAMisExtEnv)> onLinAMisExtEnvChange;
    std::function<void (float linFM)> onLinFMChange;
    std::function<void (juce::String cvInput, float loopLengthMod)> onLoopLengthModChange;
    std::function<void (int loopMode)> onLoopModeChange;
    std::function<void (juce::String cvInput, float loopStartMod)> onLoopStartModChange;
    std::function<void (float mixLevel)> onMixLevelChange;
    std::function<void (juce::String cvInput, float mixMod)> onMixModChange;
    std::function<void (bool mixModIsFader)> onMixModIsFaderChange;
    std::function<void (float pan)> onPanChange;
    std::function<void (juce::String cvInput, float panMod)> onPanModChange;
    std::function<void (juce::String cvInput, float phaseCV)> onPhaseCVChange;
    std::function<void (float pitch)> onPitchChange;
    std::function<void (juce::String cvInput, float pitchCV)> onPitchCVChange;
    std::function<void (int PlayMode)> onPlayModeChange;
    std::function<void (float pMIndex)> onPMIndexChange;
    std::function<void (juce::String cvInput, float pMIndexMod)> onPMIndexModChange;
    std::function<void (int pMSource)> onPMSourceChange;
    std::function<void (float release)> onReleaseChange;
    std::function<void (juce::String cvInput, float releaseMod)> onReleaseModChange;
    std::function<void (bool reverse)> onReverseChange;
    std::function<void (juce::String cvInput, float sampleStartMod)> onSampleStartModChange;
    std::function<void (juce::String cvInput, float sampleEndMod)> onSampleEndModChange;
    std::function<void (bool spliceSmoothing)> onSpliceSmoothingChange;
    std::function<void (juce::String cvInput, float xfadeGroup)> onXfadeGroupChange;
    std::function<void (juce::String zonesCV)> onZonesCVChange;
    std::function<void (int zonesRT)> onZonesRTChange;

    void forEachZone (std::function<bool (juce::ValueTree zoneVT)> zoneVTCallback);

    static inline const juce::Identifier ChannelTypeId { "Channel" };
    static inline const juce::Identifier AliasingPropertyId          { "aliasing" };
    static inline const juce::Identifier AliasingModPropertyId       { "aliasingMod" };
    static inline const juce::Identifier AttackPropertyId            { "attack" };
    static inline const juce::Identifier AttackFromCurrentPropertyId { "attackFromCurrent" };
    static inline const juce::Identifier AttackModPropertyId         { "attackMod" };
    static inline const juce::Identifier AutoTriggerPropertyId       { "autoTrigger" };
    static inline const juce::Identifier BitsPropertyId              { "bits" };
    static inline const juce::Identifier BitsModPropertyId           { "bitsMod" };
    static inline const juce::Identifier ChannelModePropertyId       { "channelMode" };
    static inline const juce::Identifier ExpAMPropertyId             { "expAM" };
    static inline const juce::Identifier ExpFMPropertyId             { "expFM" };
    static inline const juce::Identifier LevelPropertyId             { "level" };
    static inline const juce::Identifier LinAMPropertyId             { "linAM" };
    static inline const juce::Identifier LinAMisExtEnvPropertyId     { "linAMisExtEnv" };
    static inline const juce::Identifier LinFMPropertyId             { "linFM" };
    static inline const juce::Identifier LoopLengthModPropertyId     { "loopLengthMod" };
    static inline const juce::Identifier LoopModePropertyId          { "loopMode" };
    static inline const juce::Identifier LoopStartModPropertyId      { "loopStartMod" };
    static inline const juce::Identifier MixLevelPropertyId          { "mixLevel" };
    static inline const juce::Identifier MixModPropertyId            { "mixMod" };
    static inline const juce::Identifier MixModIsFaderPropertyId     { "mixModIsFader" };
    static inline const juce::Identifier PanPropertyId               { "pan" };
    static inline const juce::Identifier PanModPropertyId            { "panMod" };
    static inline const juce::Identifier PhaseCVPropertyId           { "phaseCV" };
    static inline const juce::Identifier PitchPropertyId             { "pitch" };
    static inline const juce::Identifier PitchCVPropertyId           { "pitchCV" };
    static inline const juce::Identifier PlayModePropertyId          { "playMode" };
    static inline const juce::Identifier PMIndexPropertyId           { "pMIndex" };
    static inline const juce::Identifier PMIndexModPropertyId        { "pMIndexMod" };
    static inline const juce::Identifier PMSourcePropertyId          { "pMSource" };
    static inline const juce::Identifier ReleasePropertyId           { "release" };
    static inline const juce::Identifier ReleaseModPropertyId        { "releaseMod" };
    static inline const juce::Identifier ReversePropertyId           { "reverse" };
    static inline const juce::Identifier SampleStartModPropertyId    { "sampleStartMod" };
    static inline const juce::Identifier SampleEndModPropertyId      { "sampleEndMod" };
    static inline const juce::Identifier SpliceSmoothingPropertyId   { "spliceSmoothing" };
    static inline const juce::Identifier XfadeGroupPropertyId        { "xfadeGroup" };
    static inline const juce::Identifier ZonesCVPropertyId           { "zonesCV" };
    static inline const juce::Identifier ZonesRTPropertyId           { "zonesRT" };

private:
    void initValueTree () override;

    void valueTreePropertyChanged (juce::ValueTree& vt, const juce::Identifier& property) override;
};

class Assimil8orPresetProperties : public ValueTreeWrapper
{
public:
    Assimil8orPresetProperties () noexcept : ValueTreeWrapper (PresetTypeId) {}

    void setData2AsCV (bool data2AsCv, bool includeSelfCallback);
    void setName (juce::String name, bool includeSelfCallback);
    void setXFadeACV (juce::String cvInput, bool includeSelfCallback);
    void setXFadeAWidth (float width, bool includeSelfCallback);
    void setXFadeBCV (juce::String cvInput, bool includeSelfCallback);
    void setXFadeBWidth (float width, bool includeSelfCallback);
    void setXFadeCCV (juce::String cvInput, bool includeSelfCallback);
    void setXFadeCWidth (float width, bool includeSelfCallback);
    void setXFadeDCV (juce::String cvInput, bool includeSelfCallback);
    void setXFadeDWidth (float width, bool includeSelfCallback);

    bool getData2AsCV ();
    juce::String getName ();
    juce::String getXFadeACV ();
    float getXFadeAWidth ();
    juce::String getXFadeBCV ();
    float getXFadeBWidth ();
    juce::String getXFadeCCV ();
    float getXFadeCWidth ();
    juce::String getXFadeDCV ();
    float getXFadeDWidth ();

    std::function<void (bool data2AsCv)> onData2AsCVChange;
    std::function<void (juce::String name)> onNameChange;
    std::function<void (juce::String cvInput)> onXFadeACVChange;
    std::function<void (float width)> onXFadeAWidthChange;
    std::function<void (juce::String cvInput)> onXFadeBCVChange;
    std::function<void (float width)> onXFadeBWidthChange;
    std::function<void (juce::String cvInput)> onXFadeCCVChange;
    std::function<void (float width)> onXFadeCWidthChange;
    std::function<void (juce::String cvInput)> onXFadeDCVChange;
    std::function<void (float width)> onXFadeDWidthChange;

    void forEachChannel (std::function<bool (juce::ValueTree channelVT)> channelVTCallback);

    static inline const juce::Identifier PresetTypeId { "Preset" };
    static inline const juce::Identifier Data2asCVPropertyId   { "data2asCV" };
    static inline const juce::Identifier PresetNamePropertyId  { "name" };
    static inline const juce::Identifier XfadeACVPropertyId    { "xfadeACV" };
    static inline const juce::Identifier XfadeAWidthPropertyId { "xfadeAWidth" };
    static inline const juce::Identifier XfadeBCVPropertyId    { "xfadeBCV" };
    static inline const juce::Identifier XfadeBWidthPropertyId { "xfadeBWidth" };
    static inline const juce::Identifier XfadeCCVPropertyId    { "xfadeCCV" };
    static inline const juce::Identifier XfadeCWidthPropertyId { "xfadeCWidth" };
    static inline const juce::Identifier XfadeDCVPropertyId    { "xfadeDCV" };
    static inline const juce::Identifier XfadeDWidthPropertyId { "xfadeDWidth" };

private:
    void initValueTree () override;

    void valueTreePropertyChanged (juce::ValueTree& vt, const juce::Identifier& property) override;
};
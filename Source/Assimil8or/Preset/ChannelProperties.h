#pragma once

#include <JuceHeader.h>
#include <tuple>
#include "ZoneProperties.h"
#include "../../Utility/ValueTreeWrapper.h"

using AmountAndCvInput = std::tuple<juce::String, double>;

class ChannelProperties : public ValueTreeWrapper<ChannelProperties>
{
public:
    ChannelProperties () noexcept : ValueTreeWrapper (ChannelTypeId) {}
    ChannelProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks) noexcept
        : ValueTreeWrapper (ChannelTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setIndex (int index, bool includeSelfCallback);
    void setAliasing (int aliasing, bool includeSelfCallback);
    void setAliasingMod (juce::String cvInput, double aliasingMod, bool includeSelfCallback);
    void setAttack (double attack, bool includeSelfCallback);
    void setAttackFromCurrent (bool attackFromCurrent, bool includeSelfCallback);
    void setAttackMod (juce::String cvInput, double attackMod, bool includeSelfCallback);
    void setAutoTrigger (bool autoTrigger, bool includeSelfCallback);
    void setBits (double bits, bool includeSelfCallback);
    void setBitsMod (juce::String cvInput, double bitsMod, bool includeSelfCallback);
    void setChannelMode (int channelMode, bool includeSelfCallback);
    void setExpAM (double expAM, bool includeSelfCallback);
    void setExpFM (double expFM, bool includeSelfCallback);
    void setLevel (double level, bool includeSelfCallback);
    void setLinAM (double linAM, bool includeSelfCallback);
    void setLinAMisExtEnv (bool linAMisExtEnv, bool includeSelfCallback);
    void setLinFM (double linFM, bool includeSelfCallback);
    void setLoopLengthMod (juce::String cvInput, double loopLengthMod, bool includeSelfCallback);
    void setLoopMode (int loopMode, bool includeSelfCallback);
    void setLoopStartMod (juce::String cvInput, double loopStartMod, bool includeSelfCallback);
    void setMixLevel (double mixLevel, bool includeSelfCallback);
    void setMixMod (juce::String cvInput, double mixMod, bool includeSelfCallback);
    void setMixModIsFader (bool mixModIsFader, bool includeSelfCallback);
    void setPan (double pan, bool includeSelfCallback);
    void setPanMod (juce::String cvInput, double panMod, bool includeSelfCallback);
    void setPhaseCV (juce::String cvInput, double phaseCV, bool includeSelfCallback);
    void setPitch (double pitch, bool includeSelfCallback);
    void setPitchCV (juce::String cvInput, double pitchCV, bool includeSelfCallback);
    void setPlayMode (int PlayMode, bool includeSelfCallback);
    void setPMIndex (double pMIndex, bool includeSelfCallback);
    void setPMIndexMod (juce::String cvInput, double pMIndexMod, bool includeSelfCallback);
    void setPMSource (int pMSource, bool includeSelfCallback);
    void setRelease (double release, bool includeSelfCallback);
    void setReleaseMod (juce::String cvInput, double releaseMod, bool includeSelfCallback);
    void setReverse (bool reverse, bool includeSelfCallback);
    void setSampleStartMod (juce::String cvInput, double sampleStartMod, bool includeSelfCallback);
    void setSampleEndMod (juce::String cvInput, double sampleEndMod, bool includeSelfCallback);
    void setSpliceSmoothing (bool spliceSmoothing, bool includeSelfCallback);
    void setXfadeGroup (juce::String xfadeGroup, bool includeSelfCallback);
    void setZonesCV (juce::String zonesCV, bool includeSelfCallback);
    void setZonesRT (int zonesRT, bool includeSelfCallback);

    int getIndex ();
    int getAliasing ();
    AmountAndCvInput getAliasingMod ();
    double getAttack ();
    int getAttackFromCurrent ();
    AmountAndCvInput getAttackMod ();
    bool getAutoTrigger ();
    double getBits ();
    AmountAndCvInput getBitsMod ();
    int getChannelMode ();
    double getExpAM ();
    double getExpFM ();
    double getLevel ();
    double getLinAM ();
    bool getLinAMisExtEnv ();
    double getLinFM ();
    AmountAndCvInput getLoopLengthMod ();
    int getLoopMode ();
    AmountAndCvInput getLoopStartMod ();
    double getMixLevel ();
    AmountAndCvInput getMixMod ();
    bool getMixModIsFader ();
    double getPan ();
    AmountAndCvInput getPanMod ();
    AmountAndCvInput getPhaseCV ();
    double getPitch ();
    AmountAndCvInput getPitchCV ();
    int getPlayMode ();
    double getPMIndex ();
    AmountAndCvInput getPMIndexMod ();
    int getPMSource ();
    double getRelease ();
    AmountAndCvInput getReleaseMod ();
    bool getReverse ();
    AmountAndCvInput getSampleStartMod ();
    AmountAndCvInput getSampleEndMod ();
    bool getSpliceSmoothing ();
    juce::String getXfadeGroup ();
    juce::String getZonesCV ();
    int getZonesRT ();

    std::function<void (int index)> onIndexChange;
    std::function<void (int aliasing)> onAliasingChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onAliasingModChange;
    std::function<void (double attack)> onAttackChange;
    std::function<void (int attackFromCurrent)> onAttackFromCurrentChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onAttackModChange;
    std::function<void (bool autoTrigger)> onAutoTriggerChange;
    std::function<void (double bits)> onBitsChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onBitsModChange;
    std::function<void (int channelMode)> onChannelModeChange;
    std::function<void (double expAM)> onExpAMChange;
    std::function<void (double expFM)> onExpFMChange;
    std::function<void (double level)> onLevelChange;
    std::function<void (double linAM)> onLinAMChange;
    std::function<void (bool linAMisExtEnv)> onLinAMisExtEnvChange;
    std::function<void (double linFM)> onLinFMChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onLoopLengthModChange;
    std::function<void (int loopMode)> onLoopModeChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onLoopStartModChange;
    std::function<void (double mixLevel)> onMixLevelChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onMixModChange;
    std::function<void (bool mixModIsFader)> onMixModIsFaderChange;
    std::function<void (double pan)> onPanChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onPanModChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onPhaseCVChange;
    std::function<void (double pitch)> onPitchChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onPitchCVChange;
    std::function<void (int PlayMode)> onPlayModeChange;
    std::function<void (double pMIndex)> onPMIndexChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onPMIndexModChange;
    std::function<void (int pMSource)> onPMSourceChange;
    std::function<void (double release)> onReleaseChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onReleaseModChange;
    std::function<void (bool reverse)> onReverseChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onSampleStartModChange;
    std::function<void (AmountAndCvInput amountAndCvInput)> onSampleEndModChange;
    std::function<void (bool spliceSmoothing)> onSpliceSmoothingChange;
    std::function<void (juce::String cvInput)> onXfadeGroupChange;
    std::function<void (juce::String zonesCV)> onZonesCVChange;
    std::function<void (int zonesRT)> onZonesRTChange;

    juce::ValueTree addZone (int index);
    void forEachZone (std::function<bool (juce::ValueTree zoneVT)> zoneVTCallback);
    int getNumZones ();

    static juce::ValueTree create (int index);
    static juce::String getCvInputAndValueString (juce::String cvInput, double value, int decimalPlaces);
    static juce::String getCvInputAndValueString (AmountAndCvInput cvInputAndValue, int decimalPlaces);
    static AmountAndCvInput getCvInputAndValueFromString (juce::String cvInputAndValueString);

    static inline const juce::Identifier ChannelTypeId { "Channel" };
    static inline const juce::Identifier IndexPropertyId             { "_index" };
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

    void initValueTree ();
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& vt, const juce::Identifier& property) override;
};

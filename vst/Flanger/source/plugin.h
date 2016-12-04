#ifndef __plugin__
#define __plugin__
#include "pluginadapter.h"
#include "FlangerProcessor.h"

namespace Steinberg {
namespace Vst {
static const FUID PluginUID (0xD39D5B65, 0xD7AF42FA, 0x843F4AC8, 0x41EB04F0);

enum
{
	kFrequencyId = 0,
	kPhaseId,
	kDelayId,
	kDepthId
};



class Plugin : public PluginAdapter
{
public:
	Plugin();
	virtual ~Plugin(){}
	tresult PLUGIN_API initialize(FUnknown* context);
	tresult PLUGIN_API process(ProcessData& data);
	void startProcessing(int numChannels, SampleRate sampleRate);
	static FUnknown* createInstance(void*) { return (IAudioProcessor*)new Plugin(); }
private:
	int numChannels;
	SampleRate sampleRate;
private:
	FlangerProcessor leftProcessor;
	FlangerProcessor rightProcessor;
};

}} // namespaces

#endif //__plugin__

#ifndef __plugin__
#define __plugin__
#include "instrumentadapter.h"
#include "OscillatorProcessor.h"

namespace Steinberg {
namespace Vst {

// change these numbers!
// every plugin needs a unique UID
static const FUID InstrumentUID (0x89E0AE5F, 0x92154F53, 0x96FAE413, 0x3C935A18);

// define parameter tags here:
enum
{
	/** parameter ID */
	kGainId = 0
};


class Instrument : public InstrumentAdapter
{
public:
	Instrument ();
	virtual ~Instrument (){}
	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API process (ProcessData& data);
	void startProcessing(int numChannels, SampleRate sampleRate);	
	static FUnknown* createInstance (void*) { return (IAudioProcessor*)new Instrument (); }
private:
	int numChannels;
	SampleRate sampleRate;
	OscillatorProcessor leftProcessor;
	OscillatorProcessor rightProcessor;
};




}} // namespaces

#endif //__plugin__

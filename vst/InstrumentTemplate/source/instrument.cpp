#include "instrument.h"
#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/vst/ivstevents.h"
#include <math.h>
#include <stdio.h>

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
Instrument::Instrument ()
: numChannels(0)
, sampleRate(0)
{
}
//-----------------------------------------------------------------------------
// member function of PluginController!
// define parameter definitions here...
tresult PLUGIN_API Instrument::initialize (FUnknown* context){
	parameters.addParameter(new RangeParameter(STR16("Gain"), kGainId, STR16("dB"), -100, 6, 0));

	// fix for RangeParameter (default value is not yet set)
	for(int i = 0; i < parameters.getParameterCount(); i++){
		Parameter* p = parameters.getParameterByIndex(i);
		p->setNormalized(p->getInfo().defaultNormalizedValue);
	}
	return InstrumentAdapter::initialize(context);	
}


//-----------------------------------------------------------------------------
void Instrument::startProcessing(int numChannels, SampleRate sampleRate){
	this->numChannels = numChannels;
	this->sampleRate = sampleRate;
	leftProcessor.initialize(sampleRate);
	rightProcessor.initialize(sampleRate);
}
tresult PLUGIN_API Instrument::process (ProcessData& data)
{
	// MIDI Events aus der Liste aller Events für diesen Block auslesen
	IEventList* inputEvents = data.inputEvents;
	if (inputEvents != 0) {
		Event e;
		int32 numEvents = inputEvents->getEventCount ();
		for (int32 i = 0; i < numEvents; i++) {
			if (inputEvents->getEvent (i, e) == kResultTrue) {
				if (e.type == Event::kNoteOnEvent) {
					if (e.noteOn.noteId == -1) { // for host which don't send unique noteId's
						e.noteOn.noteId = e.noteOn.pitch;
					}
					leftProcessor.noteOn(e.noteOn.pitch, e.noteOn.velocity);
					rightProcessor.noteOn(e.noteOn.pitch, e.noteOn.velocity);
				}
				else if (e.type == Event::kNoteOffEvent) {
					if (e.noteOn.noteId == -1) { // for host which don't send unique noteId's
						e.noteOn.noteId = e.noteOn.pitch;
					}
					leftProcessor.noteOff();
					rightProcessor.noteOff();
				}
			}
		}
	}
    if (hasInputParameterChanged(data, kGainId)){
        float paramValue = getInputParameterChange(data, kGainId);
		float dB = 106 * paramValue - 100;
		float gain = pow(10, dB/20);
		leftProcessor.setGain(gain);
		rightProcessor.setGain(gain);
    }
 
	if (numChannels > 0){
		float* leftOutputChannel = data.outputs[0].channelBuffers32[0];
		leftProcessor.process(leftOutputChannel, data.numSamples);
	}
	if (numChannels > 1){
		float* rightOutputChannel = data.outputs[0].channelBuffers32[1];
		rightProcessor.process(rightOutputChannel, data.numSamples);
	}
	return kResultTrue;
}


}} // namespaces


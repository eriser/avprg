#include "plugin.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {

// define parameter definitions here...
tresult PLUGIN_API Plugin::initialize(FUnknown* context){
	//--------------------------------------------------------------------------------
	// Definition der Parameter
	//--------------------------------------------------------------------------------
	// Frequenz: 0...1 Hz
	parameters.addParameter(new RangeParameter(STR16("Frequency"), kFrequencyId, STR16("Hz"), 0, FREQUENCY_MAX_HZ, FREQUENCY_DEFAULT_HZ));
	// Delay: 0 ... 10ms
	parameters.addParameter(new RangeParameter(STR16("Delay"), kDelayId, STR16("ms"), 0, DELAY_MAX_SEC * 1000, DELAY_DEFAULT_SEC * 1000));
	// Depth: 0 ... 100%
	parameters.addParameter(new RangeParameter(STR16("Depth"), kDepthId, STR16("%"), 0, 100, DEPTH_DEFAULT_PERCENT));
	// Phase: 0 ... 180

	// fix for RangeParameter (default value is not yet set)
	for (int i = 0; i < parameters.getParameterCount(); i++){
		Parameter* p = parameters.getParameterByIndex(i);
		p->setNormalized(p->getInfo().defaultNormalizedValue);
	}
	return PluginAdapter::initialize(context);
}



//-----------------------------------------------------------------------------
Plugin::Plugin ()
: numChannels(0)
, sampleRate(0)
{
}
//-----------------------------------------------------------------------------
void Plugin::startProcessing(int numChannels, SampleRate sampleRate){
	this->numChannels = numChannels;
	this->sampleRate = sampleRate;
	leftProcessor.initialize(sampleRate);
	rightProcessor.initialize(sampleRate);
}
tresult PLUGIN_API Plugin::process (ProcessData& data)
{
    if (hasInputParameterChanged(data, kFrequencyId)){
        float frequency = getInputParameterChange(data, kFrequencyId);
		leftProcessor.setFrequency(frequency * FREQUENCY_MAX_HZ);
		rightProcessor.setFrequency(frequency * FREQUENCY_MAX_HZ);
    }
    if (hasInputParameterChanged(data, kPhaseId)){
        float phase = getInputParameterChange(data, kPhaseId);
		rightProcessor.setPhase(phase * PI);
    }
    if (hasInputParameterChanged(data, kDelayId)){
        float delay = getInputParameterChange(data, kDelayId);
 		leftProcessor.setDelay(delay * DELAY_MAX_SEC);	// max 10 ms
		rightProcessor.setDelay(delay * DELAY_MAX_SEC);
    }
    if (hasInputParameterChanged(data, kDepthId)){
        float depth = getInputParameterChange(data, kDepthId);
 		leftProcessor.setDepth(depth);
		rightProcessor.setDepth(depth);
    }
 	if (numChannels > 0){
		float* leftInputChannel = data.inputs[0].channelBuffers32[0];
		float* leftOutputChannel = data.outputs[0].channelBuffers32[0];
		leftProcessor.process(leftInputChannel, leftOutputChannel, data.numSamples);
	}
	if (numChannels > 1){
		float* rightInputChannel = data.inputs[0].channelBuffers32[1];
		float* rightOutputChannel = data.outputs[0].channelBuffers32[1];
		rightProcessor.process(rightInputChannel, rightOutputChannel, data.numSamples);
	}
	return kResultTrue;
}


}} // namespaces


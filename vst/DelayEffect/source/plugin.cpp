#include "plugin.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {


//-----------------------------------------------------------------------------
// define parameter definitions here...
tresult PLUGIN_API Plugin::initialize(FUnknown* context){
	// Delay: 0...1 s
	parameters.addParameter(new RangeParameter(STR16("Delay"), kDelayId, STR16("s"), 0, DELAY_MAX_SEC, DELAY_DEFAULT_SEC));
	// Amount: 0 ... 100%
	parameters.addParameter(new RangeParameter(STR16("Amount"), kAmountId, STR16("%"), 0, 100, AMOUNT_DEFAULT_PERCENT));
	// Feedback: 0 ... 100%
	parameters.addParameter(new RangeParameter(STR16("Feedback"), kFeedbackId, STR16("%"), 0, 100, FEEDBACK_DEFAULT_PERCENT));

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
   if (hasInputParameterChanged(data, kDelayId)){
        float delaySec = getInputParameterChange(data, kDelayId);
		leftProcessor.setDelay(delaySec);
		rightProcessor.setDelay(delaySec);
    }
    if (hasInputParameterChanged(data, kAmountId)){
        float amount = getInputParameterChange(data, kAmountId);
		leftProcessor.setAmount(amount);
		rightProcessor.setAmount(amount);
    }
    if (hasInputParameterChanged(data, kFeedbackId)){
        float feedback = getInputParameterChange(data, kFeedbackId);
		leftProcessor.setFeedback(feedback);
		rightProcessor.setFeedback(feedback);
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


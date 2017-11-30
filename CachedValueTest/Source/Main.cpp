/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
int main (int argc, char* argv[])
{
	juce::UndoManager undomanager(200, 30);

	juce::ValueTree v(juce::Identifier("vertices"));

	juce::CachedValue<int> ch_int( v,"int", &undomanager);
	juce::CachedValue<float> ch_float(v, "int", &undomanager);
	juce::CachedValue<double> ch_double(v, "double", &undomanager);

	undomanager.beginNewTransaction();
	ch_int.setDefault(10);

	undomanager.beginNewTransaction();
	ch_int.setValue(5, &undomanager);

	juce::Logger::outputDebugString(juce::String(ch_int));		//-> 5

	juce::Logger::outputDebugString(juce::String(ch_int.getDefault())); // ->10

	//デフォルト値に戻す
	ch_int.resetToDefault();
	juce::Logger::outputDebugString(juce::String(ch_int)); //->10

	//undo
	undomanager.undo();
	juce::Logger::outputDebugString(juce::String(ch_int)); //->10

	undomanager.beginNewTransaction();
	ch_int.setValue(5, &undomanager);

	undomanager.beginNewTransaction();
	ch_int.setValue(12, &undomanager);

	undomanager.undo();
	juce::Logger::outputDebugString(juce::String(ch_int)); //->5

	juce::Logger::outputDebugString( ch_int.getPropertyID().toString() ); //->int
	
	juce::Logger::outputDebugString(v.toXmlString());


    return 0;
}

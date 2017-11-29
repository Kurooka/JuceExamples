/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
int valuetest();

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
    
    valuetest();
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}



class listenerTest : public Value::Listener
{
public:
	listenerTest() {}
	virtual ~listenerTest() {}

	virtual void valueChanged(Value& value)
	{
		juce::Logger::outputDebugString("valueChanged!");
	}
};
listenerTest listener;

//==============================================================================
int valuetest() 
{
	int a = 10;
	juce::Value v(a);

	//リスナーの追加
	v.addListener(&listener);

	juce::Logger::outputDebugString( "v=" + v.toString() + ":a="+ juce::String(a) );
	a = 1;
	juce::Logger::outputDebugString( "v=" + v.toString() + ":a=" + juce::String(a));

	//発生せず
	v = 11;
	v.setValue(19);

	juce::Value v2(v);

	v2.addListener(&listener);
	v2 = 90;

	juce::Logger::outputDebugString("v=" + v.toString() + ":a=" + juce::String(a));

	v = 11;

	juce::Logger::outputDebugString("v=" + v.toString() + ":a=" + juce::String(a));
	juce::Logger::outputDebugString("v2=" + v2.toString() + ":a=" + juce::String(a));

    return 0;
}

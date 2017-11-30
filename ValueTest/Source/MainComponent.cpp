/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
int valuetest();

//==============================================================================
MainContentComponent::MainContentComponent()
	:startButton ( "Click me" )

{
    setSize (600, 400);
	addAndMakeVisible(startButton);
	startButton.setButtonText("Click me");
	startButton.addListener(this);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
}

void MainContentComponent::resized()
{
	Rectangle<int> r = getLocalBounds();

	int guiElementAreaHeight = r.getHeight() / 3;
	int margin = guiElementAreaHeight / 4;
	int buttonHeight = guiElementAreaHeight - margin;

    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	startButton.setBounds(r.removeFromTop(guiElementAreaHeight).withSizeKeepingCentre(r.getWidth(), buttonHeight));
}

void MainContentComponent::buttonClicked(Button* button)
{
	if (button == &startButton)
	{
		valuetest();
	}
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
juce::Value v;
juce::Value v2;

//==============================================================================
int valuetest() 
{
	//リスナーの追加
	v.addListener(&listener);

	v = 11;
	juce::Logger::outputDebugString("v(11) v=" + v.toString());
	v.setValue(19);
	juce::Logger::outputDebugString("v(18) v=" + v.toString());

	v2.setValue(v);
	juce::Logger::outputDebugString("v2(v)  v=" + v.toString() + "v2=" + v.toString());

	v = 11;
	juce::Logger::outputDebugString("v(11) v=" + v.toString() + "v2=" + v.toString());

    return 0;
}

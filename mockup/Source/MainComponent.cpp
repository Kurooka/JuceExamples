/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
	addAndMakeVisible(menuBar = new MenuBarComponent(this));

    setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
	if (menuBar)
	{
		Rectangle<int> area(getLocalBounds());
		menuBar->setBounds(area.removeFromTop(LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
	}

}

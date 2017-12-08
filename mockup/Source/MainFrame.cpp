/*
  ==============================================================================

    MainFrame.cpp
    Created: 8 Dec 2017 7:25:29pm
    Author:  kurooka

  ==============================================================================
*/

#include "MainFrame.h"
#include "MainComponent.h"


MainWindow::MainWindow(String name) : 
	DocumentWindow(name,
					Desktop::getInstance().getDefaultLookAndFeel()
					.findColour(ResizableWindow::backgroundColourId),
					DocumentWindow::allButtons)
{
	setUsingNativeTitleBar(true);
	setContentOwned(new MainContentComponent(), true);

	centreWithSize(getWidth(), getHeight());
	setVisible(true);
}


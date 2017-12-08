/*
  ==============================================================================

    MainFrame.h
    Created: 8 Dec 2017 7:25:29pm
    Author:  kurooka

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This class implements the desktop window that contains an instance of
    our MainContentComponent class.
*/
class MainWindow    : public DocumentWindow
{
public:
	MainWindow(String name);

    void closeButtonPressed() override
    {
        JUCEApplication::getInstance()->systemRequestedQuit();
    }


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};
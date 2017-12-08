/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
#include "Application.h"



//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(mockupApplication)


ApplicationCommandManager* mockupApplication::applicationCommandManager = NULL;


ApplicationCommandManager& mockupApplication::getApplicationCommandManager()
{
	if (applicationCommandManager == nullptr)
		applicationCommandManager = new ApplicationCommandManager();

	return *applicationCommandManager;
}
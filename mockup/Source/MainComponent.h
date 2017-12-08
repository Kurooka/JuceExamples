/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component,
								public MenuBarModel//,
//								public ChangeBroadcaster,
//								private Button::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

	//==============================================================================
	StringArray getMenuBarNames() override
	{
		return { "File", "Edit", "Windows", "Help" };
	}

	PopupMenu getMenuForIndex(int menuIndex, const String& /*menuName*/) override
	{
		PopupMenu menu;

		if (menuIndex == 0)
		{
			menu.addItem(3000, "Load", true, false);
			menu.addItem(3001, "Save", true, false);
			menu.addItem(3002, "SaveAs", true, false);
			menu.addSeparator();
			menu.addItem(3003, "Exit", true, false);
		}
		else {
		}

		return menu;
	}

	void menuItemSelected(int menuItemID, int /*topLevelMenuIndex*/) override
	{
		DBG(menuItemID);
	}
/*
	void buttonClicked(Button* button) override
	{
	}
	*/
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)

	ScopedPointer<MenuBarComponent> menuBar;

};

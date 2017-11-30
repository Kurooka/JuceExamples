/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

/**/
extern void	AbstractFifo_test();
extern void ArrayTemplateTest();
extern void containers_dynamic_test();

/**/
void	containers_test()
{
	AbstractFifo_test();
	ArrayTemplateTest();
	containers_dynamic_test();
}


//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
	containers_test();

    return 0;
}

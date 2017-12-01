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
extern void DefaultElementComparator_test();
extern void core_containers_DefaultHashFunctions_test();
extern void core_containers_HashMap_test();
extern void core_containers_LinkedListPointer_test();

/**/
void	containers_test()
{
	AbstractFifo_test();
	ArrayTemplateTest();
	containers_dynamic_test();
	DefaultElementComparator_test();
	core_containers_DefaultHashFunctions_test();
	core_containers_HashMap_test();
	core_containers_LinkedListPointer_test();

}


//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
	containers_test();

    return 0;
}

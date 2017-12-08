/*
  ==============================================================================

    Fifo.cpp
    Created: 30 Nov 2017 6:45:47pm
    Author:  kurooka

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"
#include <memory>

/*
ƒƒbƒNƒtƒŠ[‚ÌFIFO‚ðŽÀ‘•‚·‚é‚½‚ß‚É•K—v‚ÈƒƒWƒbƒN‚ðƒJƒvƒZƒ‹‰»‚µ‚Ü‚·B
FIFO = First In, First Out

‚±‚ÌƒNƒ‰ƒX‚ÍAƒVƒ“ƒOƒ‹ƒŠ[ƒ_AƒVƒ“ƒOƒ‹ƒ‰ƒCƒ^FIFO‚ð\’z‚·‚éÛ‚É•K—v‚ÈƒƒWƒbƒN‚ðˆ—‚µ‚Ü‚·B
ŽÀÛ‚É‚Íƒf[ƒ^Ž©‘Ì‚Í•ÛŽ‚³‚ê‚Ü‚¹‚ñ‚ªAFIFOƒNƒ‰ƒX‚Å‚ÍA“Ç‚ÝŽæ‚è‚Ü‚½‚Í‘‚«ž‚ÝŽž‚ÌˆÊ’u‚ÆƒXƒe[ƒ^ƒX‚ðŠÇ—‚·‚é‚½‚ß‚É‚±‚ê‚ç‚Ì‚¢‚¸‚ê‚©‚ðŽg—p‚Å‚«‚Ü‚·B
‚±‚ê‚ðŽg—p‚·‚é‚É‚ÍAprepareToWrite()‚ðŒÄ‚Ño‚µ‚ÄAŽóMƒoƒbƒtƒ@[‚ÌŠi”[êŠ‚ðŽ©•ª‚Ìƒoƒbƒtƒ@[“à‚Å”»•Ê‚µA
prepareToRead()‚ðŒÄ‚Ño‚µ‚ÄAŽŸ‚Ì‘—MƒuƒƒbƒN‚ð‚¢‚Â“Ç‚ÝŽæ‚é‚©‚ð’²‚×‚é‚±‚Æ‚ª‚Å‚«‚Ü‚·B
*/
class MyFifo
{
public:
	MyFifo() : abstractFifo(1024)
	{
	}
	void addToFifo(const int* someData, int numItems)
	{
		int start1, size1, start2, size2;
		abstractFifo.prepareToWrite(numItems, start1, size1, start2, size2);
		if (size1 > 0)
			memcpy(myBuffer + start1, someData, size1 * sizeof(int));
		if (size2 > 0)
			memcpy(myBuffer + start2, someData + size1, size2 * sizeof(int));
		abstractFifo.finishedWrite(size1 + size2);
	}
	void readFromFifo(int* someData, int numItems)
	{
		int start1, size1, start2, size2;
		abstractFifo.prepareToRead(numItems, start1, size1, start2, size2);
		if (size1 > 0)
			memcpy(someData, myBuffer + start1, size1 * sizeof(int));
		if (size2 > 0)
			memcpy(someData + size1, myBuffer + start2, size2 * sizeof(int));
		abstractFifo.finishedRead(size1 + size2);
	}
private:
	AbstractFifo abstractFifo;
	int myBuffer[1024];
};



void	AbstractFifo_test()
{

	int data[32];
	int out[64];
	memset(out, 0, sizeof(int) * 64);

	for (int i = 0; i < 32; i++)
		data[i] = i;

	MyFifo fifo;

	fifo.addToFifo(data, 32);
	fifo.addToFifo(data, 32);

	fifo.readFromFifo(out, 64);

	for (int i = 0; i < 64; i++)
		juce::Logger::outputDebugString(juce::String(out[i]));

}



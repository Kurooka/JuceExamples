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
ロックフリーのFIFOを実装するために必要なロジックをカプセル化します。
FIFO = First In, First Out

このクラスは、シングルリーダ、シングルライタFIFOを構築する際に必要なロジックを処理します。
実際にはデータ自体は保持されませんが、FIFOクラスでは、読み取りまたは書き込み時の位置とステータスを管理するためにこれらのいずれかを使用できます。
これを使用するには、prepareToWrite()を呼び出して、受信バッファーの格納場所を自分のバッファー内で判別し、
prepareToRead()を呼び出して、次の送信ブロックをいつ読み取るかを調べることができます。
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



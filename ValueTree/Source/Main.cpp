/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
int main (int argc, char* argv[])
{
	//undo manager作成
	juce::UndoManager undomanager(200000, 30);

	//値の初期化
	juce::ValueTree v(juce::Identifier("vertices"));
	juce::Value count(var(1));

	undomanager.beginNewTransaction();
	v.setProperty("count", count, &undomanager);
	v.setProperty("x", 10, &undomanager);
	v.setProperty("y", 5, &undomanager);
	v.setProperty("z", -15, &undomanager);

	//count = 1
	juce::Logger::outputDebugString(v["count"].toString());

	//cout <- 12
	undomanager.beginNewTransaction();
	v.setProperty("count", 12, &undomanager);
	//count = 12
	juce::Logger::outputDebugString( v["count"].toString() );

	//変数 count の値を見ると変わっていない参照は無い
	juce::Logger::outputDebugString(count.toString());

	//undoをしてみる count = 1になる
	undomanager.undo();
	juce::Logger::outputDebugString( "undo = " + v["count"].toString());


	//プロパティ数を調べる
	juce::Logger::outputDebugString(juce::String(v.getNumProperties()));


	//********************************************** 
	//	XMLでの運用 
	//********************************************** 

	//	XML(文字列）へ出力(デバッグ用途）	
	juce::Logger::outputDebugString(v.toXmlString());


	//実際に読み書き前提で使用する場合
	juce::XmlElement* outxml = v.createXml();
	//e->writeToFile();

	//カレントのワーキングディレクトリを取得
	juce::File f = juce::File::getCurrentWorkingDirectory();
	juce::String filepath = f.getFullPathName() + "\\test.xml";

	//XMLファイルの書き出し
	outxml->writeToFile( filepath ,"" );
	
	delete outxml;

	//XMLの読み込み 
	juce::File readf(filepath);
	juce::XmlDocument xmldoc(readf);
	juce::ValueTree v2(juce::Identifier("vertices"));
	juce::XmlElement* inxml = xmldoc.getDocumentElement();
	v2.fromXml(*inxml);

	juce::Logger::outputDebugString(juce::String(v2.getNumChildren()));
	juce::Logger::outputDebugString(juce::String(v2.getNumProperties()));
	juce::Logger::outputDebugString(v2.toXmlString());
	delete inxml;

	//********************************************** 
	//	Juceバイナリフォーマットでの運用 
	//********************************************** 

	//バイナリフォーマットでの出力
	filepath = f.getFullPathName() + "\\test.bin";
	juce::FileOutputStream binfile( filepath );
	v.writeToStream(binfile);


    return 0;
}

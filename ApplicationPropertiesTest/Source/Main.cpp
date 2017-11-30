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
	initialiseJuce_GUI();	//GUIが初期化できていないと動作しない

	ApplicationProperties apppro;
	PropertiesFile::Options options;

	//ファイル名を決定する
	options.applicationName = "ApplicationPropertiesTest";
	options.filenameSuffix = ".settings";
	options.osxLibrarySubFolder = "Application Support";
	apppro.setStorageParameters(options);

	//これが初めて呼び出されると、プロパティファイルが作成されてロードされます。
	juce::PropertiesFile* commonProperties = apppro.getCommonSettings(true);


	//環境により以下のフォルダに格納される
	//windows	C:\Documents and Settings\username\Application Data\[folderName]\[applicationName].[filenameSuffix]
	//macos		~/Library/[osxLibrarySubFolder]/[folderName]/[applicationName].[filenameSuffix]
	//linux		~/[folderName]/[applicationName].[filenameSuffix]
	juce::PropertiesFile* userProperties = apppro.getUserSettings();
	userProperties->setValue("mode", true);
	userProperties->setValue("x", 1);
	userProperties->setValue("y", 1.5f);
	userProperties->setValue("z", 1.2);

	//現在の値のディスクへの書き込みが強制的に行われます。
	userProperties->save();

	//最後の値から変更されていれば、すべての値がディスクにフラッシュされます
	apppro.saveIfNeeded();

    return 0;
}

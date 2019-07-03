// SuaraClicker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
This is revamped clicker
*/
#include "pch.h"
#include <iostream>
//#include "../StreamBuffer/StreamBuffer.h"
//#include "../AudioStreamingModule/AudioStreamingModule.h"
//#include "../AudioStreamingController/AudioStreamingController.h"
//#include "../Microphone_API_DLL/Microphone_API.h"
//#include "../ZeroConfigModule/ServiceDiscovery_API.h"
#include "../ControlPanel/ControlPanel.h"

using namespace std;

//int main() {
//	MicrophoneAPI::MicrophoneAPIParams params;
//	params.bufferFrames = 256;
//	params.numberOfChunk = 4;
//	params.sampleRate = 48000;
//
//	MicrophoneAPI* microphone = new MicrophoneAPI(params);
//	microphone->startMicrophone();
//
//	cin.get();
//
//	vector<string> v = { "vc_audio", to_string(microphone->getLocalport()) };
//	v.push_back("vc_input");
//	v.push_back(to_string(12312));
//
//	ServiceDiscoveryAPI::ServiceDiscoveryParams sdParams;
//	sdParams.port = 12341;
//	sdParams.serviceName = "Voice Clicker" ;
//	sdParams.serviceProtocol = "_vcHello._udp";
//	sdParams.props = v;
//	sdParams.numOfProps = 2;
//	ServiceDiscoveryAPI* mSD = new ServiceDiscoveryAPI(sdParams);
//	mSD->advertise();
//
//	cin.get();
//	delete(mSD);
//	microphone->stopMicrophone();
//}

int main() {
	ControlPanel* panel = new ControlPanel();
	panel->startMicrophone();
	cin.get();
	panel->startServiceAdvertising();

	cin.get();
	panel->stopMicrophone();
	panel->stopServiceAdvertising();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

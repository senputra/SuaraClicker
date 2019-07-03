#ifdef ZEROCONFIGMODULE_EXPORTS
#define ZEROCONFIGMODULE_API __declspec(dllexport)
#else
#define ZEROCONFIGMODULE_API __declspec(dllimport)
#endif // STREAMSERVER_EXPORTS

#include "stdafx.h"
#include <vector>

using namespace Poco::DNSSD;
using namespace std;
class ZEROCONFIGMODULE_API ServiceDiscoveryAPI {
public:
	struct ServiceDiscoveryParams {
		int port;
		string serviceName; // Voice CLicker
		string serviceProtocol; // "_voiceClicker._udp"
		vector<string> props;
		int numOfProps;
	};
public:
	ServiceDiscoveryAPI(ServiceDiscoveryParams params);
	~ServiceDiscoveryAPI();
	void advertise();
	void addProps(std::string key, std::string value);
	void discardAdvertise();
	void discardAdvertise(Poco::DNSSD::ServiceHandle serviceHandle);

private:
	DNSSDResponder* dnssdResponder;
	Service::Properties *_props;

	ServiceHandle _serviceHandler;

	string _serviceName;
	string _serviceProtocol;
	int _port = 0;
	int _numOfProps = 0;
};

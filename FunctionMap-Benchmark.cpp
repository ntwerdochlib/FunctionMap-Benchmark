#if defined(WIN32)
#include <Windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <array>
#include <map>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

#include "benchmark/benchmark.h"

using std::map;
using std::string;
using std::vector;

static constexpr std::array<char*, 81> actions{
	"CreateSDCustGatewaySession",
	"IsCustomerPlatformSupported",
	"CreateSDCustConference",
	"GetSDCustGatewaySessionInfo",
	"SDCustClientReady",
	"ShowFullLegalTerms",
	"SDCustAgreementAnswered",
	"EndSDCustGatewaySession",
	"EndSessionAmbushMessage",
	"AcceptSession",
	"CreateConferenceInvitation",
	"AcceptConferenceInvitation",
	"AcceptConferenceInvitation_ExternalCommunicationResponse",
	"DeclineConferenceInvitation",
	"DeclineConferenceInvitation_ExternalCommunicationResponse",
	"GetTransferConferences",
	"GetInviteConferences",
	"GetConferenceInvitations",
	"GetInvitableSupportIssues",
	"CancelConferenceInvitation",
	"RepGatewaySessionDestructor",
	"AllocateRepLicense",
	"FreeRepLicense",
	"RequestServiceAccess",
	"AllowServiceAccess",
	"RefuseServiceAccess",
	"SendVitals",
	"GetLoggedInRepInfoByUserID",
	"GetRepExitSurvey",
	"SubmitExitSurvey",
	"SDCustElevate",
	"SetElevateState",
	"ElevationAttemptResponse",
	"RequestElevateWebSDCust",
	"WebElevationAttemptResponse",
	"RunOrphanFixer",
	"RunWatchDog",
	"GetSDCustInstaller",
	"GetSDCustInstallerForPushAgent",
	"GetFrontendSurvey",
	"GetCustomerInviteEmailText",
	"GetiOSCustomerInviteEmailText",
	"StartReverseConnect",
	"StopReverseConnect",
	"SetReverseConnectPending",
	"SetReverseConnectControl",
	"RemoveRep",
	"TerminateSession",
	"AddNote",
	"GetNotes",
	"GetSupportAccessPolicies",
	"CalculateSupportAccessPolicies",
	"SetExternalKey",
	"RevokeAllGrants",
	"SendPromptStatusToRep",
	"GetRepsInConference",
	"RequestPlatformSpecificTask",
	"PanicButtonPressed",
	"IsCustomerInSession",
	"StartRemoteShellLog",
	"StopRemoteShellLog",
	"RepIsInactive",
	"RemoveMeAndFixOrphan",
	"TakeSession",
	"GetInferiors",
	"RequestMonitorRep",
	"MonitorRepConnectionParametersResponse",
	"StartTrialSession",
	"GetContentProfiles",
	"SetRepExtendedContactState",
	"SetRepExtendedContactState_ExternalCommunicationResponse",
	"SendAmbushMessage",
	"SetSessionAttributes",
	"PrintQueueWaitHistory",
	"PrintQueueWaitEstimates",
	"PrintSessionWaitEstimates",
	"SetCapabilities",
	"ScheduleRepLogout",
	"AutoRepLogout",
	"TeamConfigurationChanged",
	"RemoveMeFromPinnedSession"
};

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(0, static_cast<int>(actions.size() - 1));

std::string getRandomAction()
{
	auto const index = dist(gen);
	return actions[index];
}

bool handleAction() { return true; }

static void ProcessMessage(benchmark::State& state)
{
	// while (state.KeepRunning()) {
	for (auto _ : state) {
		auto action = getRandomAction();

		bool ret{false};

		if (action == "CreateSDCustGatewaySession")
			ret = handleAction();
		else if (action == "IsCustomerPlatformSupported")
			ret = handleAction();
		else if (action == "CreateSDCustConference")
			ret = handleAction();
		else if (action == "GetSDCustGatewaySessionInfo")
			ret = handleAction();
		else if (action == "SDCustClientReady")
			ret = handleAction();
		else if (action == "ShowFullLegalTerms")
			ret = handleAction();
		else if (action == "SDCustAgreementAnswered")
			ret = handleAction();
		else if (action == "EndSDCustGatewaySession")
			ret = handleAction();
		else if (action == "EndSessionAmbushMessage")
			ret = handleAction();
		else if (action == "AcceptSession")
			ret = handleAction();
		else if (action == "CreateConferenceInvitation")
			ret = handleAction();
		else if (action == "AcceptConferenceInvitation")
			ret = handleAction();
		else if (action == "AcceptConferenceInvitation_ExternalCommunicationResponse")
			ret = handleAction();
		else if (action == "DeclineConferenceInvitation")
			ret = handleAction();
		else if (action == "DeclineConferenceInvitation_ExternalCommunicationResponse")
			ret = handleAction();
		else if (action == "GetTransferConferences")
			ret = handleAction();
		else if (action == "GetInviteConferences")
			ret = handleAction();
		else if (action == "GetConferenceInvitations")
			ret = handleAction();
		else if (action == "GetInvitableSupportIssues")
			ret = handleAction();
		else if (action == "CancelConferenceInvitation")
			ret = handleAction();
		else if (action == "RepGatewaySessionDestructor")
			ret = handleAction();
		else if (action == "AllocateRepLicense")
			ret = handleAction();
		else if (action == "FreeRepLicense")
			ret = handleAction();
		else if (action == "RequestServiceAccess")
			ret = handleAction();
		else if (action == "AllowServiceAccess")
			ret = handleAction();
		else if (action == "RefuseServiceAccess")
			ret = handleAction();
		else if (action == "SendVitals")
			ret = handleAction();
		else if (action == "GetLoggedInRepInfoByUserID")
			ret = handleAction();
		else if (action == "GetRepExitSurvey")
			ret = handleAction();
		else if (action == "SubmitExitSurvey")
			ret = handleAction();
		else if (action == "SDCustElevate")
			ret = handleAction();
		else if (action == "SetElevateState")
			ret = handleAction();
		else if (action == "ElevationAttemptResponse")
			ret = handleAction();
		else if (action == "RequestElevateWebSDCust")
			ret = handleAction();
		else if (action == "WebElevationAttemptResponse")
			ret = handleAction();
		else if (action == "RunOrphanFixer")
			ret = handleAction();
		else if (action == "RunWatchDog")
			ret = handleAction();
		else if (action == "GetSDCustInstaller")
			ret = handleAction();
		else if (action == "GetSDCustInstallerForPushAgent")
			ret = handleAction();
		else if (action == "GetFrontendSurvey")
			ret = handleAction();
		else if (action == "GetCustomerInviteEmailText")
			ret = handleAction();
		else if (action == "GetiOSCustomerInviteEmailText")
			ret = handleAction();
		else if (action == "StartReverseConnect")
			ret = handleAction();
		else if (action == "StopReverseConnect")
			ret = handleAction();
		else if (action == "SetReverseConnectPending")
			ret = handleAction();
		else if (action == "SetReverseConnectControl")
			ret = handleAction();
		else if (action == "RemoveRep")
			ret = handleAction();
		else if (action == "TerminateSession")
			ret = handleAction();
		else if (action == "AddNote")
			ret = handleAction();
		else if (action == "GetNotes")
			ret = handleAction();
		else if (action == "GetSupportAccessPolicies")
			ret = handleAction();
		else if (action == "CalculateSupportAccessPolicies")
			ret = handleAction();
		else if (action == "SetExternalKey")
			ret = handleAction();
		else if (action == "RevokeAllGrants")
			ret = handleAction();
		else if (action == "SendPromptStatusToRep")
			ret = handleAction();
		else if (action == "GetRepsInConference")
			ret = handleAction();
		else if (action == "RequestPlatformSpecificTask")
			ret = handleAction();
		else if (action == "PanicButtonPressed")
			ret = handleAction();
		else if (action == "IsCustomerInSession")
			ret = handleAction();
		else if (action == "StartRemoteShellLog")
			ret = handleAction();
		else if (action == "StopRemoteShellLog")
			ret = handleAction();
		else if (action == "RepIsInactive")
			ret = handleAction();
		else if (action == "RemoveMeAndFixOrphan")
			ret = handleAction();
		else if (action == "TakeSession")
			ret = handleAction();
		else if (action == "GetInferiors")
			ret = handleAction();
		else if (action == "RequestMonitorRep")
			ret = handleAction();
		else if (action == "MonitorRepConnectionParametersResponse")
			ret = handleAction();
		else if (action == "StartTrialSession")
			ret = handleAction();
		else if (action == "GetContentProfiles")
			ret = handleAction();
		else if (action == "SetRepExtendedContactState")
			ret = handleAction();
		else if (action == "SetRepExtendedContactState_ExternalCommunicationResponse")
			ret = handleAction();
		else if (action == "SendAmbushMessage")
			ret = handleAction();
		else if (action == "SetSessionAttributes")
			ret = handleAction();
		else if (action == "PrintQueueWaitHistory")
			ret = handleAction();
		else if (action == "PrintQueueWaitEstimates")
			ret = handleAction();
		else if (action == "PrintSessionWaitEstimates")
			ret = handleAction();
		else if (action == "SetCapabilities")
			ret = handleAction();
		else if (action == "ScheduleRepLogout")
			ret = handleAction();
		else if (action == "AutoRepLogout")
			ret = handleAction();
		else if (action == "TeamConfigurationChanged")
			ret = handleAction();
		else if (action == "RemoveMeFromPinnedSession")
			ret = handleAction();

		benchmark::DoNotOptimize(ret);
		benchmark::ClobberMemory();
	}
}

BENCHMARK(ProcessMessage);

using func_map_t = map<string, string>;
func_map_t functionsMap;

static void ProcessMessageMap_Setup(const benchmark::State& state)
{
	// setup
	functionsMap.clear();
	for (auto const& action : actions) {
		functionsMap.emplace(std::make_pair(action, action));
	}
}

static void ProcessMessageMap(benchmark::State& state)
{
	for (auto _ : state) {
		auto action = getRandomAction();
		func_map_t::iterator it = functionsMap.find(action);
		benchmark::DoNotOptimize(it);
		benchmark::ClobberMemory();
	}
}

BENCHMARK(ProcessMessageMap)->Setup(ProcessMessageMap_Setup);

using func_umap_t = std::unordered_map<string, string>;
func_umap_t functionsUMap;

static void ProcessMessageUMap_Setup(const benchmark::State& state)
{
	// setup
	functionsUMap.clear();
	for (auto const& action : actions) {
		functionsMap.emplace(std::make_pair(action, action));
	}
}

static void ProcessMessageUMap(benchmark::State& state)
{
	for (auto _ : state) {
		auto action = getRandomAction();
		func_umap_t::iterator it = functionsUMap.find(action);
		benchmark::DoNotOptimize(it);
		benchmark::ClobberMemory();
	}
}

BENCHMARK(ProcessMessageUMap)
	->Name("ProcessMessageUnorderedMap")
	->Setup(ProcessMessageUMap_Setup);

BENCHMARK_MAIN();

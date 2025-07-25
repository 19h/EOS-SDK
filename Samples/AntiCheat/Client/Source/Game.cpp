// Copyright Epic Games, Inc. All Rights Reserved.

#include "pch.h"
#include "Menu.h"
#include "Level.h"
#include "Game.h"
#include "AntiCheatClient.h"
#include "AntiCheatNetworkTransport.h"
#include "AntiCheatP2PNetworkTransport.h"
#include "Authentication.h"

FGame::FGame() noexcept(false) :
	FBaseGame()
{
	Menu = std::make_unique<FMenu>(Console);
	Level = std::make_unique<FLevel>();
	AntiCheatNetworkTransport = std::make_unique<FAntiCheatNetworkTransport>();
	AntiCheatP2PNetworkTransport = std::make_unique<FAntiCheatP2PNetworkTransport>();
	AntiCheatClient = std::make_unique<FAntiCheatClient>();

	CreateConsoleCommands();
}

FGame::~FGame()
{
	
}

void FGame::Init()
{
	FBaseGame::Init();
	FBaseGame::GetAuthentication()->SetDefaultLoginScope(EOS_EAuthScopeFlags::EOS_AS_BasicProfile);

	AntiCheatClient->Init();
}

void FGame::Update()
{
	FBaseGame::Update();

	AntiCheatNetworkTransport->Update();
	AntiCheatP2PNetworkTransport->Update();
}

void FGame::OnShutdown()
{
	AntiCheatClient->OnShutdown();

	FBaseGame::OnShutdown();
}

void FGame::OnGameEvent(const FGameEvent& Event)
{
	AntiCheatClient->OnGameEvent(Event);
	FBaseGame::OnGameEvent(Event);
}

const std::unique_ptr<FAntiCheatClient>& FGame::GetAntiCheatClient()
{
	return AntiCheatClient;
}

const std::unique_ptr<FAntiCheatNetworkTransport>& FGame::GetAntiCheatNetworkTransport()
{
	return AntiCheatNetworkTransport;
}

const std::unique_ptr<FAntiCheatP2PNetworkTransport>& FGame::GetAntiCheatP2PNetworkTransport()
{
	return AntiCheatP2PNetworkTransport;
}
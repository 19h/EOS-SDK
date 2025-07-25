// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Dialog.h"
#include "TextLabel.h"
#include "TextField.h"
#include "Button.h"
#include "Font.h"

class FGameEvent;

class FAntiCheatDialog : public FDialog
{
public:
	/**
	 * Constructor
	 */
	FAntiCheatDialog(Vector2 InPosition, 
		Vector2 InSize, 
		UILayer InLayer, 
		FontPtr DialogNormalFont,
		FontPtr DialogSmallFont);

	/**
	 * Destructor
	 */
	virtual ~FAntiCheatDialog() override = default;

	/**
	* IGfxComponent Overrides
	*/
	virtual void Create() override;

	/** IWidget */
	virtual void SetPosition(Vector2 Pos) override;
	virtual void SetSize(Vector2 NewSize) override;

	/** Sets proportion console is using */
	void SetWindowProportion(Vector2 InWindowProportion);

	/** Set Window Size */
	void SetWindowSize(Vector2 WindowSize);

	/**
	* Receives game event
	*
	* @param Event - Game event to act on
	*/
	void OnGameEvent(const FGameEvent& Event);

	void ShowUI();
	void HideUI();

	void OnClientServerModeButtonPressed();
	void OnP2PModeButtonPressed();
	void OnJoinGameButtonPressed();
	void OnLeaveGameButtonPressed();
	void OnRegisterPeerButtonPressed();
	void OnUnregisterPeerButtonPressed();

private:
	
	bool bIsP2P = false;

	void LeaveGame();

	/** Header Label */
	std::shared_ptr<FTextLabelWidget> HeaderLabel;

	/** Background Image */
	std::shared_ptr<FSpriteWidget> BackgroundImage;

	/** Part of window that console is taking */
	Vector2 ConsoleWindowProportion;

	std::shared_ptr<FButtonWidget> ClientServerModeButton;
	std::shared_ptr<FButtonWidget> P2PModeButton;

	/** Join Game button */
	std::shared_ptr<FButtonWidget> JoinGameButton;

	/** Leave Game button */
	std::shared_ptr<FButtonWidget> LeaveGameButton;

	std::shared_ptr<FButtonWidget> RegisterPeerButton;
	std::shared_ptr<FButtonWidget> UnregisterPeerButton;

	/** Mode label */
	std::shared_ptr<FTextLabelWidget> ModeLabel;

	/** Listen port label */
	std::shared_ptr<FTextLabelWidget> ListenPortLabel;
	
	/** Listen port field */
	std::shared_ptr<FTextFieldWidget> ListenPortField;

	/** IP (Host) label */
	std::shared_ptr<FTextLabelWidget> IPLabel;

	/** IP (Host) field */
	std::shared_ptr<FTextFieldWidget> IPField;

	/** Port label */
	std::shared_ptr<FTextLabelWidget> PortLabel;

	/** Port field */
	std::shared_ptr<FTextFieldWidget> PortField;
};


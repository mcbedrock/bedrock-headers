#pragma once

#include "../../render/ScreenContext.h"
#include <string>

struct FocusImpact;

struct BaseScreen {
	BaseScreen();

	~BaseScreen();

	void applyInput(float);

	void leaveScreen();

	void tick(int, int);

	void reload();

	void terminate();

	void onCreation();

	void onScreenExit(bool, bool);

	void onScreenEntrance(bool, bool);

	void onFocusGained();

	void onLeave();

	void onInternetUpdate();

	void onKeyboardDismissed();

	void handleBackEvent(bool);

	void handleButtonPress(unsigned int, FocusImpact);

	void handleButtonRelease(unsigned int, FocusImpact);

	void handleIdActorLost();

	void setupForRendering(ScreenContext &);

	void setupAndRender(ScreenContext &);

	void setTextboxText(std::string const &);

	void setWantsTextOnly(bool);

	bool getWantsTextOnly();

	bool getShouldSendEvents();

	bool canBePopped() const;

	bool canBePushed() const;

	bool ignoreAsTop() const;

	bool isPlayScreen() const;

	bool isShowingMenu() const;

	bool renderGameBehind() const;

	bool shouldStealMouse() const;

	bool canBeTransitioned() const;

	bool closeOnPlayerHurt() const;

	bool alwaysAcceptsInput() const;

	bool loadScreenImmediately() const;

	bool renderOnlyWhenTopMost() const;

	bool isGamepadCursorEnabled() const;

	bool isTerminating() const;

	bool isModal() const;

	bool isEntering() const;

	bool isExiting() const;

	std::string getScreenName() const;

	std::string getScreenNameW() const;
};

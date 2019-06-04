#pragma once

#include <string>

struct ClientInstance;

struct GuiData {
	// TODO: find types
	static GuiData *BUTTONS_TRANSPARENCY;
	static GuiData *GUI_SCALE_VALUES;

	GuiData(ClientInstance &);

	void addTTSMessage(std::string const &);

	void clearAllTTSMessages();

	void clearTitleMessages();

	void clearMessages();

	void forceMuteChat();

	void toggleMuteChat();

	void clearTitle();

	void resetTitle();

	void setTitle(std::string const &);

	void setSubtitle(std::string const &);

	void setTitleAnimationTimes(int, int, int);

	void setActionBarMessage(std::string const &);

	void setDevConsoleMaxMessages(int);

	void setTextToSpeechEnabled(bool);

	void setIsChatting(bool);

	void setGuiScale(float);

	void setNowPlaying(std::string const &);

	void addDevConsoleMessage(std::string const &);

	void displayClientMessage(std::string const &);

	void displaySystemMessage(std::string const &);

	void displayWhisperMessage(std::string const &, std::string const &, std::string const &, std::string const &);

	void displayAnnouncementMessage(std::string const &, std::string, std::string const &, std::string const &);

	void displayLocalizedMessage(std::string const &, bool);

	void displayDevConsoleMessage(std::string const &);

	void showJukeboxPopupNotice(std::string const &, std::string const &);

	void showTipMessage(std::string const &);

	bool isMuteChat();

	bool isTouchEnabledOrHolographic();

	bool isOddGuiScale();

	int getDevConsoleMaxMessages() const;

	std::string getTitleMessage() const;

	std::string getLastPopupText() const;

	std::string getLastDevConsoleMessage() const;

	std::string getLastChatMessage() const;
};

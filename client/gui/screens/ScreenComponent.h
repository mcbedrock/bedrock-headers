#pragma once

struct UIControl;

struct ScreenComponent {
public:
	ScreenComponent(UIControl &);

	void reset();

	void clone(UIControl &);

	void setIsModal(bool);

	void setIsVRMode(bool);

	void setCacheScreen(bool);

	void setAbsorbsInput(bool);

	void setGamepadCursor(bool);

	void setIsShowingMenu(bool);

	void setScreenDrawsLast(bool);

	void setForceRenderBelow(bool);

	void setLowFreqRendering(bool);

	void setRenderGameBehind(bool);

	void setShouldSendEvents(bool);

	void setShouldStealMouse(bool);

	void setCloseOnPlayerHurt(bool);

	void setAlwaysAcceptsInput(bool);

	void setVerticalScrollDelta(float);

	void setScreenIsNotFlushable(bool);

	void setLoadScreenImmediately(bool);

	bool getIsModal() const;

	bool getIsVRMode() const;

	bool getCacheScreen() const;

	bool getAbsorbsInput() const;

	bool getGamepadCursor() const;

	bool getIsShowingMenu() const;

	bool getScreenDrawsLast() const;

	bool getForceRenderBelow() const;

	bool getLowFreqRendering() const;

	bool getRenderGameBehind() const;

	bool getShouldSendEvents() const;

	bool getShouldStealMouse() const;

	bool getCloseOnPlayerHurt() const;

	bool getAlwaysAcceptsInput() const;

	bool loadScreenImmediately()

	float getVerticalScrollDelta() const;

	bool getScreenIsNotFlushable() const;
};

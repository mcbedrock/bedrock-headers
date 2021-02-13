#pragma once

struct GuiMessage {
    char pad_0000[0xC];
    std::string text;
	//const std::string &getString() const;

	GuiMessage(const GuiMessage &);
};

struct ClientInstanceScreenModel {
    bool isPlayerOnGround() const;

    void sendChatMessage(std::string const&);

    std::vector<GuiMessage> &getGuiMessageList();

    void sendBlockEntityUpdatePacket(BlockPos const&);
};
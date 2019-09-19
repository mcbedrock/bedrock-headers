#pragma once

struct ClientInstanceScreenModel {
    bool isPlayerOnGround() const;

    void sendChatMessage(std::string const&);

    std::vector<std::string> getGuiMessageList();
};
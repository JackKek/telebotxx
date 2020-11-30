#ifndef TELEBOTXX_SEND_MESSAGE_REQUEST_HPP
#define TELEBOTXX_SEND_MESSAGE_REQUEST_HPP

#include "Message.hpp"
#include "RequestOptions.hpp"

#include <memory>
#include <string>

namespace telebotxx {

class SendMessageRequest
{
public:
	SendMessageRequest(const std::string& telegramMainUrl, const ChatId& chat, const Text& text);
	~SendMessageRequest();

	void setParseMode(ParseMode mode);
	void setDisableWebPagePreview(const DisableWebPagePreview& disableWebPagePreview);
	void setDisableNotification(const DisableNotification& disableNotification);
	void setReplyToMessageId(const ReplyTo& replyToMessageId);

	void setOption(ParseMode mode);
	void setOption(const DisableWebPagePreview& disableWebPagePreview);
	void setOption(const DisableNotification& disableNotification);
	void setOption(const ReplyTo& replyToMessageId);

	Message execute();

private:
	class Impl;
	std::unique_ptr<Impl> impl_;
};

} // namespace telebotxx

#endif // TELEBOTXX_SEND_MESSAGE_REQUEST_HPP

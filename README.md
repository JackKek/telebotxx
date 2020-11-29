# telebotxx
[![Build Status](https://travis-ci.org/UltraCoderRU/telebotxx.svg?branch=master)](https://travis-ci.org/UltraCoderRU/telebotxx)

Telegram Bot API 2.0 for C++17. It uses [C++ Requests](https://github.com/whoshuu/cpr) library to perform HTTP requests and [RapidJSON](https://github.com/miloyip/rapidjson) to work with JSON data.
In development, so you are welcome to contribute.

## Requirements
* C++17-compatible compiler
* CMake 3.15 or newer

## Building
*You can set available options in CMakeLists.txt before running configure script.*
```bash
git submodule update --init --recursive
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```
## Usage

### Sending text message
Here is a simple example of how to send text message:
```cpp
#include <telebotxx/BotApi.hpp>

std::string token = "YOUR:BOT:TOKEN";
int main()
{
  using namespace telebotxx;
  BotApi bot(token);
  Message answer = bot.sendMessage(ChatId{"@chat_name"},
                                   Text{"Hello, world!"}
                                  );
  return 0;
}
```
Member function ```BotApi::sendMessage()``` returns information about sent message on success or throws an exception.

You can pass additional options in any combination and order:
```cpp
int messageId = ...; // ID of the original message to reply
Message answer = bot.sendMessage(ChatId{"@chat_name"},
                                 Text{"Hello, world!"},
                                 ReplyTo{messageId},
                                 ParseMode::Markdown,
                                 DisableNotification(),
                                 DisableWebPagePreview()
                                );
```
Note, that ```ChatId``` argument can be specified with its name or id:
```cpp
ChatId{"@chat_name"}
ChatId{123456}
```

### Sending images
To send a photo use any of the folowing variants depending of image source:
```cpp
// for local file
Message answer = bot.sendPhoto(ChatId{"@chat_name"}, Photo{File{"photo.jpg"}});

// for in-memory image stored in std::vector
std::vector<char> photo = ...;
Message answer = bot.sendPhoto(ChatId{"@chat_name"},
                               Photo{Buffer{photo, "photo.jpg"}}
                              );

// for in-memory image stored in C-array
Message answer = bot.sendPhoto(ChatId{"@chat_name"},
                               Photo{Buffer{photo.data(), photo.size(), "photo.jpg"}}
                              );

// for image available by URL
Message answer = bot.sendPhoto(ChatId{"@chat_name"},
                               Photo{Url{"http://sample.com/sample.jpg"}}
                              );

// for already uploaded photo you can send it by id
Message answer = bot.sendPhoto(ChatId{"@chat_name"}, Photo{123456});
```
As in the case of messages, you can pass additional options:
```cpp
Message answer = bot.sendPhoto(ChatId{"@chat_name"},
                               Photo{File{"photo.jpg"}}
                               Caption{"Sample photo"},
                               ReplyTo(messageId),
                               DisableNotification()
                              );
```

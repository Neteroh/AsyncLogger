# AsyncLogger

A lightweight C++ logging system designed to explore systems-level programming concepts such as structured data modeling, logging pipelines, and asynchronous processing.

---

## Overview

This project is being built step by step with the goal of creating a production-style logging system in C++. It starts with synchronous logging and gradually evolves into a fully asynchronous, thread-safe system using a producer-consumer architecture.

The focus is not just on making it work, but on building it in a way that reflects real-world engineering practices.

---

## Features

- Structured log messages (LogMessage) containing:
  - message text
  - log level
  - timestamp
  - thread ID
- Multiple log levels:
  - DEBUG
  - INFO
  - WARNING
  - ERROR
  - CRITICAL
- Unified logging API
- Console output
- File output (logs/app.log)
- Consistent formatted log output

### Example Output
```text
[2026-05-05 02:28:44.4711054] [INFO] [2928] Hello there buddy!
```

---

## Project Structure
```text
AsyncLogger/
├── include/AsyncLogger/
│   ├── Logger.h
│   ├── LogMessage.h
│   └── LogLevel.h
├── src/
│   ├── Logger.cpp
│   ├── LogMessage.cpp
│   └── main.cpp
├── logs/
├── CMakeLists.txt
```
---

## Build

This project uses CMake.
```bash
cmake -S . -B build
cmake --build build
```

Run the executable:

```bash
./build/AsyncLogger
```

(On Windows, run the generated .exe from the build directory.)

---

## Usage
```cpp
Logger logger;

logger.Debug("Debug message");
logger.Info("Info message");
logger.Warning("Warning message");
logger.Error("Error message");
logger.Critical("Critical message");
```

---

## Design Notes

- Logging is centralized through a single Log() function to avoid duplicated logic
- LogMessage is immutable after creation to ensure consistency and thread safety
- Formatting is separated from message creation
- Uses std::ostringstream for safe and flexible string formatting
- Uses initializer lists and move semantics to reduce unnecessary copies

---

## Limitations

- Logging is currently synchronous
- No log level filtering yet
- No configuration system implemented
- Log directory must exist before running

---

## Roadmap

- [x] Structured log messages
- [x] Console output
- [x] File output
- [ ] Minimum log level filtering
- [ ] Configurable logger settings
- [ ] Asynchronous logging (producer-consumer model)
- [ ] Thread-safe queue
- [ ] Log rotation
- [ ] Structured (JSON) logging

---

## Notes

This project is actively being built and improved over time. The goal is to not only understand how logging systems work, but to implement one in a way that reflects real-world usage and design decisions. This is my first full personal project built and documented from start to finish outside of school. Feedback and suggestions are welcome.

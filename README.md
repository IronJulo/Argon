# Argon: Command-Line Argument Processor

Argon is a simple library designed to help C++ developers process and handle command-line arguments with ease.

## Features

- Simple API for creating and configuring arguments.
- Supports various data types like `Integer`, `String`, and more.
- Ability to set mandatory and optional arguments.
- Integrated help-text functionality for better user experience.

## Installation

- Use the Header-only library available in the releases.

## Usage

Here's a quick example to get started:

```cpp
#include "Processor.h"
#include <iostream>

int main()
{
    Argon::Processor argonProcessor;

    argonProcessor.createArgument("-y")
        .setType(Argon::Type::Integer)
        .setIsRequired(true)
        .setHelpText("This is the -y parameter for user's age");

    argonProcessor.createArgument("-u")
        .setType(Argon::Type::String)
        .setIsRequired(false)
        .setHelpText("This is the -u parameter for user's username");

    const int argc = 5;
    const char *argv[argc] = {"thisProg", "-u", "Julo", "-y", "21"};

    argonProcessor.processArguments(argc, argv);
    argonProcessor.verifyArguments();

    std::cout << argonProcessor << std::endl;
    argonProcessor.showHelp();

    return 0;
}
```

## API Documentation

### Argon::Processor

The main class to interact with when creating and parsing arguments.

#### Methods

- `createArgument(<flag>)`: Create a new argument with the specified flag.
- `processArguments(argc, argv)`: Process the arguments provided in `main()`.
- `verifyArguments()`: Check if the mandatory arguments are provided.
- `showHelp()`: Display the help text for all configured arguments.

### Argon::Type

Enum for specifying the type of the argument. Supported types:

- `Integer`
- `String`
- ... (Add more types as necessary)

## Contributing

Feel free to open issues or submit pull requests if you find any bugs or have feature requests.

## License

MIT

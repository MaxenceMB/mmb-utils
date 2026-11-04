\# mmbUtils



A small personal C++ utility library, growing over time.

Everything lives in the `mmb` namespace.



\## Modules



| Module | Header | Description |

|---|---|---|

| Logs | `mmb/Logs.h` | Coloured, tagged console logs using ANSI codes |



\## Requirements



\- Windows, Visual Studio 2022 or newer (MSVC)

\- C++17 or newer

\- A console that supports ANSI escape codes (Windows Terminal, recent Windows 10/11 consoles)



\## Building



1\. Open `mmbUtils.slnx` in Visual Studio.

2\. Build \*\*Debug\*\* and \*\*Release\*\* for \*\*x64\*\*.

3\. The libraries are output to:

&#x20;  ```

&#x20;  lib/x64/Debug/mmbUtils.lib

&#x20;  lib/x64/Release/mmbUtils.lib

&#x20;  ```



\## Using it in a project



\### Option A: Project reference (recommended)



1\. Add this repo to your project, e.g. as a submodule:

&#x20;  ```

&#x20;  git submodule add https://github.com/<your-username>/mmbUtils.git external/mmbUtils

&#x20;  ```

2\. In Visual Studio, right-click the solution, then choose \*\*Add > Existing Project\*\*, then pick `external/mmbUtils/mmbUtils/mmbUtils.vcxproj`.

3\. Right-click your project, then choose \*\*Add > Reference\*\*, then tick \*\*mmbUtils\*\*.

4\. In Project Properties, go to \*\*C/C++ > General > Additional Include Directories\*\* (All Configurations), and add:

&#x20;  ```

&#x20;  $(SolutionDir)external\\mmbUtils\\mmbUtils\\include

&#x20;  ```



\### Option B: Link the prebuilt .lib



In Project Properties (All Configurations / x64):



\- \*\*C/C++ > General > Additional Include Directories\*\*: `path\\to\\mmbUtils\\mmbUtils\\include`

\- \*\*Linker > General > Additional Library Directories\*\*: `path\\to\\mmbUtils\\lib\\x64\\$(Configuration)`

\- \*\*Linker > Input > Additional Dependencies\*\*: `mmbUtils.lib`



> The Runtime Library setting (C/C++ > Code Generation, `/MD` vs `/MT`) must match between mmbUtils and your project.



\## Example



```cpp

\#include <mmb/Logs.h>



int main()

{

&#x20;   mmb::print("Game", "Starting up...");

&#x20;   mmb::printWarning("Assets", "Texture missing, using fallback");

&#x20;   mmb::printError("Audio", "Failed to open device");



&#x20;   std::cout << mmb::Modifier(mmb::BOLD) << mmb::Modifier(mmb::FG\_GREEN)

&#x20;             << "Custom styled text" << mmb::Modifier(mmb::RESET) << std::endl;



&#x20;   return EXIT\_SUCCESS;

}

```

